#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	for (int i = 1; i <= M; ++i) {
		cout << "0 " << i << "\n";
	}
	for (int i = M; i < N - 1; ++i) {
		cout << i << " " << i + 1 << "\n";
	}
	return 0;
}
