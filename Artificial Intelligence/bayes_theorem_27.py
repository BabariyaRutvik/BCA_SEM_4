# 27. Write a Python function to implement probabilistic reasoning using Bayes' theorem.
"""
Use: Used in medical screening, spam filtering, and diagnostics to update belief probabilities after new evidence.
Process: Given prior probability P(H), sensitivity P(E|H), and false positive rate P(E|not H),
bayes_theorem() computes total evidence probability P(E) across both disease and healthy groups.
It then divides the true positive joint probability by P(E) to return the posterior P(H|E).
"""

# Function to compute posterior probability P(H | E) using Bayes' theorem
def bayes_theorem(prior_h, likelihood_e_given_h, likelihood_e_given_not_h):
    prior_not_h = 1.0 - prior_h
    total_e = (prior_h * likelihood_e_given_h) + (prior_not_h * likelihood_e_given_not_h)
    posterior_h_given_e = (prior_h * likelihood_e_given_h) / total_e
    return posterior_h_given_e


# Real-life example: Medical Screening Test for a Rare Disease
# 1% of population has the disease: P(Disease) = 0.01
# Test sensitivity (True Positive Rate): P(Positive | Disease) = 0.95
# False Positive Rate: P(Positive | No Disease) = 0.05
p_disease = 0.01
p_pos_given_disease = 0.95
p_pos_given_healthy = 0.05

posterior = bayes_theorem(p_disease, p_pos_given_disease, p_pos_given_healthy)

print("Prior P(Disease):", p_disease)
print("Sensitivity P(Positive | Disease):", p_pos_given_disease)
print("False Positive Rate P(Positive | No Disease):", p_pos_given_healthy)
print(f"\nPosterior P(Disease | Positive Test): {posterior:.4f} ({posterior * 100:.2f}%)")

"""
Output:
Prior P(Disease): 0.01
Sensitivity P(Positive | Disease): 0.95
False Positive Rate P(Positive | No Disease): 0.05

Posterior P(Disease | Positive Test): 0.1610 (16.10%)
"""
