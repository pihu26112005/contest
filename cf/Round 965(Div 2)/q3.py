def find_median(arr):
    # This function returns the median of the array.
    arr.sort()
    length = len(arr)
    return arr[(length - 1) // 2]

def increase_and_find(arr, k, id, max_score, n):
    if(k==0):
        for j in range(n):
            # Calculate the score for the incremented candidate
            ci = arr[:j] + arr[j+1:]
            current_score = arr[j] + find_median(ci)
            max_score = max(max_score, current_score)
        return max_score
    
    max_score = float('-inf');

    for i in range(len(id)):
        # Increment the best candidate(s) up to k times
        arr[id[i]] += 1

        # Recursively call the function to find the maximum score
        max_score = max(max_score, increase_and_find(arr, k-1, id, max_score, n))
        
      
        arr[id[i]] -= 1
    
    return max_score
    


def solve():
    t = int(input())
    results = []
    
    for _ in range(t):
        n, k = map(int, input().split())
        a = list(map(int, input().split()))
        b = list(map(int, input().split()))
        
        # Get the initial maximum score without operations
        max_score = 0
        
        for i in range(n):
            # Form the array ci (a without the i-th element)
            ci = a[:i] + a[i+1:]
            current_score = a[i] + find_median(ci)
            max_score = max(max_score, current_score)
        
        # We now consider the possible improvements by applying operations.
        id = []
        
        for i in range(n):
            if b[i] == 1:
                id.append(i)
        
        
        max_score = increase_and_find(a, k, id, max_score, n)
        
        results.append(max_score)
    
    for result in results:
        print(result)

solve()