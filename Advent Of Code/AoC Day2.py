def two_letters():
    f = open('boxes.txt', 'r', encoding='utf8')
<<<<<<< HEAD

=======
    alfabeto = 'abcdefghijklmnopqrstuvwxyz'
>>>>>>> 2bc07bc7242f201383c9ede875bcfa88ab2b38a0
    count_2, count_3 = 0, 0
    lista_2, lista_3 = [], []
    for code in f.readlines():
        code = code.strip()
<<<<<<< HEAD
        for letter in code:
=======
        for letter in alfabeto:
>>>>>>> 2bc07bc7242f201383c9ede875bcfa88ab2b38a0

            if code.count(letter) == 2:
                count_2 += 1
                lista_2.append(code)
                break

<<<<<<< HEAD
        for letter in code:
=======
        for letter in alfabeto:
>>>>>>> 2bc07bc7242f201383c9ede875bcfa88ab2b38a0
            if code.count(letter) == 3:
                count_3 += 1
                lista_3.append(code)
                break

    #print (count_2)
    #print (count_3)
    f.close()
    return count_2 * count_3, lista_2, lista_3

# print(two_letters())


resposta1, list2, list3 = two_letters()


def differ(list2, list3):
    f = open('boxes.txt', 'r', encoding='utf8')
    for alpha in list3:
        if alpha not in list2:
            list2.append(alpha)

    final_code = ''
    for i in list2:
        for j in list2:
            dif = 0
            for index, char in enumerate(i):
                if char != j[index]:
                    dif += 1

            if dif == 1:
                for index, char in enumerate(i):
                    if char == j[index]:
                        final_code += char

                return final_code


print(resposta1)
print(differ(list2, list3))
