// hay4sale.cpp 

#include <iostream>
using namespace std;
int cap, n;
int arr[5001];
bool previous[50001]; // instead of bool dp[5000][50000], which takes up too much space, use sliding window method
bool cur[50001];

int main()
{
	cin >> cap >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= cap; j++) {
			if (i == 0) {
				previous[j] = true;
				cur[j] = true;
			}
			if (previous[j] || previous[j - arr[i] ]) { // use previous[j] instead of dp[i-1][j]
				cur[j] = true;
				previous[j] = cur[j];
			}
		}
	}

	for (int k = cap; k > 0; k--) {
		if (cur[k]) {
			cout << k << endl;
			return 0;
		}
	}

    return 0;
}

