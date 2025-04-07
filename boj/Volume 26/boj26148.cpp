#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int ans = 29 + ((N % 4 == 0 && N % 100) || N % 400 == 0);
	cout << ans << "\n";
	return 0;
}
