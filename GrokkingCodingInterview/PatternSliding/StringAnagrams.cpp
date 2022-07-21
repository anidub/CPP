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
/*https://www.educative.io/courses/grokking-the-coding-interview/YQ8N2OZq0VM
 * Given a string and a pattern, find all anagrams of the pattern in the given string.

Every anagram is a permutation of a string. As we know, when we are not allowed to repeat characters while finding permutations of a string, we get N!
 permutations (or anagrams) of a string having N characters. For example, here are the six anagrams of the string “abc”:

abc
acb
bac
bca
cab
cba
Write a function to return a list of starting indices of the anagrams of the pattern in the given string.
Input: String="abbcabc", Pattern="abc"
Output: [2, 3, 4]
Explanation: The three anagrams of the pattern in the given string are "bca", "cab", and "abc".
 */
//TC: O(N+M), O(M)
vector<int> findStringAnagrams(const string &str, const string &pattern) {
	unordered_map<char, int> charFreq;
	int windowStart = 0, matched = 0;
	vector<int> resultIndices;
	for(auto &c : pattern) {
		charFreq[c]++;
	}

	for(int windowEnd = 0; windowEnd < str.length(); windowEnd++) {
		char rightChar = str[windowEnd];
		if(charFreq.find(rightChar) != charFreq.end()) {
			charFreq[rightChar]--;
			if(charFreq[rightChar] == 0) matched++;
		}
		if(matched == charFreq.size()) resultIndices.push_back(windowStart);

		if(windowEnd >= pattern.length() - 1) {
			char leftChar = str[windowStart++];
			if(charFreq.find(windowStart) != charFreq.end()) {
				if(charFreq[leftChar] == 0) matched--;
				charFreq[leftChar]++;
			}
		}
	}
	return resultIndices;
}
/*
int main() {
	  auto result = findStringAnagrams("ppqp", "pq");
	  for (auto num : result) {
	    cout << num << " ";
	  }
	  cout << endl;

	  result = findStringAnagrams("abbcabc", "abc");
	  for (auto num : result) {
	    cout << num << " ";
	  }
	  cout << endl;
}*/
