def soma(file):
    f = open(file, 'r', encoding='utf8')
    notfound = True
    sum1 = 0
<<<<<<< HEAD
    dicio = {}
=======
    lista = []
>>>>>>> 2bc07bc7242f201383c9ede875bcfa88ab2b38a0
    todas_linhas = f.readlines()
    while notfound:
        for item in todas_linhas:
            sum1 += int(item.strip())
<<<<<<< HEAD
            dicio[sum1] = dicio.setdefault(sum1, 0) + 1
            if dicio.get(sum1) == 2:
=======

            if sum1 not in lista:
                lista.append(sum1)

            else:
>>>>>>> 2bc07bc7242f201383c9ede875bcfa88ab2b38a0
                notfound = False
                break
    f.close()

    return sum1


file = 'soma.txt'
print(soma(file))

<<<<<<< HEAD


=======
>>>>>>> 2bc07bc7242f201383c9ede875bcfa88ab2b38a0
