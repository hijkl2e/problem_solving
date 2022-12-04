#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<int> D(N + 1);
	while (M--) {
		int a{}, b{};
		cin >> a >> b;
		++D[a];
		++D[b];
	}
	for (int i = 1; i <= N; ++i) {
		cout << (D[i] - i) << (i == N ? "\n" : " ");
	}
	return 0;
}
