#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	for (int k = 0; k < 5; ++k) {
		for (int i = 0; i < N; ++i) {
			cout << string(N, '@') << string(3 * N, k % 2 ? '@' : ' ') << string(N, '@') << "\n";
		}
	}
	return 0;
}
