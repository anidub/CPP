#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;
/*
 * https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/
 * Given an integer array sorted in non-decreasing order, there is exactly one integer in the array that occurs more than 25% of the time.
Return that integer.
Example 1:
Input: arr = [1,2,2,6,6,6,6,7,10]
Output: 6

https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/discuss/454060/Concise-O(logn)-solution-using-C%2B%2B-(beat-90)
 */
//Time complexity: O(logn)
//Space complexity: O(1)
int findSpecialInteger(vector<int>& arr) {
    int sz = arr.size();
    vector<int> candidates = {arr[sz/4], arr[sz/2], arr[sz*3/4]};
    for (auto cand : candidates) {
        auto st = lower_bound(arr.begin(), arr.end(), cand);
        auto ed = upper_bound(arr.begin(), arr.end(), cand);
        if (4 * (distance(st, ed)) > sz)
            return cand;
    }
    return -1;
}

int findSpecialBruteForce(vector<int>& arr) {
     if(arr.size() == 1) return arr[0];
     int n = arr.size();
     int count = arr.size()/4;
     int result_count = 0;
     for(int i= 1; i < arr.size(); i++) {
         if(arr[i] == arr[i-1]) {
             result_count++;
             if(result_count >= count)
                 return arr[i];
         } else {
             result_count = 0;
         }
     }
     return -1;
}
/*
int main() {
	vector<int> nums;

	nums.push_back(1);nums.push_back(2);nums.push_back(2);
	nums.push_back(6);nums.push_back(6);nums.push_back(6);
	nums.push_back(6);nums.push_back(7);nums.push_back(10);

	cout << findSpecialInteger(nums) << endl;

	return 0;
}
*/
