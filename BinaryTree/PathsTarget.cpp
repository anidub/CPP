#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;
/*https://leetcode.com/problems/path-sum-iii/
 * Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.
The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).
Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
Output: 3
Explanation: The paths that sum to 8 are shown.

https://leetcode.com/problems/path-sum-iii/discuss/401013/Easy-C%2B%2B-Solution-using-dfs

https://leetcode.com/problems/path-sum-iii/discuss/779575/C%2B%2B-DFS-Based-Solution-Explained-~100-Time-~75-Space : used
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

int pathSumUtil(BNode* root, int targetSum);
int pathSum(BNode* root, int targetSum) { //O(N2)
	if(!root) return 0;

	return pathSumUtil(root, targetSum) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
}

int pathSumUtil(BNode* root, int targetSum) {
	if(!root) return 0;
	int count = 0;
	if(root->data == targetSum) count++;
	count += pathSumUtil(root->left, targetSum - root->data);
	count += pathSumUtil(root->right, targetSum - root->data);

	return count;
}
/* used! //works
int result = 0, sum;
unordered_map<int, int> seen;

int pathSumOptimal(BNode* root, int targetSum);
//void  pathSumOptimalUtil(BNode* root, int partial_sum = 0);

int pathSumOptimal(BNode* root, int targetSum) {
	if(!root) return result;

	sum = targetSum;
	seen[0] = 1; // seen set with initial value 0 will help us match from the root
	// pathSumOptimalUtil(root); //works
	return result;
}

void  pathSumOptimalUtil(BNode* root, int partial_sum = 0) {
	partial_sum += root->data;// updating partialSum with the current node

	result += seen[partial_sum - sum];// checking if we already found an interval summing up to that

	seen[partial_sum]++;// updating seen

	 if (root->left) pathSumOptimalUtil(root->left, partial_sum);
	 if (root->right) pathSumOptimalUtil(root->right, partial_sum);

	seen[partial_sum]--;// clearing seen of the last value, for backtracking purposes
}*/

/*
int main() {
	BNode* root = new BNode(20);
	root->left = new BNode(8);
	root->left->left = new BNode(4);
	root->left->right = new BNode(12);
	root->left->right->left = new BNode(10);
	root->left->right->right = new BNode(14);
	cout << pathSum(root, 12) << endl;
	//cout << pathSumOptimal(root, 12) << endl;


	delete root;
	return 0;
}*/
