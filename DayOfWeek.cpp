#include <iostream>
#include <vector>

using namespace std;
/*
 * https://leetcode.com/problems/day-of-the-week/
 * Given a date, return the corresponding day of the week for that date.

The input is given as three integers representing the day, month and year respectively.

Return the answer as one of the following values {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"}.
Example 1:

Input: day = 31, month = 8, year = 2019
Output: "Saturday"
https://leetcode.com/problems/day-of-the-week/discuss/380845/c%2B%2B-solution-beat-100
https://leetcode.com/problems/day-of-the-week/discuss/812246/C%2B%2B-Runtime-100-easy-understanding

O(1) Time O(1) Space
 */

bool isLeap(int year){
	if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) return true;
	return false;
}

string dayOfWeek(int day, int month, int year) {
	string days[] = {"Thursday", "Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday"};
	int months[] = {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 304, 334};
	int counter = 0;
	for(int i = 1971; i < year; i++) {
		counter += isLeap(i) ? 366 : 365;
	}

	counter += months[month] + day + ( month > 2 && isLeap(year) ? 1 : 0);
	return days[counter % 7];
}
/*

int main() {
	cout << dayOfWeek(31, 8, 2019);
	return 0;
}*/
