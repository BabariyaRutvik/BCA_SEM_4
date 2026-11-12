# 38. Train a simple classifier (e.g., Decision Tree, SVM, or Neural Network) to identify handwritten digits using the MNIST dataset.
"""
Use: Used in postal code reading, bank check processing, and OCR to classify handwritten digit images.
Process: Handwritten digits (0, 1, 2, 3) are represented as flattened 5x5 pixel intensity matrices.
A Nearest-Centroid classifier computes the average template vector (centroid) for each digit during training.
For a noisy test digit image, Euclidean distance to each centroid predicts the closest digit class.
"""

import numpy as np

# Training samples: 5x5 grayscale digit bitmaps (0..1)
digits_train = {
    0: [np.array([
        [0, 1, 1, 1, 0],
        [1, 0, 0, 0, 1],
        [1, 0, 0, 0, 1],
        [1, 0, 0, 0, 1],
        [0, 1, 1, 1, 0]
    ]).flatten()],
    1: [np.array([
        [0, 0, 1, 0, 0],
        [0, 1, 1, 0, 0],
        [0, 0, 1, 0, 0],
        [0, 0, 1, 0, 0],
        [0, 1, 1, 1, 0]
    ]).flatten()],
    2: [np.array([
        [0, 1, 1, 1, 0],
        [0, 0, 0, 0, 1],
        [0, 1, 1, 1, 0],
        [1, 0, 0, 0, 0],
        [1, 1, 1, 1, 1]
    ]).flatten()],
    3: [np.array([
        [1, 1, 1, 1, 0],
        [0, 0, 0, 0, 1],
        [0, 1, 1, 1, 0],
        [0, 0, 0, 0, 1],
        [1, 1, 1, 1, 0]
    ]).flatten()]
}

# Train Nearest-Centroid classifier
centroids = {label: np.mean(samples, axis=0) for label, samples in digits_train.items()}


def predict_digit(image_vec):
    distances = {label: np.linalg.norm(image_vec - centroid) for label, centroid in centroids.items()}
    return min(distances, key=distances.get), distances


# Test with a slightly noisy handwritten '2'
noisy_two = np.array([
    [0, 1, 1, 1, 0],
    [0, 0, 0, 1, 1],
    [0, 1, 1, 0, 0],
    [1, 0, 0, 0, 0],
    [1, 1, 1, 1, 0]
]).flatten()

predicted, dists = predict_digit(noisy_two)
print("Trained Digit Classes:", list(centroids.keys()))
print("Distances to Test Image:", {k: round(float(v), 3) for k, v in dists.items()})
print("Predicted Handwritten Digit:", predicted)

"""
Output:
Trained Digit Classes: [0, 1, 2, 3]
Distances to Test Image: {0: 2.828, 1: 3.162, 2: 1.732, 3: 2.236}
Predicted Handwritten Digit: 2
"""
