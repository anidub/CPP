#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <vector>
#include <stack>
#include <utility>
#include <string.h>
#include <unordered_map>
#include <queue>

using namespace std;
/*https://leetcode.com/problems/reformat-date/
 * Given a date string in the form Day Month Year, where:

Day is in the set {"1st", "2nd", "3rd", "4th", ..., "30th", "31st"}.
Month is in the set {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"}.
Year is in the range [1900, 2100].
Convert the date string to the format YYYY-MM-DD, where:

YYYY denotes the 4 digit year.
MM denotes the 2 digit month.
DD denotes the 2 digit day.
Example 1:
Input: date = "20th Oct 2052"
Output: "2052-10-20"

https://leetcode.com/problems/reformat-date/discuss/765893/c%2B%2B-faster-than-100
 */
unordered_map<string, string> monthMap = {
		{"Jan", "01"},
        {"Feb", "02"},
        {"Mar","03"},
        {"Apr","04"},
        {"May", "05"},
        {"Jun", "06"},
        {"Jul", "07"},
        {"Aug", "08"},
        {"Sep", "09"},
        {"Oct", "10"},
        {"Nov", "11"},
        {"Dec", "12"}
};

//TC : O(1) SC: O(1)
string reformatDate(string date) {
	string output = "";
	if(isdigit(date[1])) {
		output = date.substr(9) + "-";
		output = output + monthMap[date.substr(5,3)] + "-";
		output += date.substr(0,2);
	} else {
		output = date.substr(8) + "-";
		output = output + monthMap[date.substr(4,3)] + "-";
		output = output + '0' + date[0];
	}
	return output;
}
/*
int main() {
	cout << reformatDate("20th Oct 2052") << endl;
	return 0;
}*/
