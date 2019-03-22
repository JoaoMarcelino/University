def arvore(familia):
    pessoas = []
    for avos in familia.values():
            for filhos in avos.values():
                if filhos:
                    pessoas.append(filhos)

    return pessoas


familia = {'avô': {'filho1': [], 'filho2': ['neto1', 'neto2'], 'filho3': ['neto3']}}
print(arvore(familia))
