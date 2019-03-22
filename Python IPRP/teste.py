# teste
dicio = {}
dicio[1] = dicio.setdefault(1, []) + [2]
dicio[1] = dicio.setdefault(1, []) + [2]
# dicio=('n:%s***r:%s'%('123ds9ahgfiosgdkj',456))
# print(dicio)

lista = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
import copy
new_lista = copy.deepcopy(lista)
for i in range(len(lista)):
    for j in range(len(lista[i])):
        new_lista[i][j] = lista[i][len(lista[i]) - 1 - j]

# print(new_lista)


def filmes():
    # f=open(file,'r',encoding='utf8')
    linhas = ['tata me 12', 'tete you 12', 'titi him 18']
    dicio = {}
    for linha in linhas:
        filme, realizador, idade = linha.split(' ')
        value = ('Nome:%s***Realizador:%s' % (filme, realizador))
        dicio[idade] = dicio.setdefault(idade, []) + [value]
    return dicio


# print(filmes())


def tempo(lista):
    new = []
    while len(new) != len(lista):
        new.append(min(lista))
        lista.remove(min(lista))
    return new


print(tempo([6, 5, 4, 3, 2, 1]))
