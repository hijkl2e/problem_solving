#include <bits/stdc++.h>

using namespace std;

using mat = vector<vector<int>>;

mat mul(mat &m1, mat &m2) {
	mat ret = mat(m1.size(), vector<int>(m2[0].size()));
	for (int i = 0; i < ret.size(); ++i) {
		for (int j = 0; j < ret[i].size(); ++j) {
			for (int k = 0; k < m2.size(); ++k) {
				ret[i][j] += m1[i][k] * m2[k][j];
			}
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, K{};
	cin >> N >> M;
	mat A(N, vector<int>(M));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> A[i][j];
		}
	}
	cin >> M >> K;
	mat B(M, vector<int>(K));
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < K; ++j) {
			cin >> B[i][j];
		}
	}
	mat C = mul(A, B);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < K; ++j) {
			cout << C[i][j] << (j == K - 1 ? "\n" : " ");
		}
	}
	return 0;
}
