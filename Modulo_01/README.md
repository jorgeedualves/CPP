<table border="1" width="300">

   <tr>
    <td  align="center"colspan="4">Listas</td>
   </tr>
  
   <tr>
      <td align="center">Exercicios </td>
      <td align="center">Descrição </td>
  </tr>
   <tr>
    <td  align="center"colspan="4">Módulo 01</td>
   </tr>
   <tr>
    <td>Ex00: BraiiiiiiinnnzzzZ</td>
    <td>Primeiro, implemente uma classe Zombie . Ele tem um nome de atributo privado de cadeia de caracteres
    Adicione uma função de membro void anunciar( void ); para a classe Zumbi.<br>
	 Os zumbis se anunciam da seguinte forma:<br>
	 Não imprima os colchetes angulares (< e >). Para um zumbi chamado Foo, a mensagem seria:<br>
	 Foo: BraiiiiiiinnzzzZ...<br><br>
	 Em seguida, implemente as duas funções a seguir:<br><br>
	 • Zombie* newZombie( std::string name );<br>
	 Ele cria um zumbi, nomeia e retorna para que você possa usá-lo fora da função escopo<br><br>
	 • void randomChump( std::string name );<br>
	 Ele cria um zumbi, nomeia-o, e o zumbi se anuncia.<br><br>
	 Agora, qual é o objetivo real do exercício?<br>
	 Você tem que determinar em que caso é melhor alocar os zumbis na pilha ou heap.<br><br>
	 Os zumbis devem ser destruídos quando você não precisar mais deles. O destruidor deve imprimir uma mensagem com o nome do zumbi para 	       fins de depuração.</td>
   </tr>
   <tr>
    <td>Ex01: Moar brainz!</td>
    <td>Hora de criar uma horda de zumbis!<br>
    Implemente a seguinte função no arquivo apropriado:<br><br>
    Zombie* zombieHorde( int N, std::string name );<br><br>
    Ele deve alocar N objetos Zombie em uma única alocação. Em seguida, ele deve inicializar os zumbis,dando a cada um deles o nome <br>           passado como parâmetro. A função retorna um ponteiro para o primeiro zumbi.<br>
    Implemente seus próprios testes para garantir que sua função zombieHorde() funcione conforme o esperado.<br>
    Tente chamar anuncie() para cada um dos zumbis.<br><br>
    Não se esqueça de excluir todos os zumbis e verificar se há vazamentos de memória.</td>
   </tr>
   <tr>
    <td>Ex02: HI THIS IS BRAIN</td>
    <td>Escreva um programa que contenha:<br><br>
    • Uma variável de string inicializada como "HI THIS IS BRAIN".<br>
    • stringPTR: Um ponteiro para a string.<br>
    • stringREF: Uma referência à string.<br><br>
    Seu programa deve imprimir:<br>
    • O endereço de memória da variável de string.<br>
    • O endereço de memória mantido por stringPTR.<br>
    • O endereço de memória mantido por stringREF<br><br>
    E então:<br>
    • O valor da variável de string.<br>
    • O valor apontado por stringPTR.<br>
    • O valor apontado por stringREF.<br><br>
    Isso é tudo, sem truques. O objetivo deste exercício é desmistificar referências que podem parecer completamente novas.<br>
    Embora existam algumas pequenas diferenças, esta é outra sintaxe para algo que você já faz: manipulação de endereço.<br>
   </tr>
   <tr>
    <td>Ex03: Unnecessary violence</td>
    <td>Implemente uma classe de arma que tenha:<br>
    • Um tipo de atributo privado, que é uma string.<br>
    • Uma função de membro getType() que retorna uma referência const ao tipo.
    • Uma função de membro setType() que define o tipo usando o novo passado como parâmetro<br><br>
    Agora, crie duas classes: HumanA e HumanB. Ambos têm uma arma e um nome. Eles também têm uma função de membro attack()<br>
    que exibe (é claro, sem os colchetes):<br><br>
    <name> attacks with their <weapon type><br><br>
    HumanA e HumanB são quase iguais, exceto por esses dois pequenos detalhes:<br>
    • Enquanto HumanA pega a Arma em seu construtor, HumanB não.<br>
    • HumanB pode nem sempre ter uma arma, enquanto HumanA sempre estará armado.<br>
    Se sua implementação estiver correta, a execução do código a seguir imprimirá um ataque com "porrete cravado bruto" e um segundo<br>
    ataque com "algum outro tipo de clube" para ambos os casos de teste:<br>
    <img src="img/ex03_modulo01.png"><br>
    
   </tr>

</table>