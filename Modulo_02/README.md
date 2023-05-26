<table border="1" width="300">

   <tr>
    <td  align="center"colspan="4">Lista</td>
   </tr>
  
   <tr>
      <td align="center">Exercicios</td>
      <td align="center">Descrição </td>
  </tr>
  <tr>
    <td  align="center">Módulo 00</td>
   </tr>
   <tr align="center">
    <td>Ex00:<br>Minha primeira Classe na forma canônica ortodoxa</td>
    <td>Crie uma classe na Forma Canônica Ortodoxa que represente
      um número de ponto fixo:<br><br>
      
      • Membros privados:
        ◦ Um número inteiro para armazenar o valor do número de ponto fixo.
        ◦ Um inteiro constante estático para armazenar o número de bits
          fracionários. Seu valor sempre será o literal inteiro 8.
      
      • Membros públicos:
        ◦ Um construtor padrão que inicializa o valor do número de ponto
          fixo como 0
        ◦ Um construtor de cópia (Copy constructor)
        ◦ Uma sobrecarga do operador de atribuição de cópia
        ◦ Um destruidor.
        ◦ Uma função de membro int getRawBits(void) const;
          que retorna o valor bruto do valor de ponto fixo.
        ◦ Uma função de membro void setRawBits(int const raw);
          que define o valor bruto do número de ponto fixo.
   </tr>

   <tr align="center">
    <td>Ex01:<br>Rumo a uma classe de número de ponto fixo mais útil</td>
    <td>Adicione os seguintes construtores públicos e funções de
      membro públicas à sua classe:<br><br>
      
     • Um construtor que usa um número inteiro constante como parâmetro.
       Ele o converte no valor de ponto fixo correspondente. O valor de
       bits fracionários é inicializado em 8 como no exercício 00.
      
     • Um construtor que usa um número de ponto flutuante constante como
       parâmetro.
       Ele o converte no valor de ponto fixo correspondente. O valor de
       bits fracionários é inicializado em 8 como no exercício 00.
      
     • Uma função membro float toFloat(void) const;
      que converte o valor de ponto fixo em um valor de ponto flutuante.
     
      • Uma função de membro int toInt(void) const;
      que converte o valor de ponto fixo em um valor inteiro
      
      E adicione a seguinte função aos arquivos da classe Fixed :
      
      • Uma sobrecarga do operador de inserção («) que insere uma
       representação de ponto flutuante do número de ponto fixo
       no objeto de fluxo de saída passado como parâmetro.
   </tr>
  
 <tr align="center">
    <td>Ex02:<br>Agora estamos falando</td>
    <td>Adicione funções de membro públicas à sua classe para
      sobrecarregar os seguintes operadores:<br><br>
      
     • Os 6 operadores de comparação: >, <, >=, <=, == e !=.
                                                   
     • Os 4 operadores aritméticos: +, -, * e /.
     
     • Os 4 operadores de incremento/decremento (pré-incremento e
       pós-incremento, pré-decremento e pós-decremento), que
       aumentarão ou diminuirão o valor do ponto fixo do menor
       representável, como 1 + > 1.
      
     Adicione estas quatro funções de membro sobrecarregadas
     públicas à sua classe:
      
     • Uma função de membro estático min que toma como parâmetros
      duas referências em números de ponto fixo e retorna uma
      referência ao menor.
      
     • Uma função de membro estático min que toma como parâmetros
      duas referências a constante números de ponto fixo e retorna
      uma referência ao menor.
      
     • Uma função de membro estático max que usa como parâmetros duas
      referências em números de ponto fixo e retorna uma referência ao maior.
      
     • Uma função de membro estática máxima que toma como parâmetros duas
      referências a constante números de ponto fixo e retorna uma referência ao maior.
   </tr>
      
   <tr align="center">
    <td>Ex03:BSP</td>
    <td>Agora que você tem uma classe Fixed funcional , seria bom usá-la.<br><br>
      
     Vamos começar criando a classe Ponto na Forma Canônica Ortodoxa que
     representa um ponto 2D:
      
     • Membros privados:
                                                   
      ◦ Um atributo const fixo x.
      ◦ Um atributo const fixo y.
      ◦ Qualquer outra coisa útil.
     
     • Membros públicos:
      
      ◦ Um construtor padrão que inicializa x e y como 0.
      ◦ Um construtor que usa como parâmetros dois números de ponto
        flutuante constantes.
        Ele inicializa x e y com esses parâmetros.
      
      ◦ Um construtor de cópia
      ◦ Uma sobrecarga do operador de atribuição de cópia.
      ◦ Um destruidor
      ◦ Qualquer outra coisa útil
      
     Para finalizar, implemente a seguinte função no arquivo apropriado:
      
     bool bsp( Point const a, Point const b, Point const c, Point const point);
      
     • a, b, c: Os vértices do nosso amado triângulo.
      
     • point: O ponto a ser verificado
      
     • Returns: Verdadeiro se o ponto estiver dentro do triângulo.
       Falso caso contrário
      
   </tr>
</table>
