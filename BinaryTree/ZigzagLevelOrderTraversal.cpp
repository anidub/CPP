#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <stack>
#include <vector>

using namespace std;
/*https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
 * Given the root of a binary tree, return the zigzag level order traversal of its nodes' values.
 * (i.e., from left to right, then right to left for the next level and alternate between).
https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/discuss/34130/4ms-C%2B%2B-BFS-Solutions-with-Explanations

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
//check wheter stacks allowed or not
vector<vector<int>> zigzagTraversalStacks(BNode* root) {
	vector<vector<int>> levels;
	if(!root) return levels;

	stack<BNode*> curLevel, nextLevel;
	curLevel.push(root);
	bool isReversed = false;

	while(!curLevel.empty()) {
		vector<int> level;
		while(!curLevel.empty()) {
			BNode* node = curLevel.top();
			curLevel.pop();
			level.push_back(node->data);
			if(isReversed) {
				if(node->right) nextLevel.push(node->right);
				if(node->left) nextLevel.push(node->left);
			} else {
				if(node->left) nextLevel.push(node->left);
				if(node->right) nextLevel.push(node->right);
			}
		}
		levels.push_back(level);
		swap(curLevel, nextLevel);
		isReversed = !isReversed;
	}
	return levels;
}

vector<vector<int>> zigzagTraversalWithoutStacks(BNode* root) {
	vector<vector<int>> levels;
	if(!root) return levels;

	queue<BNode*> toVisit;
	toVisit.push(root);
	bool flag = false;
	int currentLevelNode = 1;

	while(!toVisit.empty()) {
		vector<int> level;
		for(int i = 0; i < currentLevelNode; i++) {
			BNode* node = toVisit.front();
			toVisit.pop();
			level.push_back(node->data);
			if(node->left) toVisit.push(node->left);
			if(node->right) toVisit.push(node->right);
		}
		if(flag) {
			reverse(level.begin(), level.end());
			flag = false;
		} else
			flag = true;
		levels.push_back(level);
		currentLevelNode = toVisit.size();
	}
	return levels;
}

vector<vector<int>> zigzagLevelOrderDFS(BNode* root);
void zigzagLevelOrderDFS(BNode* root, int curLevel, bool& nextLevel, vector<int>& level);

vector<vector<int>> zigzagLevelOrderDFS(BNode* root) {
	vector<vector<int>> levels;
	if(!root) return levels;

	bool nextLevel = true;
	int curLevel = 1;
	bool flag = false;
	while(nextLevel) {
		nextLevel = false;
		vector<int> level;
		zigzagLevelOrderDFS(root, curLevel++, nextLevel, level);
		if(flag) {
			reverse(level.begin(), level.end());
			flag = false;
		} else
			flag = true;
		levels.push_back(level);
	}
	return levels;
}

void zigzagLevelOrderDFS(BNode* node, int curLevel, bool& nextLevel, vector<int>& level) {
	if(!node) return;

	if(curLevel == 1) {
		level.push_back(node->data);
		if(node->left || node->right) nextLevel = true;
	} else {
		zigzagLevelOrderDFS(node->left, curLevel-1, nextLevel, level);
		zigzagLevelOrderDFS(node->right, curLevel-1, nextLevel, level);
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
	zigzagLevelOrderDFS(root);
	zigzagTraversalStacks(root);
	zigzagTraversalWithoutStacks(root);

	delete root;
	return 0;
}*/
