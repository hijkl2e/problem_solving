#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A(200001);
	int N{};
	cin >> N;
	int ans{};
	while (N--) {
		int a{}, b{};
		cin >> a >> b;
		if (A[a] == b) {
			++ans;
		}
		A[a] = b;
	}
	ans += accumulate(A.begin(), A.end(), 0);
	cout << ans << "\n";
	return 0;
}
