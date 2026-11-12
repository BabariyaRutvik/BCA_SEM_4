
# Program 10: First-Order Predicate Logic
"""
Use: Used to represent objects, properties, relationships, and quantified statements in AI knowledge bases.
Process: Predicates such as Student(person), Learner(person), and Studies(person, subject) are modeled as functions.
Universal rules ("Every student is a learner") are evaluated over all objects in the domain.
Existential quantification ("at least one student exists") is checked using Python's any() function.
"""

# Store objects
people = ["Rutvik", "Dhaval"]

# Define predicates
def Student(person):
    return person in people

def Learner(person):
    return Student(person)

def Studies(person, subject):
    return person == "Rutvik" and subject == "Python"


# Represent knowledge
print("Knowledge Base:")

print("Student(Rutvik):", Student("Rutvik"))
print("Student(Dhaval):", Student("Dhaval"))
print("Studies(Rutvik, Python):", Studies("Rutvik", "Python"))

# Apply the rule:
# Every student is a learner

print("\nApplying Rule: Every Student is a Learner")

for person in people:

    if Student(person):
        print(person, "is a Learner")

# Check existential quantifier
print("\nDoes at least one student exist?")

if any(Student(person) for person in people):
    print("Yes, a student exists.")
else:
    print("No student exists.")

"""
Output:
Knowledge Base:
Student(Rutvik): True
Student(Dhaval): True
Studies(Rutvik, Python): True

Applying Rule: Every Student is a Learner
Rutvik is a Learner
Dhaval is a Learner

Does at least one student exist?
Yes, a student exists.
"""
