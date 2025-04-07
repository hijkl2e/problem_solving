#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int x{};
		for (int j = 0; j < N; ++j) {
			int y{};
			cin >> y;
			x |= y;
		}
		cout << x << (i == N - 1 ? "\n" : " ");
	}
	return 0;
}
