#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <stack>
#include <vector>

/*
 * https://leetcode.com/problems/binary-tree-postorder-traversal/discuss/1678315/C%2B%2B-3-solutions-1-recursive-and-two-iterative-with-one-or-two-stack
 * https://leetcode.com/problems/binary-tree-postorder-traversal/
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
void postOrderTraversalIterative2Stacks(BNode* root);
void postOrderTraversalIterative1Stack(BNode* root, vector<int>& traversals);

void postOrderTraversalIterative2Stacks(BNode* root) {
	if(root == NULL) return;
	stack<BNode*> s;
	s.push(root);

	stack<BNode*> out;

	while(!s.empty()) {
		BNode* curr = s.top();
		s.pop();

		out.push(curr);

		if(curr->left)
			s.push(curr->left);
		if(curr->right)
			s.push(curr->right);
	}

	while(!out.empty()){
		cout << out.top() << " ";
		out.pop();
	}
}


void postOrderTraversalRecursive(BNode* root) {
	if(root == NULL) return;

	postOrderTraversalRecursive(root->left);
	postOrderTraversalRecursive(root->right);
	cout << root->data << " ";
}


void postOrderTraversalIterative1Stack(BNode* root, vector<int>& traversals) {
	BNode* node = root;
	BNode* temp;
	stack<BNode*> st;

	while(!st.empty() || node) {
		if(node) {
			st.push(node);
			node = node->left;
		} else {
			temp = st.top()->right;
			if(!temp) {
				temp = st.top();
				st.pop();
				traversals.push_back(temp->data);
				while(!st.empty() && st.top()->right == temp) {
					temp = st.top();
					st.pop();
					traversals.push_back(temp->data);
				}
			} else
				node = temp;
		}
	}
}
/*
int main() {
	BNode* root = new BNode(15);

	delete root;

	return 0;
}*/
