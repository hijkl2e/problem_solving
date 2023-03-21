#include <bits/stdc++.h>
#include "SORT.h"

using namespace std;

int sz;

void init(int T, int N) {
	sz = N;
}

void solve(vector<int> &A, int x) {
	int lo = -1, hi = A.size();
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		if (A[mid] < x ? compare(A[mid], x) : !compare(x, A[mid])) {
			lo = mid;
		} else {
			hi = mid;
		}
	}
	A.insert(A.begin() + hi, x);
}

vector<int> sorting5() {
	int x = 1, y = 2, u = 3, v = 4;
	if (!compare(x, y)) {
		swap(x, y);
	}
	if (!compare(u, v)) {
		swap(u, v);
	}
	if (!compare(y, v)) {
		swap(x, u);
		swap(y, v);
	}
	vector<int> A{x, y, v};
	solve(A, 5);
	int z = A.back();
	A.pop_back();
	solve(A, u);
	A.push_back(z);
	return A;
}

void sorting() {
	vector<int> A;
	if (sz > 4) {
		A = sorting5();
	}
	for (int i = sz > 4 ? 5 : 0; i < sz; ++i) {
		solve(A, i + 1);
	}
	for (int i = 0; i < sz; ++i) {
		answer(A[i], i + 1);
	}
}
