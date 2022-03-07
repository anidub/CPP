#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>

using namespace std;

/*
 * https://leetcode.com/problems/degree-of-an-array/
 * iven a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.

Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.
Example 1:
Input: nums = [1,2,2,3,1]
Output: 2
Explanation:
The input array has a degree of 2 because both elements 1 and 2 appear twice.
Of the subarrays that have the same degree:
[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
The shortest length is 2. So return 2.

https://leetcode.com/problems/degree-of-an-array/discuss/124317/JavaC%2B%2BPython-One-Pass-Solution
 */
int findShortestSubarrayDegree(vector<int>& A) {
	if(A.size() == 0)
		return -1;

	unordered_map<int, int> countOccurances, firstOccurance;
	int result = 0, degree = 0;
	for(int i = 0; i < A.size(); i++) {
		if(firstOccurance.count(A[i]) == 0) firstOccurance[A[i]] = i;
		countOccurances[A[i]]++;
		if(countOccurances[A[i]] > degree) {
			degree = countOccurances[A[i]];
			result = i - firstOccurance[A[i]] + 1;
		} else if(countOccurances[A[i]] == degree){
			result = min(result, i - firstOccurance[A[i]] + 1);
		}
	}
	return result;
}
/*
int main() {
	vector<int> nums;
	nums.push_back(1);nums.push_back(2);nums.push_back(2);nums.push_back(3);nums.push_back(1);nums.push_back(4);nums.push_back(2);
	cout << findShortestSubarrayDegree(nums) << endl;

	return 0;
}*/
