#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int A{}, B{}, C{};
	cin >> A >> B >> C;
	int ans = B < C ? A / (C - B) + 1 : -1;
	cout << ans << "\n";
	return 0;
}
