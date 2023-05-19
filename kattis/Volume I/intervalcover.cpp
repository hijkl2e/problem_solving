#include <bits/stdc++.h>

using namespace std;

using ddi = tuple<double, double, int>;

const double EPS = 1e-9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	double A{}, B{};
	while (cin >> A >> B) {
		B += 2 * EPS;
		int N{};
		cin >> N;
		vector<ddi> C(N + 1);
		for (int i = 0; i < N; ++i) {
			auto &[a, b, idx] = C[i];
			cin >> a >> b;
			b += 2 * EPS;
			idx = i;
		}
		C[N] = {B, B, -1};
		sort(C.begin(), C.end());
		vector<int> D;
		double x = A;
		for (int i = 0; i < N && x + EPS < B;) {
			int maxi{};
			double maxv = x;
			while (i < N) {
				auto &[a, b, idx] = C[i];
				if (x + EPS < a) {
					break;
				}
				if (maxv < b) {
					maxi = idx;
					maxv = b;
				}
				++i;
			}
			x = maxv;
			if (x + EPS < get<0>(C[i])) {
				D.clear();
				break;
			}
			D.push_back(maxi);
		}
		if (D.empty()) {
			cout << "impossible\n";
		} else {
			cout << D.size() << "\n";
			for (int i = 0; i < D.size(); ++i) {
				cout << D[i] << (i == D.size() - 1 ? "" : " ");
			}
			cout << "\n";
		}
	}
	return 0;
}
