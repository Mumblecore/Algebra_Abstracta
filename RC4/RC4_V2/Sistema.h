#include "Extensiones.h"
#include <string>
#include <sstream>
#include <stdlib.h>
#include <mach/mach_init.h>
#include <mach/mach_error.h>
#include <mach/mach_host.h>
#include <mach/vm_map.h>

using namespace std;

string StdoutFromTerminal(string cmd) {

    string data;
    FILE * stream;
    const int max_buffer = 256;
    char buffer[max_buffer];
    cmd.append(" 2>&1");

    stream = popen(cmd.c_str(), "r");
    if (stream) {
        while (!feof(stream))
            if (fgets(buffer, max_buffer, stream) != NULL) data.append(buffer);
                pclose(stream);
    }
    return data;
}

ZZ stringToZZ(string str)
{
    ZZ z;
    istringstream(str) >> z;
    return z;
}

static unsigned long long _previousTotalTicks = 0;
static unsigned long long _previousIdleTicks = 0;

// Returns 1.0f for "CPU fully pinned", 0.0f for "CPU idle", or somewhere in between
// You'll need to call this at regular intervals, since it measures the load between
// the previous call and the current one.

float CalculateCPULoad(unsigned long long idleTicks, unsigned long long totalTicks)
{
  unsigned long long totalTicksSinceLastTime = totalTicks-_previousTotalTicks;
  unsigned long long idleTicksSinceLastTime  = idleTicks-_previousIdleTicks;
  float ret = 1.0f-((totalTicksSinceLastTime > 0) ? ((float)idleTicksSinceLastTime)/totalTicksSinceLastTime : 0);
  _previousTotalTicks = totalTicks;
  _previousIdleTicks  = idleTicks;
  return ret;
}

float GetCPULoad()
{
   host_cpu_load_info_data_t cpuinfo;
   mach_msg_type_number_t count = HOST_CPU_LOAD_INFO_COUNT;
   if (host_statistics(mach_host_self(), HOST_CPU_LOAD_INFO, (host_info_t)&cpuinfo, &count) == KERN_SUCCESS)
   {
      unsigned long long totalTicks = 0;
      for(int i=0; i<CPU_STATE_MAX; i++) totalTicks += cpuinfo.cpu_ticks[i];
      return CalculateCPULoad(cpuinfo.cpu_ticks[CPU_STATE_IDLE], totalTicks);
   }
   else return -1.0f;
}

ZZ ZZCPULoad()
{
   float f = GetCPULoad();
   f *= 1000000;
   ZZ F(conv<ZZ>((int)f));
   //debido a que la variacion de esta variable se ve solo en los ultimos dos digitos
   return nmod(F, ZZ(100));
}

static double ParseMemValue(const char * b)
{
   while((*b)&&(isdigit(*b) == false)) b++;
   return isdigit(*b) ? atof(b) : -1.0;
}

// Returns a number between 0.0f and 1.0f, with 0.0f meaning all RAM is available, and 1.0f meaning all RAM is currently in use
ZZ GetSystemMemoryUsagePercentage()
{
   FILE * fpIn = popen("/usr/bin/vm_stat", "r");
   if (fpIn)
   {
      double pagesUsed = 0.0, totalPages = 0.0;
      char buf[512];
      while(fgets(buf, sizeof(buf), fpIn) != NULL)
      {
         if (strncmp(buf, "Pages", 5) == 0)
         {
            double val = ParseMemValue(buf);
            if (val >= 0.0)
            {
               if ((strncmp(buf, "Pages wired", 11) == 0)||(strncmp(buf, "Pages active", 12) == 0)) pagesUsed += val;
               totalPages += val;
            }
         }
         else if (strncmp(buf, "Mach Virtual Memory Statistics", 30) != 0) break;  // Stop at "Translation Faults", we don't care about anything at or below that
      }
      pclose(fpIn);
      //edito el valor para poder usarlo
      if (totalPages > 0.0){
         float f = (float) (pagesUsed/totalPages);
         f*=1000000;
         return ZZ((conv<ZZ>((int)f)));
      }
   }
   return ZZ(-1);  // indicate failure
}

void AddLoadAverage(Vec<ZZ> &K)
{
   string n;
   string c = StdoutFromTerminal("iostat");
   for(int i = 2; i < 16; i++)
      if(c[c.size() - i] != '.')
         n += c[c.size() - i];
   for(int i = 0; i < 3; i++){
      string a(n, i*4, 3);
      K[i] = stringToZZ(a);
   }
}

//esta la hice yo
ZZ GetWifiRedsInfo()
{
   system("system_profiler SPAirPortDataType > wifi_info.txt");
   system("grep Noise wifi_info.txt > wifi_info2.txt");
   string wi = StdoutFromTerminal("LC_CTYPE=C tr -dc 0-9 < wifi_info2.txt");
   return stringToZZ(wi);
}