#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	int x1{}, y1{}, x2{}, y2{};
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			int k{};
			cin >> k;
			if (k == 1) {
				x1 = i, y1 = j;
				swap(x1, x2);
				swap(y1, y2);
			}
		}
	}
	int ans = abs(x2 - x1) + abs(y2 - y1);
	cout << ans << "\n";
	return 0;
}
