#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A{
		1, 1, 5, 11, 36, 95, 281, 781, 2245, 6336, 18061, 51205, 145601, 413351,
		1174500, 3335651, 9475901, 26915305, 76455961, 217172736, 616891945, 1752296281
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
