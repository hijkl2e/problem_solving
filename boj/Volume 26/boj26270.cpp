#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;
using query = tuple<int, int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{}, Q{};
	cin >> N >> K >> Q;
	vector<int> A(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}
	vector<vector<int>> B(N + 1);
	for (int i = 1; i <= N; ++i) {
		B[A[i]].push_back(i);
	}
	vector<ii> C;
	for (int i = 1; i <= N; ++i) {
		for (int j = K - 1; j < B[i].size(); ++j) {
			C.push_back({B[i][j], B[i][j - K + 1]});
		}
	}
	sort(C.begin(), C.end());
	vector<query> D(Q);
	for (int i = 0; i < Q; ++i) {
		auto &[r, l, idx] = D[i];
		cin >> l >> r;
		idx = i;
	}
	sort(D.begin(), D.end());
	map<int, int> i2a;
	vector<int> E(Q);
	for (int i = 0, j = 0; i < Q; ++i) {
		auto &[r, l, idx] = D[i];
		while (j < C.size()) {
			auto &[b, a] = C[j];
			if (r < b) {
				break;
			}
			++j;
			if (i2a.size() && (--i2a.end())->first > a) {
				continue;
			}
			int len = b - a + 1;
			auto it = i2a.insert({a, len}).first;
			while (it != i2a.begin()) {
				if ((--it)->second < len) {
					break;
				}
				it = i2a.erase(it);
			}
		}
		auto it = i2a.lower_bound(l);
		E[idx] = it == i2a.end() ? -1 : it->second;
	}
	for (int i = 0; i < Q; ++i) {
		cout << E[i] << "\n";
	}
	return 0;
}
