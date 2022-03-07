#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <stack>
#include <vector>

using namespace std;
/*https://www.geeksforgeeks.org/print-path-root-given-node-binary-tree/
 * Print path from root to a given node in a binary tree
 * Input :        1
               /   \
              2     3
             / \   /  \
            4   5  6   7

               x = 5

Output : 1->2->5
 */
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
//O(n) in worst case, where n is the number of nodes in the binary tree.
bool printPathRootToNode(BNode* root, vector<int>& path, int x) {
	if(root == NULL) return false;

	path.push_back(root->data);

	if(root->data == x) return true;

	if(printPathRootToNode(root->left, path, x) || printPathRootToNode(root->right, path, x))
		return true;
	path.pop_back();
	return false;
}
/*
int main() {
	BNode* root = new BNode(1);
    root->left = new BNode(2);
    root->right = new BNode(3);
    root->left->left = new BNode(4);
    root->left->right = new BNode(5);
    root->right->left = new BNode(6);
    root->right->right = new BNode(7);

    vector<int> path;
    bool hasPath = printPathRootToNode(root, path, 6);
    if(hasPath){
    	for(int& i : path)
    		cout << i << " ";
    }
	delete root;

	return 0;
}*/
