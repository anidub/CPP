#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <queue>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/maximum-swap/
 * You are given an integer num. You can swap two digits at most once to get the maximum valued number.

Return the maximum valued number you can get.
Input: num = 2736
Output: 7236
Explanation: Swap the number 2 and the number 7.
https://leetcode.com/problems/maximum-swap/discuss/107073/C%2B%2B-one-pass-simple-and-fast-solution%3A-1-3ms-O(n)-time

https://leetcode.com/problems/maximum-swap/discuss/976478/C%2B%2B-Simple-and-Efficient-O(n)-Solution-0ms-faster-than-100 : if to_str not allowed
 */
//TC O(N), space O(1)
int swapDigitsMax(int num) {
	if(num == 0) return 0;

	string str = to_string(num);

	int leftIdx = -1, rightIdx = -1, maxIdx = -1, maxdigit = -1;

	for(int i = str.size() - 1; i >= 0; i--) {
		if(str[i] > maxdigit) {
			maxdigit = str[i];
			maxIdx = i;
			continue;
		}
		if(str[i] < maxdigit) {
			leftIdx = i;
			rightIdx = maxIdx;
		}
	}
	if(leftIdx == -1) return num;

	swap(str[leftIdx], str[rightIdx]);

	return stoi(str);
}
/*
int main() {
	cout << swapDigitsMax(2736) << endl;

	return 0;
}*/
