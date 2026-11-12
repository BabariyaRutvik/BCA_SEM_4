# 24. Write Python code to simulate the learning of a neural network using the Hebbian learning rule.
"""
Use: Used in neural networks for pattern association and simple binary classification (such as spam filtering).
Process: Based on Hebb's rule ("neurons that fire together wire together"), each weight updates by lr * x * y.
Positive correlations strengthen weights while negative correlations weaken them across training samples.
After training, the weighted sum of features plus bias classifies unseen inputs.
"""

# Hebbian Learning Rule: w_new = w_old + learning_rate * x * y
def hebbian_train(training_data, learning_rate=0.5):
    weights = [0.0, 0.0]
    bias = 0.0

    for x, y in training_data:
        weights[0] += learning_rate * x[0] * y
        weights[1] += learning_rate * x[1] * y
        bias += learning_rate * y
        print(f"Input: {x}, Target: {y:+d} -> Weights: {weights}, Bias: {bias}")

    return weights, bias


def predict(x, weights, bias):
    net = x[0] * weights[0] + x[1] * weights[1] + bias
    return 1 if net >= 0 else -1


# Real-life example: Email Spam Classifier using bipolar features (+1 = Present, -1 = Absent)
# Features: [Has_Lottery_Keyword, Unknown_Sender] -> Target: +1 (Spam), -1 (Not Spam)
spam_dataset = [
    ([1, 1], 1),
    ([1, -1], 1),
    ([-1, 1], -1),
    ([-1, -1], -1)
]

print("Training Spam Filter with Hebbian Rule:")
w, b = hebbian_train(spam_dataset)

print("\nTesting Trained Classifier:")
for features, target in spam_dataset:
    pred = predict(features, w, b)
    label = "Spam" if pred == 1 else "Not Spam"
    print(f"Features={features} => Predicted={pred:+d} ({label}), Expected={target:+d}")

"""
Output:
Training Spam Filter with Hebbian Rule:
Input: [1, 1], Target: +1 -> Weights: [0.5, 0.5], Bias: 0.5
Input: [1, -1], Target: +1 -> Weights: [1.0, 0.0], Bias: 1.0
Input: [-1, 1], Target: -1 -> Weights: [1.5, -0.5], Bias: 0.5
Input: [-1, -1], Target: -1 -> Weights: [2.0, 0.0], Bias: 0.0

Testing Trained Classifier:
Features=[1, 1] => Predicted=+1 (Spam), Expected=+1
Features=[1, -1] => Predicted=+1 (Spam), Expected=+1
Features=[-1, 1] => Predicted=-1 (Not Spam), Expected=-1
Features=[-1, -1] => Predicted=-1 (Not Spam), Expected=-1
"""
