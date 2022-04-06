#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <stack>
#include <sstream>

using namespace std;
/*https://leetcode.com/problems/exclusive-time-of-functions/
 * On a single-threaded CPU, we execute a program containing n functions. Each function has a unique ID between 0 and n-1.

Function calls are stored in a call stack: when a function call starts, its ID is pushed onto the stack, and when a function call ends, its ID is popped off the stack. The function whose ID is at the top of the stack is the current function being executed. Each time a function starts or ends, we write a log with the ID, whether it started or ended, and the timestamp.

You are given a list logs, where logs[i] represents the ith log message formatted as a string "{function_id}:{"start" | "end"}:{timestamp}". For example, "0:start:3" means a function call with function ID 0 started at the beginning of timestamp 3, and "1:end:2" means a function call with function ID 1 ended at the end of timestamp 2. Note that a function can be called multiple times, possibly recursively.

A function's exclusive time is the sum of execution times for all function calls in the program. For example, if a function is called twice, one call executing for 2 time units and another call executing for 1 time unit, the exclusive time is 2 + 1 = 3.

Return the exclusive time of each function in an array, where the value at the ith index represents the exclusive time for the function with ID i.
Input: n = 2, logs = ["0:start:0","1:start:2","1:end:5","0:end:6"]
Output: [3,4]
Explanation:
Function 0 starts at the beginning of time 0, then it executes 2 for units of time and reaches the end of time 1.
Function 1 starts at the beginning of time 2, executes for 4 units of time, and ends at the end of time 5.
Function 0 resumes execution at the beginning of time 6 and executes for 1 unit of time.
So function 0 spends 2 + 1 = 3 units of total time executing, and function 1 spends 4 units of total time executing.

https://leetcode.com/problems/exclusive-time-of-functions/discuss/1024327/C%2B%2B-O(number-of-log-lines)-stack-solution-with-diagram : used
https://leetcode.com/problems/exclusive-time-of-functions/discuss/105103/C%2B%2B-O(n)-stack-with-explaination : to understand
 */
struct Log {
	int id;
	bool isStart;
	int time;
};

Log getLog(string &s) {
	string id, isStart, time;
	stringstream ss(s);

	getline(ss, id, ':');
	getline(ss, isStart, ':');
	getline(ss, time, ':');

	return { stoi(id), isStart == "start", stoi(time) };
}
//TC : O(N) ([Note that the time taken to parse the log lines can be carefully assumed to be O(1) in the context of the given the constraints.
//Since the function ids < 100, at max first three char will be sufficient to get the ids,
//similarly for other attributes too]), SC : O(N)
vector<int> exclusiveTimeFunctionCalls(int n, vector<string>& logs) {
	if(n != logs.size()) return {};

	vector<int> exclusive(n, 0);
	stack<Log> st;

	for(auto &log : logs) {
		Log curLog = getLog(log);
		if(curLog.isStart) {
			st.push(curLog);
		} else {
			int time = curLog.time - st.top().time + 1;
			exclusive[curLog.id] += time;
			st.pop();

			if(!st.empty())
				exclusive[st.top().id] -= time; //since single threaded machine
		}
	}
	return exclusive;
}
/*
int main() {
	vector<string> logs = {"0:start:0","1:start:2","1:end:5","0:end:6"};
	exclusiveTimeFunctionCalls(2, logs);

	return 0;
}*/
