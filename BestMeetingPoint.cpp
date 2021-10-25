#include <iostream>
#include <stdio.h>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <utility>
#include <queue>
#include <unordered_set>

using namespace std;
/* 296. Best Meeting Point
 * A group of two or more people wants to meet and minimize the total travel distance. You are given a 2D grid of values 0 or 1, where each 1 marks the home of someone in the group. The distance is calculated using Manhattan Distance, where distance(p1, p2) = |p2.x - p1.x| + |p2.y - p1.y|.

Example:

Input:

1 - 0 - 0 - 0 - 1
|   |   |   |   |
0 - 0 - 0 - 0 - 0
|   |   |   |   |
0 - 0 - 1 - 0 - 0

Output: 6

Explanation: Given three people living at
(0,0)
,
(0,4)
, and
(2,2)
:
   The point 0,2)
 is an ideal meeting point, as the total travel distance
             of 2+2+2=6 is minimal. So return 6.

 * https://www.cnblogs.com/grandyang/p/5291058.html
 * https://just4once.gitbooks.io/leetcode-notes/content/leetcode/math/296-best-meeting-point.html
 */
int minTotalDistanceTravelTime(vector< int > v) {
    /* int res = 0 ;
     for(int& i : v) cout << i << " ";
     cout << endl;
    sort(v.begin(), v.end());
    for(int& i : v)
    	cout << i << " ";
    cout << endl;
    int i = 0 , j = v.size()- 1 ;
     while (i <j){
    	 cout << "j:" << v[j] << " i:" << v[i] << endl;
    	 res += v[j]-v[i];
    	 j--;i++;
     }

     cout << "res:" << res << endl;
     return res;*/
	int result = 0;
	sort(v.begin(), v.end());
	int i = 0, j = v.size()-1;
	while(i < j) {
		result += v[j] - v[i];
		j--; i++;
	}
	return result;
}
//Time complexity O(mn + mn log(mn)) = O(mn log(mn)) Space complexity O(mn)
int minimizeTravelTime(vector<vector<int>>&  grid) {
	vector<int> rows, cols;
	for(int i = 0; i < grid.size(); i++) {
		for(int j = 0; j < grid[0].size(); j++) {
			if(grid[i][j] == 1){
				rows.push_back(i);
				cols.push_back(j);
			}
		}
	}
	return minTotalDistanceTravelTime(rows) + minTotalDistanceTravelTime(cols);
}

/*
int main() {
	vector<vector<int>> grid;
	vector<int> v1; v1.push_back(1);v1.push_back(0);v1.push_back(0);v1.push_back(0);v1.push_back(1);
	vector<int> v2; v2.push_back(0);v2.push_back(0);v2.push_back(0);v2.push_back(0);v2.push_back(0);
	vector<int> v3; v3.push_back(0);v3.push_back(0);v3.push_back(1);v3.push_back(0);v3.push_back(0);
	grid.push_back(v1);grid.push_back(v2);grid.push_back(v3);
	cout << minimizeTravelTime(grid) << endl;
	return 0;
}*/
