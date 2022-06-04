#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

class TreeNode {
public:
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int x) {
		val = x;
		left = nullptr;
		right = nullptr;
	}
};
/*https://www.educative.io/courses/grokking-the-coding-interview/m280XNlPOkn
 * Given a binary tree and a number sequence, find if the sequence is present as a root-to-leaf path in the given tree.
 *
 */
class PathWitGivenSequence {
public:
	//TC:O(N), SC:O(N)
	bool findPathWithGivenSequence(TreeNode* root, vector<int> &sequence) {
		if(root == nullptr)
			return sequence.empty();

		return findPathWithGivenSequenceUtil(root, sequence, 0);
	}

	bool findPathWithGivenSequenceUtil(TreeNode *root, vector<int> &sequence, int index) {
		if(root == nullptr) return false;

		if(index >= sequence.size() || sequence[index] != root->val)
			return false;

		if(root->left == nullptr && root->right == nullptr && index == sequence.size() - 1)
			return true;

		return findPathWithGivenSequenceUtil(root->left, sequence, index + 1) ||
				findPathWithGivenSequenceUtil(root->right, sequence, index + 1);
	}
};
/*
int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(0);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(1);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(5);
  PathWitGivenSequence pgs;
  vector<int> s1 = {1, 0, 7};

  cout << "Tree has path sequence: " << pgs.findPathWithGivenSequence(root, s1)   << endl;
  vector<int> s2 = {1, 1, 6};
  cout << "Tree has path sequence: " <<  pgs.findPathWithGivenSequence(root, s2)  << endl;
}*/

