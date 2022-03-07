#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;
/*
 * https://leetcode.com/problems/cells-with-odd-values-in-a-matrix/
 * https://leetcode.com/problems/cells-with-odd-values-in-a-matrix/discuss/736668/C%2B%2B
Given n and m which are the dimensions of a matrix initialized by zeros and given an array indices where indices[i] = [ri, ci]. For each pair of [ri, ci] you have to increment all cells in row ri and column ci by 1.

Return the number of cells with odd values in the matrix after applying the increment to all indices.
Input: n = 2, m = 3, indices = [[0,1],[1,1]]
Output: 6
Explanation: Initial matrix = [[0,0,0],[0,0,0]].
After applying first increment it becomes [[1,2,1],[0,1,0]].
The final matrix will be [[1,3,1],[1,3,1]] which contains 6 odd numbers.
*/
int oddCells(int n, int m, vector<vector<int>>& indices) {
	int N = indices.size();

	if(N == 0) return 0;
	vector<vector<int>> matrix(n, vector<int>(m,0));
	for(auto item : indices) {
		for(int col = 0; col < m; col++) {
			matrix[item[0]][col]++;
		}

		for(int row = 0; row < n; row++) {
			matrix[row][item[1]]++;
		}
	}

	int result = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(matrix[i][j] % 2 == 1)
				result++;
		}
	}
	cout << result;
	return result;
}

//https://leetcode.com/problems/cells-with-odd-values-in-a-matrix/discuss/473135/c%2B%2B-0ms-9.1Mb
/*int oddCells(int n, int m, vector<vector>& indices) {
vector row_counter(n,0);
vector column_counter(m,0);
for(int i=0;i<indices.size();++i)
{
int r=indices[i][0];
int cl=indices[i][1];
row_counter[r]++;
column_counter[cl]++;
}
int odd_counter=0;
for(int i=0;i<n;++i)
for(int j=0;j<m;++j)
if((row_counter[i]+column_counter[j])%2)
odd_counter++;
return odd_counter;

} */
/*
int main() {

	vector<int> nums1; vector<int> nums2;
	vector<vector<int>> nums;
	nums1.push_back(0); nums1.push_back(1);
	nums2.push_back(1); nums2.push_back(1);
	nums.push_back(nums1); nums.push_back(nums2);
	oddCells(2,3, nums);

	return 0;
} */
