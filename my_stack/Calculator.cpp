#include "Calculator.h"


bool TCalculator::expression()
{
    if (c.IsEmpty() == false)
    {
        this->c.Clear();

    }
    int res = 0;
    for (int i = 0; i < inf.size(); i++)
    {
        if (inf[i] == '(')
        {
            c.Push(inf[i]);
        }
        if (inf[i] == ')')
        {
            if (!c.IsEmpty())
            {
                c.Pop();
            }
            else
                res = 1;
        }
    }
    if (!c.IsEmpty())
        res = 1;
    if (res == 0)
    {
        return true;
    }
    else
        return false;
}

void TCalculator::set_infix(std::string str)
{
    inf = str;
}
std::string TCalculator::get_infix()
{
    return inf;
}

double TCalculator::calc()
{
    string str = "(";
    str += inf;
    str += ")";

    c.Clear();
    d.Clear();
    char* tmp;
    double res;
    for (int i = 0; i < str.size(); i++)
    {

        if (str[i] == '(') c.Push(str[i]);
        if (str[i] >= '0' && str[i] <= '9' || str[i] == '.' || str[i] == ',')
        {
            double dou = strtod(&str[i], &tmp);
            int j = tmp - &str[i];
            i += j - 1;
            d.Push(dou);
        }
        if (str[i] == '(' && str[i + 1] == '-')
        {
            int j = i + 1;
            str.insert(j, 1, '0');
        }
        if (str[i] == '+' || str[i] == '-' || str[i] == '/' || str[i] == '*' || str[i] == '^')
        {
            char tmp = c.Pop();
            while (prioritet(str[i]) <= prioritet(tmp))
            {
                char op = tmp;
                tmp = c.Pop();
                if (op == '+' || op == '-' || op == '*' || op == '/' || op == '^')
                {
                    double op1 = d.Pop();
                    double op2 = d.Pop();
                    switch (op)
                    {
                    case '+':
                        res = op1 + op2;
                        break;
                    case  '-':
                        res = op2 - op1;
                        break;
                    case '*':
                        res = op1 * op2;
                        break;
                    case '/':
                        res = op2 / op1;
                        break;
                    case '^':
                        res = pow(op2, op1);
                        break;
                    default:
                        if (c.IsEmpty()) throw - 1;
                    }
                    d.Push(res);
                }
            }
            c.Push(tmp);
            c.Push(str[i]);
        }
        if (str[i] == ')')
        {
            char op = c.Pop();
            while (op != '(')
            {
                if (op == '+' || op == '-' || op == '*' || op == '/' || op == '^')
                {
                    double op1 = d.Pop();
                    double op2 = d.Pop();
                    switch (op)
                    {
                    case '+':
                        res = op1 + op2;
                        break;
                    case  '-':
                        res = op2 - op1;
                        break;
                    case '*':
                        res = op1 * op2;
                        break;
                    case '/':
                        res = op2 / op1;
                        break;
                    case '^':
                        res = pow(op2, op1);
                        break;
                    default:
                        if (c.IsEmpty()) throw - 1;
                    }
                    d.Push(res);
                }
                op = c.Pop();
            }
        }
    }
    return d.Pop();
}



