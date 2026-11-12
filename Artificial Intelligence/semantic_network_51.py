# 51. Write a Python program to represent knowledge using a semantic network and answer inheritance-based queries.
"""
Use: Used in knowledge graphs and ontology systems to represent concepts, properties, and IS-A hierarchies.
Process: Nodes store their own attributes and an 'is_a' link to a parent concept.
query_property() checks if a node directly has the requested property; if not, it follows 'is_a' links upward.
This allows child concepts (like Tesla_Model_3) to inherit attributes from parent concepts (like Vehicle).
"""

# Semantic network: node -> properties and 'is_a' parent link
semantic_net = {
    "Vehicle": {"has_wheels": True, "used_for": "Transport"},
    "Car": {"is_a": "Vehicle", "wheels_count": 4},
    "Electric_Car": {"is_a": "Car", "fuel_type": "Battery"},
    "Tesla_Model_3": {"is_a": "Electric_Car", "autopilot": True}
}


def query_property(concept, prop):
    current = concept
    while current in semantic_net:
        node = semantic_net[current]
        if prop in node:
            return node[prop]
        current = node.get("is_a")
    return None


queries = [
    ("Tesla_Model_3", "autopilot"),
    ("Tesla_Model_3", "fuel_type"),
    ("Tesla_Model_3", "wheels_count"),
    ("Tesla_Model_3", "used_for")
]

print("Semantic Network Inheritance Queries:")
for concept, prop in queries:
    print(f"- {concept}.{prop} => {query_property(concept, prop)}")

"""
Output:
Semantic Network Inheritance Queries:
- Tesla_Model_3.autopilot => True
- Tesla_Model_3.fuel_type => Battery
- Tesla_Model_3.wheels_count => 4
- Tesla_Model_3.used_for => Transport
"""
