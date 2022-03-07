#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <stack>
#include <vector>

using namespace std;
/*https://leetcode.com/problems/build-binary-expression-tree-from-infix-expression/
 * A binary expression tree is a kind of binary tree used to represent arithmetic expressions. Each node of a binary expression tree has either zero or two children. Leaf nodes (nodes with 0 children) correspond to operands (numbers), and internal nodes (nodes with 2 children) correspond to the operators '+' (addition), '-' (subtraction), '*' (multiplication), and '/' (division).

For each internal node with operator o, the infix expression that it represents is (A o B), where A is the expression the left subtree represents and B is the expression the right subtree represents.

You are given a string s, an infix expression containing operands, the operators described above, and parentheses '(' and ')'.

Return any valid binary expression tree, which its in-order traversal reproduces s after omitting the parenthesis from it (see examples below).

Please note that order of operations applies in s. That is, expressions in parentheses are evaluated first, and multiplication and division happen before addition and subtraction.

Operands must also appear in the same order in both s and the in-order traversal of the tree.

Input: s = "3*4-2*5"
Output: [-,*,*,3,4,2,5]
Explanation: The tree above is the only valid tree whose inorder traversal produces s.

https://leetcode.com/problems/build-binary-expression-tree-from-infix-expression/discuss/869209/C%2B%2B-recursive-with-look-for-specific-op-type
 */
class BNode{
public:
	char val;
	BNode *left;
	BNode *right;

	BNode(char val) {
		this->val = val;
		this->left = NULL;
		this->right = NULL;
	}
};

BNode* makeExpTree(string str, int start, int end);

BNode* expTree(string str) {
	return makeExpTree(str, 0, str.size() - 1);
}

BNode* makeExpTree(string str, int start, int end) {
	if(start > end) return nullptr;
	if(start == end) return new BNode(str[start]);

	int in_p = 0;

	for(int i = end; i >= start; i--) {
		char c = str[i];
		if(c == '+' || c =='-') {
			if(in_p > 0) continue;
			auto r = new BNode(c);
			r->right = makeExpTree(str, i + 1, end);
			r->left = makeExpTree(str, start, i-1);
			return r;
		} else if(c == ')')
			in_p++;
		else if(c == '(')
			in_p--;
 	}

	for(int i = end; i >= start; i--) {
		char c = str[i];
		if(c == '*' || c == '/') {
			if(in_p > 0) continue;
			auto r = new BNode(c);
			r->right = makeExpTree(str, i + 1, end);
			r->left = makeExpTree(str, start, i - 1);
			return r;
		} else if(c == ')')
			in_p++;
		else if(c == '(')
			in_p--;
	}

	return makeExpTree(str, start + 1, end - 1);
}
/*
int main() {
	BNode* expTr = expTree("3*4-2*5");
}*/
