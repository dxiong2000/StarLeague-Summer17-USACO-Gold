// bds.cpp 

#include <iostream>
#include <cmath>
using namespace std;
int n, finalsum, arr[100], arr2[100];
bool mark[100];

int factorial(int a) {
	if (a == 0) {
		return 1;
	}

	return a*factorial(a - 1);
}

int comb(int a, int b) { //aCb
	return (factorial(a)) / (factorial(b)*factorial(a - b));
}

int solve() { //uses binomial expansion/pascals triangle to get final sum
	int sum =0;

	for (int i = 0; i < n; i++) { // n iterations for n variables
		sum += arr[i] * comb(n - 1, i);
	}


	return sum;
}

void perms(int k) { // gets all permutations
	if (k == n + 1) { // compare sum from solve() to final sum
		if (solve() == finalsum) {
			for (int i = 0; i < n; i++) {
				if (i == n - 1) {
					cout << arr2[i] << endl;
				}
				else {
					cout << arr2[i] << " ";
				}
			}
			exit(0);
		}
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!mark[i]) {
			arr[i] = k;
			arr2[i] = k;
			mark[i] = true;
			perms(k + 1);
			mark[i] = false;
		}
	}
}
	

int main()
{
	cin >> n >> finalsum;
	
	perms(1);

    return 0;
}