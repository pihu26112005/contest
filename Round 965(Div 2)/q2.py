def solve():
    t = int(input())
    for _ in range(t):
        n = int(input())
        p = list(map(int, input().split()))
        # Reverse p to create q
        # q = p[::-1]
        q = [p[-1]] + p[:-1]
        # Print the permutation q
        print(' '.join(map(str, q)))

# Run the solution
solve()

