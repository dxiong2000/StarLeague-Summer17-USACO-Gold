// painting.cpp 

#include <iostream>
using namespace std;
int n;

struct fence {
	int x1, x2, y1, y2;
};

int main()
{
	fence arr[50000];

	cin >> n;
	int total = n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].x1 >> arr[i].y1 >> arr[i].x2 >> arr[i].y2;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i].x1 > arr[j].x1 && arr[i].y1 > arr[j].y1 && arr[i].x2 < arr[j].x2) {
				total--;
				break;
			}
		}
	}

	cout << total << endl;


    return 0;
}

