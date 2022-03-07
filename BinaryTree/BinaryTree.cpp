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
	if(leaf != NULL){
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		delete leaf;
	}
}

void BinaryTree::insert(int key, BinaryTreeNode *leaf){
	if(key < leaf->value){
		if(leaf->left != NULL){
			insert(key, leaf->left);
		}else{
			leaf->left = new BinaryTreeNode;
			leaf->left->value = key;
			leaf->left->left = NULL;
			leaf->left->right = NULL;
		}
	}else if(key >= leaf->value){
		if(leaf->right != NULL){
			insert(key, leaf->right);
		}else{
			leaf->right = new BinaryTreeNode;
			leaf->right->value = key;
			leaf->right->right = NULL;
			leaf->right->left = NULL;
		}
	}

}

void BinaryTree::insert(int key){
	if(root != NULL){
		insert(key, root);
	}else{
		root = new BinaryTreeNode;
		root->value = key;
		root->left = NULL;
		root->right = NULL;
	}
}

BinaryTreeNode *BinaryTree::search(int key, BinaryTreeNode *leaf){
	if(leaf != NULL){
		if(key == leaf->value){
			return leaf;
		}
		if(key < leaf->value){
			return search(key, leaf->left);
		}else{
			return search(key, leaf->right);
		}
	}else{
		return NULL;
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
	if(leaf != NULL){
		inorder_print(leaf->left);
		cout << leaf->value << ",";
		inorder_print(leaf->right);
	}
}

void BinaryTree::postorder_print(){
	postorder_print(root);
	cout << "\n";
}

void BinaryTree::postorder_print(BinaryTreeNode *leaf){//left -> right ->center
	if(leaf != NULL){
		inorder_print(leaf->left);
		inorder_print(leaf->right);
		cout << leaf->value << ",";
	}
}

void BinaryTree::preorder_print(){
	preorder_print(root);
	cout << "\n";
}

void BinaryTree::preorder_print(BinaryTreeNode *leaf){ // center ->left -> right
	if(leaf != NULL){
		cout << leaf->value << ",";
		inorder_print(leaf->left);
		inorder_print(leaf->right);
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

}*/
