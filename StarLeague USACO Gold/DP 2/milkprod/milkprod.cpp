// milkprod.cpp 

#include <iostream>
#include <algorithm>
using namespace std;
int hours, intervals, rest;

struct lol {
	int start, end, val;
};

bool comp(lol a, lol b) {
	return a.start < b.start;
}

lol arr[1000];
int maxVal[1000];

int main()
{
	cin >> hours >> intervals >> rest;

	for (int i = 0; i < intervals; i++) {
		int start, end, val;
		cin >> start >> end >> val;
		end += rest;
		arr[i].start = start;
		arr[i].end = end;
		arr[i].val = val;
	}

	sort(arr, arr + intervals, comp);

	for (int i = intervals - 1; i >= 0; i--) {
		if (i == intervals - 1) {
			maxVal[i] = arr[i].val;
			continue;
		}
		for (int j = i + 1; j < intervals; j++) {
			if (arr[j].start >= arr[i].end) {
				if (arr[i].val + maxVal[j] > maxVal[i]) {
					maxVal[i] = arr[i].val + maxVal[j];
				}
			}
			else {
				maxVal[i] = arr[i].val;
			}
		}
	}

	cout << *max_element(maxVal, maxVal + intervals) << endl;

    return 0;
}

