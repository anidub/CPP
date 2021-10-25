#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <utility>
#include <sstream>
#include <stack>

using namespace std;
/*
 * https://leetcode.com/problems/invalid-transactions/
 * A transaction is possibly invalid if:
the amount exceeds $1000, or;
if it occurs within (and including) 60 minutes of another transaction with the same name in a different city.
You are given an array of strings transaction where transactions[i] consists of comma-separated values representing the name, time (in minutes), amount, and city of the transaction.
Return a list of transactions that are possibly invalid. You may return the answer in any order.
Example 1:

Input: transactions = ["alice,20,800,mtv","alice,50,100,beijing"]
Output: ["alice,20,800,mtv","alice,50,100,beijing"]
Explanation: The first transaction is invalid because the second transaction occurs within a difference of 60 minutes, have the same name and is in a different city. Similarly the second one is invalid too.


 https://leetcode.com/problems/invalid-transactions/discuss/701427/C%2B%2B-or-Stringstream-or-Naive-approach
 */
//O(N)
vector<string> invalidTransactions(vector<string>& transactions) {
	vector<string> result;
	int n = transactions.size();
	if(transactions.empty()) return result;
	vector<vector<string>> flattened;

	for(int i = 0; i < n; i++) {
		stringstream ss(transactions[i]);
		string str;
		vector<string> v;
        while(getline(ss, str, ',')) //works
            v.push_back(str);
		flattened.push_back(v);
	}

	vector<bool> store(n, false);

	for(int i = 0; i < n; i++) {
		if(stoi(flattened[i][2]) > 1000)
			store[i] = true;
		for(int j = i+1; j < n; j++) {
			if(flattened[i][0] == flattened[j][0] && flattened[i][3] != flattened[j][3]
					&& (abs(stoi(flattened[i][1]) - stoi(flattened[j][1])) <= 60)) {
				store[i] = true;
				store[j] = true;
			}
		}
	}
	for(int i = 0; i < n; i++) {
		if(store[i])
			result.push_back(transactions[i]);
	}
	return result;
}
/*
int main() {
	vector<string> transactions;
	transactions.push_back("alice,20,800,mtv"); transactions.push_back("alice,50,100,beijing");
	invalidTransactions(transactions);
	return 0;
}
*/
