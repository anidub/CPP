#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <vector>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/count-good-nodes-in-binary-tree/
 *Given a binary tree root, a node X in the tree is named good if in the path from root to X there are no nodes with a value greater than X.

Return the number of good nodes in the binary tree.
Input: root = [3,1,4,3,null,1,5]
Output: 4
Explanation: Nodes in blue are good.
Root Node (3) is always a good node.
Node 4 -> (3,4) is the maximum value in the path starting from the root.
Node 5 -> (3,4,5) is the maximum value in the path
Node 3 -> (3,1,3) is the maximum value in the path.

 https://leetcode.com/problems/count-good-nodes-in-binary-tree/discuss/1408533/CC%2B%2B-Simple-Clean-and-Short-recursive-solution
 when using dfs try to use return over void

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


int getGoodNodesUtil(BNode* root, int max_val);

int getGoodNodes(BNode* root) {
	if(!root) return 0;
	return getGoodNodesUtil(root, root->data);
}

int getGoodNodesUtil(BNode* root, int max_val) {
	if(!root) return 0;

	max_val = max(max_val, root->data);

	if(root->data >= max_val)
		return 1 + getGoodNodesUtil(root->left, max_val) + getGoodNodesUtil(root->right, max_val);
	else
		return getGoodNodesUtil(root->left, max_val) + getGoodNodesUtil(root->right, max_val);

}
/*
int main() {
    BNode* root = new BNode(20);
    root->left = new BNode(8);
    root->left->left = new BNode(4);
    root->left->right = new BNode(12);
    root->left->right->left = new BNode(10);
    root->left->right->right = new BNode(14);
    root->right = new BNode(22);
    root->right->right = new BNode(25);

    cout << getGoodNodes(root) << endl;
    delete root;

	return 0;
}*/
