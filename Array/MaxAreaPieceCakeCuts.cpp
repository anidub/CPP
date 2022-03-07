#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>

using namespace std;
/*
 * https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/
 * You are given a rectangular cake of size h x w and two arrays of integers horizontalCuts and verticalCuts where:
horizontalCuts[i] is the distance from the top of the rectangular cake to the ith horizontal cut and similarly, and
verticalCuts[j] is the distance from the left of the rectangular cake to the jth vertical cut.
Return the maximum area of a piece of cake after you cut at each horizontal and vertical position provided in the arrays horizontalCuts and verticalCuts. Since the answer can be a large number, return this modulo 109 + 7.
 Input: h = 5, w = 4, horizontalCuts = [1,2,4], verticalCuts = [1,3]
Output: 4
Explanation: The figure above represents the given rectangular cake. Red lines are the horizontal and vertical cuts. After you cut the cake, the green piece of cake has the maximum area.
https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/discuss/1248524/C%2B%2B-Simple-and-Clean-7-Line-Solution

 */
int maxDiffArea(vector<int> v, int len) {
	sort(v.begin(), v.end());
	int maxdiff = v[0];

	for(int i = 1; i < v.size(); i++) {
		maxdiff = max(maxdiff, v[i] - v[i-1]);
	}

	maxdiff =  max(maxdiff, len - v.back());

	return maxdiff;
}

//Time: O(v log v + h log h), where v and h are the number of vertical and horizontal cuts.
//Memory: O(1), plus memory required by the sort algorithm (from O(log n) to O(n), where n is the number of elements we sort).
int maxareaAfterCuts(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
	return (long)maxDiffArea(horizontalCuts, h) * maxDiffArea(verticalCuts, w) % 1000000007;
}
/*
int main() {
	vector<int> hcuts;
	hcuts.push_back(1);hcuts.push_back(2);hcuts.push_back(4);
	vector<int> vcuts;
	vcuts.push_back(1);vcuts.push_back(3);
	cout << maxareaAfterCuts(5,4,hcuts, vcuts) << endl;

	return 0;
}*/
