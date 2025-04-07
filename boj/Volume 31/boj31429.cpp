#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A{
		-1, 12, 11, 11, 10, 9, 9, 9, 8, 7, 6, 6
	};
	vector<int> B{
		-1, 1600, 894, 1327, 1311, 1004, 1178, 1357, 837, 1055, 556, 773
	};
	int N{};
	cin >> N;
	cout << A[N] << " " << B[N] << "\n";
	return 0;
}
