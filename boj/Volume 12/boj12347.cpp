#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<ll> A;
	for (int i = 1; i < 10; ++i) {
		A.push_back(i);
		for (int j = -i; i + j < 10; ++j) {
			string s = to_string(i);
			while (true) {
				char c = s.back() + j;
				if (isdigit(c) && s.size() < 18) {
					s += c;
				} else {
					break;
				}
				A.push_back(stoll(s));
			}
		}
	}
	sort(A.begin(), A.end());
	ll N{};
	cin >> N;
	int ans = upper_bound(A.begin(), A.end(), N) - A.begin();
	cout << ans << "\n";
	return 0;
}
