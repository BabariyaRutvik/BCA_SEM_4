# 34. Write Python code to simulate the reasoning process in a rule-based expert system with uncertainty.
"""
Use: Used in vehicle/equipment fault diagnosis when sensor readings and rules have varying confidence levels.
Process: Observed symptoms are stored with confidence values between 0 and 1.
Each rule computes its conclusion confidence as min(symptom confidences) * rule_confidence.
The system ranks inferred faults so technicians inspect the most likely issue first.
"""

# Observed car engine symptoms with confidence scores
symptoms = {
    "engine_overheating": 0.90,
    "coolant_leak_visible": 0.80,
    "weak_battery_crank": 0.40
}

# Rules: (required_symptoms, fault_diagnosis, rule_confidence)
expert_rules = [
    (["engine_overheating", "coolant_leak_visible"], "Radiator_Or_Hose_Leak", 0.95),
    (["engine_overheating"], "Thermostat_Failure", 0.65),
    (["weak_battery_crank"], "Battery_Needs_Replacement", 0.85)
]

diagnoses = []

print("Observed Vehicle Symptoms:")
for s, conf in symptoms.items():
    print(f"- {s}: {conf:.2f}")

print("\nRule Evaluation:")
for reqs, fault, rule_conf in expert_rules:
    if all(r in symptoms for r in reqs):
        min_symp = min(symptoms[r] for r in reqs)
        final_conf = min_symp * rule_conf
        diagnoses.append((fault, final_conf))
        print(f"Rule fired for {fault}: confidence = {final_conf:.3f}")

diagnoses.sort(key=lambda item: item[1], reverse=True)
print("\nRanked Fault Diagnoses:")
for fault, conf in diagnoses:
    print(f"- {fault}: {conf * 100:.1f}%")

"""
Output:
Observed Vehicle Symptoms:
- engine_overheating: 0.90
- coolant_leak_visible: 0.80
- weak_battery_crank: 0.40

Rule Evaluation:
Rule fired for Radiator_Or_Hose_Leak: confidence = 0.760
Rule fired for Thermostat_Failure: confidence = 0.585
Rule fired for Battery_Needs_Replacement: confidence = 0.340

Ranked Fault Diagnoses:
- Radiator_Or_Hose_Leak: 76.0%
- Thermostat_Failure: 58.5%
- Battery_Needs_Replacement: 34.0%
"""
