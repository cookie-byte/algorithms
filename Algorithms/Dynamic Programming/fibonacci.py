

n=int(input("Enter value for n"))
if n==1 or n==2:
    print(1)
else:
    l=[]
    l.insert(0,1)
    l.insert(1,1)
    i=2
    while(i<=n-1):
        b=l[i-1]+l[i-2]
        l.insert(i,b)
        i+=1
print("The {}th fibonacci number is {}".format(n,l[n-1]))