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
/*https://leetcode.com/problems/alert-using-same-key-card-three-or-more-times-in-a-one-hour-period/
 * LeetCode company workers use key-cards to unlock office doors. Each time a worker uses their key-card, the security system saves the worker's name and the time when it was used. The system emits an alert if any worker uses the key-card three or more times in a one-hour period.

You are given a list of strings keyName and keyTime where [keyName[i], keyTime[i]] corresponds to a person's name and the time when their key-card was used in a single day.

Access times are given in the 24-hour time format "HH:MM", such as "23:51" and "09:49".

Return a list of unique worker names who received an alert for frequent keycard use. Sort the names in ascending order alphabetically.

Notice that "10:00" - "11:00" is considered to be within a one-hour period, while "22:51" - "23:52" is not considered to be within a one-hour period.
Input: keyName = ["daniel","daniel","daniel","luis","luis","luis","luis"], keyTime = ["10:00","10:40","11:00","09:00","11:00","13:00","15:00"]
Output: ["daniel"]
Explanation: "daniel" used the keycard 3 times in a one-hour period ("10:00","10:40", "11:00").

https://leetcode.com/problems/alert-using-same-key-card-three-or-more-times-in-a-one-hour-period/discuss/877041/C%2B%2B-Sorting : comments
Collect times for each person, sort them, and then use a sliding window to check for alarms.
 */
//TC : NLOGN, SC : O(N)
vector<string> alertNames(vector<string>& keyNames, vector<string>& keyTime) {
	if(keyNames.empty() || keyNames.size() != keyTime.size()) return {};
	vector<string> res;

	unordered_map<string, vector<int>> mp;
	for(int i = 0; i < keyNames.size(); i++) {
		mp[keyNames[i]].push_back(stoi(keyTime[i].substr(0,2) + keyTime[i].substr(3) ) );
	}

	for(auto &[key, v] : mp) {
		sort(v.begin(), v.end());
		for(int i = 2; i < v.size(); i++){
			if(v[i-2] >= v[i] - 100) {// Also '60' is not critical, we can use decimal stoi() directly.
				res.push_back(key);
				break;
			}
		}
	}
	sort(res.begin(), res.end());
	return res;
}
/*
int main() {
	vector<string> keyNames = {"daniel","daniel","daniel","luis","luis","luis","luis"};
	vector<string> keyTimes = {"10:00","10:40","11:00","09:00","11:00","13:00","15:00"};

	alertNames(keyNames, keyTimes);
	return 0;
}*/
