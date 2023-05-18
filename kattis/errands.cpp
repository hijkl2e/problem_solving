#include <bits/stdc++.h>

using namespace std;

using dd = pair<double, double>;

const int INF = 1e9 + 7;

int n;
vector<dd> B;
vector<vector<double>> dp;
vector<vector<int>> par;

double dist(dd &a, dd &b) {
	auto &[x1, y1] = a;
	auto &[x2, y2] = b;
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

double solve(int u, int x) {
	if (dp[u][x] != INF) {
		return dp[u][x];
	} else if (x == 0) {
		return dp[u][x] = dist(B[u], B.back());
	}
	double &val = dp[u][x];
	for (int i = 0; i < n; ++i) {
		if (x & (1 << i)) {
			double nval = dist(B[u], B[i]) + solve(i, x & ~(1 << i));
			if (val > nval) {
				val = nval;
				par[u][x] = i;
			}
		}
	}
	return val;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	map<string, dd> n2c;
	while (N--) {
		string s;
		double x{}, y{};
		cin >> s >> x >> y;
		n2c[s] = {x, y};
	}
	cin.ignore();
	string s;
	while (getline(cin, s)) {
		istringstream iss(s);
		vector<string> A;
		while (iss >> s) {
			A.push_back(s);
		}
		A.push_back("work");
		A.push_back("home");
		n = A.size();
		B.resize(n);
		for (int i = 0; i < n; ++i) {
			B[i] = n2c[A[i]];
		}
		--n;
		dp.assign(n, vector<double>(1 << n, INF));
		par.assign(n, vector<int>(1 << n, -1));
		int u = --n;
		int x = (1 << u) - 1;
		solve(u, x);
		vector<int> C;
		while (par[u][x] != -1) {
			C.push_back(par[u][x]);
			u = par[u][x];
			x &= ~(1 << u);
		}
		for (int i = 0; i < n; ++i) {
			cout << A[C[i]] << (i == n - 1 ? "\n" : " ");
		}
	}
	return 0;
}
