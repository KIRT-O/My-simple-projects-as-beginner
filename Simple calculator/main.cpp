#include <iostream>
using namespace std;
// This code is about making calculator
int main()
{
    int num1 , num2 ;
    char op;
    cout << "Enter first number: ";
     if(!(cin>>num1)){   // This means: "Check if the input is a valid number"
        cout << "Error: please enter a valid number" ;
        return 1;
    }
    cout << "Enter operator: ";
    cin >> op;
    cout << "Enter second number: ";
    if(!(cin>>num2)){
        cout << "Error: please enter a valid number " ;
        return 1; // "return 1" means the program has fail
    }
//Here are the math operators
    int result;
    if (op == '+'){
        result = num1 + num2 ;
    } else if (op == '-'){
        result = num1 - num2;
    } else if (op == '/'){
        result = num1 / num2 ;
    } else if(op == '*'){
        result = num1 * num2 ;
    }
    else {
        cout << "Invalid Operator ";
    }
    cout<< "The result is : " << result ;


    return 0;
}
