#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <map>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/squares-of-a-sorted-array/
 * Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.
 * Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].
 */
//TC:O(N), SC: O(1)
vector<int> sortedSquares(vector<int>& nums) {
    if(nums.size() == 0) return {};
    vector<int> result(nums.size());
    int left = 0;
    int right = nums.size() - 1;

    for(int i = nums.size() - 1; i >= 0; --i) {
        if( abs(nums[left]) > abs(nums[right]) ){
            result[i] = nums[left] * nums[left];
            left++;
        }else {
            result[i] = nums[right] * nums[right];
            right--;
        }
    }
    return result;
}
/*
int main() {
	vector<int> nums = {-4, -1, 0, 0, 10};
	sortedSquares(nums);
}*/
