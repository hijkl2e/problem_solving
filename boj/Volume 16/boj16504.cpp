#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	N *= N;
	ll sum{};
	while (N--) {
		int x{};
		cin >> x;
		sum += x;
	}
	cout << sum << "\n";
	return 0;
}
