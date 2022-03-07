#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <queue>

using namespace std;
/*https://leetcode.com/problems/k-closest-points-to-origin/
 * Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).

The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).

You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).
Input: points = [[3,3],[5,-1],[-2,4]], k = 2
Output: [[3,3],[-2,4]]
Explanation: The answer [[-2,4],[3,3]] would also be accepted.

refer soln for why x2 + y2

https://leetcode.com/problems/k-closest-points-to-origin/discuss/221532/C%2B%2B-STL-quickselect-priority_queue-and-multiset //comments
 */

struct compare{
	bool operator() (vector<int>& p, vector<int>& q) {
		return p[0] * p[0] + p[1] * p[1] < q[0] * q[0] + q[1] * q[1]; //x2 + y2 > a2 + b2
	}
};
//TC: O(NLOGK), SC: O(K)
vector<vector<int>> kClosestPoints(vector<vector<int>> points, int K) {
	priority_queue<vector<int>, vector<vector<int>>, compare> pq;

	for(vector<int> &point : points) {
		pq.push(point);
		if(pq.size() > K)
			pq.pop();
	}

	vector<vector<int>> ans;
	while(!pq.empty()) {
		ans.push_back(pq.top());
		pq.pop();
	}
	return ans;
}

int distance(vector<int>& p);
int partition(vector<vector<int>>& points, int low, int high) ;
//TC: O(N): QuickSelect algorithm roughly halves the remaining elements needed to process at each iteration, so the total number of processes will average at N + N/2 + N/4.... which results in an average time complexity of O(N)
//SC : O(1)
vector<vector<int>> KclosestPointsOptimal(vector<vector<int>> points, int K) {
	if(points.empty()) return {};
	int left = 0, right = points.size() - 1;
	K--;
	while(true) {
		int p = partition(points, left, right);
		if(p == K)
			break;
		else if(p < K)
			left = p + 1;
		else
			right = p - 1;
	}
	vector<vector<int>> ans;
	//return vector<vector<int>>(points.begin(), points.begin() + K + 1); //works
	return ans;
}

int partition(vector<vector<int>>& points, int low, int high) {
	int pivot = distance(points[high]);
	for(int i = low; i < high; i++) {
		if(distance(points[i]) < pivot)
			swap(points[i], points[low]);
	}
	swap(points[high], points[low]);
	return low;
}

int distance(vector<int>& p) {
	return p[0] * p[0] + p[1] * p[1];
}
/*
int main() {
	vector<vector<int>> points = {{-5,4},{-6,-5},{4,6}};
	KclosestPointsOptimal(points, 2);

	return 0;
}
*/
