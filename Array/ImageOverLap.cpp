#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <utility>
#include <unordered_map>

using namespace std;
/*
 * https://leetcode.com/problems/image-overlap/
 * You are given two images img1 and img2 both of size n x n, represented as binary, square matrices of the same size. (A binary matrix has only 0s and 1s as values.)
We translate one image however we choose (sliding it left, right, up, or down any number of units), and place it on top of the other image.  After, the overlap of this translation is the number of positions that have a 1 in both images.
What is the largest possible overlap?


 */
//https://leetcode.com/problems/image-overlap/discuss/173110/C%2B%2B-easy-to-understand-std%3A%3Aunordered_map-solution
int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
	vector<pair<int, int>> vec1, vec2;

	for(int i = 0; i < A.size(); i++) {
		for(int j = 0; j < B.size(); j++) {
			if(A[i][j])
				vec1.emplace_back(i, j);
			if(B[i][j])
				vec2.emplace_back(i, j);
		}
	}

	unordered_map<string, int> umap;
	int result = 0;

	for(const auto& p1 : vec1) {
		for(const auto& p2 : vec2) {
			string key = to_string(p2.first - p1.first) + " , " + to_string(p2.second - p1.second);
			++umap[key];
			result = max(result, umap[key]);
		}
	}
	return result;

}
/*
int main() {

	return 0;
}
*/
