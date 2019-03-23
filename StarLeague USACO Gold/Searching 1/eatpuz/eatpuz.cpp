// eatpuz.cpp 

#include <iostream>
#include <algorithm>
using namespace std;
int arr[21], mark[21];
int cals, buckets, best(0), yes(0);

void solve(int sum, int c) {

	if (sum > cals|| (c+1)>=buckets) {
		return;
	}
	if (sum > best) {
		best = sum;
	}
		
	for (int i = c+1; i < buckets; i++) {
		sum += arr[i];

		for (int j = 1; j < buckets; j++) {
			solve(sum, c + j);
		}
		/*solve(sum, c + 1);
		solve(sum, c + 2);
		solve(sum, c + 3);*/
	}
}

int main()
{
	cin >> cals >> buckets;

	
	for (int i = 0; i < buckets; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + buckets);


	solve(0,-1);

	if (yes != 2) {
		cout << best << endl;
	}

    return 0;
}

