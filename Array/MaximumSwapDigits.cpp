#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <queue>
#include <unordered_map>

using namespace std;
/*
 * https://leetcode.com/problems/maximum-swap/
 * you are given an integer num. You can swap two digits at most once to get the maximum valued number.
Return the maximum valued number you can get.
Example 1:

Input: num = 2736
Output: 7236
Explanation: Swap the number 2 and the number 7.
https://leetcode.com/problems/maximum-swap/discuss/107138/C%2B%2B-concise-code-O(N-8)
 */
void print1(vector<int>& nums) {
    cout << endl;
    for(int& i : nums)
        cout << i << " ";
    cout << endl;
}

int maximumSwapDigits(int num) {
	string s = to_string(num);
	int n = s.size();
	if(n == 1) return num;
	vector<int> pos(n, n-1);
	print1(pos);

	// the index of maximum digit in range [i, n)
	for(int i = n-2; i >= 0; i--) {
		pos[i] = s[i] > s[pos[i+1]] ? i : pos[i+1];
	}
	print1(pos);
	int i = 0;
	// find the first index whose digit is not maximum, and swap it
	while(i < n && s[i] > s[pos[i]])
		i++;

	if(i < n)
		//swap(s[i], s[pos[i]]); works
	return stoi(s);
}
/*
int main() {
	cout << maximumSwapDigits(2736) << endl;
	return 0;
}*/
