#include <iostream>
#include <vector>

using namespace std;
/*
 * https://leetcode.com/problems/lucky-numbers-in-a-matrix/
 * Given a m * n matrix of distinct numbers, return all lucky numbers in the matrix in any order.

A lucky number is an element of the matrix such that it is the minimum element in its row and maximum in its column.
 *
 * Example 1:

Input: matrix = [[3,7,8],[9,11,13],[15,16,17]]
Output: [15]
Explanation: 15 is the only lucky number since it is the minimum in its row and the maximum in its column
Example 2:

Input: matrix = [[1,10,4,2],[9,3,8,7],[15,16,17,12]]
Output: [12]
Explanation: 12 is the only lucky number since it is the minimum in its row and the maximum in its column.

https://leetcode.com/problems/lucky-numbers-in-a-matrix/discuss/941933/C%2B%2B-99
 */
vector<int> luckyNumbers (vector<vector<int>>& matrix) {
    vector<int> result;
    if(matrix.size() == 0 || matrix[0].size() == 0)
    	return result;
    vector<int> minRow;

    for(const auto& i : matrix) //stores min element from every row
    	//minRow.push_back(*min_element(i.begin(), i.end())); works

    for(int i = 0; i < matrix[0].size(); i++) { //iterates columns
    	int num = 0, pos = 0;
    	for(int k = 0; k < matrix.size(); k++) { //iterates rows check for every column
    		if(num < matrix[k][i]){
    			num = matrix[k][i];
    			pos = k;
    		}
    	}
    		if(num == minRow[pos]) //compares num if same with that of min row for same column
    			result.push_back(num);
    	}
    return result;
}
/*
int main() {
	vector<int> nums;

	return 0;
}*/
