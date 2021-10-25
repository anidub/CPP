#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>

using namespace std;
/*
 * https://leetcode.com/problems/frequency-of-the-most-frequent-element/
 * The frequency of an element is the number of times it occurs in an array.
You are given an integer array nums and an integer k. In one operation, you can choose an index of nums and increment the element at that index by 1.
Return the maximum possible frequency of an element after performing at most k operations.
Example 1:
Input: nums = [1,2,4], k = 5
Output: 3
Explanation: Increment the first element three times and the second element two times to make nums = [4,4,4].
4 has a frequency of 3.
https://leetcode.com/problems/frequency-of-the-most-frequent-element/discuss/1175090/JavaC%2B%2BPython-Sliding-Window
https://leetcode.com/problems/frequency-of-the-most-frequent-element/discuss/1175088/C%2B%2B-Maximum-Sliding-Window-Cheatsheet-Template! : used

https://www.youtube.com/watch?v=vgBrQ0NM5vE : understand
 */
int maxFrequencyFrequenctElement(vector<int>& nums, int k) {
	if(nums.empty()) return 0;
	sort(begin(nums), end(nums));
	long i = 0, result = 0, sum = 0;
	for(int j = 0; j < nums.size(); j++) {
		sum += nums[j];
		while( (j - i + 1) * nums[j] > sum + k) //here nums[j] is the one we want to make most frequent and we compare with sum
 			sum -= nums[i++];
		result = max(result, j - i + 1);
	}
	return result;
}
/*
int main() {
	vector<int> nums;
	nums.push_back(1);nums.push_back(2);nums.push_back(4);
	cout << maxFrequencyFrequenctElement(nums, 5) << endl;

	return 0;
}*/
