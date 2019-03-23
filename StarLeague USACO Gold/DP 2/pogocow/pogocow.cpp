// pogocow.cpp 

#include <iostream>
#include <algorithm>
using namespace std;
int n;
int dp[1000][1000];

struct target {
	int x, pts;
};

bool comp(target a, target b) {
	return a.x < b.x;
}

target arr[1000];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].x >> arr[i].pts;
	}

	sort(arr, arr + n, comp);

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (i == j) {
				dp[i][j] = arr[i].pts;
			}
			if()
		}
	}
		

    return 0;
}

