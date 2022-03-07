#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <unordered_map>

using namespace std;
/*
 * https://leetcode.com/problems/cinema-seat-allocation/
 * Input: n = 3, reservedSeats = [[1,2],[1,3],[1,8],[2,6],[3,1],[3,10]]
Output: 4
Explanation: The figure above shows the optimal allocation for four groups, where seats mark with blue are already reserved and contiguous seats mark with orange are for one group.
 https://leetcode.com/problems/cinema-seat-allocation/discuss/546473/C%2B%2B-Greedy-%2B-Binary-Search
 */
int cinemaSeatAllocation(int n, vector<vector<int>>& res) {
	if(res.empty()) return n * 2;
	unordered_map<int, vector<int>> mp;
	for(int i = 0; i < res.size(); i++) {
		mp[res[i][0]].push_back(res[0][1]);
	}

	int count = 0, rows = 0;
	for(auto& it: mp) {
		vector<int> v = it.second;
		rows++;
		sort(v.begin(), v.end());
		for(int i = 2; i <= 6;) { // because of seating as per question will start at 2,4,6
			auto lb = lower_bound(v.begin(), v.end(), i);
			if(lb == v.end() || *(lb) - i >= 4) { // lb == v.end() if  there is one element in vector v
				count++;
				i += 4;
			} else {
				i += 2;
			}
 		}

	}
	count += ((n - rows) * 2); // in case entire rows are unfilled
	return count;

}
/*
int main() {
	vector<vector<int>> res;
	vector<int> v1; v1.push_back(2);v1.push_back(1);
	vector<int> v2; v2.push_back(1);v2.push_back(8);
	vector<int> v3; v3.push_back(2);v3.push_back(6);

	cout << cinemaSeatAllocation(2, res) << endl;
	return 0;
}*/
