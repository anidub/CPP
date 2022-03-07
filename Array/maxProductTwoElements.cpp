#include <iostream>
#include <vector>

using namespace std;

/*
https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/
Given the array of integers nums, you will choose two different indices i and j of that array. Return the maximum value of (nums[i]-1)*(nums[j]-1).

		Example 1:

		Input: nums = [3,4,5,2]
		Output: 12
		Explanation: If you choose the indices i=1 and j=2 (indexed from 0), you will get the maximum value, that is, (nums[1]-1)*(nums[2]-1) = (4-1)*(5-1) = 3*4 = 12.
*/
int findMaxProduct(vector<int>& nums) {
	if(nums.size() == 0) return 0;

	int m1 = 0;
	int m2 = 0;

	for(auto i : nums) {
		if(i > m1){
			m2 = m1;
			m1 = i;
		} else if (i > m2 && i != m1) {
			m2 = i;
		}
	}

	return (m1-1) * (m2-1);

}
/*
int main() {
	vector<int> nums;
	nums.push_back(3);nums.push_back(4);nums.push_back(5);nums.push_back(2);
	return 0;
} */
