//
// Created by ASUS on 11/14/2023.
//

#include "RPN.h"


double RPN::evaluate(double left, char op, double right)
{
    switch (op) {
        case '+':
            return left + right;
        case '-':
            return left - right;
        case '*':
            return left * right;
        case '/':
            return left / right;
        case '^':
            return pow(left, right);
        default:
            std::cout << "Invalid\n";
            return 400;
    }
}

std::string RPN::toRPN(const std::string& infix)
{
    std::stack<char> operators_stack;
    std::string output;
    std::map<char, int> rank;

    rank['+'] = rank['-'] = 1;
    rank['*'] = rank['/'] = 2;

    for (char character : infix) {
        if (std::isdigit(character))
        {
            output += character;
        }
        else
        {
            while (!operators_stack.empty() && rank[operators_stack.top()] >= rank[character])
            {
                output += operators_stack.top();
                operators_stack.pop();
            }
            operators_stack.push(character);
        }
    }

    while (!operators_stack.empty()) {
        output += operators_stack.top();
        operators_stack.pop();
    }
    std::cout << output << std::endl;
    return output;
}

double RPN::evaluate(const std::string& postfixExpression)
{
    std::stack<int> s;
    double res;
    RPN rpn;

    for (const char & character : postfixExpression) {
        if (std::isdigit(character))
        {
            int num = character - '0';
            s.push(num);
        }
        else
        {
            int top_1 = s.top();
            s.pop();
            int top_2 = s.top();
            s.pop();

            res = rpn.evaluate(top_2, character, top_1);

            s.push(res);
        }
    }

    return res;
}
