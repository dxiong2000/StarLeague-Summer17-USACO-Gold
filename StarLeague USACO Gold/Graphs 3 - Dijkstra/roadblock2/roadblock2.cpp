// roadblock.cpp

#include <iostream>
using namespace std;
int verts, edges, vertID, djk1, djk2;
int dist[101];
int adj[101][101];
int parent[101];
int path[101];
bool visited[101] = { false };


int djk(int vert) {

	for (int i = 1; i <= verts; i++) { // updates distances
		if (dist[vert] + adj[vert][i] < dist[i] && visited[i] == false ) {
			dist[i] = dist[vert] + adj[vert][i];
			//cout << i << " " << dist[i] << endl;
		}
	}

	int best = 1000001;

	for (int i = 1; i <= verts; i++) { // gets next vertex and its distance
		if (i == 1 || i == vert || visited[i] == true) {
			continue;
		}
		if (dist[i] < best) {
			best = dist[i];
			vertID = i;
		}
	}
	cout << "node: " << vertID << "   parent: " << vert << endl;
	parent[vertID] = vert;
	visited[vert] = true;

	return vertID;

}

int main()
{
	cin >> verts >> edges;

	for (int i = 0; i <= verts; i++) {
		if (i == 1) {
			dist[i] = 0;
			parent[i] = 1;
		}
		else {
			dist[i] = 1000001;
			parent[i] = -1;
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

	while (nextv != verts) {
		nextv = djk(v);
		v = nextv;
		if (nextv == verts) {
			int x = djk(verts);
			break;
		}
	}
/*
	djk1 = dist[5];

	int prev;
	int x = verts;
	int count = 0;
	while (x != 1) {
		prev = parent[x];
		path[count] = x;
		x = prev;
		count++;
	}
	*/
	//cout << path[0] << " " << path[1] << " " << path[2] << " " << path[3] << " " << path[4] << endl;


/*	cout << djk(1) << endl;
	for (int i = 1; i <= 5; i++) {
		cout << i << " " << dist[i] << endl;
	}
	cout << djk(3) << endl;
	for (int i = 1; i <= 5; i++) {
		cout << i << " " << dist[i] << endl;
	}
	cout << djk(4) << endl;
	for (int i = 1; i <= 5; i++) {
		cout << i << " " << dist[i] << endl;
	}*/

	//output
	//cout << djk2 - djk1 << endl;

	return 0;
}
