#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <unordered_map>

using namespace std;
/*
 * https://leetcode.com/problems/can-make-palindrome-from-substring/
 * Given a string s, we make queries on substrings of s.

For each query queries[i] = [left, right, k], we may rearrange the substring s[left], ..., s[right], and then choose up to k of them to replace with any lowercase English letter.

If the substring is possible to be a palindrome string after the operations above, the result of the query is true. Otherwise, the result is false.
Input: s = "abcda", queries = [[3,3,0],[1,2,0],[0,3,1],[0,3,2],[0,4,1]]
Output: [true,false,false,true,true]
Explanation:
queries[0] : substring = "d", is palidrome.
queries[1] : substring = "bc", is not palidrome.
queries[2] : substring = "abcd", is not palidrome after replacing only 1 character.
queries[3] : substring = "abcd", could be changed to "abba" which is palidrome. Also this can be changed to "baab" first rearrange it "bacd" then replace "cd" with "ab".
queries[4] : substring = "abcda", could be changed to "abcba" which is palidrome.

 */

// O(26*N)
vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
	if(queries.empty())  return {};
	vector<vector<int>> maps;
	vector<int> map(26, 0);

	maps.push_back(map);
	for(char c : s) {
		map[c - 'a']++;
		maps.push_back(map);
	}
	vector<bool> result;
	for(auto& q : queries) {
		int high = q[1];
		int low = q[0];
		int k = q[2];

		int oddcount = 0;
		int diff = 0;

		for(int i = 0; i < 26; i++) {
			diff = maps[high+1][i] - maps[low][i];
			oddcount += diff % 2;
		}

		result.push_back(oddcount/2 <= k);
	}
	return result;
}
/*
int main() {
	vector<vector<int>> queries;
	vector<int> q1; q1.push_back(3);q1.push_back(3);q1.push_back(0);
	vector<int> q2; q2.push_back(1);q2.push_back(2);q2.push_back(0);
	vector<int> q3; q3.push_back(0);q3.push_back(3);q3.push_back(1);
	vector<int> q4; q4.push_back(0);q4.push_back(3);q4.push_back(2);
	vector<int> q5; q5.push_back(0);q5.push_back(4);q5.push_back(1);
	canMakePaliQueries("abcde", queries);
	return 0;
}*/
