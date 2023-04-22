#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = 4e18;

struct vec {
	int x[3]{};
	int &operator[](size_t n) {
		return x[n];
	}
};

vec sub(vec &v1, vec &v2) {
	vec ret;
	for (int i = 0; i < 3; ++i) {
		ret[i] = v1[i] - v2[i];
	}
	return ret;
}

ll inner(vec &v1, vec &v2) {
	ll ret{};
	for (int i = 0; i < 3; ++i) {
		ret += 1LL * v1[i] * v2[i];
	}
	return ret;
}

vec outer(vec &v1, vec &v2) {
	vec ret;
	ret[0] = v1[1] * v2[2] - v1[2] * v2[1];
	ret[1] = v1[2] * v2[0] - v1[0] * v2[2];
	ret[2] = v1[0] * v2[1] - v1[1] * v2[0];
	return ret;
}

double solve(ll s1, ll s2, ll n) {
	return n ? s1 - s2 * s2 * 1.0 / n : 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<vec> A(N);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < 3; ++j) {
			cin >> A[i][j];
		}
	}
	if (K == 1 || N < 3) {
		double ans{};
		for (int j = 0; j < 3; ++j) {
			ll s1{}, s2{};
			for (int i = 0; i < N; ++i) {
				s1 += A[i][j] * A[i][j];
				s2 += A[i][j];
			}
			ans += solve(s1, s2, N);
		}
		ans = K == 1 ? ans : 0;
		cout << fixed << setprecision(6);
		cout << ans << "\n";
		return 0;
	}
	ll s1[2][3]{};
	ll s2[2][3]{};
	double ans = INF;
	for (int p = 0; p < N; ++p) {
		for (int q = p + 1; q < N; ++q) {
			for (int r = q + 1; r < N; ++r) {
				vec B = {p, q, r};
				vec pq = sub(A[q], A[p]);
				vec pr = sub(A[r], A[p]);
				vec norm = outer(pq, pr);
				memset(s1, 0, sizeof s1);
				memset(s2, 0, sizeof s2);
				int n{};
				for (int i = 0; i < N; ++i) {
					if (i == p || i == q || i == r) {
						continue;
					}
					vec px = sub(A[i], A[p]);
					int x = inner(px, norm) > 0;
					n += x;
					for (int j = 0; j < 3; ++j) {
						s1[x][j] += A[i][j] * A[i][j];
						s2[x][j] += A[i][j];
					}
				}
				for (int i = 0; i < 8; ++i) {
					for (int j = 0; j < 3; ++j) {
						for (int k = 0; k < 3; ++k) {
							s1[(i >> k) & 1][j] += A[B[k]][j] * A[B[k]][j];
							s2[(i >> k) & 1][j] += A[B[k]][j];
						}
					}
					double res{};
					for (int j = 0; j < 3; ++j) {
						res += solve(s1[0][j], s2[0][j], N - n - __builtin_popcount(i));
						res += solve(s1[1][j], s2[1][j], n + __builtin_popcount(i));
					}
					ans = min(ans, res);
					for (int j = 0; j < 3; ++j) {
						for (int k = 0; k < 3; ++k) {
							s1[(i >> k) & 1][j] -= A[B[k]][j] * A[B[k]][j];
							s2[(i >> k) & 1][j] -= A[B[k]][j];
						}
					}
				}
			}
		}
	}
	cout << fixed << setprecision(6);
	cout << ans << "\n";
	return 0;
}
