#include <iostream>
#include <iomanip>
#include <string.h>
#include <cmath>
#include <algorithm>
#define S 2 // 学期数
#define MAX 5 //每个班级最多容纳人数
static int failscore = 60;
using namespace std;
//------------------------------------------------------------------------------------------------------------------------------------------------------------------
class Student
{
    friend class CLS;

private:
    int id;
    string name;
    bool isFail;
    float* score[S]; //数组中的每个指针指向一个学期若干门课的课程成绩
    int course_no[S]; //course_no[i]代表第i+1个学期的课程数目


public:
    Student() { //默认构造函数不申请成绩数组空间
        for (int i = 0; i < S; i++)
            score[i] = NULL;
    }
    void stu_init();
    Student(int _id, string _name, int c_no[]);

    ~Student()
    {
        for (int i = 0; i < S; i++)
            delete[] score[i];

    }
    Student(const Student&);
    void input_scores(float* _score[]);//得到各科成绩并设置isFail的值

    float ave();

    void update_name(string _n)//更新名字
    {
        name = _n;
    }

    void update_id(int _id)//更新id
    {
        id = _id;
    }

    string get_name()//返回名字
    {
        return name;
    }

    int get_id()//返回id
    {
        return id;
    }
    void update_course_no(int a[])//更新课程号
    {
        for (int i = 0; i < S; i++)
            course_no[i] = a[i];
    }
    void get_fail()//根据各科成绩设置isFail的值
    {
        isFail = false;
        for (int i = 0; i < S; i++)
            for (int j = 0; j < course_no[i]; j++)
                if (score[i][j] < failscore) isFail = true;
    }
    // void update(); //更新学生信息

    void show_info()//显示学生信息
    {
        cout << "学生id号码:" << id << endl;
        cout << "姓名:" << name << endl;

        for (int i = 0; i < S; i++)
        {
            cout << setw(10) << "学期 " << i + 1 << ":";
            for (int j = 0; j < course_no[i]; j++)
                cout << setw(10) << score[i][j];
            cout << endl;
        }
        cout << setw(10) << "平均成绩: " << setw(10) << ave() << endl;

        get_fail();
        if (isFail) cout << "有科目挂科." << endl;
        else cout << "没有科目挂科." << endl;
        cout << "------华丽的分割线--------" << endl;
    }
    float get_score(int, int);
};

//Student::Student(){}
Student::Student(int _id, string _name, int c_no[])//初始化id，name以及课程数
{
    id = _id;
    name = _name;
    for (int i = 0; i < S; i++)//输入每个学期的课程数目
        course_no[i] = c_no[i];
    stu_init();
}

Student::Student(const Student& s) // 构造新对象，id加1，其他信息一致
{
    id = s.id + 1;
    name = s.name;
    isFail = s.isFail;
    for (int i = 0; i < S; i++)
        course_no[i] = s.course_no[i];

    //深复制
    stu_init();

    for (int i = 0; i < S; i++)
        for (int j = 0; j < course_no[i]; j++)
            score[i][j] = s.score[i][j];
    // cout<<"A new student with id "<<id<<" was copy constructed."<<endl;
}

void Student::stu_init() //申请成绩数组的存储空间
{
    for (int i = 0; i < S; i++)
        score[i] = new float[course_no[i]];

}
void Student::input_scores(float* _score[])//得到各科成绩并设置isFail的值
{
    for (int i = 0; i < S; i++)
        for (int j = 0; j < course_no[i]; j++)
        {
            score[i][j] = _score[i][j];
        }
    get_fail();
}

float Student::ave()//取学生各课成绩总和平均值
{
    float sum = 0;
    int M = 0;
    for (int i = 0; i < S; i++)
    {
        M += course_no[i];
        for (int j = 0; j < course_no[i]; j++)
            sum += score[i][j];
    }

    return sum / M;
}


float Student::get_score(int semes, int index)//得到什么学期什么课程号的成绩
{
    return score[semes - 1][index - 1];
}

//-----------------------------------------------------------------------------------------------------------------------------------------------
class CLS
{

    Student stu[MAX];
    int stu_no;//班级现有人数
    string* c_names[S]; //各个学期的课程名称
    int* c_ids[S];//各个学期的课程号
    int c_no[S]; //每个学期的课程数目

public:
    CLS(int no);
    CLS();
    void input_stu_num(int no);
    void init();
    void show_class();
    void input_stu_scores();
    Student& get_top_stu(); //找到排名第一的同学
    void sort_by_course_score(int);//根据输入的课程号，按照高低对成绩排序并输出
    int get_stu_no()
    {
        return stu_no;
    }
    void delete_stu(string stu_name);//删除某位同学

