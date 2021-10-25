#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>

using namespace std;
/*
 * https://leetcode.com/problems/image-smoother/
 * Given a 2D integer matrix M representing the gray scale of an image, you need to design a smoother to make the gray scale of each cell becomes the average gray scale (rounding down) of all the 8 surrounding cells and itself. If a cell has less than 8 surrounding cells, then use as many as you can.
 * Input:
[[1,1,1],
 [1,0,1],
 [1,1,1]]
Output:
[[0, 0, 0],
 [0, 0, 0],
 [0, 0, 0]]
Explanation:
For the point (0,0), (0,2), (2,0), (2,2): floor(3/4) = floor(0.75) = 0
For the point (0,1), (1,0), (1,2), (2,1): floor(5/6) = floor(0.83333333) = 0
For the point (1,1): floor(8/9) = floor(0.88888889) = 0

https://leetcode.com/problems/image-smoother/discuss/1076187/Easy-to-understand-C%2B%2B-solution
https://leetcode.com/problems/image-smoother/discuss/698958/C%2B%2B-solution

 */

vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
    int n = M.size(), m = M[0].size();
    vector<vector<int>> result(n, vector<int>(m));

    for(int i = 0; i < n; i++) {
    	for(int j = 0; j < m; j++) {
    		int sum = 0, total = 0;
    		for(int x = -1; x <= 1; x++) {
    			for(int y = -1; y <= 1; y++) {
    				if(i+x >= 0 && i+x < n && j+y >= 0 && j+y < m)
    					sum += M[i+x][j+y]; total++;
    			}
    		}
    		result[i][j] = sum/total;
    	}
    }
    return result;
}

/*
int main() {
	vector<vector<int>> matrix;
	vector<int> nums;vector<int> nums1;vector<int> nums2;
	nums.push_back(1);nums.push_back(1);nums.push_back(1);
	nums1.push_back(1);nums1.push_back(0);nums1.push_back(1);
	nums2.push_back(1);nums2.push_back(1);nums2.push_back(1);
	matrix.push_back(nums);matrix.push_back(nums1);matrix.push_back(nums2);
	imageSmoother(matrix);

	return 0;
}*/
