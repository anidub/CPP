#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <vector>
#include <utility>
#include <unordered_map>

using namespace std;
/*https://www.educative.io/courses/grokking-the-coding-interview/3YxNVYwNR5p
 * Given an array of points in a 2D
 plane, find ‘K’ closest points to the origin.
Input: points = [[1,2],[1,3]], K = 1
Output: [[1,2]]
Explanation: The Euclidean distance between (1, 2) and the origin is sqrt(5).
The Euclidean distance between (1, 3) and the origin is sqrt(10).
Since sqrt(5) < sqrt(10), therefore (1, 2) is closer to the origin.
 *https://leetcode.com/problems/k-closest-points-to-origin/discuss/221532/C%2B%2B-STL-quickselect-priority_queue-and-multiset comments
 *https://www.youtube.com/watch?v=7h1s2SojIRw quick sort explained
 */
class Point {
public:
 int x = 0;
 int y = 0;

 Point(int x, int y) {
   this->x = x;
   this->y = y;
 }

 int distFromOrigin() const {
   return (x * x) + (y * y);
 }

};

class KClosestPointsToOrigin {
public:

	//TC:O(NLOGK), SC:O(K)
	vector<Point> kClosestPoints(vector<Point> &points, int K) {
		vector<Point> result;
 		if(points.empty()) return result;

 		priority_queue<pair<int, int>> pq; // min heap

 		for(int i = 0; i < points.size(); i++) {
 			Point p = points[i];
 			int distance = p.distFromOrigin();

 			pair<int, int> entry = {distance, i};
 			if(pq.size() < K)
 				pq.push(entry);
 			else if(distance < pq.top().first) {
 				pq.pop();
 				pq.push(entry);
 			}
 		}

 		while(!pq.empty()) {
 			int entryIndex = pq.top().second;
 			pq.pop();
 			result.push_back(points[entryIndex]);
 		}
 		return result;
	}


	//OPTIMAL //TC:O(N) for avg and ON^2) for worst, SC:O(1)
	vector<Point> kClosestPointsOptimal(vector<Point> &points, int K) {
		if(points.empty()) return {};

		K--;
		int left = 0, right = points.size() - 1;
		while(true) {
			int p = partition(points, left, right);
			if(p == K)
				break;
			else if(p < K)
				left = p + 1;
			else
				right = p - 1;
		}
		return vector<Point>(points.begin(), points.begin() + K + 1);
	}

	int partition(vector<Point> &points, int left, int right) {
		int pivot = points[right].distFromOrigin();

		for(int i = left; i < right; i++) {
			if(points[i].distFromOrigin() < pivot) {
				swap(points[i], points[left++]);
			}
		}
		swap(points[left], points[right]);
		return left;
	}
};
/*
int main() {
		Point p1 = {1, 3}; Point p2 = {3, 4}; Point p3 = {2, -1};
		vector<Point> points = {p1, p2, p3};
		KClosestPointsToOrigin kcpo;


	  vector<Point> maxHeap = kcpo.kClosestPoints(points, 2);
	  cout << "Here are the k points closest the origin: ";
	  for (auto p : maxHeap) {
	    cout << "[" << p.x << " , " << p.y << "] ";
	  }
	  cout << endl;

	  maxHeap = kcpo.kClosestPointsOptimal(points, 2);
	  cout << "Here are the k points closest the origin: ";
	  for (auto p : maxHeap) {
	    cout << "[" << p.x << " , " << p.y << "] ";
	  }
}
*/
