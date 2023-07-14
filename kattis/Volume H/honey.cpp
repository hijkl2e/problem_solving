#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A{
		-1, 0, 6, 12, 90, 360, 2040, 10080, 54810, 290640,
		1588356, 8676360, 47977776, 266378112, 1488801600
	};
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		cout << A[N] << "\n";
	}
	return 0;
}
