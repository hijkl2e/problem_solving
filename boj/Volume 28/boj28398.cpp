#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

set<ii> S;
int ans;

int count(const ii &p) {
	return (p.second - p.first) / 2 + 1;
}

void insert(int x) {
	int l = x, r = x;
	auto it = S.lower_bound({x, x});
	if (it != S.end() && it->first == x + 1) {
		r = it->second;
		ans -= count(*it);
		it = S.erase(it);
	}
	if (it != S.begin() && (--it)->second == x - 1) {
		l = it->first;
		ans -= count(*it);
		it = S.erase(it);
	}
	it = S.insert(it, {l, r});
	ans += count(*it);
}

void erase(int x) {
	auto it = --S.lower_bound({x + 1, -1});
	int l = it->first, r = it->second;
	if (x < r) {
		S.insert(it, {x + 1, r});
		ans += count({x + 1, r});
	}
	if (l < x) {
		S.insert(it, {l, x - 1});
		ans += count({l, x - 1});
	}
	ans -= count(*it);
	S.erase(it);
}

void solve(int &f, int &s, int x, int y) {
	if (f + 1 < s) {
		erase(f);
	}
	if (f == x) {
		f = y;
	} else {
		s = y;
	}
	if (f > s) {
		swap(f, s);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, Q{};
	cin >> N >> Q;
	vector<int> A(2 * N);
	for (int i = 0; i < A.size(); ++i) {
		cin >> A[i];
	}
	vector<ii> B(N + 1, {-1, -1});
	for (int i = 0; i < A.size(); ++i) {
		if (B[A[i]].first == -1) {
			B[A[i]].first = i;
		} else {
			B[A[i]].second = i;
		}
	}
	ans = N;
	for (int i = 1; i <= N; ++i) {
		if (B[i].first + 1 < B[i].second) {
			insert(B[i].first);
		}
	}
	cout << ans << "\n";
	while (Q--) {
		int l{}, r{};
		cin >> l >> r;
		--l, --r;
		if (A[l] == A[r]) {
			cout << ans << "\n";
			continue;
		}
		auto &[lf, ls] = B[A[l]];
		auto &[rf, rs] = B[A[r]];
		swap(A[l], A[r]);
		solve(lf, ls, l, r);
		solve(rf, rs, r, l);
		if (lf + 1 < ls) {
			insert(lf);
		}
		if (rf + 1 < rs) {
			insert(rf);
		}
		cout << ans << "\n";
	}
	return 0;
}
