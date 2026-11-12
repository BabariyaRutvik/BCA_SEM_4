# 17. Write a Python program to train a neural network using backpropagation.
"""
Use: Used to train multi-layer neural networks for classification and prediction tasks like exam pass/fail.
Process: In the forward pass, inputs flow through hidden and output layers using sigmoid activations.
In the backward pass, the output error is propagated back to compute hidden and output layer deltas.
Weights and biases are updated via gradient descent over many epochs to minimize error.
"""

import math
import random


# Sigmoid activation and its derivative
def sigmoid(x):
    return 1.0 / (1.0 + math.exp(-x))


def sigmoid_derivative(output):
    return output * (1.0 - output)


# Real-life dataset: Predicting Exam Pass (1) / Fail (0)
# Inputs: [Normalized Study Hours, Normalized Attendance]
dataset = [
    ([0.1, 0.2], 0),
    ([0.2, 0.3], 0),
    ([0.7, 0.8], 1),
    ([0.9, 0.9], 1)
]

random.seed(42)

# Initialize weights for 2 -> 2 -> 1 network
w_hidden = [[random.uniform(-1, 1) for _ in range(2)] for _ in range(2)]
b_hidden = [random.uniform(-1, 1) for _ in range(2)]
w_output = [random.uniform(-1, 1) for _ in range(2)]
b_output = random.uniform(-1, 1)

learning_rate = 0.5
epochs = 3000

# Train using backpropagation
for epoch in range(epochs):
    total_error = 0.0

    for inputs, target in dataset:
        # Forward pass: hidden layer
        hidden_out = []
        for j in range(2):
            net_h = inputs[0] * w_hidden[j][0] + inputs[1] * w_hidden[j][1] + b_hidden[j]
            hidden_out.append(sigmoid(net_h))

        # Forward pass: output layer
        net_o = hidden_out[0] * w_output[0] + hidden_out[1] * w_output[1] + b_output
        predicted = sigmoid(net_o)

        # Error calculation
        error = target - predicted
        total_error += error ** 2

        # Backward pass: output delta
        delta_o = error * sigmoid_derivative(predicted)

        # Backward pass: hidden deltas
        delta_h = [
            delta_o * w_output[j] * sigmoid_derivative(hidden_out[j])
            for j in range(2)
        ]

        # Update output weights and bias
        for j in range(2):
            w_output[j] += learning_rate * delta_o * hidden_out[j]
        b_output += learning_rate * delta_o

        # Update hidden weights and biases
        for j in range(2):
            for i in range(2):
                w_hidden[j][i] += learning_rate * delta_h[j] * inputs[i]
            b_hidden[j] += learning_rate * delta_h[j]

print(f"Training completed in {epochs} epochs.")
print("\nPredictions on Student Exam Dataset:")
for inputs, target in dataset:
    h = [sigmoid(inputs[0] * w_hidden[j][0] + inputs[1] * w_hidden[j][1] + b_hidden[j]) for j in range(2)]
    pred = sigmoid(h[0] * w_output[0] + h[1] * w_output[1] + b_output)
    status = "Pass" if pred >= 0.5 else "Fail"
    print(f"Study={inputs[0]}, Attendance={inputs[1]} => Target={target}, Predicted={pred:.4f} ({status})")

"""
Output:
Training completed in 3000 epochs.

Predictions on Student Exam Dataset:
Study=0.1, Attendance=0.2 => Target=0, Predicted=0.0090 (Fail)
Study=0.2, Attendance=0.3 => Target=0, Predicted=0.0236 (Fail)
Study=0.7, Attendance=0.8 => Target=1, Predicted=0.9754 (Pass)
Study=0.9, Attendance=0.9 => Target=1, Predicted=0.9890 (Pass)
"""
