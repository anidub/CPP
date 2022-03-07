#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits> //for INT_MIN std::numeric_limits

using namespace std;

/*
 * Given an array of integers A, return the largest integer that only occurs once.
If no integer occurs once, return -1.

Example 1:
Input: [5,7,3,9,4,9,8,3,1]
Output: 8
Explanation:
The maximum integer in the array is 9 but it is repeated. The number 8 occurs only once, so it's the answer.
Example 2:
Input: [9,9,8,8]
Output: -1
Explanation:
There is no number that occurs only once.
https://www.programmersought.com/article/75726764224/
https://codeleading.com/article/61582187659/
 */

int largestUnique(vector<int>& nums) {
	if(nums.size() == 0)
		return 0;
	unordered_map<int, int> map;
	for(int i : nums) {
		map[i]++;
	}
	int result = INT_MIN;

	for(auto it = map.begin(); it != map.end(); ++it) {
		if(it->second == 1)
			result = max(result, it->first);
	}
	return result == INT_MIN ? -1 : result;
}
/*
int main() {
	vector<int> nums;
	nums.push_back(5);nums.push_back(7);nums.push_back(3);
	nums.push_back(9);nums.push_back(4);nums.push_back(9);
	nums.push_back(8);nums.push_back(3);nums.push_back(1);

	cout << largestUnique(nums) << endl;;
}*/
