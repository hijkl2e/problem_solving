#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll solve(string &S) {
	ll ret{};
	for (int i = 1; i <= S.size(); ++i) {
		if (S[S.size() - i] == '1') {
			ret = (1LL << i) - ret - 1;
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	string A{}, B{};
	cin >> N >> A >> B;
	ll ans = solve(B) - solve(A) - 1;
	cout << ans << "\n";
	return 0;
}
