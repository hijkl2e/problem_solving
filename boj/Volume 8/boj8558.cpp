#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A{1, 1, 2, 6, 4, 0};
	int N{};
	cin >> N;
	N = min(N, 5);
	cout << A[N] << "\n";
	return 0;
}
