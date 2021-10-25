#include <iostream>
#include <stdio.h>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/24-game/
 * You are given an integer array cards of length 4. You have four cards, each containing a number in the range [1, 9]. You should arrange the numbers on these cards in a mathematical
 * expression using the operators ['+', '-', '*', '/'] and the parentheses '(' and ')' to get the value 24.
You are restricted with the following rules:
The division operator '/' represents real division, not integer division.
For example, 4 / (1 - 2 / 3) = 4 / (1 / 3) = 12.
Every operation done is between two numbers. In particular, we cannot use '-' as a unary operator.
For example, if cards = [1, 1, 1, 1], the expression "-1 - 1 - 1 - 1" is not allowed.
You cannot concatenate numbers together
For example, if cards = [1, 2, 1, 2], the expression "12 + 12" is not valid.
Return true if you can get such expression that evaluates to 24, and false otherwise.
Example 1:

Input: cards = [4,1,8,7]
Output: true
Explanation: (8-4) * (7-1) = 24
https://leetcode.com/problems/24-game/discuss/107685/679.-24-Game-C%2B%2B-Recursive
 */
vector<char> operations{'+', '-', '*', '/'};

bool judge24DFS(vector<double>& vec) {
	if(vec.size() == 1) {
		return abs(vec[0] - 24) <= 0.0001;
	}

	for(int i = 0; i < vec.size(); i++) {
		for(int j = 0; j < vec.size(); j++) {
			if(i == j) continue;
			vector<double> result;
			for(int k = 0; k < vec.size(); k++) {
				if(k != i && k != j)
					result.push_back(vec[k]);
			}
			for(char& op : operations) {
				if((op == '+' || op == '*') && i > j) continue;
				if(op == '/' && vec[j] == 0.0) continue;
				switch(op) {
					case '+' : result.push_back(vec[i] + vec[j]); break;
					case '-' : result.push_back(vec[i] - vec[j]); break;
					case '*' : result.push_back(vec[i] * vec[j]); break;
					case '/' : result.push_back(vec[i] / vec[j]); break;
				}
				if(judge24DFS(result)) return true;
				result.pop_back();
			}
		}
	}
	return false;
}

bool judge24(vector<int>& cards) {
	vector<double> vec;
	for(int& n : cards){
		vec.push_back(n * 1.0);
	}
	return judge24DFS(vec);
}
/*
int main() {
	vector<int> cards;
	cards.push_back(4);cards.push_back(1);cards.push_back(8);cards.push_back(7);
	cout << judge24(cards) << endl;
	return 0;
}*/
