#include <bits/stdc++.h>

using namespace std;

vector<int> shuffle(vector<int> &A, string &sh) {
	vector<int> ret;
	ret.reserve(A.size());
	if (sh == "out") {
		for (int i = 0; i < A.size() / 2; ++i) {
			ret.push_back(A[i]);
			ret.push_back(A[(A.size() + 1) / 2 + i]);
		}
		if (A.size() % 2) {
			ret.push_back(A[A.size() / 2]);
		}
	} else {
		for (int i = 0; i < A.size() / 2; ++i) {
			ret.push_back(A[A.size() / 2 + i]);
			ret.push_back(A[i]);
		}
		if (A.size() % 2) {
			ret.push_back(A[A.size() - 1]);
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	string sh;
	cin >> N >> sh;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		A[i] = i;
	}
	vector<int> B(A.begin(), A.end());
	int ans{};
	do {
		B = shuffle(B, sh);
		++ans;
	} while (A != B);
	cout << ans << "\n";
	return 0;
}
