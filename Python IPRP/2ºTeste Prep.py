# Preparacao Segundo Teste
import math
import copy
# --------------Teste 2012 1º ----------------- #


def conta(texto, letra):
    num = 0
    for car in texto:
        if car.upper() == letra.upper():
            num += 1
    return num


def mdc(lista_1, lista_2):
    lista_final = []
    for elem1 in lista_1:
        for elem2 in lista_2:
            if elem1 == elem2:
                lista_final.append(elem1)
    return lista_final[-1], lista_final

# print(mdc([1, 2, 4, 8], [1, 2, 3, 4, 6, 12]))


def divide(string, num):
    total = len(string)
    char = total // num
    new_list = []
    resto = total % num
    # print(total)
    if resto == 0:
        for i in range(0, total, char):
            new_list.append(string[i:char + i])

    else:
        for i in range(0, total, char + 1):
            new_list.append(string[i:(char + 1) + i])
    return new_list

# print(divide('quem parte e reparte e nao fica com a melhor parte',4))

# --------------Teste 2012 2º ----------------- #


def divisores(num):
    lista = []
    for elem in range(1, num // 2 + 1):
        if num / elem == num // elem:
            lista.append(elem)
    lista.append(num)
    return lista
# print(divisores(8))


def img_soma(img1, img2):
    img_new = img1.copy()
    for i in img1:
        for j in img1:
            if img1[i][j] != img2[i][j]:
                img_new[i][j] = 1
    return img_new

# --------------Teste 2012 3º ----------------- #


def maiusculas(string):
    final = []
    string = string.strip()
    for char in string:
        if char == char.upper() and char not in ' ':
            final.append(char)
    return final

# print(maiusculas('LeTraS GraNdeS'))


def transposta(matriz):
    new = []
    final = []
    for linha in range(len(matriz)):
        size = len(matriz[linha])
    for coluna in range(size):
        for linha in range(len(matriz)):
            new.append(matriz[linha][coluna])
    for i in range(0, len(new), 2):
        final.append(new[i:i + 2])

    return final


# print(transposta([[1, 2, 3], [4, 5, 6]]))


def exe_7_12():
    f = open('exercicio_teste.txt', 'r', encoding='utf8')
    linhas = f.readlines()
    f.close()
    f_in = open('segundo_exercicio.txt', 'w', encoding='utf8')

    dicio_prof = {'102': 'Puta', '411': 'Proxeneta', '203': 'Cliente'}
    dicio_ec = {'1': 'Casado', '2': 'Not Casado'}
    for linha in linhas:
        nome, apelido, idade, code_prof, code_ec = linha.split(' ')
        code_ec = code_ec.strip('\n')
        print(nome, apelido, idade, code_prof, code_ec)
        f_in.write('%s.%s.  %s  %s\t%s \n' % (nome[0], apelido[0], idade, dicio_prof.get(code_prof), dicio_ec.get(code_ec)))
    f.close()
    return 'Done'

# --------------Teste 2012 4º ---------------- #


def transformacao(password):
    new_pass = ''
    dicio = {'O': '0', 'I': '1', 'E': '3', 'A': '4', 'B': '8'}
    for char in password:
        if char in dicio.keys():
            new_pass += dicio[char]
        else:
            new_pass += char
    return new_pass

# print(transformacao('AEBOI_CD'))


def conta_metros(lista):
    distancia = 0
    for index in range(1, len(lista)):
        vetor_f, vetor_i = lista[index], lista[index - 1]

        x1, y1 = vetor_f
        x2, y2 = vetor_i

        distx, disty = (x1 - x2, y1 - y2)
        distancia += math.sqrt(distx**2 + disty**2)

    return distancia, distancia / len(lista)


#print(conta_metros([(73, 41), (68, 42), (4, 11), (16, 82)]))

# --------------Teste 2013 2/8 ---------------- #


def double_listing(texto, numeros):
    final_string = ''
    for index in range(len(texto)):
        print(texto[index].split(' '))
        final_string += ' ' + texto[index].split(' ')[numeros[index]]
    final_string += '.'
    return final_string.strip()

#print(double_listing(['EstaSim EstaNao','EstaNao EstaSim'],[0,1]))


def domino():
    lista = []
    for i in range(7):
        lista.append((i, i))       # 00 11 22 33 44 55 66
        if i != 0:
            lista.append((0, i))      # 01 02 03 04 05 06
            if i != 1:
                lista.append((1, i))     # 12 13 14 15 15
                if i != 2:
                    lista.append((2, i))    # 23 24 25 26
                    if i != 3:
                        lista.append((3, i))   # 34 35 36
                        if i != 4:
                            lista.append((4, i))  # 45 46
                            if i != 5:
                                lista.append((5, i))  # 56

    return lista

# print(domino())


def rotacao(matriz):
    new_matriz = copy.deepcopy(matriz)
    for i in range(len(matriz)):
        for j in range(len(matriz[0])):
            new_matriz[j][len(matriz) - 1 - i] = matriz[i][j]
    return new_matriz


#print(rotacao([[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12], [13, 14, 15, 16]]))

def jaccard(lista1, lista2):

    def a_e_b(lista1, lista2):
        count = 0
        for elem in lista1:
            for num in lista2:
                if elem == num:
                    count += 1
        return count

    def a_ou_b(lista1, lista2):
        lista_aux = lista1 + lista2
        lista_final = []
        for index in range(len(lista_aux)):
            if lista_aux[index] not in lista_aux[index + 1:]:
                lista_final.append(lista_aux[index])
        return len(lista_final)

    return a_e_b(lista1, lista2) / a_ou_b(lista1, lista2)


#print(jaccard([1, 2, 3, 4], [2, 3, 5]))

receitas  ={  'sonhos'  :[  'agua',  'farinha'  ,  'manteiga' , 'ovos'  ,  'acucar'],  'rabanadas'  :[  'pao'  ,  'leite'  ,  'ovos'  ,  'manteiga'  ,  'acucar']  ,  'leite  creme'  :[  'acucar'  ,  'farinha',  'ovos',  'leite'  ]}

def ingredientes_mais_usados(receitas):
    ingredientes={}
    final={}
    
    for key,value in receitas.items():
        for item in value:
            ingredientes[item]=ingredientes.setdefault(item,[]) + [key]
    #return ingredientes
    
    maior=0
    for key,value in ingredientes.items():
        if len(value)>maior:
            maior=len(value)
        
    for key,value in ingredientes.items():
        if maior==len(value):
            final[key]=value
    
    return final
#print(ingredientes_mais_usados(receitas))

def horarios(file,num_sala):
    f=open(file,'r',encoding='utf8')
    linhas=f.readlines()
    linhas.sort()
    f.close
    
    f=open('horario sala.txt','w',encoding='utf8')
    f.write('Horario da Sala %s\n'%num_sala)    
    for linha in linhas:
        ds, inicio, duracao, turma, aula, sala = linha.split(' ')

        if sala.strip()==num_sala:
            f.write('%s %s %s %s %s\n' % (ds, inicio, duracao, turma, aula))
    f.close()

#horarios('horarios.txt','G41')

def moda(lista):
    numero=0
    count=0
    num_contados=[]
    for num in lista:
        if num not in num_contados:
            if lista.count(num)>count:
                count=lista.count(num)
                numero=num
            elif lista.count(num)== count and num<numero:
                numero=num
            num_contados.append(num)

    return (numero,count)

#print(moda([1,1,1,1,3,3,3,3]))

def factorial(number):
    fac=1
    
    for elem in range(1,number+1):
        fac*=elem
    return fac


def erf(x,n):
    const=2/(math.sqrt(math.pi))
    somatorio=0
            
    for number in range(n):
        somatorio+= (((-1)**number) * (x**(2*number+1))) / ((2*number+1) * (factorial(number)))
    
    return const*somatorio

#print(erf(1,1))
'''
import turtle 

def triang(lado,angulo):
    turtle.setheading(angulo)
    for i in range(3):
        turtle.fd(lado)
        turtle.left(120)

def desenho(lado,angulo,n):
    comp=0
    for i in range(n):
        comp+=lado
        triang(comp,angulo)
'''    
#desenho(20,-120,10)    
#turtle.exitonclick()

def count_strings(text,string):
    count=0
    p_count=0
    for i in range(len(text)):
        if text[i]==string[p_count]:
            p_count+=1
        else:
            p_count=0
        
        if p_count==3:
            count+=1
            p_count=0
    
    return count

#print(count_strings('olalal mundo','lal'))

dic1={3:5,6:2,'len':7}
dic2={2:1,3:2,6:3,'len':7}
def dic2list(dic):
    lista=[]
    for i in range(dic['len']):
        lista.append(0)
    for key,value in dic.items():
        if type(key)==int:
            lista[key]=value
    return lista

def soma_esparsos(l1,l2):
    new_l=[]
    for i in range(len(l1)):
        soma=l1[i]+l2[i]
        new_l.append(soma)
    return new_l
        
def list2dic(lst):
    dic={}
    for i in range(len(lst)):
        if lst[i] != 0:
            dic[i]= lst[i]
        dic['len']=len(lst)
    return dic
#print(list2dic( soma_esparsos( dic2list(dic1) , dic2list(dic2) )))

def ficheiro(file):
    f=open(file,'r')
    linhas=f.readlines()
    f.close()
    soma=[]
    new_l=[]
    for linha in linhas:
        leng= len(linha) // 2
    for i in range(leng):
        soma.append(0)    
        
    for linha in linhas:

        linha=linha.strip('\n')
        for i in range(0,len(linha),2):
            new_l.append(int(linha[i]))
            
        #return len(new_l), len(soma)
        soma+= soma_esparsos(soma,new_l)
    return soma

#print(ficheiro('vetores.txt'))

def altera(L1, L2):
    for elemento in L2:
        L1.append(elemento)
        L2 = L2 + [4]

        L1[-1] = 10

        del L2[0]
        return L2[:]

Lista1 = [1, 2, 3]

Lista2 = [1, 2, 3]

Lista3 = altera(Lista1, Lista2)
#print(Lista1,Lista2,Lista3)

def decode(text):
    cadeia=''
    text=text.replace('[',' ')
    text=text.replace(']',' ')
    text=text.split()
    for elem in text:
        if elem[0].isdigit():
            num=elem[:-1]
            cadeia+= int(num) * elem[-1]
        else:
            cadeia+=elem
    return cadeia

#print(decode('AB[12c]D[2e]'))

def cds(ficheiro):
    f=open(ficheiro,'r')
    linhas=f.readlines()
    f.close()
    lista=[]
    for linha in linhas:
        album,artista,pessoa=linha.split(',')
        pessoa=pessoa.strip('\n')
        if pessoa not in lista:
            lista.append(pessoa)
    return lista

#print(cds('cds.txt'))

def nifvalidos(nifs):
    new_dicio={}
    for key,value in nifs.items():
        soma=0
        for i in range(len(str(key))):
            strkey=str(key)
            soma+= int(strkey[i]) * (len(strkey)-i)
        if soma%11 ==0:
            new_dicio[key]=value
    return new_dicio

#print(nifvalidos({501617582:'UC',501617583:'Errado'}))


def subtracao_matriz(matriz,num):
    copia=copy.deepcopy(matriz)
    for i in range(len(copia)):
        for j in range(len(copia[i])):
            if copia[i][j]-num < 0:
                copia[i][j]=0
            else:
                copia[i][j]-= num
    return copia

#print(subtracao_matriz([[1,2,3],[4,5,6],[7,8,9]],3))

def matriz_dict(matriz):
    dicio={}
    for i in range(len(matriz)):
        for j in range(len(matriz[i])):
            if matriz[i][j] != 0:
                dicio[(i+1,j+1)]=matriz[i][j]
    return dicio

#print(matriz_dict([[1,2,0],[0,5,6],[7,0,9]]))


def acrescenta_da_seguinte(lista):
    new=[]
    final=[]
    for i in range(len(lista)):
        if lista[i]==lista[len(lista)-1]:
            new=[]
            for j in range(len(lista[i])):
                new.append(lista[i][j])
            final+=[new]
        else:
            new=[]
            new.append(lista[i+1][len(lista[i])-1])
            for j in range(len(lista[i])):
                new.append(lista[i][j])
            final+=[new]
    return final

#print(acrescenta_da_seguinte([[1,2,3],[4,5,6],[7,8,9]]))

directory='/home/j_marcelino/Desktop/university/'
file='bom Directory'
f=open(directory+file,'w',encoding='utf8') 
f.write('Nice Directory')
f.close()