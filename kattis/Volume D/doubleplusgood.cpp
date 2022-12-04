#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	istringstream iss(S);
	vector<ll> A;
	while (getline(iss, S, '+')) {
		A.push_back(stoll(S));
	}
	vector<ll> B;
	for (int i = 0; i < (1 << A.size()); i += 2) {
		ll x{}, y = A[0];
		for (int j = 1; j < A.size(); ++j) {
			if ((i >> j) & 1) {
				y = stoll(to_string(y) + to_string(A[j]));
			} else {
				x += y;
				y = A[j];
			}
		}
		x += y;
		B.push_back(x);
	}
	sort(B.begin(), B.end());
	B.resize(unique(B.begin(), B.end()) - B.begin());
	cout << B.size() << "\n";
	return 0;
}
