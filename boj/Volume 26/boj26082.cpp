#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int A{}, B{}, C{};
	cin >> A >> B >> C;
	int ans = 3 * B * C / A;
	cout << ans << "\n";
	return 0;
}
