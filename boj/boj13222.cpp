#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, w{}, h{};
	cin >> N >> w >> h;
	int d = sqrt(w * w + h * h);
	while (N--) {
		int x{};
		cin >> x;
		cout << (x <= d ? "YES" : "NO") << "\n";
	}
	return 0;
}
