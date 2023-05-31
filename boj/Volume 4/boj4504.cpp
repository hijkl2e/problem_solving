#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, x{};
	cin >> N;
	while (cin >> x, x) {
		cout << x << " is " << (x % N ? "NOT " : "") << "a multiple of " << N << ".\n";
	}
	return 0;
}
