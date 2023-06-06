### Construtor PhoneBook::PhoneBook():
```mermaid
graph LR
    A[Início] --> B[Criação do objeto PhoneBook]
    B --> C[Definir _index como 0]
    C --> D[Definir _count como 0]
    D --> E[Término]
```
### Método PhoneBook::addContact():
```mermaid
graph
    A[Início] --> B[Capturar dados do contato]
    B --> C[Chamar métodos setFirstName, setLastName, setNickName, setPhoneNumber e setDarkestSecret do objeto Contact]
    C --> D[Verificar limite de contatos]
    D --> E[Incrementar _count]
    E --> F[Incrementar _index]
    F --> G[Verificar _index >= 8]
    G -- Sim --> H[Calcular _index % 8]
    G -- Não --> I[Término]
```
### Método PhoneBook::searchContact():
```mermaid
graph LR
    A[Início] --> B[Capturar índice do contato]
    B --> C[Verificar se o índice é válido]
    C -- Sim --> D[Chamar método printOneContact com o contato correspondente]
    C -- Não --> E[Imprimir 'Índice inválido!']
    D --> F[Término]
    E --> F[Término]
```
### Método PhoneBook::formatPrinting():
```mermaid
 graph LR
    A[Início] --> B[Verificar se o comprimento de str é maior que 9]
    B -- Sim --> C[Imprimir str.substr de '0, 9' + '.']
    B -- Não --> D[Imprimir str]
    C --> E[Término]
    D --> E[Término]
```
### Método PhoneBook::printAllContacts():
```mermaid
  graph
    A[Início] --> B[Imprimir cabeçalho da tabela]
    B --> C[Loop para cada contato]
    C --> D[Imprimir índice do contato]
    D --> E[Chamar método formatPrinting para o primeiro nome do contato]
    E --> F[Chamar método formatPrinting para o sobrenome do contato]
    F --> G[Chamar método formatPrinting para o apelido do contato]
    G --> H[Término]
```
### Método PhoneBook::printOneContact():
```mermaid
 graph
    A[Início] --> B[Imprimir primeiro nome do contato]
    B --> C[Imprimir sobrenome do contato]
    C --> D[Imprimir apelido do contato]
    D --> E[Imprimir número de telefone do contato]
    E --> F[Imprimir segredo mais sombrio do contato]
    F --> G[Término]
```
### Método PhoneBook::getContactsCount():
```mermaid
 graph LR
    A[Início] --> B[Retornar o valor de _count]
    B --> C[Término]
```

