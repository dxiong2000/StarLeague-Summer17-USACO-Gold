// silvlily.cpp 

#include <iostream>
using namespace std;
int rows, col, map[30][30], startX, startY;

int main()
{
	cin >> rows >> col;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < col; j++) {
			int input;
			cin >> input;
			map[i][j] = input;
			if (input == 3) {
				startX = j;
				startY = i;
			}
		}
	}



    return 0;
}

