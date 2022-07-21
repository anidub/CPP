#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <vector>
#include <deque>
#include <utility>
#include <unordered_map>

using namespace std;
/*https://leetcode.com/problems/count-number-of-nice-subarrays/
 * Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

Return the number of nice sub-arrays.
Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
https://leetcode.com/problems/count-number-of-nice-subarrays/discuss/824621/C%2B%2B-Sliding-Window-Solution-O(1)-Space
 */
int getNice(vector<int> &nums, int k) ;

//TC: O(N), SC: O(1)
int numberOfNiceSubarrays(vector<int> &nums, int k) {
	return getNice(nums, k) - getNice(nums, k - 1);
}

int getNice(vector<int> &nums, int k) {
	int ans = 0, count = 0;
	int i = 0, j = 0, n = nums.size();

	while(j < n) {
		if(nums[j] % 2 == 1) count++;
		if(count > k) {
			while(i <= j && count > k) {
				if(nums[i] % 2 == 1)
					count--;
				i++;
			}
		}
		ans += (j - i + 1);
		j++;
	}
	return ans;
}
//tc: o(n), sc:(1): But more optimum..can try this
//https://leetcode.com/problems/count-number-of-nice-subarrays/discuss/1232436/Easy-oror-Commented-oror-O(N)-Time-and-O(1)-Space-oror-Window-Sliding
int numberOfSubarraysBetter(vector<int>& nums, int k) {
	int l = 0, r = 0, n = nums.size(), kCount = 0, count = 0, prefix = 0;
	        while (r < n) {
	            // increase odd count
	            kCount += (nums[r++] & 1);
	            if (kCount > k) {
	                l++;
	                kCount--;
	                prefix = 0;
	            }

	            // Count the number of prefix which is even because either we include them or not still we get the nice one
	            while (l < r && (nums[l] % 2 == 0)) prefix++, l++;
	            if (kCount == k) {
	                count += (1 + prefix);
	            }
	        }
	        return count;
}
/*
int main() {
	vector<int> nums = {1, 1, 3, 1, 1};
	cout << numberOfNiceSubarrays(nums, 3) << endl;
	cout << numberOfSubarraysBetter(nums, 3) << endl;
}*/
