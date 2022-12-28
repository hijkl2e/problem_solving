#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	string ans;
	for (int i = 0; i < N / 2 - 1; ++i) {
		ans += "RURD";
	}
	for (int i = 0; i < N / 2 - 1; ++i) {
		ans += i ? "LDRD" : "RDRD";
	}
	for (int i = 0; i < N / 4 - 1; ++i) {
		for (int j = 0; j < N / 2 - 1; ++j) {
			ans += j ? "LURU" : "LDLU";
		}
		for (int j = 0; j < N / 2 - 1; ++j) {
			ans += j ? "LDRD" : "LULD";
		}
	}
	ans += "LDLU";
	if (N % 4 == 1) {
		for (int i = 0; i < N / 2 - 2; ++i) {
			ans += "LURU";
		}
	} else {
		ans += "LURULULD";
		for (int i = 0; i < N / 4 - 1; ++i) {
			ans += "LULURURDRURULULD";
		}
	}
	ans += "LULU";
	if (N == 3) {
		ans = "RDLU";
	}
	cout << ans.size() << "\n";
	cout << "2 1\n";
	cout << ans << "\n";
	return 0;
}
