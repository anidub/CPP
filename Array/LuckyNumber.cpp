#include <iostream>
#include <vector>
#include<unordered_map>

using namespace std;

/*
 * https://leetcode.com/problems/find-lucky-integer-in-an-array/
 * Given an array of integers arr, a lucky integer is an integer which has a frequency in the array equal to its value.

Return a lucky integer in the array. If there are multiple lucky integers return the largest of them. If there is no lucky integer return -1.
Example 1:

Input: arr = [2,2,3,4]
Output: 2
Explanation: The only lucky number in the array is 2 because frequency[2] == 2.
Example 2:

Input: arr = [1,2,2,3,3,3]
Output: 3
Explanation: 1, 2 and 3 are all lucky numbers, return the largest of them.

https://leetcode.com/problems/find-lucky-integer-in-an-array/discuss/555088/C%2B%2B
 */

int findLucky(vector<int>& arr) {
	if(arr.size() == 0) return -1;
	int result = -1;
	unordered_map<int, int> map;

	for(int i : arr)
		map[i]++;

	for(auto n : map) {
		if(n.first == n.second)
			result = std::max(result, n.first);
	}

	return result;
}

/*
int main() {
	return 0;
}
*/
