/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:02:45 by joeduard          #+#    #+#             */
/*   Updated: 2023/04/13 16:05:54 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int const Fixed::_fractionalBits = 8;

/**
 * @brief Construtor padrão da classe Fixed. Esse construtor é chamado quando um objeto Fixed é criado sem argumentos.

O construtor inicializa o membro _rawBits com o valor 0 e exibe uma mensagem na saída padrão indicando
que o construtor padrão foi chamado. A inicialização do _rawBits com 0 é feita usando a 
sintaxe : _rawBits(0) após a lista de inicializadores do construtor.

Por fim, o construtor padrão retorna sem retornar nenhum valor explícito.
O construtor padrão é uma função importante para permitir a criação de objetos Fixed com um
valor inicial padrão e é chamado automaticamente pelo compilador quando um objeto é criado sem argumentos.
 * 
 */
Fixed::Fixed(void) : _rawBits(0)
{
	std::cout << "Default Constructor called" << std::endl;
	return;
}

/**
 * @brief construtor de cópia da classe Fixed. Esse construtor é chamado quando um objeto Fixed é criado a partir de outro objeto já existente.

O construtor exibe uma mensagem na saída padrão indicando que o construtor de cópia foi chamado e, em seguida, chama o operador de atribuição sobrecarregado
da classe (operator=) para copiar os valores do objeto src para o objeto atual.
Isso é feito usando o operador de atribuição *this = src.

Por fim, o construtor de cópia retorna sem retornar nenhum valor explícito.
O construtor de cópia é uma função importante para permitir a criação de cópias de objetos Fixed e é chamado
automaticamente pelo compilador em muitas situações, como quando um objeto é passado por valor para uma função
ou quando um objeto é retornado de uma função.
 * 
 */
Fixed::Fixed(Fixed const &src) 
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return;
}

/**
 * @brief construtor da classe Fixed. Esse construtor recebe um inteiro n como parâmetro e inicializa o objeto Fixed com o valor correspondente a n convertido para o formato de ponto fixo.

O construtor exibe uma mensagem na saída padrão indicando que o construtor foi chamado e, em seguida, define o valor do membro _rawBits como n deslocado fractionalBits posições à esquerda (isto é, n é multiplicado por 2^fractionalBits). O membro _fractionalBits é uma constante que representa o número de bits que serão usados para representar a parte fracionária do número em ponto fixo.

Em resumo, esse construtor permite que um objeto Fixed seja inicializado a partir de um inteiro e define seu valor interno em ponto fixo de acordo com a quantidade de bits especificados para a parte fracionária.
 * 
 * @param n 
 */
Fixed::Fixed(int const n)
{
    std::cout << "Int constructor called" << std::endl;
    this->_rawBits = n << _fractionalBits;
}

/**
 * @brief Construtor da classe Fixed que recebe um valor de ponto flutuante (float) como argumento. O construtor converte o valor de ponto flutuante em um valor de ponto fixo e armazena o resultado na variável membro _rawBits.

A implementação do construtor usa a função roundf da biblioteca padrão do C++ para arredondar o valor de ponto flutuante para o valor mais próximo de ponto fixo. A função roundf retorna um valor de ponto flutuante arredondado para o inteiro mais próximo.

Antes de chamar a função roundf, o construtor multiplica o valor de ponto flutuante por 2 elevado à potência de _fractionalBits, o que é o mesmo que deslocar os bits do valor de ponto flutuante para a esquerda em _fractionalBits posições. Isso garante que o valor de ponto flutuante seja multiplicado pelo fator correto para se tornar um valor de ponto fixo.

O resultado da multiplicação é convertido em um valor inteiro usando a função static_cast<int>. Esse valor inteiro é armazenado na variável membro _rawBits, que representa o valor de ponto fixo armazenado no objeto Fixed.

Finalmente, o construtor imprime uma mensagem na saída padrão indicando que o construtor de ponto flutuante foi chamado.

Em resumo, esse construtor é útil para inicializar um objeto Fixed a partir de um valor de ponto flutuante, o que pode ser necessário em situações em que o código precisa trabalhar com diferentes tipos de números ou em cálculos que requerem precisão fixa.
 * 
 * @param f 
 */
