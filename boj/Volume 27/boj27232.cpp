#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	set<ii> S;
	for (int i = 0; i < K; ++i) {
		S.insert({A[i], i});
	}
	ll now{}, x = S.begin()->second;
	for (auto &p : S) {
		now += abs(x - p.second);
		x = p.second;
	}
	ll ans = now;
	for (int i = K; i < N; ++i) {
		auto it = S.insert({A[i], i}).first;
		if (next(it) != S.end()) {
			now += abs(next(it)->second - i);
		}
		if (it != S.begin()) {
			now += abs(prev(it)->second - i);
		}
		if (next(it) != S.end() && it != S.begin()) {
			now -= abs(next(it)->second - prev(it)->second);
		}
		it = S.erase(S.find({A[i - K], i - K}));
		if (it != S.end()) {
			now -= abs(it->second - (i - K));
		}
		if (it != S.begin()) {
			now -= abs(prev(it)->second - (i - K));
		}
		if (it != S.end() && it != S.begin()) {
			now += abs(it->second - prev(it)->second);
		}
		ans = min(ans, now);
	}
	cout << ans << "\n";
	return 0;
}
