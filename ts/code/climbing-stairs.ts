type Memo = Record<number, number>

const climbingStairs = (n: number, memo: Memo = {}) => {
  if (n <= 1) return 1;
  if (n in memo) return memo[n]
  memo[n] = climbingStairs(n - 1, memo) + climbingStairs(n - 2, memo)
  return memo[n]
}

const climbingStairsDp = (n: number, dp: Memo = {}) => {
  dp[0] = 1;
  dp[1] = 1;

  for (let i = 2; i <= n; i++) {
    dp[i] = dp[i - 1] + dp[i - 2]
  }

  return dp[n]
}

console.log(climbingStairs(30))
console.log(climbingStairsDp(30))