Fixed::Fixed(float const f)
{
    std::cout << "Float constructor called" << std::endl;
    this->_rawBits = static_cast<int>(roundf(f *(1 << _fractionalBits)));
}

/**
 * @brief o destrutor da classe Fixed. O destrutor é uma função especial que é chamada automaticamente
 * pelo compilador quando um objeto é destruído, ou seja, quando a memória alocada para o objeto é liberada.

O destrutor não tem nenhum parâmetro e não retorna nenhum valor. No código acima, o destrutor exibe uma
mensagem na saída padrão indicando que o destrutor foi chamado.

O objetivo principal do destrutor é executar qualquer limpeza de recursos necessária antes que o objeto seja
destruído. Isso pode incluir a liberação de memória alocada dinamicamente, a liberação de recursos do sistema
ou a notificação de outros objetos que o objeto atual está sendo destruído.

É importante lembrar que o destrutor é chamado automaticamente pelo compilador e não precisa ser chamado
explicitamente pelo programador. O destrutor é uma parte importante da gerência automática de memória em
C++ e ajuda a evitar vazamentos de memória e outros problemas relacionados ao gerenciamento manual de memória.
 * 
 */
Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}

/**
 * @brief operador de atribuição (operator=) para a classe Fixed. O operador de atribuição é usado para
 * atribuir o valor de um objeto a outro objeto da mesma classe.

O operador de atribuição tem um parâmetro constante por referência src, que é o objeto a ser atribuído ao
objeto atual. A função retorna uma referência ao objeto atual, permitindo a chamada encadeada de operadores.

Dentro do operador de atribuição, uma mensagem é exibida na saída padrão indicando que o operador de
atribuição foi chamado. Em seguida, o valor de src é atribuído ao objeto atual usando o método
setRawBits() da classe Fixed. O método setRawBits() é responsável por definir o valor bruto do objeto Fixed.

Por fim, o operador de atribuição retorna uma referência ao objeto atual (*this), permitindo que o operador
de atribuição seja encadeado com outros operadores ou chamadas de função.

O operador de atribuição é uma parte importante da sobrecarga de operadores em C++ e permite que objetos da
classe Fixed sejam copiados e atribuídos uns aos outros.
 * 
 * @param src 
 * @return Fixed& 
 */
Fixed &Fixed::operator=(Fixed const &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(src.getRawBits());
	return (*this);
}

/**
 * @brief método membro chamado getRawBits() na classe Fixed. Esse método é usado para obter o valor bruto
 * do objeto Fixed.

O método getRawBits() não tem parâmetros e retorna um valor inteiro que representa o valor bruto do objeto
Fixed.

O método getRawBits() é definido como constante, o que significa que ele não pode modificar o estado do
objeto Fixed. Essa é uma boa prática de programação para métodos que apenas retornam informações sobre o
objeto.

O método getRawBits() é útil porque permite que o valor bruto do objeto Fixed seja acessado de fora da classe,
o que pode ser necessário em algumas situações. É importante lembrar que o valor bruto do objeto Fixed é um
número inteiro que representa a parte fracionária do número armazenado pelo objeto, e não o número completo
em ponto flutuante.
 * 
 * @return int 
 */
int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return(this->_rawBits);
}

/**
 * @brief método membro chamado setRawBits() na classe Fixed. Esse método é usado para definir o valor
 * bruto do objeto Fixed.

O método setRawBits() tem um parâmetro inteiro constante raw, que representa o valor bruto a ser definido
para o objeto Fixed. O método atribui o valor raw ao membro de dados privado _rawBits do objeto Fixed.

O método setRawBits() não retorna nenhum valor e é definido como void, o que significa que não há valor de
retorno.

O método setRawBits() é útil porque permite que o valor bruto do objeto Fixed seja definido de fora da classe,
o que pode ser necessário em algumas situações. É importante lembrar que o valor bruto do objeto Fixed é um
número inteiro que representa a parte fracionária do número armazenado pelo objeto, e não o número completo
em ponto flutuante.
 * 
 * @param raw 
 */
