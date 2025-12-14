def set_to_bitstring(U, S):
	return [1 if x in S else 0 for x in U]
def bitstring_to_set(U, bits):
	return {U[i] for i, bit in enumerate(bits) if bit == 1}
U = [1, 2, 3, 4, 5, 6]
A = {2, 4, 6}
bits = set_to_bitstring(U, A)
print("Bitstring for A:", bits)
print("Reconstructed Set:", bitstring_to_set(U, bits))