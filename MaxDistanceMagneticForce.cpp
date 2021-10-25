#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <unordered_map>

using namespace std;
/*
 * https://leetcode.com/problems/magnetic-force-between-two-balls/
 *  Rick discovered a special form of magnetic force between two balls if they are put in his new invented basket.
 *  Rick has n empty baskets, the ith basket is at position[i], Morty has m balls and needs to distribute the balls into the baskets such that the minimum magnetic force between any two balls is maximum.
Rick stated that magnetic force between two different balls at positions x and y is |x - y|.
Given the integer array position and the integer m. Return the required force.
Input: position = [1,2,3,4,7], m = 3
Output: 3
Explanation: Distributing the 3 balls into baskets 1, 4 and 7 will make the magnetic force between ball pairs [3, 3, 6]. The minimum magnetic force is 3. We cannot achieve a larger minimum magnetic force than 3.
https://leetcode.com/problems/magnetic-force-between-two-balls/discuss/794147/binary-search-well-commented-code-c
https://www.youtube.com/watch?v=QWiO7t79M_8
 */
int isValidCount(vector<int>& A, int mid, int m) {
	int count = 1;
	int prev = A[0];

	for(int i = 1; i < A.size(); i++) {
		if(A[i] - prev >= mid) {
			prev = A[i];
			count++;
			if(count == m) return true;
		}
	}
	if(count < m) return false;
	return true;
}

int getMaxMagnetic(vector<int>& A, int m) {
	if(A.empty()) return 0;
	sort(A.begin(), A.end());
	int n = A.size();
	// minimum difference can be 0 and maximum can be the difference of last bucket and the first bucket
	int start = 0, end = A[n-1];
	int result;

	while(start <= end) {
		// to avoid  overflow
		int mid = start + (end - start)/2;

		if(isValidCount(A, mid, m)) {
			result = mid;
			start = mid+1; // if this gap is sufficient enough try widening the gap
		} else {
			end = mid-1;// reduce the gap size
		}
	}
	return result;
}
/*
int main() {
	vector<int> A;
	A.push_back(1);A.push_back(2);A.push_back(3);A.push_back(4);A.push_back(7);
	cout << getMaxMagnetic(A, 3) << endl;

	return 0;
}
*/
