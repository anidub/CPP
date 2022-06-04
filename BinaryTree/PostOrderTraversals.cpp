#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <stack>
#include <vector>

/*
 * https://leetcode.com/problems/binary-tree-postorder-traversal/discuss/1678315/C%2B%2B-3-solutions-1-recursive-and-two-iterative-with-one-or-two-stack
 * https://leetcode.com/problems/binary-tree-postorder-traversal/
 * https://leetcode.com/problems/binary-tree-postorder-traversal/discuss/45648/3-ways-of-Iterative-PostOrder-Traversing-(Morris-traversal)
 */
using namespace std;

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

void postOrderTraversalRecursive(BNode* root);
vector<int> postOrderTraversalIterative1Stack(BNode* root, vector<int>& traversals);
/*https://www.geeksforgeeks.org/morris-traversal-for-postorder/
 *  Time Complexity: O(N). sc:o(1)
 */
vector<int> postOrderTraversalIterativeMorrisTraversal(BNode* root) {
	if(root == nullptr) return {};
	vector<int> res;
	BNode* cur = root;

	while(cur != nullptr) {
		if(cur->right == nullptr) {
			res.push_back(cur->data);
			cur = cur->left;
		} else {
			BNode* predecessor = cur->right;
			while(predecessor->left != nullptr && predecessor->left != cur) {
				predecessor = predecessor->left;
			}
			if(predecessor->left == nullptr) {
				res.push_back(cur->data);
				predecessor->left = cur;
				cur = cur->right;
			} else {
				predecessor->left = nullptr;
				cur = cur->left;
			}
		}
	}
	reverse(res.begin(), res.end());
	return res;
}


void postOrderTraversalRecursive(BNode* root) {
	if(root == NULL) return;

	postOrderTraversalRecursive(root->left);
	postOrderTraversalRecursive(root->right);
	cout << root->data << " ";
}


vector<int> postOrderTraversalIterative1Stack(BNode* root, vector<int>& traversals) {
			vector<int> nodes;
			BNode* node = root, *last = nullptr;
	        stack<BNode*> stk;

	        while(!stk.empty() || node) {
	            if(node) {
	                stk.push(node);
	                node = node->left;
	            } else {
	            	BNode* temp = stk.top();
	                if(temp->right && last != temp->right) {
	                    node = temp->right;
	                } else {
	                    nodes.push_back(temp->data);
	                    last = temp;
	                    stk.pop();
	                }
	            }
	        }
	        return nodes;
}
/*
int main() {
	BNode* root = new BNode(15);

	delete root;

	return 0;
}*/
