// badhair.cpp 

#include <iostream>
#include <stack>
using namespace std;

	
int main()
{
	long long n, arr[80000], sum(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		if (i == n - 1 && arr[i-1]>arr[i]) {
			sum++;
			break;
		}
		for (int j = i+1; j < n; j++) {
			if (arr[j] >= arr[i]) {
				sum += j - i - 1 ;
				break;
			}
		}
	}

	cout << sum << endl;

    return 0;
}

