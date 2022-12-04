#include <bits/stdc++.h>

using namespace std;

void print(int x, int y) {
	if (x) {
		cout << (y == 1 ? "single" : y == 2 ? "double" : "triple") << " ";
		cout << x << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	for (int i = 0; i < 21; ++i) {
		for (int j = 1; j < 4; ++j) {
			for (int k = 0; k < 21; ++k) {
				for (int l = 1; l < 4; ++l) {
					for (int m = 0; m < 21; ++m) {
						for (int n = 1; n < 4; ++n) {
							if (i * j + k * l + m * n == N) {
								print(i, j);
								print(k, l);
								print(m, n);
								return 0;
							}
						}
					}
				}
			}
		}
	}
	cout << "impossible\n";
	return 0;
}
