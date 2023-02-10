#include <bits/stdc++.h>

using namespace std;

int binary_search(int l, int r, int val) {
	int mid = (l + r) / 2;
	if (mid == val) {
		return 0;
	} else if (val < mid) {
		return binary_search(l, mid - 1, val) + 1;
	} else {
		return binary_search(mid + 1, r, val) + 1;
	}
}

int ternary_search(int l, int r, int val) {
	int lt = l + (r - l) / 3;
	int rt = r - (r - l) / 3;
	if (lt == val) {
		return 0;
	} else if (rt == val) {
		return 1;
	} else if (val < lt) {
		return ternary_search(l, lt - 1, val) + 2;
	} else if (val < rt) {
		return ternary_search(lt + 1, rt - 1, val) + 2;
	} else {
		return ternary_search(rt + 1, r, val) + 2;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> B(N);
	vector<int> T(N);
	for (int i = 0; i < N; ++i) {
		B[i] = binary_search(0, N - 1, i);
	}
	for (int i = 0; i < N; ++i) {
		T[i] = ternary_search(0, N - 1, i);
	}
	int cnt1{}, cnt2{};
	for (int i = 0; i < N; ++i) {
		if (B[i] < T[i]) {
			++cnt1;
		} else if (B[i] > T[i]) {
			++cnt2;
		}
	}
	cout << cnt1 << "\n" << (N - cnt1 - cnt2) << "\n" << cnt2 << "\n";
	return 0;
}
