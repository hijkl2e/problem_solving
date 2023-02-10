#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int A{}, B{}, V{};
	cin >> A >> B >> V;
	int ans = (V - B - 1) / (A - B) + 1;
	cout << ans << "\n";
	return 0;
}
