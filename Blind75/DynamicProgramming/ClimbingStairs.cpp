#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/climbing-stairs/
 * You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
https://leetcode.com/problems/climbing-stairs/discuss/25299/Basically-it's-a-fibonacci.  : comments
 */
class ClimbingStairs {
public:
	//TC:O(N), SC:O(N)
	int climbStairs(int n) {
		if(n <= 0) return 0;
		if(n <= 1) return 1;
		if(n <= 2) return 2;

		int dp[n + 1];
		dp[1] = 1;
		dp[2] = 2;

		for(int i = 3; i <= n; i++)
			dp[i] = dp[i - 1] + dp[i - 2];

		return dp[n];
	}

	//https://leetcode.com/problems/climbing-stairs/solution/
	//TC:O(N), SC:O(1)
	int climbStairsFibo(int n) {
		if(n <= 0) return 0;
		if(n <= 1) return 1;
		if(n <= 2) return 2;

		int first = 1, second = 2;

		for(int i = 3; i <= n; i++) {
			int sum = first + second;
			first = second;
			second = sum;
		}
		return second;
	}
};

/*
int main() {
	ClimbingStairs cs;
	cout << cs.climbStairs(2) << endl;
	cout << cs.climbStairsFibo(2) << endl;
}*/
