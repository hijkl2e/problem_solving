#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int convert(string &t) {
	istringstream iss(t);
	int h{}, m{}, s{};
	char c{};
	iss >> h >> c >> m >> c >> s;
	return 3600 * h + 60 * m + s;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<ll> A(86401);
	while (--N) {
		int q{};
		string s1, s2;
		cin >> q >> s1 >> s2;
		int t1 = convert(s1);
		int t2 = convert(s2);
		++A[t1 + 1], --A[t2 + 1];
	}
	for (int k = 0; k < 2; ++k) {
		for (int i = 1; i < A.size(); ++i) {
			A[i] += A[i - 1];
		}
	}
	int q{};
	string s;
	cin >> q >> s;
	int t = convert(s);
	ll ans{};
	for (int i = t; i < A.size(); ++i) {
		ans = max(ans, A[i] - A[i - t]);
	}
	cout << ans << "\n";
	return 0;
}
