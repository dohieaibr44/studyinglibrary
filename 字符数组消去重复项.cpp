#include <iostream>
#include <cstring>
using namespace std;

char words[100];
int main()
{
    cin>>words;
    cout<<words[0];
    for(int i=1;i<=strlen(words)-1;i++)
    {
        if(words[i]!=words[i-1])cout<<words[i];
    }
}
//我爱偷懒！❤
