#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<string> unit1{
		"thou", "inch", "foot", "yard", "chain", "furlong", "mile", "league"
	};
	vector<string> unit2{
		"th", "in", "ft", "yd", "ch", "fur", "mi", "lea"
	};
	map<string, int> u2i;
	for (int i = 0; i < unit1.size(); ++i) {
		u2i[unit1[i]] = i;
		u2i[unit2[i]] = i;
	}
	vector<int> A{1000, 12, 3, 22, 10, 8, 3};
	ll V;
	string u1, u2;
	cin >> V >> u1 >> u2;
	cin >> u2;
	int from = u2i[u1];
	int to = u2i[u2];
	bool flag = from > to;
	if (from > to) {
		swap(from, to);
	}
	ll x = 1;
	for (int i = from; i < to; ++i) {
		x *= A[i];
	}
	if (flag) {
		cout << V * x << "\n";
	} else {
		cout << fixed << setprecision(15);
		cout << V * 1.0 / x << "\n";
	}
	return 0;
}
