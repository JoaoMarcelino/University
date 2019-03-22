from datetime import datetime


def readfile(file, pos):
    f = open(file, 'r')
    f.seek(pos)
    print(f.read())
    f.close()
    return


def writefile(file):
    now = datetime.now()
    day, month, year = now.day, now.month, now.year
    meses = {
        1: 'Janeiro', 2: 'Fevereiro', 3: 'Março',
        4: 'Abril', 5: 'Maio', 6: 'Junho',
        7: 'Julho', 8: 'Agosto', 9: 'Setembro',
        10: 'Outubro', 11: 'Novembro', 12: 'Dezembro'
    }

    f = open(file, 'w')
    f.write('\nO meu primeiro ficheiro de Python!\n')
    f.write('\nData de hoje: %d / %d / %d  ||' % (day, month, year))
    f.write('  %d de %s de %d \n' % (day, meses[month], year))
    f.close()
    return


def copyfile(original, copy):

    # ORIGINAL
    f = open(original, 'r')
    texto = f.read()
    f.close()

    # COPY
    f = open(copy, 'w')
    f.write(texto)
    f.close()


file = 'primeiro.txt'
copy = 'primeiro_copy.txt'
writefile(file)
readfile(file, 0)

#copyfile(file, copy)
#readfile(copy, 0)

