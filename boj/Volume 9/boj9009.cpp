#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> fibo(45);
	fibo[1] = 1;
	for (int i = 2; i < fibo.size(); ++i) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		vector<int> A;
		for (int i = fibo.size() - 1; i > 0; --i) {
			if (N >= fibo[i]) {
				N -= fibo[i];
				A.push_back(fibo[i]);
			}
		}
		reverse(A.begin(), A.end());
		for (int i = 0; i < A.size(); ++i) {
			cout << A[i] << (i == A.size() - 1 ? "\n" : " ");
		}
	}
	return 0;
}
