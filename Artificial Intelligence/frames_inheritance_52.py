# 52. Write a Python program to represent knowledge using frames (slots and fillers) and retrieve inherited attribute values.
"""
Use: Used in structured knowledge representation (like university or medical records) to group object attributes.
Process: Each Frame holds a name, an optional parent frame, and a dictionary of slots (attributes) and fillers (values).
get_slot() looks up a slot in the current frame first and recursively checks the parent frame if missing.
Child frames inherit defaults from parent frames while overriding specific slots when needed.
"""


class Frame:

    def __init__(self, name, parent=None, slots=None):
        self.name = name
        self.parent = parent
        self.slots = slots or {}

    def get_slot(self, slot_name):
        if slot_name in self.slots:
            return self.slots[slot_name]
        if self.parent is not None:
            return self.parent.get_slot(slot_name)
        return None


# Real-life example: University Student Frame Hierarchy
person_frame = Frame("Person", slots={"species": "Human", "has_id": True})
student_frame = Frame("Student", parent=person_frame, slots={"role": "Learner", "library_access": True})
bca_student = Frame("Rutvik", parent=student_frame, slots={"course": "BCA", "semester": 5})

print("Frame Slot Retrieval for:", bca_student.name)
for slot in ["course", "semester", "role", "library_access", "species"]:
    print(f"- {slot}: {bca_student.get_slot(slot)}")

"""
Output:
Frame Slot Retrieval for: Rutvik
- course: BCA
- semester: 5
- role: Learner
- library_access: True
- species: Human
"""
