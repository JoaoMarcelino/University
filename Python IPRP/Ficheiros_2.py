def transacao(file, info, vendedor):
    f = open(file, 'a', encoding='utf8')
    f.close()

    f = open(file, 'r', encoding='utf8')
    n_trans = len(f.readlines()) + 1
    f.close()

    f = open(file, 'a', encoding='utf8')
    f.write(' Nº Transacao: %d \t Nome Empresa: %s \t NºContribuinte: %s \t Data: %s \t Valor: %s \n' % (n_trans, info['empresa'], info['n_cont'], info['data'], info['valor']))
    f.close()

    print('\tFATURA\n----------------------\n Nome Empresa: %s \n NºContribuinte: %s \n Data: %s \n Valor: %s \n Vendedor: %s \n----------------------\n' % (info['empresa'], info['n_cont'], info['data'], info['valor'], vendedor))

    return


#informacao = {'empresa': 'WoW', 'n_cont': '43', 'data': '29 Novembro', 'valor': '5 Paus'}
#transacao('transacao.txt', informacao, 'Marcelino')


def carta(file_carta, base_dados, template):

    f = open(base_dados, 'r', encoding='utf8')
    todas_linhas = f.readlines()

    f_template = open(template, 'r', encoding='utf8')
    texto = f_template.read()
    f_template.close()
    for i in range(len(todas_linhas)):
        info = todas_linhas[i].strip().split(' ')
        f_carta = open(info[0] + file_carta, 'w', encoding='utf8')
        f_carta.write('%s \n%s \n%s' % (info[0], info[2], texto))
        f_carta.close()
    f.close()
    return


carta('cartas.txt', 'base_dados.txt', 'template.txt')
