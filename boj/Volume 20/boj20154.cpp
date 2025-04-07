#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A{
		3, 2, 1, 2, 3, 3, 3, 3, 1, 1, 3, 1, 3,
		3, 1, 2, 2, 2, 1, 2, 1, 1, 2, 2, 2, 1
	};
	string S;
	getline(cin, S);
	int cnt{};
	for (char c : S) {
		cnt += A[c - 'A'];
	}
	if (cnt % 2) {
		cout << "I'm a winner!\n";
	} else {
		cout << "You're the winner?\n";
	}
	return 0;
}
