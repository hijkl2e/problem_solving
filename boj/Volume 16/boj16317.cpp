#include <bits/stdc++.h>

using namespace std;

int dirty(vector<int> &A, int day) {
	int ret{};
	for (int x : A) {
		ret += day - x;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A;
	A.reserve(N);
	int ans = 1;
	while (N--) {
		int x{};
		cin >> x;
		if (dirty(A, x) >= 20) {
			A.clear();
			++ans;
		}
		A.push_back(x);
	}
	cout << ans << "\n";
	return 0;
}
