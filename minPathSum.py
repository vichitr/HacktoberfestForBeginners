class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        r = len(grid)
        c = len(grid[0])
        dp = [[0 for i in range(c)] for j in range(r)]
        dp[0][0] = grid[0][0]
        for i in range(1, c):
            dp[0][i] = dp[0][i - 1] + grid[0][i]
        for i in range(1, r):
            dp[i][0] = dp[i - 1][0] + grid[i][0]
        for i in range(1, r):
            for j in range(1, c):
                dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1])
        return dp[-1][-1]
