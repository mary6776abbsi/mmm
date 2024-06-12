#include <iostream>
#include <cmath> // برای تابع pow

using namespace std;

// تابع ماشین حساب
void calculator(double num1, double num2, char op) {
    double result;
    bool validOperator = true;

    // استفاده از switch برای تفکیک عملگرها
    switch (op) {
    case '+':
        result = num1 + num2;
        break;
    case '-':
        result = num1 - num2;
        break;
    case '*':
        result = num1 * num2;
        break;
    case '/':
        // بررسی تقسیم بر صفر
        if (num2 != 0) {
            result = num1 / num2;
        }
        else {
            cout << "Error: Division by zero!" << endl;
            validOperator = false;
        }
        break;
    case '^':
        // تابع بازگشتی برای محاسبه توان
        result = 1;
        for (int i = 0; i < num2; ++i) {
            result *= num1;
        }
        break;
    case '%':
        // بررسی باقی مانده
        if (num2 != 0) {
            result = fmod(num1, num2);
        }
        else {
            cout << "Error: Modulus by zero!" << endl;
            validOperator = false;
        }
        break;
    default:
        cout << "Error: Invalid operator!" << endl;
        validOperator = false;
    }

    // چاپ نتیجه اگر عملگر معتبر بود
    if (validOperator) {
        cout << "Result: " << result << endl;
    }
}

int main() {
    double num1, num2;
    char op;

    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter operator (+, -, *, /, ^, %): ";
    cin >> op;
    cout << "Enter second number: ";
    cin >> num2;

    // فراخوانی تابع ماشین حساب
    calculator(num1, num2, op);

    return 0;
}
