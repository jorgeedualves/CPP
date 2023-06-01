<table border="1" width="300">

   <tr>
    <td  align="center"colspan="4">Lista</td>
   </tr>
  
   <tr>
      <td align="center">Exercicios</td>
      <td align="center"colspan="4">Descrição</td>
  </tr>
   <tr>
    <td  align="center"colspan="4">Módulo 03</td>
   </tr>
   <tr align="center">
    <td>Ex00: Aaaae... ABRA</td>
    <td>
      
      Primeiro, você tem que implementar uma classe! 
        
      Ele será chamado de ClapTrap e terá os seguintes atributos 
      privados inicializados com os valores
      
      • Nome, que é passado como parâmetro para um construtor
      • Pontos de vida (10), representam a saúde do ClapTrap
      • Pontos de energia (10)
      • Dano de ataque (0)
      
      Adicione as seguintes funções de membro público para que o
      ClapTrap pareça mais realista:
      
      • void attack(const std::string& target)
      • void takeDamage((unsigned int amoun);
      • void beRepaired((unsigned int amoun);
      
      Quando ClapTrack ataca, ele faz com que seu alvo perca 
      <attack damage> pontos de vida. Quando o ClapTrap se repara,
      ele recupera <amount> pontos de vida. Atacar e reparar custa 1
      ponto de energia cada. Claro, ClapTrap não pode fazer nada se não
      tiver pontos de vida ou pontos de energia sobrando.
       
      Em todas essas funções de membro, você deve imprimir uma mensagem
      para descrever o que acontece. Por exemplo, a função attack() pode
      exibir algo como (claro, sem os colchetes):
        
      ClapTrap <name> attacks <target>, causing <damage> pontos de dano!
        
      Os construtores e destruidores também devem exibir uma mensagem,
      para que seus avaliadores podem ver facilmente que foram chamados.
        
      Implemente e entregue seus próprios testes para garantir que seu
      código funcione conforme o esperado
   </tr>
   <tr align="center">
    <td>Ex01:<br> Serena, my love</td>
    <td>
      
      Como você nunca terá ClapTraps suficientes, agora criará um robô derivado
      
      Ele será nomeado ScavTrap e herdará os construtores e destruidores de
      Clap Trap. No entanto, seus construtores, destruidor e attack() imprimirão
      mensagens diferentes.
      Afinal, ClapTraps tem consciência de sua individualidade.
      
      Observe que o encadeamento adequado de construção/destruição deve ser mostrado
      em seus testes.Quando um ScavTrap é criado, o programa começa construindo um ClapTrap.
      A destruição está na ordem nversa. Por que?
      
      ScavTrap usará os atributos de ClapTrap (atualize ClapTrap em consequência) e deve
      inicializá-los para:
      
      • Name, que é passado como parâmetro para um construtor
      • Hit points (100),representam a saúde do ClapTrap
      • Energy points (50)
      • Attack damage (20)
      
      O ScavTrap também terá sua própria capacidade especial:
      void guardGate();
      
      Esta função de membro exibirá uma mensagem informando que o ScavTrap agora está
      no modo Gatekeeper
   </tr>
   <tr align="center">
    <td>Ex02: Repetitive work</td>
    <td>
      
      Agora, implemente uma classe FragTrap que herda de ClapTrap.
      É muito semelhante ao ScavTrap.
      No entanto, suas mensagens de construção e destruição devem ser diferentes.
      O encadeamento adequado de construção/destruição deve ser mostrado em seus testes.
      Quando um FragTrap é criado, o programa começa construindo um ClapTrap.
      A destruição está na ordem inversa
      
      Mesma coisa para os atributos, mas com valores diferentes desta vez:
      
      • Name,que é passado como parâmetro para um construtor
      • Hit points (100), representam a saúde do ClapTrap
      • Energy points (100)
      • Attack damage (30)
      
      FragTrap também tem uma capacidade especial:
      void highFivesGuys(void)
      
      Esta função de membro exibe uma solicitação positiva
      de high fives na saída padrão.
   </tr>
   <tr align="center">
    <td>Ex03: Now it’s weird!</td>
    <td>
      
      Neste exercício, você criará um monstro: um ClapTrap que é meio FragTrap,
      meio ScavTrap.
      Ele será nomeado DiamondTrap e herdará tanto do FragTrap quanto do ScavTrap.
      Isso é tão arriscado!
      
      A classe DiamondTrap terá um atributo privado de nome. Dê a este atributo
      exatamente o mesmo nome da variável (sem falar sobre o nome do robô aqui)
      que o da classe base ClapTrap.
      
      Para ficar mais claro, aqui estão dois exemplos:
      Se a variável do ClapTrap for name, dê o nome name ao do DiamondTrap.
      Se a variável do ClapTrap for _name, dê o nome _name ao do DiamondTrap.
      
      Seus atributos e funções de membro serão escolhidos de qualquer uma de suas
      classes pai:
      
      • Name,que é passado como parâmetro para um construtor
      • ClapTrap::name (parâmetro do construtor + sufixo "_clap_name")
      • Hit points (FragTrap)
      • Energy points (ScavTrap)
      • Attack damage (FragTrap)
      • attack() (Scavtrap)
      
      Além das funções especiais de ambas as classes pai, DiamondTrap terá sua própria
      capacidade especial:
      
      void whoAmI();
      
      Esta função de membro exibirá seu nome e seu nome ClapTrap.
      
      Claro, o subobjeto ClapTrap do DiamondTrap será criado uma vez, e apenas uma vez.
      Sim, há um truque.
    
   </tr>

</table>
