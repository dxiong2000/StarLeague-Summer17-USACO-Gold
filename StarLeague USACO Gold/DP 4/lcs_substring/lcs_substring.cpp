// lcs_substring.cpp

#include <iostream>
#include <string>
using namespace std;
int size1, size2, best(0);
string s1, s2;
int dp[1010][1010];

int main()
{
	cin >> s1;
	cin >> s2;
	size1 = s1.length();
	size2 = s2.length();
			
	for (int j = 1; j <= size2; j++) {
		for (int i = 1; i <= size1; i++) {
			if (s1[i - 1] == s2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				if (dp[i][j] > best) {
					best = dp[i][j];
				}
			}
			else {
				dp[i][j] = 0;
			}
		}
	}

	cout << best << endl;

	return 0;
}