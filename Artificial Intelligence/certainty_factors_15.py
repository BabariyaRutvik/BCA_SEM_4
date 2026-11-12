# 15. Create a Python program to simulate certainty factors in rule-based reasoning.
"""
Use: Used in diagnostic expert systems (like MYCIN) when facts and rules carry degrees of confidence.
Process: For each rule, the minimum certainty factor (CF) among its AND conditions is multiplied by the rule's CF.
When multiple rules support the same conclusion, combine_cf() merges them using CF1 + CF2 * (1 - CF1).
This produces a combined confidence score between 0 and 1 for the final diagnosis.
"""

# Function to combine two positive certainty factors
def combine_cf(cf1, cf2):
    return cf1 + cf2 * (1 - cf1)


# Facts with their certainty factors
fact_cf = {
    "Fever": 0.8,
    "Cough": 0.7,
    "Headache": 0.6
}

# Rules: (conditions, conclusion, rule_cf)
rules = [
    (["Fever", "Cough"], "Flu", 0.9),
    (["Headache"], "Flu", 0.5)
]

conclusion_cf = {}

print("Initial Facts and Certainty Factors:")
for fact, cf in fact_cf.items():
    print(f"- {fact}: {cf}")

print("\nEvaluating Rules:")
for conditions, conclusion, rule_cf in rules:
    # Minimum CF among conditions (AND combination)
    min_cond_cf = min(fact_cf[c] for c in conditions)
    inferred_cf = min_cond_cf * rule_cf
    print(f"Rule {conditions} => {conclusion} | Inferred CF = {inferred_cf:.4f}")

    # Combine CF if conclusion already has a CF
    if conclusion in conclusion_cf:
        conclusion_cf[conclusion] = combine_cf(conclusion_cf[conclusion], inferred_cf)
    else:
        conclusion_cf[conclusion] = inferred_cf

print("\nFinal Combined Certainty Factors:")
for conclusion, cf in conclusion_cf.items():
    print(f"- {conclusion}: {cf:.4f}")

"""
Output:
Initial Facts and Certainty Factors:
- Fever: 0.8
- Cough: 0.7
- Headache: 0.6

Evaluating Rules:
Rule ['Fever', 'Cough'] => Flu | Inferred CF = 0.6300
Rule ['Headache'] => Flu | Inferred CF = 0.3000

Final Combined Certainty Factors:
- Flu: 0.7410
"""
