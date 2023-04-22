#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, F{};
	cin >> N >> F;
	N = N / 100 * 100;
	int ans = (F - N % F) % F;
	cout << setw(2) << setfill('0') << ans << "\n";
	return 0;
}
