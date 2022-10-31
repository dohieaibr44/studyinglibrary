#include <iostream>
using namespace std;
class Tree
{
    int ages=0;
public:
    Tree(){cout<<"creat a tree,age="<<ages<<endl;};
    int age(){cout<<"age="<<ages<<endl;}
    void grow(int years){ages=ages+years;}
};

int main()
{
  Tree t;
  int year;
  t.age();

  cin>>year;
  t.grow(year);
  t.age();
}
