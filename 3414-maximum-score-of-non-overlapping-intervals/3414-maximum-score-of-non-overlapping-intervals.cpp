class Solution {
public:
    struct Node {
        int l, r, w, idx;
    };

    struct State {
        long long score;
        vector<int> pick;
    };

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<Node> a;

        for (int i = 0; i < n; i++)
            a.push_back({intervals[i][0], intervals[i][1],
                         intervals[i][2], i});

        sort(a.begin(), a.end(), [](auto &x, auto &y) {
            return x.l < y.l;
        });

        vector<int> starts;
        for (auto &x : a) starts.push_back(x.l);

        vector<int> nxt(n);
        for (int i = 0; i < n; i++)
            nxt[i] = upper_bound(starts.begin(), starts.end(), a[i].r)
                     - starts.begin();

        vector<vector<State>> dp(n + 1, vector<State>(5));

        for (int k = 0; k <= 4; k++)
            dp[n][k] = {0, {}};

        for (int i = n - 1; i >= 0; i--) {
            for (int k = 1; k <= 4; k++) {

                State skip = dp[i + 1][k];

                State take = dp[nxt[i]][k - 1];
                take.score += a[i].w;
                take.pick.insert(take.pick.begin(), a[i].idx);

                sort(take.pick.begin(), take.pick.end());

                if (take.score > skip.score)
                    dp[i][k] = take;
                else if (take.score < skip.score)
                    dp[i][k] = skip;
                else
                    dp[i][k] = (take.pick < skip.pick) ? take : skip;
            }
        }

        return dp[0][4].pick;
    }
};