#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<int> A(N);
	vector<int> B(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i] >> B[i];
	}
	int s{}, e{}, maxl{};
	multiset<int> S, E;
	vector<ii> C;
	while (e < N) {
		S.insert(A[e]);
		E.insert(B[e]);
		++e;
		while (*--S.end() > *E.begin()) {
			S.erase(S.find(A[s]));
			E.erase(E.find(B[s]));
			++s;
		}
		if (maxl < e - s) {
			maxl = e - s;
			C.clear();
		}
		if (maxl == e - s) {
			C.push_back({*--S.end(), *E.begin()});
		}
	}
	sort(C.begin(), C.end());
	int cnt{}, r{};
	for (auto &[u, v] : C) {
		cnt += max(v - max(u - 1, r), 0);
		r = max(r, v);
	}
	cout << maxl << " " << cnt << "\n";
	return 0;
}
