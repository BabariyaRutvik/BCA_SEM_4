# 40. Build a recommendation engine using collaborative filtering or content-based filtering on a sample movie dataset.
"""
Use: Used by streaming platforms (like Netflix/YouTube) to suggest movies matching a user's taste.
Process: User-movie ratings are represented as vectors, and cosine similarity measures taste overlap
between the target user (Rutvik) and other users. Ratings from similar users are weighted by similarity
to recommend unseen movies with the highest predicted score.
"""

import math

# Sample user ratings (1 to 5; 0 means not watched yet)
ratings = {
    "Rutvik": {"Inception": 5, "Interstellar": 5, "Titanic": 1, "Avatar": 0, "The_Matrix": 0},
    "Aman":   {"Inception": 5, "Interstellar": 4, "Titanic": 1, "Avatar": 5, "The_Matrix": 4},
    "Priya":  {"Inception": 1, "Interstellar": 2, "Titanic": 5, "Avatar": 2, "The_Matrix": 1}
}


def cosine_sim(u1, u2, movies):
    dot = sum(u1[m] * u2[m] for m in movies)
    n1 = math.sqrt(sum(u1[m] ** 2 for m in movies))
    n2 = math.sqrt(sum(u2[m] ** 2 for m in movies))
    return dot / (n1 * n2) if n1 and n2 else 0.0


target_user = "Rutvik"
common_movies = [m for m, r in ratings[target_user].items() if r > 0]
unwatched = [m for m, r in ratings[target_user].items() if r == 0]

similarities = {
    other: cosine_sim(ratings[target_user], ratings[other], common_movies)
    for other in ratings if other != target_user
}

recommendations = {}
for movie in unwatched:
    weighted_sum = sum(similarities[other] * ratings[other][movie] for other in similarities)
    sim_sum = sum(similarities.values())
    recommendations[movie] = weighted_sum / sim_sum

print("User Similarities with", target_user + ":", {k: round(v, 3) for k, v in similarities.items()})
print("\nRecommended Movies for", target_user + ":")
for movie, score in sorted(recommendations.items(), key=lambda x: x[1], reverse=True):
    print(f"- {movie}: predicted rating {score:.2f} / 5")

"""
Output:
User Similarities with Rutvik: {'Aman': 0.994, 'Priya': 0.511}

Recommended Movies for Rutvik:
- Avatar: predicted rating 3.98 / 5
- The_Matrix: predicted rating 2.98 / 5
"""
