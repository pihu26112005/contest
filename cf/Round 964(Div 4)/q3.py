
def main():
    t = int(input())

    for _ in range(t):
        # n = int(input())
        # s = int(input())
        # m = int(input())
        nsm = list(map(int, input().split()))
        n = nsm[0]
        s = nsm[1]
        m = nsm[2]
        arr = []
        for i in range(n):
            # arr = list(map(int, input().split()))
            arr.append(list(map(int, input().split())))
        # print(arr)
        st = 0
        en = m
        finalarr = []
        finalarr.append(arr[0][0]-0)
        for i in range(1, n):
            finalarr.append(arr[i][0] - arr[i-1][1])
        finalarr.append(m - arr[n-1][1])       
        
        # print(finalarr)

        # check if there exist any element in finalarr which is greater or equal to s
        # if yes, then print the index of that element
        # else print -1
        for i in range(len(finalarr)):
            if finalarr[i] >= s:
                print("YES")
                break
        else:
            print("NO")

main()