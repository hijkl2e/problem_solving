#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	char c1 = 'A' + (N + 8) % 12;
	char c2 = '0' + (N + 6) % 10;
	cout << c1 << c2 << "\n";
	return 0;
}
