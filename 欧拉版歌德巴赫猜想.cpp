#include <iostream>

using namespace std;

int main()
{
    int n,a,b,i,j,k,sign{0};
    cin>>n;
    for(i=3;i<=n/2;i+=2){
        a=i;
        b=n-i;
        j=a-1;
        k=b-1;
        while(j>1)
        {
            if(a%j==0){sign=1;}
            j-=1;
        }
        while(k>1)
        {
            if(b%k==0){sign=1;}
            k=k-1;
        }

        if(sign==0){
        cout<<n<<"="<<a<<"+"<<b<<endl;


        }
        sign=0;
    }


}
