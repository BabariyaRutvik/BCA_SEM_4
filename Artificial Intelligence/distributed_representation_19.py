# 19. Implement a Python function to represent distributed representations in a connectionist model.
"""
Use: Used in connectionist AI and NLP to represent concepts as overlapping feature vectors rather than isolated symbols.
Process: Each vehicle is encoded as a vector of semantic features (engine, siren, heavy load, wheels, passengers).
Cosine similarity compares the angle between a query vector (Ambulance) and all other concept vectors.
Higher similarity scores reveal which concepts share the most semantic features.
"""

import math


# Function to create distributed representations and compute cosine similarity
def analyze_distributed_representations(concepts, query_concept):
    def cosine_similarity(vec_a, vec_b):
        dot = sum(a * b for a, b in zip(vec_a, vec_b))
        norm_a = math.sqrt(sum(a * a for a in vec_a))
        norm_b = math.sqrt(sum(b * b for b in vec_b))
        return dot / (norm_a * norm_b)

    query_vec = concepts[query_concept]
    similarities = {}

    for name, vec in concepts.items():
        if name != query_concept:
            similarities[name] = cosine_similarity(query_vec, vec)

    return similarities


# Real-life example: Semantic features of emergency and transport vehicles
# Features: [Has_Engine, Has_Siren, Carries_Heavy_Load, Two_Wheels, Carries_Passengers]
vehicle_features = {
    "Ambulance": [1, 1, 0, 0, 1],
    "Fire_Truck": [1, 1, 1, 0, 0],
    "City_Bus": [1, 0, 0, 0, 1],
    "Bicycle": [0, 0, 0, 1, 1]
}

query = "Ambulance"
results = analyze_distributed_representations(vehicle_features, query)

print("Distributed Feature Vectors:")
for name, vec in vehicle_features.items():
    print(f"- {name}: {vec}")

print(f"\nCosine Similarity with '{query}':")
for name, score in sorted(results.items(), key=lambda item: item[1], reverse=True):
    print(f"- {name}: {score:.4f}")

"""
Output:
Distributed Feature Vectors:
- Ambulance: [1, 1, 0, 0, 1]
- Fire_Truck: [1, 1, 1, 0, 0]
- City_Bus: [1, 0, 0, 0, 1]
- Bicycle: [0, 0, 0, 1, 1]

Cosine Similarity with 'Ambulance':
- City_Bus: 0.8165
- Fire_Truck: 0.6667
- Bicycle: 0.4082
"""
