#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <vector>
#include <utility>
#include <unordered_map>

using namespace std;

/*https://www.educative.io/courses/grokking-the-coding-interview/3j9V2QL3Ky9
 * Given a number ‘n’, write a function to return all structurally unique Binary Search Trees (BST) that can store values 1 to ‘n’?
 *Input: 2
Output: List containing root nodes of all structurally unique BSTs.
Explanation: Here are the 2 structurally unique BSTs storing all numbers from 1 to 2:
 */
class TreeNode {
 public:
  int val = 0;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int x) { val = x; }
};

class UniqueTrees {
public:
	//TC: O(N * 2 ^ N), SC:O(2 ^ N)
	vector<TreeNode*> uniqueTrees(int n) {
		if(n <= 0) return vector<TreeNode*>();
		return uniqueTreesHelper(1, n);
	}

	vector<TreeNode*> uniqueTreesHelper(int start, int end) {
		vector<TreeNode*> result;
		if(start > end) {
			result.push_back(nullptr);
			return result;
		}

		for(int i = start; i <= end; i++) {
			vector<TreeNode*> leftSubtrees = uniqueTreesHelper(start, i - 1);
			vector<TreeNode*> rightSubtrees = uniqueTreesHelper(i + 1, end);

			for(auto leftTree : leftSubtrees) {
				for(auto righTree : rightSubtrees) {
					TreeNode* node = new TreeNode(i);
					node->left = leftTree;
					node->right = righTree;
					result.push_back(node);
				}
			}
		}
		return result;
	}

	/*https://www.educative.io/courses/grokking-the-coding-interview/gx6BMKoWqR9
		Given a number ‘n’, write a function to return the count of structurally unique Binary Search Trees (BST) that can store values 1 to ‘n’.
		Input: 2
		Output: 2
		Explanation: As we saw in the previous problem, there are 2 unique BSTs storing numbers from 1-2.
	*/
	//TC: O(N^2), SC: O(N)
	unordered_map<int, int> mapCount = unordered_map<int, int>();
	int countUniqueTrees(int n) {
		if(mapCount.find(n) != mapCount.end())
			return mapCount[n];

		if(n <= 1) return 1;
		int count = 0;

		for(int i = 1; i <= n; i++) {
			int countLeftTrees = countUniqueTrees(i - 1);
			int countRightTrees = countUniqueTrees(n - i);
			count += countLeftTrees * countRightTrees;
		}
		mapCount[n] = count;
		return count;
	}
};

/*
int main(int argc, char *argv[]) {
	UniqueTrees ut;
  vector<TreeNode *> result = ut.uniqueTrees(2);
  cout << "Total trees: " << result.size() << endl;

  result = ut.uniqueTrees(3);
  cout << "Total trees: " << result.size() << endl;
}
*/
