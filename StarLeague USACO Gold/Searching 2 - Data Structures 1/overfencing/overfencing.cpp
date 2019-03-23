// overfencing.cpp 

#include <iostream>
#include <string>
using namespace std;
int row1, col1, row2, col2, beststeps(10000);
int arr[100][38];

void solve(int row, int col, int steps) {
	int left = col - 1;
	int up = row - 1;
	int right = col + 1;
	int down = row + 1;

	if (arr[row][left] == 0) {
		arr[row][col] = 3;
		solve(row, left, steps++);
		arr[row][col] = 0;
	}
	if (arr[up][col] == 0) {
		arr[row][col] = 3;
		solve(up, col, steps++);
		arr[row][col] = 0;
	}
	if (arr[row][right] == 0) {
		arr[row][col] = 3;
		solve(row, right, steps++);
		arr[row][col] = 0;
	}
	if (arr[down][col] == 0) {
		arr[row][col] = 3;
		solve(down, col, steps++);
		arr[row][col] = 0;
	}
	else {
		if (steps < beststeps) {
			beststeps = steps;
		}
		
		return;
	}

}

int main()
{
	int width, height, a(0);
	
	cin >> width >> height;
	
	string str; // extra getline after 2 cin because for some reason getline gets the rest of the cin line
	getline(cin, str);

	int inputW = 2 * width + 1;
	int inputH = 2 * height + 1;

	string line;
	for (int i = 0; i < inputH; i++) { // 0 =path ; 1 = wall ; 2 = exit
		getline(cin, line);
		for (int j = 0; j < inputW; j++) {
			if (line[j] == '+' || line[j] == '-' || line[j] == '|') { 
				arr[i][j] = 1;
			}
			if (line[j] == ' ') {
				if (i == 0 || i == inputH - 1 || j == 0 || j == inputW - 1) {
					arr[i][j] = 2;
					if (a == 0) {
						row1 = i;
						col1 = j;
						a = 1;
					}
					if (a == 1) {
						row2 = i;
						col2 = j;
					}
				}
				else{
					arr[i][j] = 0;
				}
			}
		}
	}

//	solve(row1, col1, 0);
//	solve(row2, col2, 0);

	cout << beststeps << endl;

    return 0;
}

