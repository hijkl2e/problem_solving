#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		cout << string(M / N + (i < M % N), '*') << "\n";
	}
	return 0;
}
