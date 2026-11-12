# 18. Develop a Python program to model a recurrent neural network and apply it to a time-series problem.
"""
Use: Used to model sequential and time-series data (such as daily temperatures) where past values affect future ones.
Process: At each time step, the RNN combines the current input with its previous hidden state using tanh.
During training, prediction errors adjust input, recurrent, and output weights across the sequence.
After training, the network processes the historical sequence to forecast the next day's temperature.
"""

import math


# Tanh activation for hidden state
def tanh(x):
    return math.tanh(x)


# Simple Recurrent Neural Network for 1D time-series forecasting
class SimpleRNN:

    def __init__(self, w_x=0.5, w_h=0.4, w_y=1.0, b_h=0.0, b_y=0.0):
        self.w_x = w_x
        self.w_h = w_h
        self.w_y = w_y
        self.b_h = b_h
        self.b_y = b_y

    # Train using gradient descent over sequence steps
    def train(self, series, lr=0.01, epochs=300):
        for _ in range(epochs):
            h = 0.0
            for t in range(len(series) - 1):
                x = series[t]
                target = series[t + 1]

                # Forward step
                z_h = self.w_x * x + self.w_h * h + self.b_h
                h_next = tanh(z_h)
                y_pred = self.w_y * h_next + self.b_y

                # Loss gradient
                error = y_pred - target
                d_w_y = error * h_next
                d_b_y = error

                d_h = error * self.w_y * (1 - h_next ** 2)
                d_w_x = d_h * x
                d_w_h = d_h * h
                d_b_h = d_h

                # Update weights
                self.w_y -= lr * d_w_y
                self.b_y -= lr * d_b_y
                self.w_x -= lr * d_w_x
                self.w_h -= lr * d_w_h
                self.b_h -= lr * d_b_h

                h = h_next

    # Predict next value given historical sequence
    def predict_next(self, series):
        h = 0.0
        for x in series:
            h = tanh(self.w_x * x + self.w_h * h + self.b_h)
        return self.w_y * h + self.b_y


# Real-life example: Daily temperature time series (normalized in 0..1, representing 20C..35C)
# Raw temperatures (C): [22, 24, 26, 28, 30, 32]
temps_c = [22, 24, 26, 28, 30, 32]
normalized = [t / 40.0 for t in temps_c]

rnn = SimpleRNN()
rnn.train(normalized, lr=0.05, epochs=500)

next_norm = rnn.predict_next(normalized)
predicted_temp = next_norm * 40.0

print("Historical Daily Temperatures (C):", temps_c)
print(f"Predicted Next Day Temperature: {predicted_temp:.2f} C")

"""
Output:
Historical Daily Temperatures (C): [22, 24, 26, 28, 30, 32]
Predicted Next Day Temperature: 31.59 C
"""
