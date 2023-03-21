#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int E{}, S{}, M{};
	cin >> E >> S >> M;
	int e{}, s{}, m{}, ans{};
	e = s = m = ans = 1;
	while (E != e || S != s || M != m) {
		e = e % 15 + 1;
		s = s % 28 + 1;
		m = m % 19 + 1;
		++ans;
	}
	cout << ans << "\n";
	return 0;
}
