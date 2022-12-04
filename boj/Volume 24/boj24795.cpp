#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, Y{};
	cin >> N >> Y;
	deque<bool> chk(N);
	while (Y--) {
		int x{};
		cin >> x;
		chk[x] = true;
	}
	for (int i = 0; i < N; ++i) {
		if (!chk[i]) {
			cout << i << "\n";
		}
	}
	cout << "Mario got " << accumulate(chk.begin(), chk.end(), 0);
	cout << " of the dangerous obstacles.\n";
	return 0;
}
