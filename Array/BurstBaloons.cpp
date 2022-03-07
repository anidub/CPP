#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>
#include <climits>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/burst-balloons/
 * You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.
If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.
Return the maximum coins you can collect by bursting the balloons wisely.
Example 1:

Input: nums = [3,1,5,8]
Output: 167
Explanation:
nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167
https://www.youtube.com/watch?v=Hps6bHDGtqQ
https://leetcode.com/problems/burst-balloons/discuss/1180636/C%2B%2B-RECURSION-%2B-MEMOIZATION
 */

//Time Complexity - O(N ^ 3) --> left can have different N values and each left N different right value then we are trying all N balloons in betwee.
//Space - O(N ^ 2)
int dp_burst[502][502];

int getBurstBaloonsCoins(vector<int>& nums, int l, int r) {
	if(dp_burst[l][r] != -1 )
		return dp_burst[l][r];

	int ans = 0;
	for(int i = l+1; i < r; i++) {
		int score = nums[l] * nums[i] * nums[r];
		ans = max(ans, score + getBurstBaloonsCoins(nums, l, i) + getBurstBaloonsCoins(nums, i, r));
	}
	dp_burst[l][r] = ans;
	return ans;
}

int burstBaloons(vector<int>& nums) {
	nums.insert(nums.begin(), 1);
	nums.push_back(1);
	int n = nums.size();
	memset(dp_burst , -1 , sizeof(dp_burst));

	return getBurstBaloonsCoins(nums, 0, n-1);
}
/* This works but give TLE
     unordered_map<string, int> mp;

    int getCoin(vector<int>& nums, int l, int r) {
        string key = to_string(l) + "|" + to_string(r);
        if(mp.find(key) == mp.end()) {
            int max_coin = 0;
            for(int i = l+1; i < r; i++) {
                int score = nums[l] * nums[i] * nums[r];
                max_coin = max(max_coin, score + getCoin(nums,l,i) + getCoin(nums, i, r));
            }
            mp[key] = max_coin;
        }
        return mp[key];
    }*/

/*
int main() {
	vector<int> nums; nums.push_back(3);nums.push_back(1);nums.push_back(5);nums.push_back(8);
	cout << burstBaloons(nums) << endl;

	return 0;
}*/
