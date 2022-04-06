#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <vector>
#include <stack>
#include <utility>
#include <string.h>
#include <queue>
#include <unordered_map>

using namespace std;
/*https://leetcode.com/problems/knight-dialer/
 *The chess knight has a unique movement, it may move two squares vertically and one square horizontally, or two squares horizontally and one square vertically (with both forming the shape of an L). The possible movements of chess knight are shown in this diagaram:

A chess knight can move as indicated in the chess diagram below:
Input: n = 1
Output: 10
Explanation: We need to dial a number of length 1, so placing the knight over any numeric cell of the 10 cells is sufficient.

https://leetcode.com/problems/knight-dialer/discuss/189284/C%2B%2B-backtracking-and-memoization : used

https://www.youtube.com/watch?v=AspiZ9mUghM : explained

https://leetcode.com/problems/knight-dialer/discuss/190787/How-to-solve-this-problem-explained-for-noobs!!!

https://leetcode.com/problems/knight-dialer/discuss/189287/O(n)-time-O(1)-space-DP-solution-%2B-Google-interview-question-writeup : stealthm comments for DP
https://leetcode.com/problems/knight-dialer/discuss/191495/Java-DP-(Talk-about-Patience...) : dp
 */
vector<vector<int>> memo;
unordered_map<int, vector<int>> mp;
int mod;

int aux(int cur, int start, int N) ;

int knightDialer(int N) {
	mp[0] = {4 , 6};
	mp[1] = {6 , 8};
	mp[2] = {7 , 9};
	mp[3] = {4 , 8};
	mp[4] = {3 , 9, 0};
	mp[5] = { };
	mp[6] = {7, 1, 0};
	mp[7] = {6 , 2};
	mp[8] = {1 , 3};
	mp[9] = {2 , 4};

    memo = vector<vector<int>>(10, vector<int>(N, -1));
   // mod = pow(10, 9) + 7; // WORKS
    int count = 0;

    for(int i = 0; i < 10; i++)
    	count = (count + aux(i, 1, N)) % mod;

    return count;
}

int aux(int cur, int start, int N) {
	if(start == N) return 1;

	if(memo[cur][start] > -1) return memo[cur][start];

	int count = 0;

	for(auto k : mp[cur]) {
		count = (count + aux(k, start + 1, N)) % mod;
	}
	memo[cur][start] = count;
	return count;
}
/*
int main() {
	cout << knightDialer(3) << endl;

	return 0;
}*/
