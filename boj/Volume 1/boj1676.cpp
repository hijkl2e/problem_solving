#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int ans = N / 5 + N / 25 + N / 125;
	cout << ans << "\n";
	return 0;
}
