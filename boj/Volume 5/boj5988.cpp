#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	while (N--) {
		string K;
		getline(cin, K);
		cout << (K.back() % 2 ? "odd" : "even") << "\n";
	}
	return 0;
}
