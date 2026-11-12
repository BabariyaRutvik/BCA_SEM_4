# 26. Create a Python program that models a simple symbolic AI system using rules and logic.
"""
Use: Used in business decision systems (like bank loan approval) where transparent, explainable logic is required.
Process: Applicant attributes are stored as symbolic facts (e.g., high_credit_score, stable_income).
The evaluate() method applies explicit IF-THEN logical rules to infer risk level, loan approval, and discounts.
Each conclusion is directly traceable to the symbolic rules that triggered it.
"""

# Symbolic AI System for Bank Loan Eligibility Evaluation
class SymbolicLoanAdvisor:

    def __init__(self, applicant_facts):
        self.facts = set(applicant_facts)

    def evaluate(self):
        inferred = set(self.facts)

        # Logical rules
        if "high_credit_score" in inferred and "stable_income" in inferred:
            inferred.add("low_default_risk")

        if "low_default_risk" in inferred and "no_active_defaults" in inferred:
            inferred.add("loan_approved")

        if "loan_approved" in inferred and "existing_customer" in inferred:
            inferred.add("interest_discount_eligible")

        return inferred


# Real-life example: Evaluating a home loan applicant
applicant_profile = [
    "high_credit_score",
    "stable_income",
    "no_active_defaults",
    "existing_customer"
]

advisor = SymbolicLoanAdvisor(applicant_profile)
decisions = advisor.evaluate()

print("Applicant Facts:", applicant_profile)
print("\nSymbolic Inferences:")
print("- Low Default Risk:", "low_default_risk" in decisions)
print("- Loan Approved:", "loan_approved" in decisions)
print("- Interest Discount Eligible:", "interest_discount_eligible" in decisions)

"""
Output:
Applicant Facts: ['high_credit_score', 'stable_income', 'no_active_defaults', 'existing_customer']

Symbolic Inferences:
- Low Default Risk: True
- Loan Approved: True
- Interest Discount Eligible: True
"""
