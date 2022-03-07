#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <unordered_map>

using namespace std;
/*
 * A binary matrix means that all elements are 0 or 1. For each individual row of the matrix, this row is sorted in non-decreasing order.
Given a row-sorted binary matrix binaryMatrix, return leftmost column index(0-indexed) with at least a 1 in it. If such index doesn't exist, return -1.
You can't access the Binary Matrix directly.  You may only access the matrix using a BinaryMatrix interface:
BinaryMatrix.get(x, y) returns the element of the matrix at index (x, y) (0-indexed).
BinaryMatrix.dimensions() returns a list of 2 elements [n, m], which means the matrix is n * m.
Submissions making more than 1000 calls to BinaryMatrix.get will be judged Wrong Answer
 *
 * http://leetcode.libaoj.in/leftmost-column-with-at-least-a-one.html : use this

https://www.geeksforgeeks.org/leftmost-column-with-atleast-one-1-in-a-row-wise-sorted-binary-matrix-set-2/
 */
/*
 * Time complexity : O(N⋅M) : cant use since constraint is to have max calls at 1000 and with this approach can go beyond
int leftMostColumnTLE(BinaryMatrix& binaryMatrix) {
	int rows = binaryMatrix.dimensions[0];
	int cols = binaryMatrix.dimensions[1];
	int smallestIndex = cols;

	for(int row = 0; row < rows; row++) {
		for(int col = 0; col < cols; col++) {
			if(binaryMatrix.get(row, col) == 1) {
				smallestIndex = min(smallestIndex, col);
				break;
			}
		}
	}
	return smallestIndex == cols - 1 ? -1 : smallestIndex;
}
//O(NlogM)
int leftMostColumnBinarySearch(BinaryMatrix& binaryMatrix) {
	int rows = binaryMatrix.dimensions[0];
	int cols = binaryMatrix.dimensions[1];
	int smallestIndex = cols;

	for(int row = 0; row < rows; row++) {
		int low = 0;
		int high = cols-1;
		while(low < high) {
			int mid = (low + high)/2;

			if(binaryMatrix.get(row,mid) == 0) {
				low = mid+1;
			} else {
				high = mid;
			}
			if(binaryMatrix.get(row, low) == 1) {
				smallestIndex = min(smallestIndex, low);
			}
		}
	}
	return smallestIndex == cols ? -1 : smallestIndex;
}

//Time complexity :  O(N+M)
int leftMostColumnWithOne(BinaryMatrix& binaryMatrix) {
	int rows = binaryMatrix.dimensions[0];
	int cols = binaryMatrix.dimensions[1];

	int currentRow = 0;
	int currentCol = cols-1;

	while(currentRow < rows && currentCol >= 0) {
		if(binaryMatrix.get(currentRow, currentCol) == 0) {
			currentRow++;
		} else {
			currentCol--;
		}
	}
	return (currentCol == cols - 1) ? -1 : currentCol + 1;
}*/
