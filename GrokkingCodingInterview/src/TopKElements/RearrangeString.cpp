#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <vector>
#include <utility>
#include <unordered_map>

using namespace std;
/*https://www.educative.io/courses/grokking-the-coding-interview/xV7wx4o8ymB
 * Given a string, find if its letters can be rearranged in such a way that no two same characters come next to each other.
 * Input: "aappp"
Output: "papap"
Explanation: In "papap", none of the repeating characters come next to each other.

https://leetcode.com/problems/reorganize-string/
 */

class RearrangeString {
 public:
	struct ValueCompare {
		bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
			return a.second < b.second;
		}
	};
	//TC:O(NLOGN) SC:O(N)
  string rearrangeString(const string &str) {
	  unordered_map<char, int> charFreq;
	  for(char c : str)
		  charFreq[c]++;

	  priority_queue<pair<char, int>, vector<pair<char, int>>, ValueCompare> max_heap;

	  for(auto entry : charFreq)
		  max_heap.push(entry);

	  pair<char, int> previous(-1, -1);
	  string result = "";

	  while(!max_heap.empty()) {
		  auto current = max_heap.top(); max_heap.pop();
		  if(previous.second > 0)
			  max_heap.push(previous);

		  result += current.first;
		  current.second--;
		  previous = current;
	  }
	  return result.size() == str.size() ? result : "";

    return "";
  }

  //TC:O(N) SC:O(N) leetcode https://leetcode.com/problems/reorganize-string/ increase 26 to more for upper case
  string rearrangeStringOptimal(string &str) {
	  if(str.empty()) return str;
	  vector<int> count(26);
	  int mostFreqChar = 0, i = 0;

	  for(char c : str) {
		  count[c - 'a']++;
		  if(count[c - 'a'] > count[mostFreqChar])
			  mostFreqChar = (c - 'a');
	  }
	  if(2 * count[mostFreqChar] - 1 > str.size()) return "";

	  while(count[mostFreqChar]) {
		  str[i] = ('a' + mostFreqChar);
		  count[mostFreqChar]--;
		  i += 2;
	  }

	  for(int j = 0; j < 26; j++) {
		  while(count[j]) {
			  if(i >= str.size())
				  i = 1;
			  str[i] = ('a' + j);
			  count[j]--;
			  i += 2;
		  }
	  }
	  return str;
  }
};
/*
int main(int argc, char *argv[]) {
	RearrangeString rs;
	cout << "Rearranged string: " << rs.rearrangeString("aappp") << endl;
	cout << "Rearranged string: " << rs.rearrangeString("Programming") << endl;
	string s = "Programming";
	cout << "Rearranged string: " << rs.rearrangeStringOptimal(s) << endl;

	cout << "Rearranged string: " << rs.rearrangeString("aapa") << endl;
}
*/
