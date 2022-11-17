//求Fibonacci 数列的前n项

#include "iostream"
#include<iomanip>
using namespace std;

void Fibonacci(int f[],int n);
void PrintFibonacci(int f[],int n);

int main()
{  int i,k;
   int n;
   int f [50] = {1,1}; //定义，初始化
   cin>>n;
   Fibonacci(f,n);
   PrintFibonacci(f,n);
}

//此处添加函数实现
void Fibonacci(int f[],int n)
{
    for(int i=2;i<=n-1;i++)
    {
        f[i]=f[i-1]+f[i-2];
    }
}
void PrintFibonacci(int f[],int n)
{   int count=0;
    for(int i=n-1;i>=0;i--)
    {

        cout<<setw(8)<<f[i];
        count++;
        if(count%5==0&&count!=1)
        {
            cout<<endl;
        }
    }
}
