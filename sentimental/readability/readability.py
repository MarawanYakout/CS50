from cs50 import get_string
# Get text from user
text = get_string("Text: ")

# Count letters, words, and sentences
letters = sum(i.isalpha() for i in text)
words = len(text.split())
sentences = sum(i in '.!?' for i in text)

# Calculate Coleman-Liau index
L = (letters / words) * 100
S = (sentences / words) * 100
index = round(0.0588 * L - 0.296 * S - 15.8)

# Output grade level
if index < 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print(f"Grade {index}")
