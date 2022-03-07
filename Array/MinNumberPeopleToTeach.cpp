#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <unordered_map>
#include <unordered_set>

using namespace std;
/*https://leetcode.com/problems/minimum-number-of-people-to-teach/
 * n a social network consisting of m users and some friendships between users, two users can communicate with each other if they know a common language.

You are given an integer n, an array languages, and an array friendships where:

There are n languages numbered 1 through n,
languages[i] is the set of languages the i  user knows, and
friendships[i] = [ui and vi] denotes a friendship between the users u and v
You can choose one language and teach it to some users so that all friends can communicate with each other. Return the minimum number of users you need to teach.

Note that friendships are not transitive, meaning if x is a friend of y and y is a friend of z, this doesn't guarantee that x is a friend of z.


Example 1:

Input: n = 2, languages = [[1],[2],[1,2]], friendships = [[1,2],[1,3],[2,3]]
Output: 1
Explanation: You can either teach user 1 the second language or user 2 the first language.

https://www.youtube.com/watch?v=JKtjz1rurTE : soln
Time: O(NM) N = languages, M : users
Space: O(NM) coz : unordered_map<int, unordered_set<int>> mp;
 */
int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
	int m = languages.size(); int ans = m;
	unordered_map<int, unordered_set<int>> mp;

	for(int i = 0; i < m; i++) {
		for(int j = 0; j < languages[i].size(); j++) {
			mp[languages[i][j]].insert(i+1);
		}
	}

	unordered_set<int> s;
	for(int i = 0; i < friendships.size(); i++)  {
		int user1 = friendships[i][0];
		int user2 = friendships[i][1];
		int f = 0;
		for(int j = 0; j < languages[user1 - 1].size(); j++) {
			int l = languages[user1 - 1][j];
			if(mp[l].find(user2) != mp[l].end()){
				f = 1;
				break;
			}
		}
		if(!f) {
			s.insert(user1);
			s.insert(user2);
		}
	}

	for(int i = 1; i <= n; i++) {
		int c = 0;
		for(auto u : s) {
			if(mp[i].find(u) == mp[i].end())
				c++;
		}
		ans = min(ans, c);
	}

	return ans;
}
/*
int main() {
	vector<vector<int>> languages;
	vector<vector<int>> friendships;

	vector<int> l1; l1.push_back(1);
	vector<int> l2; l2.push_back(2);
	vector<int> l3; l3.push_back(1);l3.push_back(2);
	languages.push_back(l1);languages.push_back(l2);languages.push_back(l3);

	vector<int> f1; f1.push_back(1);f1.push_back(2);
	vector<int> f2; f2.push_back(1);f2.push_back(3);
	vector<int> f3; f3.push_back(2);f3.push_back(3);
	friendships.push_back(f1);friendships.push_back(f2);friendships.push_back(f3);

	cout << minimumTeachings(2, languages, friendships) << endl;
	return 0;
}*/
