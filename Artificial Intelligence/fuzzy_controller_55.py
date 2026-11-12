# 55. Write a Python program to design a fuzzy logic controller (e.g., fan speed from temperature and humidity) using fuzzification, rule evaluation and defuzzification.
"""
Use: Used in smart appliances (ACs, smart fans, washing machines) for smooth control from sensor inputs.
Process: Fuzzification converts crisp temperature (32 C) and humidity (70%) into Low/Medium/High degrees.
Fuzzy IF-THEN rules evaluate firing strengths for Low, Medium, and High fan speeds using min().
Centroid defuzzification computes a single crisp fan speed percentage from the weighted rule outputs.
"""


def tri_mf(x, a, b, c):
    if x <= a or x >= c:
        return 0.0
    return (x - a) / (b - a) if x <= b else (c - x) / (c - b)


# Fuzzify Temperature (15..45 C) and Humidity (20..100%)
temp = 32
humidity = 70

t_low = tri_mf(temp, 10, 15, 25)
t_med = tri_mf(temp, 20, 28, 36)
t_high = tri_mf(temp, 30, 40, 50)

h_low = tri_mf(humidity, 10, 30, 50)
h_high = tri_mf(humidity, 50, 75, 100)

# Rule evaluation
# Rule 1: IF Temp is Low THEN Fan = Low (25%)
# Rule 2: IF Temp is Medium AND Humidity is Low THEN Fan = Medium (55%)
# Rule 3: IF Temp is High OR (Temp is Medium AND Humidity is High) THEN Fan = High (85%)
r_low = t_low
r_med = min(t_med, h_low)
r_high = max(t_high, min(t_med, h_high))

# Weighted average (Centroid-style) defuzzification
numerator = (r_low * 25) + (r_med * 55) + (r_high * 85)
denominator = r_low + r_med + r_high
fan_speed = numerator / denominator if denominator > 0 else 0.0

print(f"Inputs -> Temperature: {temp} C, Humidity: {humidity}%")
print(f"Fuzzified Temp: Low={t_low:.2f}, Med={t_med:.2f}, High={t_high:.2f}")
print(f"Fuzzified Humidity: Low={h_low:.2f}, High={h_high:.2f}")
print(f"Rule Strengths -> Fan Low={r_low:.2f}, Med={r_med:.2f}, High={r_high:.2f}")
print(f"\nDefuzzified Fan Speed: {fan_speed:.2f}%")

"""
Output:
Inputs -> Temperature: 32 C, Humidity: 70%
Fuzzified Temp: Low=0.00, Med=0.50, High=0.20
Fuzzified Humidity: Low=0.00, High=0.80
Rule Strengths -> Fan Low=0.00, Med=0.00, High=0.50

Defuzzified Fan Speed: 85.00%
"""
