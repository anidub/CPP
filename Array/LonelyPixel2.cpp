#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <unordered_map>

using namespace std;
/*
 * https://www.cnblogs.com/grandyang/p/6754987.html
 * Lonely Pixel II
 * Given a picture consisting of black and white pixels, and a positive integer N, find the number of black pixels located at some specific row R and column C that align with all the following rules:

Row R and column C both contain exactly N black pixels.
For all rows that have a black pixel at column C, they should be exactly the same as row R
The picture is represented by a 2D char array consisting of'B' and'W', which means black and white pixels respectively.

Example:
Input:
[['W','B','W','B','B','W'],
 ['W','B','W','B','B','W'],
 ['W','B','W','B','B','W'],
 ['W','W','B','W','B','W']]

N = 3
Output: 6
 Explanation: All the bold'B' are the black pixels we need (all'B's at column 1 and 3).
        0 1 2 3 4 5 column index
0 [['W', 'B' ,'W', 'B' ,'B','W'],
1 ['W', 'B' ,'W', 'B' ,'B','W'],
2 ['W', 'B' ,'W', 'B' ,'B','W'],
3 ['W','W','B','W','B','W']]
row index

Take'B' at row R = 0 and column C = 1 as an example:
Rule 1, row R = 0 and column C = 1 both have exactly N = 3 black pixels.
Rule 2, the rows have black pixel at column C = 1 are row 0, row 1 and row 2. They are exactly the same as row R = 0
https://massivealgorithms.blogspot.com/2017/08/leetcode-533-lonely-pixel-ii.html
time complexity is O(m*n). m = number of rows, n = number of columns.
 */

int findBlackPixel(vector<vector<char>>& picture, int N) {
	if(picture.empty() || picture[0].empty()) return 0;
	int m = picture.size(); int n = picture[0].size();
	int result = 0; int k = 0;
	vector<int> colCount(m, 0);
	unordered_map<string, int> umap;
	cout << " ok here" << endl;
	for(int i = 0; i < m; i++) {
		int count = 0;
		string keyS = "";
		for(int j = 0; j < n; j++) {
			if(picture[i][j] == 'B') {
				colCount[j]++;
				count++;
			}
			keyS += picture[i][j];
		}
		if(count == N) {
			umap[keyS]++;
		}
	}
	cout << "here" << endl;
	for(auto& it: umap) {
		if(it.second != N) continue;
		string key = it.first;
		for(int i = 0; i < n; i++) {
			if(key[i] == 'B' && colCount[i] == N)
				result += N;
		}
	}
	return result;
}
/*
int main() {
	vector<vector<char>> picture;
	vector<char> p1; p1.push_back('W');p1.push_back('B');p1.push_back('W');p1.push_back('B');p1.push_back('B');p1.push_back('W');
	vector<char> p2; p2.push_back('W');p2.push_back('B');p2.push_back('W');p2.push_back('B');p2.push_back('B');p2.push_back('W');
	vector<char> p3; p3.push_back('W');p3.push_back('B');p3.push_back('W');p3.push_back('B');p3.push_back('B');p3.push_back('W');
	vector<char> p4; p4.push_back('W');p4.push_back('W');p4.push_back('B');p4.push_back('W');p4.push_back('B');p4.push_back('B');
	picture.push_back(p1);picture.push_back(p2);picture.push_back(p3);picture.push_back(p4);
	cout << findBlackPixel(picture, 3) << endl;

	return 0;
}
*/
