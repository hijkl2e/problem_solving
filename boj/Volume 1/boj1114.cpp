#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int L{}, K{}, C{};
	cin >> L >> K >> C;
	vector<int> A(K + 2);
	for (int i = 0; i < K; ++i) {
		cin >> A[i];
	}
	A[K] = L;
	sort(A.begin(), A.end());
	vector<int> B;
	for (int i = 0; i + 1 < A.size(); ++i) {
		if (A[i + 1] - A[i]) {
			B.push_back(A[i + 1] - A[i]);
		}
	}
	int lo = *max_element(B.begin(), B.end()) - 1, hi = L;
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		int sum{}, cnt{};
		for (int i = 0; i < B.size(); ++i) {
			if (sum + B[i] <= mid) {
				sum += B[i];
			} else {
				sum = B[i];
				++cnt;
			}
		}
		if (cnt > C) {
			lo = mid;
		} else {
			hi = mid;
		}
	}
	vector<int> D;
	int sum{}, cnt{}, pos = L;
	for (int i = B.size() - 1; i >= 0; --i) {
		if (sum + B[i] <= hi) {
			sum += B[i];
		} else {
			pos -= sum;
			sum = B[i];
			++cnt;
		}
	}
	if (cnt < C) {
		pos = A[1];
	}
	cout << hi << " " << pos << "\n";
	return 0;
}
