#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cout << (N % 3 == 2 ? "Vaporeon" : N % 3 == 0 ? "Jolteon" : "Flareon") << "\n";
	return 0;
}
