# 29. Create a Python class to simulate forward and backward reasoning in a logic programming language.
"""
Use: Used in logic programming and troubleshooting engines that support both data-driven and goal-driven queries.
Process: The LogicEngine class stores facts and (conditions, conclusion) rules.
forward_reason() starts from known facts and repeatedly fires rules to derive all possible conclusions.
backward_reason(goal) starts from a target goal and recursively checks if rules and facts can prove it.
"""

# Logic Programming Engine supporting both Forward and Backward Reasoning
class LogicEngine:

    def __init__(self, facts, rules):
        self.facts = set(facts)
        self.rules = rules  # List of (conditions, conclusion)

    # Forward reasoning: derive all possible conclusions from known facts
    def forward_reason(self):
        inferred = set(self.facts)
        while True:
            added = False
            for conditions, conclusion in self.rules:
                if all(c in inferred for c in conditions) and conclusion not in inferred:
                    inferred.add(conclusion)
                    added = True
            if not added:
                break
        return inferred

    # Backward reasoning: verify if a specific goal can be proven
    def backward_reason(self, goal):
        if goal in self.facts:
            return True
        for conditions, conclusion in self.rules:
            if conclusion == goal:
                if all(self.backward_reason(c) for c in conditions):
                    return True
        return False


# Real-life example: IT Helpdesk Network Troubleshooting System
known_facts = ["router_power_off", "cable_unplugged"]
troubleshooting_rules = [
    (["cable_unplugged"], "no_power_supply"),
    (["router_power_off", "no_power_supply"], "internet_down"),
    (["internet_down"], "plug_power_cable")
]

engine = LogicEngine(known_facts, troubleshooting_rules)

print("Known Facts:", known_facts)
print("\nForward Reasoning (All Derived Facts):")
print(sorted(engine.forward_reason()))

goal_to_check = "plug_power_cable"
print(f"\nBackward Reasoning (Can we prove '{goal_to_check}'?):", engine.backward_reason(goal_to_check))

"""
Output:
Known Facts: ['router_power_off', 'cable_unplugged']

Forward Reasoning (All Derived Facts):
['cable_unplugged', 'internet_down', 'no_power_supply', 'plug_power_cable', 'router_power_off']

Backward Reasoning (Can we prove 'plug_power_cable'?): True
"""
