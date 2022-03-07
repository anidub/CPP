#include <iostream>
#include <vector>

using namespace std;

/*
 * https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/
Given an array arr, replace every element in that array with the greatest element among the elements to its right, and replace the last element with -1.

After doing so, return the array.
		Input: arr = [17,18,5,4,6,1]
		Output: [18,6,6,6,1,-1]
		Explanation:
		- index 0 --> the greatest element to the right of index 0 is index 1 (18).
		- index 1 --> the greatest element to the right of index 1 is index 4 (6).
		- index 2 --> the greatest element to the right of index 2 is index 4 (6).
		- index 3 --> the greatest element to the right of index 3 is index 4 (6).
		- index 4 --> the greatest element to the right of index 4 is index 5 (1).
		- index 5 --> there are no elements to the right of index 5, so we put -1.
		*/

vector<int> replaceGreatest(vector<int>& nums) {
	if(nums.size() == 0) return {};
	int last = nums[nums.size() - 1];
	nums[nums.size() - 1] = -1;
	int max;
	for(int i = nums.size() - 2; i >= 0; --i) {
		max = nums[i];
		nums[i] = last;
		//last = std::max(max, last); works
	}
	for(int i : nums)
		cout << i << " ";
	return nums;
}

/*
int main() {
	vector<int> nums;
	nums.push_back(17);nums.push_back(18);nums.push_back(5);nums.push_back(4);
	nums.push_back(6);nums.push_back(1);
	replaceGreatest(nums);
	return 0;
} */

