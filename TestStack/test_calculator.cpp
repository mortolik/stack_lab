#include "../my_stack/Calculator.h"

#include "gtest.h"

TEST(TCalculator, can_create_calculator_with_positive_size_of_str)
{
    std::string a = "1+1";
    ASSERT_NO_THROW(TCalculator calc(a));
}
TEST(TCalculator, can_get_infix_form_of_calculator)
{
    std::string a="2+(3*5)";
    std::string b;
    TCalculator calc(a);
    ASSERT_NO_THROW(b=calc.get_infix());
    EXPECT_EQ(a, b);
}
TEST(TCalculator, can_set_infix_form_of_calculator)
{
    std::string a = "2+(3*5)";
    std::string b;
    TCalculator calc(a);
    ASSERT_NO_THROW(calc.set_infix(b));
    EXPECT_EQ(calc.get_infix(), b);
}
TEST(TCalculator, can_solve_big_ex)
{
    std::string a = "((5.5+2)*3)^2";
    double b = pow(((5.5 + 2) * 3), 2);
    TCalculator calculator(a);
    EXPECT_EQ(calculator.calc(), b);
}
TEST(TCalculator, check_expression_return_true_when_the_number_of_brackets_is_correct)
{
    std::string a = "2+(3*5)";
    
    
    TCalculator calc(a);
    bool check;
    ASSERT_NO_THROW(check=calc.expression());
    EXPECT_EQ(1, check);
}
TEST(TCalculator, check_expression_return_false_when_the_number_of_brackets_is_incorrect)
{
    std::string a = "2+((3*5)";


    TCalculator calc(a);
    bool check;
    ASSERT_NO_THROW(check = calc.expression());
    EXPECT_EQ(0, check);
}