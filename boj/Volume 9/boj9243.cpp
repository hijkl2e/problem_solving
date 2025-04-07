#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	if (N % 2) {
		for (auto &c : s1) {
			c ^= 1;
		}
	}
	cout << "Deletion " << (s1 == s2 ? "succeeded" : "failed") << "\n";
	return 0;
}
