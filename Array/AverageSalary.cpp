#include <iostream>
#include <vector>

using namespace std;
/*
 * https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/
 * Given an array of unique integers salary where salary[i] is the salary of the employee i.

Return the average salary of employees excluding the minimum and maximum salary.
Input: salary = [4000,3000,1000,2000]
Output: 2500.00000
Explanation: Minimum salary and maximum salary are 1000 and 4000 respectively.
Average salary excluding minimum and maximum salary is (2000+3000)/2= 2500

https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/discuss/708131/C%2B%2B-Solution

 */

double average(vector<int>& salary) {
	if(salary.size() == 0)
		return 0.0;
	double total = 0.0;
	int max = salary[0];
	int min = salary[0];

	for(int i : salary) {
		if(i > max) max = i;
		if(i < min) min = i;

		total += i;
	}

	total = total - max;
	total = total - min;

	return total/(salary.size() - 2);
}

/*
int main() {

	vector<int> salary;
	salary.push_back(4000);salary.push_back(3000);salary.push_back(2000);salary.push_back(1000);
	cout << average(salary);

	return 0;
}
*/
