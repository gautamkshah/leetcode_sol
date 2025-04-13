class Solution {
public:
    bool solve(int n, int target, vector<int>& dp, int mask) {
        if (target <= 0) {
            // If odd bits used, it's Bob's turn → Alice made the last move → Alice wins
            // If even bits used, it's Alice's turn → Bob made the last move → Alice loses
            return (countBits(mask) % 2 == 1);
        }
        if (dp[mask] != -1) {
            return dp[mask];
        }

        int bitsUsed = countBits(mask);
        bool isAliceTurn = (bitsUsed % 2 == 0);

        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                continue; // Skip if number (i+1) is already picked
            }

            int newMask = mask | (1 << i); // Mark (i+1) as picked
            if (isAliceTurn) {
                // Alice's turn: If she can win by picking (i+1), return true
                if (solve(n, target - (i + 1), dp, newMask)) {
                    return dp[mask] = true;
                }
            } else {
                // Bob's turn: If any move leads to Alice losing, return false
                if (!solve(n, target - (i + 1), dp, newMask)) {
                    return dp[mask] = false;
                }
            }
        }

        // If Alice's turn and no winning move → she loses
        // If Bob's turn and all moves lead to Alice winning → she wins
        return dp[mask] = !isAliceTurn;
    }

    bool canIWin(int n, int target) {
        if (target == 0) {
            return true; // Alice wins immediately
        }
        if (n * (n + 1) / 2 < target) {
            return false; // Impossible to reach target
        }
        vector<int> dp(1 << n, -1); // DP table for memoization
        return solve(n, target, dp, 0); // Start with mask=0 (no numbers picked)
    }

private:
    int countBits(int mask) {
        int count = 0;
        while (mask) {
            count++;
            mask &= (mask - 1); // Brian Kernighan's algorithm
        }
        return count;
    }
};