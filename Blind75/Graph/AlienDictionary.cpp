#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/alien-dictionary/
 * There is a new alien language that uses the English alphabet. However, the order among the letters is unknown to you.

You are given a list of strings words from the alien language's dictionary, where the strings in words are sorted
 lexicographically by the rules of this new language.

Return a string of the unique letters in the new alien language sorted in lexicographically increasing order by the new language's rules.
 If there is no solution, return "". If there are multiple solutions, return any of them.

A string s is lexicographically smaller than a string t if at the first letter where they differ, the letter
in s comes before the letter in t in the alien language. If the first min(s.length, t.length) letters are the same,
 then s is smaller if and only if s.length < t.length.

 https://www.educative.io/courses/grokking-the-coding-interview/R8AJWOMxw2q
 */
class AlienDictionary {
public:
	string alienOrder(const vector<string>& words) {
		if(words.empty()) return "";
		string sortedOrder;

		unordered_map<char, int> inDegree;
		unordered_map<char, vector<char>> graph;

		for(string word : words) {
			for(char character : word) {
				inDegree[character] = 0;
				graph[character] = vector<char>();
			}
		}

		for(int i = 0; i < words.size() - 1; i++) {
			string w1 = words[i], w2 = words[i + 1];
			for(int j = 0; j < min(w1.length(), w2.length()); j++) {
				char parent = w1[j], child = w2[j];
				if(parent != child) {
					graph[parent].push_back(child);
					inDegree[child]++;
					break;
				}
			}
		}

		queue<char> queue;
		for(auto entry : inDegree) {
			if(entry.second == 0)
				queue.push(entry.first);
		}

		while(!queue.empty()) {
			char vertex = queue.front(); queue.pop();
			sortedOrder.push_back(vertex);
			vector<char> children = graph[vertex];
			for(char child : children) {
				inDegree[child]--;
				if(inDegree[child] == 0)
					queue.push(child);
			}
		}

		return sortedOrder.size() == inDegree.size() ? sortedOrder : "";
	}
};

/*
int main() {
	AlienDictionary ad;
  string result = ad.alienOrder(vector<string>{"ba", "bc", "ac", "cab"});
  cout << "Character order: " << result << endl;

  result = ad.alienOrder(vector<string>{"cab", "aaa", "aab"});
  cout << "Character order: " << result << endl;

  result = ad.alienOrder(vector<string>{"ywx", "wz", "xww", "xz", "zyy", "zwz"});
  cout << "Character order: " << result << endl;
}
*/
