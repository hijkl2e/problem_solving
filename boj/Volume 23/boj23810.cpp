#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	for (int k = 0; k < 5; ++k) {
		for (int i = 0; i < N; ++i) {
			cout << string((k == 0 || k == 2 ? 5 : 1) * N, '@') << "\n";
		}
	}
	return 0;
}
