#include <bits/stdc++.h>
#include "perm.h"

using namespace std;

std::vector<int> construct_permutation(long long k) {
	vector<int> A;
	--k;
	while (k >= (1LL << A.size())) {
		k -= 1LL << A.size();
		A.push_back(2 * A.size() + 1);
	}
	for (int i = A.size() - 1; i >= 0; --i) {
		if (k & (1LL << i)) {
			if (i && (k & (1LL << (i - 1))) && A[A.size() - 2] > max(A[A.size() - 1], 2 * (i - 1))) {
				A.insert(A.end() - 2, 2 * (i - 1));
				--i;
			} else {
				A.push_back(2 * i);
			}
		}
	}
	for (int i = 0, j = 0; i < A.size(); ++i) {
		while (true) {
			auto it = find(A.begin(), A.end(), j++);
			if (it != A.end()) {
				*it = i;
				break;
			}
		}
	}
	return A;
}
