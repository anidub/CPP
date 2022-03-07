#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>

using namespace std;
/*
 * https://haren-lin-1.gitbook.io/leetcode-training/string/ukn2.-perform-string-shifts
 * You are given a string s containing lowercase English letters, and a matrix shift, where shift[i] = [direction, amount]:
direction can be 0 (for left shift) or 1 (for right shift).
amount is the amount by which string s is to be shifted.
A left shift by 1 means remove the first character of s and append it to the end.
Similarly, a right shift by 1 means remove the last character of s and add it to the beginning.
Return the final string after all operations.
 * Example 1:
 * Input: s = "abc", shift = [[0,1],[1,2]]
Output: "cab"
Explanation:
[0,1] means shift to left by 1. "abc" -> "bca"
[1,2] means shift to right by 2. "bca" -> "cab"

Example 2:
Input: s = "abcdefg", shift = [[1,1],[1,1],[0,2],[1,3]]
Output: "efgabcd"
Explanation:
[1,1] means shift to right by 1. "abcdefg" -> "gabcdef"
[1,1] means shift to right by 1. "gabcdef" -> "fgabcde"
[0,2] means shift to left by 2. "fgabcde" -> "abcdefg"
[1,3] means shift to right by 3. "abcdefg" -> "efgabcd"

https://blog.csdn.net/qq_21201267/article/details/107095564
 */

string stringShiftOther(string s, vector<vector<int>>& shift) {
	int left = 0; int right = 0;
	for(auto& v : shift) {
		if(v[0] == 0)
			left += v[1];
		else
			right += v[1];
	}

	int n = abs(left - right) % s.size();

	if(left - right > 0){ //left shift
		return s.substr(n) + s.substr(0,n);
	} else
		return s.substr(s.size() - n) + s.substr(0, s.size() - n);
}

/*
int main() {
	vector<vector<int>> shifts;
	vector<int> nums1; vector<int> nums2;

	nums1.push_back(0);nums1.push_back(1);
	nums2.push_back(1);nums2.push_back(2);

	shifts.push_back(nums1);shifts.push_back(nums2);
	string s = "abc";
	cout << stringShiftOther(s, shifts) << endl;
	return 0;
}
*/
