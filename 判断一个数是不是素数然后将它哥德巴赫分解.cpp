#include <iostream>

using namespace std;

int IsPrime(int m)
{
    for(int n=m-1;n>1;n--)
    {
        if(m%n==0)
            {
                cout<<m<<" is not a prime!"<<endl;
                break;
            }
    }

}
int gedebahewenti(int n)
{
    int m=n/2;
    for(int i=3;i<=m;)
    {   int t=0;
        for(int k=2;k<=i-1;)
        {
           if(i%k==0){t=1;}

           k++;

        }//验证i是否为素数，不是则i不可用

        for(int k=2;k<=n-i-1;)
        {
           if((n-i)%k==0){t=1;}

           k++;

        }


        if(t==0){cout<<n<<"="<<i<<"+"<<n-i<<endl;}
        i+=2;
    }


}
int main()
{
    int n;
    cin>>n;
    IsPrime(n);
    gedebahewenti(n);

    return 0;
}
