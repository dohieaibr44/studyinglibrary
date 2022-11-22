#include <iostream>
using namespace std;
int print(int (&a)[3][3])
{
    for(int i=0;i<=2;i++)
    {
        for(int j=0;j<=2;j++)
        {
            cout<<a[i][j]<<"  ";

        }
        cout<<endl;
    }
}
int exchange(int (&a)[3][3],int (&b)[3][3])
{
    for(int i=0,j=0;j<=2;j++)
    {
        b[i][j]=a[i][j];
        a[i][j]=a[j][i];
        a[j][i]=b[i][j];
    }
    for(int i=1,j=2;i<=2;i++)
    {
        b[i][j]=a[i][j];
        a[i][j]=a[j][i];
        a[j][i]=b[i][j];
    }
}
int info(int (&a)[3][3])
{
    for(int i=0;i<=2;i++)
    {
        for(int j=0;j<=2;j++)
        {
            cin>>a[i][j];
        }
    }
}
int main()
{
    int a[3][3],b[3][3];
    info(a);
    exchange(a,b);
    print(a);
}
