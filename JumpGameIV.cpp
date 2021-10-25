#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <unordered_map>
#include <queue>

using namespace std;
/*https://leetcode.com/problems/jump-game-iv/
 * Given an array of integers arr, you are initially positioned at the first index of the array.
In one step you can jump from index i to index:
i + 1 where: i + 1 < arr.length.
i - 1 where: i - 1 >= 0.
j where: arr[i] == arr[j] and i != j.
Return the minimum number of steps to reach the last index of the array.
Notice that you can not jump outside of the array at any time.
Input: arr = [100,-23,-23,404,100,23,23,23,3,404]
Output: 3
Explanation: You need three jumps from index 0 --> 4 --> 3 --> 9. Note that index 9 is the last index of the array.
https://leetcode.com/problems/jump-game-iv/discuss/502699/JavaC%2B%2B-BFS-Solution-Clean-code-O(N)
 */
//TC: O(N)
int minJumpsIV(vector<int>& arr) {
	if(arr.empty()) return 0;
	int n = arr.size();
	unordered_map<int, vector<int>> indicesOfValue;
	for(int i = 0; i < n; i++)
		indicesOfValue[arr[i]].push_back(i);
	int step = 0;
	queue<int> q; q.push(0);
	vector<bool> visited(n); visited[0] = true;

	while(!q.empty()) {
		for(int size = q.size(); size > 0; size--) {
			int i = q.front(); q.pop();
			if(i == n-1) return step;
			vector<int>& next = indicesOfValue[arr[i]];
			next.push_back(i-1); next.push_back(i+1);
			for(int j : next) {
				if(j >= 0 && j < n && !visited[j]){
					visited[j] = true;
					q.push(j);
				}
			}
			next.clear();
		}
		step++;
	}
	return step;
}
/*
int main() {
	vector<int> arr;
	arr.push_back(100);arr.push_back(-23);arr.push_back(-23);
	arr.push_back(404);arr.push_back(100);arr.push_back(23);
	arr.push_back(23);arr.push_back(23);arr.push_back(3);
	arr.push_back(404);
	cout << minJumpsIV(arr) << endl;

	return 0;
}*/
