#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <unordered_map>
#include <unordered_set>
#include <utility>

using namespace std;
/*https://www.educative.io/courses/grokking-the-coding-interview/g7pBzR12YPl
 *Input: str1="xy#z", str2="xyz#"
Output: false
Explanation: After applying backspaces the strings become "xz" and "xy" respectively.
 */
int getNextValidCharIndex(const string &str, int index);

//TC:O(N_M), SC:O(1)
bool compareStringBackspaces(const string &str1, const string &str2) {
	if(str1.empty() || str2.empty()) return false;
	int index1 = str1.length() - 1, index2 = str2.length() - 1;

	while(index1 >= 0 || index2 >= 0) {
		int i1 = getNextValidCharIndex(str1, index1);
		int i2 = getNextValidCharIndex(str2, index2);

		if(i1 < 0 && i2 < 0) return true;
		if(i1 < 0 || i2 < 0) return false;

		if(str1[i1] != str2[i2]) return false;

		index1 = i1 - 1; // -1 because the current char is same
		index2 = i2 - 1;
	}
	return true;
}

int getNextValidCharIndex(const string &str, int index) {
	int backSpace = 0;

	while(index >= 0) {
		if(str[index] == '#')
			backSpace++;
		else if(backSpace > 0)
			backSpace--;
		else
			break;
		index--;
	}
	return index;
}
/*
int main() {
	string s1 = "xy#z";
	string s2 = "xzz#";
	cout << compareStringBackspaces(s1, s2) << endl;

	return 0;
}*/
