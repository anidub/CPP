#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <queue>

using namespace std;
/*https://leetcode.com/problems/process-restricted-friend-requests/
 * You are given an integer n indicating the number of people in a network. Each person is labeled from 0 to n - 1.

You are also given a 0-indexed 2D integer array restrictions, where restrictions[i] = [xi, yi] means that person xi and person yi cannot become friends, either directly or indirectly through other people.

Initially, no one is friends with each other. You are given a list of friend requests as a 0-indexed 2D integer array requests, where requests[j] = [uj, vj] is a friend request between person uj and person vj.

A friend request is successful if uj and vj can be friends. Each friend request is processed in the given order (i.e., requests[j] occurs before requests[j + 1]), and upon a successful request, uj and vj become direct friends for all future friend requests.

Return a boolean array result, where each result[j] is true if the jth friend request is successful or false if it is not.

Note: If uj and vj are already direct friends, the request is still successful.

 Input: n = 3, restrictions = [[0,1]], requests = [[0,2],[2,1]]
Output: [true,false]
Explanation:
Request 0: Person 0 and person 2 can be friends, so they become direct friends.
Request 1: Person 2 and person 1 cannot be friends since person 0 and person 1 would be indirect friends (1--2--0).

https://leetcode.com/problems/process-restricted-friend-requests/discuss/1576935/C%2B%2B-Union-Find

 */

class UnionFind {
vector<int> id;
public:
	UnionFind(int n) : id(n) {
		iota(begin(id), end(id), 0);
	}

	void connect(int a, int b) {
		id[find(a)] = find(b);
	}

	int find(int a) {
		if(id[a] == a) return a;
		return find(id[a]);
	}

	int connected(int a, int b) {
		return find(a) == find(b);
	}
};
// Time: O(R * B) where `R`/`B` is the length of `requests`/`bans`
// Space: O(N)
vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
	if(requests.empty()) return {};

	vector<bool> ans;
	UnionFind uf(n);

	for(auto &r : requests) {
		int p = uf.find(r[0]), q = uf.find(r[1]); // the leaders of the two parties
		bool valid = true;
		if(!uf.connected(p, q)) { // Only need to check the bans if the two parties are not already connected
			for(auto &b : restrictions) {
				int x = uf.find(b[0]), y = uf.find(b[1]);//the leaders of the two banned parties

				if((x == p && y == q) || (x == q && y == p)) {
					valid = false;
					break;
				}
			}
		}
		ans.push_back(valid);
		if(valid) uf.connect(p, q); // connect two parties if request is valid
	}
	return ans;

}
/*
int main () {
	vector<vector<int>> restrictions = {{0, 1}};
	vector<vector<int>> requests = {{0,2}, {2,1}};

	friendRequests(3, restrictions, requests);
	return 0;
}*/

