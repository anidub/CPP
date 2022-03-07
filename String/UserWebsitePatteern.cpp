#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <vector>
#include <stack>
#include <utility>
#include <string.h>
#include <unordered_map>
#include <map>
#include <unordered_set>

using namespace std;
/*https://leetcode.com/problems/analyze-user-website-visit-pattern/
 *You are given two string arrays username and website and an integer array timestamp. All the given arrays are of the same length and the tuple [username[i], website[i], timestamp[i]] indicates that the user username[i] visited the website website[i] at time timestamp[i].

A pattern is a list of three websites (not necessarily distinct).

For example, ["home", "away", "love"], ["leetcode", "love", "leetcode"], and ["luffy", "luffy", "luffy"] are all patterns.
The score of a pattern is the number of users that visited all the websites in the pattern in the same order they appeared in the pattern.
 if the pattern is ["leetcode", "love", "leetcode"], the score is the number of users x such that x visited "leetcode" then visited "love" and visited "leetcode" one more time after that.
 Input: username = ["joe","joe","joe","james","james","james","james","mary","mary","mary"], timestamp = [1,2,3,4,5,6,7,8,9,10], website = ["home","about","career","home","cart","maps","home","home","about","career"]
Output: ["home","about","career"]
Explanation: The tuples in this example are:
["joe","home",1],["joe","about",2],["joe","career",3],["james","home",4],["james","cart",5],["james","maps",6],["james","home",7],["mary","home",8],["mary","about",9], and ["mary","career",10].
The pattern ("home", "about", "career") has score 2 (joe and mary).
The pattern ("home", "cart", "maps") has score 1 (james).
The pattern ("home", "cart", "home") has score 1 (james).
The pattern ("home", "maps", "home") has score 1 (james).
The pattern ("cart", "maps", "home") has score 1 (james).
The pattern ("home", "home", "home") has score 0 (no user visited home 3 times).

Soln:

 *Collect the user data (website and timestamp) into a map of maps
i.e user name string -> website string and time stamp integer

Collect 3-sequences for each user.
Reminder :
"A 3-sequence is a list of websites of length 3 sorted in ascending order by the time of their visits. "

Find and return the 3-sequence with the largest count.
 *https://leetcode.com/problems/analyze-user-website-visit-pattern/discuss/1166450/Accepted%3A-use-hash-maps-and-sets
 */
//O(N^4)
vector<string> mostVisitedPattern(vector<string>& users, vector<int>& time, vector<string>& sites) {
	if(users.empty()) return {};

	unordered_map<string, map<int, string>> userToDatas;// user name: <timestamp, website>
	unordered_map<string, int> threeSequencesCount; // count the time of visiting 3-sequence websites
	int maxCount = 0; string res;

	  // Step 1: collect user data in a map of maps Basically store website and time data for every user name, by user name
	for(int i = 0; i < users.size(); i++) {
		userToDatas[users[i]][time[i]] = sites[i];
	}

	 // Step 2: collect three sequences
	for(auto userToData : userToDatas) {
		unordered_set<string> threeSeq;
		// T :O(n^3)
		for(auto it = begin(userToData.second); it != end(userToData.second); it++) {
			for(auto it1 = next(it); it1 != end(userToData.second); it1++) {
				for(auto it2 = next(it1); it2 != end(userToData.second); it2++) {
					threeSeq.insert(it->second + '$' + it1->second + '#' + it2->second);
				}
			}
		}

		for(auto threeSq : threeSeq) {
			threeSequencesCount[threeSq]++;
		}
	}

	for(auto threeSeq : threeSequencesCount) {
		if(threeSeq.second >= maxCount) {// If there is more than one solution, return the lexicographically smallest such 3-sequence.
			res = threeSeq.second > maxCount ? threeSeq.first : min(res, threeSeq.first);
			maxCount = threeSeq.second;
		}
	}
	auto seperator1 = res.find('$');
	auto seperator2 = res.find('#');

	return { res.substr(0, seperator1),// element 1
			res.substr(seperator1 + 1, seperator2 - seperator1 - 1),// element 2
			res.substr(seperator2 + 1) 	};// element 3
}

/*
int main() {
	vector<string>username = {"ua","ua","ua","ub","ub","ub"};
	vector<int> timestamp = {1,2,3,4,5,6};
	vector<string> website = {"a","b","a","a","b","c"};

	mostVisitedPattern(username, timestamp, website);

	return 0;
}*/
