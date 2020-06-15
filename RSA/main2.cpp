#include <iostream>
#include<stdlib.h>
using namespace std;
int pow(int pow_a, unsigned int pow_b, int pow_c) {
   int result = 1;
   pow_a = pow_a % pow_c;
   while (pow_b > 0) {
      if (pow_b & 1)
      result = (result * pow_a) % pow_c;
      pow_b = pow_b >> 1;
      pow_a = (pow_a * pow_a) % pow_c;
   }
   return result;
}
bool MiillerTest(int MT_dt, int MT_num) {
   int MT_a = 2 + rand( ) % (MT_num - 4);
   int MT_x = pow(MT_a, MT_dt, MT_num);
   if (MT_x == 1 || MT_x == MT_num - 1)
      return true;
   while (MT_dt != MT_num - 1) {
      MT_x = (MT_x * MT_x) % MT_num;
      MT_dt *= 2;
      if (MT_x == 1)
         return false;
      if (MT_x == MT_num - 1)
         return true;
   }
   return false;
}
bool prime(int P_N, int P_K) {
   if (P_N <= 1 || P_N == 4)
      return false;
   if (P_N <= 3)
      return true;
   int P_D = P_N - 1;
   while (P_D % 2 == 0)
      P_D /= 2;
   for (int i = 0; i < P_K; i++)
      if (MiillerTest(P_D, P_N) == false)
         return false;
      return true;
}
int main() {
   int iter = 10000;
   long n;
   int c = 10;
   while(c--)
   {
        cout<< "Enter the number: ";
        cin >> n;
        cout<<endl;
        if(prime(n, iter))
            cout<<n<<" is a prime number\n"<<endl;
        else
            cout<<n<<" is a composite number\n"<<endl;
   }
   return 0;
}