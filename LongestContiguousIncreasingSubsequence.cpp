#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>

using namespace std;
/*
 * https://leetcode.com/problems/longest-continuous-increasing-subsequence/
 * Given an unsorted array of integers nums, return the length of the longest continuous increasing subsequence (i.e. subarray). The subsequence must be strictly increasing.
A continuous increasing subsequence is defined by two indices l and r (l < r) such that it is [nums[l], nums[l + 1], ..., nums[r - 1], nums[r]] and for each l <= i < r, nums[i] < nums[i + 1].
Example 1:
Input: nums = [1,3,5,4,7]
Output: 3
Explanation: The longest continuous increasing subsequence is [1,3,5] with length 3.
Even though [1,3,5,7] is an increasing subsequence, it is not continuous as elements 5 and 7 are separated by element
4.

https://leetcode.com/problems/longest-continuous-increasing-subsequence/discuss/107365/JavaC%2B%2BClean-solution //check comments for solution
 */

int findLengthOfLCIS(vector<int>& nums) {
	if(nums.size() == 0) return 0;
	int result = 0, count = 0;
	for(unsigned i = 0; i < nums.size(); i++) {
		if(i == 0)
			count = 1;
		else if(nums[i] > nums[i-1])
			count++;
		else {
			result = max(result, count);
			count = 1;
		}
	}
	result = max(result, count);
	return result;
}
/*
 * If asked for indices of start & end :
 * int findLengthOfLCIS(vector<int>& nums) {
         int result = 0, count = 0;
        int start = 0, end = 0;
        int currStart = 0, currEnd = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(i == 0) {
                count = 1;
                currStart = i;
            }
            else if(nums[i] > nums[i-1]){
                count++;
            } else {
                if(result < count) {
                    result = count;
                    currEnd = i-1;
                    end = currEnd;
                    start = currEnd - count + 1;
                }
                count = 1;

            }
        }
        if(result < count) {
            result = count;
            end = nums.size() - 1;
            start = currEnd - count;
        }
        cout << "start:" << start << " end " << end << endl;
        return result;
 }
 */
/*
int main() {
	vector<int> nums;
	nums.push_back(1);nums.push_back(3);nums.push_back(5);nums.push_back(4);nums.push_back(7);
	cout << findLengthOfLCIS(nums) << endl;
	return 0;
}*/
