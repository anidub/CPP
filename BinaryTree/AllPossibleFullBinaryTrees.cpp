#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <map>
#include <vector>

using namespace std;
/*https://leetcode.com/problems/all-possible-full-binary-trees/
 * Given an integer n, return a list of all possible full binary trees with n nodes. Each node of each tree in the answer must have Node.val == 0.

Each element of the answer is the root node of one possible tree. You may return the final list of trees in any order.

A full binary tree is a binary tree where each node has exactly 0 or 2 children.

https://leetcode.com/problems/all-possible-full-binary-trees/solution/ :: needs cache

https://leetcode.com/problems/all-possible-full-binary-trees/discuss/166480/C%2B%2B-16-line
https://leetcode.com/problems/all-possible-full-binary-trees/discuss/340007/C%2B%2B-recursive-solution
used combo of above 2
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

map<int, vector<BNode*>> binaryMap;

vector<BNode*> allPossibleBinaryFullTrees(int N) {
// it is impossible to have a full binary tree on an even number of nodes (both left and right subtrees must be full, + 1 for the root makes it an odd number of nodes)
	if(binaryMap.count(N)) return binaryMap[N];
	if(N == 1) {
		BNode* n = new BNode(0);
		vector<BNode*> vec; vec.push_back(n);
		binaryMap[1] = vec;
		return binaryMap[1];

	}

	vector<BNode*> res;
	for(int k = 2; k < N; k += 2) {
		vector<BNode*> v1 = allPossibleBinaryFullTrees(k-1);
		vector<BNode*> v2 = allPossibleBinaryFullTrees(N-k);

		int n1 = v1.size(), n2 = v2.size();
		for(int i = 0; i < n1; i++) {
			for(int j = 0; j < n2; j++) {
				BNode* newNode = new BNode(0);
				newNode->left = v1[i];
				newNode->right = v2[j];
				res.push_back(newNode);
			}
		}
		binaryMap[N] = res;
		return binaryMap[N];
	}
}

/*
int main() {

	allPossibleBinaryFullTrees(7);

	return 0;
}*/
