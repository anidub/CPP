#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <utility>
#include <unordered_map>
#include <unordered_set>

using namespace std;
/*
 * https://leetcode.com/problems/count-unhappy-friends/
 * You are given a list of preferences for n friends, where n is always even.
For each person i, preferences[i] contains a list of friends sorted in the order of preference. In other words, a friend earlier in the list is more preferred than a friend later in the list. Friends in each list are denoted by integers from 0 to n-1.
All the friends are divided into pairs. The pairings are given in a list pairs, where pairs[i] = [xi, yi] denotes xi is paired with yi and yi is paired with xi.
However, this pairing may cause some of the friends to be unhappy. A friend x is unhappy if x is paired with y and there exists a friend u who is paired with v but:
x prefers u over y, and
u prefers x over v.
Return the number of unhappy friends.
Example 1:
Input: n = 4, preferences = [[1, 2, 3], [3, 2, 0], [3, 1, 0], [1, 2, 0]], pairs = [[0, 1], [2, 3]]
Output: 2
Explanation:
Friend 1 is unhappy because:
- 1 is paired with 0 but prefers 3 over 0, and
- 3 prefers 1 over 2.
Friend 3 is unhappy because:
- 3 is paired with 2 but prefers 1 over 2, and
- 1 prefers 3 over 0.
Friends 0 and 2 are happy.

https://leetcode.com/problems/count-unhappy-friends/discuss/843963/C%2B%2B-Friend-Distance : comments for solution
work out solution on paper to understand
O(N2)
 */

void print(vector<vector<int>>& map){
    for(auto& i : map) {
        for(auto& j : i) {
            cout << " " << j;
        }
        cout << endl;
    }
}

int countUnhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
	int m = preferences[0].size();
	vector<vector<int>> umap(n, vector<int>(n, 0));
	for(int i = 0; i < preferences.size(); i++) {
		for(int j = 0; j < preferences[0].size(); j++) {
			umap[i][preferences[i][j]] = j;
		}
	}
    print(umap);
	unordered_set<int> unhappyPeople;
	for(int i = 0; i < pairs.size(); i++) {
		for(int j = i+1; j < pairs.size(); j++) {
			int one = pairs[i][0]; int two = pairs[i][1]; int three = pairs[j][0]; int four = pairs[j][1];
			//check one and three
			if(umap[one][three] < umap[one][two] && umap[three][one] < umap[three][four]) {
				unhappyPeople.insert(one);
				unhappyPeople.insert(three);
			}
			//check one and four
			if(umap[one][four] < umap[one][two] && umap[four][one] < umap[four][three]) {
				unhappyPeople.insert(one);
				unhappyPeople.insert(four);
			}
			//check two and three
			if(umap[two][three] < umap[two][one] && umap[three][two] < umap[three][four]) {
				unhappyPeople.insert(two);
				unhappyPeople.insert(three);
			}
			//check two and four
			if(umap[two][four] < umap[two][one] && umap[four][two] < umap[four][three]) {
				unhappyPeople.insert(two);
				unhappyPeople.insert(four);
			}
		}
	}
	return unhappyPeople.size();
}

/*
int main() {

	return 0;
}*/
