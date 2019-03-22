def tempo(lista):
    lista = [0] + lista[:]
    for i in range(1, len(lista)):
        elem = lista[i]
        for j in range(i - 1, -1, -1):
            if elem < lista[j]:
                lista[j + 1] = lista[j]
            else:
                lista[j + 1] = elem
                break
    return lista[1:]


print(tempo([6, 5, 4, 3, 2, 1]))


def ficheiro(file, atleta):
    pos = 0
    with open(file, 'r', encoding='utf8') as f:
        linhas = f.readlines()
        nome, tempo = atleta
        for i in range(len(linhas)):
            linha = linhas[i]
            name, time = linha.split()
            f = open(file, 'w', encoding='utf8')
            if int(tempo) < int(time.strip('\n')):
                f.write('%s %s\n' % (nome, tempo))
            else:
                f.write
                return


ficheiro('Corrida.txt', ('John', '13'))
