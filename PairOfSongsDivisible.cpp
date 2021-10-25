#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <unordered_map>

using namespace std;
/*https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/
 *You are given a list of songs where the ith song has a duration of time[i] seconds.
Return the number of pairs of songs for which their total duration in seconds is divisible by 60. Formally, we want the number of indices i, j such that i < j with (time[i] + time[j]) % 60 == 0.
Example 1:

Input: time = [30,20,150,100,40]
Output: 3
Explanation: Three pairs have a total duration divisible by 60:
(time[0] = 30, time[2] = 150): total duration 180
(time[1] = 20, time[3] = 100): total duration 120
(time[1] = 20, time[4] = 40): total duration 60
https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/discuss/736497/c%2B%2B-hashmap
similar to two sum problem
 */
int pairOfSongsDivisisbleBy60(vector<int>& time) {
	if(time.empty()) return 0;
	int result = 0;
	unordered_map<int, int> umap;
	for(int i = 0; i < time.size(); i++) {
		int val = time[i] % 60;
		result += umap[(60 - val) % 60];
		umap[val]++;
	}
	return result;
}
/*
int main() {
	vector<int> time;
	time.push_back(30);time.push_back(20);time.push_back(150);time.push_back(100);time.push_back(40);
	cout << pairOfSongsDivisisbleBy60(time) << endl;

	return 0;
}
*/
