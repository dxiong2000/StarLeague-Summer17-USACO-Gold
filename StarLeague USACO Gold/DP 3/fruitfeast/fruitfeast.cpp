// fruitfeast.cpp 

#include <iostream>
using namespace std;
int cap, a, b;
bool dp[5000000]; // dp[i] = true if sum "i" is reachable

int main()							// runs knapsack once, then halves, then runs knapsack again
{
	cin >> cap >> a >> b;
	
	for (int i = 0; i <= cap; i++) {
		if (i%a == 0 || i%b == 0) { // sets multiples of a and b as reachable sums
			dp[i] = true;
		}
		if (dp[i]) {
			dp[i + a] = true;
			dp[i + b] = true;
		}
	}

	if (dp[cap]) {
		cout << cap << endl;
		return 0;
	}
	else {
		for (int i = 0; i <= cap; i++) {
			if (dp[i]) {
				if (i % 2 == 1) {
					int x = (i - 1) / 2;
					dp[x] = true;
				}
				else {
					int x = i / 2;
					dp[x] = true;
				}
			}
		}
	}

	for (int i = 0; i <= cap; i++) {
		if (dp[i]) {
			dp[i + a] = true;
			dp[i + b] = true;
		}
	}

	for (int i = cap; i > 0; i--) {
		if (dp[i]) {
			cout << i << endl;
			return 0;
		}
	}


    return 0;
}

