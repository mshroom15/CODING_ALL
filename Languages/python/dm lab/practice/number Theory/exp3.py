def extented_euclidean(a, b):
    if b ==0 : return a,1,0
    g , x1 , y1 = extented_euclidean(b,a%b)
    x=y1
    y = x1 - (a//b)*y1
    return g,x,y
def mod_inverse(a,n):
    g ,x,y=extented_euclidean(a,n)
    if (g!=1):
        raise ValueError("inverse doesn't exist")
    else:
        return x % n
a,n=11,31
print(mod_inverse(a,n))
