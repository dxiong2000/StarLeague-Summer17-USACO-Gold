// meteor.cpp

#include <iostream>
using namespace std;
int numM;
int map[300][300]; 

struct meteor {
	int xpos, ypos, time;
};

void floodfill(int xpos, int ypos, int x) {
	if (xpos < 0 || xpos>300 || ypos < 0 || ypos>300) {
		return;
	}

	if(xpos+1)
	floodfill(xpos + 1, ypos, x++);
	floodfill(xpos - 1, ypos, x++);
	floodfill(xpos, ypos + 1, x++);
	floodfill(xpos, ypos - 1, x++);
}

int main()
{
	cin >> numM;
	meteor arr[50000];
	for (int i = 0; i < numM; i++) { //reads coords into array
		cin >> arr[i].xpos >> arr[i].ypos >> arr[i].time;
	}

	floodfill(0, 0, 0);

    return 0;
}

