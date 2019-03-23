// lcs2.cpp 

#include <iostream>
#include <string>
using namespace std;
int size1, size2, best(0);
string s1, s2;
int pv[10010], cur[10010], pv2[10010];

int main()
{
	cin >> s1;
	cin >> s2;
	size1 = s1.length();
	size2 = s2.length();


	for (int j = 1; j <= size2; j++) {
		for (int i = 1; i <= size1; i++) {
			if (s1[i - 1] == s2[j - 1]) {
				cur[i] = pv2[i - 1] + 1;
			}
			else {
				if (cur[i-1] >= pv[i]) {
					cur[i] = cur[i - 1];
				}
				else {
					cur[i] = pv[i];
				}
			}

			if (cur[i] > best) {
				best = cur[i];
			}
			pv2[i] = pv[i];
			pv[i] = cur[i];
		}
	}

	cout << best << endl;

	return 0;
}