#include <iostream>
#include <math.h>
#include <cmath>
#include <iomanip>

using namespace std;

double f(double x){

return cos(x)-x ;
}
int main()
{
    cout<< "Counting the root of function, method using Bisection"<<endl;

    ///Specify the values for Xl , Xr and tolerance
    double left_x, right_x, left_x_value, right_x_value;
    double tolerance= 10e-8;
    double error;

    cout << "Enter left value:" << endl;
    cin>> left_x;
    cout << "Enter right value:" << endl;
    cin>> right_x;
    left_x_value = f(left_x);
    cout<< left_x_value<<" -  left_x_value"<<endl;
    right_x_value = f(right_x);
    cout<< right_x_value<<"  right_x_value"<<endl;

    ///Calculate the middle value
    double middle_x = (left_x + right_x)/2.0;
    cout << "Middle x is :  " << middle_x<<endl;
    cout << "Middle x value is:  " << f(middle_x)<< endl;

    if(left_x_value * right_x_value > 0.0){
        cout<< " There is an error; the root isn't in this interval"<<endl;
        system("pause");
        return 0;
    }

    ///Check that the root is in interval
    if((left_x_value)*(right_x_value)<=0.0){
        cout<< " The root is in interval"<<endl;
    }
    int i=0;
    do{
        middle_x=(right_x+left_x)/2.0;
        if(f(left_x) *f(middle_x) >0.0){
            left_x = middle_x;
        }
        else{
            right_x= middle_x;
        }
        error=fabs((right_x-left_x)/middle_x);
        i++;


    }while(error>tolerance);

    cout<<"Root found at: "<<setprecision(8)<<middle_x<<endl;
    cout<<"Number of iterations: "<<i<<endl;

    return 0;
}
