// distant1.cpp 

#include <iostream>
#include <queue>		// p_q
#include <functional>	// greater
#include <utility>		// pair
#include <vector>		// vector
#define pii pair<int,int>
using namespace std;
int n, a, b, map[32][32];


int main()
{
	cin >> n >> a >> b;

	for (int i = 1; i <= n; i++ ) {//? 				( = 1
		for (int j = 1; j <= n; j++) {//? 			) = 2
			char c;
			cin >> c;
			if (c == '(') {
				map[i][j] = 1;
			}
			else {
				map[i][j] = 2;
			}
		}
	}
	

	

	return 0;
}

