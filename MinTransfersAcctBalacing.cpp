#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>
#include <climits>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <utility>
#include <unordered_map>

using namespace std;
/*465. Optimal Account Balancing Optimal Account Balancing
 * https://www.cnblogs.com/grandyang/p/6108158.html
 * A group of friends went on holiday and sometimes lent each other money. For example, Alice paid for Bill's lunch for $10. Then later Chris gave Alice $5 for a taxi ride. We can model each transaction as a tuple (x, y, z) which means person x gave person y $z. Assuming Alice, Bill, and Chris are person 0, 1, and 2 respectively (0, 1, 2 are the person's ID), the transactions can be represented as [[0, 1, 10], [2, 0, 5]].
Given a list of transactions between a group of people, return the minimum number of transactions required to settle the debt.
A transaction will be given as a tuple (x, y, z). Note that x ≠ y and z > 0. Person's IDs may not be linear, e.g. we could have the persons 0, 1, 2 or we could also have the persons 0, 2, 6. Example 1:
Input:
[[0,1,10], [2,0,5]]
Output:
2
Explanation:
Person #0 gave person #1 $10.
Person #2 gave person #0 $5.

Two transactions are needed. One way to settle the debt is person #1 pays person #0 and #2 $5 each.
https://www.cnblogs.com/grandyang/p/6108158.html
 */
void minTransfersAcctBalanceHelper(vector<int>& acct, int start, int cnt, int& result) {
	int n = acct.size();
	while(start < n && acct[start] == 0) start++;
	if(start == n) {
		result = min(result, cnt);
		return;
	}

	for(int i = start+1; i < n; i++) {
		if((acct[i] < 0 && acct[start] > 0) || (acct[i] > 0 && acct[start] < 0)) {
			acct[i] += acct[start];
			minTransfersAcctBalanceHelper(acct, start+1, cnt+1, result);
			acct[i] -= acct[start];
		}
	}
}

int minTransfersAcctBalance(vector<vector<int>>& transactions) {
	if(transactions.empty()) return 0;
	int result = INT_MAX;
	unordered_map<int, int> mp;
	for(auto& t : transactions) {
		mp[t[0]] -= t[2];
		mp[t[1]] += t[2];
	}
	vector<int> acct;
	for(auto& m : mp) {
		if(m.second != 0)
			acct.push_back(m.second);
	}
	minTransfersAcctBalanceHelper(acct, 0, 0, result);
	return result;
}
/*
int main(){
    vector<vector<int>> t;
    vector<int> t1; t1.push_back(0);t1.push_back(1);t1.push_back(10);
    vector<int> t2; t2.push_back(2);t2.push_back(0);t2.push_back(5);
    t.push_back(t1); t.push_back(t2);
    cout << minTransfersAcctBalance(t) << endl;

    return 0;
}*/
