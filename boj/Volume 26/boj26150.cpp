#include <bits/stdc++.h>

using namespace std;

using iis = tuple<int, int, string>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<iis> A(N);
	for (auto &[i, d, s] : A) {
		cin >> s >> i >> d;
	}
	sort(A.begin(), A.end());
	for (auto &[i, d, s] : A) {
		char c = toupper(s[d - 1]);
		cout << c;
	}
	cout << "\n";
	return 0;
}
