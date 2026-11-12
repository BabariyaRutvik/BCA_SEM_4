#1. Write a Python program to simulate a simple production system using a set of rules.
"""
Use: Used in rule-based AI and expert systems to automatically derive new conclusions from known facts.
Process: Starting from initial facts, the loop checks each IF-THEN rule. Whenever all conditions of a
rule are present in facts and its conclusion is missing, the rule fires and adds the conclusion.
This repeats until no new rules can fire.
"""

# init facts
facts = {"dark_clouds", "high_humidity"}

# production rules
rules = [
    (["dark_clouds", "high_humidity"], "rain_likely"),
    (["rain_likely"], "carry_umbrella"),
    (["high_temperature"], "switch_on_fan")
]

print("Initial Facts:", facts)

# production system

while True:
    rule_fired = False

    for conditions, conclusion in rules:

        # Check whether all conditions are met.
        if all(condition in facts for condition in conditions):
            if conclusion not in facts:
                print(f"Rule fired: {conditions} => {conclusion}")
                facts.add(conclusion)
                rule_fired = True
                break

    if not rule_fired:
        break

print("\nFinal Facts:", facts)

"""
Output:
Initial Facts: {'dark_clouds', 'high_humidity'}
Rule fired: ['dark_clouds', 'high_humidity'] => rain_likely
Rule fired: ['rain_likely'] => carry_umbrella

Final Facts: {'rain_likely', 'carry_umbrella', 'dark_clouds', 'high_humidity'}
"""
