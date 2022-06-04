#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <vector>
#include <utility>
#include <unordered_map>

using namespace std;
/*https://www.educative.io/courses/grokking-the-coding-interview/m2E4y26k3LE
 * Rearrange String K Distance Apart (hard) #
Given a string and a number ‘K’, find if the string can be rearranged such that the same characters are at least ‘K’ distance apart from each other.
Input: "mmpp", K=2
Output: "mpmp" or "pmpm"
Explanation: All same characters are 2 distance apart.
 */
class RearrangeStringKDistanceApart {
public:
	struct ValueCompare {
		bool operator()(const pair<char, int> &a, const pair<char, int> &b) {
			return a.second < b.second;
		}
	};

	//TC:O(NLOGN), SC:o(N)
	string reorganizeStringKdistanceApart(const string &str, int k) {
		if(k <= 1) return str;
		string result;

		unordered_map<char, int> count;
		for(char c : str) {
			count[c]++;
		}

		priority_queue< pair<int, int>, vector<pair<char, int>>, ValueCompare> maxHeap;
		for(auto entry : count) {
			maxHeap.push(entry);
		}
		queue<pair<char, int>> queue;

		while(!maxHeap.empty()) {
			auto current = maxHeap.top(); maxHeap.pop();
			result += current.first;
			current.second--;
			queue.push(current);
			if(queue.size() == k) {
				auto entry = queue.front();
				queue.pop();
				if(entry.second > 0)
					maxHeap.push(entry);
			}
		}
		return result.size() == str.size() ? result : "";
	}
};
/*
int main(int argc, char *argv[]) {
	RearrangeStringKDistanceApart rskda;
  cout << "Reorganized string: "
       << rskda.reorganizeStringKdistanceApart("Programming", 3) << endl;
  cout << "Reorganized string: "
       << rskda.reorganizeStringKdistanceApart("mmpp", 2) << endl;
  cout << "Reorganized string: "
       << rskda.reorganizeStringKdistanceApart("aab", 2) << endl;
  cout << "Reorganized string: " << rskda.reorganizeStringKdistanceApart("aappa", 3)
       << endl;
}
*/
