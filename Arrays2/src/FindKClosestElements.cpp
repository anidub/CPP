#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <stack>

using namespace std;
/*https://leetcode.com/problems/find-k-closest-elements/
 * Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.

An integer a is closer to x than an integer b if:

|a - x| < |b - x|, or
|a - x| == |b - x| and a < b
Input: arr = [1,2,3,4,5], k = 4, x = -1
Output: [1,2,3,4]
https://leetcode.com/problems/find-k-closest-elements/discuss/106426/JavaC%2B%2BPython-Binary-Search-O(log(N-K)-%2B-K)
 */
//TC:O(log(n-k) + k) We need O(logn) time complexity to find r at the start. Then we need another O(k) time to expand our window to fit k elements
//SC: O(1)
vector<int> findClosestElements(vector<int>& A, int k, int x) {
    if(A.empty()) return {};

    int left = 0, right = A.size() - k;

    while(left < right) {
    	int mid = (left + right) / 2;
    	if(x - A[mid] > A[mid + k] - x)
    		left = mid + 1;
    	else
    		right = mid;
    }
    return vector<int>(A.begin() + left, A.begin() + left + k);
}
/*
int main() {
	vector<int> nums = {1,2,3,4,5};
	findClosestElements(nums, 4, -1);

	return 0;
}*/
