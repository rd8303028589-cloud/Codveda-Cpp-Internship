#include <iostream>
#include<cmath>
using namespace std;
int main() {
    double num1, num2;
    char op;
    //Input
    cout<<"====Simpe Calculator===="<<endl;
    cout<<"Enter First Number: ";
    cin>>num1;
    cout<<"Enter Operator(+,-,*,/): ";
    cin>>op;
    cout<<"Enter Second Number: ";
    cin>>num2;
    //Perform Caculator
    switch(op) {
        case'+':
        cout<<"Result = "<<num1+num2<<endl;
        break;
        case'-':
        cout<<"Result = "<<num1-num2<<endl;
        break;
        case'*':
        cout<<"Result = "<<num1*num2<<endl;
        break;
        case'/':
        if(num2 != 0){
        cout<<"Result = "<<num1/num2<<endl;
        } else {
            cout<<"Error Division by zero is not allowed !"<<endl;
        }
        break;
        default:
        cout<<"Invalid Operater !"<<endl;
    }
    
    return 0;
}