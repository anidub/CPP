#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <queue>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/angle-between-hands-of-a-clock/
 * Given two numbers, hour and minutes, return the smaller angle (in degrees) formed between the hour and the minute hand.

Answers within 10-5 of the actual value will be accepted as correct.
Input: hour = 12, minutes = 30
Output: 165
https://leetcode.com/problems/angle-between-hands-of-a-clock/discuss/502738/JavaPythonC%2B%2B-Simple-Math-on-Clock-angles
Hour Hand
In 12 hours Hour hand complete whole circle and cover 360°
So, 1 hour = 360° / 12 = 30°

Since 1 hours = 30°
In 1 minute, hours hand rotate -> 30° / 60 = 0.5°
So total angle because of minutes by hour hand is minutes/60 * 30 or minutes * 0.5

Minute Hand
In 60 minutes Minute Hand completes whole circle and cover 360°.
So, 1 minute -> 360° / 60 = 6°
 */

//TC : O(1), SC: (1)
double angleBetweenHandsClock(int hour, int minutes) {
	double h = (hour % 12 * 30) + ((double) minutes / 60 * 30); // Degree covered by hour hand (hour area + minutes area)

	double m = minutes * 6; // Degree covered by minute hand (Each minute = 6 degree)

	double angle = abs(m - h); // Absolute angle between them

	if(angle > 180) angle = 360.0 - angle;// If the angle is obtuse (>180), convert it to acute (0<=x<=180)

	return angle;
}
/*
int main() {
	cout << angleBetweenHandsClock(12, 30) << endl;

	return 0;
}
*/
