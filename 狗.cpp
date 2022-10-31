#include <cstdlib>
#include<iostream>
using namespace std;
class dog{
private:
    int age=1;
    int weight=5;

public:
    dog(){};
    dog(int Age,int Weight)
    {
        age=Age;
        weight=Weight;
    };

    int getage(){return age;};
    int getweight(){return weight;};

};



int main()
{ dog d;
  cout<<"age="<<d.getage()<<",weight="<<d.getweight()<<endl;
  int nage,nweight;
  cin>>nage>>nweight;
  dog dog2(nage,nweight);
  cout<<"age="<<dog2.getage()<<",weight="<<dog2.getweight()<<endl;
return 0;
}
