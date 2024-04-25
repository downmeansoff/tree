#include <set.h>
#include <gtest/gtest.h>
#include<iostream>

TEST(tree_test, constructor_params) {
	binary_tree bt{ 1 };
	ASSERT_EQ(bt.get_root_value(), 1);
}

TEST(tree_test, overloaded_equal) {
	binary_tree set2(1);
	binary_tree set1 = set2;
	ASSERT_TRUE(set1 == set2);
}

TEST(tree_test, copy_constructor) {
	binary_tree bt(1);
	binary_tree copy(bt);
	ASSERT_TRUE(copy == bt);
}
