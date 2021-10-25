#include <iostream>
#include <stdio.h>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <utility>
#include <queue>
#include <set>

using namespace std;
/*https://leetcode.com/problems/jump-game-v/
 *Given an array of integers arr and an integer d. In one step you can jump from index i to index:

i + x where: i + x < arr.length and 0 < x <= d.
i - x where: i - x >= 0 and 0 < x <= d.
In addition, you can only jump from index i to index j if arr[i] > arr[j] and arr[i] > arr[k] for all indices k between i and j (More formally min(i, j) < k < max(i, j)).

You can choose any index of the array and start jumping. Return the maximum number of indices you can visit.

Notice that you can not jump outside of the array at any time.

 Input: arr = [6,4,14,6,8,13,9,7,10,6,12], d = 2
Output: 4
Explanation: You can start at index 10. You can jump 10 --> 8 --> 6 --> 7 as shown.
Note that if you start at index 6 you can only jump to index 7. You cannot jump to index 5 because 13 > 9. You cannot jump to index 4 because index 5 is between index 4 and 6 and 13 > 9.
Similarly You cannot jump from index 3 to index 2 or index 1.
https://www.youtube.com/watch?v=sCbuxSvoJqI
https://leetcode.com/problems/jump-game-v/discuss/496520/Top-Down-DP-O(nd)
 */

int dp_[1001];

int dfs(vector<int>& arr, int i, int d, int res = 1) {
	if(dp_[i]) return dp_[i];
	for(int j = i+1; j <= min(i+d, (int)arr.size()-1) && arr[j] < arr[i]; j++) {
		res = max(res, 1 + dfs(arr, j, d));
	}
	for(int j = i-1; j >= max(0, i-d) && arr[j] < arr[i]; j--){
		res = max(res, 1 + dfs(arr,j,d));
	}
	dp_[i] = res;
	return res;
}
//Time: O(nd) Memory: O(n) to memoize jumps for every index.
int maxJumpsGames(vector<int>& arr, int d, int res = 1) {
	for(int i = 0; i < arr.size(); i++) {
		res = max(res, dfs(arr, i , d));
	}
	return res;
}
/*
int main() {
	vector<int> arr; arr.push_back(6);arr.push_back(4);arr.push_back(14);
	arr.push_back(6);arr.push_back(8);arr.push_back(13);arr.push_back(9);
	arr.push_back(7);arr.push_back(10);arr.push_back(6);arr.push_back(12);
	cout << maxJumpsGames(arr, 2);

	return 0;
}*/
