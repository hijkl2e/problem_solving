#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int maxv{}, maxi{};
	vector<int> A(5);
	for (int i = 1; i <= N; ++i) {
		for (int j = 0; j < 5; ++j) {
			cin >> A[j];
		}
		for (int j = 0; j < 5; ++j) {
			for (int k = j + 1; k < 5; ++k) {
				for (int l = k + 1; l < 5; ++l) {
					int val = (A[j] + A[k] + A[l]) % 10;
					if (maxv <= val) {
						maxv = val;
						maxi = i;
					}
				}
			}
		}
	}
	cout << maxi << "\n";
	return 0;
}
