#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	if (N > M) {
		swap(N, M);
	}
	for (int i = N + 1; i <= M + 1; ++i) {
		cout << i << "\n";
	}
	return 0;
}
