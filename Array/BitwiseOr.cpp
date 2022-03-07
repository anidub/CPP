#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <unordered_set>
#include <set>

using namespace std;
/*
 * https://leetcode.com/problems/bitwise-ors-of-subarrays/
 * We have an array arr of non-negative integers.
For every (contiguous) subarray sub = [arr[i], arr[i + 1], ..., arr[j]] (with i <= j), we take the bitwise OR of all the elements in sub, obtaining a result arr[i] | arr[i + 1] | ... | arr[j].
Return the number of possible results. Results that occur more than once are only counted once in the final answer
Example 1:
Input: arr = [0]
Output: 1
Explanation: There is only one possible result: 0.
https://leetcode.com/problems/bitwise-ors-of-subarrays/discuss/165859/C%2B%2B-O(kN)-solution
 */
//O(kN), where k is a constant depends on the bitwise length of input numbers. (32 in this problem)
//The | (bitwise OR) in C or C++ takes two numbers as operands and does OR on every bit of two numbers. The result of OR is 1 if any of the two bits is 1.
//intuition : get subarrays and store them in set r , then do bitwise for current element with those in r. store in s.
int subArrayBitwiseOr(vector<int>& arr) {
	unordered_set<int> s;
	set<int> t;

	for(int& i : arr) {
		set<int> r;
		r.insert(i);
		for(int j : t)
			r.insert(i | j);
		t = r;
		for(int j : t)
			s.insert(j);
	}
	return s.size();
}
/*
int main() {
	vector<int> arr;
	arr.push_back(1);arr.push_back(1);arr.push_back(2);
	cout << subArrayBitwiseOr(arr) << endl;

	return 0;
}*/
