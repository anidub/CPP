#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

/*
 * https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/
 * Given an array of numbers arr. A sequence of numbers is called an arithmetic progression if the difference between any two consecutive elements is the same.

Return true if the array can be rearranged to form an arithmetic progression, otherwise, return false.
Example 1:
Input: arr = [3,5,1]
Output: true
Explanation: We can reorder the elements as [1,3,5] or [5,3,1] with differences 2 and -2 respectively, between each consecutive elements.
 *
 *https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/discuss/722307/C%2B%2B-oror-Without-Sort-oror-Set-oror-Easy-to-understand
 https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/discuss/1021731/Optimized-O(n)-Solution-or-AP-Explained
 video: https://www.youtube.com/watch?time_continue=577&v=MOaSXYGas0I&feature=emb_logo
 */

bool canMakeArithmeticProgression(vector<int>& nums) {
	if(nums.size() == 0)
		return false;
	//sort(nums.begin(), nums.end()); //works
	int diff = nums[1] - nums[0];
	for(int i = 2; i < nums.size(); i++) {
		if(nums[i] - nums[i-1] != diff)
			return false;
	}
	return true;
}
/*
 * works O(n)
bool canMakeArithmeticProgressionOptimized(vector<int>& nums) {
	if(nums.size() == 0)
		return false;

	unordered_set<int> set(nums.begin(), nums.end());
  //  int min = *min_element(nums.begin(), nums.end()); works
  //  int max = *max_element(nums.begin(), nums.end()); works

    int diff = max - min;
    int n = nums.size();
    if(diff % (n-1) != 0)
        return false;
    int i = 0;
    diff = diff/(n-1);
    while(i < n) {
        if(!set.count(min))
            return false;
        min = min + diff;
        i++;
    }
    return true;
}
*/

/*
int main() {

	return 0;
}
*/
