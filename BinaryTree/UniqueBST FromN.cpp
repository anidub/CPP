#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <vector>
#include <utility>
#include <tuple>

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
/*https://leetcode.com/problems/unique-binary-search-trees-ii/
 * Given an integer n, return all the structurally unique BST's (binary search trees), which has exactly n nodes of unique values from 1 to n. Return the answer in any order.
 * https://leetcode.com/problems/unique-binary-search-trees-ii/discuss/31597/30-ms-c%2B%2B-solution
 *
 *Time complexity : The main computations are to construct all possible trees with a given root, that is actually Catalan number Gn. This is done n times, that results in time complexity nGn

Space complexity : nGn as we keep Gn trees with n elements
 */
vector<BNode*> getUniqueBSTFromNDFS(int s,int e);

vector<BNode*> getUniqueBSTFromN(int n) {
	if(n == 0) return {};
	return getUniqueBSTFromNDFS(1, n);
}

vector<BNode*> getUniqueBSTFromNDFS(int s,int e) {
	if(s > e) return {nullptr};
	vector<BNode*> result;

	for(int i = s; i <= e; i++) {
		vector<BNode*> left = getUniqueBSTFromNDFS(s, i-1);
		vector<BNode*> right = getUniqueBSTFromNDFS(i+1, e);
		for(int j = 0; j < left.size(); j++) {
			for(int k = 0; k < right.size(); k++) {
				BNode* root = new BNode(i);
				root->left = left[j];
				root->right = right[k];
				result.push_back(root);
			}
		}
	}
	return result;
}
/*
int main() {
	getUniqueBSTFromN(3);
	return 0;
}
*/
