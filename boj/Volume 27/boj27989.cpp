#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<ll> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	map<ll, ll> B;
	B[0] = 0;
	for (int i = 0; i < N; ++i) {
		auto it = --B.lower_bound(A[i]);
		ll val = it->second + A[i];
		it = B.insert({A[i], 0}).first;
		(it++)->second = val;
		while (it != B.end() && val >= it->second) {
			it = B.erase(it);
		}
	}
	cout << (--B.end())->second << "\n";
	return 0;
}
