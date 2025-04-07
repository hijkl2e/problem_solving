#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	while (N--) {
		int a{}, b{}, x{};
		cin >> a >> b >> x;
		cout << a * (x - 1) + b << "\n";
	}
	return 0;
}
