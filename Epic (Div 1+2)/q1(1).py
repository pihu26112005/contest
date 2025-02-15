def solve():
    t = int(input())
    for _ in range(t):
        n, m, k = map(int, input().split())

        a,b=0,0

        if(k<=n):
            a = k
        else:
            a = n

        if(k<=m):
            b = k
        else:
            b = m

        print(a*b)
                    

solve()