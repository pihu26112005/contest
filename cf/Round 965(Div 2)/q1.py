def solve():
    t = int(input())
    for _ in range(t):
        xc, yc, k = map(int, input().split())
        p = []
        if(k%2 == 0):
            for i in range(int(k/2)):
                p.append((xc + (i+1), yc))
                p.append((xc - (i+1), yc))
        else:
            # Place the first point at (xc, yc)
            p.append((xc, yc))
            for i in range(int(k/2)):
                p.append((xc + (i+1), yc))
                p.append((xc - (i+1), yc))
        
        for x, y in p:
            print(x, y)

solve()
