#include <iostream>
#include <cmath>

using namespace std;

double funcLeft, funcRight, funcPrecision, n;

string textRepresentation(int func) {
    switch (func) {
        case 1:
            return "cos^2(x) + cos(x^2)";
        case 2:
            return "x^3 + 2x^2 + 3x + 4";
        case 3:
            return "log(x)^e";
        default:
            return "";
    }
}

double applyFunction(int func, double h, double x) {
    switch (func) {
        case 1:
            return h*(pow(cos(x),2) + cos(pow(x,2)));
        case 2:
            return h*(pow(x,3) + pow(2*x,2) + 3*x + 4);
        case 3:
            return h*(pow(log(x), M_E));
    }
}

void solveLeft(int func) {
    n = 4;
    double step = funcRight - funcLeft;
    double I0 = 0;
    double h = step / n;

    for (double i = funcLeft; i < funcRight; i += h) {
        I0 = I0 + applyFunction(func, h, i);
    }
    n *= 2;

    while (true) {
        h = step / n;
        double I1 = 0;
        for (double i = funcLeft; i < funcRight; i += h) {
            I1 = I1 + applyFunction(func, h, i);
        }

        if (abs(I1 - I0) < (1/pow(10, funcPrecision))) {
            I0 = I1;
            break;
        } else {
            I0 = I1;
            n *= 2;
        }
    }

    cout << "Function " << textRepresentation(func) <<", left rectangles method\n" <<
                      "High reach " << funcRight <<", low reach " << funcLeft << ", precision " <<
                      funcPrecision << "numbers after dot\n" <<
                      "Answer: " << I0 <<"\n" <<
                      "Number of separating " << n << endl;
}

void solveMiddle(int func) {
    n = 4;
    double step = funcRight - funcLeft;
    double I0 = 0;
    double h = step / n;

    for (double i = funcLeft + h/2; i < funcRight - h/2; i += h) {
        I0 = I0 + applyFunction(func, h, i);
    }
    n *= 2;

    while (true) {
        h = step / n;
        double I1 = 0;
        for (double i = funcLeft + h/2; i < funcRight - h/2; i += h) {
            I1 = I1 + applyFunction(func, h, i);
        }

        if (abs(I1 - I0) < (1/pow(10, funcPrecision))) {
            I0 = I1;
            break;
        } else {
            I0 = I1;
            n *= 2;
        }
    }

    cout << "Function " << textRepresentation(func) <<", middle rectangles method\n" <<
         "High reach " << funcRight <<", low reach " << funcLeft << ", precision " <<
         funcPrecision << "numbers after dot\n" <<
         "Answer: " << I0 <<"\n" <<
         "Number of separating " << n << endl;
}

void solveRight(int func) {
    n = 4;
    double step = funcRight - funcLeft;
    double I0 = 0;
    double h = step / n;

    for (double i = funcLeft + h; i < funcRight; i += h) {
        I0 = I0 + applyFunction(func, h, i);
    }
    n *= 2;

    while (true) {
        h = step / n;
        double I1 = 0;
        for (double i = funcLeft + h; i < funcRight; i += h) {
            I1 = I1 + applyFunction(func, h, i);
        }

        if (abs(I1 - I0) < (1/pow(10, funcPrecision))) {
            I0 = I1;
            break;
        } else {
            I0 = I1;
            n *= 2;
        }
    }

    cout << "Function " << textRepresentation(func) <<", right rectangles method\n" <<
         "High reach " << funcRight <<", low reach " << funcLeft << ", precision " <<
         funcPrecision << "numbers after dot\n" <<
         "Answer: " << I0 <<"\n" <<
         "Number of separating " << n << endl;
}

void solve(int func, int method){
    switch (method){
        default: {
            solveLeft(func);
            solveMiddle(func);
            solveRight(func);
        }
    }
}

int verify(){
    int number;
    cin >> number;
    if (number > 3 || number < 1){
        cout << "Stop right there, criminal scum. Insert right number, %Username% \n" << endl;
        verify();
    }

    return number;
}

int main() {
    int funcNumber, methodNumber;
    cout << "Hello, %Username% \n" << endl;
    cout << "Choose function from suggested, just press down the needed function number! \n" << endl;
    cout << "1 - cos^2(x) + cos(x^2)" << endl;
    cout << "2 - x^3 + 2x^2 + 3x + 4" << endl;
    cout << "3 - log(x)^e (WARNING!!! Remember logarithm restrictions!!!)\n" << endl;
    funcNumber = verify();
    methodNumber = 0;

    cout << "Insert low reach of integration: \n" << endl;
    cin >> funcLeft;

    cout << "Insert high reach of integration: \n" << endl;
    cin >> funcRight;

    if (funcLeft > funcRight){
        double c = funcLeft;
        funcLeft = funcRight;
        funcRight = c;
    }

    cout << "Insert amount of numbers after dot (number from 0 to 25): \n" << endl;
    cin >> funcPrecision;
    if (funcPrecision < 0 ) funcPrecision = 0;
    if (funcPrecision > 25) funcPrecision = 25;

    solve(funcNumber, methodNumber);

    return 0;
}