#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int M{};
	cin >> M;
	vector<int> A(M);
	for (int i = 0; i < M; ++i) {
		cin >> A[i];
	}
	int N = *min_element(A.begin(), A.end()) * *max_element(A.begin(), A.end());
	cout << N << "\n";
	return 0;
}
