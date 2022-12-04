#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int A{}, I{};
	cin >> A >> I;
	int ans = A * (I - 1) + 1;
	cout << ans << "\n";
	return 0;
}
