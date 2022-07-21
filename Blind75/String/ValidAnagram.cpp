#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/valid-anagram/
 * Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase,
 typically using all the original letters exactly once.
 Input: s = "anagram", t = "nagaram"
Output: true

 */
class ValidAnagram {
public:
	//TC:O(N), SC:O(M) where M is total types of chars supported like 26 if lowercase, 52 if both lower and upper
    bool isAnagram(string s, string t) {
    	if(s.length() != t.length()) return false;
    	unordered_map<char, int> letters;

    	for(char &c : s) letters[c]++;

    	for(int i = 0; i < t.length(); i++) {
    		char c = t[i];
    		if(letters.find(c) == letters.end()) return false;

    		letters[c]--;
    		if(letters[c] == 0) letters.erase(c);
    	}

    	return letters.size() > 0 ? false : true;
    }
};
/*
int main() {
	ValidAnagram va;
	cout << va.isAnagram("anagram", "nagaram") << endl;
}*/
