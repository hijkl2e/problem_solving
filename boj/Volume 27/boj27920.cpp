#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cout << "YES\n";
	for (int i = 0; i < N; ++i) {
		int x = i == N / 2 ? N : i < N / 2 ? (N - 2 * i - 1) : (2 * (i - N / 2) - N % 2);
		cout << x << (i == N - 1 ? "\n" : " ");
	}
	for (int i = 0; i < N; ++i) {
		int x = i % 2 ? (N - i / 2) : (i / 2 + 1);
		cout << x << (i == N - 1 ? "\n" : " ");
	}
	return 0;
}
