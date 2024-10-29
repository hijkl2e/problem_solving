#include <bits/stdc++.h>

using namespace std;

vector<int> A;
int ans;

void solve(int x, int y, int a, int b) {
	if (x > 5 && y < x - 5) {
		return;
	} else if (x == 10) {
		++ans;
		return;
	}
	for (int i = 1; i < 6; ++i) {
		if (a == i && b == i) {
			continue;
		}
		solve(x + 1, y + (A[x] == i), b, i);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	A.resize(10);
	for (int i = 0; i < 10; ++i) {
		cin >> A[i];
	}
	solve(0, 0, -1, -1);
	cout << ans << "\n";
	return 0;
}
