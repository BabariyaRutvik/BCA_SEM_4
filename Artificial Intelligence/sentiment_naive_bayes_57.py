# 57. Write a Python program to build a sentiment analysis classifier on a sample set of reviews (Naive Bayes).
"""
Use: Used in e-commerce and social media monitoring to automatically classify customer reviews as Positive or Negative.
Process: Training reviews are tokenized to count word frequencies per sentiment class with Laplace smoothing.
For a new review, Naive Bayes sums log prior probabilities and word log-likelihoods for each class.
The class with the higher posterior log-probability is chosen as the predicted sentiment.
"""

import math
import re
from collections import Counter

training_reviews = [
    ("amazing product fast delivery loved it", "Positive"),
    ("great quality works perfectly highly recommend", "Positive"),
    ("excellent phone battery life is awesome", "Positive"),
    ("terrible quality broke in two days", "Negative"),
    ("worst experience slow delivery waste of money", "Negative"),
    ("poor build bad customer service disappointed", "Negative")
]


def tokenize(text):
    return re.findall(r"[a-z]+", text.lower())


class NaiveBayesSentiment:

    def fit(self, data):
        self.class_counts = Counter()
        self.word_counts = {"Positive": Counter(), "Negative": Counter()}
        self.vocab = set()

        for text, label in data:
            self.class_counts[label] += 1
            for word in tokenize(text):
                self.word_counts[label][word] += 1
                self.vocab.add(word)

        self.total_docs = len(data)
        self.vocab_size = len(self.vocab)

    def predict(self, text):
        tokens = tokenize(text)
        scores = {}
        for label in self.class_counts:
            log_prob = math.log(self.class_counts[label] / self.total_docs)
            total_words = sum(self.word_counts[label].values())
            for w in tokens:
                # Laplace smoothing
                word_prob = (self.word_counts[label][w] + 1) / (total_words + self.vocab_size)
                log_prob += math.log(word_prob)
            scores[label] = log_prob
        return max(scores, key=scores.get), scores


model = NaiveBayesSentiment()
model.fit(training_reviews)

test_reviews = [
    "fast delivery and great quality",
    "bad quality and waste of money"
]

for review in test_reviews:
    label, _ = model.predict(review)
    print(f"Review: '{review}' => Sentiment: {label}")

"""
Output:
Review: 'fast delivery and great quality' => Sentiment: Positive
Review: 'bad quality and waste of money' => Sentiment: Negative
"""
