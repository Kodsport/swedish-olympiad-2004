n = int(input())
k = int(input())

words = [input() for i in range(k)]

def best(words, n, prefix_sum):
    indexes = [0]
    max_len = -1
    for i in range(len(words)-1):
        currentLength = (prefix_sum[i] - prefix_sum[indexes[-1]])
        futureLength = (prefix_sum[i+1] - prefix_sum[indexes[-1]])
        if abs(currentLength - n) < abs(futureLength - n):
            indexes.append(i)

    indexes.append(len(words))

    for index in range(len(indexes)-1):
        sentence = words[indexes[index]:indexes[index+1]]
        max_len = max(abs(k - len(" ".join(sentence))), max_len)

    return max_len

def get_best(words, n, prefix_sum):
    indexes = [0]
    for i in range(len(words)-1):
        currentLength = (prefix_sum[i] - prefix_sum[indexes[-1]])
        futureLength = (prefix_sum[i+1] - prefix_sum[indexes[-1]])
        if abs(currentLength - n) < abs(futureLength - n):
            indexes.append(i)

    indexes.append(len(words))

    sentences = []
    for index in range(len(indexes)-1):
        sentences.append(words[indexes[index]:indexes[index+1]])

    return sentences

words_length = len(" ".join(words))

best_split = 1e8
best_input = 0
tried = set()
prefix_sum = []
partial_sum = 0
for word in words:
    partial_sum += len(word)
    prefix_sum.append(partial_sum)

for i in range(2, len(words)):
    new_attempt = words_length // i
    if i in tried:
        continue

    tried.add(new_attempt)
    split = best(words, new_attempt, prefix_sum)
    if split < best_split:
        best_split = split
        best_input = new_attempt

best_splitting = get_best(words, best_input, prefix_sum)
for sentence in best_splitting:
    print(" ".join(sentence))
