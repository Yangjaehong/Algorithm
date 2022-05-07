
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
# define N 5

int map[N][N];

vector<int> v;  

int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };

// 재귀함수
void recursive(int x, int y, int num, int len) {
	
	if (len == 6) { // 숫자가 여섯자리가 된 경우
		v.push_back(num);
		return;
	}

	for (int k = 0; k < 4; k++) { // 인접한 곳으로 이동
		int nx = x + dx[k];
		int ny = y + dy[k];

		if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
			recursive(nx, ny, num * 10 + map[nx][ny], len + 1); 
		}
	}
}

int main() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			recursive(i, j, map[i][j], 1); // 시작점 : map[i][j], 시작할 때 길이 : 1
		}
	}

	// 벡터 중복 값 제거
	sort(v.begin(), v.end()); // 정렬
	v.erase(unique(v.begin(), v.end()), v.end()); // 제거

	cout << v.size() << '\n';

	return 0;
}