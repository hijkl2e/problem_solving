#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	if (N % 2 == 0) {
		cout << "I LOVE CBNU\n";
		return 0;
	}
	cout << string(N, '*') << "\n";
	cout << string(N / 2, ' ') << "*\n";
	for (int i = 0; i < N / 2; ++i) {
		cout << string(N / 2 - i - 1, ' ') << "*" << string(2 * i + 1, ' ') << "*\n";
	}
	return 0;
}
