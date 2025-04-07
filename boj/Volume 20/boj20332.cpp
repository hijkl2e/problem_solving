#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int sum{};
	while (N--) {
		int x{};
		cin >> x;
		sum += x;
	}
	cout << (sum % 3 == 0 ? "yes" : "no") << "\n";
	return 0;
}
