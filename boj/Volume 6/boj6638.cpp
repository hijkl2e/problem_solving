#include <bits/stdc++.h>

using namespace std;

using ll = long long;

vector<ll> P;
ll X, Y;
set<ll> S;

void solve(int step, ll val) {
	if (Y < val) {
		return;
	} else if (X <= val && val <= Y) {
		S.insert(val);
	}
	for (int i = step; i < P.size(); ++i) {
		solve(i, val * P[i]);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	while (cin >> N, N) {
		P.resize(N);
		for (int i = 0; i < N; ++i) {
			cin >> P[i];
		}
		cin >> X >> Y;
		S.clear();
		solve(0, 1);
		if (S.empty()) {
			cout << "none\n";
		} else {
			auto it = S.begin();
			while (it != S.end()) {
				cout << *it;
				cout << (++it == S.end() ? "\n" : ",");
			}
		}
	}
	return 0;
}
