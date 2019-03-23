// agrinet.cpp

#include <iostream>
using namespace std;
int n, sum(0), vertID;
int adj[101][101];
int arr[101];
bool visited[101];


int idk(int a) { // finds and stores neighbor data into arr. index is vert#. returns the vertex to choose next.

	for (int i = 1; i <= n; i++) { 
		if (adj[a][i] < arr[i] && visited[i] == false) {
			arr[i] = adj[a][i];
		}
	}

	int best = 20001;

	for (int i = 1; i <= n; i++) {
		if (arr[i] < best) {
			best = arr[i];
			vertID = i;
			cout << "YES" << " " << best<< endl;
		}
	}

	sum += best;

	arr[vertID] = 20002;

	visited[a] = true;

	return vertID;

}

int main()
{
	cin >> n;

	for (int i = 0; i <= n; i++) {
		arr[i] = 30000;
	}

	for (int i = 1; i <= n; i++) { 
		for (int j = 1; j <= n; j++) {
			int x;
			cin >> x;
			if (x == 0) {
				adj[i][j] = 20000;
				continue;
			}
			else {
				adj[i][j] = x;
				// << x << endl;
			}
		}
	}


	int counter(0);
	int vert(1);

	while (counter < n) {
		int nextvert = idk(vert);

		vert = nextvert;
		counter++;
	}

	cout << sum - 20000 << endl;

    return 0;
}

