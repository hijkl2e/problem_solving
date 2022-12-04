#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<int> A(K);
	while (N--) {
		int x{};
		cin >> x;
		++A[x - 1];
	}
	int minv = *min_element(A.begin(), A.end());
	vector<int> B;
	for (int i = 0; i < K; ++i) {
		if (A[i] == minv) {
			B.push_back(i + 1);
		}
	}
	cout << B.size() << "\n";
	for (int i = 0; i < B.size(); ++i) {
		cout << B[i] << (i == B.size() - 1 ? "\n" : " ");
	}
	return 0;
}
