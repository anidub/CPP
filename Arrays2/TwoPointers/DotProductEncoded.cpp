#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <stack>
#include <sstream>

using namespace std;
/*https://leetcode.com/problems/product-of-two-run-length-encoded-arrays/
 * Run-length encoding is a compression algorithm that allows for an integer array nums with many segments of consecutive repeated numbers to be represented by a (generally smaller) 2D array encoded. Each encoded[i] = [vali, freqi] describes the ith segment of repeated numbers in nums where vali is the value that is repeated freqi times.

For example, nums = [1,1,1,2,2,2,2,2] is represented by the run-length encoded array encoded = [[1,3],[2,5]]. Another way to read this is "three 1's followed by five 2's".
The product of two run-length encoded arrays encoded1 and encoded2 can be calculated using the following steps:

Expand both encoded1 and encoded2 into the full arrays nums1 and nums2 respectively.
Create a new array prodNums of length nums1.length and set prodNums[i] = nums1[i] * nums2[i].
Compress prodNums into a run-length encoded array and return it.
You are given two run-length encoded arrays encoded1 and encoded2 representing full arrays nums1 and nums2 respectively. Both nums1 and nums2 have the same length. Each encoded1[i] = [vali, freqi] describes the ith segment of nums1, and each encoded2[j] = [valj, freqj] describes the jth segment of nums2.

Return the product of encoded1 and encoded2.

Note: Compression should be done such that the run-length encoded array has the minimum possible length.

Input: encoded1 = [[1,3],[2,3]], encoded2 = [[6,3],[3,3]]
Output: [[6,6]]
Explanation: encoded1 expands to [1,1,1,2,2,2] and encoded2 expands to [6,6,6,3,3,3].
prodNums = [6,6,6,6,6,6], which is compressed into the run-length encoded array [[6,6]].

https://leetcode.com/problems/product-of-two-run-length-encoded-arrays/discuss/1505754/c%2B%2B-clean-and-concise : comments
 *
 */
//TC: O(M + N), SC  : O(1)
vector<vector<int>> dotProdEncoded(vector<vector<int>> &encoded1, vector<vector<int>> &encoded2) {
	vector<vector<int>> result;
	int i = 0; int j = 0;

	while(i < encoded1.size() && j < encoded2.size()) {
		const int cnt1 = encoded1[i][1];
		const int cnt2 = encoded2[j][1];
		int minCnt = min(cnt1, cnt2);

		int product = encoded1[i][0] * encoded2[j][0];

		if(!result.empty() && product == (result.back())[0] ) {
			(result.back())[1] += minCnt;
		} else {
			result.push_back({product, minCnt});
		}
		encoded1[i][1] -= minCnt;
		encoded2[j][1] -= minCnt;

		if(!encoded1[i][1])
			i++;
		if(!encoded2[j][1])
			j++;
	}
	return result;

	return result;
}
/*
int main() {
	vector<vector<int>> encoded1 = {{1,3},{2,3}};
	vector<vector<int>> encoded2 =  {{6,3},{3,3}};

	dotProdEncoded(encoded1, encoded2);

	return 0;
}*/
