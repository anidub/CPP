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
/*https://leetcode.com/problems/counting-bits/
 * Given an integer n, return an array ans of length n + 1
 * such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.
 * Input: n = 2
Output: [0,1,1]
Explanation:
0 --> 0
1 --> 1
2 --> 10

https://leetcode.com/problems/counting-bits/solution/
 */

class CountingBits {
public:
	//TC:O(NLOGN), SC:O(1)
	vector<int> countBits(int n) {
		vector<int> ans(n + 1);
		for(int x = 0; x <= n; x++) {
			ans[x] = popCount(x);
		}
		return ans;
	}
private:
	int popCount(int x) {
		int count;
		for(count = 0; x != 0; count++) {
			x &= (x - 1);
		}
		return count;
	}
};
/*
int main() {
	CountingBits cb;
	cb.countBits(2);
}*/
