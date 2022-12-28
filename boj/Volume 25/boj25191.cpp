#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, A{}, B{};
	cin >> N >> A >> B;
	int ans = min(N, A / 2 + B);
	cout << ans << "\n";
	return 0;
}
