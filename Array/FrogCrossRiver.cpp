#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <unordered_map>

using namespace std;
/*https://leetcode.com/problems/frog-jump/
 * A frog is crossing a river. The river is divided into some number of units, and at each unit, there may or may not exist a stone. The frog can jump on a stone, but it must not jump into the water.

Given a list of stones' positions (in units) in sorted ascending order, determine if the frog can cross the river by landing on the last stone. Initially, the frog is on the first stone and assumes the first jump must be 1 unit.

If the frog's last jump was k units, its next jump must be either k - 1, k, or k + 1 units. The frog can only jump in the forward direction.



Example 1:

Input: stones = [0,1,3,5,6,8,12,17]
Output: true
Explanation: The frog can jump to the last stone by jumping 1 unit to the 2nd stone, then 2 units to the 3rd stone, then 2 units to the 4th stone, then 3 units to the 6th stone, 4 units to the 7th stone, and 5 units to the 8th stone.
https://www.youtube.com/watch?v=1V8gRXh1qbU : to understand
https://leetcode.com/problems/frog-jump/discuss/88805/Straight-forward-9ms-7-line-c%2B%2B-solution-with-explanation
 */

unordered_map<string, bool> mp;

bool canFrogCross(vector<int>& stones, int pos, int k) {
	string key = "pos" + to_string(pos) + "k" + to_string(k);

	if(mp.find(key) != mp.end()) return mp[key];

	for(int i = pos+1; i < stones.size(); i++) {
		int gap = stones[i] - stones[pos];
		if(gap < k-1) continue;
		if(gap > k+1) {
			mp[key] = false;
			return false;
		}
		if(canFrogCross(stones, i, gap)) {
			mp[key] = true;
			return true;
		}
	}
	mp[key] = pos == stones.size()-1;
	return mp[key];
}

bool canFrogCrossRiver(vector<int>& stones) {
	return canFrogCross(stones, 0, 0);
}

bool canFrogCrossRiverInefficient(vector<int>& stones, int pos = 0, int k = 0) {
	for(int i = pos+1; i < stones.size(); i++) {
		int gap = stones[i] - stones[pos];
		if(gap < k-1) continue;
		if(gap > k+1) return false;
		if(canFrogCrossRiverInefficient(stones, i, gap)) return true;
	}
	return pos == stones.size()-1;
}
/*
int main() {
	vector<int> stones;
	stones.push_back(0);stones.push_back(1);stones.push_back(3);stones.push_back(5);
	stones.push_back(6);stones.push_back(8);stones.push_back(12);stones.push_back(17);

	cout << canFrogCrossRiver(stones) << endl;
	return 0;
}*/
