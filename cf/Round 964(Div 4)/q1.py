t = int(input())

for _ in range(t):
    n = int(input())
    
    digit1 = n // 10  
    digit2 = n % 10   
    sum_of_digits = digit1 + digit2
    
    print(sum_of_digits)
