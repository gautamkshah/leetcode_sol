class Solution {
public:
    int mod = 1e9 + 7;

    // Modular addition
    int mod_sum(int a, int b) { 
        return (a % mod + b % mod) % mod; 
    }

    // Modular multiplication
    int mod_multiply(int a, int b) { 
        return (1LL * (a % mod) * (b % mod)) % mod; 
    }

    // Modular exponentiation (binary exponentiation)
    int binary_exponentiation(int a, int b) {
        int res = 1;
        int base = a % mod;
        while (b) {
            if (b & 1) {
                res = mod_multiply(res, base);
            }
            base = mod_multiply(base, base);
            b >>= 1;
        }
        return res;
    }

    // Modular inverse using Fermat's little theorem
    int mod_inverse(int a) { 
        return binary_exponentiation(a, mod - 2); 
    }

    // Modular subtraction
    int mod_subtract(int a, int b) {
        return ((a % mod) - (b % mod) + mod) % mod;
    }

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        string temp;
        vector<int> conversion; // maps original index to compressed index on digits
        int c = 0;
        for (int i = 0; i < n; i++) {
            conversion.push_back(c);
            if (s[i] > '0') { 
                temp.push_back(s[i]);
                c++;
            }
        }
        conversion.push_back(c);

        int nn = temp.size();
        vector<int> suffixSum(nn + 1, 0);
        vector<int> digit(nn + 1, 0);
        int base = 1;

        // Precompute suffix sums and digit multiplications modulo mod
        for (int i = nn - 1; i >= 0; i--) {
            suffixSum[i] = mod_sum(suffixSum[i + 1], temp[i] - '0');
            digit[i] = mod_sum(mod_multiply(temp[i] - '0', base), digit[i + 1]);
            base = mod_multiply(base, 10);
        }

        vector<int> ans;
        for (auto& q : queries) {
            int l = conversion[q[0]];
            int r = conversion[q[1] + 1];
            if (r <= l) {
                ans.push_back(0);
                continue;
            }
            int power = binary_exponentiation(10, nn - r);
            int val = mod_multiply(mod_subtract(digit[l], digit[r]), mod_inverse(power));
            val = mod_multiply(val, mod_subtract(suffixSum[l], suffixSum[r])); // fixed to use mod_subtract and mod_multiply correctly
            ans.push_back(val);
        }
        return ans;
    }
};
