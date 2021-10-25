#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <set>

using namespace std;
/*
 * 163. Missing Ranges
 * Given a sorted integer array where the range of elements are in the inclusive range [lower, upper], return its missing ranges.
For example, given [0, 1, 3, 50, 75], lower = 0 and upper = 99, return ["2", "4->49", "51->74", "76->99"].

Thought process:
Get missing range from lower to nums[0].
Get missing ranges in nums.
Get missing range from nums[len - 1] to upper.
https://zhuhan0.blogspot.com/2017/10/leetcode-163-missing-ranges.html
 */

string getRange(long lower, long upper) {
	if(lower == upper) {
		return to_string(lower);
	} else {
		return to_string(lower) + "->" + to_string(upper);
	}
}

vector<string> findMissingRamges(vector<int>& nums, int lower, int upper) {
	vector<string> result;
	if(nums.size() == 0) {
		if(lower <= upper) {
			result.push_back(getRange(lower, upper));
		}
	}

	if(lower < nums[0]) {
		result.push_back(getRange(lower, nums[0] - 1));
	}

	for(int i = 1; i < nums.size(); i++) {
		if(nums[i] > nums[i-1] && nums[i-1] != nums[i] - 1) {
			result.push_back(getRange(nums[i-1]+1, nums[i] - 1));
		}
	}

	if(upper > nums[nums.size() - 1]) {
		result.push_back(getRange(nums[nums.size() -1] + 1, upper));
	}
	for(string& s : result)
		cout << s << endl;
	return result;
}
/*
int main() {
	vector<int> nums;
	nums.push_back(0);nums.push_back(1);nums.push_back(3);nums.push_back(50);nums.push_back(75);
	findMissingRamges(nums, 0, 99);
	return 0;
}*/

