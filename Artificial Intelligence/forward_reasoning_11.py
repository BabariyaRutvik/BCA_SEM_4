# 11. Implement a Python function that simulates forward reasoning in a rule-based system.
"""
Use: Used in data-driven expert systems to infer all possible conclusions from known symptoms or facts.
Process: Starting from initial facts, forward_reasoning() scans all IF-THEN rules.
When every condition of a rule is satisfied and its conclusion is not yet known, the rule fires and adds it.
The loop repeats until no more new facts can be inferred.
"""

# Function to simulate forward reasoning
def forward_reasoning(facts, rules):
    inferred = set(facts)
    print("Initial Facts:", inferred)

    while True:
        new_fact_added = False

        # Check each rule against current facts
        for conditions, conclusion in rules:
            if all(cond in inferred for cond in conditions) and conclusion not in inferred:
                print(f"Rule fired: IF {' AND '.join(conditions)} THEN {conclusion}")
                inferred.add(conclusion)
                new_fact_added = True

        # Stop when no new facts can be inferred
        if not new_fact_added:
            break

    return inferred


# Define initial facts and rules
initial_facts = ["Fever", "Cough", "Body_Ache"]

rules = [
    (["Fever", "Cough"], "Flu_Symptoms"),
    (["Flu_Symptoms", "Body_Ache"], "Possible_Flu"),
    (["Possible_Flu"], "Advise_Rest")
]

# Run forward reasoning
final_facts = forward_reasoning(initial_facts, rules)
print("\nFinal Inferred Facts:", sorted(final_facts))

"""
Output:
Initial Facts: {'Cough', 'Body_Ache', 'Fever'}
Rule fired: IF Fever AND Cough THEN Flu_Symptoms
Rule fired: IF Flu_Symptoms AND Body_Ache THEN Possible_Flu
Rule fired: IF Possible_Flu THEN Advise_Rest

Final Inferred Facts: ['Advise_Rest', 'Body_Ache', 'Cough', 'Fever', 'Flu_Symptoms', 'Possible_Flu']
"""
