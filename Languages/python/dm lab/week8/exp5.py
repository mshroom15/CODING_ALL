import matplotlib.pyplot as plt

n=10
a=list(range(20))
residues=[x%n for x in a]

plt.stem(a,residues)
plt.title("Residue Classes modulo 10")
plt.xlabel("a")
plt.ylabel("a mod 10")
plt.show()
