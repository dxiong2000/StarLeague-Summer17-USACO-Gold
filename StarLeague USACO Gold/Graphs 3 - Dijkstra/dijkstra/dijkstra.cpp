// dijkstra.cpp 

#include <iostream>
using namespace std;
int verts, edges, start, vertID;
int arr[2501] = { 20000 };
int adj[2501][2501];
bool visited[2501];


int djk(int vert) {

	for (int i = 1; i <= verts; i++) { // updates distances
		if (arr[vert] + adj[vert][i] < arr[i] && visited[i] == false) {
			arr[i] = arr[vert] + adj[vert][i];
		}
	}

	int best = 20000;

	for (int i = 1; i <= verts; i++) { // gets next vertex and its distance
		if (i == start) {
			continue;
		}
		if (arr[i] < best) {
			best = arr[i];
			vertID = i;
		}
	}

	visited[vert] = true;

	return vertID;

}

int main()
{
	cin >> verts >> edges >> start;
	
	for (int i = 0; i <= verts; i++) {
		if (i == start) {
			arr[i] = 0;
		}
		else{
			arr[i] = 20000;
		}
	}

	for (int i = 0; i < edges; i++) {
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

	//djk(start);
	//djk(3);
	//cout << arr[3] << endl;

	int counter(0);
	int vert(start);
	
	while (counter < verts) {
		int nextvert = djk(vert);

		vert = nextvert;
		counter++;
	}
	
	//output
	for (int i = 1; i <= verts; i++) {
		if (arr[i] == 20000) {
			cout << -1 << endl;
		}
		else if (i == start) {
			cout << 0 << endl;
		}
		else {
			cout << arr[i] << endl;
		}
	}

    return 0;
}

