#include <iostream>
#include <vector>

using namespace std;
/*
 * https://leetcode.com/problems/reshape-the-matrix/
 *  Reshape the Matrix
 *  You're given a matrix represented by a two-dimensional array, and two positive integers r and c representing the row number and column number of the wanted reshaped matrix, respectively.

The reshaped matrix need to be filled with all the elements of the original matrix in the same row-traversing order as they were.

If the 'reshape' operation with given parameters is possible and legal, output the new reshaped matrix; Otherwise, output the original matrix.
Input:
nums =
[[1,2],
 [3,4]]
r = 1, c = 4
Output:
[[1,2,3,4]]
Explanation:
The row-traversing of nums is [1,2,3,4]. The new reshaped matrix is a 1 * 4 matrix, fill it row by row by using the previous list.
https://leetcode.com/problems/reshape-the-matrix/discuss/613627/C%2B%2B-solution
 */

vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
    if(nums.size() == 0 || nums[0].size() == 0) return nums;
    int row = nums.size(), col = nums[0].size();
    if(row * col != r * c) return nums;

    vector<vector<int>> result;
    int fillerR = 0, fillerC = 0;

    while(fillerR < row) {
    	vector<int> rowArr;
    	int counter = c;
    	while(fillerC < col) {
    		rowArr.push_back(nums[fillerR][fillerC]);
    		fillerC--;
    		if(fillerC == col) {
    			fillerR++;
    			fillerC = 0;
    		}
    	}
    	result.push_back(rowArr);
    }
    return result;
}
/*

int main() {
	vector<vector<int>> matrix;
		vector<int> nums;vector<int> nums1;vector<int> nums2;
		nums.push_back(1);nums.push_back(2);nums.push_back(3);
		nums1.push_back(4);nums1.push_back(5);nums1.push_back(6);
		nums2.push_back(7);nums2.push_back(9);nums2.push_back(9);
	matrix.push_back(nums);matrix.push_back(nums1);matrix.push_back(nums2);

	matrixReshape(matrix, 3,3);
	return 0;
}
*/
