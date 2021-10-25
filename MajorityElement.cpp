#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;
/*
 * https://leetcode.com/problems/majority-element/
 * Given an array nums of size n, return the majority element.
The majority element is the element that appears more than n/2 times. You may assume that the majority element always exists in the array.
Example 1:
Input: nums = [3,2,3]
Output: 3
Example 2:
Input: nums = [2,2,1,1,1,2,2]
Output: 2
 */

//moore's voting algo
//https://leetcode.com/problems/majority-element/discuss/613453/C%2B%2B-or-Moore's-voting
int majorityElement(vector<int>& nums) {
	if(nums.size() == 0) return -1;

	int count = 1, majority = nums[0];

	for(int i : nums) {
		if(i == majority)
			count++;
		else
			count--;

		if(count == 0){
			majority = i;
			count = 1;
		}
	}
	return majority;
}

//https://leetcode.com/problems/majority-element/discuss/834845/C%2B%2B-solution-or-O(n)
int majorityElementNth(vector<int>& nums) {
	if(nums.size() == 0) return -1;
	//https://en.cppreference.com/w/cpp/algorithm/nth_element
	nth_element(nums.begin(), nums.begin() + nums.size()/2, nums.end());
	return nums[nums.size()/2];
}
/*
int main() {
	vector<int> nums;
	nums.push_back(2);nums.push_back(2);nums.push_back(1);nums.push_back(1);
	nums.push_back(1);nums.push_back(2);nums.push_back(2);

	cout << majorityElement(nums) << endl;
	cout << majorityElementNth(nums) << endl;

	return 0;
}
*/
