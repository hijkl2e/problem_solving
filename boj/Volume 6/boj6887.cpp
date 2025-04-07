#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int ans = 1;
	while ((ans + 1) * (ans + 1) <= N) {
		++ans;
	}
	cout << "The largest square has side length " << ans << ".\n";
	return 0;
}
