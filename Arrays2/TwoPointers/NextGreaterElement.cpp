#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <queue>
#include <utility>

using namespace std;
/*Given a positive integer n, find the smallest integer which has exactly the same digits existing in the integer n and is greater in value than n. If no such positive integer exists, return -1.

Note that the returned integer should fit in 32-bit integer, if there is a valid answer but it does not fit in 32-bit integer, return -1.
 *https://leetcode.com/problems/next-greater-element-iii/discuss/186425/C%2B%2B-easy-to-understand-O(n)-time
 *explained well in soltuion
 */
//TC:O(N), TC: O(N)
int nextGreaterElement(int n) {
	string s = to_string(n);
	int i = s.size() - 1;

	for(; i >= 0; i--) {  // start from right find the number x which is smaller than the next one
		if(s[i] < s[i + 1])
			break;
	}
	if(i < 0) return -1;// if it doesn't exist, return -1

	for(int j = s.size() - 1; j > i; j--) {// find the number x' in the right side which is just greater than x
		if(s[j] > s[i]) {
			swap(s[j], s[i]);
			break;
		}
	}
	reverse(s.begin() + i + 1, s.end());// reverse right side to make it in increasing order
	long res = stol(s);
	return res > INT_MAX ? -1 : res; // check if the result is longer than 32-bits

}
/*
int main() {
	cout << nextGreaterElement(12) << endl;

	return 0;
}*/
