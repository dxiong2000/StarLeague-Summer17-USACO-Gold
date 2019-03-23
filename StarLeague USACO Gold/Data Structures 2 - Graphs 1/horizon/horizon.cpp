// horizon.cpp

#include <iostream>
using namespace std;
int n, sum(0);

struct building {
	int a, b, h, area;
} ;

int main()
{
	building arr[40000];
	int heights[40000] = { 0 };
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].a >> arr[i].b >> arr[i].h;
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = arr[i].a; j < arr[i].b; j++) {
			if (heights[j] == 0) {
				heights[j] = arr[i].h;
				sum += heights[j];
			}
			if (heights[j] < arr[i].h) {
				sum = sum - heights[j];
				heights[j] = arr[i].h;
				sum = sum + heights[j];
			}
		}
	}

	cout << sum << endl;

    return 0;
}

