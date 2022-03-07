#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>

using namespace std;
/*
 * https://leetcode.com/problems/majority-element-ii/
 * Given an integer array of size n, find all elements that appear more than  n/3  times.
Follow-up: Could you solve the problem in linear time and in O(1) space?
Example 1:
Input: nums = [3,2,3]
Output: [3]
https://leetcode.com/problems/majority-element-ii/discuss/63571/My-C%2B%2B-Solution
 */
//O(N); space: O(1)
vector<int> majorityElementNby3(vector<int>& nums) {
	if(nums.empty()) return  {};
	vector<int> result;
	int count1 = 0, count2 = 0;
	int result1 = INT_MAX, result2 = INT_MAX;

	for(int& n : nums) {
		if(n == result1) count1++;
		else if(n == result2) count2++;
		else if(count1 == 0) {result1 = n; count1 = 1;}
		else if(count2 == 0) {result2 = n; count2 = 1;}
		else {
			count1--; count2--;
		}
	}

	count1 = count2 = 0;
	for(int& n : nums) {
		if(n == result1) count1++;
		else if(n == result2) count2++;
	}

	if(count1 > nums.size()/3) result.push_back(result1);
	if(count2 > nums.size()/3) result.push_back(result2);
	return result;
}
/*
int main() {
	vector<int> nums;
	nums.push_back(3);nums.push_back(2);nums.push_back(3);
	majorityElementNby3(nums);
	return 0;
}*/
