// invite.cpp 

#include <iostream>
using namespace std;
int n, groups;

struct group {
	int groupNum, cowID;
}arr[250000];

int main()
{
	cin >> n >> groups;
	for (int i = 0; i < groups; i++) {
		int cows; 
		cin >> cows;
		for (int j = 0; i < cows; j++) {
			arr[j].groupNum = i + 1;
			cin >> arr[j].cowID;
		}
	}




    return 0;
}

