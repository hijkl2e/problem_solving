#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(100001);
	while (N--) {
		int x{};
		cin >> x;
		A[x] = (A[x] + 1) % 2;
	}
	cout << (count(A.begin(), A.end(), 1) ? "koosaga" : "cubelover") << "\n";
	return 0;
}
