#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int L{}, M{};
	cin >> L >> M;
	cin.ignore();
	int minv = 1e9;
	vector<string> A;
	while (M--) {
		string n;
		ll p{}, c{}, t{}, r{};
		char d{};
		getline(cin, n, ',');
		cin >> p >> d >> c >> d >> t >> d >> r;
		cin.ignore();
		if (10080 * c * t / (t + r) >= L) {
			if (minv > p) {
				A.clear();
				A.push_back(n);
				minv = p;
			} else if (minv == p) {
				A.push_back(n);
			}
		}
	}
	if (A.empty()) {
		cout << "no such mower\n";
	} else {
		for (auto &s : A) {
			cout << s << "\n";
		}
	}
	return 0;
}
