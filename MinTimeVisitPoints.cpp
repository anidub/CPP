#include <iostream>
#include <vector>
#include <map>

using namespace std;
/*
https://www.youtube.com/watch?v=jqcmjnXmCaw
https://leetcode.com/problems/minimum-time-visiting-all-points/
Input: points = [[1,1],[3,4],[-1,0]]
Output: 7
Explanation: One optimal path is [1,1] -> [2,2] -> [3,3] -> [3,4] -> [2,3] -> [1,2] -> [0,1] -> [-1,0]
Time from [1,1] to [3,4] = 3 seconds
Time from [3,4] to [-1,0] = 4 seconds
Total time = 7 seconds
*/
int minTimeVisitAllPoints(vector<vector<int>>& points) {
	if(points.size() == 0) return 0;
	int count = 0;
	auto p1 = points[0];

	for(int i = 1; i < points.size(); i++) {
		auto p2 = points[i];
		int dx = p2[0] - p1[0];
		int dy = p2[1] - p1[1];
		count += max(abs(dx), abs(dy));
		p1 = p2;
	}
	cout << count;
	return count;
}

/*int main() {
	vector<vector<int>> nums;
	vector<int> nums1;
	vector<int> nums2;
	vector<int> nums3;

	nums1.push_back(1);nums1.push_back(1);
	nums2.push_back(3);nums2.push_back(4);
	nums3.push_back(-1);nums3.push_back(0);
	nums.push_back(nums1);nums.push_back(nums2);nums.push_back(nums3);
	minTimeVisitAllPoints(nums);
	return 0;
} */
