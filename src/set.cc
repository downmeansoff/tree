#include <set.h>
#include <iostream>

//default constructor
binary_tree::binary_tree() : _root(nullptr) {};
//create tree with 1 node
binary_tree::binary_tree(const int val) : _root(new node{ val, nullptr, nullptr }) {};


binary_tree& binary_tree::operator=(binary_tree other) {// not const binary_tree& because you need a copy of other
	swap(other);//swap copy and this
	return *this;
}

void binary_tree::swap(binary_tree& other) {
	std::swap(_root, other._root);//overload swap for operator= (copy and swap idiom)
}

node* binary_tree::copy(node* root) {//method needs for copy constructor
	//creates a deep copy of the binary tree by recursively creating new nodes and copying the left and right subtrees.
	if (!root) return nullptr;//if other == null then copy = null
	node* new_node = new node{ root->data, root->left, root->right };//else create a new node
	new_node->left = copy(root->left);//recusively copy left subtree
	new_node->right = copy(root->right);//right
	return new_node;//returns new tree root
}

binary_tree::binary_tree(const binary_tree& other) {//copy constructor
	_root = copy(other._root); //just create new root 
}

int binary_tree::get_root_value() {
	return _root->data;//need for tests
}

bool binary_tree::contains(int key) {
	//since we have a search tree, the right side contains elements that are larger than the current one
	//and on the left - smaller
	node* tmp = _root;
	while (tmp) {//while root exists
		if (tmp->data == key) return true;//found
		if (tmp->data > key) {//if current value larger than key. look for in left subtree
			tmp = tmp->left;
		}
		else tmp = tmp->right;
	}
	return false;
}


bool binary_tree::insert(int key) {
	auto new_node = new node{ key, nullptr, nullptr };
	//replace head if head is null
	if (!_root) {
		_root = new_node;
		return true;
	}
	node* tmp = _root;

	while (tmp) {//while root exist try to find position for insert
		//if there is such a node, then we dont insert
		if (tmp->data == key) return false;
		//else find position for insert
		if (tmp->data > key) {//if current value larger than key. look for in left subtree
			if (!tmp->left) {//if node=nullptr insert new value
				tmp->left = new_node;
				return true;
			}
			tmp = tmp->left;
		}
		else {//search in right subtree
			if (!tmp->right) {//if node=nullptr insert new value
				tmp->right = new_node;
				return true;
			}
			tmp = tmp->right;
		}
	}
	return false;
}


bool binary_tree::equal(const node* first, const node* second) {//needs for operator==
	//params: first tree`s root and second`s root
	if (!first && !second) return true;//if both null 
	if (first && second) {//if both exists
		//check current data and recursively check left and right subtrees
		return first->data == second->data && equal(first->left, second->left) && equal(first->right, second->right);
	}
	return false;
}

bool binary_tree::operator==(const binary_tree& second) {
	return equal(_root,second._root);
}