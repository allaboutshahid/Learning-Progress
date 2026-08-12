import re
from collections import Counter

def word_frequency(text, top_n=10):
    words = re.findall(r"\b[a-zA-Z']+\b", text.lower())
    counts = Counter(words)
    return counts.most_common(top_n)


if __name__ == "__main__":
    sample_text = """
    The quick brown fox jumps over the lazy dog.
    The dog barks, but the fox runs away quickly.
    """
    for word, count in word_frequency(sample_text, 5):
        print(f"{word}: {count}")