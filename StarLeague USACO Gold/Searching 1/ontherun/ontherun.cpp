// ontherun.cpp 

#include <iostream>
#include <cmath>
using namespace std;

int n, start, arr[1000], mark[1000], best(1000000); //arr is pos of grass

void func(int curpos, int oldpos, int eaten, int staleness, int c, int time) {
	if (eaten == n) {
		if (staleness < best) {
			best = staleness;
		}
	//	cout << staleness << endl;
		return;
	}
	time += abs(curpos - oldpos);
	for (int i = c +1; i <= n; i++) {
		
		func(arr[c+1], arr[c], eaten + 1, staleness + time, c+1, time);
	//	func(arr[c + 2], eaten + 1, staleness + time, c + 2, time);
	}

}
	
int main()
{
	cin >> n >> start;
	arr[0] = start;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	func(start, start, 0, 0,0, 0);

	cout << best << endl;

    return 0;
}

