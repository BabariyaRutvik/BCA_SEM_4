# 56. Write a Python program to perform text preprocessing: tokenization, stop-word removal, stemming and lemmatization.
"""
Use: Used in NLP pipelines (search engines, chatbots, sentiment analysis) to clean raw text before modeling.
Process: Regex splits text into lowercase word tokens, and common stop-words (is, the, very, and) are removed.
Simple suffix-stripping stemming reduces words to rough stems, while a lemma dictionary maps words
to their proper base dictionary forms (e.g., 'running' -> 'run', 'better' -> 'good').
"""

import re

STOP_WORDS = {"the", "is", "and", "to", "a", "in", "very", "was", "for", "this"}
LEMMA_DICT = {
    "running": "run",
    "runs": "run",
    "delivering": "deliver",
    "delayed": "delay",
    "better": "good",
    "products": "product"
}


def tokenize(text):
    return re.findall(r"[a-z]+", text.lower())


def remove_stopwords(tokens):
    return [t for t in tokens if t not in STOP_WORDS]


def stem(word):
    for suffix in ("ing", "ed", "es", "s"):
        if len(word) > len(suffix) + 2 and word.endswith(suffix):
            return word[: -len(suffix)]
    return word


def lemmatize(word):
    return LEMMA_DICT.get(word, word)


raw_text = "The delivery was delayed, and the products were running better than expected!"
tokens = tokenize(raw_text)
filtered = remove_stopwords(tokens)
stemmed = [stem(w) for w in filtered]
lemmatized = [lemmatize(w) for w in filtered]

print("Original Text :", raw_text)
print("Tokens        :", tokens)
print("No Stop-words :", filtered)
print("Stemmed       :", stemmed)
print("Lemmatized    :", lemmatized)

"""
Output:
Original Text : The delivery was delayed, and the products were running better than expected!
Tokens        : ['the', 'delivery', 'was', 'delayed', 'and', 'the', 'products', 'were', 'running', 'better', 'than', 'expected']
No Stop-words : ['delivery', 'delayed', 'products', 'were', 'running', 'better', 'than', 'expected']
Stemmed       : ['delivery', 'delay', 'product', 'were', 'runn', 'better', 'than', 'expect']
Lemmatized    : ['delivery', 'delay', 'product', 'were', 'run', 'good', 'than', 'expected']
"""
