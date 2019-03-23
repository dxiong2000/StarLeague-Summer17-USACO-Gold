// snail.cpp 

#include <iostream>
#include <string>
using namespace std;
int n, bar, bestSteps(0);
int map[130][130] = {0}; // map[row][col]


void solve(int row, int col, int steps, int dir) { // 1 left 2 up 3 right 4  down
	int rowDown = row + 1;
	int rowUp = row - 1;
	int colLeft = col - 1;
	int colRight = col + 1;

	if (dir == 1 && map[row][colLeft] == 1) {
		if (steps > bestSteps) {
			bestSteps = steps;
		}
		return;
	}
	if (dir ==2 && map[rowUp][col] == 1) {
		if (steps > bestSteps) {
			bestSteps = steps;
		}
		return;
	}
	if (dir == 3 && map[row][colRight] == 1) {
		if (steps > bestSteps) {
			bestSteps = steps;
		}
		return;
	}
	if (dir == 4 && map[rowDown][col] == 1) {
		if (steps > bestSteps) {
			bestSteps = steps;
		}
		return;
	}

	if (colLeft != 0 && map[row][colLeft] == 0) { // LEFT
		map[row][col] = 1;
		solve(row, colLeft, steps++, 1);
		map[row][col] = 0;
	}
	if (rowUp != 0 && map[rowUp][col] == 0) { // UP	
		map[row][col] = 1;
		solve(rowUp, col, steps++, 2);
		map[row][col] = 0;
	}
	if (colRight <= n && map[row][colRight] == 0) { // RIGHT
		map[row][col] = 1;
		solve(row, colRight, steps++,3 );
		map[row][col] = 0;
	}
	if (rowDown <= n && map[rowDown][col] == 0) { // DOWN
		map[row][col] = 1;
		solve(rowDown, col, steps++,4);
		map[row][col] = 0;
	}

}

int main()
{
	cin >> n >> bar;

	for (int i = 0; i < bar; i++) {
		string x;
		cin >> x;
		char c = x[0];
		int a = c - 64; // A=1, B=2, C=3, etc
		int b = x[1] - 48;
		map[b][a] = 2; // 2 is a barrier
	}

	solve(1, 1, 1, 0);

	cout << bestSteps << endl;

    return 0;
}

/*
bool noMoves(int row, int col) {
	int rowDown = row + 1;
	int rowUp = row - 1;
	int colLeft = col - 1;
	int colRight = col + 1;

	if ((rowUp < 1 || map[rowUp][col] == 2) && (colRight > n || map[row][colRight] == 2) && (rowDown > n || map[rowDown][col] == 2) && (colLeft < 1 || map[row][colLeft] == 2)) {
		return true;
	}
	 if (colRight > n || map[row][colRight] == 2) {
	 return true;
	 }
	 if (rowDown > n || map[rowDown][col] == 2) {
	 return true;
	 }
	 if (colLeft < 1 || map[row][colLeft] == 2) {
	 return true;
	 }

	return false;
}
*/

/*
if (noMoves(row, col) == true) {
//cout << "YES" << endl;
if (steps - 1 > bestSteps) {
bestSteps = steps - 1;
}
return;
}


map[rowUp][col] = 2;
solve(rowUp, col, steps++);
map[rowUp][col] = 0;

map[row][colRight] = 2;
solve(row, colRight, steps++);
map[row][colRight] = 0;

map[rowDown][col] = 2;
solve(rowDown, col, steps++);
map[rowDown][col] = 0;

map[row][colLeft] = 2;
solve(row, colLeft, steps++);
map[row][colLeft] = 0;
*/