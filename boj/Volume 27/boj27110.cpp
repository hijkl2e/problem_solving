#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, A{}, B{}, C{};
	cin >> N >> A >> B >> C;
	int ans = min(N, A) + min(N, B) + min(N, C);
	cout << ans << "\n";
	return 0;
}
