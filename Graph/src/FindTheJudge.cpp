#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <queue>

using namespace std;
/*https://leetcode.com/problems/find-the-town-judge/
 *In a town, there are n people labeled from 1 to n. There is a rumor that one of these people is secretly the town judge.

If the town judge exists, then:

The town judge trusts nobody.
Everybody (except for the town judge) trusts the town judge.
There is exactly one person that satisfies properties 1 and 2.
You are given an array trust where trust[i] = [ai, bi] representing that the person labeled ai trusts the person labeled bi.

Return the label of the town judge if the town judge exists and can be identified, or return -1 otherwise.
https://leetcode.com/problems/find-the-town-judge/discuss/1663344/C%2B%2BJavaPython3Javascript-Everything-you-need-to-know-from-start-to-end-.
 */
//TC: O(M) : m is number of pairs, SC: O(N) : number of people
int findJudge(int n, vector<vector<int>>& trust) {
    if(trust.size() == 0) {
        if(n == 1) return 1;
        else return -1;
    }

    vector<int> Trusted(n + 1, 0);

    for(auto &person : trust) {
    	Trusted[person[0]]--;
    	Trusted[person[1]]++;
    }

    for(int i = 1; i <= n; i++) {
    	if(Trusted[i] == n - 1)
    		return i;
    }
    return -1;

}
/*
int main() {
	vector<vector<int>> trust = {{1,2}};
	cout << findJudge(2, trust) << endl;

	return 0;
}*/
