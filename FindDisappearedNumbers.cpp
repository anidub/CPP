#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <set>
#include <unordered_map>

using namespace std;
/*
 * https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
 * Given an array of integers where 1 <= a[i] <=n (n = size of array), some elements appear twice and others appear once.
Find all the elements of [1, n] inclusive that do not appear in this array.
Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.
Example:
Input:
[4,3,2,7,8,2,3,1]
Output:
[5,6]

https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/discuss/92958/c%2B%2B-solution-O(1)-space
// O(n) Time and O(1) space.
 */
vector<int> findDisappearedNumbers(vector<int>& nums) {
	if(nums.size() == 0) return {};
	for(int i = 0; i < nums.size(); i++) {
		int temp = abs(nums[i])-1;
		nums[temp] = nums[temp] > 0 ? -nums[temp] : nums[temp];
	}

	vector<int> result;
	for(int i = 0; i < nums.size(); i++) {
		if(nums[i] > 0) result.push_back(i+1);
	}
	return result;
}
//https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/discuss/581023/C%2B%2B
vector<int> findDisappearedNumbersExplained(vector<int>& nums) {
	if(nums.size() == 0) return {};
    vector<int> ans;

    // 1st for loop: nums = [4,3,2,7,8,2,3,1]
    for(int i = 0; i < nums.size(); i++)  // each iteration:
    {                                     // i = 0              i = 1               i = 2                ... i = 7
        int temp = nums[i];               // temp = 4           temp = 3            temp = -2            ... temp = -1
        temp = (temp > 0) ? temp : -temp; // temp = 4           temp = 3            temp = 2             ... temp = 1
        if(nums[temp-1] > 0)              // nums[3] > 0        nums[2] > 0         nums[1] > 0          ... nums[0] > 0
            nums[temp-1] *= -1;           // [4,3,2,-7,8,2,3,1] [4,3,-2,-7,8,2,3,1] [4,-3,-2,-7,8,2,3,1] ... [-4,-3,-2,-7,8,2,-3,-1]
    }

	// 2nd for loop: nums = [-4,-3,-2,-7,8,2,-3,-1]
    for(int i = 0; i < nums.size(); i++)
        if(nums[i] > 0)         // the 4th & 5th indexes are positive
            ans.push_back(i+1); // ans = [5,6]

    return ans;
}

/*
int main() {
	return 0;
}*/
