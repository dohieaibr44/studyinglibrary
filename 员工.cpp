#include<iostream>
using namespace std;

class employee //定义employee类
{
    int empno,grade,accumpay;

public:
    employee(int e=11111,int g=1,int a=5000)
    {
        empno=e;
        grade=g;
        accumpay=a;
    }

    employee(const employee &t2)
    {
       empno=t2.empno+1;
        grade=t2.grade;
        accumpay=t2.accumpay;

    }
    void display()
    {
        cout<<empno<<","<<grade<<","<<accumpay<<endl;
    }
    void addPay(int x)
    {
        accumpay=accumpay+x;
    }
};

int main()

{
    int EmpNo;
    int grade;
    int accumPay;
    cin>>EmpNo>>grade>>accumPay;
    employee t1;         //t1:工号11111、 级别 1、工资 5000
    employee t2(EmpNo,grade,accumPay);//t2:工号EmpNo、 级别 grade、工资 accumPay
    employee t3(t2);// t3工号是t2工号加1，其他数据与当前t2一致

    t1.display();

    t2.display();

    t3.display();

    t3.addPay(2000);    //t3工资共涨2000

    t3.display();

    return 0;

}
