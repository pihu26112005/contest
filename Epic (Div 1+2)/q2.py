def find_winner(n, a, b):
    # Compare the last elements of both arrays
    if a[-1] == b[-1]:
        return "Bob"
    else:
        return "Alice"


def alice_move(n, a, b, removed_element):
    if removed_element != a[0]:
        if a[0] != b[0] and a[0] != b[-1]:
            return a.pop(0)
    if removed_element != a[-1]:
        if a[-1] != b[0] and a[-1] != b[-1]:
            return a.pop(-1)
    if a[0] != b[0] and a[0] != b[-1]:
        return a.pop(0)
    return a.pop(-1)

def bob_move(n, a, b, removed_element):
    if removed_element == b[0]:
        return b.pop(0)
    elif removed_element == b[-1]:
        return b.pop(-1)
    else:
        if b[0] != a[0] and b[0] != a[-1]:
            return b.pop(-1)
        else:
            return b.pop(0)

# Reading input
t = int(input())  # number of test cases
results = []
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    removed_element = 0

    for i in range(n-1):
        removed_element = alice_move(n, a, b, removed_element)
        # print("alice removed", removed_element)
        removed_element = bob_move(n, a, b, removed_element)
        # print("bob removed", removed_element)

    results.append(find_winner(n, a, b))

# Output results for all test cases
for result in results:
    print(result)