def mapa():
  return [[' ' for coluna in range(0,3)] for linha in range(0,3)]
  # return [[" "," "," "],[" "," "," "],[" "," "," "]]

def jogador(count):
  if count%2 != 0:
    jogador="jogador 1"
  else:
    jogador="jogador 2"
  return jogador

def jogada(lista):
  linha=eval(input("Escolha a linha: "))
  coluna=eval(input("Escolha a coluna: "))
  
  while lista[linha-1][coluna-1] != " ":
    for i in range(3):
        print (lista[i])        
    print("Erro!")
    linha=eval(input("Escolha a linha: "))
    coluna=eval(input("Escolha a coluna: "))    
  return [linha-1,coluna-1]


def mudanca(lista,escolha,count):
  if jogador(count)=="jogador 1":
    lista[escolha[0]][escolha[1]]="X"
  else:
    lista[escolha[0]][escolha[1]]="O"
  
    
  for i in range(1,4):
      print(lista[i-1:i])
  
  return lista    

def vencedor(lista):
  count_x=0
  count_x2_1=0
  count_x2_2=0
  count_o=0
  count_o2_1=0
  count_o2_2=0
   
  for i in range(3):
    if lista[i].count('X')==3:
      count_x=3
      
    elif lista[i].count('O')==3:
      count_o=3
  
  for j in range(3):
    if lista[0][j]==lista[1][j]==lista[2][j]=='X':
      count_x=3
    elif lista[0][j]==lista[1][j]==lista[2][j]=='O':
      count_o=3
  
  for h in range(3):
    if lista[h][h]=='X':
      count_x2_1+=1
    elif lista[h][h]=='O':
      count_o2_1+=1
  
  for h in range(3):
    if lista[h][2-h]=='X':
      count_x2_2+=1
    elif lista[h][2-h]=='O':
      count_o2_2+=1    
  
  if count_x2_1==3 or count_x2_2==3:
    count_x=3
  elif count_o2_1==3 or count_x2_2==3:
    count_o=3
  
  
  if count_x==3:
    return [True, "X"]
  elif count_o==3:
    return [True, "O"]

  return [False,""]
  


def jogo_do_galo():
  lista=mapa()
  count=1
  for i in range(3):
    print (lista[i])  
  while (vencedor(lista)[0]==False) and (count < 10):
    print()
    print("Vez do jogador ", jogador(count))  
    mudanca(lista,jogada(lista),count)
    count+=1
  
  if vencedor(lista)[1]=="X":
    print("Winner : X")
  elif vencedor(lista)[1]=="O":
    print("Winner: O")
  else:
    print("Tie")



if __name__== "__main__":
  jogo_do_galo()
