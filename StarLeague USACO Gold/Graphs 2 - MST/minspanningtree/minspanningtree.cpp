// minspanningtree.cpp 

#include <iostream>
#include <algorithm>
using namespace std;
int verts, edges, sum(0), vertID;
int adj[2501][2501];
int arr[2501]; // neighbor data
bool visited[2501];


bool Visited() {
	for (int i = 1; i <= verts; i++) {
		if (visited[i] == false) {
			return true;
		}
	}

	return false;
}

int idk(int a) { // finds and stores neighbor data into arr. index is vert#. returns the vertex to choose next.

	for (int i = 1; i <= verts; i++) { // 
		if (adj[a][i] < arr[i] && visited[i]==false) {
			arr[i] = adj[a][i];
		}
	}

	int best = 20001;

	for (int i = 1; i <= verts; i++) {
		if (arr[i] < best) {
			best = arr[i];
			vertID = i;
		}
	}

	sum += best;
	arr[vertID] = 20002; 

	visited[a] = true;

	return vertID;

}

int main()
{
	cin >> verts >> edges;

	for (int i = 0; i <= verts; i++) {
		arr[i] = 30000;
	}

	for (int i = 0; i < edges; i++) { // stores input in adj matrix
		int a, b, c;
		cin >> a >> b >> c;

		adj[a][b] = c;
		adj[b][a] = c;
	}

	for (int a = 1; a <= verts; a++) { // sets impossible paths to large #
		for (int b = 1; b <= verts; b++) {
			if (adj[a][b] == 0) {
				adj[a][b] = 20000;
			}
		}
	}
	
	int counter(0);
	int vert(1);

	while (counter < verts) {
		int nextvert = idk(vert);

		vert = nextvert;
		counter++;
	}

	cout << sum - 20000 << endl;
	
    return 0;
}

