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
	int M{};
	cin >> M;
	vector<int> B;
	auto it = min_element(A.begin() + 1, A.end());
	if (it == A.end() || M < *it) {
		cout << "0\n";
		return 0;
	}
	B.push_back(it - A.begin());
	M -= *it;
	it = min_element(A.begin(), A.end());
	while (M >= *it) {
		B.push_back(it - A.begin());
		M -= *it;
	}
	for (int i = 0; i < B.size(); ++i) {
		for (int j = B[i] + 1; j < N; ++j) {
			if (M >= A[j] - A[B[i]]) {
				M -= A[j] - A[B[i]];
				B[i] = j;
			}
		}
	}
	for (int x : B) {
		cout << x;
	}
	cout << "\n";
	return 0;
}
