#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <vector>
#include <utility>
#include <unordered_map>

using namespace std;
/*
 * https://leetcode.com/problems/split-array-into-fibonacci-sequence/
 * You are given a string of digits num, such as "123456579". We can split it into a Fibonacci-like sequence [123, 456, 579].

Formally, a Fibonacci-like sequence is a list f of non-negative integers such that:

0 <= f[i] < 231, (that is, each integer fits in a 32-bit signed integer type),
f.length >= 3, and
f[i] + f[i + 1] == f[i + 2] for all 0 <= i < f.length - 2.
Note that when splitting the string into pieces, each piece must not have extra leading zeroes, except if the piece is the number 0 itself.
Return any Fibonacci-like sequence split from num, or return [] if it cannot be done.
Example 1:

Input: num = "1101111"
Output: [11,0,11,11]
Explanation: The output [110, 1, 111] would also be accepted.
https://leetcode.com/problems/split-array-into-fibonacci-sequence/discuss/133983/Well-Commented-C%2B%2B-Backtracking-Solution comments
The problem statement says F[i] should not be larger than 2^31 - 1, whose length is 10. If we pick the first 11 character, it must be larger than INT_MAX.

More backtracking: https://stackoverflow.com/questions/20049829/how-to-calculate-time-complexity-of-backtracking-algorithm
 */

class SplitArrayFibonacci {
public:
	//TC:O(N^2). SC:O(N)
	vector<int> splitIntoFibonacci(string s) {
		vector<int> nums;
		backtrack(s, 0, nums);
		return nums;
	}

	bool backtrack(string s, int start, vector<int> &nums) {
		int n = s.length();

		// If we reached end of string nd we have at least 3 elements in our sequence then return true
		if(start >= n && nums.size() >= 3) return true;

		 // since '0' in the beginning is invalid therefore if the current char is '0' then we can use it
		 // alone and cannot extend it by adding more chars at the back. Otherwise, we can make upto 10 chars
		 // because length of INT_MAX is 10 (2447483647)
		int maxSplitSize = (s[start] == '0' ? 1 : 10);

		// Try getting a solution by forming a number with 'i' chars beginning with 'start'
		for(int i = 1; i <= maxSplitSize && (start + i) <= s.length(); i++) {
			long long num = stoll(s.substr(start, i));
			if(num > INT_MAX) continue;

			int sz = nums.size();
			// If fibonacci property is not satisfied then we cannot get a solution
			if(sz >= 2) {
				if(nums[sz - 1] > INT_MAX) continue;
				if(nums[sz - 2] > INT_MAX) continue;

				long long cur = (long)nums[sz - 1] + (long)nums[sz - 2];
				if(cur > INT_MAX) continue;

				if(cur != num) continue;
			}
			nums.push_back(num);
			if(backtrack(s, start + i, nums))
				return true;

			nums.pop_back();
		}
		return false;
	}
};
/*
int main() {
	SplitArrayFibonacci sf;
	sf.splitIntoFibonacci("1101111");
}*/
