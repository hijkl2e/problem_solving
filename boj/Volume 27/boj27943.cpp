#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N{};
	cin >> N;
	cout << "? " << (N + 1) / 2 << endl;
	string g;
	cin >> g;
	ll lo = 0, hi = (N + 1) / 2;
	while (lo + 1 < hi) {
		ll mid = (lo + hi) / 2;
		cout << "? " << mid << endl;
		string s;
		cin >> s;
		if (s == g) {
			hi = mid;
		} else {
			lo = mid;
		}
	}
	ll a = hi;
	lo = (N + 1) / 2, hi = N + 1;
	while (lo + 1 < hi) {
		ll mid = (lo + hi) / 2;
		cout << "? " << mid << endl;
		string s;
		cin >> s;
		if (s == g) {
			lo = mid;
		} else {
			hi = mid;
		}
	}
	ll b = lo;
	cout << "! " << a << " " << b << endl;
	return 0;
}
