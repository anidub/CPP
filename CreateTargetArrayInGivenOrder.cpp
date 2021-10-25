#include <iostream>
#include <vector>
#include <map>

using namespace std;
/*
https://leetcode.com/problems/create-target-array-in-the-given-order/
Given two arrays of integers nums and index. Your task is to create target array under the following rules:

Initially target array is empty.
From left to right read nums[i] and index[i], insert at index index[i] the value nums[i] in target array.
Repeat the previous step until there are no elements to read in nums and index.
Return the target array.

It is guaranteed that the insertion operations will be valid
Input: nums = [0,1,2,3,4], index = [0,1,2,2,1]
Output: [0,4,1,3,2]
Explanation:
nums       index     target
0            0        [0]
1            1        [0,1]
2            2        [0,1,2]
3            2        [0,1,3,2]
4            1        [0,4,1,3,2]
*/

vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
	vector<int> result;
	int n = nums.size();
	if(n == 0) return result;
	for(int i = 0; i < n; i++) {
		if(index[i] > result.size())
			result.push_back(nums[i]); //0
		else{
			result.insert(result.begin() + index[i], nums[i]); //
		}
	}
	for(int i : result)
		cout << i << " ";
	return result;
}

/*int main() {

	cout << "-------------------" << endl;
	vector<int> nums;
	nums.push_back(0);nums.push_back(1);
	nums.push_back(2);nums.push_back(3);
	nums.push_back(4);//nums.push_back(3);

	vector<int> nums1;
	nums1.push_back(0);nums1.push_back(1);
	nums1.push_back(2);nums1.push_back(2);
	nums1.push_back(1);//nums.push_back(3);
	createTargetArray(nums, nums1);
	return 0;
}*/
