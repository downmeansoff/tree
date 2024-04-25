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
	binary_tree(const binary_tree& other);

	void swap(binary_tree& other);
	binary_tree& operator=(binary_tree other);
	node* copy(node* root);
	bool equal(const node* first, const node* second);
	bool operator==(const binary_tree& second);
	bool contains(int key);
	bool insert(int key);

	int get_root_value();
	
};
