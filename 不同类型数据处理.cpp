#include <iostream>
using namespace std;
class DataType
{
    int I;
    char C;
    float F;
    double D;
    int k;
public:
    DataType(int i){k=1;I=i;};
    DataType(char c){k=2;C=c;};
    DataType(float f){k=3;F=f;};
    DataType(double d){k=4;D=d;};

    void Show()
    {
        switch (k){

            case 1:cout<<"int "<<I<<endl;break;
            case 2:cout<<"char "<<C<<endl;break;
            case 3:cout<<"float "<<F<<endl;break;
            case 4:cout<<"double "<<D<<endl;break;
        }

    };

};

int main()
    {   int i;
        char c;
        float f;
        double d;
        cin>>i;
    	DataType a(i);
    	a.Show();
    	cin>>c;
    	DataType b1(c);
    	b1.Show();
    	cin>>f;
    	DataType b2(f);
    	b2.Show();
    	cin>>d;
    	DataType b3(d);
    	b3.Show();
    	return 0;
    }
