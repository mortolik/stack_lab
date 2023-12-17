#include "../my_stack/TStack.h"

#include "gtest.h"

TEST(TStack, can_create_stack_with_positive_size)
{
  ASSERT_NO_THROW(TStack<int> st(3));
}
TEST(TStack, cant_create_stack_with_negative_size)
{
    ASSERT_ANY_THROW(TStack<int> st(-12));
}

TEST(TStack, can_get_length)
{
    TStack<int> st(3);
 

  EXPECT_EQ(-1, st.get_CurrInd());
}


TEST(TStack, new_stack_is_empty)
{
    TStack<int> st(3);

    int status = st.Empty();

  EXPECT_EQ(1, status);
}


TEST(TStack, can_push_and_pop)
{
    TStack<int> st(5);
    int a1 = 1;
    int a2 = 2;
    int a3 = 3;
    ASSERT_NO_THROW(st.Push(a1));
    ASSERT_NO_THROW(st.Push(a2));
    ASSERT_NO_THROW(st.Push(a3));
    int b1, b2, b3;
    ASSERT_NO_THROW( b1 = st.Pop());
    ASSERT_NO_THROW( b2 = st.Pop());
    ASSERT_NO_THROW( b3 = st.Pop());
    EXPECT_EQ(a1, b3); 
    EXPECT_EQ(a2, b2);
    EXPECT_EQ(a3, b1);  
}




TEST(TStack, throws_when_use_pop_on_empty_stack)
{
    TStack<int> st(3);
  ASSERT_ANY_THROW(st.Pop());
}

TEST(TStack, throws_when_use_push_on_overflow_stack)
{
    TStack<int> st(3);
    st.Push(1);
    st.Push(1);
    st.Push(1);
    ASSERT_ANY_THROW(st.Push(1));
}

TEST(TStack, throws_when_use_element_index_on_empty_stack)
{
    TStack<int> st(3);
 
    ASSERT_ANY_THROW(st.IndEl());
}

TEST(TStack, return_true_when_use_Full_on_full_stack)
{
    TStack<int> st(3);
    st.Push(1);
    st.Push(1);
    st.Push(1);
    bool b1 = st.Full();
    EXPECT_EQ(1, b1);
}
TEST(TStack, return_false_when_use_Full_on_not_full_stack)
{
    TStack<int> st(3);
    st.Push(1);
    st.Push(1);
   
    bool b1 = st.Full();
    EXPECT_EQ(0, b1);
}
TEST(TStack, return_true_when_use_Empty_on_empty_stack)
{
    TStack<int> st(3);
   
    bool b1 = st.Empty();
    EXPECT_EQ(1, b1);
}
TEST(TStack, return_false_when_use_Empty_on_not_empty_stack)
{
    TStack<int> st(3);
    st.Push(1);
    st.Push(1);

    bool b1 = st.Empty();
    EXPECT_EQ(0, b1);
}

