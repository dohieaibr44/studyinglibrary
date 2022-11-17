#include<iostream>
#include<cmath>
using namespace std;

bool IsPrime(int n);

int order(int a[],int b[],int n);  //素数存到b[],该函数返回b数组的大小


int main()
{
    int a[40],b[40],n,i,q;
    cin>>n;
    for(i=0;i<n;i++)
// 输入数组a[n]

{
    cin>>a[i];
}


    q=order(a,b,n);
    //输出排序后的数组 b[]

    for(int i=q;i>=0;i--)
{
    if(b[i]!=1&&b[i]!=0)cout<<b[i]<<" ";
}

return 0;}

//请添加函数实现代码
bool IsPrime(int n)
{   bool p=true;

    for(int i=n;i>=2;i--)
    {   //cout<<"i"<<endl;
        if(n%i==0&&n!=i)
            {
                p=false;
                //cout<<"false"<<endl;
                //cout<<p<<endl;
                return p;

            }

    }
    //cout<<p<<endl;
    return p;
}

int order(int a[],int b[],int n)
{   int countt=0;
    int c[100];
    for(int i=0;i<=n-1;i++)
    {   //cout<<a[i]<<endl;
        if(IsPrime(a[i])==1)
        {   //cout<<"countt="<<countt<<endl;
            b[countt]=a[i];
            //cout<<"a="<<a[i]<<endl;
            //cout<<"b="<<b[countt]<<endl;
            countt++;

        }

    }
    for(int i=0;i<=countt;i++)
    {
        for(int j=i+1;j<=countt;j++)
        {
            if(b[j]>b[i])
            {
                c[i]=b[j];
                b[j]=b[i];
                b[i]=c[i];
            }
        }
    }
    //cout<<"countt="<<countt<<endl;
    return countt;
}
