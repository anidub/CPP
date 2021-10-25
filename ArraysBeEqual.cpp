#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
/*
 *
 * https://leetcode.com/problems/make-two-arrays-equal-by-reversing-sub-arrays/
Given two integer arrays of equal length target and arr.

In one step, you can select any non-empty sub-array of arr and reverse it. You are allowed to make any number of steps.

Return True if you can make arr equal to target, or False otherwise.
Input: target = [1,2,3,4], arr = [2,4,1,3]
Output: true
Explanation: You can follow the next steps to convert arr to target:
1- Reverse sub-array [2,4,1], arr becomes [1,4,2,3]
2- Reverse sub-array [4,2], arr becomes [1,2,4,3]
3- Reverse sub-array [4,3], arr becomes [1,2,3,4]
There are multiple ways to convert arr to target, this is not the only way to do so.
https://leetcode.com/problems/make-two-arrays-equal-by-reversing-sub-arrays/discuss/660729/C%2B%2B-or-HashMap
*/

bool canBeEqual(vector<int>& target, vector<int>& arr) {
	if(arr.size() != target.size()) return false;
	unordered_map<int, int> unorderedMap;
	for(int source : arr) {
		unorderedMap[source]++;
	}

	for(int targetNum : target) {
		unorderedMap[targetNum]--;
		if(unorderedMap[targetNum] == 0) unorderedMap.erase(targetNum);
	}

	if(unorderedMap.empty()) return true;
	return false;

}

/*
int main() {
	vector<int> nums;
	nums.push_back(1);nums.push_back(2);nums.push_back(3);nums.push_back(4);
	vector<int> nums1;
	nums1.push_back(2);nums1.push_back(4);nums1.push_back(1);nums1.push_back(3);
	cout << canBeEqual(nums1, nums);
	return 0;
} */
