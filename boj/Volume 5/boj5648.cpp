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
		string s;
		cin >> s;
		reverse(s.begin(), s.end());
		A[i] = stoll(s);
	}
	sort(A.begin(), A.end());
	for (ll x : A) {
		cout << x << "\n";
	}
	return 0;
}
