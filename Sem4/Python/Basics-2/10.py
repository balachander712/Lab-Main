import collections
concordance = collections.defaultdict(set)
book = input("Enter the multiline sentence: (In the format <line number>: <line>.): ")

for sentence in book.split("."):
    sentence = sentence.strip()
    if not sentence: continue
    line_number = int(sentence[0])
    line = sentence[1:]
    line = line.strip(" .")
    for word in line.split():
        concordance[word].add(line_number) 

concordance = dict(sorted(dict(concordance).items()))
print(concordance)