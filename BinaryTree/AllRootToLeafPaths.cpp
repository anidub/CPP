#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <queue>
#include <vector>

using namespace std;
/*https://leetcode.com/problems/binary-tree-paths/
 * Given the root of a binary tree, return all root-to-leaf paths in any order.
 * https://leetcode.com/problems/binary-tree-paths/discuss/247162/C%2B%2B-recursivebacktrackingiterative
 *  * Input :     1
               /   \
              2     3
             / \   /  \
            4   5  6   7
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

vector<string> binaryTreePaths(BNode* root);
void  binaryTreePaths(BNode* root, string path, vector<string>& paths);
vector<string> binaryTreePathsIterative(BNode* root);

vector<string> binaryTreePaths(BNode* root) {
	vector<string> paths;
	string path;
	binaryTreePaths(root, path, paths);
	return paths;
}

void binaryTreePaths(BNode* root, string path, vector<string>& paths) {
	if(!root) return;

	path += (path.empty() ? "" : "->") + to_string(root->data);

	if(!root->left && !root->right) {
		paths.push_back(path);
	} else {
		binaryTreePaths(root->left, path, paths);
		binaryTreePaths(root->right, path, paths);
	}
}


vector<string> binaryTreePathsIterative(BNode* root) {
	if(!root) return {};

	vector<string> paths;
	queue<pair<BNode*, string>> queue;
	queue.push({root, to_string(root->data)});

	while(!queue.empty()) {
		pair<BNode*, string> p = queue.front();
		queue.pop();
		BNode* node = p.first;
		string path = p.second;
		if(!node->left && !node->right)
			paths.push_back(path);
		else {
			if(node->left)
				queue.push({node->left, path +  "->" + to_string(node->left->data)});
			if(node->right)
				queue.push({node->right, path + "->" + to_string(node->right->data)});
		}
	}
	return paths;
}
/*
int main() {
	BNode* root = new BNode(1);
    root->left = new BNode(2);
    root->right = new BNode(3);
    root->left->left = new BNode(4);
    root->left->right = new BNode(5);
    root->right->left = new BNode(6);
    root->right->right = new BNode(7);


    vector<string> paths = binaryTreePathsIterative(root);

    for(auto& i : paths){
    	cout << i << "      ";
    }
    cout << endl;
    paths = binaryTreePaths(root);
    for(auto& i : paths){
    	cout << i << "      ";
    }
	delete root;
	return 0;
}*/
