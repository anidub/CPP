#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
 * Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your
 * serialization/deserialization algorithm should work. You just need to ensure that a binary tree
 *  can be serialized to a string and this string can be deserialized to the original tree structure.
 */
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class SerializeDeserialize{
public:
	//TC:O(N), SC:O(N)
	string serialize(TreeNode* root) {
		if(root == nullptr) return "#";
		return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
	}

	//TC:O(N), SC:O(N)
	TreeNode* deserialize(string data) {
		return deserializeUtil(data);
	}

	TreeNode* deserializeUtil(string data) {
		if(data[0] == '#') {
			if(data.size() > 1)
				data = data.substr(2);
			return nullptr;
		} else {
			TreeNode* root = new TreeNode(helper(data));
			root->left = deserializeUtil(data);
			root->right = deserializeUtil(data);
			return root;
		}
	}

private:
	int helper(string &data) {
		int pos = data.find(',');
		int val = stoi(data.substr(0, pos));
		data = data.substr(pos + 1);
		return val;
	}
};
/*
int main() {
	SerializeDeserialize sd;

}

*/
