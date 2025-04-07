#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	for (int k = 0; k < 5; ++k) {
		for (int i = 0; i < N; ++i) {
			cout << string((k % 2 ? 1 : 5) * N, '@') << "\n";
		}
	}
	return 0;
}
