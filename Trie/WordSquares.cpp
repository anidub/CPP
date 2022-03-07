#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>
#include <climits>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <utility>
#include <unordered_map>
#include <set>

using namespace std;

void wordSquaresHelper(int i, int n, vector<vector<char>>& mat, unordered_map<string, set<string>>& mp, vector<vector<string>>& res) {
	if(i == n) {
		vector<string> out;
		for(int j = 0; j < n; j++)
			out.push_back(string(mat[j].begin(), mat[j].end()));
		res.push_back(out);
		return;
	}

	string key = string(mat[i].begin(), mat[i].begin() + i);
	for(string str : mp[key]) {
		mat[i][i] = str[i];
		int j = i+1;
		for(; j < n; j++) {
			mat[i][j] = str[j];
			mat[j][i] = str[j];
			if(!mp.count(string(mat[j].begin(), mat[j].begin() + i + 1))) break;
		}
		if(j == n) wordSquaresHelper(i+1, n, mat, mp, res);
	}
}

vector<vector<string>> wordSquares(vector<string>& words) {
	if(words.empty()) return {};
	vector<vector<string>> res;
	unordered_map<string, set<string>> mp;
	int n = words[0].size();
	for(string& word : words) {
		for(int i = 0; i < n; i++) {
			string key = word.substr(0, i);
			mp[key].insert(word);
		}
	}
	vector<vector<char>> mat(n, vector<char>(n));
	wordSquaresHelper(0, n, mat, mp, res);
	return res;
}
/*
int main() {
	vector<string> words;
	words.push_back("area");words.push_back("lead");
	words.push_back("wall");words.push_back("lady");
	words.push_back("ball");
    vector<vector<string>> res = wordSquares(words);
    for(auto& s : res) {
        for(auto& i : s) {
            cout << i << endl;
        }
        cout << "---" << endl;
    }
	return 0;
}*/
