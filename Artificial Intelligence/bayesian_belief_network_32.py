# 32. Implement a Python function to model a Bayesian belief network and perform inference.
"""
Use: Used in security, medical diagnosis, and fault detection to infer hidden causes from observed alarms or symptoms.
Process: The network models Burglary (B) and Earthquake (E) influencing Alarm (A), which triggers SecurityCall (C).
Using conditional probability tables, infer_burglary_given_alarm() sums joint probabilities over E.
Bayes' rule normalizes the result to return P(Burglary = True | Alarm = True).
"""

# Bayesian Belief Network tables for a Home Security System
P_B = {True: 0.01, False: 0.99}
P_E = {True: 0.02, False: 0.98}

# P(Alarm=True | Burglary, Earthquake)
P_A_given_BE = {
    (True, True): 0.95,
    (True, False): 0.90,
    (False, True): 0.30,
    (False, False): 0.01
}


# Perform exact inference for P(Burglary=True | Alarm=True)
def infer_burglary_given_alarm():
    p_b_true_and_a = 0.0
    p_b_false_and_a = 0.0

    for e in [True, False]:
        p_b_true_and_a += P_B[True] * P_E[e] * P_A_given_BE[(True, e)]
        p_b_false_and_a += P_B[False] * P_E[e] * P_A_given_BE[(False, e)]

    total_p_a = p_b_true_and_a + p_b_false_and_a
    return p_b_true_and_a / total_p_a


posterior = infer_burglary_given_alarm()
print("Home Security Bayesian Belief Network Inference:")
print(f"Prior P(Burglary = True): {P_B[True]:.4f}")
print(f"Prior P(Earthquake = True): {P_E[True]:.4f}")
print(f"Posterior P(Burglary = True | Alarm = True): {posterior:.4f} ({posterior * 100:.2f}%)")

"""
Output:
Home Security Bayesian Belief Network Inference:
Prior P(Burglary = True): 0.0100
Prior P(Earthquake = True): 0.0200
Posterior P(Burglary = True | Alarm = True): 0.3655 (36.55%)
"""
