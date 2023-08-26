#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	int x = accumulate(A.begin(), A.begin() + N / 2, 0);
	int y = accumulate(A.begin() + N / 2, A.end(), 0);
	cout << x << " " << y << "\n";
	return 0;
}
