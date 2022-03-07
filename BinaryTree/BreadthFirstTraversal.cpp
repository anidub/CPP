#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <deque>
#include <queue>
#include <vector>

using namespace std;
/* Breadth first traversal using queue */
// level order print
class BNode{
public:
	int data;
	BNode *left;
	BNode *right;

	BNode(int data) {
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};


void BreadthFirstTraversal(BNode* root) {
	if(root == NULL) return;
	queue<BNode*> queue;
	queue.push(root);
	cout << root->data << " ";

	while(!queue.empty()) {
		BNode* node = queue.front();
		queue.pop();

		if(node->left){
			queue.push(node->left);
			cout << node->left->data << " ";
		}
		if(node->right) {
			queue.push(node->right);
			cout << node->right->data << " ";
		}
	}
	return;
}

int getLevelOfNode(BNode* root, int value, int level) {
	if(root == NULL) return -1;
	if(value == root->data) return level;
	else if(value < root->data)
		return getLevelOfNode(root->left, value, level+1);
	else
		return getLevelOfNode(root->right, value, level+1);
}

/*
int main() {
	BNode* root = new BNode(15);
	root->left = new BNode(10);
	root->right = new BNode(20);
	root->right->left = new BNode(16);
	root->right->right = new BNode(25);

	BreadthFirstTraversal(root);
	cout << endl;

	cout << getLevelOfNode(root, 25, 0);
	delete root;
	return 0;
}*/
