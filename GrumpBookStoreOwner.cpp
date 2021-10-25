#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <map>
#include <utility>
#include <unordered_map>

using namespace std;
/*
 * https://leetcode.com/problems/grumpy-bookstore-owner/
 * customers (customers[i]) enter the store, and all those customers leave after the end of that minute.
On some minutes, the bookstore owner is grumpy.  If the bookstore owner is grumpy on the i-th minute, grumpy[i] = 1, otherwise grumpy[i] = 0.  When the bookstore owner is grumpy, the customers of that minute are not satisfied, otherwise they are satisfied.
The bookstore owner knows a secret technique to keep themselves not grumpy for X minutes straight, but can only use it once.
Return the maximum number of customers that can be satisfied throughout the day.
Example 1:
Input: customers = [1,0,1,2,1,1,7,5], grumpy = [0,1,0,1,0,1,0,1], X = 3
Output: 16
Explanation: The bookstore owner keeps themselves not grumpy for the last 3 minutes.
The maximum number of customers that can be satisfied = 1 + 1 + 1 + 1 + 7 + 5 = 16.
https://leetcode.com/problems/grumpy-bookstore-owner/discuss/299198/C%2B%2B-Linear-Time-(Easy-to-Understand)
One pass: https://leetcode.com/problems/grumpy-bookstore-owner/discuss/917252/C%2B%2B-sliding-window
https://leetcode.com/problems/grumpy-bookstore-owner/discuss/299237/C%2B%2B-Sliding-Window
 */
int maxSatisfiedCustomers(vector<int>& customers, vector<int>& grumpy, int X) {
	int mins = customers.size();
	int directly_satisfied = 0;

	for(int i = 0; i < mins; i++) {
		if(!grumpy[i]){
			directly_satisfied += customers[i];
			customers[i] = 0;
		}
	}

	int sum = 0, secretly_satisfied = 0;
	for(int i = 0, j = 0; j < mins; j++) {
		sum += customers[j];
		if(j - i == X) {
			sum -= customers[i++];
		}
		secretly_satisfied = max(secretly_satisfied, sum);
	}
	return directly_satisfied + secretly_satisfied;
}
/*
int main() {
	vector<int> customers;
	customers.push_back(1);customers.push_back(0);customers.push_back(1);customers.push_back(2);customers.push_back(1);
	customers.push_back(1);	customers.push_back(7);customers.push_back(5);

	vector<int> grumpy;
	grumpy.push_back(0);grumpy.push_back(1);grumpy.push_back(0);grumpy.push_back(1);
	grumpy.push_back(0);grumpy.push_back(1);grumpy.push_back(0);grumpy.push_back(1);

	cout << maxSatisfiedCustomers(customers, grumpy, 3) << endl;
	return 0;
}*/
