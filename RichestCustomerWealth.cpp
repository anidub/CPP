#include <iostream>
#include <vector>

using namespace std;
int maxWealth(vector<vector<int>>& accounts) {
	if(accounts.empty())
		return 0;
	int maxAmount = 0;
	for(auto& account : accounts){
		int amountInCurrentBank = 0;
		for(auto& money: account) {
			amountInCurrentBank += money;
		}
		maxAmount = max(maxAmount, amountInCurrentBank);
	}

	cout << "max amount : " << maxAmount << endl;
	return maxAmount;
}


/*int main() {
	vector<vector<int>> accounts;
	vector<int> money1; vector<int> money2;
	money1.push_back(1); money1.push_back(2);money1.push_back(3);
	money2.push_back(3);money2.push_back(4);money2.push_back(5);
	accounts.push_back(money1);accounts.push_back(money2);
	maxWealth(accounts);

	return 0;
} */
