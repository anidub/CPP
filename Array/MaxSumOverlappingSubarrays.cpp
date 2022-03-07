#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <map>
#include <utility>

using namespace std;
/*
 * https://leetcode.com/problems/maximum-sum-of-two-non-overlapping-subarrays/
 * Given an array A of non-negative integers, return the maximum sum of elements in two non-overlapping (contiguous) subarrays, which have lengths L and M.  (For clarification, the L-length subarray could occur before or after the M-length subarray.)
Formally, return the largest V for which V = (A[i] + A[i+1] + ... + A[i+L-1]) + (A[j] + A[j+1] + ... + A[j+M-1]) and either:
0 <= i < i + L - 1 < j < j + M - 1 < A.length, or
0 <= j < j + M - 1 < i < i + L - 1 < A.length.
Example 1:
Input: A = [0,6,5,2,2,5,1,9,4], L = 1, M = 2
Output: 20
Explanation: One choice of subarrays is [9] with length 1, and [6,5] with length 2.
https://leetcode.com/problems/maximum-sum-of-two-non-overlapping-subarrays/discuss/279701/C%2B%2B-straightforward-12ms
https://leetcode.com/problems/maximum-sum-of-two-non-overlapping-subarrays/discuss/278251/JavaC%2B%2BPython-O(N)Time-O(1)-Space
https://leetcode.com/problems/maximum-sum-of-two-non-overlapping-subarrays/discuss/278962/c%2B%2B-solutoin-(O(n))-with-explanation
https://leetcode.com/problems/maximum-sum-of-two-non-overlapping-subarrays/discuss/287238/C%2B%2B-11l-ine
 */

int maxSumOverlappingSubarrays(vector<int>& A, int L, int M) {
	int result = INT_MIN;
	int sumL = accumulate(A.begin(), A.begin() + L, 0);

	for(int i = 0; i < A.size()-L-M; i++) {
		if(i != 0)
			sumL += A[i+L-1] - A[i-1];
		int sumM  = accumulate(A.begin()+i+L, A.begin()+i+L+M, 0);
		for(int j = i+L; j <= A.size()-M; j++) {
			if(j != i+L)
				sumM += A[j+M-1] - A[j-1];
			result = max(result, sumL+sumM);
		}
	}

	sumL = accumulate(A.begin()+A.size()-L, A.end(), 0);
	for(int i = A.size()-L; i >= M; i--) {
		if(i != A.size()-L)
			sumL += A[i] - A[i+L];
		int sumM = accumulate(A.begin()+i-M, A.begin()+i, 0);
		for(int j = i-M; j >= 0; j--) {
			if(j != i-M)
				sumM += A[j] - A[j+M];
			result = max(result, sumL+sumM);
		}
	}
	return result;
}
/*
int main() {

	return 0;
}*/
