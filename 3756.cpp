class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        const long long MOD = 1000000007;

        int n = s.size();

        vector<long long> pow10(n + 1, 1);
        vector<long long> xPrefix(n + 1, 0);
        vector<int> prefixSum(n + 1, 0);
        vector<int> nonZeroCount(n + 1, 0);

        for (int i = 0; i < n; i++) {
            int d = s[i] - '0';

            pow10[i + 1] = (pow10[i] * 10) % MOD;

            prefixSum[i + 1] = prefixSum[i] + d;
            nonZeroCount[i + 1] = nonZeroCount[i] + (d != 0);

            if (d != 0) {
                xPrefix[i + 1] = (xPrefix[i] * 10 + d) % MOD;
            } else {
                xPrefix[i + 1] = xPrefix[i];
            }
        }

        vector<int> ans;

        for (auto& q : queries) {
            int l = q[0];
            int r = q[1];

            int sum = prefixSum[r + 1] - prefixSum[l];

            int len = nonZeroCount[r + 1] - nonZeroCount[l];

            long long leftPart = xPrefix[l] * pow10[len] % MOD;
            long long x = (xPrefix[r + 1] - leftPart + MOD) % MOD;

            long long result = x * sum % MOD;

            ans.emplace_back(result);
        }

        return ans;
    }
};