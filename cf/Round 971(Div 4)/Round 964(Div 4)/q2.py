def sameElementInArray(arr):
    for i in range(len(arr)):
        for j in range(i+1, len(arr)):
            if arr[i] != arr[j]:
                return False
    return True

def checkWinner(arr):
    win = 0;
    if(sameElementInArray(arr)):
        return 0
    if(arr[0] > arr[2] and arr[1] > arr[3]):
        win += 1
    elif(arr[0] > arr[2] and arr[1] == arr[3]):
        win += 1
    elif(arr[0] == arr[2] and arr[1] > arr[3]):
        win += 1

    return win

def main():
    t = int(input())

    for _ in range(t):
        arr = list(map(int, input().split()))
        # arr = []
        # for _ in range(4):
        #     n = int(input())
        #     arr.append(n)
            
        wins = 0

        if(sameElementInArray(arr)):
            print("0")
            continue 
            
            
        if(arr[0] == arr[1] and arr[2] == arr[3]):
            if(arr[0] > arr[2]):
                print("4")
            else:
                print("0")
            continue
        
        newarr = [[arr[0], arr[1], arr[2], arr[3]], 
                [arr[0], arr[1], arr[3], arr[2]], 
                [arr[1], arr[0], arr[2], arr[3]], 
                [arr[1], arr[0], arr[3], arr[2]]]
        
        for i in range(4):
            wins += checkWinner(newarr[i])
        
        print(wins)
        continue

main()