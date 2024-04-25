#include <set.h>
#include <gtest/gtest.h>
#include<iostream>

TEST(set_test, constructor_params) {
	binary_tree set{ 1 };
	ASSERT_EQ(set.get_root_value(), 1);
}

