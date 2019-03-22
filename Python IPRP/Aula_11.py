def main(text):
    dicio = {}
    vogais = 'aeiouAEIOU'
    for pos in range(len(text)):
        if text[pos] in vogais:
            dicio[text[pos]] = dicio.get(text[pos], []) + [pos]
    return dicio


texto = 'aAeEiIoOuUaAeEiIoOuU'
print(main(texto))
