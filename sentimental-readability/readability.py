from cs50 import get_string


def count_letters(text):
    letters = 0
    for char in text:
        if char.isalpha():
            letters += 1
    return letters


def count_words(text):
    words_list = text.split()
    return len(words_list)


def count_sentences(text):
    sentences = 0
    for char in text:
        if char in ['.', '!', '?']:
            sentences += 1
    return sentences


text = get_string("Text:")
letters = count_letters(text)
words = count_words(text)
sentences = count_sentences(text)

L = (letters/words)*100
S = (sentences/words)*100

index = 0.0588*L-0.296*S-15.8

grade = round(index)

if grade < 1:
    print("Before Grade 1")
elif grade >= 16:
    print("Grade 16+")
else:
    print(f"Grade {grade}")
