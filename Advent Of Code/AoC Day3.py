def results():
    f = open('Day3.txt', 'r', encoding='utf8')
    linhas = f.readlines()
    new_linhas = []
    f.close()
    dicio_1 = {}
    dicio_2 = {}
    area = 0
    lista_aux = []

    for code in linhas:
        code = code.strip('\n')
        code = code.split(' ')
        del code[1]

        index = code[0][1:]

        code[1] = code[1].split(',')
        code[1][1] = code[1][1].strip(':')
        widthmin = code[1][0]
        heightmin = code[1][1]

        code[2] = code[2].split('x')
        widthmax = code[2][0]
        heightmax = code[2][1]

        new_linhas.append([index, widthmin, widthmax, heightmin, heightmax])
    # return new_linhas

    for code in new_linhas:
        for width in range(int(code[1]), int(code[1]) + int(code[2])):
            for height in range(int(code[3]), int(code[3]) + int(code[4])):
                value = ('%s,%s' % (width, height))
                dicio_1[value] = dicio_1.setdefault(value, 0) + 1
                lista_aux.append([value])
        dicio_2[code[0]] = dicio_2.setdefault(code[0], []) + [lista_aux]

    for key in dicio_1.keys():
        if dicio_1.get(key) > 1:
            area += 1
    # return area, dicio_1
    return dicio_2
    #This Doesn't Work#
    count = 0
    for key, value in dicio_2.items():
        for ponto in value:
            if dicio_1[value] == 1:
                count += 1

            if count == len(value):
                return key


print(results())
