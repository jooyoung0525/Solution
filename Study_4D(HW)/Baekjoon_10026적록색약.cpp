#include<iostream>
#include<vector>
#include<string>

using namespace std;

//적록색약은 빨강 == 초록 (같은구역)
//N*N배열
//R,G,B중 구역의 색
//DFS=> map을 돌면서 체크안한곳 방문 -> 이어지는곳 탐색

int N;
char map[110][110] = { 0 };
bool check[110][110] = { 0 };
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
bool second = false;
vector<int>result;

void input();
void Find();

int main()
{
	input();
	Find();
	Find();

	for (int i = 0; i < 2; i++)
	{
		cout << result[i] << " ";
	}

	return 0;
}

void DFS(int curx,int cury, char now)
{
	for (int i = 0; i < 4; i++) {

		int nx = curx + dx[i];
		int ny = cury + dy[i];

		if (nx < 0 || ny < 0 || nx >= N || ny >= N)continue;
		if (second == false) 
		{
			if (check[nx][ny] == false && now == map[nx][ny])
			{
				check[nx][ny] = true;
				DFS(nx, ny, map[nx][ny]);
			}
		}
		if (second == true)
		{
			if (check[nx][ny] == false)
			{
				if (now == 'R' && (map[nx][ny] == 'G' || map[nx][ny] == 'R')) {
					check[nx][ny] = true;
					DFS(nx, ny, map[nx][ny]);
				}
				if (now == 'G' && (map[nx][ny] == 'G' || map[nx][ny] == 'R')) {
					check[nx][ny] = true;
					DFS(nx, ny, map[nx][ny]);
				}
				if (now == 'B' && map[nx][ny] == 'B') {
					check[nx][ny] = true;
					DFS(nx, ny, map[nx][ny]);
				}
			}
		}
	}
}
void input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
		}
	}
}

void Find()
{
	int cnt = 0;
	memset(check, 0, sizeof(check));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (check[i][j] == 0) {
				DFS(i, j, map[i][j]);
				cnt++;
			}
		}
	}

	result.push_back(cnt);
	second = true;
}
