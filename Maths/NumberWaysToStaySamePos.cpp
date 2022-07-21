#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <unordered_map>
#include <unordered_set>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps/
 * You have a pointer at index 0 in an array of size arrLen. At each step, you can move 1 position to the left, 1 position to the right in the array, or stay in the same place (The pointer should not be placed outside the array at any time).

Given two integers steps and arrLen, return the number of ways such that your pointer still at index 0 after exactly steps steps. Since the answer may be too large, return it modulo 109 + 7.
Input: steps = 3, arrLen = 2
Output: 4
Explanation: There are 4 differents ways to stay at index 0 after 3 steps.
Right, Left, Stay
Stay, Right, Left
Right, Stay, Left
Stay, Stay, Stay

https://leetcode.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps/discuss/436117/C%2B%2B-Recursive-DP-(Memoization)
 */

int num_ways_mod = 1e9 + 7;
vector<vector<int>> num_ways_memo;
int arrLength;

int numWayStaySamePosDP(int i, int steps);

//Time: O(steps^2).
//Space: O(steps^2). This can be reduecd to O(steps) by using top-down DP.
int numWayStaySamePos(int steps, int arrLen) {
	num_ways_memo.resize(steps/2 + 1, vector<int>(steps + 1, -1));
	arrLength = arrLen;

	numWayStaySamePosDP(0, steps);
}

int numWayStaySamePosDP(int i, int steps) {
	if(i == 0 && steps == 0) return 1;//Base condition

	if(i < 0 || i >= arrLength || steps == 0 || i > steps) return 0;//Pruning.

	if(num_ways_memo[i][steps] != -1)//If we have already cached the result for current `steps` and `index` get it.
		return num_ways_memo[i][steps];

	return num_ways_memo[i][steps] = ( (  numWayStaySamePosDP(i + 1, steps - 1) % num_ways_mod +
							       numWayStaySamePosDP(i - 1, steps - 1)) % num_ways_mod +
			 	 	 	 	 	   numWayStaySamePosDP(i, steps - 1)) % num_ways_mod ;//Either move right, left or stay.

}
/*
int main() {
	cout << numWayStaySamePos(3, 2) << endl;

	return 0;
}*/
