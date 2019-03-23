// proximity.cpp 

#include <iostream>
using namespace std;
int n, k, best(-1);
int arr[50001];
int dp[1000001]; // dp[i] is the most recent index of cow id i

int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < 1000001; i++) {
		dp[i] = -k - 1;
	}
	for (int i = 0; i < n; i++) {
		if ((dp[arr[i]] >= i-k)) {
			if (arr[i] > best) {
				best = arr[i];
			}
		}
		dp[arr[i]] = i;
	}

	cout << best << endl;

    return 0;
}