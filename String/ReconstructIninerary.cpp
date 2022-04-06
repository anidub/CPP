#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <vector>
#include <stack>
#include <utility>
#include <map>
#include <set>

using namespace std;
/*https://leetcode.com/problems/reconstruct-itinerary/
 * You are given a list of airline tickets where tickets[i] = [fromi, toi] represent the departure and the arrival airports of one flight. Reconstruct the itinerary in order and return it.

All of the tickets belong to a man who departs from "JFK", thus, the itinerary must begin with "JFK". If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string.

For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"]
Input: tickets = [["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]
Output: ["JFK","MUC","LHR","SFO","SJC"]
https://leetcode.com/problems/reconstruct-itinerary/discuss/78768/Short-Ruby-Python-Java-C%2B%2B

https://www.youtube.com/watch?v=8MpoO2zA2l4 : eulerian path explained
https://leetcode.com/problems/reconstruct-itinerary/discuss/78842/C%2B%2B-non-recursive-O(N)-time-O(N)-space-solution-with-detail-explanations : iterative
 */
map<string, multiset<string>> targets;
vector<string> route;

void visit(string airport);
//O(ELogE) where E is number of edges. Because we offer each edge into queue once and then poll it out once.
//Space complexity is O(E)
vector<string> findItinerary(vector<vector<string>>& tickets) {
	if(tickets.empty()) return {};
	for(auto ticket : tickets) {
		targets[ticket[0]].insert(ticket[1]);
	}
	visit("JFK");
	reverse(route.begin(), route.end());
	return route;
}

void visit(string airport) {
	while(targets[airport].size()) {
		string next = *targets[airport].begin();
		targets[airport].erase(targets[airport].begin());
		visit(next);
	}
	route.push_back(airport);
}
/*
int main() {
	vector<vector<string>> tickets = {{"MUC","LHR"},{"JFK","MUC"},{"SFO","SJC"},{"LHR","SFO"}};
	findItinerary(tickets);
	return 0;
}*/
