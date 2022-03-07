#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>
#include <climits>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <utility>
#include <queue>

using namespace std;
/*https://leetcode.com/problems/minimum-cost-to-hire-k-workers/
 * There are n workers. You are given two integer arrays quality and wage where quality[i] is the quality of the ith worker and wage[i] is the minimum wage expectation for the ith worker.

We want to hire exactly k workers to form a paid group. To hire a group of k workers, we must pay them according to the following rules:

Every worker in the paid group should be paid in the ratio of their quality compared to other workers in the paid group.
Every worker in the paid group must be paid at least their minimum-wage expectation.
Given the integer k, return the least amount of money needed to form a paid group satisfying the above conditions. Answers within 10-5 of the actual answer will be accepted.
Example 1:

Input: quality = [10,20,5], wage = [70,50,30], k = 2
Output: 105.00000
Explanation: We pay 70 to 0th worker and 35 to 2nd worker.
https://leetcode.com/problems/minimum-cost-to-hire-k-workers/discuss/142209/O(NlogN)-C%2B%2B-code-using-priority-queue-with-explanation : comments

 */
struct Person{
	int qual;
	int wage;
	double wagePerQuality;
	Person(int qual_, int wage_) {
		qual = qual_;
		wage = wage_;
		wagePerQuality = (double)wage/qual;
	}
};

struct comparator{
	bool operator()(const Person& a, const Person& b) {
		return a.wagePerQuality < b.wagePerQuality;
	}
};
//Time : O(NLOGN)
double minCostToHireKWorkers(vector<int>& quality, vector<int>& wage, int K){
	if(quality.empty()) return 0.0;
	int n = wage.size();
	vector<Person> workers;
	for(int i = 0; i < n; i++) {
		Person p(quality[i], wage[i]);
		workers.push_back(p);
	}
	sort(workers.begin(), workers.end(), comparator()); //Sorting them according in ASC order of Wage/Quality (Lowest cost of 1 unit quality first)
	priority_queue<int> pq;//Just Store the "QUALITY REQUIRED" in MAX HEAP
	int totalQuality = 0;
	double minCost = std::numeric_limits<double>::max();

	for(auto& worker : workers) {
		double rate = worker.wagePerQuality;  //This rate will be applicable to all people seen before as well
		totalQuality += worker.qual;
		pq.push(worker.qual);

		if(pq.size() > K) {
			totalQuality -= pq.top();
			pq.pop();
		}
		if(pq.size() == K) {
			minCost = min(minCost, rate * totalQuality);
		}
	}
	return minCost;
}
/*
int main() {
	vector<int> quality;
	quality.push_back(3);quality.push_back(1);quality.push_back(10);quality.push_back(10);quality.push_back(1);
	vector<int> wage;
	wage.push_back(4);wage.push_back(8);wage.push_back(2);wage.push_back(2);wage.push_back(7);
	cout << minCostToHireKWorkers(quality, wage, 3) << endl;
}*/
