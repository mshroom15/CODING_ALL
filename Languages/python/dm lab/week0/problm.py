num = int(input("ENTER AN NUMBER")) 
i =2
while i*i<=num:
    while num%i==0:
        print(i,end=" ")
        num//=i
    i+=1
if num>1:
    print(num)



    
        