    ~CLS();
};
CLS::CLS() {}
CLS::CLS(int no) { stu_no = no; }
void CLS::input_stu_num(int no)
{
    stu_no = no;
}

void CLS::init() //初始化班级数据
{   
    cout << "一共" << S << "个学期" << endl;
    cout << "请分别输入各个学期的课程数目：" << endl;
    for (int i = 0; i < S; i++)
        cin >> c_no[i];

    for (int i = 0; i < S; i++)
    {
        c_ids[i] = new int[c_no[i]];
        c_names[i] = new string[c_no[i]];
    }

    for (int i = 0; i < S; i++)
    {
        cout << "请按顺序分别输入第" << i + 1 << "学期的课程号" << endl;
        for (int j = 0; j < c_no[i]; j++)
            cin >> c_ids[i][j];
    }

    for (int i = 0; i < S; i++)
    {
        cout << "请按顺序分别输入第" << i + 1 << "学期的课程名称:" << endl;
        for (int j = 0; j < c_no[i]; j++)
            cin >> c_names[i][j];
    }

    //接下来对班级里的学生信息进行赋值，学号从1开始自动增加，姓名由键盘输入，由于学生数组中的学生对象由默认构造函数创建，没有成绩数组空间，因此需在此进行学生成绩数组空间分配，此外，为每位学生的course_no赋值

    int id = 1;
    cout << "本班共" << stu_no << "人，请按顺序分别输入学生姓名:" << endl;
    for (int i = 0; i < stu_no; i++)
    {
        string Names;
        cin >> Names;
        stu[i].Student::update_name(Names);
        stu[i].Student::update_id(id);
        stu[i].Student::update_course_no(c_no);
        stu[i].Student::stu_init();
        id += 1;
    }
}

CLS:: ~CLS()
{

    for (int i = 0; i < S; i++)
    {
        delete[]c_ids[i];
        delete[]c_names[i];
    }
}

void CLS::show_class()//展示
{
    cout << "班级总人数:" << stu_no << endl;

    for (int i = 0; i < S; i++)
    {
        cout << "第" << i + 1 << "学期课程:" << endl;

        cout << setw(10) << "课程号";

        for (int j = 0; j < c_no[i]; j++)
            cout << setw(10) << c_ids[i][j];
        cout << endl;

        cout << setw(10) << "课程名";

        for (int j = 0; j < c_no[i]; j++)
            cout << setw(10) << c_names[i][j];
        cout << endl;
    }

    cout << "班级学生基本数据:" << endl;

    cout << setw(10) << "学号";

    for (int i = 0; i < stu_no; i++)
        cout << setw(10) << stu[i].get_id();
    cout << endl;

    cout << setw(10) << "姓名";

    for (int i = 0; i < stu_no; i++)

        cout << setw(10) << stu[i].get_name();

    cout << endl;
    cout << "------华丽的分割线--------" << endl;

    for (int i = 0; i < stu_no; i++)
        stu[i].show_info();

}

void CLS::input_stu_scores()//输入学生成绩
{

    float* sco[S];

    for (int i = 0; i < S; i++)
        sco[i] = new float[c_no[i]];


    for (int k = 0; k < stu_no; k++)
    {
        cout << "下面输入学生" << stu[k].get_name() << "的成绩信息" << endl;
        for (int i = 0; i < S; i++) //科目数量
        {   
            cout << "请输入第 " << i+1 << " 个学期的 " << c_no[i] << " 科成绩" << endl;
            for (int j = 0; j < c_no[i]; j++)//学生 
            {
                
                cin >> sco[i][j];
            }
        }
        /*
        cout << "Please enter the " << c_no[0] << " scores for the 1-th semester" << endl;
        for (int i = 0; i < c_no[0]; i++)
        {
            cin >> sco[0][i];
            stu[k].score[0][i] = sco[0][i];
        }
        cout << "Please enter the " << c_no[1] << " scores for the 2-th semester" << endl;
        for (int i = 0; i < c_no[1]; i++)
        {
            cin >> sco[1][i];
        }
        */
        //cout<<sco<<endl;纠错＆防伪
        stu[k].Student::input_scores(sco);
    }

    for (int i = 0; i < S; i++)
        delete[]sco[i];

}

Student& CLS::get_top_stu()//取最高成绩
{
    float grades = stu[0].ave();
    int g = 0;
    for (int i = 0; i < stu_no; i++)
    {
        if (grades < stu[i].ave())
        {
            grades = stu[i].ave();
            g = i;
        }

    }
    return stu[g];


}

