#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, Q{};
	cin >> N >> Q;
	for (int i = 0; i < Q; ++i) {
		cout << N + i % 2 - 1 << "\n";
	}
	return 0;
}
