#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	for (int i = 2; i < 101; ++i) {
		for (int j = 2; j < i; ++j) {
			for (int k = j; k < i; ++k) {
				for (int l = k; l < i; ++l) {
					if (i * i * i == j * j * j + k * k * k + l * l * l) {
						cout << "Cube = " << i << ", ";
						cout << "Triple = (" << j << "," << k << "," << l << ")\n";
					}
				}
			}
		}
	}
	return 0;
}
