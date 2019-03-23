// knapsack.cpp 

#include <iostream>
using namespace std;
int n, cap;
int dp[1000][5000];
int s[1001], v[1001];

int main()
{
	cin >> n >> cap;
	for (int i = 1; i <= n; i++) { // 1 indexing
		cin >> s[i] >> v[i];
	}

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= cap; j++) {
			if (i == 0) {
				dp[i][j] = 0;
				continue;
			}
			if (j >= s[i]) {
				if (dp[i - 1][j] <= (dp[i - 1][j - s[i]] + v[i])) {

					dp[i][j] = dp[i - 1][j - s[i]] + v[i];
				}
				else {
					dp[i][j] = dp[i - 1][j];
				}
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	// debugging stuff
	/*for (int i = 0; i <= 10; i++) { 
		cout << i << " " << dp[3][i] << endl;
	}*/

	cout << dp[n][cap] << endl;

    return 0;
}

