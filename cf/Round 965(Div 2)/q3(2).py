def find_median(arr):
    # This function returns the median of the array.
    arr.sort()
    length = len(arr)
    return arr[(length - 1) // 2]

def solve():
    t = int(input())
    results = []
    
    for _ in range(t):
        n, k = map(int, input().split())
        a = list(map(int, input().split()))
        b = list(map(int, input().split()))
        
        # Get the initial maximum score without any operations
        max_score = 0
        
        for i in range(n):
            ci = a[:i] + a[i+1:]
            current_score = a[i] + find_median(ci)
            max_score = max(max_score, current_score)
        
        # DP array to store the maximum score after j increments
        dp = [max_score] * (k + 1)
        
        # Get indices where b[i] == 1
        ids = [i for i in range(n) if b[i] == 1]
        
        # Bottom-up DP
        for j in range(1, k + 1):
            current_max = dp[j - 1]  # Start with the previous max score
            for i in ids:
                # Increment a[i] by 1 and calculate new score
                a[i] += 1
                ci = a[:i] + a[i+1:]
                new_score = a[i] + find_median(ci)
                current_max = max(current_max, new_score)
                a[i] -= 1  # Revert increment to maintain original array for further operations
            
            dp[j] = current_max  # Store the best score after j increments
        
        results.append(dp[k])  # The best score after k increments
    
    for result in results:
        print(result)

solve()
