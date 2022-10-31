#include <iostream>
#include <iomanip>
using namespace std;
enum MT{Jan=1,Feb,Mar,Apr,May,Jun,Jul,Aug,Sep,Oct,Nov,Dec};
typedef int YR;
class Timedate{
private:
	YR year;
	MT month;
	int date;
	int hh;
	int mm;
	int ss;
	string fuckingmonth;
public:
	Timedate(){year=2000;month=Jan;date=1;hh=0;mm=0;ss=0;}
	Timedate(YR a, MT b, int c){
		year=a;
		month=b;
		date=c;
		hh=12;mm=30;ss=0;
	}
	void getdate(YR &,MT &,int &);//使用引用一次取得3个数值
	void gettime(int &,int &,int &);
	void putdate(YR ,MT ,int );
	void puttime(int ,int ,int );
	void list();
};
void Timedate::putdate(YR Y ,MT M,int D)
	{
	    year=Y;
	    month=M;
	    date=D;
	    cout<<month;

    };
	void Timedate::puttime(int h,int m,int s)
	{
        hh=h;
        mm=m;
        ss=s;
	};
	void Timedate::list()
	{   string s;
        switch (month)
        {
            case 1:s="Jan";break;
            case 2:s="Feb";break;
            case 3:s="Mar";break;
            case 4:s="Apr";break;
            case 5:s="May";break;
            case 6:s="Jun";break;
            case 7:s="Jul";break;
            case 8:s="Aug";break;
            case 9:s="Sep";break;
            case 10:s="Oct";break;
            case 11:s="Nov";break;
            case 12:s="Dec";break;
        }
        cout<<"year/month/date :"<<year<<"/"<<s<<"/"<<date<<endl;
        cout<<"hour:minite:second :"<<hh<<":"<<mm<<":"<<ss<<endl;
	};

int main(int argc, char* argv[]){
    int y,d,month,h,m,s;
	Timedate A(2004,Mar,3),B;
	A.list();
	B.list();

	cin>>y>>month>>d; //输入年月日，设置日期
	B.putdate(y,(MT)month,d);

	cin>>h>>m>>s;        //输入时分秒，设置时间
	B.puttime(h,m,s);
	B.list();
	return 0;
}
