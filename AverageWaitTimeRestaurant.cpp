#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <utility>

using namespace std;
/*
 * https://leetcode.com/problems/average-waiting-time/
 there is a restaurant with a single chef. You are given an array customers, where customers[i] = [arrivali, timei]:

arrivali is the arrival time of the ith customer. The arrival times are sorted in non-decreasing order.
timei is the time needed to prepare the order of the ith customer.
When a customer arrives, he gives the chef his order, and the chef starts preparing it once he is idle. The customer
waits till the chef finishes preparing his order.
 The chef does not prepare food for more than one customer at a time. The chef prepares food for customers in the order they were given in the input.

Input: customers = [[5,2],[5,4],[10,3],[20,1]]
Output: 3.25000
Explanation:
1) The first customer arrives at time 5, the chef takes his order and starts preparing it immediately at time 5, and finishes at time 7, so the waiting time of the first customer is 7 - 5 = 2.
2) The second customer arrives at time 5, the chef takes his order and starts preparing it at time 7, and finishes at time 11, so the waiting time of the second customer is 11 - 5 = 6.
3) The third customer arrives at time 10, the chef takes his order and starts preparing it at time 11, and finishes at time 14, so the waiting time of the third customer is 14 - 10 = 4.
4) The fourth customer arrives at time 20, the chef takes his order and starts preparing it immediately at time 20, and finishes at time 21, so the waiting time of the fourth customer is 21 - 20 = 1.
So the average waiting time = (2 + 6 + 4 + 1) / 4 = 3.25.

https://leetcode.com/problems/average-waiting-time/discuss/987328/JavaC%2B%2BPython-Straight-Forward
 */

double averageWaitingTime(vector<vector<int>>& customers) {
	if(customers.empty()) return 0.0;
	double result = customers[0][1];
	int lastEnd = customers[0][0] + customers[0][1];

	for(int i = 1; i < customers.size(); i++) {
		int timePrepare = customers[i][1];
		lastEnd = max(lastEnd, customers[i][0]) + timePrepare;
		result += lastEnd - customers[i][0];
	}
	return (double)result/customers.size();
}

double averageWaitingTimeClean(vector<vector<int>>& customers) {
	if(customers.empty()) return 0.0;
	double wait = 0, cur = 0;
	for(auto& a : customers) {
		cur = max(cur, 1.0 * a[0]) + a[1];
		wait += cur - a[0];
	}
	return (double) wait/ customers.size();
}
/*
int main() {
	vector<vector<int>> customers;
	vector<int> nums; nums.push_back(5);nums.push_back(2);
	vector<int> nums1; nums1.push_back(5);nums1.push_back(4);
	vector<int> nums2; nums2.push_back(10);nums2.push_back(3);
	vector<int> nums3; nums3.push_back(20);nums3.push_back(1);
	customers.push_back(nums);customers.push_back(nums1);customers.push_back(nums2);customers.push_back(nums3);
	cout << averageWaitingTime(customers) << endl;
	cout << averageWaitingTimeClean(customers) << endl;

	return 0;
}*/
