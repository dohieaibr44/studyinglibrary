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
	cout<<"圆半径:"<<cl3.GetR()<<'\t'<<"圆周长:"<<cl3.GetCircumference()
		<<'\t'<<"圆面积:"<<cl3.GetAreaCircle()<<endl;
	cin>>r;
	cl2.SetR(r);
	cout<<"圆半径:"<<cl2.GetR()<<'\t'<<"圆周长:"<<cl2.GetCircumference()
		<<'\t'<<"圆面积:"<<cl2.GetAreaCircle()<<endl;
	return 0;
}
