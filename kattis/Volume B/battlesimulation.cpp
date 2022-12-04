#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	map<char, char> m2c{
		{'R', 'S'}, {'B', 'K'}, {'L', 'H'}
	};
	int combo{};
	for (auto &p : m2c) {
		combo += p.first;
	}
	for (int i = 0; i < S.size(); ++i) {
		int sum{};
		for (int j = i; j < i + 3 && j < S.size(); ++j) {
			sum += S[j];
		}
		if (sum == combo) {
			cout << "C";
			i += 2;
			continue;
		}
		cout << m2c[S[i]];
	}
	cout << "\n";
	return 0;
}
