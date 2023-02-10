#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	for (int k = 0; k < 5; ++k) {
		for (int i = 0; i < N; ++i) {
			cout << string(N, '@') << string(N * (abs(k - 2) + 1), k == 2 ? '@' : ' ');
			cout << string(N, '@') << "\n";
		}
	}
	return 0;
}
