#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together/
 * Given a binary array data, return the minimum number of swaps required to group all 1’s present in the array together in any place in the array.
 * Input: data = [1,0,1,0,1]
Output: 1
Explanation: There are 3 ways to group all 1's together:
[1,1,1,0,0] using 1 swap.
[0,1,1,1,0] using 2 swaps.
[0,0,1,1,1] using 1 swap.
The minimum is 1.

// [memo] Slide windows , which length is equal to number of 1's

// 1. calculate the total number of 1's, which is our slide window length

// 2. start to move slide window to the right, the holes inside is the # of swaps we need to supplement

// 3. update each slide window move to find the minimal holes in the window
 *
https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together/discuss/1634951/c%2B%2B-slide-window-brief-explanation-and-easy-to-understand

 */
//TC: O(n), Sc : O(1)
int minSwapsGroupOnes(vector<int>& data) {
	if(data.empty()) return 0;

	int winLength = 0;
	for(int d : data) if(d == 1) winLength++;

	int minHoles = 0;
	for(int i = 0; i < winLength; i++) if(data[i] == 0) minHoles++;

	int res = minHoles;

	for(int i = winLength; i < data.size(); i++) {
		if(data[i] == 1) minHoles--;

		if(data[i - winLength] == 1) minHoles++;

		res = min(res, minHoles);
	}
	return res;
}
/*
int main() {
	vector<int> data = {1, 0, 1, 0, 1};

	return 0;
}*/
