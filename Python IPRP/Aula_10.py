# Teste Para ver se sei meter ficheiro no github


def op_basicas():
    dicio = {'word': 'genius', 'anotha_one': 'dj khaled', 'hotel': 'trivago'}
    dicio.setdefault('name', 'João')
    dicio['age'] = 18
    del dicio['word']

    return dicio, len(dicio), 'anotha_one' in dicio


# print(op_basicas())

def loja_de_fruta():
    loja = {'laranja': {'stock': 30, 'fruta_out': 8, 'p_venda': 0.80, 'p_compra': 0.60},
            'banana': {'stock': 18, 'fruta_out': 15, 'p_venda': 1.75, 'p_compra': 1.36},
            'maçã': {'stock': 15, 'fruta_out': 5, 'p_venda': 0.80, 'p_compra': 1.24},
<<<<<<< HEAD
            'tomate': {'stock': 12, 'fruta_out': 2, 'p_venda': 0.39, 'p_compra': 1.02}}
=======
            'tomate': {'stock': 12, 'fruta_out': 2, 'p_venda': 0.39, 'p_compra': 1.02}
           }
>>>>>>> 4d76de6d9e9104578d57d985a3cf12966dc50385

    # stock_final
    def money(loja):
        lucro = 0
        for fruta in loja.values():
            lucro += fruta['fruta_out'] * (fruta['p_venda'] - fruta['p_compra'])
        return lucro

    def cara(loja):
        mais_cara = 0
        for chave, valor in loja.items():
            if valor['p_compra'] > mais_cara:
                mais_cara = valor['p_compra']
                product = chave
        return mais_cara, product

    return money(loja), cara(loja)


# print(loja_de_fruta())


def exercicio_pessoas():
    pessoas = {246246: {'altura': 2.17, 'peso': 132}, 123123: {'altura': 1.74, 'peso': 85}}

    def dicio_imc(pessoas):
        for ch, val in pessoas.items():
            indice = imc(val['peso'], val['altura'])
            val['imc'] = indice
        return pessoas

    def imc(peso, altura):
        return peso / (altura**2)

    return dicio_imc(pessoas)


print(exercicio_pessoas())
