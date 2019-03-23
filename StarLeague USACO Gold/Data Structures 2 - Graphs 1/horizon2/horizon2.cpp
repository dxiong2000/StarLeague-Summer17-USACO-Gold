// horizon2.cpp 

#include <iostream>
#include <algorithm>
using namespace std;
int n, sum(0);

struct building {
	int a, h;
};

bool comp(building a, building b) {
	return a.a < b.a;
}

int main()
{
	building arr[40000];
	//int arr[80000] = { 0 };
	cin >> n;
	for (int i = 0; i < 2 * n; i= i+2) {
		cin >> arr[i].a >> arr[i + 1].a >> arr[i].h;
		arr[i + 1].h = arr[i].h;
	}

	sort(arr, arr + 2 * n, comp);

	for (int i = 0; i < 2*n; i++) {
		//if(arr[i].h )

		sum += arr[i].h*(arr[i + 1].a - arr[i].a);


	}

	cout << arr[5].a << " " << arr[4].h << endl;
	
	return 0;
}
