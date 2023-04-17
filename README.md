# CPP
C++ é uma linguagem de programação compilada multi-paradigma e de uso geral.O objetivo desses módulos é apresentá-lo à Programação Orientada a Objetos.
Este será o ponto de partida de sua jornada C++. Muitos idiomas são recomendados para aprender
OOP. Decidimos escolher C++, pois é derivado do seu velho amigo C.
Por se tratar de uma linguagem complexa e para manter as coisas simples, seu código estará em
conformidade com o padrão C++98

# Descrições:

- **Standard Library** - A biblioteca padrão C++ fornece vários contêineres genéricos, funções para usar e manipular esses contêineres, objetos de função, strings e fluxos genéricos (incluindo I/O interativa e de arquivo), suporte para alguns recursos de linguagem e funções para tarefas comuns, como encontrar a raiz quadrada de um número.
- **istream -** significa fluxo de entrada para obter entradas;
- **ostream -** fluxo de saída para fornecer saídas;
- **Stream(fluxo)** - É uma sequência de caracteres lidos ou gravado em um dispositivo de entrada e saída.
- **iostream** - É uma biblioteca que faz parta da biblioteca padrão “Standard Library”Composta por istream e ostream; Há 4 objetos definidos por ela:
    
    1. **cin** - Objeto do tipo istream usado para entrada padrão (standard input);
    2. **cout** - Significa Saída do Console. Objeto do tipo ostream de saída padrão (standard output);
    3. **cerr** - Objeto do tipo ostream de erro padrão (standard error);
    4. **clog** - Objeto do tipo ostream usado para informações gerais (general information);
##

- **Namespace** - É uma região declarativa que fornece uma escopo para os identificadores dentro dela. os indetificadores são:
    - Nomes de tipos, funções ou variáveis e etc. Para esses tipos de indenficadores, o namespace é uma região declarativa que fornecerá o escopo para isso.
    Namespaces são usados para organizar o código em grupos lógicos e evitar colisões de nomes que podem ocorrer quando a base de código inclue várias bibliotecas.
- **Operador de resolução do escopo ::** - É utilizado para identificar e remover ambiguidades de identificadores usados em escopos diferentes. Para mais informações sobre escopo.

Tudo em C++ é associado a classes e objetos, juntamente com seus atributos e métodos.

- **Classe** - Uma classe é definida pelo utilizador tipo de dados que podemos utilizar no nosso programa, e funciona como um construtor de objeto, ou um "modelo" para a criação de objetos.

- **Objeto** - É criado a partir de uma classe. Para criar um objeto basta especificar as nome da classe, seguido do nome do objeto. Pode-se criar vários objetos de uma classe. 

Em C++, existem três especificadores de acesso:

    public - membros são acessíveis de fora da classe
    private - membros não pode ser acessado (ou visto) de fora da classe
    protected - membros não podem ser acessados a partir de fora da sala de aula, no entanto, eles podem ser acessados em classes herdadas.

##

- **Sobrecarga de Operadores** - Permite que a linguagem seja estendida e que você possa fazer somas, multiplicações, conversões e várias outras operações entre os objetos que você criou.

    - A linguagem C++ tem como um de seus objetivos fazer classes e objetos trabalharem de forma similar às variáveis e tipos primitivos (char, int, float, double, wchar_t e bool.)
    
    - Para sobrecarregar um operador utiliza-se uma forma especial de função, chamada de função operator:
    
      operator+() Sobrecarrega operador de soma;
      
      operator*() Sobrecarrega opetador de multipilicação;
        
    A sobrecarga permite:
      Tratar classes como tipos primitivos;
      Simplificar o uso de objetos dessas classes;
    
    A maior parte dos operadores podem ser sobrecarregados através de **métodos** ou **funções**
   
   **Restrições**
   
   - Usar um operador como método de uma classe
        - obriga o operando esquerdo a ser um objeto
   
   - Os operadores não precisam ser métodos
        - Mas pelo menos um dos operandos deve ser um objeto de uma classe definida pelo programador
        
   - Não é possivel:
        - Alterar as regras de uso do operador
            - Alterar a Precedência, número de argumetnos, etc. (operador + requer dois operandos)
        - Criar operadores
            - Só é possível sobrescrever operadores existentes. (operador @ não existe na linguagem C++)
    
