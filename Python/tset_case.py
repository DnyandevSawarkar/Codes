# cook your dish here
test = int(input())
x,y = input().split()
x = int(x)
y = int(y)
if ((1<= test <= 100) & (1<=x) & (y<=6)):
    if ((x+y)>=6):
        print("YES")
    else:
        print("NO")
    