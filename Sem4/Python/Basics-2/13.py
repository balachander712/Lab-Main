import random

words = [
    'previous',
    'mammoth',
    'answer',
    'applaud',
    'thoughtless',
    'makeshift',
    'belong',
    'attack'
]

word = random.choice(words)
word = list(word)
guessed = '_'*len(word)
guessed = list(guessed)
listGuessed = []


letter = input('Guess letter:')
while True:
    if letter.lower() in listGuessed:
        letter = ''
        print(f'Already guessed {letter}')
    elif letter.lower() in word:
        index = word.index(letter.lower())
        guessed[index] = letter.lower()
        word[index] = '_'
    else:
        print(''.join(guessed))
        if letter is not '':
            listGuessed.append(letter.lower())
        letter = input('guess letter:')

    if '_' not in guessed:
        print('You guessed the letter')
        break