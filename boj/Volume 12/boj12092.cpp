#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A{
		-1, 25, 100, -1, 25, 100, -1, 25, 100, -1, 12, 50, -1, 12, 50, -1, 12, 50, -1, 25, -1,
		50, -1, 50, -1, 50, -1, 50, -1, 25, 100, -1, 25, 100, -1, 50, -1, 50, -1, 50, -1, 50, -1,
		25, 100, -1, 50, -1, 50, -1, 50, -1, 50, -1, 50, -1, 50, -1, 50, -1, 25, 100, -1, 25, 100,
		-1, 25, 100, -1, 25, 100, -1, 50, -1, 25, 100, -1, 50, -1, 50, -1, 50, -1, -1, 50, -1, 50,
		-1, 50, -1, 50, -1, 25, 100, -1, -1, 50, -1, 50, -1, 50, -1, 50, -1, 50, -1, -1, -1, -1, 50,
		-1, 50, -1, -1, -1, -1, 50, -1, 50, -1, 50, -1, -1, -1, -1, -1, -1, -1, -1, 400, -1, -1, -1,
		25, -1, -1, -1, -1, 50, -1, 50, -1, -1, -1, -1, -1, -1, 25, 100, -1, -1, -1
	};
	int N{};
	cin >> N;
	cout << A[N] << "\n";
	return 0;
}