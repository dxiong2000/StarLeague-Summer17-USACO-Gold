// cowtraffic.cpp 

#include <iostream>
#include <algorithm>
using namespace std;
int intersections, trails;
int waysInto[5001], waysOut[5001], paths[5001];

int main()
{			
	cin >> intersections >> trails;
	for (int i = 0; i < trails; i++) {
		int a, b;
		cin >> a >> b;
		waysInto[b]++;
		waysOut[a]++;
	}		




			
    return 0;
}

/*int timesVisited[5001];

void solve(int pos) {
	if (pos == intersections) {
		return;
	}

	for (int i = pos + 1; i <= intersections; i++) {
		if (adj[pos][i]) {
			solve(i);
			timesVisited[i]++;
		}
	}

	return;
	}*/

/*for (int i = 1; i <= intersections; i++) {
		bool check = false;
		for (int j = 1; j <= i; j++) {
			if (adj[j][i]) {
				check = true;
			}
			if (j == i && !check) {
				solve(i);
			}
		}
	}

	cout << *max_element(timesVisited, timesVisited + intersections ) << endl;*/