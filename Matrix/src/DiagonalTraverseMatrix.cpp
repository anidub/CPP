#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <vector>
#include <stack>
#include <utility>
#include <string.h>
#include <queue>
#include <unordered_set>

using namespace std;
/*https://leetcode.com/problems/diagonal-traverse/
 * Given an m x n matrix mat, return an array of all the elements of the array in a diagonal order.
 *
 *Input: mat = [[1,2,3],
 *              [4,5,6],
 *              [7,8,9]]
Output: [1,2,4,7,5,3,6,8,9]

https://leetcode.com/problems/diagonal-traverse/discuss/136365/C%2B%2B-O((N%2BM)2)-with-O(1)-extra-memory-explained : well explained
 */

//TC: O((N+M)^2) SC:  O(1)
vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
	if(matrix.empty() || matrix[0].size() == 0) return {};
	vector<int> result;

	const int N = matrix.size();
	const int M = matrix[0].size();

	vector<int> res;

	for(int s = 0; s <= N + M - 2; s++) {
		for(int x = 0; x <= s; x++) {
			int i = x;
			int j = s - i;

			if(s % 2 == 0) swap(i, j); // to  change direction..works for anti direction also then change to s% 2 != 0

			if(i >= N || j >= M) continue;

			res.push_back(matrix[i][j]);
		}
	}
	return res;
}

// Time/Space: O(MN); O(MN) // matrix is M by N
 vector<int> findDiagonalOrderNM(vector<vector<int>>& matrix) {
        vector<vector<int>> dict; // simulate hashmap
        for(int i = 0; i < matrix.size(); i++)
            for(int j = 0; j < matrix[i].size(); j++){
                if(i+j == dict.size()) dict.push_back({});
                dict[i+j].push_back(matrix[i][j]);
            }

        bool flip = true;
        vector<int> ans;
        for(const auto& diag: dict){
            if(flip == true) ans.insert(ans.end(), rbegin(diag), rend(diag));
            else ans.insert(ans.end(), begin(diag), end(diag));
            flip = !flip;
        }
        return ans;
 }
/*
int main() {
	vector<vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}};

	findDiagonalOrder(mat);

	return 0;
}
*/
