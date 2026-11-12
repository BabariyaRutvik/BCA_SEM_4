# 9. Create a Python class to represent a knowledge base and use it to store facts and rules.
"""
Use: Used to organize and store domain facts and logical rules for intelligent agents and expert systems.
Process: The KnowledgeBase class maintains separate lists for facts and rules.
Methods add_fact() and add_rule() insert new knowledge, while display() prints all stored entries.
This structure forms the foundation for rule-based inference engines.
"""
# Create Knowledge Base class
class KnowledgeBase:

    def __init__(self):
        self.facts = []
        self.rules = []

    # Store facts
    def add_fact(self, fact):
        self.facts.append(fact)

    # Store rules
    def add_rule(self, rule):
        self.rules.append(rule)

    # Display facts and rules
    def display(self):

        print("Facts:")
        for fact in self.facts:
            print("-", fact)

        print("\nRules:")
        for rule in self.rules:
            print("-", rule)


# Create an object
kb = KnowledgeBase()

# Add facts
kb.add_fact("Fever")
kb.add_fact("Cough")

# Add rules
kb.add_rule("IF Fever AND Cough THEN Possible Flu")

# Display Knowledge Base
kb.display()

"""
Output:
Facts:
- Fever
- Cough

Rules:
- IF Fever AND Cough THEN Possible Flu
"""

