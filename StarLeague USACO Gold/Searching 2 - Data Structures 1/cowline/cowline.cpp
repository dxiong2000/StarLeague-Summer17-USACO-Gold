// cowline.cpp 

#include <iostream>
#include <string>
#include <cmath>
using namespace std;



int main()
{
	int s, currentcow(1), ans(0);
	cin >> s;

	for (int i = 0; i < s; i++) {
		string input;
		getline(cin,input);

		int size = input.size();
		int sideEnter; // 0 = left 1 = right
		int sideLeave, k;

		if (size == 3) { // determines whether cow arrives on left or right side
			if (input[2] == 'L'){ // left
				sideEnter = 0;
	
			}
			else {				  // right
				sideEnter = 1;
			
			}
		}
		if (size == 5) { // determines whether cow leaves from left or right side and how many 
			k = input[4] - 48;

			if (input[2] == 'L') { // left
				sideLeave = 0;

			}
			else {				  // right
				sideLeave = 1;
			}
		}

	



	}

    return 0;
}

