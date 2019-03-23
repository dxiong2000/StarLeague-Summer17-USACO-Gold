// perimeter.cpp 

#include <iostream>
#include <queue>
#include <utility>
#include <set>
#define pii pair<int,int>
int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int dy[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };
using namespace std;
int n, perimeter(0);
queue<pii> q;
set<pii> s;

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		s.insert({ x,y });
	}

	set<pii>::iterator it;

	q.push({ s.begin()->first,s.begin()->second - 1 }); // starting point is the space above the topmost haybale

	int sx(s.begin()->first), sy(s.begin()->second - 1);
	
	cout << q.front().first << " " << q.front().second << endl;

	int x = 0;
	int y = 0;
	while (x!=sx && y!=sy) {
		
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int j = 0; j < 8; j++) {
			int x1 = x + dx[j];
			int y1 = y + dy[j];
			if (s.find({ x1,y1 }) == s.end()) {
				for (int i = 0; i < 8; i++) {
					if (s.find({ (x1 + dx[i]),(y1 + dy[i]) }) != s.end()) { // 
						q.push({ x1,y1 });
						break;
					}
				}
			}
		}

		perimeter++;


		//cout << q.front().first << " " << q.front().second << endl;

	}

	cout << perimeter << endl;

    return 0;
}

//bool balesNearby(int x, int y) {
//	if (s.find({ x + up,y }) != s.end()) { // if the space above is not shaded
//		return true;
//	}
//
//	if (s.find({ x + up,y + right }) != s.end()) {
//		return true;
//	}
//
//	if (s.find({ x,y + right }) != s.end()) {
//		return true;
//	}
//
//	if (s.find({ x + down,y + right }) != s.end()) {
//		return true;
//	}
//
//	if (s.find({ x + down,y }) != s.end()) {
//		return true;
//	}
//
//	if (s.find({ x + down,y + left }) != s.end()) {
//		return true;
//	}
//
//	if (s.find({ x,y + left }) != s.end()) {
//		return true;
//	}
//
//	if (s.find({ x + up,y + left }) != s.end()) {
//		return true;
//	}
//
//	return false;
//}
