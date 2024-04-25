struct node {
	int data;
	node* left;
	node* right;
};

class binary_tree {
	node* _root;

public:
	binary_tree();
	binary_tree(const int val);

	int get_root_value();
	
};
