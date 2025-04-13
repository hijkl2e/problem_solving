#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int x = 2024 + N / 2;
	int y = (8 + 7 * (N - 1) - 1) % 12 + 1;
	cout << x << " " << y << "\n";
	return 0;
}
