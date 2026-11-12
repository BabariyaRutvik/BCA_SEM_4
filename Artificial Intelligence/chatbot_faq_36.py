# 36. Build a simple chatbot using Python that can respond to user queries (like greetings, FAQs).
"""
Use: Used in customer support and college helpdesks to automatically answer common greetings and FAQs.
Process: User input is lowercased and matched against keyword rules (greetings, fees, exam, library, bye).
When a keyword matches, the chatbot returns the corresponding predefined FAQ response.
If no keyword matches, it gives a polite fallback message asking the user to rephrase.
"""

# Rule-based College Helpdesk Chatbot
def chatbot_response(user_message):
    msg = user_message.lower().strip()

    if any(word in msg for word in ["hello", "hi", "hey"]):
        return "Hello! Welcome to the BCA Helpdesk. How can I assist you?"
    elif "exam" in msg or "timetable" in msg:
        return "Semester practical exams start next Monday at 10:00 AM in Lab 2."
    elif "fee" in msg or "fees" in msg:
        return "You can pay semester fees online via the Student Portal before the 15th."
    elif "library" in msg:
        return "The library is open Monday to Saturday from 8:30 AM to 6:00 PM."
    elif "bye" in msg or "exit" in msg:
        return "Goodbye! Best of luck with your practicals."
    else:
        return "Sorry, I didn't understand that. Please ask about exams, fees, or library timings."


# Simulated user conversation
sample_queries = [
    "Hi there!",
    "When is the exam timetable?",
    "How do I pay my college fees?",
    "What are the library hours?",
    "Bye"
]

for query in sample_queries:
    print("User:", query)
    print("Bot :", chatbot_response(query))

"""
Output:
User: Hi there!
Bot : Hello! Welcome to the BCA Helpdesk. How can I assist you?
User: When is the exam timetable?
Bot : Semester practical exams start next Monday at 10:00 AM in Lab 2.
User: How do I pay my college fees?
Bot : You can pay semester fees online via the Student Portal before the 15th.
User: What are the library hours?
Bot : The library is open Monday to Saturday from 8:30 AM to 6:00 PM.
User: Bye
Bot : Goodbye! Best of luck with your practicals.
"""