void Fixed::setRawBits(int const raw)
{
	this->_rawBits = raw;
	return;
}

/**
 * @brief método membro chamado toInt() na classe Fixed. Esse método é usado para converter o valor
 * armazenado no objeto Fixed em um número inteiro.

O método toInt() não tem parâmetros e retorna um valor inteiro.
O método usa o operador de deslocamento à direita (>>) para deslocar o valor do membro de dados
privado _rawBits para a direita, de modo que os bits fracionários são descartados.
O resultado desse deslocamento é o valor inteiro equivalente ao valor armazenado no objeto Fixed.

O valor deslocado é então retornado pelo método toInt().

O método toInt() é útil porque permite que o valor armazenado no objeto Fixed seja convertido em um
número inteiro para operações aritméticas ou outras operações que exigem um valor inteiro.
É importante lembrar que a conversão para inteiro pode resultar em perda de precisão,
uma vez que os bits fracionários são descartados.
 * 
 * @return int 
 */
int Fixed::toInt(void) const
{
    return (this->_rawBits >> _fractionalBits);
}

/**
 * @brief método membro chamado toFloat() na classe Fixed. Esse método é usado para converter o valor
 * armazenado no objeto Fixed em um número em ponto flutuante.

O método toFloat() não tem parâmetros e retorna um valor em ponto flutuante. O método usa o operador
de deslocamento à direita (>>) para deslocar o valor do membro de dados privado _rawBits para a direita,
de modo que os bits fracionários são descartados. O resultado desse deslocamento é um valor inteiro
equivalente ao valor armazenado no objeto Fixed.

O valor inteiro é então convertido em um valor em ponto flutuante usando a função static_cast<float>.
A conversão para ponto flutuante é realizada dividindo o valor inteiro pelo valor 2 elevado à
potência _fractionalBits. Isso é necessário porque o valor armazenado no objeto Fixed representa a
parte fracionária do número em ponto flutuante.

O valor em ponto flutuante é então retornado pelo método toFloat().

O método toFloat() é útil porque permite que o valor armazenado no objeto Fixed seja convertido em um
número em ponto flutuante para operações aritméticas ou outras operações que exigem um valor em ponto
flutuante. É importante lembrar que a conversão para ponto flutuante pode resultar em perda de precisão,
uma vez que os bits fracionários são representados com menos precisão do que os bits inteiros.
 * 
 * @return float 
 */
float Fixed::toFloat(void) const
{
    return (static_cast<float>(this->_rawBits) / (1 << _fractionalBits));
}

/**
 * @brief função amiga (friend) sobrecarregada do operador de inserção << que permite que um objeto Fixed seja impresso na saída padrão (std::cout).

A função recebe dois argumentos: um objeto do tipo std::ostream que representa a saída padrão (std::cout), e um objeto constante do tipo Fixed que representa o valor a ser impresso.

A implementação da função chama a função toFloat() do objeto Fixed para obter o valor do ponto fixo em forma de ponto flutuante e, em seguida, imprime o resultado na saída padrão usando o operador de inserção << do objeto std::ostream.

A função retorna uma referência para o objeto std::ostream passado como argumento, permitindo que várias operações de inserção de dados sejam encadeadas em uma única instrução.

Em resumo, essa função é útil para imprimir o valor de um objeto Fixed na saída padrão de uma maneira conveniente e legível. É importante destacar que essa função só permite imprimir valores de ponto fixo como valores de ponto flutuante.
 * 
 * @param o 
 * @param i 
 * @return std::ostream& 
 */
std::ostream &operator<<(std::ostream &o, Fixed const &i)
{
	o << i.toFloat();
	return(o);
}

