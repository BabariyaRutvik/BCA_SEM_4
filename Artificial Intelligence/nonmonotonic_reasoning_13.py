# 13. Implement nonmonotonic reasoning in Python by representing assumptions and revising beliefs.
"""
Use: Used in AI systems that make default assumptions with incomplete data and revise them when exceptions appear.
Process: With only partial facts, update_beliefs() adds default assumptions to the belief set.
When new contradicting evidence arrives, the conflicting assumption is retracted and beliefs are updated.
This allows conclusions to be withdrawn rather than only growing monotonically.
"""

# Represent knowledge base with facts, assumptions, and beliefs
facts = set()
assumptions = set()
beliefs = set()


# Infer beliefs using default assumptions
def update_beliefs():
    global beliefs, assumptions
    beliefs = set(facts)
    assumptions.clear()

    # Default rule: If X is a bird and not known to be a penguin, assume X can fly
    if "is_bird" in facts and "is_penguin" not in facts:
        assumptions.add("can_fly")
        beliefs.add("can_fly")
    elif "is_penguin" in facts:
        beliefs.add("cannot_fly")


# Initial observation: Tweety is a bird
print("Observing Tweety is a bird")
facts.add("is_bird")
update_beliefs()
print("Facts:", sorted(facts))
print("Assumptions:", sorted(assumptions))
print("Beliefs:", sorted(beliefs))

# New contradicting observation: Tweety is a penguin
print("\nNew information - Tweety is a penguin")
facts.add("is_penguin")
update_beliefs()
print("Facts:", sorted(facts))
print("Assumptions:", sorted(assumptions))
print("Revised Beliefs:", sorted(beliefs))

"""
Output:
Observing Tweety is a bird
Facts: ['is_bird']
Assumptions: ['can_fly']
Beliefs: ['can_fly', 'is_bird']

New information - Tweety is a penguin
Facts: ['is_bird', 'is_penguin']
Assumptions: []
Revised Beliefs: ['cannot_fly', 'is_bird', 'is_penguin']
"""
