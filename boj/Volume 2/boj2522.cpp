#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	for (int i = 1; i < N; ++i) {
		cout << string(N - i, ' ') << string(i, '*') << "\n";
	}
	for (int i = N; i > 0; --i) {
		cout << string(N - i, ' ') << string(i, '*') << "\n";
	}
	return 0;
}
