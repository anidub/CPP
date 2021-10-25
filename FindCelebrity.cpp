#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>

using namespace std;
/*
 * https://www.cnblogs.com/grandyang/p/5310649.html
 * Find the Celebrity
 * Suppose you are at a party with  n people (labeled from  0 to  n - 1) and among them, there may exist one celebrity. The definition of a celebrity is that all the other  n - 1 people know him/her but he/she does not know any of them.

Now you want to find out who the celebrity is or verify that there is not one. The only thing you are allowed to do is to ask questions like: "Hi, A. Do you know B?" to get information of whether A knows B. You need to find out the celebrity (or verify there is not one) by asking as few questions as possible (in the asymptotic sense).

You are given a helper function  bool knows(a, b)which tells you whether A knows B. Implement a function  int findCelebrity(n). There will be exactly one celebrity if he/she is in the party. Return the celebrity's label if there is a celebrity in the party. If there is no celebrity, return  -1.
 Input: graph = [
  [1,1,0],
  [0,1,0],
  [1,1,1]
]
 https://www.cnblogs.com/grandyang/p/5310649.html
 */
vector<vector<int>> matrix;

//if(mat[a][b] == 1, then a knows b
bool knows(int a, int b) {
	return matrix[a][b];
}

int findCelebrity(int n) {
	if(n == 0) return -1;
	int result = 0;

	for(int i = 0; i < n; i++) {//find 1st person does not know other
		if(knows(result, i)) result = i;
	}

	for(int i = 0; i < n; i++) {
		if(result != i && (knows(result, i) || !knows(i, result)) ) //confirm if all know person but that person does not know others
			return -1;
	}
	return result;
}
/*
int main() {
	vector<int> m1; m1.push_back(1);m1.push_back(1);m1.push_back(0);
	vector<int> m2; m2.push_back(0);m2.push_back(1);m2.push_back(0);
	vector<int> m3; m3.push_back(1);m3.push_back(1);m3.push_back(1);
	matrix.push_back(m1);matrix.push_back(m2);matrix.push_back(m3);
	cout << findCelebrity(2) << endl;
	return 0;
}
*/
