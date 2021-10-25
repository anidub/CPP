#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <unordered_map>

using namespace std;
/*
 * https://leetcode.com/problems/check-array-formation-through-concatenation/
 * you are given an array of distinct integers arr and an array of integer arrays pieces, where the integers in pieces are distinct. Your goal is to form arr by concatenating the arrays in pieces in any order. However, you are not allowed to reorder the integers in each array pieces[i].

Return true if it is possible to form the array arr from pieces. Otherwise, return false.
Example 1:

Input: arr = [85], pieces = [[85]]
Output: true
Example 2:

Input: arr = [15,88], pieces = [[88],[15]]
Output: true
Explanation: Concatenate [15] then [88]
 * https://leetcode.com/problems/check-array-formation-through-concatenation/discuss/996750/C%2B%2B-Solution-with-unordered_map
 * https://www.youtube.com/watch?v=1Q4N98UQnuc
 * https://leetcode.com/problems/check-array-formation-through-concatenation/discuss/998041/C%2B%2B-Simple-bruteforce-approach
 *
 *
 */

bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
	if(arr.size() == 0) return false;
	unordered_map<int, vector<int>> map;

	for(auto& p : pieces) {
		map[p[0]] = p;
	}

	int i = 0;
	while(i < arr.size()) {
		int item = arr[i];
		if(!map.count(item)) return false;
		vector<int> temp = map[item];
		for(auto& x : temp) {
			if(x != arr[i++])
				return false;
		}
	}
	return true;
}
/*
int main() {

	vector<int> nums;
	nums.push_back(91);nums.push_back(4);nums.push_back(64);nums.push_back(78);

	vector<int> p1; p1.push_back(78);
	vector<int> p2; p2.push_back(4);p2.push_back(64);
	vector<int> p3; p3.push_back(91);
	vector<vector<int>> p;
	p.push_back(p1);p.push_back(p2);p.push_back(p3);

	cout << canFormArray(nums, p) << endl;
	return 0;
}*/
