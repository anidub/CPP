#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <utility>

using namespace std;
/*https://www.educative.io/courses/grokking-the-coding-interview/R8AJWOMxw2q
 *There is a dictionary containing words from an alien language for which we don’t know the ordering of the letters.
 *Write a method to find the correct order of the letters in the alien language.
 * It is given that the input is a valid dictionary and there exists an ordering among its letters.
 *Input: Words: ["ba", "bc", "ac", "cab"]
Output: bac
Explanation: Given that the words are sorted lexicographically by the rules of the alien language, so
from the given words we can conclude the following ordering among its characters:

1. From "ba" and "bc", we can conclude that 'a' comes before 'c'.
2. From "bc" and "ac", we can conclude that 'b' comes before 'a'

From the above two points, we can conclude that the correct character order is: "bac"

Take Example-1 above: [“ba”, “bc”, “ac”, “cab”]

Take the first two words “ba” and “bc”. Starting from the beginning of the words, find the first character
that is different in both words: it would be ‘a’ from “ba” and ‘c’ from “bc”. Because of the sorted order of
words (i.e. the dictionary!), we can conclude that ‘a’ comes before ‘c’ in the alien language.
Similarly, from “bc” and “ac”, we can conclude that ‘b’ comes before ‘a’.
 */
class AlienDictionary{
public:
	//TC: O(V + N), SC:O(V + N), V : total number of diff chars, N = number of words
	string findOrder(const vector<string> &words) {
		if(words.empty()) return "";

		unordered_map<char, int> inDegree;
		unordered_map<char, vector<char>> graph;

		for(auto word : words) {
			for(char character : word) {
				inDegree[character] = 0;
				graph[character] = vector<char>();
			}
		}

		for(int i = 0; i < words.size() - 1; i++) {
			string w1 = words[i], w2 = words[i + 1];// find ordering of characters from adjacent words
			for(int j = 0; j < min(w1.length(), w2.length()); j++) {
				char parent = w1[j], child = w2[j];
				if(parent != child) {// if the two characters are different
					graph[parent].push_back(child); // put the child into it's parent's list
					inDegree[child]++;// increment child's inDegree
					break;// only the first different character between the two words will help us find the order
				}
			}
		}

		queue<char> sources;
		for(auto entry : inDegree) {
			if(entry.second == 0)
				sources.push(entry.first);
		}


	    // d. For each source, add it to the sortedOrder and subtract one from all of its children's
	    // in-degrees if a child's in-degree becomes zero, add it to the sources queue
		string sortedOrder;
		while(!sources.empty()) {
			char vertex = sources.front(); sources.pop();
			sortedOrder += vertex;
			vector<char> children = graph[vertex];
			for(auto child : children) {
				inDegree[child]--;
				if(inDegree[child] == 0)
					sources.push(child);
			}
		}

		if(sortedOrder.length() != inDegree.size())
			 return "";
		return sortedOrder;
	}
};

/*
int main(int argc, char *argv[]) {
	AlienDictionary ad;
  string result = ad.findOrder(vector<string>{"ba", "bc", "ac", "cab"});
  cout << "Character order: " << result << endl;

  result = ad.findOrder(vector<string>{"cab", "aaa", "aab"});
  cout << "Character order: " << result << endl;

  result = ad.findOrder(vector<string>{"ywx", "wz", "xww", "xz", "zyy", "zwz"});
  cout << "Character order: " << result << endl;
}
*/
