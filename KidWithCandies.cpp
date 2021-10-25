#include<iostream>
#include<vector>
using namespace std;

vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
	vector<bool> result;
	if(candies.empty()) {
		return result;
	}
	int maxValue = 0;
	for(size_t  i = 0; i < candies.size(); i++) {
		maxValue = max(candies[i], maxValue);
	}
	for(size_t i = 0; i < candies.size(); i ++) {
		if(candies[i] + extraCandies >= maxValue) {
			result.push_back(true);
		}else {
			result.push_back(false);
		}
	}
	for(size_t i : result){
		cout << "value :" << i << endl;
	}
	return result;
}

/*int main() {
	vector<int> candies;
	candies.push_back(2);candies.push_back(3);candies.push_back(5);candies.push_back(1);candies.push_back(3);
	int extra = 3;
	kidsWithCandies(candies, extra);

	return 0;
}*/
