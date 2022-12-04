#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using rec = tuple<ll, int, string>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<rec> A(N);
	for (int i = 0; i < N; ++i) {
		auto &[f, idx, name] = A[i];
		cin >> f >> name;
		f *= -(i + 1);
		idx = i;
	}
	sort(A.begin(), A.end());
	for (int i = 0; i < M; ++i) {
		auto &[f, idx, name] = A[i];
		cout << name << "\n";
	}
	return 0;
}
