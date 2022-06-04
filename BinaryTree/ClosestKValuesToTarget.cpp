#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <math.h>

using namespace std;
/*https://leetcode.com/problems/closest-binary-search-tree-value-ii/
 * Given the root of a binary search tree, a target value, and an integer k, return the k values in the BST that are closest to the target. You may return the answer in any order.

You are guaranteed to have only one unique set of k values in the BST that are closest to the target.
Input: root = [4,2,5,1,3], target = 3.714286, k = 2
Output: [4,3]

https://leetcode.com/problems/closest-binary-search-tree-value-ii/discuss/70488/Simple-C%2B%2B-solution-with-priority-queue

optimal:
https://leetcode.com/problems/closest-binary-search-tree-value-ii/discuss/692071/Clean-and-Short-C%2B%2B-(logn-%2B-k)-Solution-with-Clear-Explanation
https://leetcode.com/problems/closest-binary-search-tree-value-ii/discuss/70491/Concise-C%2B%2B-sol-using-2-stacks
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

void closesKValuesTargetDFS(BNode* root, priority_queue<pair<double, int>>& pq, double target, int k);
//TC:O(nlogk)
vector<int> closesKValuesTarget(BNode* root, double target, int k) {
	if(!root) return {};
	vector<int> result;
	priority_queue<pair<double, int>> pq;
	closesKValuesTargetDFS(root, pq, target, k);

	while(!pq.empty()) {
		result.push_back(pq.top().second);
		pq.pop();
	}
	return result;
}

void closesKValuesTargetDFS(BNode* root, priority_queue<pair<double, int>>& pq, double target, int k) {
	if(!root) return;
	pq.push(make_pair(fabs(target - (double)root->data), root->data));

	if(pq.size() > k)
		pq.pop();

	closesKValuesTargetDFS(root->left, pq, target, k);
	closesKValuesTargetDFS(root->right, pq, target, k);
}


//---------------------------------Stack approach-------------------------------------------------//
//https://leetcode.com/problems/closest-binary-search-tree-value-ii/discuss/70511/AC-clean-Java-solution-using-two-stacks : comments
//..if the tree is balanced, the time cost will be amortized O(k), and the space cost will be O(logN), but if the tree is not balanced, the worst space cost will be O(N)
void pushStack(BNode* root, double target, stack<BNode*>& pred, stack<BNode*>& succ);
//TC:O(N), SC:O(N)
vector<int> closesKValuesTargetLogN(BNode* root, double target, int k) {
    if(!root) return {};
    if(!root->left && !root->right) return {root->data};
            vector<int> res;
    stack<BNode*> pred; stack<BNode*> succ;
    // two stacks would both be pushed
    pushStack(root, target, pred, succ);

    while (k-- > 0) {
        if (succ.empty() || (!pred.empty() &&
            abs(pred.top()->data - target) < abs(succ.top()->data - target)) ) {
        	BNode* temp = pred.top();
            res.push_back(temp->data);
            pred.pop();
            // only pred stack would be pushed
            pushStack(temp->left, target, pred, succ);
        } else {
        	BNode* temp = succ.top();
            res.push_back(temp->data);
            succ.pop();
            // only succ stack would be pushed
            pushStack(temp->right, target, pred, succ);
        }
    }
    return res;
}

void pushStack(BNode* node, double target, stack<BNode*>& pred, stack<BNode*>& succ) {
    while (node) {
        if (target <= node->data) {
            succ.push(node);
            node = node->left;
        } else {
            pred.push(node);
            node = node->right;
        }
    }
}
/*
int main() {
    BNode* root = new BNode(4);
    root->left = new BNode(2);
    root->left->left = new BNode(1);
    root->left->right = new BNode(3);
    root->right = new BNode(5);

    closesKValuesTarget(root, 3.714286, 2);
    closesKValuesTargetLogN(root, 3.714286, 2);
    delete root;

	return 0;
}*/
