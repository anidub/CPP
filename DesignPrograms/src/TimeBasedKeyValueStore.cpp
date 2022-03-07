#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <map>
#include <vector>
#include <stack>
#include <utility>
#include <list>
#include <iterator>
#include <unordered_map>

using namespace std;
/*https://leetcode.com/problems/time-based-key-value-store/
 * Design a time-based key-value data structure that can store multiple values for the same key at different time stamps and retrieve the key's value at a certain timestamp.

Implement the TimeMap class:

TimeMap() Initializes the object of the data structure.
void set(String key, String value, int timestamp) Stores the key key with the value value at the given time timestamp.
String get(String key, int timestamp) Returns a value such that set was called previously, with timestamp_prev <= timestamp. If there are multiple such values, it returns the value associated with the largest timestamp_prev. If there are no values, it returns "".
Input
["TimeMap", "set", "get", "get", "set", "get", "get"]
[[], ["foo", "bar", 1], ["foo", 1], ["foo", 3], ["foo", "bar2", 4], ["foo", 4], ["foo", 5]]
Output
[null, null, "bar", "bar", null, "bar2", "bar2"]

Explanation
TimeMap timeMap = new TimeMap();
timeMap.set("foo", "bar", 1);  // store the key "foo" and value "bar" along with timestamp = 1.
timeMap.get("foo", 1);         // return "bar"
timeMap.get("foo", 3);         // return "bar", since there is no value corresponding to foo at timestamp 3 and timestamp 2, then the only value is at timestamp 1 is "bar".
timeMap.set("foo", "bar2", 4); // store the key "foo" and value "bar2" along with timestamp = 4.
timeMap.get("foo", 4);         // return "bar2"
timeMap.get("foo", 5);         // return "bar2"

https://leetcode.com/problems/time-based-key-value-store/discuss/299520/C%2B%2B-unordered_map-%2B-Binary-Search(last-occurrence) and comments

 */
class TimeMap {
	unordered_map<string, vector<pair<int, string>>> m;
public:
	TimeMap() {

	}
	//TC: O(1), Space Complexity: O(n)
	void set(string key, string value, int timestamp) {
		m[key].push_back({timestamp, value});
	}

	//TC: O(LogN)
	string get(string key, int timestamp) {
		if(!m.count(key)) return "";

		auto& vec = m[key];
		int start = 0, end = vec.size() - 1;

		while(start <= end) {
			int mid = start + (end - start)/2;
			if(vec[mid].first == timestamp) return vec[mid].second; // exact time match found, return string (Val)

			if(vec[mid].first > timestamp)
				end = mid - 1;
			else
				start = mid + 1;
		}
		if(end >= 0) return vec[end].second; /// since we want time less than  key (time) so end is moving left
		return "";
	}
};
/*
int main() {
	 TimeMap* obj = new TimeMap();
	 obj->set("foo", "bar", 1);
	 string param_2 = obj->get("foo", 1);
	 cout << param_2 << endl;

	 delete obj;
	return 0;
}*/
