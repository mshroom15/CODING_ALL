def edc(a,b):
    if b==0: return a,1,0
    g,x1,y1=edc(b,a%b)
    x=y1
    y=x1-(a//b)*y1
    return g,x,y
def inverse(a,n):
    g,x,y=edc(a,n)
    if g!=1:
        return False
    else: return x%n 
print(inverse(11,31))

a=17*11-((17*11)//31)*31
print(a)