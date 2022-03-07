#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <utility>
#include <unordered_map>
#include <unordered_set>

using namespace std;
/*
 * https://leetcode.com/problems/corporate-flight-bookings/
 * There are n flights that are labeled from 1 to n.
You are given an array of flight bookings bookings, where bookings[i] = [firsti, lasti, seatsi] represents a booking for flights firsti through lasti (inclusive) with seatsi seats reserved for each flight in the range.
Return an array answer of length n, where answer[i] is the total number of seats reserved for flight i.
Example 1:

Input: bookings = [[1,2,10],[2,3,20],[2,5,25]], n = 5
Output: [10,55,45,25,25]
Explanation:
Flight labels:        1   2   3   4   5
Booking 1 reserved:  10  10
Booking 2 reserved:      20  20
Booking 3 reserved:      25  25  25  25
Total seats:         10  55  45  25  25
Hence, answer = [10,55,45,25,25]

 */
vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
    if(bookings.empty()) return {};
    vector<int> result(n, 0);

    for(auto& flight: bookings) {
        int start = flight[0]-1; //array index starts from 0 but questions has bookings from 1 hence -1;
        int end = flight[1]-1;
        int seats = flight[2];
        while(start <= end) {
            cout << "seats:" << seats << endl;
            result[start] += seats;
            start++;
        }
    }
    for(auto& i : result) {
        cout << " " << i << endl;
    }
    return result;
}
/*
int main() {
	vector<vector<int>> bookings;
	vector<int> b1; b1.push_back(1);b1.push_back(2);b1.push_back(10);
	vector<int> b2; b2.push_back(2);b2.push_back(3);b2.push_back(20);
	vector<int> b3; b3.push_back(2);b3.push_back(5);b3.push_back(25);
	bookings.push_back(b1);bookings.push_back(b2);bookings.push_back(b3);
	corpFlightBookings(bookings, 5);
}*/
