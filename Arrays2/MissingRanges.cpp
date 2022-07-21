#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <stack>

using namespace std;
/*https://leetcode.com/problems/missing-ranges/
 * You are given an inclusive range [lower, upper] and a sorted unique integer array nums, where all elements are in the inclusive range.

A number x is considered missing if x is in the range [lower, upper] and x is not in nums.

Return the smallest sorted list of ranges that cover every missing number exactly. That is, no element of nums is in any of the ranges, and each missing number is in one of the ranges.

Each range [a,b] in the list should be output as:

"a->b" if a != b
"a" if a == b

 * Input: nums = [0,1,3,50,75], lower = 0, upper = 99
Output: ["2","4->49","51->74","76->99"]
Explanation: The ranges are:
[2,2] --> "2"
[4,49] --> "4->49"
[51,74] --> "51->74"
[76,99] --> "76->99"

https://leetcode.com/problems/missing-ranges/discuss/50492/Simply-0ms-C%2B%2B-solution
 */

string getRange(int start, int end);
//TC: O(N)
vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
	vector<string> result;
	if(nums.empty()) {
		result.push_back(getRange(lower, upper));
		return result;
	}
	long int prev = (long) lower - 1;
	for(int i = 0; i <= nums.size(); i++) {
		long int cur = (i == nums.size() ? (long) upper + 1 : nums[i]);
		if(cur - prev >= 2) {
			result.push_back(getRange(prev + 1, cur - 1));
		}
		prev = cur;
	}
	return result;
}

string getRange(int start, int end) {
	return start == end ? to_string(start) : to_string(start) + "->" + to_string(end);
}
/*
int main() {
	vector<int> ranges = {0,1,3,50,75};
	findMissingRanges(ranges, 0, 99);

	return 0;
}*/
