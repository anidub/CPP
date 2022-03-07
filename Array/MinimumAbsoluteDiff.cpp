#include <iostream>
#include <vector>

using namespace std;
/*
 *
 * Given an array of distinct integers arr,
 *  find all pairs of elements with the minimum absolute difference of any two elements.
Return a list of pairs in ascending order(with respect to pairs), each pair [a, b] follows
a, b are from arr
a < b
b - a equals to the minimum absolute difference of any two elements in arr
Input: arr = [4,2,1,3]
Output: [[1,2],[2,3],[3,4]]
Explanation: The minimum absolute difference is 1. List all pairs with difference equal to 1 in ascending order.

https://leetcode.com/problems/minimum-absolute-difference/discuss/388260/Easy-C%2B%2B-Solution
check comments
 */

vector<vector<int>> minimumAbsoluteDiff(vector<int>& arr) {
	vector<vector<int>> result;
	if(arr.size() == 0)
		return result;
	//sort(arr.begin(), arr.end()); works
	int min_diff =-10000; // use int_max
	//int min_diff = INT_MAX; works
	for(int i = 0; i < arr.size() - 1; i++) {
		min_diff = min((arr[i+1] - arr[i]), min_diff);
	}

	for(int i = 0; i < arr.size() - 1; i++) {
		if(arr[i+1] - arr[i] == min_diff)
			result.push_back({arr[i+1], arr[i]});
	}

	return result;
}

vector<vector<int>> minimumAbsoluteDiffOnePass(vector<int>& arr) {
	vector<vector<int>> result;
	if(arr.size() == 0)
		return result;

	//sort(arr.begin(), arr.end());

	int min_diff = -10000; // use int_max
	//min_diff = INT_MAX; works
	int cur_diff;

	for(int i = 0; i < arr.size() - 1; i++) {
		cur_diff = arr[i+1] - arr[i];
		if(cur_diff > min_diff) continue;

		if(cur_diff == min_diff) {
			result.push_back({arr[i], arr[i+1]});
		} else {
			result.clear();
			result.push_back({arr[i], arr[i+1]});
			min_diff = cur_diff;
		}
	}

	return result;
}

/*
int main() {

	vector<int> nums;
	nums.push_back(4);nums.push_back(2);nums.push_back(3);
	nums.push_back(1);

	//cout << minimumAbsoluteDiffOnePass(nums) << endl;
	//cout << minimumAbsoluteDiff(nums) << endl;

	return 0;
}
*/
