#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <utility>

using namespace std;
/*
 * https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/
 * You have n boxes. You are given a binary string boxes of length n, where boxes[i] is '0' if the ith box is empty, and '1' if it contains one ball.
In one operation, you can move one ball from a box to an adjacent box. Box i is adjacent to box j if abs(i - j) == 1. Note that after doing so, there may be more than one ball in some boxes.
Return an array answer of size n, where answer[i] is the minimum number of operations needed to move all the balls to the ith box.
Each answer[i] is calculated considering the initial state of the boxes.
Example 1:
Input: boxes = "110"
Output: [1,1,3]
Explanation: The answer for each box is as follows:
1) First box: you will have to move one ball from the second box to the first box in one operation.
2) Second box: you will have to move one ball from the first box to the second box in one operation.
3) Third box: you will have to move one ball from the first box to the third box in two operations, and move one ball from the second box to the third box in one operation.

https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/discuss/1075474/C%2B%2BJava-O(n)-LTR-%2B-RTL
https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/discuss/1076162/C%2B%2B-solution
https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/discuss/1075669/C%2B%2B-O(N)-keep-track-of-of-balls-to-the-right-and-left
https://www.youtube.com/watch?v=Eo_d1dKQuqM
 */

vector<int> minOperations(string boxes) {
	if(boxes.length() == 0) return {};
	vector<int> balls;
	vector<int> result(boxes.length(),0);
	for(int i = 0; i < boxes.length(); i++) {
		if(boxes[i] == '1')
			balls.push_back(i);
	}

	for(int i = 0; i < boxes.length(); i++) {
		for(int j = 0; j < balls.size(); j++) {
			result[i] += abs(balls[j] - i);
		}
	}
	for(int i : result) {
		cout << i << " ";
	}
	return result;
}

vector<int> minOperationsOptimal(string boxes) {
	if(boxes.length() == 0) return {};
	int sumLeft = 0; int sumRight = 0;
	int numLeft = 0; int numRight = 0;
	vector<int> result(boxes.size(),-1);

	for(int i = 0; i < boxes.length(); i++) {
		if(boxes[i] == '1'){
			numRight++;
			sumRight += i+1;
		}
	}

	for(int i = 0; i < boxes.length(); i++) {
		sumRight -= numRight;
		sumLeft += numLeft;

		result[i] = sumRight + sumLeft;
		if(boxes[i] == '1') {
			numRight--;
			numLeft++;
		}
	}
	for(int i : result) {
		cout << i << " ";
	}
	return result;
}
/*
int main() {
	string s = "001011";
	minOperations(s);
	cout << endl;
	minOperationsOptimal(s);

	return 0;
}
*/
