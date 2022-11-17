#include<iostream>
using namespace std;
void cal(int a[],int n,int &max_a,int &min_a)

{  int max=a[0];
   int min=a[9];
   for(int i=0;i<=n-1;i++)
   {
       if(a[i]>max){max=a[i];}
       if(a[i]<min){min=a[i];}
   }
    max_a=max;
    min_a=min;
}


int main(){
	int a[10],max_a,min_a;
	cout<<"输入10个整数："<<endl;
	for(int i=0;i<10;i++) cin>>a[i];
	cal(a,10 ,max_a,min_a);
    for(int i=0;i<10;i++) cout<<a[i]<<"  ";
	cout<<endl;
	cout<<"max="<<max_a<<",min="<<min_a<<endl;
	return 0;
}
