#include <bits/stdc++.h>

using namespace std;

struct Window {
	int x{}, y{}, w{}, h{};
};

int X, Y;
vector<Window> windows;

bool fit(Window &w) {
	return w.x + w.w <= X && w.y + w.h <= Y;
}

bool overlap(Window &w1, Window &w2) {
	return max(w1.x, w2.x) < min(w1.x + w1.w, w2.x + w2.w)
		&& max(w1.y, w2.y) < min(w1.y + w1.h, w2.y + w2.h);
}

bool overlap(Window &w, int skip = -1) {
	for (int i = 0; i < windows.size(); ++i) {
		if (i == skip) {
			continue;
		}
		Window &v = windows[i];
		if (overlap(w, v)) {
			return true;
		}
	}
	return false;
}

bool inside(Window &w, int x, int y) {
	return w.x <= x && x < w.x + w.w && w.y <= y && y < w.y + w.h;
}

int find(int x, int y) {
	for (int i = 0; i < windows.size(); ++i) {
		if (inside(windows[i], x, y)) {
			return i;
		}
	}
	return -1;
}

int move(int idx) {
	Window &w = windows[idx];
	vector<int> A{idx};
	for (int i = 0; i < windows.size(); ++i) {
		Window &v = windows[i];
		if (w.x < v.x) {
			A.push_back(i);
		}
	}
	sort(A.begin(), A.end(), [](int a, int b) {
		return windows[a].x > windows[b].x;
	});
	vector<int> D(A.size());
	for (int i = 0; i < A.size(); ++i) {
		Window &v = windows[A[i]];
		D[i] = X - v.x - v.w;
		for (int j = 0; j < i; ++j) {
			Window &u = windows[A[j]];
			if (v.y + v.h <= u.y || u.y + u.h <= v.y) {
				continue;
			}
			D[i] = min(D[i], D[j] + u.x - (v.x + v.w));
		}
	}
	return D.back();
}

void move(int idx, int d) {
	Window &w = windows[idx];
	for (int i = 0; i < windows.size(); ++i) {
		Window &v = windows[i];
		if (v.y + v.h <= w.y || w.y + w.h <= v.y || v.x <= w.x || d <= v.x - (w.x + w.w)) {
			continue;
		}
		int dist = v.x - (w.x + w.w);
		move(i, d - dist);
	}
	w.x += d;
}

int move(int idx, int dx, int dy) {
	int ret{};
	if (dy) {
		swap(X, Y);
		for (auto &w : windows) {
			swap(w.x, w.y);
			swap(w.w, w.h);
		}
		ret = move(idx, dy, dx);
		swap(X, Y);
		for (auto &w : windows) {
			swap(w.x, w.y);
			swap(w.w, w.h);
		}
	} else if (dx < 0) {
		for (auto &w : windows) {
			w.x = X - w.x - w.w;
		}
		ret = move(idx, -dx, dy);
		for (auto &w : windows) {
			w.x = X - w.x - w.w;
		}
	} else {
		ret = min(dx, move(idx));
		move(idx, ret);
	}
	return ret;
}

void report(int cnum, string com, string msg) {
	cout << "Command " << cnum << ": " << com << " - " << msg << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> X >> Y;
	cin.ignore();
	string S;
	for (int i = 1; getline(cin, S); ++i) {
		istringstream iss(S);
		string cmd;
		int x{}, y{};
		iss >> cmd >> x >> y;
		if (cmd == "OPEN") {
			int w{}, h{};
			iss >> w >> h;
			Window win{x, y, w, h};
			if (fit(win) && !overlap(win)) {
				windows.push_back(win);
			} else {
				report(i, cmd, "window does not fit");
			}
			continue;
		}
		int idx = find(x, y);
		if (idx == -1) {
			report(i, cmd, "no window at given position");
			continue;
		}
		if (cmd == "CLOSE") {
			windows.erase(windows.begin() + idx);
		} else if (cmd == "RESIZE") {
			int w{}, h{};
			iss >> w >> h;
			Window win = windows[idx];
			win.w = w;
			win.h = h;
			if (fit(win) && !overlap(win, idx)) {
				windows[idx] = win;
			} else {
				report(i, cmd, "window does not fit");
			}
		} else {
			int dx{}, dy{};
			iss >> dx >> dy;
			int res = move(idx, dx, dy);
			int d = abs(dx + dy);
			if (res != d) {
				string msg = "moved " + to_string(res) + " instead of " + to_string(d);
				report(i, cmd, msg);
			}
		}
	}
	cout << windows.size() << " window(s):\n";
	for (auto &w : windows) {
		cout << w.x << " " << w.y << " " << w.w << " " << w.h << "\n";
	}
	return 0;
}
