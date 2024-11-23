#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <map>
#include <vector>
#include <stack>
#include <utility>
#include <list>
#include <iterator>
#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;
/*https://leetcode.com/problems/design-an-expression-tree-with-evaluate-function/
 * Given the postfix tokens of an arithmetic expression, build and return the binary expression tree that represents this expression.
 *
 * postfix notation is a notation for writing arithmetic expressions in which the operands (numbers) appear before their operators. For example, the postfix tokens of the expression 4*(5-(7+2)) are represented in the array postfix = ["4","5","7","2","+","-","*"].
 *
 *The class Node is an interface you should use to implement the binary expression tree. The returned tree will be tested using the evaluate function, which is supposed to evaluate the tree's value. You should not remove the Node class; however, you can modify it as you wish, and you can define other classes to implement it if needed.

A binary expression tree is a kind of binary tree used to represent arithmetic expressions. Each node of a binary expression tree has either zero or two children. Leaf nodes (nodes with 0 children) correspond to operands (numbers), and internal nodes (nodes with two children) correspond to the operators '+' (addition), '-' (subtraction), '*' (multiplication), and '/' (division).

It's guaranteed that no subtree will yield a value that exceeds 109 in absolute value, and all the operations are valid (i.e., no division by zero).

Follow up: Could you design the expression tree such that it is more modular? For example, is your design able to support additional operators without making changes to your existing evaluate implementation?
 *
 * Input: s = ["3","4","+","2","*","7","/"]
Output: 2
Explanation: this expression evaluates to the above binary tree with expression ((3+4)*2)/7) = 14/7 = 2.

Input: s = ["4","5","2","7","+","-","*"]
Output: -16
Explanation: this expression evaluates to the above binary tree with expression 4*(5-(2+7)) = 4*(-4) = -16.

https://leetcode.com/problems/design-an-expression-tree-with-evaluate-function/discuss/915167/JavaC%2B%2B-Implementing-an-abstract-class
 */

class Node {
public:
	virtual ~Node() {};
	virtual int evaluate() const = 0;
protected:

};

class NumNode : public Node { // number node
public:
	NumNode(int val) : val(val) {};
	int evaluate() const {
		return val;
	};

protected:
	int val;
};

class OpNode : public Node { // operation node like +,-,*,/
public:
	OpNode(char op, Node *left, Node *right) : op(op), left(left), right(right) {}
	int evaluate() const;
protected:
	char op;
	Node *left;
	Node *right;
};



int OpNode::evaluate() const {
	switch(this->op) {
		case '+' :
			return left->evaluate() + right->evaluate();
		case '-' :
			return left->evaluate() - right->evaluate();
		case '*':
			return left->evaluate() * right->evaluate();
		case '/':
			return left->evaluate() / right->evaluate();
		default:
			return 0;
	}
}

class TreeBuilder {
public:
	Node *buildTree(vector<string>& postfix) {
		stack<Node*> st;
		for(auto s : postfix) {
			if(isdigit(s[0]))
				st.push(new NumNode(stoi(s)));
			else {
				auto r = st.top();
				st.pop();
				auto l = st.top();
				st.pop();
				st.push(new OpNode(s[0], l, r));
			}

		}
		return st.top();
	}
};
/*
int main() {
	 TreeBuilder* obj = new TreeBuilder();
	 vector<string> postfix = {"3","4","+","2","*","7","/"};
	 Node* expTree = obj->buildTree(postfix);
	 int ans = expTree->evaluate();
	 cout << ans << endl;

	return 0;
}*/
