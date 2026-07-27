def is_palindrome(text):
    text = text.lower().replace(" ", "")
    return text == text[::-1]

word = input("Enter a word or sentence: ")

if is_palindrome(word):
    print("It is a palindrome.")
else:
    print("It is not a palindrome.")