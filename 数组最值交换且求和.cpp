#include<iostream>
#include<cmath>
using namespace std;

int fun(int a[],int l)
//函数实现
{   int max=a[0];
    int min=a[0];
    int maxsign,minsign;
    int b[10];
    int summ=0;
    for(int i=0;i<=l-1;i++)
    {
        if(a[i]>max){max=a[i];maxsign=i;}
        if(a[i]<min){min=a[i];minsign=i;}
    }
    //________________________switch______________
    b[0]=a[maxsign];
    a[maxsign]=a[minsign];
    a[minsign]=b[0];
    //____________________________________________
    for(int i=0;i<=l-1;i++)
    {
        summ=summ+a[i];
    }
    return summ;
}


int main()
{int a[50],n,i,sum;
    cin>>n;

//输入n个元素的数组

for(int i=0;i<=n-1;i++)
{
    cin>>a[i];
}


sum=fun(a,n);

//输出数组

for(int i=0;i<=n-1;i++)
{
    cout<<a[i]<<" ";
}


cout<<endl;
cout<<"sum="<<sum<<endl;

return 0;}
