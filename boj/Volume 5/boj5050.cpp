#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int C{}, N{}, A{};
	cin >> C >> N >> A;
	vector<int> B(A);
	for (int i = 0; i < A; ++i) {
		cin >> B[i];
	}
	vector<int> next(N, 1e9);
	vector<int> D(A);
	for (int i = A - 1; i >= 0; --i) {
		D[i] = next[B[i]];
		next[B[i]] = i;
	}
	set<ii> S;
	deque<bool> inc(N);
	int ans{};
	for (int i = 0; i < A; ++i) {
		if (inc[B[i]]) {
			S.erase(S.find({i, B[i]}));
			S.insert({D[i], B[i]});
			continue;
		}
		if (S.size() == C) {
			auto it = --S.end();
			inc[it->second] = false;
			S.erase(it);
		}
		S.insert({D[i], B[i]});
		inc[B[i]] = true;
		++ans;
	}
	cout << ans << "\n";
	return 0;
}
