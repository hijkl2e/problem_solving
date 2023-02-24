#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<int> A(N + 1);
	while (M--) {
		int a{}, b{}, c{};
		cin >> a >> b >> c;
		for (int i = a; i <= b; ++i) {
			A[i] = c;
		}
	}
	for (int i = 1; i <= N; ++i) {
		cout << A[i] << (i == N ? "\n" : " ");
	}
	return 0;
}
