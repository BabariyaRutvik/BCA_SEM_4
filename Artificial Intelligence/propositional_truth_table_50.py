# 50. Write a Python program to evaluate propositional logic expressions and generate truth tables for given formulas.
"""
Use: Used in digital logic design, formal verification, and AI reasoning to check formula validity.
Process: itertools.product generates all True/False combinations for propositional variables P and Q.
For each row, logical operators (AND, OR, NOT, IMPLIES) evaluate the formula.
The formatted truth table is printed row by row showing T/F values.
"""

import itertools


def implies(p, q):
    return (not p) or q


def fmt(val):
    return "T" if val else "F"


print("Truth Table for Formula: (P AND Q) -> (P OR Q)")
print("P | Q | P AND Q | P OR Q | (P AND Q) -> (P OR Q)")
print("--+---+---------+--------+----------------------")

for p, q in itertools.product([True, False], repeat=2):
    p_and_q = p and q
    p_or_q = p or q
    result = implies(p_and_q, p_or_q)
    print(f"{fmt(p)} | {fmt(q)} |    {fmt(p_and_q)}    |   {fmt(p_or_q)}    |          {fmt(result)}")

"""
Output:
Truth Table for Formula: (P AND Q) -> (P OR Q)
P | Q | P AND Q | P OR Q | (P AND Q) -> (P OR Q)
--+---+---------+--------+----------------------
T | T |    T    |   T    |          T
T | F |    F    |   T    |          T
F | T |    F    |   T    |          T
F | F |    F    |   F    |          T
"""
