#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	while (cin >> N, N) {
		int x = 1;
		while (N--) {
			int a{}, b{};
			cin >> a >> b;
			x = a * x - b;
		}
		cout << x << "\n";
	}
	return 0;
}
