#include <iostream>

using namespace std;

int main()
{
    string account,paswd,start;
    int bo1,bo2,bo3;

do{
    bo1 = 0;
    cout << "ACCOUNT:";
    cin >> account;
    if(account=="admin")
    {

        do{
            cout<<"PASSWORD:";
            cin >> paswd;
            bo2=0;
            if(paswd=="123")
            {
            cout<<"密码正确，允许登录"<<endl<<"欢迎使用多此一举计算器"<<endl;
            do{
            bo3=0;
            cout<<"输入start运行"<<endl;
            cin >>start;
                if(start=="start")
                    {
                    //服务主体内容






















                    }else bo3=1;


                }while(bo3==1);
            }else{cout<<"密码错误"<<endl;bo2=1;}
           }while(bo2==1);
    }else {cout<<"无当前账号"<<endl;bo1=1;}


  }while (bo1==1);


}
