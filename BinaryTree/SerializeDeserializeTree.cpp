#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <stack>

using namespace std;
/*https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
 * Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer,
 *  or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your
serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a
string and this string can be deserialized to the original tree structure.
https://leetcode.com/problems/serialize-and-deserialize-binary-tree/discuss/74252/Clean-C%2B%2B-solution
 *
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
string serialize(BNode* root);
BNode* deserialize(string root);
BNode* deserializeUtil(string& data);
int deserializeGetVal(string& data);

string serializeIterative(BNode* root) {
    string ans;
    queue<BNode*> todo;
    todo.push(root);
    while (!todo.empty()) {
    	BNode* node = todo.front();
        todo.pop();
        ans += node ? to_string(node -> data) + " " : "# ";
        if (node) {
            todo.push(node -> left);
            todo.push(node -> right);
        }
    }
    return ans;
}

string serialize(BNode* root) {
	if(root == NULL) return "#";
	return to_string(root->data) + "," + serialize(root->left) + "," + serialize(root->right);
}

BNode* deserialize(string data) {
	return deserializeUtil(data);
}

BNode* deserializeUtil(string& data) {
	if(data[0] == '#') {
		if(data.size() > 1) data = data.substr(2);
		return NULL;
	} else {
		int val = deserializeGetVal(data);
		BNode* root = new BNode(val);
		root->left = deserializeUtil(data);
		root->right = deserializeUtil(data);
		return root;
	}
}

int deserializeGetVal(string& data) {
	int pos = data.find(',');
	int val = stoi(data.substr(0,pos));
	data = data.substr(pos+1);
	return val;
}
/*
int main() {

	return 0;
}*/
