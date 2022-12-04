#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	map<string, int> n2i;
	vector<string> A(N);
	vector<int> B(N);
	deque<bool> C(N);
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	while (N--) {
		int q{}, x{}, y{};
		string s;
		cin >> q;
		if (q == 0) {
			cin >> s >> y;
			x = n2i.size();
			n2i.insert({s, x});
			A[x] = s;
			B[x] = y;
			pq.push({-y, x});
		} else if (q == 1) {
			cin >> s >> y;
			if (y) {
				x = n2i[s];
				B[x] += y;
				pq.push({-B[x], x});
			}
		} else if (q == 2) {
			cin >> s;
			x = n2i[s];
			C[x] = true;
		} else {
			while (pq.size()) {
				auto &[u, v] = pq.top();
				if (u < -B[v] || C[v]) {
					pq.pop();
				} else {
					break;
				}
			}
			if (pq.empty()) {
				cout << "The clinic is empty\n";
			} else {
				cout << A[pq.top().second] << "\n";
			}
		}
	}
	return 0;
}
