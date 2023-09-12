#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		while (N--) {
			int a{}, b{};
			cin >> a >> b;
			cout << a + b << " " << a * b << "\n";
		}
	}
	return 0;
}
