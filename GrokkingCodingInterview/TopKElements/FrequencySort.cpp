#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <vector>
#include <utility>
#include <unordered_map>

using namespace std;
/*https://www.educative.io/courses/grokking-the-coding-interview/gxZz615BPPG
 * Given a string, sort it based on the decreasing frequency of its characters.
 * Input: "Programming"
Output: "rrggmmPiano"
Explanation: 'r', 'g', and 'm' appeared twice, so they need to appear before any other character.

 */
class FrequencySort {
public:
	struct valueCompare {
		bool operator()(const pair<char, int> &x, const pair<char, int> &y) {
			return x.second < y.second;
		}
	};

	//TC:O(NLOGN), SC:O(N)
	string sortCharacterByFrequency(const string &str) {
		unordered_map<char, int> charFreqMap;
		for(char c : str)
			charFreqMap[c]++;

		priority_queue<pair<char, int>, vector<pair<char, int>>, valueCompare > max_heap;

		for(auto entry : charFreqMap)
			max_heap.push(entry);

		string sortedString = "";
		while(!max_heap.empty()) {
			auto entry = max_heap.top(); max_heap.pop();
			for(int i = 0; i < entry.second; i++)
				sortedString += entry.first;
		}
		return sortedString;
	}
};

/*
int main(int argc, char *argv[]) {
	FrequencySort fs;
  string result = fs.sortCharacterByFrequency("Programming");
  cout << "Here is the given string after sorting characters by frequency: " << result << endl;

  result = fs.sortCharacterByFrequency("abcbab");
  cout << "Here is the given string after sorting characters by frequency: " << result << endl;
}
*/
