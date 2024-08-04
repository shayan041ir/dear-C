// shayan rezayi
//  i use template in this code for fun
#include <iostream>
#include <stack>
#include <string>
using namespace std;
template <class T>
T getOperator(T op)
{
    if (op == '+' || op == '-')
    {
        return 1;
    }
    else if (op == '*' || op == '/')
    {
        return 2;
    }
    return 0;
}
template <class R>
R infixToPostfix(R expression)
{
    stack<char> operators;
    string postfix = "";

    for (int i = 0; i < expression[i]; i++)
    {
        if (isalnum(expression[i])) // برای برسی اینکه ایا حرف یا عدد است
        {
            postfix += expression[i];
        }
        else if (expression[i] == '(')
        {
            operators.push(expression[i]);
        }
        else if (expression[i] == ')')
        {
            while (!operators.empty() && operators.top() != '(')
            {
                postfix += operators.top();
                operators.pop();
            }
            operators.pop();
        }
        else
        {
            while (!operators.empty() && getOperator(expression[i]) <= getOperator(operators.top()))
            {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(expression[i]);
        }
    }

    while (!operators.empty())
    {
        postfix += operators.top();
        operators.pop();
    }

    return postfix;
}

int main()
{
    string infixExpression;
    cout << "pls enter Infix Expression: " << endl;
    getline(cin, infixExpression);
    string postfixExpression = infixToPostfix(infixExpression);

    cout << "Infix Expression: " << infixExpression << endl;
    cout << "Postfix Expression: " << postfixExpression << endl;

    return 0;
}
