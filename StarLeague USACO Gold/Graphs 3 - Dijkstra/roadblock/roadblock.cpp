// roadblock.cpp

#include <iostream>
using namespace std;
int verts, edges, vertID;
int arr[101];
int adj[101][101];
bool visited[101];


int djk(int vert) {

	for (int i = 1; i <= verts; i++) { // updates distances
		if (arr[vert] + adj[vert][i] < arr[i] && visited[i] == false) {
			arr[i] = arr[vert] + adj[vert][i];
		}
	}

	int best = 1000001;

	for (int i = 1; i <= verts; i++) { // gets next vertex and its distance
		if (i == 1) {
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
	cin >> verts >> edges;

	for (int i = 0; i <= verts; i++) {
		if (i == 1) {
			arr[i] = 0;
		}
		else {
			arr[i] = 1000001;
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
				adj[a][b] = 1000001;
			}
		}
	}

	int v = 1;
	int nextv = 0;

	/*while (nextv != verts) {
		nextv = djk(v);
		v = nextv;
		if (nextv == verts) {
			int x = djk(verts);
		}
	}*/
	cout << djk(1) << endl;
	cout << arr[5] << endl;

	//output
	

	return 0;
}
