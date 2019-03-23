// lcs.cpp 

#include <iostream>
#include <string>
using namespace std;
int size1, size2;
string s1, s2;
int dp[1010][1010];

int main()
{
	cin >> s1;
	cin >> s2;
	size1 = s1.length();
	size2 = s2.length();

	for (int i = 1; i <= size1; i++) {
		for (int j = 1; j <= size2; j++) {
			if (s1[i - 1] == s2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				if (dp[i - 1][j] >= dp[i][j - 1]) {
					dp[i][j] = dp[i - 1][j];
				}
				else {
					dp[i][j] = dp[i][j - 1];
				}
			}
		}
	}

	cout << dp[size1][size2] << endl;

    return 0;
}

