#include <bits/stdc++.h>

using namespace std;

using ll = long long;
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
	vector<ii> C, D;
	for (int i = 0; i < N; ++i) {
		if (A[i] < B[i]) {
			C.push_back({A[i], B[i] - A[i]});
		} else {
			D.push_back({B[i], A[i] - B[i]});
		}
	}
	sort(C.begin(), C.end());
	sort(D.begin(), D.end());
	bool yes = true;
	ll p{};
	for (auto &[u, v] : C) {
		if (p < u) {
			yes = false;
			break;
		}
		p += v;
	}
	for (auto &[u, v] : D) {
		p -= v;
	}
	yes &= p >= 0;
	for (auto &[u, v] : D) {
		if (p < u) {
			yes = false;
			break;
		}
		p += v;
	}
	cout << yes << "\n";
	return 0;
}
