import matplotlib.pyplot as plt

a=list(range(30))

res7=[x%7 for x in a]
res12=[x%12 for x in a]

plt.stem(a,res7)
plt.title("Residues modulo 7")
plt.xlabel("a")
plt.ylabel("a mod 7")
plt.show()

plt.stem(a,res12)
plt.title("Residues modulo 12")
plt.xlabel("a")
plt.ylabel("a mod 12")
plt.show()
