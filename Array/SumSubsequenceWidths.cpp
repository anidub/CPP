#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <set>

using namespace std;
/*https://leetcode.com/problems/sum-of-subsequence-widths/
 * The width of a sequence is the difference between the maximum and minimum elements in the sequence.

Given an array of integers nums, return the sum of the widths of all the non-empty subsequences of nums. Since the answer may be very large, return it modulo 109 + 7.

A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].

Input: nums = [2,1,3]
Output: 6
Explanation: The subsequences are [1], [2], [3], [2,1], [2,3], [1,3], [2,1,3].
The corresponding widths are 0, 0, 0, 1, 1, 2, 2.
The sum of these widths is 6.


my first intuition is to sort the array.

For each number A[i]:

There are i smaller numbers,
so there are 2 ^ i sequences in which A[i] is maximum.
we should do res += A[i] * 2^i

There are n - i - 1 bigger numbers,
so there are 2 ^ (n - i - 1) sequences in which A[i] is minimum.
we should do res -= A[i] * 2^(n - i - 1)

https://leetcode.com/problems/sum-of-subsequence-widths/discuss/1456511/C%2B%2B-O(nlogn)-Approach-Sum-of-Subsequence-Widths : well explained
https://leetcode.com/problems/sum-of-subsequence-widths/discuss/162318/O(nlogn)-solution : well explained
https://leetcode.com/problems/sum-of-subsequence-widths/discuss/161267/JavaC%2B%2BPython-Sort-and-One-Pass : used
 */
//Time O(NlogN) Space O(1)
int sumSubsequenceWidths(vector<int>& A) {
	if(A.empty()) return 0;
	sort(A.begin(), A.end());
	long c = 1, res = 0, mod = 1e9 + 7 , n = A.size();

	for(int i = 0; i < n; i++) {
		res = (res + A[i] * c - A[n - i - 1] * c) % mod;
		c = c * 2 % mod;
	}
	return res;
}

/*
int main() {
	vector<int> A = {2, 1, 3};
	cout << sumSubsequenceWidths(A) << endl;

	return 0;
}*/
