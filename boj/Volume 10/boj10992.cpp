#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cout << string(N - 1, ' ') << "*\n";
	for (int i = 1; i < N - 1; ++i) {
		cout << string(N - i - 1, ' ') << "*" << string(2 * i - 1, ' ') << "*\n";
	}
	if (N > 1) {
		cout << string(2 * N - 1, '*') << "\n";
	}
	return 0;
}
