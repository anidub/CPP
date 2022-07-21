#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <unordered_map>
#include <unordered_set>
#include <utility>

using namespace std;
/*https://www.educative.io/courses/grokking-the-coding-interview/39q3ZWq27jM
 * Any number will be called a happy number if, after repeatedly replacing it with a number equal to the sum of the square of all of its digits, leads us to number ‘1’. All other (not-happy) numbers will never reach ‘1’. Instead, they will be stuck in a cycle of numbers which does not include ‘1’.
Input: 23
Output: true (23 is a happy number)
Explanations: Here are the steps to find out that 23 is a happy number:
 */
int findSquareSum(int num);
//O(LOGN)
bool findHappyNum(int num) {
	int slow = num, fast = num;
	slow = findSquareSum(slow);
	fast =  findSquareSum(findSquareSum(fast));

	while(slow != fast) {
		slow = findSquareSum(slow);
		fast =  findSquareSum(findSquareSum(fast));
	}
	return slow == 1;
}

int findSquareSum(int num) {
	int sum = 0, digit;

	while(num > 0) {
		digit = num % 10;
		num /= 10;
		sum += digit * digit;
	}
	return sum;
}
/*
int main(int argc, char* argv[]) {
  cout << findHappyNum(23) << endl;
  cout << findHappyNum(12) << endl;
}*/
