#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool compare_rows(pair<int, int> a, pair<int, int> b) {
    if (a.first != b.first) {
        return a.first < b.first;
    } else {
        return a.second < b.second;
    }
}

bool compare_columns(pair<int, int> a, pair<int, int> b) {
    if (a.second != b.second) {
        return a.second < b.second;
    } else {
        return a.first < b.first;
    }
}

int main() {
    int m, n, k;
    int res = 0;

    cin >> m >> n >> k;

    vector<pair<int, int>> black_points;
    vector<pair<int, int>> single_points;

    for (int i = 0; i < k; ++i) {
        pair<int, int> p;
        cin >> p.first >> p.second;
        p.first--;
        p.second--;
        black_points.push_back(p);
    }

    for (int i = 0; i < m; i++) {
        black_points.push_back({i, n});
        black_points.push_back({i, -1});
    }

    for (int i = 0; i < n; i++) {
        black_points.push_back({m, i});
        black_points.push_back({-1, i});
    }

    sort(black_points.begin(), black_points.end(), compare_rows);

    for (int i = 0; i < black_points.size() - 1; i++) {
        if (black_points[i].first == black_points[i + 1].first) {
            if (black_points[i + 1].second - black_points[i].second > 2) {
                res++;
            } else if (black_points[i + 1].second - black_points[i].second == 2) {
                pair<int, int> p(black_points[i].first, black_points[i].second + 1);
                single_points.push_back(p);
            }
        }
    }

    sort(black_points.begin(), black_points.end(), compare_columns);

    for (int i = 0; i < black_points.size() - 1; i++) {
        if (black_points[i].second == black_points[i + 1].second) {
            if (black_points[i + 1].first - black_points[i].first > 2) {
                res++;
            } else if (black_points[i + 1].first - black_points[i].first == 2) {
                pair<int, int> p(black_points[i].first + 1, black_points[i].second);
                single_points.push_back(p);
            }
        }
    }

    sort(single_points.begin(), single_points.end(), compare_rows);

    if (single_points.size() > 1) {
        for (int i = 0; i < single_points.size() - 1; i++) {
            if (single_points[i] == single_points[i + 1]) {
                res++;
                i++;
            }
        }
    }

    cout << res;

    return 0;
}