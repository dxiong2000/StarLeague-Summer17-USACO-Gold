// blink.cpp 

#include <iostream>
using namespace std;

int n, arr[16], arr2[16];
int b;

void change(int i) {
	if (arr[i] == 1) {
		arr[i] = 0;
		return;
	}
	if (arr[i] == 0) {
		arr[i] = 1;
		return;
	}
}

int main()
{
	cin >> n >> b;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		arr2[i] = arr[i];
	}

	for (int time = 1; time <= b; time++) {
		for (int bulb = 0; bulb < n; bulb++) {
			if (bulb == 0 && arr2[n-1]==1) {
				change(bulb);
			}
			if (arr2[bulb - 1] == 1) {
				change(bulb);
			}

			if (bulb == n - 1) {
				for (int k = 0; k < n; k++) {
					arr2[k] = arr[k];
				}
			}
		}
	}


	for (int i = 0; i < n; i++) { 
		cout << arr[i] << endl;
	}

    return 0;
}

