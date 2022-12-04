#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using il = pair<ll, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<il> A(N);
	vector<il> D(N);
	vector<il> H(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i].first >> D[i].first >> H[i].first;
		A[i].second = D[i].second = H[i].second = i;
	}
	set<int> S;
	sort(A.rbegin(), A.rend());
	for (int i = 0; i < K; ++i) {
		S.insert(A[i].second);
	}
	sort(D.rbegin(), D.rend());
	for (int i = 0; i < K; ++i) {
		S.insert(D[i].second);
	}
	sort(H.rbegin(), H.rend());
	for (int i = 0; i < K; ++i) {
		S.insert(H[i].second);
	}
	cout << S.size() << "\n";
	return 0;
}
