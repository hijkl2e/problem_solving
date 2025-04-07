#include <bits/stdc++.h>

using namespace std;

using iii = tuple<int, int, int>;

bool D[201][201][201];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A(3);
	for (int i = 0; i < 3; ++i) {
		cin >> A[i];
	}
	queue<iii> q;
	D[0][0][A[2]] = true;
	q.push({0, 0, A[2]});
	vector<int> B(3);
	int &x = B[0], &y = B[1], &z = B[2];
	while (q.size()) {
		tie(x, y, z) = q.front(); q.pop();
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				if (i == j) {
					continue;
				}
				int k = min(B[i], A[j] - B[j]);
				B[i] -= k;
				B[j] += k;
				if (!D[x][y][z]) {
					D[x][y][z] = true;
					q.push({x, y, z});
				}
				B[i] += k;
				B[j] -= k;
			}
		}
	}
	vector<int> C;
	for (int i = 0; i <= A[2]; ++i) {
		if (A[2] - i <= A[1] && D[0][A[2] - i][i]) {
			C.push_back(i);
		}
	}
	for (int i = 0; i < C.size(); ++i) {
		cout << C[i] << (i == C.size() - 1 ? "\n" : " ");
	}
	return 0;
}
