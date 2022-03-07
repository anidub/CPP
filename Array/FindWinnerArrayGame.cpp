#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <unordered_map>

using namespace std;
/*
 * https://leetcode.com/problems/find-the-winner-of-an-array-game/
 * Given an integer array arr of distinct integers and an integer k.
A game will be played between the first two elements of the array (i.e. arr[0] and arr[1]). In each round of the game, we compare arr[0] with arr[1], the larger integer wins and remains at position 0 and the smaller integer moves to the end of the array. The game ends when an integer wins k consecutive rounds.
Return the integer which will win the game.
It is guaranteed that there will be a winner of the game.
Example 1:

Input: arr = [2,1,3,5,4,6,7], k = 2
Output: 5
Explanation: Let's see the rounds of the game:
Round |       arr       | winner | win_count
  1   | [2,1,3,5,4,6,7] | 2      | 1
  2   | [2,3,5,4,6,7,1] | 3      | 1
  3   | [3,5,4,6,7,1,2] | 5      | 1
  4   | [5,4,6,7,1,2,3] | 5      | 2
So we can see that 4 rounds will be played and 5 is the winner because it wins 2 consecutive games.
https://leetcode.com/problems/find-the-winner-of-an-array-game/discuss/768298/Python-or-C%2B%2B-or-Easy-to-understand-with-comments-or-O(1)-Space-or-O(n)-Time
https://leetcode.com/problems/find-the-winner-of-an-array-game/discuss/768007/JavaC%2B%2BPython-One-Pass-O(1)-Space
Time O(N)
Space O(1)
 */

int findWinnerArrayGame(vector<int>& arr, int k) {
	if(arr.empty()) return 0;
	if(arr.size() <= k) {
		auto maxElement = *max_element(arr.begin(), arr.end());
		return maxElement;
	}

	if(k == 1) {
		return max(arr[0], arr[1]);
	}

	int wins = 0;
	int winner = arr[0];
	for(int i = 1; i < arr.size(); i++) {
		if(winner > arr[i]) {
			wins++;
		} else {
			wins = 1;
			winner = arr[i];
		}
		if(wins == k) break;
	}
	return winner;
}
/*
int main() {
	vector<int> arr;
	arr.push_back(2);arr.push_back(1);arr.push_back(3);arr.push_back(5);arr.push_back(4);arr.push_back(6);arr.push_back(7);
	cout << findWinnerArrayGame(arr, 2) << endl;
	return 0;
}
*/
