#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <deque>
#include <utility>
#include <unordered_map>
#include <queue>

using namespace std;
/*
 * https://leetcode.com/problems/reduce-array-size-to-the-half/
 * Given an array arr.  You can choose a set of integers and remove all the occurrences of these integers in the array.
Return the minimum size of the set so that at least half of the integers of the array are removed.
Example 1:
Input: arr = [3,3,3,3,5,5,5,2,2,7]
Output: 2
Explanation: Choosing {3,7} will make the new array [5,5,5,2,2] which has size 5 (i.e equal to half of the size of the old array).
Possible sets of size 2 are {3,5},{3,2},{5,2}.
Choosing set {2,7} is not possible as it will make the new array [3,3,3,3,5,5,5] which has size greater than half of the size of the old array.
https://leetcode.com/problems/reduce-array-size-to-the-half/discuss/915964/C%2B%2B-or-Easy-Heap-Based-Solution
https://leetcode.com/problems/reduce-array-size-to-the-half/discuss/707778/C%2B%2B-using-map
 */

int minSetSize(vector<int>& arr) {
	if(arr.empty()) return 0;

	unordered_map<int, int> umap;
	for(int& i : arr) {
		umap[i]++;
	}

	priority_queue<pair<int, int>> pq;
	for(auto& i : umap) {
		pq.push(make_pair(i.second, i.first));
	}

	int current = 0;
	int result = 0;
	while(current < arr.size()/2) {
		current += pq.top().first;
		pq.pop();
		result++;
	}
	return result;
}
/*
int main() {
	vector<int> nums;
	nums.push_back(3);nums.push_back(3);nums.push_back(3);nums.push_back(3);
	nums.push_back(5);nums.push_back(5);nums.push_back(5);nums.push_back(2);
	nums.push_back(2);nums.push_back(7);
	cout << minSetSize(nums) << endl;

	return 0;
}*/
