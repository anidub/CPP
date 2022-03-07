#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <map>
#include <utility>

using namespace std;
/*
 *https://cheonhyangzhang.gitbooks.io/leetcode-solutions/content/solutions-501-550/531-lonely-pixel-i.html
 *531 Lonely Pixel I
Given a picture consisting of black and white pixels, find the number of black lonely pixels.
The picture is represented by a 2D char array consisting of 'B' and 'W', which means black and white pixels respectively.
A black lonely pixel is character 'B' that located at a specific position where the same row and same column don't have any other black pixels.
Example:
Input:
[['W', 'W', 'B'],
 ['W', 'B', 'W'],
 ['B', 'W', 'W']]

Output: 3
Explanation: All the three 'B's are black lonely pixels.

 */

int findLonelyPixel(vector<vector<char>>& picture) {
	if(picture.empty() || picture.size() == 0 || picture[0].size() == 0)
		return 0;

	int m = picture.size(); int n = picture[0].size();
	vector<int> row(m, 0);
	vector<int> col(n, 0);

	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			if(picture[i][j] == 'B') {
				row[i]++;
				col[j]++;
			}
		}
	}

	int result = 0;
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			if(picture[i][j] == 'B' && row[i] == 1 && col[j] == 1)
				result++;
		}
	}
	return result;
}

//https://massivealgorithms.blogspot.com/2017/08/leetcode-531-lonely-pixel-i.html
int findLonelyPixelOptimal(vector<vector<char>>& picture) {
	if(picture.empty() || picture.size() == 0 || picture[0].size() == 0)
		return 0;

	int m = picture.size();
	int n = picture[0].size();

	vector<int> col(m, 0);

	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			if(picture[i][j] == 'B')
				col[j]++;
		}
	}

	int result = 0;

	for(int i = 0; i < m; i++) {
		int count = 0, pos = 0;
		for(int j = 0; j < n; j++) {
			if(picture[i][j] == 'B') {
				count++;
				pos = j;
			}
		}
		if(count == 1 && col[pos] == 1) result++;
	}
	return result;
}
/*
int main() {
	vector<vector<char>> picture;
	vector<char> row; row.push_back('W');row.push_back('W');row.push_back('B');
	vector<char> row1; row1.push_back('W');row1.push_back('B');row1.push_back('W');
	vector<char> row2; row2.push_back('B');row2.push_back('W');row2.push_back('W');

	picture.push_back(row);picture.push_back(row1);picture.push_back(row2);

	cout << findLonelyPixel(picture) << endl;
	cout << findLonelyPixelOptimal(picture) << endl;

	return 0;
}
*/
