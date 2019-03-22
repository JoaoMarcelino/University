import resource
import sys
resource.setrlimit(resource.RLIMIT_STACK, (2**29, -1))
sys.setrecursionlimit(10**6)


def removal(text):
    for ind in range(1, len(text)):
        if text[ind] == text[ind - 1].lower() and text[ind - 1] == text[ind].upper() or text[ind] == text[ind - 1].upper() and text[ind - 1] == text[ind].lower():
            del text[ind]
            del text[ind - 1]

            text = removal(text)
            break
    string = ''.join(text)
    return string


def count_text(text):
    count = 0
    for letter in text:
        count += 1
    return count


def parte_2(text):
    dicio = {}
    for first_word in range(len(text)):
        lista_aux = []
        for second_word in range(len(text)):
            if text[second_word].upper() != text[first_word].upper():
                lista_aux.append(text[second_word])

        if first_word not in dicio.keys():
            dicio[text[first_word]] = count_text(removal(lista_aux))
    return dicio


f = open('Day5.txt', 'r', encoding='utf8')
text = f.readlines()[0].strip()
f.close()

lst = []
for i in range(len(text)):
    lst.append(text[i])
lista_exemplos = ['a', 'b', 'a']
# print(count_text(removal(lst)))

print(parte_2(lst))


