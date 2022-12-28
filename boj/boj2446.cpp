#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cout << string(i, ' ') << string(2 * (N - i) - 1, '*') << "\n";
	}
	for (int i = N - 2; i >= 0; --i) {
		cout << string(i, ' ') << string(2 * (N - i) - 1, '*') << "\n";
	}
	return 0;
}
