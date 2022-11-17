#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char a[100];
    cin>>a;
    for(int i=strlen(a)-2;i>=0;i--)
    {
        cout<<a[i];

    }
}
