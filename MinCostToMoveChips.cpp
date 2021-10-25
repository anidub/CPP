#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
/*
 * https://leetcode.com/problems/minimum-cost-to-move-chips-to-the-same-position/submissions/
 * We have n chips, where the position of the ith chip is position[i].

We need to move all the chips to the same position. In one step, we can change the position of the ith chip from position[i] to:

position[i] + 2 or position[i] - 2 with cost = 0.
position[i] + 1 or position[i] - 1 with cost = 1.
Return the minimum cost needed to move all the chips to the same position.
Input: position = [1,2,3]
Output: 1
Explanation: First step: Move the chip at position 3 to position 1 with cost = 0.
Second step: Move the chip at position 2 to position 1 with cost = 1.
Total cost is 1.
https://leetcode.com/problems/minimum-cost-to-move-chips-to-the-same-position/discuss/696871/C%2B%2B-solution

 * https://www.youtube.com/watch?v=BLYLGcYhcn8
 */

int minCostToMoveChips(vector<int>& chips) {
	if(chips.size() == 0) return 0;
	int even = 0, odd = 0;
	for(int chip : chips){
		if(chip % 2 == 0)
			++odd;
		else
			++even;
	}
	//return min(odd,even);//works
	return 0;
}
/*
int main() {
	vector<int> chips;
	chips.push_back(2);chips.push_back(2);chips.push_back(24);
	chips.push_back(3);chips.push_back(3);
	minCostToMoveChips(chips);

	return 0;
} */
