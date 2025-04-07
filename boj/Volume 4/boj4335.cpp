#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int lo = 1, hi = 11;
	int N{};
	while (cin >> N, N) {
		cin.ignore();
		string S;
		getline(cin, S);
		if (S == "too high") {
			hi = min(hi, N);
		} else if (S == "too low") {
			lo = max(lo, N + 1);
		} else {
			if (lo <= N && N < hi) {
				cout << "Stan may be honest\n";
			} else {
				cout << "Stan is dishonest\n";
			}
			lo = 1, hi = 11;
		}
	}
	return 0;
}
