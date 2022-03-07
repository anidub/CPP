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
/*774.Minimize-Max-Distance-to-Gas-Station
 * On a horizontal number line, we have gas stations at positions stations[0], stations[1], ..., stations[N-1], where N = stations.length.
Now, we add K more gas stations so that D, the maximum distance between adjacent gas stations, is minimized.
Return the smallest possible value of D.
Example:
Input: stations = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], K = 9
Output: 0.500000
https://blog.csdn.net/magicbean2/article/details/79663323
https://www.cnblogs.com/Dylan-Java-NYC/p/8452521.html : used
 * https://www.youtube.com/watch?v=gcDUAw3vQlg : to understand
 */
bool isPossibleMinMaxGasDist(vector<int>& stations, int K, double mid) {
	int count = 0;
	for(int i = 0; i < stations.size()-1; i++) {
		count += (int)(stations[i+1] - stations[i])/mid;
	}
	return count <= K;
}

double minMaxGasDistance(vector<int> stations, int K) {
	if(stations.empty()) return 0.0;
	double left = 0, right = 1e8;

	while(right - left > 1e-6) {
		double mid = left + (right - left)/2.0;
		if(isPossibleMinMaxGasDist(stations, K, mid))
			right = mid;
		else
			left = mid;
	}
	return left;
}
/*
int main() {
    vector<int> stations;
    stations.push_back(1);stations.push_back(2);stations.push_back(3);
    stations.push_back(4);stations.push_back(5);stations.push_back(6);
    stations.push_back(7);stations.push_back(8);stations.push_back(9);
    stations.push_back(10);

    cout << minMaxGasDistance(stations, 9);

	return 0;
}*/
