#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <stack>
#include <vector>

using namespace std;

class BNode {
public:
	int val;
	BNode *left;
	BNode *right;

	BNode() : val(0), left(nullptr), right(nullptr) {}
	BNode(int x) : val(x), left(nullptr), right(nullptr) {}
	BNode(int x, BNode *left, BNode *right) : val(x), left(left), right(right) {}
};
/*https://leetcode.com/problems/construct-binary-tree-from-string/
 * You need to construct a binary tree from a string consisting of parenthesis and integers.

The whole input represents a binary tree. It contains an integer followed by zero, one or two pairs of parenthesis. The integer represents the root's value and a pair of parenthesis contains a child binary tree with the same structure.

You always start to construct the left child node of the parent first if it exists.
Input: s = "4(2(3)(1))(6(5))"
Output: [4,2,6,3,1,5]
https://leetcode.com/problems/construct-binary-tree-from-string/discuss/100378/C%2B%2B-Clean-Code

 */
BNode* buildStrToTree(string& s, int& i);

//TC: O(N), SC: O(H) H is height of tree
BNode* stringToTree(string s) {
	if(s.empty()) return nullptr;
	int i = 0;
	return buildStrToTree(s, i);
}

BNode* buildStrToTree(string& s, int& i) {
	if(i >= s.size()) return nullptr;

	int start = i;
	if(s[i] == '-') {
		i++;
	}

	while(i < s.size() && isdigit(s[i])) {
		i++;
	}

	int num = stoi( s.substr(start, i - start) );
	BNode* node = new BNode(num);

	if(s[i] == '(') {
		i++; // skip '('
		node->left = buildStrToTree(s, i);
		i++; //skip ')'
	}

	if(s[i] == '(') {
		i++; //skip '('
		node->right = buildStrToTree(s, i);
		i++; //skip ')'
	}
	return node;
}
/*
int main() {
	stringToTree("4(-2(3)(1))(6(5))");

	return 0;
}*/
