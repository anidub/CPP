#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <vector>
#include <utility>
#include <unordered_map>

using namespace std;
/*https://www.educative.io/courses/grokking-the-coding-interview/R1B78K9oBEz
 * Given an array of numbers sorted in ascending order, find the range of a given number ‘key’. The range of the ‘key’ will be the first and last position of the ‘key’ in the array.
 Input: [4, 6, 6, 6, 9], key = 6
Output: [1, 3]
https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/discuss/519580/C%2B%2B-O(log-n)%3A-Fast-Runtime-Binary-Search
 */

class FirstLastPosition {
public:
	//O(LOGN), SC:O(1)
	pair<int, int> searchRangeElement(const vector<int> &nums, int target) {
		int first_position = binarySearchRange(nums, target, "First");
		int last_position = binarySearchRange(nums, target, "Last");

		return make_pair(first_position, last_position);
	}

	int binarySearchRange(const vector<int> &nums, int target, string position) {
		int start = 0, end = nums.size() - 1, mid;
		int result = -1;

		while(start <= end) {
			mid = start + (end - start) / 2;
			if(target < nums[mid])
				end = mid - 1;
			else if(target > nums[mid])
				start = mid + 1;
			else {
				result = mid;
				(position == "First" ? end = mid - 1 : start = mid + 1);
			}
		}
		return result;
	}
};
/*
int main(int argc, char *argv[]) {
	FirstLastPosition flp;
  pair<int, int> result = flp.searchRangeElement(vector<int>{4, 6, 6, 6, 9}, 6);
  cout << "Range: [" << result.first << ", " << result.second << "]" << endl;
  result = flp.searchRangeElement(vector<int>{1, 3, 8, 10, 15}, 10);
  cout << "Range: [" << result.first << ", " << result.second << "]" << endl;
  result = flp.searchRangeElement(vector<int>{1, 3, 8, 10, 15}, 12);
  cout << "Range: [" << result.first << ", " << result.second << "]" << endl;
}*/

