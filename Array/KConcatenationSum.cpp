#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/k-concatenation-maximum-sum/
 * Given an integer array arr and an integer k, modify the array by repeating it k times.

For example, if arr = [1, 2] and k = 3 then the modified array will be [1, 2, 1, 2, 1, 2].

Return the maximum sub-array sum in the modified array. Note that the length of the sub-array can be 0 and its sum in that case is 0.

As the answer can be very large, return the answer modulo 109 + 7.
Input: arr = [1,-2,1], k = 5
Output: 2
https://leetcode.com/problems/k-concatenation-maximum-sum/discuss/939212/CC%2B%2B-Simple-Solution-to-understand-in-O(n).
 */

#define mod 1000000007
//time: O(n)
int kadane(vector<int>& arr) {
	long cur_sum = 0, max_sum = 0;
	for(int i = 0; i < arr.size(); i++) {
		cur_sum = max(cur_sum + arr[i], (long)arr[i]);
		max_sum = max(max_sum, cur_sum);
	}
	return max_sum%mod;
}

int kConcatenationSum(vector<int>& arr, int k) {
	if(arr.empty()) return 0;
	if(k == 1) return kadane(arr);
	long sum = 0;
	for(int& i : arr)
		sum += i;

	vector<int> newV;
	for(int i = 0; i < 2 * arr.size(); i++)
		newV.push_back(arr[i%arr.size()]);

	if(sum < 0) return kadane(newV);
	else
		return kadane(newV) + (k-2)*sum%mod;
}
/*
int main() {
	vector<int> arr;
	arr.push_back(1);arr.push_back(-2);arr.push_back(1);
	cout << kConcatenationSum(arr, 5) << endl;
	return 0;
}*/
