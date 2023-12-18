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
}/*

std::string TCalculator::get_postfix()
{
    return postf;
}*/

std::string TCalculator::get_infix()
{
    return inf;
}

//double TCalculator::CalcPostfix()
//{
//    if (d.IsEmpty() == false)
//    {
//        this->d.Clear();
//    }
//    for (int i = 0; i < postf.length(); i++)
//    {
//        if (postf[i] >= '0' && postf[i] <= '9')
//        {
//            d.Push(postf[i] - '0');
//        }
//        
//        
//        if ((postf[i] == '+') || (postf[i] == '-') || (postf[i] == '*') || (postf[i] == '/') || (postf[i] == '^'))
//        {
//                double x1 = 0; double x2 = 0;double  y = 0;
//                if (d.IsEmpty() == false)
//                {
//                    x2 = d.Pop();
//                }
//                if (d.IsEmpty() == false)
//                {
//                    x1 = d.Pop();
//                }
//                if (postf[i] == '+')
//                    y = x1 + x2;
//                if (postf[i] == '-')
//                    y = x1 - x2;
//                if (postf[i] == '*')
//                    y = x1 * x2;
//                if (postf[i] == '/')
//                    y = x1 / x2;
//                if (postf[i] == '^')
//                    y = pow(x1, x2);
//
//                d.Push(y);
//
//        }
//        
//    }
//    double res;
//    if(d.IsEmpty()==false)
//    {
//        res = d.Pop();
//    }
//    else
//    {
//        throw "IsEmpty stack.";
//    }
//
//    
//    if (!d.IsEmpty())
//    {
//        throw "Any problems with brackets.";
//    }
//   return res;
//}

//void TCalculator::CurrIndostfix()
//{
//    if (c.IsEmpty() == false)
//    {
//        this->c.Clear();
//    }
//    std::string str = '(' + inf + ')';
//    for (int i = 0; i < str.size(); i++)
//    {
//        if (str[i] == '(')
//        {
//            c.Push('(');
//        }
//        if (str[i] >= '0' && str[i] <= '9')
//        {
//            postf += str[i];
//        }
//        if (str[i] == ')')
//        {
//            char opelement = c.Pop();
//            while (opelement!='(')
//            {
//                postf += opelement;
//                opelement = c.Pop();
//            }
//        }
//        if ((str[i] == '+') || (str[i] == '-') || (str[i] == '*') || (str[i] == '/') || (str[i] == '^'))
//        {
//            char opelement = c.Pop();
//            if (prioritet(opelement) >= prioritet(str[i]))
//            {
//                postf += opelement;
//                opelement = c.Pop();
//            }
//            else
//            {
//                c.Push(opelement);
//            }
//            c.Push(str[i]);
//        }
//    }
//
//}
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
    //if (!(st_d.IsEmpty()))throw - 1;
    return d.Pop();
}//((2+5)*9)/((-1)*9)



