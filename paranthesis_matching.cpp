#include <iostream>
#include <stack>
#include <string>

bool isMatching(char opening, char closing)
{
    return (opening == '(' && closing == ')') ||
           (opening == '{' && closing == '}') ||
           (opening == '[' && closing == ']');
}

bool isBalanced(const std::string &expression)
{
    std::stack<char> s;

    for (char ch : expression)
    {
        if (ch == '(' || ch == '{' || ch == '[')
        {
            s.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (s.empty() || !isMatching(s.top(), ch))
            {
                return false;
            }
            s.pop();
        }
    }

    return s.empty();
}

int main()
{
    std::string expression;
    std::cout << "Enter the expression: ";
    std::cin >> expression;

    if (isBalanced(expression))
    {
        std::cout << "Brackets balanced" << std::endl;
    }
    else
    {
        std::cout << "Brackets unbalanced" << std::endl;
    }

    return 0;
}
