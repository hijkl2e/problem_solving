#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, T{};
	cin >> N >> T;
	vector<ii> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i].first >> A[i].second;
	}
	sort(A.begin(), A.end());
	vector<int> C(N);
	for (int i = 0; i < N; ++i) {
		C[i] = A[i].second;
	}
	vector<ii> F;
	vector<int> B(N);
	int min_c = INF;
	bool yes = true;
	for (int i = N - 1; i >= 0; --i) {
		auto &[ri, di] = A[i];
		for (int j = 0; j < N; ++j) {
			auto &[rj, dj] = A[j];
			if (dj < di) {
				continue;
			}
			C[j] -= T;
			while (B[j] < F.size() && C[j] < F[B[j]].second) {
				C[j] = min(C[j], F[B[j]++].first);
			}
			min_c = min(min_c, C[j]);
		}
		if (i == 0 || A[i - 1].first < ri) {
			if (min_c < ri) {
				yes = false;
				break;
			}
			if (min_c < ri + T) {
				F.push_back({min_c - T, ri});
			}
		}
	}
	cout << (yes ? "yes" : "no") << "\n";
	return 0;
}
