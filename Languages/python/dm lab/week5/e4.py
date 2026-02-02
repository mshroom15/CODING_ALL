import matplotlib.pyplot as plt

a1,d,r,n=2,3,2,5
arith=[a1+i*d for i in range(n)]
geom=[a1*r**i for i in range(n)]
x=range(n)

plt.plot(x,arith,marker='o',label='Arithmetic')
plt.plot(x,geom,marker='s',label='Geometric')
plt.title("Arithmetic vs Geometric Sequences")
plt.xlabel("n")
plt.ylabel("Value")
plt.legend()
plt.grid(True)
plt.show()
