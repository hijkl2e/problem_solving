#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(26);
	while (N--) {
		char c{};
		cin >> c;
		++A[c - 'A'];
	}
	char c{};
	cin >> c;
	cout << A[c - 'A'] << "\n";
	return 0;
}
