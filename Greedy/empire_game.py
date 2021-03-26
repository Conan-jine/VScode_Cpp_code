N=int(input())
s=input().split()
left=int(s[0]);
right=int(s[1]);
arr=[]
for i in range(1, N+1):
    k=input().split()
    arr.append((int(k[0]), int(k[1])))
arr.sort(key=lambda x:x[0]*x[1])
ans=0
for i in range(0, N):
    if left//arr[i][1] > ans:
        ans=left//arr[i][1]
    left*=arr[i][0]

print(ans)