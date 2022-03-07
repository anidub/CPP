#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <string>

using namespace std;
/*
 * https://leetcode.com/problems/positions-of-large-groups/
 * In a string s of lowercase letters, these letters form consecutive groups of the same character.

For example, a string like s = "abbxxxxzyy" has the groups "a", "bb", "xxxx", "z", and "yy".

A group is identified by an interval [start, end], where start and end denote the start and end indices (inclusive) of the group. In the above example, "xxxx" has the interval [3,6].

A group is considered large if it has 3 or more characters.

Return the intervals of every large group sorted in increasing order by start index.
Example 1:
Input: s = "abbxxxxzzy"
Output: [[3,6]]
Explanation: "xxxx" is the only large group with start index 3 and end index 6.
 */
vector<vector<int>> largeGroupPositions(string s) {
    vector<vector<int>> result;
    if(s.empty()) return  result;

    for(int i = 0; i < s.length(); i++) {
    	int end = i+1;
    	while(end < s.length() && s.at(end) == s.at(i)) {
    		end++;
    	}
    	int distance = end - i;
    	if(distance >= 3) {
    		vector<int> current;
    		current.push_back(i), current.push_back(end - 1);
    		result.push_back(current);
    	}
    	i = end-1;
    }
    return result;
}

/*
int main() {
	string s = "abbxxxxzzy";
	largeGroupPositions(s);
}*/
