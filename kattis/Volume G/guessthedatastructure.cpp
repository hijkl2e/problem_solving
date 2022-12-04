#include <bits/stdc++.h>

using namespace std;

vector<int> A, B;

bool is_st() {
	stack<int> st;
	for (int i = 0; i < A.size(); ++i) {
		if (A[i] == 1) {
			st.push(B[i]);
		} else if (st.size() && st.top() == B[i]) {
			st.pop();
		} else {
			return false;
		}
	}
	return true;
}

bool is_q() {
	queue<int> q;
	for (int i = 0; i < A.size(); ++i) {
		if (A[i] == 1) {
			q.push(B[i]);
		} else if (q.size() && q.front() == B[i]) {
			q.pop();
		} else {
			return false;
		}
	}
	return true;
}

bool is_pq() {
	priority_queue<int> pq;
	for (int i = 0; i < A.size(); ++i) {
		if (A[i] == 1) {
			pq.push(B[i]);
		} else if (pq.size() && pq.top() == B[i]) {
			pq.pop();
		} else {
			return false;
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	while (cin >> N) {
		A.resize(N);
		B.resize(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i] >> B[i];
		}
		int res = (is_st() << 2) | (is_q() << 1) | is_pq();
		string ans = res == 4 ? "stack" : res == 2 ? "queue"
					: res == 1 ? "priority queue" : res == 0 ? "impossible" : "not sure";
		cout << ans << "\n";
	}
	return 0;
}
