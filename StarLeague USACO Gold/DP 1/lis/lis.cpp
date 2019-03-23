// lis.cpp 

#include <iostream>
#include <algorithm>
using namespace std;
int n;
int seq[20000], arr[20000];

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> seq[i];
		arr[i] = 1;
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) { //searches from index 0 up to current i
			if (seq[i] > seq[j]) {
				if (arr[i] < arr[j] + 1) {
					arr[i] = arr[j] + 1;
				}
			}
		}
	}

	cout << *max_element(arr, arr + n) << endl; 

    return 0;
}

