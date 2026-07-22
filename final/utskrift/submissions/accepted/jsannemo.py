want_length = int(input())
n = int(input())
words = []
for _ in range(n):
    words.append(input())

dp = {}

def best(words, current_length):
    if not words:
        return abs(current_length - want_length)
    if (len(words), current_length) in dp:
        return dp[(len(words), current_length)]
    # Put word on line
    answer = best(words[1:], current_length + len(words[0]) + (1 if current_length else 0))
    # New line
    if current_length:
        answer = min(answer, max(abs(current_length - want_length), best(words, 0)))
    dp[(len(words), current_length)] = answer
    return answer

def reconstruct(words):
    answer = best(words, 0)
    current_length = 0
    while words:
        # New line?
        if current_length and max(abs(current_length - want_length), best(words, 0)) <= answer:
            print()
            current_length = 0
        else:
            print(words[0], "", end="")
            current_length += len(words[0]) + (1 if current_length else 0)
            words = words[1:]

reconstruct(words)
