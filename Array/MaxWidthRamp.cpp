#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <stack>

using namespace std;
/*https://leetcode.com/problems/maximum-width-ramp/
 * Given an array nums of integers, a ramp is a tuple (i, j) for which i < j and nums[i] <= nums[j].  The width of such a ramp is j - i.
Find the maximum width of a ramp in nums.  If one doesn't exist, return 0.
Example 1:
Input: nums = [6,0,8,2,1,5]
Output: 4
Explanation:
The maximum width ramp is achieved at (i, j) = (1, 5): nums[1] = 0 and nums[5] = 5.
 https://leetcode.com/problems/maximum-width-ramp/discuss/590536/C%2B%2B-Stack
 https://leetcode.com/problems/maximum-width-ramp/discuss/208348/JavaC%2B%2BPython-O(N)-Using-Stack
 */

int maxWidthRamp(vector<int>& A) {
	if(A.empty()) return 0;
	stack<int> stk;
	for(int i = 0; i < A.size(); i++) {
		if(stk.empty() || A[stk.top()] > A[i])
			stk.push(i);
	}

	int result = 0;
	for(int i = A.size()-1; i >= 0; i--) {
		while(!stk.empty() && A[stk.top()] <= A[i]){
			result = max(result, i - stk.top());
			stk.pop();
		}
	}
	return result;
}
/*
int main() {
	vector<int> A;
	A.push_back(9);A.push_back(8);A.push_back(1);A.push_back(0);A.push_back(1);
	A.push_back(9);A.push_back(4);A.push_back(0);A.push_back(4);A.push_back(1);
	cout << maxWidthRamp(A) << endl;
	return 0;
}*/
