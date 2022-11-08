#include <iostream>

using namespace std;

long f(int s, int t, int n)

{
long sum=0,sum1=s;
for(int i=1;i<=n;i++)//nÏîºÍ
{
    for(int k=1;k<i;k++)
    {
        sum1=sum1+t;
        cout<<sum1<<endl;
    }
    sum=sum+sum1;
}
    return sum;
 }
int main()
{
 int s,t, n;
 cin>>s>>t>>n;
 cout<<f(s,t,n);
return 0;

}
