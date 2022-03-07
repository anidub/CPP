#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <unordered_map>

using namespace std;
/*https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/
 * Given an array of integers arr of even length n and an integer k.
We want to divide the array into exactly n / 2 pairs such that the sum of each pair is divisible by k.
Return True If you can find a way to do that or False otherwise.
Example 1:

Input: arr = [1,2,3,4,5,10,6,7,8,9], k = 5
Output: true
Explanation: Pairs are (1,9),(2,8),(3,7),(4,6) and (5,10).
https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/discuss/709288/C%2B%2B-or-Hash-map-or-Commented-code
 */
//O(N)
int checkArrayPairsDivisibleK(vector<int>& arr, int k) {
	if(arr.empty()) return false;
	unordered_map<int, int> mp;

	for(int i = 0; i < arr.size(); i++) {
		/* Add k to ensure this works for negative numbers */
		mp[(k + arr[i] % k) % k]++;
	}

	for(int i = 0; i < arr.size(); i++) {
		int r = (k + arr[i] % k) % k;

		if(r == 0) {
			/* If remainder is 0, then there must be even number of such array elements */
			if(mp[r] % 2 != 0)
				return false;
		} else if (mp[r] != mp[k-r]){
			/* number of elements with remainder r must be same as number of elements with remainder k-r */
				return false;
		}
	}
	return true;
}
/*
int main() {
	vector<int> arr;
	arr.push_back(1);arr.push_back(2);arr.push_back(3);arr.push_back(4);arr.push_back(5);
	arr.push_back(10);arr.push_back(6);arr.push_back(7);arr.push_back(8);arr.push_back(9);

	cout << checkArrayPairsDivisibleK(arr, 10) << endl;

	return false;
}
*/
