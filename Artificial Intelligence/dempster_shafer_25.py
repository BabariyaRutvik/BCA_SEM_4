# 25. Implement a Python program to simulate Dempster-Shafer theory for uncertainty reasoning.
"""
Use: Used in medical diagnosis and sensor fusion to combine uncertain evidence from multiple independent sources.
Process: Each source assigns belief masses to single or combined hypotheses (such as {Pneumonia, Bronchitis}).
Dempster's rule intersects all pairs of hypotheses from both sources and accumulates conflicting mass K.
Remaining masses are normalized by (1 - K) to produce combined belief masses.
"""

# Combine two mass functions m1 and m2 using Dempster's Rule of Combination
def dempster_combine(m1, m2):
    combined = {}
    conflict = 0.0

    for s1, v1 in m1.items():
        for s2, v2 in m2.items():
            intersection = s1.intersection(s2)
            product = v1 * v2
            if not intersection:
                conflict += product
            else:
                combined[intersection] = combined.get(intersection, 0.0) + product

    # Normalize by (1 - conflict)
    normalizer = 1.0 - conflict
    for key in combined:
        combined[key] /= normalizer

    return combined, conflict


# Real-life example: Medical diagnosis combining Blood Test (m1) and Chest X-Ray (m2)
# Hypotheses: P = Pneumonia, B = Bronchitis, Frame = {P, B}
P = frozenset(["Pneumonia"])
B = frozenset(["Bronchitis"])
PB = frozenset(["Pneumonia", "Bronchitis"])

blood_test_m1 = {P: 0.6, B: 0.2, PB: 0.2}
xray_test_m2 = {P: 0.7, B: 0.1, PB: 0.2}

combined_mass, conflict_k = dempster_combine(blood_test_m1, xray_test_m2)

print(f"Conflict Factor (K): {conflict_k:.4f}")
print("\nCombined Belief Masses:")
for hypothesis, mass in combined_mass.items():
    print(f"- {sorted(hypothesis)}: {mass:.4f}")

"""
Output:
Conflict Factor (K): 0.2000

Combined Belief Masses:
- ['Pneumonia']: 0.8500
- ['Bronchitis']: 0.1000
- ['Bronchitis', 'Pneumonia']: 0.0500
"""
