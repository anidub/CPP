#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <map>
#include <utility>
#include <unordered_map>

using namespace std;
/*
 * https://leetcode.com/problems/max-chunks-to-make-sorted/
 * Given an array arr that is a permutation of [0, 1, ..., arr.length - 1], we split the array into some number of "chunks" (partitions), and individually sort each chunk.  After concatenating them, the result equals the sorted array.
What is the most number of chunks we could have made?
Example 1:
Input: arr = [4,3,2,1,0]
Output: 1
Explanation:
Splitting into two or more chunks will not return the required result.
For example, splitting into [4, 3], [2, 1, 0] will result in [3, 4, 0, 1, 2], which isn't sorted.
https://leetcode.com/problems/max-chunks-to-make-sorted/discuss/113497/C%2B%2B-4-lines-O(n)-O(1)

https://leetcode.com/problems/max-chunks-to-make-sorted/discuss/150977/Easy-O(n)-C%2B%2B-solution-with-explanation : also decent solution to understand
 */
int maxChunksToSorted(vector<int>& arr) {
	if(arr.empty()) return 0;

	int max_element = -1;
	int count = 0;

	for(int i = 0; i < arr.size(); i++) {
		max_element = max(max_element, arr[i]);
		if(max_element == i)
			count++;
	}
	return count;
}
/*
int main() {
	vector<int> nums;
	nums.push_back(1);nums.push_back(0);nums.push_back(2);nums.push_back(3);nums.push_back(4);
	cout << maxChunksToSorted(nums) << endl;

	return 0;
}
*/
