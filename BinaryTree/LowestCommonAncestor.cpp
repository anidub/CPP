#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <stack>
#include <unordered_set>

using namespace std;
//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
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

//assumes keys are present in tree
BNode* findLCAbothPresent(BNode* root, int n1, int n2) {
	if(root == NULL) return NULL;

	if(root->data == n1 || root->data == n2)
		return root;

	BNode* leftLCA = findLCAbothPresent(root->left, n1, n2);
	BNode* rightLCA = findLCAbothPresent(root->right, n1, n2);

	if(leftLCA && rightLCA) return root;

	return leftLCA != NULL ? leftLCA : rightLCA;
}

//assumes keys are present in tree
BNode* findLCiterative(BNode* root, BNode* p, BNode* q) {
	if(root == NULL) return NULL;
	unordered_map<BNode*, BNode*> parent;
	parent[root] = NULL;
	stack<BNode*> st;
	st.push(root);

	while(!parent[p] || !parent[q]) {
		BNode* node = st.top(); st.pop();
		if(node->left) {
			parent[node->left] = node;
			st.push(node->left);
		}
		if(node->right) {
			parent[node->right] = node;
			st.push(node->right);
		}
	}
	unordered_set<BNode*> ancestor;
	while(p) {
		ancestor.insert(p);
		p = parent[p];
	}
	while(ancestor.find(q) == ancestor.end()) {
		q = parent[q];
	}
	return q;
}

bool findBNode(BNode* root, int k) {
	if(root == NULL) return false;
	if(root->data == k || findBNode(root->left, k) || findBNode(root->right, k))
		return true;

	return false;
}

BNode* findLCAbothNotPresent(BNode* root, BNode* p, BNode* q) {
	if(root == NULL) return NULL;
	bool v1 = findBNode(root, p->data);
	bool v2 = findBNode(root, q->data);

	if(!v1 || !v2) return NULL;
	else return findLCAbothPresent(root, p->data, q->data);
}

//https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/235.%20Lowest%20Common%20Ancestor%20of%20a%20Binary%20Search%20Tree.cpp
BNode* LCAinBST(BNode* root, BNode* p, BNode* q) {
	BNode* cur = root;
	while(cur != NULL) {
		if(p->data > cur->data && q->data > cur->data)
			cur = cur->right;
		else if(p->data < cur->data && q->data < cur->data)
			cur = cur->left;
		else
			return cur;
	}
	return NULL;
}

//when access to parent
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
/*https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-iii/discuss/937341/C%2B%2B-in-7-Lines-with-100-Fast-Space-and-Time
https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-iii/
*/
Node* getLCAParent(Node* p, Node* q) {
	Node* a = p;
	Node* b = q;
	while(a != b) {
		a = a == nullptr ? q : a->parent;
		b = b == nullptr ? p : b->parent;
	}
	return a;
}
/*
int main() {
	BNode * root = new BNode(1);
    root->left = new BNode(2);
    root->right = new BNode(3);
    root->left->left = new BNode(4);
    root->left->right = new BNode(5);
    root->right->left = new BNode(6);
    root->right->right = new BNode(7);

    BNode* p = new BNode(4);
    BNode* q = new BNode(5);

    BNode* lca = findLCAbothPresent(root, 4, 5);

    lca = findLCAbothNotPresent(root, p, q);

   // lca = findLCiterative(root, p, q); //works in leetcode
    if(lca == NULL) cout << "NULL";
    else cout << "LCA:" << lca->data;

	return 0;
}*/
