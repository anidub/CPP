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

https://walkccc.me/LeetCode/problems/1597/
 */
struct Node {
    char val;
    Node *left;
    Node *right;
    Node() : val(' '), left(nullptr), right(nullptr) {}
    Node(char x) : val(x), left(nullptr), right(nullptr) {}
    Node(char x, Node *left, Node *right) : val(x), left(left), right(right) {}
};

Node* buildNode(char op, Node* right, Node* left) {
	return new Node(op, left, right);
}

char pop(stack<char> &ops) {
	const char op = ops.top(); ops.pop();
	return op;
}

Node* pop(stack<Node*> nodes) {
	Node* node = nodes.top(); nodes.pop();
	return node;
}

bool compare(char op1, char op2) {// return true if op1 is a operator and priority(op1) >= priority(op2)
	if(op1 == ')' || op1 == '(') return false;
	return op1 == '*' || op1 == '/' || op2 == '+' || op2 == '-';
}
//TC:O(N), SC:O(N)
Node* expTree(string s) {
	if(s.empty()) return nullptr;
	stack<char> ops;
	stack<Node*> nodes;

    for(const char &c : s) {
        if(isdigit(c)) {
            nodes.push(new Node(c));
        } else if(c == '(') {
            ops.push(c);
        } else if(c == ')') {
            while(ops.top() != '(') {
                nodes.push(buildNode(pop(ops), pop(nodes), pop(nodes)));
            }
            ops.pop();// remove '('
        } else {
            while(!ops.empty() && compare(ops.top(), c))
                nodes.push(buildNode(pop(ops), pop(nodes), pop(nodes)));
            ops.push(c);
        }
    }
    while(!ops.empty()) {
        nodes.push(buildNode(pop(ops), pop(nodes), pop(nodes)));
    }
    return nodes.top();
}


/*
int main() {
	BNode* expTr = expTree("3*4-2*5");
}*/
