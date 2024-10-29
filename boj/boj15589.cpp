#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	vector<int> B(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i] >> B[i];
	}
	vector<ii> C;
	for (int i = 0; i < N; ++i) {
		C.push_back({A[i], 1});
		C.push_back({B[i], -1});
	}
	sort(C.begin(), C.end());
	vector<int> D, E;
	D.push_back(0);
	E.push_back(0);
	for (int i = 0; i < C.size(); ++i) {
		if (C[i].first != D.back()) {
			D.push_back(C[i].first);
			E.push_back(E.back());
		}
		E.back() += C[i].second;
	}
	vector<ii> F;
	int ans{};
	for (int i = 0; i + 1 < D.size(); ++i) {
		if (E[i]) {
			ans += D[i + 1] - D[i];
			if (E[i] == 1) {
				F.push_back({D[i], D[i + 1]});
			}
		}
	}
	int minv = 1e9;
	for (int i = 0; i < N; ++i) {
		auto it = upper_bound(F.begin(), F.end(), make_pair(A[i], -1));
		if (it != F.begin()) {
			--it;
		}
		int cnt{};
		while (it != F.end() && it->first < B[i]) {
			int s = max(A[i], it->first);
			int e = min(B[i], it->second);
			cnt += max(e - s, 0);
			++it;
		}
		minv = min(minv, cnt);
	}
	ans -= minv;
	cout << ans << "\n";
	return 0;
}
