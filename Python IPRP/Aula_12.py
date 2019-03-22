def ordena(seq):
    if len(seq) == 1:
        return seq
    else:
        return inserir(seq[0], ordena(seq[1:]))


def inserir(elem, lista_ordenada):
    if lista_ordenada == []:
        return [elem]
    elif elem > lista_ordenada[0]:
        return [lista_ordenada[0]] + inserir(elem, lista_ordenada[1:])
    else:
        return [elem] + lista_ordenada

# print(inserir(7,[1,3,4]))


def ordena_fusao(seq):
    if len(seq) == 1:
        return seq
    else:
        meio = len(seq) // 2
        lista_1 = ordena_fusao(seq[meio:])
        lista_2 = ordena_fusao(seq[:meio])
        return junta(lista_1, lista_2)


def junta(lista_1, lista_2):
    if lista_1 == [] or lista_2 == []:
        return lista_1 + lista_2
    elif lista_1[0] < lista_2[0]:
        return [lista_1[0]] + junta(lista_1[1:], lista_2)
    else:
        return [lista_2[0]] + junta(lista_1, lista_2[1:])


lst = ([3, 6, 15, 2, 7, 24, 9])
# print(ordena_fusao(lst))


def repeticao(cadeia):

    if len(cadeia) == 1:
        return [cadeia]
    elif cadeia[0] not in cadeia[1:]:
        return [cadeia[0]] + repeticao(cadeia[1:])
    else:
        return repeticao(cadeia[1:])


# print(repeticao('abcdunodostres'))


def vetores(vetx, vety):
    if len(vetx) == 1 and len(vety) == 1:
        return vetx[0] * vety[0]
    else:
        return vetx[0] * vety[0] + vetores(vetx[1:], vety[1:])


print(vetores([1, 2, 3], [4, 5, 6]))
