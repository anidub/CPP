#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <unordered_map>
#include <queue>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/ipo/
 * Given a set of investment projects with their respective profits, we need to find the most profitable projects. We are given an initial capital and are allowed to invest only in a fixed number of projects. Our goal is to choose projects that give us the maximum profit. Write a function that returns the maximum total capital after selecting the most profitable projects.

We can start an investment project only when we have the required capital. Once a project is selected, we can assume that its profit has become our capital.

Example 1:

Input: Project Capitals=[0,1,2], Project Profits=[1,2,3], Initial Capital=1, Number of Projects=2
Output: 6
Explanation:

With initial capital of ‘1’, we will start the second project which will give us profit of ‘2’. Once we selected our first project, our total capital will become 3 (profit + initial capital).
With ‘3’ capital, we will select the third project, which will give us ‘3’ profit.
After the completion of the two projects, our total capital will be 6 (1+2+3).

Example 2:

Input: Project Capitals=[0,1,2,3], Project Profits=[1,2,3,5], Initial Capital=0, Number of Projects=3
Output: 8
Explanation:

With ‘0’ capital, we can only select the first project, bringing out capital to 1.
Next, we will select the second project, which will bring our capital to 3.
Next, we will select the fourth project, giving us a profit of 5.
After selecting the three projects, our total capital will be 8 (1+2+5).

https://www.educative.io/courses/grokking-the-coding-interview/B6x69OLX4jY
https://leetcode.com/problems/ipo/solution/
 */
class MaximizeCapital {
#define pi pair<int, int>

public:
	//TC:O(NLOGK) SC:O(N)
    int findMaximizedCapital(int k, int W, vector<int>& p, vector<int>& c) {
        int n = p.size();
        vector<pair<int, int>> profit_capital;
        for(int i = 0; i < n; i++) {
            profit_capital.push_back({p[i], c[i]});
        }

        sort(profit_capital.begin(), profit_capital.end(), [&](pi a, pi b) {return a.second < b.second;});//sorting based on low captial first

        int i = 0;
        priority_queue<int> profit_holder;//max heap

        while(k) {
            while(i < n && profit_capital[i].second <= W) {
                profit_holder.push(profit_capital[i++].first);
            }
            if(!profit_holder.empty()) {
                W += profit_holder.top();
                profit_holder.pop();
            }
            k--;
        }
        return W;
    }
};

/*
int main(int argc, char *argv[]) {
	MaximizeCapital mc;
	vector<int> p{1,2,3};
	vector<int> c{0,1,2};

	int result  = mc.findMaximizedCapital(2, 1, p, c);

  cout << "Maximum capital: " << result << endl;


}*/
