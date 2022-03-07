#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <vector>
#include <utility>
#include <tuple>

using namespace std;
/*https://leetcode.com/problems/same-tree/
 * Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.
 * Input: p = [1,2,3], q = [1,2,3]
Output: true
https://leetcode.com/problems/same-tree/discuss/794503/C%2B%2B-simple-recursive-solution
https://leetcode.com/problems/same-tree/discuss/139171/C%2B%2B-Iterative-solution-using-std%3A%3Apair-and-queue
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

bool sameTreeDFS(BNode* p, BNode* q) {
	if(!(p) && !(q)) return true;
	else if(!p || !q) return false;
	else {
		if(p->data != q->data) return false;
		else
			return sameTreeDFS(p->left, q->left) && sameTreeDFS(p->right, q->right);
	}
}

bool sameTreeBFS(BNode* p, BNode* q) {
	if(!p && !q) return true;
	else if(!p || !q) return false;
	queue<pair<BNode*, BNode*>> que;

	que.push(make_pair(p,q));

	while(!que.empty()) {
		pair<BNode*, BNode*> front = que.front(); que.pop();
		if(!front.first && !front.second) continue;
		else if(!front.first || !front.second) return false;
		else {
			if(front.first->data != front.second->data) return false;
			else {
				que.push(make_pair(front.first->left, front.second->left));
				que.push(make_pair(front.first->right, front.second->right));
			}
		}
		return true;
	}
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

    BNode* root1 = new BNode(20);
    root1->left = new BNode(8);
    root1->left->left = new BNode(4);
    root1->left->right = new BNode(12);
    root1->left->right->left = new BNode(10);
    root1->left->right->right = new BNode(14);
    root1->right = new BNode(22);
    root1->right->right = new BNode(25);

    cout << sameTreeDFS(root, root1) << endl;
    cout << sameTreeBFS(root, root1) << endl;

    delete root; delete root1;

	return 0;
}*/
