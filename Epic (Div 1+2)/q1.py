def fill_all_blocks_at_distance_k(arr, n, m, k, i, j,min):
    for r in range(n):
        for c in range(m):
            if (max(abs(r-i),abs(c-j)) >= k):
                arr[r][c] = min

def solve():
    t = int(input())
    for _ in range(t):
        n, m, k = map(int, input().split())

        arr = [[0 for _ in range(m)] for _ in range(n)]
        # print(arr)

        # m = {}
        min = 1
        
        for i in range(n):
            for j in range(m):
                if(arr[i][j] == 0):
                    arr[i][j] = min
                    # m[min] = (i, j)
                    fill_all_blocks_at_distance_k(arr, n, m, k, i, j, min)
                    min += 1

        print(min-1)
                    

solve()