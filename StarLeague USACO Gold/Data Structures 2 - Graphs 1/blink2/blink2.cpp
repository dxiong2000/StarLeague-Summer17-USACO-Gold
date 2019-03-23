// blink.cpp 

#include <iostream>
#include <cmath>
using namespace std;

long long int x = 0;
int n, arr[16], arr2[16], store[100];
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
		x = x + arr[i] * pow(10, n - 1 - i);
		arr2[i] = arr[i];
		store[0] = x;
	}




	/*for (int time = 1; time <= b; time++) {
		for (int bulb = 0; bulb < n; bulb++) {
			if (bulb == 0 && arr2[n - 1] == 1) {
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
	}*/
	
	//cout << arr2[0] << endl << arr2[1] << endl << arr2[2] << endl;


	return 0;
}