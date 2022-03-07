#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>
#include <climits>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/max-chunks-to-make-sorted-ii/
 * You are given an integer array arr.
We split arr into some number of chunks (i.e., partitions), and individually sort each chunk. After concatenating them, the result should equal the sorted array.
Return the largest number of chunks we can make to sort the array.
Example 1:

Input: arr = [5,4,3,2,1]
Output: 1
Explanation:
Splitting into two or more chunks will not return the required result.
For example, splitting into [5, 4], [3, 2, 1] will result in [4, 5, 1, 2, 3], which isn't sorted.

https://leetcode.com/problems/max-chunks-to-make-sorted-ii/discuss/249164/C%2B%2B-O(N)-solution-with-explanation
https://www.youtube.com/watch?v=GxTo3agdnjs : to understand
 */
//Time : O(n), Space : O(n)
int maxChunksToMakeSorted2(vector<int>& arr) {
	if(arr.empty()) return 0;

	int n = arr.size();
	vector<int> leftMax(n+1, INT_MIN);//From left Max value in range [0, i)
	for(int i = 1; i <= n; i++) {
		leftMax[i] = max(leftMax[i-1], arr[i-1]);
	}

	vector<int> rightMin(n+1, INT_MAX); //From Min value in range [N, i])
	for(int i = n-1; i >= 0; i--) {
		rightMin[i] = min(rightMin[i+1], arr[i]);
	}

	int chunks = 0;//// Calculate Chunks
	for(int i = 1; i <= n; i++) {
		chunks += leftMax[i] <= rightMin[i]; //// if max of range[0, i) <= min of range[i, N)  // add 1 to number of chunks.
	}
	return chunks;
}
/*
int main() {
	vector<int> arr;
	arr.push_back(2);arr.push_back(1);arr.push_back(3);arr.push_back(4);arr.push_back(4);
	cout << maxChunksToMakeSorted2(arr) << endl;
}*/
