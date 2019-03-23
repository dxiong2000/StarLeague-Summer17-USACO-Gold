// cardgame.cpp 

#include <iostream>
#include <algorithm>
using namespace std;
int n, points(0);
bool cards[100001];	// true = Elsie's cards, false = Bessie's cards
int elsieOrder[50001];
int bessieCards[50001];
bool v[50001];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		cards[x] = true;
		elsieOrder[i] = x;
	}
	int c = 0;
	for (int i = 1; i < 2 * n; i++) {
		if (!cards[i]) {
			bessieCards[c] = i;
			c++;
		}
	}
	sort(bessieCards, bessieCards + n);
	int a(n / 2), b(0);
	for (int i = 0; i < n; i++) {
		if (i < n / 2) {
			for (int j = n / 2; j < n; j++) {
				if (bessieCards[j] > elsieOrder[i] && !v[j]) {
					v[j] = true;
					points++; 
					break;
				}
				if (j == n - 1) {
					v[a] = true;
					break;
					a++;
				}
			}
		}
		if (i >= n / 2) {
			for (int j = 0; j < n / 2; j++) {
				if (bessieCards[j] < elsieOrder[i] && !v[j]) {
					v[j] = true;
					points++;
					break;
				}
				if (j == n / 2 - 1) {
					v[b] = true;
					break;
					b++;
				}
			}
		}
	}


	cout << points << endl;
    return 0;
}

