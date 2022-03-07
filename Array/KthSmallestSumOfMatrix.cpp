#include <iostream>
#include <stdio.h>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <utility>
#include <queue>
#include <set>

using namespace std;
/*
 * https://leetcode.com/problems/find-the-kth-smallest-sum-of-a-matrix-with-sorted-rows/
 * You are given an m * n matrix, mat, and an integer k, which has its rows sorted in non-decreasing order.
You are allowed to choose exactly 1 element from each row to form an array. Return the Kth smallest array sum among all possible arrays.
Example 1:

Input: mat = [[1,3,11],[2,4,6]], k = 5
Output: 7
Explanation: Choosing one element from each row, the first k smallest sum are:
[1,2], [1,4], [3,2], [3,4], [1,6]. Where the 5th sum is 7.
https://leetcode.com/problems/find-the-kth-smallest-sum-of-a-matrix-with-sorted-rows/discuss/609804/C%2B%2B-using-Priority-Queue

https://www.youtube.com/watch?v=ZYlVCy_vRp8
https://www.youtube.com/watch?v=Ih3NcrnXssA
 */
int kthSmallestSumOfMatrix(vector<vector<int>> mat, int k){
	if(mat.empty()) return 0;
	using vv = pair<int, vector<int>>;

	int m = mat.size(), n = mat[0].size();
	priority_queue<vv, vector<vv>, greater<vv>> q;
	set<vector<int>> visited;
	vector<int> vec;

	vector<int> temp(m, 0);
	int sumVal = 0;
	for(int i = 0; i < m; i++)
		sumVal += mat[i][temp[i]];

	q.push({sumVal, temp});
	visited.insert(temp);

	while(vec.size() < k) {
		if(q.empty()) return -1;
		vector<int> cur = q.top().second;
		vec.push_back(q.top().first);
		q.pop();

		for(int i = 0; i < m; i++) {
			if(cur[i] + 1 < n){
				++cur[i];
				if(visited.find(cur) == visited.end()) {
					int val = vec.back() + mat[i][cur[i]] - mat[i][cur[i] - 1];
					q.push({val, cur});
					visited.insert(cur);
				}
				--cur[i];
			}
		}
	}
	return vec.back();
}
//https://www.youtube.com/watch?v=Ih3NcrnXssA
int kthSmallestSumMatrixOther(vector<vector<int>>& mat, int k) {
	int m = mat.size(), n = mat[0].size();
	vector<int> temp = mat[0];

	for(int i = 1; i < m; i++) {
		vector<int> cur;
		for(int j = 0;j < n; j++) {
			for(int it = 0; it < temp.size(); it++) {
				cur.push_back(temp[it] + mat[i][j]);
			}
		}
		sort(cur.begin(), cur.end());
		temp.clear();
		int max_size = min(k+1, (int)cur.size());
		for(int j = 0; j < max_size; j++) {
			temp.push_back(cur[j]);
		}
	}
	return temp[k-1];
}
/*
int main() {
	vector<vector<int>> mat;
	vector<int> v1; v1.push_back(1);v1.push_back(3);v1.push_back(11);
	vector<int> v2; v2.push_back(2);v2.push_back(4);v2.push_back(6);
	mat.push_back(v1);mat.push_back(v2);

	cout << kthSmallestSumOfMatrix(mat, 5) << endl;
	cout << kthSmallestSumMatrixOther(mat, 5) << endl;
	return 0;
}*/
