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
/*https://leetcode.com/problems/leftmost-column-with-at-least-a-one/
 * A row-sorted binary matrix means that all elements are 0 or 1 and each row of the matrix is sorted in non-decreasing order.

Given a row-sorted binary matrix binaryMatrix, return the index (0-indexed) of the leftmost column with a 1 in it. If such an index does not exist, return -1.

You can't access the Binary Matrix directly. You may only access the matrix using a BinaryMatrix interface:

BinaryMatrix.get(row, col) returns the element of the matrix at index (row, col) (0-indexed).
BinaryMatrix.dimensions() returns the dimensions of the matrix as a list of 2 elements [rows, cols], which means the matrix is rows x cols.
Submissions making more than 1000 calls to BinaryMatrix.get will be judged Wrong Answer. Also, any solutions that attempt to circumvent the judge will result in disqualification.

Input: mat = [[0,0],[0,1]]
Output: 1
https://leetcode.com/problems/leftmost-column-with-at-least-a-one/discuss/590080/C%2B%2B-O(N%2BM)-Easy-or-With-Comments
 *
 */
class BinaryMatrix {
  public:
    int get(int row, int col);
    vector<int> dimensions();
};
//TC: O(N+M), SC: O(1) WORKS!!
/*
int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
	int rows = binaryMatrix.dimensions()[0];
	int cols = binaryMatrix.dimensions()[1];

	int check = cols - 1;

	for(int i = 0; i < rows; i++) {//go as much left as you can, and then go downwards.
		while(check >= 0 && binaryMatrix.get(i, check) == 1)
			check--;
	}

	return (check == cols - 1) ? -1 : check;
}*/
/*
int main() {

	return 0;
}*/
