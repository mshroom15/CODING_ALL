a,b=map(int,input("enter range : ").split())
prime = [True]*(b+1)
prime[0]=prime[1]=False
i=2
while i*i<=b:
    if prime[i]==True:
        for j in range(i*i,b+1,i):
            prime[j]=False
    i+=1
if b==0 or b==1:
    print("none")
else :
    for k in range(2,b+1):
        if prime[k]==True:
            print(k,end=" ")


