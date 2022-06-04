#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <vector>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/house-robber-iii/
 * The thief has found himself a new place for his thievery again. There is only one entrance to this area, called root.

Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that
all houses in this place form a binary tree. It will automatically contact the police if two directly-linked houses were broken into on the same night.

Given the root of the binary tree, return the maximum amount of money the thief can rob without alerting the police.
https://leetcode.com/problems/house-robber-iii/discuss/1611899/C%2B%2B-or-with-and-without-memo-or-Detailed-explaination
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

int houseRobberUtil(BNode* root);
pair<int, int> houseRobberOptimalUtil(BNode* root);

unordered_map<BNode*, int> house_robber_memo;

int houseRobber(BNode* root) {
	if(!root) return 0;
	return houseRobberUtil(root);
}
int houseRobberUtil(BNode* root) {
	if(!root) return 0;

	if(house_robber_memo.count(root))
		return house_robber_memo[root];

	int ans_inc_root = root->data;
	if(root->left)
		ans_inc_root += houseRobberUtil(root->left->left) + houseRobberUtil(root->left->right);

	if(root->right)
		ans_inc_root += houseRobberUtil(root->right->left) + houseRobberUtil(root->right->right);

	int ans_not_root = houseRobberUtil(root->left) + houseRobberUtil(root->right);

	int ans = max(ans_inc_root, ans_not_root);

	house_robber_memo[root] = ans;

	return ans;
}

//TC:O(N), SC:O(N)
int houseRobberOptimal(BNode* root) {
	if(!root) return 0;
	pair<int, int> ans = houseRobberOptimalUtil(root);
	return max(ans.first, ans.second);
}

pair<int, int> houseRobberOptimalUtil(BNode* root) {
	if(!root) return {0,0};

	pair<int, int> left = houseRobberOptimalUtil(root->left);
	pair<int, int> right = houseRobberOptimalUtil(root->right);

	int root_house_robbed = left.second + right.second + root->data;

	int root_house_not_robbed = max(left.first, left.second) + max(right.first, right.second);

	pair<int, int> ans;
	ans.first = root_house_robbed, ans.second = root_house_not_robbed;
	return ans;
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

    cout << houseRobber(root) << endl;
    cout << houseRobberOptimal(root) << endl;
    delete root;

	return 0;
}
*/
