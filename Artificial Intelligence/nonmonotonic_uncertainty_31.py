# 31. Write a Python program to demonstrate nonmonotonic logic for reasoning under uncertainty.
"""
Use: Used in autonomous systems and weather advisories when default decisions must be revised under uncertain new evidence.
Process: Initially, a drone delivery system assumes clear flight if no storm alert exists.
When uncertain radar evidence (rain probability >= 0.6) arrives, the default assumption is retracted.
Beliefs and flight decisions are revised nonmonotonically to hold delivery.
"""

# Evaluate flight decision using default assumptions and uncertain weather data
def evaluate_flight_beliefs(radar_rain_prob, visibility_km):
    assumptions = set()
    beliefs = set()

    # Default assumption under low uncertainty
    if radar_rain_prob < 0.5 and visibility_km >= 3.0:
        assumptions.add("safe_flight_by_default")
        beliefs.add("approve_drone_delivery")
    else:
        beliefs.add("weather_hazard_likely")
        beliefs.add("hold_drone_delivery")

    return assumptions, beliefs


# Initial state: low rain probability, good visibility
print("Case 1: Morning Dispatch (Rain Prob = 0.20, Visibility = 6.0 km)")
a1, b1 = evaluate_flight_beliefs(0.20, 6.0)
print("Assumptions:", sorted(a1))
print("Beliefs:", sorted(b1))

# Updated uncertain radar report: rain probability rises to 0.75
print("\nCase 2: Updated Radar Report (Rain Prob = 0.75, Visibility = 2.0 km)")
a2, b2 = evaluate_flight_beliefs(0.75, 2.0)
print("Assumptions:", sorted(a2))
print("Revised Beliefs:", sorted(b2))

"""
Output:
Case 1: Morning Dispatch (Rain Prob = 0.20, Visibility = 6.0 km)
Assumptions: ['safe_flight_by_default']
Beliefs: ['approve_drone_delivery']

Case 2: Updated Radar Report (Rain Prob = 0.75, Visibility = 2.0 km)
Assumptions: []
Revised Beliefs: ['hold_drone_delivery', 'weather_hazard_likely']
"""
