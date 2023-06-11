#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int x = N / 100 * 100 + 99;
	if (x > 99 && N % 100 < 49) {
		x -= 100;
	}
	cout << x << "\n";
	return 0;
}
