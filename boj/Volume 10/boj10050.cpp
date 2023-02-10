#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

vector<vector<int>> A{
	{}, {}, {},
	{2, 5, 3},
	{6, 3, 0, 7},
	{8, 3, 6, 0, 9},
	{10, 7, 2, 6, 0, 11},
	{12, 5, 8, 3, 9, 0, 13}
};
vector<ii> B;

void solve(int N, int s) {
	if (N < 8) {
		for (int i = 0; i < N; ++i) {
			int x = s + A[N][i];
			int y = s + (N == 3 && i == 2 ? -3 : i == 0 ? -1 : A[N][i - 1]);
			B.push_back({x, y});
		}
		return;
	}
	B.push_back({s + 2 * N - 2, s - 1});
	B.push_back({s + 3, s + 2 * N - 2});
	solve(N - 4, s + 4);
	B.push_back({s, s + 2 * N - 5});
	B.push_back({s + 2 * N - 1, s});
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	solve(N, 0);
	for (auto &p : B) {
		cout << p.first << " to " << p.second << "\n";
	}
	return 0;
}
