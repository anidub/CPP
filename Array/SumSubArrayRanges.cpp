#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <stack>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/sum-of-subarray-ranges/
 * You are given an integer array nums. The range of a subarray of nums is the difference between the largest and smallest element in the subarray.

Return the sum of all subarray ranges of nums.

A subarray is a contiguous non-empty sequence of elements within an array.

 * Input: nums = [1,2,3]
Output: 4
Explanation: The 6 subarrays of nums are the following:
[1], range = largest - smallest = 1 - 1 = 0
[2], range = 2 - 2 = 0
[3], range = 3 - 3 = 0
[1,2], range = 2 - 1 = 1
[2,3], range = 3 - 2 = 1
[1,2,3], range = 3 - 1 = 2
So the sum of all ranges is 0 + 0 + 0 + 1 + 1 + 2 = 4.

https://leetcode.com/problems/sum-of-subarray-ranges/discuss/1624268/Reformulate-Problem-O(n) : to understand
https://leetcode.com/problems/sum-of-subarray-ranges/discuss/1626628/O(n)-solution-with-monotonous-stack-oror-Full-explaination : well explained

 * https://leetcode.com/problems/sum-of-subarray-ranges/discuss/1624222/JavaC%2B%2BPython-O(n)-solution-detailed-explanation
 */
long long sumSubArrayRangesOptimal(vector<int>& A) {
	long long res = 0;
	int n = A.size(), j, k;
	stack<int> s;

	for(int i = 0; i <= n; i++) {
		while(!s.empty() && A[s.top()] > (i == n ? INT_MIN : A[i])) {
			j = s.top(); s.pop();
			k = s.empty() ? -1 : s.top();
			res -= (long) A[j] * (i - j) * (j - k);
		}
		s.push(i);
	}
	s = stack<int>();
	for(int i = 0; i <= n; i++) {
		while(!s.empty() && A[s.top()] < (i == n ? INT_MAX : A[i])) {
			j = s.top(); s.pop();
			k = s.empty() ? -1 : s.top();
			res += (long) A[j] * (i - j) * (j - k);
		}
		s.push(i);
	}
	return res;
}

long long sumSubArrayRanges(vector<int>& A) {
	if(A.empty()) return 0;
	long long int sum = 0;
	int n = A.size();

	for(int i = 0; i < n; i++) {
		int mx = A[i];
		int mn = A[i];
		for(int j = i; j < n; j++) {
			mx = max(mx ,A[j]);
			mn = min(mn, A[j]);
			sum += mx - mn;
		}
	}
	return sum;

}
/*
int main() {
	vector<int> A = {1, 2, 3};
	cout << sumSubArrayRanges(A) << endl;
	return 0;
}*/
