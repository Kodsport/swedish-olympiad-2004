import sys

def solve():
    # Läs in all indata
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    n = int(input_data[0])
    k = int(input_data[1])
    words = input_data[2:k+2]
    
    lengths = [len(w) for w in words]
    
    # dp[i] lagrar en tupel: (minsta möjliga maximala avvikelsen, minsta summan av kvadratavvikelser)
    # för suffixet av ord från index i till k.
    # Vi använder kvadratsumman som "tie-breaker" för att få ett snyggare resultat vid likvärdiga val.
    dp = [(float('inf'), float('inf'))] * (k + 1)
    choice = [-1] * (k + 1)
    
    dp[k] = (0, 0)
    
    for i in range(k - 1, -1, -1):
        current_len = -1
        best_val = (float('inf'), float('inf'))
        best_j = -1
        
        for j in range(i, k):
            # Lägg till längden av ordet + ett mellanslag
            current_len += lengths[j] + 1
            
            # Om raden överstiger n tecken, bryt loopen då vi inte får plats med fler ord
            if current_len > n:
                break
            
            dev = n - current_len
            next_max_dev, next_sum_sq = dp[j + 1]
            
            # Utvärdera detta val
            val_max = max(dev, next_max_dev)
            val_sum_sq = dev * dev + next_sum_sq
            
            val = (val_max, val_sum_sq)
            
            if val < best_val:
                best_val = val
                best_j = j
                
        dp[i] = best_val
        choice[i] = best_j
        
    # Återskapa och skriv ut texten enligt de optimala valen från DP:n
    curr = 0
    while curr < k:
        nxt = choice[curr]
        print(" ".join(words[curr:nxt + 1]))
        curr = nxt + 1

if __name__ == '__main__':
    solve()
