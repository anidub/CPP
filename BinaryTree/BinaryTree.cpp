#include <iostream>

using namespace std;
/*
 * https://www.bogotobogo.com/cplusplus/binarytree.php
 * https://gist.github.com/toboqus/def6a6915e4abd66e922
 * https://www.cprogramming.com/tutorial/lesson18.html
 * https://www.bogotobogo.com/index.php
 */
struct BinaryTreeNode{
	int value;
	BinaryTreeNode *left;
	BinaryTreeNode *right;
};

class BinaryTree{
public:
	BinaryTree();
	~BinaryTree();

	void insert(int key);
	BinaryTreeNode *search(int key);
	void destroy_tree();
	void inorder_print();
	void postorder_print();
	void preorder_print();

private:
	void destroy_tree(BinaryTreeNode *leaf);
	void insert(int key, BinaryTreeNode *leaf);
	BinaryTreeNode *search(int key, BinaryTreeNode *leaf);
	void inorder_print(BinaryTreeNode *leaf);
	void postorder_print(BinaryTreeNode *leaf);
	void preorder_print(BinaryTreeNode *leaf);

	BinaryTreeNode *root;
};


BinaryTree::BinaryTree(){
	root = NULL;
}

BinaryTree::~BinaryTree(){
	destroy_tree();
}

void BinaryTree::destroy_tree(BinaryTreeNode *leaf){
	if(leaf != nullptr) {
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		delete leaf;
	}
}

void BinaryTree::insert(int key, BinaryTreeNode *leaf){
	if(key < leaf->value) {
		if(leaf->left != nullptr) {
			insert(key, leaf->left);
		} else {
			root->left = new BinaryTreeNode;
			root->left->value = key;
			root->left->left = nullptr;
			root->left->right = nullptr;
		}
	} else {
		if(leaf->right != nullptr) {
			insert(key, leaf->right);
		} else {
			leaf->right = new BinaryTreeNode;
			leaf->right->value = key;
			leaf->right->left  = nullptr;
			leaf->right->right = nullptr;
		}
	}

}

void BinaryTree::insert(int key){
	if(root != nullptr) {
		insert(key, root);
	} else {
		root = new BinaryTreeNode;
		root->value = key;
		root->left = nullptr;
		root->right = nullptr;
	}
}

BinaryTreeNode *BinaryTree::search(int key, BinaryTreeNode *leaf){
	if(leaf != nullptr) {
		if(leaf->value == key) return leaf;
		else if(key < leaf->value)
			search(key, leaf->left);
		else
			search(key, leaf->right);
	} else {
		return nullptr;
	}
}

BinaryTreeNode *BinaryTree::search(int key){
	return search(key, root);
}

void BinaryTree::destroy_tree(){
	destroy_tree(root);
}

void BinaryTree::inorder_print(){
	inorder_print(root);
	cout << "\n";
}

void BinaryTree::inorder_print(BinaryTreeNode *leaf){// left ->center ->right
	if(leaf != nullptr) {
		inorder_print(leaf->left);
		cout << leaf->value << " ";
		inorder_print(leaf->right);
	}
}

void BinaryTree::postorder_print(){
	postorder_print(root);
	cout << "\n";
}

void BinaryTree::postorder_print(BinaryTreeNode *leaf){//left -> right ->center
	if(leaf != nullptr) {
		postorder_print(leaf->left);
		postorder_print(leaf->right);
		cout << leaf->value << " ";
	}
}

void BinaryTree::preorder_print(){
	preorder_print(root);
	cout << "\n";
}

void BinaryTree::preorder_print(BinaryTreeNode *leaf){ // center ->left -> right
	if(leaf != nullptr) {
		cout << leaf->value << " ";
		preorder_print(leaf->left);
		preorder_print(leaf->right);
	}
}
/*
int main(){
	//BinaryTree tree;
	BinaryTree *tree = new BinaryTree();

	tree->insert(10);
	tree->insert(6);
	tree->insert(14);
	tree->insert(5);
	tree->insert(8);
	tree->insert(11);
	tree->insert(18);

	tree->preorder_print();
	tree->inorder_print();
	tree->postorder_print();

	delete tree;
	return 0;

}
*/
