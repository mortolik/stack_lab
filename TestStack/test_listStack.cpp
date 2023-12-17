#include "../my_stack/TStack.h"

#include "gtest.h"
using namespace ListStack;
TEST(TStack, can_create_stack)
{
	ASSERT_NO_THROW(TStack<int> s);
}
TEST(TStack, can_push_elem_in_stack)
{
	int a = 1;
	TStack<int> s;
	ASSERT_NO_THROW(s.Push(a));
}
TEST(TStack, can_pop_elem_from_stack)
{
	int a;
	TStack<int> s;
	for (int i = 0; i < 5; i++)
	{
		s.Push(i);
	}
	ASSERT_NO_THROW(a = s.Pop());
}
TEST(TStack, can_look_top_elem_in_no_empty_stack)
{

	TStack<int> s;
	for (int i = 0; i < 5; i++)
	{
		s.Push(i);
	}
	ASSERT_NO_THROW(s.Top());
}
TEST(TStack, poped_elem_is_equal_to_top_elem)
{
	int a, k;
	TStack<int> s;
	for (int i = 0; i < 5; i++)
	{
		s.Push(i);
	}
	a = s.Top();
	k = s.Pop();
	EXPECT_EQ(a, k);
}
TEST(TStack, copied_stack_has_own_memory)
{
	TStack<int> s;
	TStack<int> l(s);
	for (int i = 0; i < 5; i++)
	{
		s.Push(i);
	}
	for (int i = 0; i < 5; i++)
	{
		l.Push(i + 1);
	}
	int a, k;
	a = s.Pop();
	k = l.Pop();
	EXPECT_NE(a, k);
}
TEST(TStack, can_clear_stack)
{
	TStack<int> s;
	for (int i = 0; i < 5; i++)
	{
		s.Push(i);
	}
	s.Clear();
	bool f = s.IsEmpty();
	EXPECT_EQ(1, f);
}
TEST(TStack, can_assign_stack_to_stack)
{
	TStack<int> s;
	TStack<int> l;
	ASSERT_NO_THROW(l = s);
}