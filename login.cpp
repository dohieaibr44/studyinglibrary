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
            cout<<"������ȷ�������¼"<<endl<<"��ӭʹ�ö��һ�ټ�����"<<endl;
            do{
            bo3=0;
            cout<<"����start����"<<endl;
            cin >>start;
                if(start=="start")
                    {
                    //������������






















                    }else bo3=1;


                }while(bo3==1);
            }else{cout<<"�������"<<endl;bo2=1;}
           }while(bo2==1);
    }else {cout<<"�޵�ǰ�˺�"<<endl;bo1=1;}


  }while (bo1==1);


}
