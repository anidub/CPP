#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/rank-teams-by-votes/
 * In a special ranking system, each voter gives a rank from highest to lowest to all teams participated in the competition.
The ordering of teams is decided by who received the most position-one votes. If two or more teams tie in the first position, we consider the second position to resolve the conflict, if they tie again, we continue this process until the ties are resolved. If two or more teams are still tied after considering all positions, we rank them alphabetically based on their team letter.
Given an array of strings votes which is the votes of all voters in the ranking systems. Sort all teams according to the ranking system described above.
Return a string of all teams sorted by the ranking system.
Example 1:
Input: votes = ["ABC","ACB","ABC","ACB","ACB"]
Output: "ACB"
Explanation: Team A was ranked first place by 5 voters. No other team was voted as first place so team A is the first team.
Team B was ranked second by 2 voters and was ranked third by 3 voters.
Team C was ranked second by 3 voters and was ranked third by 2 voters.
As most of the voters ranked C second, team C is the second team and team B is the third.
 *https://leetcode.com/problems/rank-teams-by-votes/discuss/868585/C%2B%2B-or-Sort
 */
string rankTeams(vector<string>& votes) {
	if(votes.empty()) return "";
	int n = votes[0].size();
	vector<string> frequency(26, string(n, '0'));

	for(string& s : votes) {
		for(int i = 0; i < n; i++)
			frequency[s[i] - 'A'][i]++;
	}

	string result = votes[0];

	sort(result.begin(), result.end(),[frequency](char a, char b) {
		if(frequency[a-'A'] == frequency[b - 'A']) return a < b;
		return frequency[a-'A'] > frequency[b-'A'];
 	});
	return result;
}
/*
int main() {
	vector<string> votes;
	votes.push_back("ABC");votes.push_back("ACB");votes.push_back("ABC");votes.push_back("ACB");votes.push_back("ACB");
	cout << rankTeams(votes) << endl;
	return 0;
}
*/
