#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n{}, m{}, s{}, d{};
	cin >> n >> m >> s >> d;
	vector<ii> A(s);
	for (int i = 0; i < s; ++i) {
		cin >> A[i].first;
		A[i].second = i;
	}
	sort(A.begin(), A.end());
	for (int i = 0; i < s; ++i) {
		if (n) {
			A[i].first = min(d - A[i].first, n);
			n -= A[i].first;
		} else {
			m -= min(A[i].first, m);
			A[i].first = 0;
		}
	}
	if (m) {
		cout << "impossible\n";
		return 0;
	}
	vector<int> B(s);
	for (int i = 0; i < s; ++i) {
		B[A[i].second] = A[i].first;
	}
	for (int i = 0; i < s; ++i) {
		cout << B[i] << (i == s - 1 ? "\n" : " ");
	}
	return 0;
}
