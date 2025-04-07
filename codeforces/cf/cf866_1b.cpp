#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<ll, ll>;

ii solve(vector<ii> &A) {
	int n = A.size();
	ll sum{};
	for (int i = 0; i < n; ++i) {
		sum += A[i].first * A[i].second;
	}
	ll r{};
	for (int i = 0; i < n; ++i) {
		r = max(r, A[i].first);
	}
	if (sum % r) {
		return {-1, -1};
	}
	ll c = sum / r;
	ii ret = {r, c};
	multiset<ii> s1, s2;
	for (int i = 0; i < n; ++i) {
		s1.insert(A[i]);
		s2.insert({A[i].second, A[i].first});
	}
	while (s1.size()) {
		auto it = s1.lower_bound({r, -1});
		if (it == s1.end() || it->first > r) {
			return {-1, -1};
		}
		while (it != s1.end() && it->first == r) {
			c -= it->second;
			s2.erase(s2.find({it->second, it->first}));
			it = s1.erase(it);
		}
		swap(r, c);
		swap(s1, s2);
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		vector<ii> A(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i].first >> A[i].second;
		}
		vector<ii> B;
		ii res = solve(A);
		if (res.first != -1) {
			B.push_back(res);
		}
		for (int i = 0; i < N; ++i) {
			swap(A[i].first, A[i].second);
		}
		res = solve(A);
		swap(res.first, res.second);
		if (res.first != -1 && (B.empty() || B[0] != res)) {
			B.push_back(res);
		}
		cout << B.size() << "\n";
		for (int i = 0; i < B.size(); ++i) {
			cout << B[i].first << " " << B[i].second << "\n";
		}
	}
	return 0;
}
