#include <iostream>
#include <iomanip>
#include <string.h>
#include <cmath>
#define M 3 // 课程门数
#define N 4 //学生数组中的学生个数
using namespace std;

class Student
{
public:
    Student() {}
    Student(const Student&);
    void input_info()
    {
        // cout<<"Please enter student id......"<<endl;
        cin>>id;

        //cout<<"Please enter student name:"<<endl;
        cin>>name;

        //cout<<"Please enter scores:"<<endl;
        for(int i=0; i<3; i++)
            cin>>score[i];

        //cout<<"------华丽的分割线--------"<<endl;

        isFail=false;
        for(int i=0; i<3; i++)
            if(score[i]<60) isFail=true;
    }

    void input_lesson_ids()
    {
        //cout<<"Please enter lesson ids:"<<endl;
        for(int i=0; i<M; i++)
            cin>>lesson_id[i];
    }
    void show_info()
    {
        cout<<"Student id:"<<id<<endl;
        cout<<"Student name:"<<name<<endl;
        cout<<setw(10)<<"lesson_id ";
        for(int i=0; i<M; i++)
            cout<<setw(10)<<lesson_id[i];

        cout<<setw(10)<<"Average";
        cout<<endl;

        cout<<setw(10)<<"scores ";
        for(int i=0; i<M; i++)
            cout<<setw(10)<<score[i];

        cout<<setw(10)<<ave();
        cout<<endl;

        if(isFail) cout<<"The student failed."<<endl;
        else cout<<"The student didn\'t fail."<<endl;
        cout<<"------华丽的分割线--------"<<endl;

    } //showinfo()
    float ave()//求平均成绩
    {
   return (score[0]+score[1]+score[2])/3;
    }
    string get_name()
    {
        return name;
    }

private:
    int id;
    string name;
    bool isFail;
    static int lesson_id[M];
    float score[M];
};
int Student::lesson_id[M];

Student::Student(const Student& s)
{
   id=s.id;
    name=s.name;
    for(int i=0;i<=3;i++)
    {
        lesson_id[i]=s.lesson_id[i];
    }
    for(int i=0;i<=3;i++)
    {
        score[i]=s.score[i];
    }

}


int main()
{

    Student cs[N];

    cs[0].input_lesson_ids();// 用一个学生对象对静态数组成员赋值

    for(int i=0; i<N; i++)
        cs[i].input_info();
    Student temp[N];
for(int i=0;i<=3;i++)
{
    for(int k=i+1;k<=3;k++)
    {
        if(cs[k].ave()>cs[i].ave())
            {   temp[i]=cs[k];
                cs[k]=cs[i];
                cs[i]=temp[i];


            }
    }
}


cout<<"Student "<<cs[0].get_name()<<" got the highest average score as "<<cs[0].ave()<<endl;
cout<<"Student "<<cs[3].get_name()<<" got the lowest average score as "<<cs[3].ave()<<endl;

    for(int i=0; i<N; i++)//输出排序后的结果
        cs[i].show_info();

////------------------------------
    return 0;
}
