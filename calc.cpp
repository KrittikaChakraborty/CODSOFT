#include <iostream>
using namespace std;

int main() {
    double n1;
    double n2;
    char op;

    cout << "Welcome to the C++ Calculator,please choose a operation and give number inputs!\n";

    cout << "Enter the first number: ";
    cin >> n1;
    cout << "Enter the second number: ";
    cin >> n2;

    // Input operation
    cout << "Choose an operation (+, -, *, /): ";
    cin >> op;
    switch(op) {
        case '+':
            cout << "Result: " << n1+n2 << endl;
            break;
        case '-':
            cout << "Result: " << n1-n2 << endl;
            break;
        case '*':
            cout << "Result: " << n1*n2 << endl;
            break;
        case '/':
            if(n2!= 0)
                cout << "Result: " << n1/n2 << endl;
            else
                cout << "Error: Division by zero is not allowed!,pls change input" << endl;
            break;
        default:
            cout << "Invalid operation! Please choose +, -, * or /." << endl;
    }

    return 0;
}
