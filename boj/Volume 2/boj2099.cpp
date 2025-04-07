#include <bits/stdc++.h>

using namespace std;

using mat = vector<bitset<201>>;

mat T(mat &m) {
	mat ret = mat(m.size());
	for (int i = 0; i < m.size(); ++i) {
		for (int j = 0; j < m.size(); ++j) {
			ret[j][i] = m[i][j];
		}
	}
	return ret;
}

mat mul(mat &m1, mat &m2) {
	mat ret = mat(m1.size());
	mat m3 = T(m2);
	for (int i = 0; i < ret.size(); ++i) {
		for (int j = 0; j < ret.size(); ++j) {
			ret[i][j] = (m1[i] & m3[j]).any();
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{}, M{};
	cin >> N >> K >> M;
	mat A(N);
	for (int i = 0; i < N; ++i) {
		int x{}, y{};
		cin >> x >> y;
		A[x - 1][i] = A[y - 1][i] = true;
	}
	mat B(N);
	for (int i = 0; i < N; ++i) {
		B[i][i] = true;
	}
	while (K) {
		if (K % 2) {
			B = mul(A, B);
		}
		A = mul(A, A);
		K /= 2;
	}
	while (M--) {
		int a{}, b{};
		cin >> a >> b;
		cout << (B[b - 1][a - 1] ? "death" : "life") << "\n";
	}
	return 0;
}
