#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, X{}, K{};
	cin >> N >> X >> K;
	while (K--) {
		int a{}, b{};
		cin >> a >> b;
		if (X == a) {
			X = b;
		} else if (X == b) {
			X = a;
		}
	}
	cout << X << "\n";
	return 0;
}
