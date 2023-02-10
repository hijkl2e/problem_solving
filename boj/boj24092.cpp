#include <bits/stdc++.h>

using namespace std;

int cnt;
bool yes;
vector<int> A, B;

bool solve(int x) {
	return A[x] == B[x];
}

int partition(int p, int r) {
	int x = A[r];
	int i = p;
	for (int j = p; j < r; ++j) {
		if (A[j] <= x) {
			cnt += solve(i) + solve(j);
			swap(A[i], A[j]);
			cnt -= solve(i) + solve(j);
			yes |= cnt == 0;
			++i;
		}
	}
	if (i < r) {
		cnt += solve(i) + solve(r);
		swap(A[i], A[r]);
		cnt -= solve(i) + solve(r);
		yes |= cnt == 0;
	}
	return i;
}

void quick_sort(int p, int r) {
	if (p < r) {
		int q = partition(p, r);
		quick_sort(p, q - 1);
		quick_sort(q + 1, r);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	A.resize(N);
	B.resize(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	for (int i = 0; i < N; ++i) {
		cin >> B[i];
	}
	for (int i = 0; i < N; ++i) {
		if (A[i] != B[i]) {
			++cnt;
		}
	}
	yes = cnt == 0;
	quick_sort(0, N - 1);
	cout << yes << "\n";
	return 0;
}
