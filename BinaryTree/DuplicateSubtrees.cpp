#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <vector>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/find-duplicate-subtrees/
 * Given the root of a binary tree, return all duplicate subtrees.

For each kind of duplicate subtrees, you only need to return the root node of any one of them.

Two trees are duplicate if they have the same structure with the same node values.
Input: root = [1,2,3,4,null,2,4,null,null,4]
Output: [[2,4],[4]]
https://leetcode.com/problems/find-duplicate-subtrees/discuss/106014/8-lines-C%2B%2B
///https://leetcode.com/problems/find-duplicate-subtrees/discuss/1258318/C%2B%2B-oror-Easy-and-Concise-Inorder-Traversal
 * I think the complexity is O(N^2). It creates N strings representing the serializations of the sub-trees for each node,
 *  and it calculates a hash value for each sting, and the length of these strings is O(N).
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

string findDuplicateSubtreesDFS(BNode* root, unordered_map<string, int>& map, vector<BNode*>& res);
//Time:O(n), sc:o(n^2)

vector<BNode*> findDuplicateSubtrees(BNode* root) {
	if(!root) return {};
	unordered_map<string, int> map;
	vector<BNode*> res;
	findDuplicateSubtreesDFS(root, map, res);
	return res;
}

string findDuplicateSubtreesDFS(BNode* root, unordered_map<string, int>& map, vector<BNode*>& res) {
	if(!root) return "";
	string s = to_string(root->data) +"," + findDuplicateSubtreesDFS(root->left, map, res) + "," + findDuplicateSubtreesDFS(root->right, map, res);
	if(map[s] == 1) res.push_back(root); // means it is already present
	map[s]++;
	return s;
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

    findDuplicateSubtrees(root);
    delete root;

	return 0;
}*/
