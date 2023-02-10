#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cout << string(5 * N, '@') << "\n";
	}
	for (int i = 0; i < 3 * N; ++i) {
		cout << string(N, '@') << "\n";
	}
	for (int i = 0; i < N; ++i) {
		cout << string(5 * N, '@') << "\n";
	}
	return 0;
}
