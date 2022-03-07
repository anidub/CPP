#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <utility>
#include <set>
#include <queue>

using namespace std;
/*
 * https://leetcode.com/problems/maximum-score-words-formed-by-letters/
 * Given a list of words, list of  single letters (might be repeating) and score of every character.
Return the maximum score of any valid set of words formed by using the given letters (words[i] cannot be used two or more times).
It is not necessary to use all characters in letters and each letter can only be used once. Score of letters 'a', 'b', 'c', ... ,'z' is given by score[0], score[1], ... , score[25] respectively.
Example 1:

Input: words = ["dog","cat","dad","good"], letters = ["a","a","c","d","d","d","g","o","o"], score = [1,0,9,5,0,0,3,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0]
Output: 23
Explanation:
Score  a=1, c=9, d=5, g=3, o=2
Given letters, we can form the words "dad" (5+1+5) and "good" (3+2+2+5) with a score of 23.
Words "dad" and "dog" only get a score of 21.
https://leetcode.com/problems/maximum-score-words-formed-by-letters/discuss/425264/C%2B%2B-straightforward-backtracking
 */
int result = 0;

void backtrack(vector<string>& words, vector<int> score, vector<int>& count, vector<int>& used, int pos, int reward) {
	for(int i = 0; i < 26; i++) {
		if(used[i] > count[i])
			return;
	}
	result = max(result, reward);
	for(int i = pos; i < words.size(); i++) {
		for(auto& c : words[i]) {
			used[c - 'a']++;
			reward += score[c - 'a'];
		}
		backtrack(words, score, count, used, i+1, reward);

		for(auto& c : words[i]) {
			used[c - 'a']--;
			reward -= score[c - 'a'];
		}
	}
}
//O(m*2^n), where n is number of words, and m is the length of one word
int  maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
	vector<int> used(26, 0), count(26, 0);
	for(auto& c : letters) {
		count[c - 'a']++;
	}
	backtrack(words, score, count, used, 0, 0);
	return result;
}

/*
int main() {
	vector<string> words; words.push_back("dog");words.push_back("cat");words.push_back("dad");words.push_back("good");
	vector<char> letters; letters.push_back('a');letters.push_back('a');letters.push_back('c');letters.push_back('d');letters.push_back('d');
	letters.push_back('d');letters.push_back('g');letters.push_back('o');letters.push_back('o');
	vector<int> score; score.push_back(1);score.push_back(0);score.push_back(9);score.push_back(5);score.push_back(0);score.push_back(0);
	score.push_back(3);score.push_back(0);score.push_back(0);score.push_back(0);score.push_back(0);score.push_back(0);score.push_back(0);
	score.push_back(0);score.push_back(2);score.push_back(0);score.push_back(0);score.push_back(0);score.push_back(0);
	score.push_back(0);score.push_back(0);score.push_back(0);score.push_back(0);score.push_back(0);score.push_back(0);score.push_back(0);

	cout << maxScoreWords(words, letters, score) << endl;

	return 0;
}*/
