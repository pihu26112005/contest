def is_subsequence(s, t):
    it = iter(s)
    return all(char in it for char in t)

def solve(test_cases):
    results = []
    for s, t in test_cases:
        # Create a list from s to make modifications easier
        s_list = list(s)
        
        # Iterate through s and replace '?' with appropriate characters
        t_index = 0
        for i in range(len(s_list)):
            if s_list[i] == '?':
                if t_index < len(t) and is_subsequence(s_list[i+1:], t[t_index+1:]):
                    s_list[i] = t[t_index]
                    t_index += 1
                else:
                    s_list[i] = 'a'
        
        # Check if t is a subsequence of the modified s
        if is_subsequence(s_list, t):
            results.append(f"YES\n{''.join(s_list)}")
        else:
            results.append("NO")
    
    return results

# Read input
import sys
input = sys.stdin.read
data = input().split()
T = int(data[0])
index = 1
test_cases = []
for _ in range(T):
    s = data[index]
    t = data[index + 1]
    test_cases.append((s, t))
    index += 2

# Solve the problem
results = solve(test_cases)

# Print the results
for result in results:
    print(result)
