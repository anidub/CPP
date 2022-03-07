#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <vector>
#include <stack>
#include <utility>
#include <string.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;
/*https://leetcode.com/problems/accounts-merge/
 * Given a list of accounts where each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, and the rest of the elements are emails representing emails of the account.

Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some common email to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.

After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in sorted order. The accounts themselves can be returned in any order.
Input: accounts = [["John","johnsmith@mail.com","john_newyork@mail.com"],["John","johnsmith@mail.com","john00@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
Output: [["John","john00@mail.com","john_newyork@mail.com","johnsmith@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
Explanation:
The first and second John's are the same person as they have the common email "johnsmith@mail.com".
The third John and Mary are different people as none of their email addresses are used by other accounts.
We could return these lists in any order, for example the answer [['Mary', 'mary@mail.com'], ['John', 'johnnybravo@mail.com'],
['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']] would still be accepted.

https://leetcode.com/problems/accounts-merge/discuss/1601960/C%2B%2BPython-Simple-Solution-w-Images-and-Explanation-or-Building-Graph-and-DFS : explained
 */
unordered_map<string, vector<string>> G;// adjacency list graph with email as nodes and edges between adjacent email of same account
unordered_set<string> seen;// to mark an email as visited in DFS
vector<vector<string>> accAns;// final answer after merging accounts


void accountsMergeDFS(string& email);
/*Time Complexity : O(NML*log(NM)), where N is the number of accounts,
 *  M is the number of emails per account, L is the length of each email.
 *   We firstly iterate over each email from each account and form the graph which requires O(NML).
 *    Then for every account, we consider the 1st email in it and perform a DFS if that email was not seen previously. Finally the set of emails found in DFS are sorted and inserted into the final list. In worst case, every email may belongs to same person and in this case sorting takes O(NML*log(NM))
Space Complexity : O(NML), required to store the graph.
*/
vector<vector<string>> accountsMerge(vector<vector<string>>& A) {
	if(A.empty()) return {};

	for(auto& acc : A) {
		for(int i = 2; i < acc.size(); i++) {
			G[acc[i]].push_back(acc[i-1]); // create graph with email as nodes and,
			G[acc[i-1]].push_back(acc[i]);// add edges between adjacent nodes of same account
		}
	}

	for(auto& acc : A) {
		if(!seen.count(acc[1])) {// If an email from a account is not previously seen,
			accAns.push_back({acc[0]});// create new account & insert person's name
			accountsMergeDFS(acc[1]);// perform dfs to find all his emails & add it to the list
			sort(begin(accAns.back()) + 1, end(accAns.back()));// sort the emails !!! only emails hence +1 as 0 is for name
		}
	}
	return accAns;
}

void accountsMergeDFS(string& email){
	seen.insert(email);
	accAns.back().push_back(email);
	for(auto& adjEmail : G[email]) {
		if(!seen.count(adjEmail)) {
			accountsMergeDFS(adjEmail);
		}
	}
}
/*
int main() {
	vector<vector<string>> A = {{"John","johnsmith@mail.com","john_newyork@mail.com"},{"John","johnsmith@mail.com","john00@mail.com"},{"Mary","mary@mail.com"},{"John","johnnybravo@mail.com"}};
	accountsMerge(A);
	return 0;
}
*/
