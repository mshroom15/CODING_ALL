import matplotlib.pyplot as plt
A=[1,2,3]
B=[2,3,3]
mapping =dict(zip(A,B))
plt.scatter(A, [1]*len(A), color='blue',label ='Domain')
plt.scatter(B, [2]*len(B), color='red',label ='Codomain')
for a,b in mapping.items():
    plt.plot([a,b],[1,2],'k-')
plt.yticks([1,2],['domain(A)','Codomain(B)'])
plt.legend()
plt.title("Visual Representation of Mapping f : A to B")
plt.show()