#include <bits/stdc++.h>

using namespace std;

using ll = long long;

vector<int> A, C;
vector<ll> B;

void solve(int step, int wgt) {
	if (wgt >= 200) {
		for (int x : C) {
			B[x] += 1LL << (A.size() - step);
		}
		for (int i = step; i < A.size(); ++i) {
			B[i] += 1LL << (A.size() - step - 1);
		}
		return;
	} else if (step == A.size()) {
		return;
	}
	for (int i = step; i < A.size(); ++i) {
		C.push_back(i);
		solve(i + 1, wgt + A[i]);
		C.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	A.resize(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	B.resize(N);
	solve(0, 0);
	ll ans{};
	for (int i = 0; i < N; ++i) {
		ans += A[i] * B[i];
	}
	cout << ans << "\n";
	return 0;
}