void CLS::sort_by_course_score(int cid)
{
    float s[MAX];//成绩数组
    string names[MAX];//姓名数组
    int k, l;
    for (int i = 0; i < S; i++)
    {
        for (int j = 0; j < c_no[i]; j++)
        {
            if (c_ids[i][j] == cid)
            {
                k = i;
                l = j;
            }
        }
    }
    for (int i = 0; i < stu_no; i++)
    {
        names[i] = stu[i].get_name();
        s[i] = stu[i].get_score(k + 1, l + 1);
    }
    for (int i = 0; i < S; i++)
    {
        for (int j = 0; j < S - 1; j++)
        {
            if (s[i] < s[i + 1])
            {
                float p[10];
                p[0] = s[i + 1];
                s[i + 1] = s[i];
                s[i] = p[0];
                string x;
                x = names[i];
                names[i] = names[i + 1];
                names[i + 1] = x;
            }
        }
    }


    cout << "排序结果：" << endl;
    for (int q = 0; q < stu_no; q++)
        cout << setw(10) << names[q];
    cout << endl;
    for (int w = 0; w < stu_no; w++)
        cout << setw(10) << s[w];
    cout << endl;

}

void CLS::delete_stu(string stu_name)//删除学生
{
    for (int i = 0; i < stu_no; i++)
        if (stu[i].get_name() == stu_name)
        {
            for (int j = i; j < stu_no - 1; j++)// stu[j+1]前移到stu[j]
            {
                stu[j].id = stu[j + 1].id;
                stu[j].name = stu[j + 1].name;
                stu[j].isFail = stu[j + 1].isFail;
                //course_no 数组一样 不需要赋值
                for (int u = 0; u < S; u++)
                    for (int v = 0; v < c_no[u]; v++)
                        stu[j].score[u][v] = stu[j + 1].score[u][v];

                //                for(int u=0; u<S; u++) //也可以互换指针实现
                //                {
                //                    float *p=stu[j].score[u];
                //                    stu[j].score[u]=stu[j+1].score[u];
                //                    stu[j+1].score[u]=p;
                //
                //                }


            }
        }

    stu_no--;
}
void showmenu() {
    cout << endl;
    cout << "o----------------学生成绩管理系统----------------o" << endl;
    cout << "|    请输入数字进行以下功能                      |" << endl;
    cout << "|    1.初始化班级；                              |" << endl;
    cout << "|    2.输入学生成绩；                            |" << endl;
    cout << "|    3.将班级学生按照课程成绩排序；              |" << endl;
    cout << "|    4.列出班级总平均成绩最高的同学；            |" << endl;
    cout << "|    5.删除学生；                                |" << endl;
    cout << "|    6.显示班级信息；                            |" << endl;
    cout << "|    7.更改及格线成绩；                          |" << endl;
    cout << "|    8.退出；                                    |" << endl;
    cout << "o------------------------------------------------o" << endl;
    cout << endl;
}

//------------------------------------------------------------------------------------------------------------------------------
int main()
{   
    
    CLS class_13;
    int stunum;
    bool stop = 0;
    int cid;
    int againstsame=0;
    while (stop != 1) {
        int Switchnum = 0;
        showmenu();
        cin >> Switchnum;
        switch (Switchnum)
        {
        case 1: {
            cout << "请输入学生数量" << endl;
            cin >> stunum;
            class_13.input_stu_num(stunum);
            class_13.init();
            cout << "初始化完成" << endl;
            break;
        }
        case 2: {
            class_13.input_stu_scores();
            break; 
        }
        case 3: {
            
            cout << "请输入要排成绩的课程号：" << endl;
            cin >> cid;
            class_13.sort_by_course_score(cid);//将班级学生按照某个课程的成绩排序
            break; 
        }
        case 4: {
            Student* s = new Student;
            *s = class_13.get_top_stu();
            cout << "该班级总平均成绩最高的同学是" << (*s).get_name() << ", 其学号为" << (*s).get_id() << "，总平均成绩为：" << (*s).ave() << endl;
            //delete s;
            break;
        }
        case 5: {
            string name;
            cout << "请输入要删除的学生姓名：" << endl;
            cin >> name;
            class_13.delete_stu(name);
            break;
        }
        case 6: {
            class_13.show_class();
            break;
        }
        case 7: {
            int failsco;
            cout << "请输入设置及格线分数" << endl;
            cin >> failsco;
            failscore = failsco;
            break;
        }
        case 8: {
            cout << "已退出" << endl;
            stop = 1;
        }
        default:break;

        }
    }
    
}