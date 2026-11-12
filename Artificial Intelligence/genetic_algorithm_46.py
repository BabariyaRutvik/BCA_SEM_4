# 46. Write a Python program to implement a genetic algorithm to maximize a given function (selection, crossover and mutation).
"""
Use: Used in optimization, scheduling, and engineering design to evolve better solutions over generations.
Process: Candidate values (0..31) are encoded as 5-bit binary chromosomes and scored by fitness f(x) = x^2.
In each generation, tournament selection picks parents, single-point crossover combines them,
and random bit-flip mutation maintains diversity until the population converges near x = 31.
"""

import random

random.seed(42)


def fitness(chrom):
    x = int(chrom, 2)
    return x * x


def select_parent(population):
    a, b = random.sample(population, 2)
    return a if fitness(a) >= fitness(b) else b


def crossover(p1, p2):
    point = random.randint(1, len(p1) - 1)
    return p1[:point] + p2[point:], p2[:point] + p1[point:]


def mutate(chrom, rate=0.1):
    bits = list(chrom)
    for i in range(len(bits)):
        if random.random() < rate:
            bits[i] = "1" if bits[i] == "0" else "0"
    return "".join(bits)


population = [format(random.randint(0, 31), "05b") for _ in range(6)]

for gen in range(1, 11):
    population.sort(key=fitness, reverse=True)
    best = population[0]
    if gen in (1, 5, 10):
        print(f"Generation {gen:2d}: Best={best} (x={int(best, 2):2d}), Fitness={fitness(best)}")

    next_pop = [population[0]]  # Elitism: keep best individual
    while len(next_pop) < len(population):
        p1 = select_parent(population)
        p2 = select_parent(population)
        c1, c2 = crossover(p1, p2)
        next_pop.append(mutate(c1))
        if len(next_pop) < len(population):
            next_pop.append(mutate(c2))
    population = next_pop

best_final = max(population, key=fitness)
print(f"\nFinal Best Solution: x = {int(best_final, 2)}, f(x) = {fitness(best_final)}")

"""
Output:
Generation  1: Best=10001 (x=17), Fitness=289
Generation  5: Best=11011 (x=27), Fitness=729
Generation 10: Best=11111 (x=31), Fitness=961

Final Best Solution: x = 31, f(x) = 961
"""
