#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<int> A;
string ans = "-1";

void solve(int x) {
	if (N < x) {
		return;
	} else if (N == x) {
		if (--K == 0) {
			ans.clear();
			for (int i = 0; i < A.size(); ++i) {
				ans += to_string(A[i]) + (i == A.size() - 1 ? "" : "+");
			}
		}
		return;
	}
	for (int i = 1; i < 4; ++i) {
		A.push_back(i);
		solve(x + i);
		A.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> K;
	solve(0);
	cout << ans << "\n";
	return 0;
}
