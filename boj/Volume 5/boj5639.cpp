#include <bits/stdc++.h>

using namespace std;

vector<int> A;

void solve(int s, int e) {
	if (s == e) {
		return;
	}
	int x = upper_bound(A.begin() + s + 1, A.begin() + e, A[s]) - A.begin();
	solve(s + 1, x);
	solve(x, e);
	cout << A[s] << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int x{};
	while (cin >> x) {
		A.push_back(x);
	}
	solve(0, A.size());
	return 0;
}
