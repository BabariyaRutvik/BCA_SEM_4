# 14. Write Python code to implement a basic Bayesian network and compute posterior probabilities.
"""
Use: Used for probabilistic reasoning under uncertainty by modeling cause-and-effect dependencies between events.
Process: Prior probabilities P(Rain) and conditional probabilities P(WetGrass | Rain) are stored in tables.
Using the law of total probability, the program computes P(WetGrass = True) across all cases.
Bayes' theorem then calculates the updated posterior probability P(Rain = True | WetGrass = True).
"""

# Prior probabilities for Rain
P_rain = {
    True: 0.2,
    False: 0.8
}

# Conditional probabilities P(WetGrass | Rain)
P_wet_given_rain = {
    True: 0.9,   # P(WetGrass=True | Rain=True)
    False: 0.1   # P(WetGrass=True | Rain=False)
}


# Compute posterior probability P(Rain=True | WetGrass=True) using Bayes' theorem
def compute_posterior_rain_given_wet():
    # Joint probabilities
    joint_rain_wet = P_rain[True] * P_wet_given_rain[True]
    joint_no_rain_wet = P_rain[False] * P_wet_given_rain[False]

    # Total probability P(WetGrass=True)
    p_wet = joint_rain_wet + joint_no_rain_wet

    # Posterior probability
    posterior = joint_rain_wet / p_wet
    return p_wet, posterior


p_wet, posterior_rain = compute_posterior_rain_given_wet()

print("Prior P(Rain = True):", P_rain[True])
print("P(WetGrass = True | Rain = True):", P_wet_given_rain[True])
print("P(WetGrass = True | Rain = False):", P_wet_given_rain[False])
print(f"\nTotal P(WetGrass = True): {p_wet:.4f}")
print(f"Posterior P(Rain = True | WetGrass = True): {posterior_rain:.4f}")

"""
Output:
Prior P(Rain = True): 0.2
P(WetGrass = True | Rain = True): 0.9
P(WetGrass = True | Rain = False): 0.1

Total P(WetGrass = True): 0.2600
Posterior P(Rain = True | WetGrass = True): 0.6923
"""
