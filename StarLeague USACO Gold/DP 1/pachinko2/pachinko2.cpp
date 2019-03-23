// pachinko2.cpp 

#include <iostream>
using namespace std;
int rows, pk[100][100], best(0);

void solve(int row, int col, int x) {
	if (row == rows) {
		if (x > best) {
			best = x;
		}
		return;
	}
	x += pk[row][col];
	solve(row + 1, col, x);
	solve(row + 1, col + 1, x);
}

int main()
{
	cin >> rows;
	int a = 1;
	for (int i = 0; i < rows; i++){
		for (int j = 0; j < a; j++) {
			cin >> pk[i][j];
		}
		a++;
	}

	solve(0, 0, 0);

	cout << best << endl;

    return 0;
}