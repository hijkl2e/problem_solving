#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	int N{};
	cin >> S >> N;
	vector<char> A(123);
	for (int i = 'A'; i <= 'z'; ++i) {
		A[i] = i;
	}
	while (N--) {
		int q{};
		cin >> q;
		if (q == 2) {
			for (char c : S) {
				cout << A[c];
			}
			cout << "\n";
			continue;
		}
		char c1{}, c2{};
		cin >> c1 >> c2;
		for (int i = 'A'; i <= 'z'; ++i) {
			if (A[i] == c1) {
				A[i] = c2;
			}
		}
	}
	return 0;
}
