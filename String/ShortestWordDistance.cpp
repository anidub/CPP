#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <vector>
#include <stack>
#include <utility>
#include <string.h>
#include <unordered_map>

using namespace std;
/*https://leetcode.com/problems/shortest-word-distance-ii/
 * Design a data structure that will be initialized with a string array, and then it should answer queries of the shortest distance between two different strings from the array.

Implement the WordDistance class:

WordDistance(String[] wordsDict) initializes the object with the strings array wordsDict.
int shortest(String word1, String word2) returns the shortest distance between word1 and word2 in the array wordsDict.
https://leetcode.com/problems/shortest-word-distance-ii/discuss/67066/9-line-O(n)-C%2B%2B-Solution
 */
class WordDistance {
private:
	unordered_map<string, vector<int>> wordMap;
public:
	WordDistance(vector<string>& words) { //O(N)
		for(int i = 0; i < words.size(); i++)
			wordMap[words[i]].push_back(i);
	}

	int shortest(string word1, string word2) {// O(n)
		int i = 0, j = 0, dist = INT_MAX;
		while(i < wordMap[word1].size() && j < wordMap[word2].size()) {
			dist = min(dist, abs(wordMap[word1][i] - wordMap[word2][j]));
			wordMap[word1][i] < wordMap[word2][j] ? i++ : j++;
		}
		return dist;
	}
};
/*
int main() {
	vector<string> wordsDict = {"practice", "makes", "perfect", "coding", "makes","makes", "coding" };
	 WordDistance* obj = new WordDistance(wordsDict);
	 cout << obj->shortest("coding","practice") << endl;
	 delete obj;
	return 0;
}*/
