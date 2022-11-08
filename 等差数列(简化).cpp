#include <iostream>

using namespace std;

long f(int s, int t, int n)

{
    long sum=0;
    sum=(s+t*(n-1)+s)*n/2;
    return sum;
 }
int main()
{
 int s,t, n;
 cin>>s>>t>>n;
 cout<<f(s,t,n);
return 0;

}
