// THERE ARE N PEOPLE AND 1 KNIFE AND 1ST PERSON STARTS GAME AND ATLERNATE PEOPLE ARE KILLED TELL WHICH PERSON IS ALIVE
//IDEA IS TO REPRESENT N IN FORM OF 2^X +L 
//AND THE ANS WILL BE 2*L +1
/*EG:
   ALIVE    |  N
   1           1
   1           1 2
   3           1 2 3
   1           1 2 3 4
   3           1 2 3 4 5
   5           1 2 3 4 5 6
   7           1 2 3 4 5 6 7
   1           1 2 3 4 5 6 7 8
   3           1 2 3 4 5 6 7 8 9 
   
   SO 1 = 2^0+0 L=0 2L+1= 1 
      2 = 2^1+0 L=0 2L+1= 1 
      3 = 2^1+1 L=1 2L+1= 3
      4 = 2^2+0 L=0 2L+1= 1 
      5 = 2^2+1 L=1 2L+1= 3
      6 = 2^2+2 L=2 2L+1= 5
      7 = 2^2+3 L=3 2L+1= 7
      8 = 2^3+0 L=0 2L+1= 1 
      9 = 2^3+1 L=1 2L+1= 3
*/

#include <iostream>
using namespace std;
int power_of_2(int n)
{
    int i=1;
    while(i*2<=n)
    {
        i=i*2;
    }
    return i;
}
int alive(int n)
{
    int m=power_of_2(n);
    int r=n-m;
    return (2*r+1);
}

int main() 
{
    int n=9;
    cout<<alive(n);
    return 0;
}
