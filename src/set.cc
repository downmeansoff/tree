#include <set.h>
#include <iostream>

//default constructor
binary_tree::binary_tree() : _root(nullptr) {};
//create tree with 1 node
binary_tree::binary_tree(const int val) : _root(new node{ val, nullptr, nullptr }) {};

int binary_tree::get_root_value() {
	return _root->data;//need for tests
}
