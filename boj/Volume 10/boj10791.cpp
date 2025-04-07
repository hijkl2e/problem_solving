#include <bits/stdc++.h>

using namespace std;

int N;
double w, h;
vector<double> x;

double solve(int step, double val) {
	if (step == N) {
		x[N] = w;
		return val * w * w;
	}
	double a = 1 - 2 * val;
	double b = (1 - (h * h) / (w * w)) / 2;
	double ret = solve(step + 1, (b * b) / (2 * a));
	x[step] = b / a * x[step + 1];
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> w >> h >> N;
	x.resize(N + 1);
	double ans = (w + h) * (w + h) / 4 - solve(0, 0);
	cout << fixed << setprecision(10);
	cout << ans << "\n";
	for (int i = 0; i < N && i < 10; ++i) {
		cout << x[i] << "\n";
	}
	return 0;
}
