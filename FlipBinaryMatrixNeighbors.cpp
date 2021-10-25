#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <utility>
#include <unordered_set>
#include <unordered_map>

using namespace std;

bool check(vector<vector<int>> mat, int n, int m) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(mat[i][j] == 1) return false;
		}
	}
	return true;
}

void flip(vector<vector<int>> mat, int n, int m, int i, int j) {
	mat[i][j] = mat[i][j] ^ 1;
	if(i - 1 >= 0) mat[i - 1][j] = mat[i-1][j] ^ 1;
	if(j - 1 >= 0) mat[i][j - 1] = mat[i][j-1] ^ 1;
	if(i + 1 < n) mat[i + 1][j] = mat[i+1][j] ^ 1;
	if(j + 1 < m) mat[i][j + 1] = mat[i][j+1] ^ 1;
}

int helper(vector<vector<int>> mat, int n, int m, unordered_set<string> st, unordered_map<string, int> mp) {
	if(check(mat, n, m)) return 0;
	string state = "";
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			state += to_string(mat[i][j]);
		}
	}
	cout << "state:" << state << endl;

	if(mp.count(state)) return mp[state];
	if(st.count(state)) return INT_MAX;

	st.insert(state);
	int min_value = INT_MAX;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			flip(mat, n, m, i, j);
			int small = helper(mat, n, m, st, mp);
			if(small != INT_MAX) min_value = min(min_value, 1 + small);
			flip(mat, n, m, i, j);
		}
	}
	st.erase(state);
	mp[state] = min_value;
	return min_value;
}

int minFlipsBinary(vector<vector<int>> mat) {
	int n = mat.size(), m = mat[0].size();
	unordered_map<string, int> mp;
	unordered_set<string> st;
	int result = helper(mat, n, m, st, mp);
	return result == INT_MAX ? -1: result;
}
/*
int main() {
	vector<vector<int>> mat;
	vector<int> v1; v1.push_back(0);v1.push_back(0);
	vector<int> v2; v2.push_back(0);v2.push_back(1);
	mat.push_back(v1);  mat.push_back(v2);

	cout << minFlipsBinary(mat) << endl;

	return 0;
}
 */

