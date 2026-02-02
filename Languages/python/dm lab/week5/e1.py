def geometric_nth(a1,r,n):
    return a1*r**(n-1)

def geometric_sum(a1,r,n):
    return a1*(r**n-1)//(r-1) if r!=1 else a1*n


a1,r,n=2,2,5
print("5th term:",geometric_nth(a1,r,n))
print("Sum of 5 terms:",geometric_sum(a1,r,n))
