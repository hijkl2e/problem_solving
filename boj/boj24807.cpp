#include <bits/stdc++.h>

using namespace std;

using iii = tuple<int, int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int B{}, D{}, C{}, L{};
	cin >> B >> D >> C >> L;
	vector<iii> A;
	for (int i = 0; B * i <= L; ++i) {
		for (int j = 0; B * i + D * j <= L; ++j) {
			int x = L - B * i - D * j;
			if (x % C == 0) {
				A.push_back({i, j, x / C});
			}
		}
	}
	if (A.empty()) {
		cout << "impossible\n";
	} else {
		for (auto &[i, j, k] : A) {
			cout << i << " " << j << " " << k << "\n";
		}
	}
	return 0;
}
