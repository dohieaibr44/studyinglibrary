#include<iostream>
using namespace std;
#include<cmath>
void yh(int a[][50],int n);

void PrintYH(int a[][50],int n);

int main()

{
    int a[50][50],n,i,j;
    cin>>n;
    yh(a,n);
    PrintYH(a, n);
    return 0;

}

//此处添加函数实现代码

void yh(int a[][50],int n)
{
    for(int k=0;k<=49;k++)
    {
        a[k][0]=1;
        a[k][k]=1;
    }
    for(int i=2;i<=n-1;i++)
    {
        for(int j=1;j<=i-1;j++)
        {
            a[i][j]=a[i-1][j-1]+a[i-1][j];
        }
    }
}
void PrintYH(int a[][50],int n)
{
    for(int i=0;i<=n-1;i++)
    {
        for(int j=0;j<=i;j++)
        {
            cout<<a[i][j]<<" ";
            if(i==j)cout<<endl;
        }
    }
}
