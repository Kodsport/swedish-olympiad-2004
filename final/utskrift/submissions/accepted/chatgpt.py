def solve():
    import sys
    sys.setrecursionlimit(10**5)
    n = int(input())
    k = int(input())
    words = [input() for _ in range(k)]

    # DP: dp[i] = (bästa avvikelse från ord i, nästa index)
    from functools import lru_cache

    @lru_cache(None)
    def dp(i):
        if i == k:
            return (0, -1)  # ingen avvikelse kvar
        best = (10**9, -1)  # (maxAvvikelse, nextIndex)
        length = 0
        for j in range(i, k):
            word_len = len(words[j])
            if j == i:
                length = word_len
            else:
                length += 1 + word_len  # +1 mellanslag
            if length > n:  # får inte överstiga n
                break
            avvikelse = abs(length - n)
            rest_avvikelse, _ = dp(j + 1)
            worst = max(avvikelse, rest_avvikelse)
            if worst < best[0]:
                best = (worst, j + 1)
        return best

    # backtrack
    lines = []
    i = 0
    while i < k:
        best = (10**9, -1)
        length = 0
        for j in range(i, k):
            word_len = len(words[j])
            if j == i:
                length = word_len
            else:
                length += 1 + word_len
            if length > n:
                break
            avvikelse = abs(length - n)
            rest_avvikelse, _ = dp(j + 1)
            worst = max(avvikelse, rest_avvikelse)
            if worst < best[0]:
                best = (worst, j + 1)
                best_line = words[i:j+1]
        lines.append(" ".join(best_line))
        i = best[1]

    # skriv ut
    for line in lines:
        print(line)


if __name__ == "__main__":
    solve()
