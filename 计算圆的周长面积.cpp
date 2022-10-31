#include<iostream>
#include<cmath>
#define PI 3.14159265

using namespace std;

class Circle{
private:
    float radius=0;

public:
    Circle(int r=0){radius=r;};
    Circle(const Circle & c)
    {
        radius=c.radius;
    }
    float GetCircumference()
    {
        float l;
        l=2*radius*3.1415926535;
        return l;
    };

    float GetAreaCircle()
    {
        float s;
        s=(radius*radius*3.1415926535);
        return s;
    };

    float GetR(){return radius;};
    float SetR(int r){radius=r;}

};




int main(){
    int r;
    cin>>r;
	Circle cl1(r),cl2,cl3=cl1;
	cout<<"Բ�뾶:"<<cl3.GetR()<<'\t'<<"Բ�ܳ�:"<<cl3.GetCircumference()
		<<'\t'<<"Բ���:"<<cl3.GetAreaCircle()<<endl;
	cin>>r;
	cl2.SetR(r);
	cout<<"Բ�뾶:"<<cl2.GetR()<<'\t'<<"Բ�ܳ�:"<<cl2.GetCircumference()
		<<'\t'<<"Բ���:"<<cl2.GetAreaCircle()<<endl;
	return 0;
}
