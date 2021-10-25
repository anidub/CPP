#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <unordered_map>
#include <map>

using namespace std;
/*https://github.com/ScientificKnights/Leetcode-Templates-and-Examples/blob/master/code/1152.%20Analyze%20User%20Website%20Visit%20Pattern.h
 * 1152. Analyze User Website Visit Pattern
 * You are given three arrays username, timestamp and website of the same length N where the ith tuple means that the user
with name username[i] visited the website website[i] at time timestamp[i].
A 3-sequence is a list of not necessarily different websites of length 3 sorted in ascending order by the time of their visits.
Find the 3-sequence visited at least once by the largest number of users. If there is more than one solution,
return the lexicographically minimum solution.
A 3-sequence X is lexicographically smaller than a 3-sequence Y if X[0] < Y[0] or X[0] == Y[0]
and (X[1] < Y[1] or X[1] == Y[1] and X[2] < Y[2]).
It is guaranteed that there is at least one user who visited at least 3 websites. No user visits two websites at the same time.
Input: username = ["joe","joe","joe","james","james","james","james","mary","mary","mary"], timestamp = [1,2,3,4,5,6,7,8,9,10],
website = ["home","about","career","home","cart","maps","home","home","about","career"]
Output: ["home","about","career"]
Explanation:
The tuples in this example are:
["joe", 1, "home"]
["joe", 2, "about"]
["joe", 3, "career"]
["james", 4, "home"]
["james", 5, "cart"]
["james", 6, "maps"]
["james", 7, "home"]
["mary", 8, "home"]
["mary", 9, "about"]
["mary", 10, "career"]
The 3-sequence ("home", "about", "career") was visited at least once by 2 users.
The 3-sequence ("home", "cart", "maps") was visited at least once by 1 user.
The 3-sequence ("home", "cart", "home") was visited at least once by 1 user.
The 3-sequence ("home", "maps", "home") was visited at least once by 1 user.
The 3-sequence ("cart", "maps", "home") was visited at least once by 1 user.

Note:
3 <= N = username.length = timestamp.length = website.length <= 50
1 <= username[i].length <= 10
0 <= timestamp[i] <= 10^9
1 <= website[i].length <= 10
Both username[i] and website[i] contain only lowercase characters.
 */
/// Time Complexity: O(n^3)
/// Space Complexity: O(n^3)
vector<string> mostVisitedWebsitePattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
	int n = username.size();
	unordered_map<string, map<int, string>> data;
	for(int i = 0; i < n; i++) {
		data[username[i]][timestamp[i]] = website[i];
	}

	map<vector<string>, unordered_map<string, int>> result;

	for(auto m : data) {
		if(m.second.size() < 3) continue;
		for(auto i = m.second.begin(); i != m.second.end(); i++) {
			auto j = i; j++;
			for(; j != m.second.end(); j++) {
				auto k = j; k++;
				for(; k != m.second.end(); k++) {
					cout << endl;
					cout << m.first << ": " << (*i).second << " " << (*j).second << " " << (*k).second;
					result[{(*i).second, (*j).second, (*k).second}][m.first]++;
					cout << endl;
				}
			}
		}
	}

	vector<string> ans;
	int max = 0;
	for(auto& i : result) {
		if(i.second.size() > max) {
			ans = i.first;
			max = i.second.size();
		}
	}
    for(auto& v: ans) {
        cout << v << " ";
    }
	return ans;
}

/*
int main() {
    //username = ["joe","joe","joe","james","james","james","james","mary","mary","mary"]
    vector<string> username; username.push_back("joe");username.push_back("joe");username.push_back("joe");
    username.push_back("james");username.push_back("james");username.push_back("james");username.push_back("james");
    username.push_back("mary");username.push_back("mary");username.push_back("mary");
    //timestamp = [1,2,3,4,5,6,7,8,9,10]
    vector<int> timestamp; timestamp.push_back(2);timestamp.push_back(3);timestamp.push_back(4);
    timestamp.push_back(5);timestamp.push_back(6);timestamp.push_back(7);timestamp.push_back(8);
    timestamp.push_back(9);timestamp.push_back(10);
    //website = ["home","about","career","home","cart","maps","home","home","about","career"]
    vector<string> website; website.push_back("home");website.push_back("about");website.push_back("career");
    website.push_back("home");website.push_back("cart");website.push_back("maps");website.push_back("home");
    website.push_back("home");website.push_back("about");website.push_back("career");

    mostVisitedWebsitePattern(username, timestamp, website);

	return 0;
}*/
