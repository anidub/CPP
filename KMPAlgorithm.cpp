#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <utility>

using namespace std;
/*
 * KMP Algorithm for pattern matching. O(n+m)
 * Best explained :https://www.youtube.com/watch?v=V5-7GzOfADQ
 * https://www.educative.io/edpresso/what-is-the-knuth-morris-pratt-algorithm
 */
vector<int> prepareArrayKMP(string pattern) {
	int m = pattern.size();
	vector<int> arr(m, 0);
	int i = 0, j = 1;

	while(j < m) {
		if(pattern[i] == pattern[j]) {
			i++;
			arr[j] = i;
			j++;
		} else if (i == 0) {
			arr[j] = 0;
			j++;
		} else
			i = arr[i-1];
	}
	return arr;
}
void printArr(vector<int> arr) {
	for(int& i : arr)
		cout << " " << i << endl;
}

bool kmp_search(string original, string pattern) {
	vector<int> arr = prepareArrayKMP(pattern);

	int m = original.size();
	int n = pattern.size();
	int j = 0, i = 0;
	printArr(arr);

	while(i < m && j < n) {
		if(pattern[j] == original[i] && j == m-1)
			return true;
		else if(pattern[j] == original[i]) {
			j++;
			i++;
		} else {
			if(j != 0)
				j = arr[j-1];
			else
				i++;
		}
	}
	return true;
}
/*
int main() {
	string original = "heyhello";
	string pattern = "hell";
	cout << "result:" << kmp_search(original, pattern) << endl;
	return 0;
}*/
