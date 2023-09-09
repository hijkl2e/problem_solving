#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	while (cin >> N, N) {
		for (int i = 1; i <= N; ++i) {
			cout << string(i, '*') << "\n";
		}
	}
	return 0;
}
