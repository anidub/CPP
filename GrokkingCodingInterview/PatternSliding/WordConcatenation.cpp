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
/*https://www.educative.io/courses/grokking-the-coding-interview/Y5YDWzqPn7O
 *Given a string and a list of words, find all the starting indices of substrings in the given string that are a concatenation of
 *all the given words exactly once without any overlapping of words. It is given that all words are of the same length.
 Input: String="catcatfoxfox", Words=["cat", "fox"]
Output: [3]
Explanation: The only substring containing both the words is "catfox".

 */
//TC: O(N * M * Len), SC: O(M)
vector<int> findWordConcatenation(const string &str, const vector<string> &words) {
	unordered_map<string, int> wordMap;
	for(auto &s : words) {
		wordMap[s]++;
	}
	vector<int> result;

	int wordLen = words[0].size(), wordCount = words.size();

	for(int i = 0; i <= int(str.length()) - wordLen * wordCount; i++) {
		unordered_map<string, int> wordSeen;

		for(int j = 0; j < wordCount; j++) {
			int nextWordIndex = i + j * wordLen;
			string word = str.substr(nextWordIndex, wordLen);
			if(wordMap.find(word) == wordMap.end()) break;// break if we don't need this word
			wordSeen[word]++;
			if(wordSeen[word] > wordMap[word]) break;// no need to process further if the word has higher frequency than required

			if(j + 1 == wordCount) result.push_back(i); // store index if we have found all the words
		}
	}
	return result;
}

/*
int main() {
	  vector<int> result = findWordConcatenation("catfoxcat", vector<string>{"cat", "fox"});
	  for (auto num : result) {
	    cout << num << " ";
	  }
	  cout << endl;

	  result = findWordConcatenation("catcatfoxfox", vector<string>{"cat", "fox"});
	  for (auto num : result) {
	    cout << num << " ";
	  }
	  cout << endl;
}*/

