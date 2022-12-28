#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cout << string(N, '*') << string(2 * N - 3, ' ') << string(N, '*') << "\n";
	for (int i = 1; i < N; ++i) {
		cout << string(i, ' ') << "*" << string(N - 2, ' ') << "*";
		if (i < N - 1) {
			cout << string(2 * (N - i) - 3, ' ') << "*";
		}
		cout << string(N - 2, ' ') << "*\n";
	}
	for (int i = N - 2; i > 0; --i) {
		cout << string(i, ' ') << "*" << string(N - 2, ' ') << "*";
		cout << string(2 * (N - i) - 3, ' ') << "*" << string(N - 2, ' ') << "*\n";
	}
	cout << string(N, '*') << string(2 * N - 3, ' ') << string(N, '*') << "\n";
	return 0;
}
