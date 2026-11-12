# 53. Write a Python program to implement fuzzy sets and perform union, intersection, complement and alpha-cut operations.
"""
Use: Used in fuzzy control and decision systems to handle vague concepts like 'Warm' or 'Humid' using degrees (0..1).
Process: Fuzzy sets A and B map elements to membership degrees in [0, 1].
Union takes max(A[x], B[x]), Intersection takes min(A[x], B[x]), and Complement takes 1 - A[x].
Alpha-cut returns all elements whose membership degree meets or exceeds threshold alpha.
"""

# Fuzzy sets over afternoon temperatures (C)
A_warm = {20: 0.2, 25: 0.6, 30: 0.9, 35: 1.0}
B_humid = {20: 0.4, 25: 0.8, 30: 0.5, 35: 0.3}

union_set = {x: round(max(A_warm[x], B_humid[x]), 2) for x in A_warm}
intersection_set = {x: round(min(A_warm[x], B_humid[x]), 2) for x in A_warm}
complement_a = {x: round(1.0 - A_warm[x], 2) for x in A_warm}

alpha = 0.6
alpha_cut_a = [x for x, mu in A_warm.items() if mu >= alpha]

print("Fuzzy Set A (Warm):", A_warm)
print("Fuzzy Set B (Humid):", B_humid)
print("\nUnion (A U B):", union_set)
print("Intersection (A n B):", intersection_set)
print("Complement (not A):", complement_a)
print(f"Alpha-cut of A (alpha = {alpha}):", alpha_cut_a)

"""
Output:
Fuzzy Set A (Warm): {20: 0.2, 25: 0.6, 30: 0.9, 35: 1.0}
Fuzzy Set B (Humid): {20: 0.4, 25: 0.8, 30: 0.5, 35: 0.3}

Union (A U B): {20: 0.4, 25: 0.8, 30: 0.9, 35: 1.0}
Intersection (A n B): {20: 0.2, 25: 0.6, 30: 0.5, 35: 0.3}
Complement (not A): {20: 0.8, 25: 0.4, 30: 0.1, 35: 0.0}
Alpha-cut of A (alpha = 0.6): [25, 30, 35]
"""
