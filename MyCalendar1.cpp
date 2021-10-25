#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <map>

using namespace std;
/*
 *https://leetcode.com/problems/my-calendar-i
 *Implement a MyCalendar class to store your events. A new event can be added if adding the event will not cause a double booking.
Your class will have the method, book(int start, int end). Formally, this represents a booking on the half open interval [start, end), the range of real numbers x such that start <= x < end.
A double booking happens when two events have some non-empty intersection (ie., there is some time that is common to both events.)
For each call to the method MyCalendar.book, return true if the event can be added to the calendar successfully without causing a double booking. Otherwise, return false and do not add the event to the calendar.
Your class will be called like this: MyCalendar cal = new MyCalendar(); MyCalendar.book(start, end)
Example 1:

MyCalendar();
MyCalendar.book(10, 20); // returns true
MyCalendar.book(15, 25); // returns false
MyCalendar.book(20, 30); // returns true
Explanation:
The first event can be booked.  The second can't because time 15 is already booked by another event.
The third event can be booked, as the first event takes every time less than 20, but not including 20.
https://leetcode.com/problems/my-calendar-i/discuss/109475/JavaC%2B%2B-Clean-Code-with-Explanation
 *
 */

class MyCalendar {
private:
	map<int, int> map;

public:
    MyCalendar() {

    }
	bool book(int start, int end) {// O(logN): since its map
		auto next = map.lower_bound(start);
		cout << "next first:" << next->first << " next->second:" << next->second << endl;

		if(next != map.end() && next->first < end) {
			return false;
		}

		if(next != map.begin()) {
			--next;
            cout << "next->second:" << next->second << endl;
            cout << "return false second" << endl;
			if(start < next->second)
				return false;
		}
		map[start] = end;
		return true;
	}
};
/*O(N)
 * class MyCalendar {
    vector<pair<int, int>> books;
public:
    bool book(int start, int end) {
        for (pair<int, int> p : books)
            if (max(p.first, start) < min(end, p.second)) return false;
        books.push_back({start, end});
        return true;
    }
}
 */
/*
int main() {
	MyCalendar cal;
	cout << cal.book(10, 20) << endl;
	cout << cal.book(15, 25) << endl;
	cout << cal.book(20, 30) << endl;

	return 0;
}*/
