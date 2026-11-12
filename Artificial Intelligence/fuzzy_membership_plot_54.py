# 54. Write a Python program to implement triangular and trapezoidal membership functions and plot them.
"""
Use: Used in fuzzy logic systems to convert crisp sensor values (like temperature) into fuzzy membership degrees.
Process: triangular_mf(x, a, b, c) rises linearly from a to peak b and falls to c.
trapezoidal_mf(x, a, b, c, d) rises from a to b, stays at 1.0 across plateau [b, c], and falls to d.
Both functions are evaluated across 10..50 C and plotted as a clear ASCII chart.
"""


def triangular_mf(x, a, b, c):
    if x <= a or x >= c:
        return 0.0
    elif a < x <= b:
        return (x - a) / (b - a)
    else:
        return (c - x) / (c - b)


def trapezoidal_mf(x, a, b, c, d):
    if x <= a or x >= d:
        return 0.0
    elif b <= x <= c:
        return 1.0
    elif a < x < b:
        return (x - a) / (b - b + (b - a))
    else:
        return (d - x) / (d - c)


temps = list(range(10, 55, 5))

print("Triangular MF 'Warm' (a=15, b=30, c=45):")
for t in temps:
    mu = triangular_mf(t, 15, 30, 45)
    bar = "#" * int(round(mu * 20))
    print(f"{t:2d}C | {mu:.2f} | {bar}")

print("\nTrapezoidal MF 'Hot' (a=25, b=35, c=45, d=55):")
for t in temps:
    mu = trapezoidal_mf(t, 25, 35, 45, 55)
    bar = "#" * int(round(mu * 20))
    print(f"{t:2d}C | {mu:.2f} | {bar}")

"""
Output:
Triangular MF 'Warm' (a=15, b=30, c=45):
10C | 0.00 | 
15C | 0.00 | 
20C | 0.33 | #######
25C | 0.67 | #############
30C | 1.00 | ####################
35C | 0.67 | #############
40C | 0.33 | #######
45C | 0.00 | 
50C | 0.00 | 

Trapezoidal MF 'Hot' (a=25, b=35, c=45, d=55):
10C | 0.00 | 
15C | 0.00 | 
20C | 0.00 | 
25C | 0.00 | 
30C | 0.50 | ##########
35C | 1.00 | ####################
40C | 1.00 | ####################
45C | 1.00 | ####################
50C | 0.50 | ##########
"""
