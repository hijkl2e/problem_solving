#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int prev_x{};
	for (int i = 0; i < N; ++i) {
		int x{};
		cin >> x;
		for (int j = prev_x + 1; j < x; ++j) {
			cout << j << "\n";
		}
		prev_x = x;
	}
	if (prev_x == N) {
		cout << "good job\n";
	}
	return 0;
}
