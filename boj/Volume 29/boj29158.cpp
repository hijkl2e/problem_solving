#include <bits/stdc++.h>

using namespace std;

using ll = long long;

string solve(ll x) {
	vector<string> A;
	for (ll i = 2; i * i <= x; ++i) {
		while (x % i == 0) {
			A.push_back(to_string(i));
			x /= i;
		}
	}
	if (x > 1) {
		A.push_back(to_string(x));
	}
	sort(A.begin(), A.end(), [](string &s1, string &s2) {
		return s1 + s2 > s2 + s1;
	});
	return accumulate(A.begin(), A.end(), string(""));
}

string add(string a, string b) {
	string ret(max(a.size(), b.size()) + 1, '0');
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	copy(a.begin(), a.end(), ret.begin());
	for (int i = 0; i < ret.size(); ++i) {
		if (i < b.size()) {
			ret[i] += b[i] - '0';
		}
		if (ret[i] > '9') {
			ret[i] -= 10;
			++ret[i + 1];
		}
	}
	if (ret.back() == '0') {
		ret.pop_back();
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N{};
	cin >> N;
	if (N == 2) {
		cout << "3\n";
		return 0;
	}
	ll K = 2;
	for (int i = 0; K + (1LL << (i / 2)) < N; ++i) {
		K += 1LL << (i / 2);
	}
	cout << add(solve(N), solve(K)) << "\n";
	return 0;
}
