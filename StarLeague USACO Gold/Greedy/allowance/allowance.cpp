// allowance.cpp 

#include <iostream>
#include <algorithm>
using namespace std;
int n, c, weeks(0);

struct allow {
	int val, num, need, ratio;
}arr[21];

bool comp(allow a, allow b) {
	return a.val > b.val;
}

void calc(int lim, int init, int cur) {
	if (arr[cur].num == 0) {
		return;
	}
	int rem = lim % arr[cur].val;
	int need = (lim - rem) / arr[cur].val;

	arr[cur].need = need;
	if (need != 0) {
		arr[cur].ratio = arr[cur].num / arr[cur].need;
	}

	if (rem == 0) {
		int best = 2000000;
		for (int i = init; i <= cur; i++) {
			if (arr[i].ratio < best) {
				best = arr[i].ratio;
			}
		}

		for (int i = init; i <= cur; i++) {
			arr[i].num -= best;
		}

		weeks += best;

		return;
	}
	
	calc(rem , init, cur + 1);

	return;
}

void calc2(int lim, int i) {
	int times(1);
	int x = arr[i].val;
	while (x < lim) {
		x += x;
		times++;
	}
	
	weeks += arr[i].num / times;
	
	return;
}

int main()
{
	cin >> n >> c;

	for (int i = 0; i < n; i++) {
		cin >> arr[i].val >> arr[i].num;
	}

	sort(arr, arr + n, comp); // sorts greatest to least by denomination

	for (int i = 0; i < n; i++) {
		if (arr[i].val >= c) {
			weeks += arr[i].num;
			arr[i].num = 0;
			continue;
		}
		else {
			if (arr[i].num != 0) {
				calc(c, i, i);
			}
			if (arr[i].num != 0) {
				calc2(c, i);
			}
		}
	}

//	cout << arr[0].num << endl;
	cout << weeks << endl;


    return 0;
}
