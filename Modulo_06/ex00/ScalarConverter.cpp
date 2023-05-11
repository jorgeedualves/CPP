/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 21:28:58 by joeduard          #+#    #+#             */
/*   Updated: 2023/05/10 15:52:10 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) : _input(""), _raw(0)
{
    std::cout << "Defaut Constructor Called\n";
    return;
}

/**
 * @brief construtor da classe ScalarConverter que converte uma string de entrada em um valor numérico
 * do tipo double, armazenado na variável de membro '_raw'.
 * O construtor recebe um argumento 'inputRaw' do tipo const std::string&, que é a string a ser
 * convertida.
 * 
 * O construtor começa inicializando a variável de membro '_input' com o valor de 'inputRaw' e a
 * variável de membro '_raw' com 0.
 * 
 * A próxima linha de código é um teste condicional usando um 'if', que verifica se o comprimento
 * da string 'inputRaw' é igual a 1 e se o primeiro caractere é uma letra do alfabeto.
 * Se isso for verdadeiro, a letra é convertida em um valor numérico correspondente de acordo
 * com a tabela ASCII e atribuída à variável de membro '_raw' usando
 * static_cast<double>(*inputRaw.begin()).
 * Se o teste condicional não for verdadeiro, o bloco else é executado,
 * onde a função std::strtod é usada para converter a string 'inputRaw' em um valor numérico
 * double. O resultado da conversão é armazenado na variável de membro '_raw'.
 * Em resumo, o construtor da classe ScalarConverter converte a string 'inputRaw' em um valor
 * numérico double e armazena-o na variável de membro '_raw'. Se a string 'inputRaw' for uma
 * letra, a letra é convertida em seu valor numérico correspondente de acordo com a tabela ASCII.
 * 
 * @param inputRaw 
 */
ScalarConverter::ScalarConverter(const std::string& inputRaw) : _input(inputRaw), _raw(0)
{
    std::cout << "Parametric Constructor Called\n";
    if (inputRaw.length() == 1 && std::isalpha(*inputRaw.begin()))
        this->_raw = static_cast<double>(*inputRaw.begin());
    else
        this->_raw = std::strtod(inputRaw.c_str(), NULL);
}

ScalarConverter::ScalarConverter(ScalarConverter& src)
{
    std::cout << "Copy Constructor Called\n";
    *this = src;
}

ScalarConverter::~ScalarConverter(void)
{
    std::cout << "Defaut Destructor Called\n";
    return;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs)
{
    std::cout << "operator= Called\n";
    const_cast<std::string&>(this->_input) = rhs.getInput();
    const_cast<double&>(this->_raw) = rhs.getRaw();
    return (*this);
}

ScalarConverter::operator char()
{
    std::cout << "operator char Called\n";
    return(static_cast<char>(this->_raw));
}
    
ScalarConverter::operator int()
{

    std::cout << "operator int Called\n";
    return (static_cast<int>(this->_raw));
}

ScalarConverter::operator float()
{
    std::cout << "operator float Called\n";
    return (static_cast<float>(this->_raw));
}

ScalarConverter::operator double()
{
    std::cout << "operator double\n";
    return (static_cast<double>(this->_raw));

}

std::string ScalarConverter::getInput(void) const
{
    std::cout << "getInput Called\n";
    return(this->_input);
}

double ScalarConverter::getRaw(void) const
{
    std::cout << "getRaw Called\n";
    return (this->_raw);
}

/**
 * @brief Esse método tem como objetivo converter o valor de uma string de entrada para
 * um caractere do tipo "char" e, em seguida, retornar uma string com informações sobre
 * a conversão.
 * 
 * 1 - std::stringstream ss; - cria um objeto stringstream, que é usado para converter o
 * caractere em uma string.
 * 
 * 2 - char c = static_cast<char>(ScalarConverter(this->_input)); - converte a string de
 * entrada em um caractere do tipo "char" usando um objeto ScalarConverter
 * (que não está definido no código fornecido). A função "static_cast" é usada para
 * realizar a conversão.
 * 
 * 3 - if(this->_input.compare("0") && c == 0) - verifica se a string de entrada é
 * diferente de "0" e se o valor do caractere é igual a zero. Se isso for verdadeiro,
 * a função retorna uma string "char: impossible".
 * 
 * 4 - else if (!std::isprint(c)) - verifica se o valor do caractere não é imprimível
 * (ou seja, não está dentro do conjunto de caracteres ASCII imprimíveis).
 * Se isso for verdadeiro, a função retorna uma string "char: Non displayable".
 * 
 * 5 - else - se nenhum dos casos acima for verdadeiro, o caractere é imprimível e a
 * função converte o caractere em uma string usando o objeto stringstream criado
 * anteriormente e retorna uma string com o formato "char: 'valor_do_caractere'".]
 * 
 * Em resumo, este código é uma implementação de um método que converte uma string
 * para um caractere do tipo "char" e retorna uma string com informações sobre a
 * conversão. A função verifica se o valor do caractere é imprimível ou não,
 * e também verifica se a conversão é possível.
 * 
 * @return std::string 
 */
std::string ScalarConverter::castingChar(void)
{
    std::stringstream ss;
    std::cout << "********castingChar*******\n";
    char c = static_cast<char>(ScalarConverter(this->_input));

    if(this->_input.compare("0") && c == 0)
        return("char: impossible");
    else if (!std::isprint(c))
        return ("char: Non displayable");
    else
    {
        ss << "'" << c << "'";
        return ("char: " + ss.str());
    }
}

/**
 * @brief Esse método tem como objetivo converter o valor de uma string de entrada para
 * um número inteiro do tipo "int" e, em seguida, retornar uma string com informações
 * sobre a conversão.
 * 
 * 1 - std::stringstream ss; - cria um objeto stringstream, que é usado para converter
 * o valor inteiro em uma string.
 * 
 * 2 - int n = static_cast<int>(ScalarConverter(this->_input)); - converte a string de
 * entrada em um número inteiro do tipo "int" usando um objeto ScalarConverter
 * (que não está definido no código fornecido).
 * A função "static_cast" é usada para realizar a conversão.
 * 
 * 3 - if ((this->_input.compare("0") && n == 0) || ((this->_input.compare("-2147483648")
 *            && n == -2147483648)))
 * - verifica se a string de entrada é diferente de "0" e se o valor do número inteiro
 * é igual a zero.
 * Ou, se a string de entrada é diferente de "-2147483648" e o valor do número
 * inteiro é igual a -2147483648. Se isso for verdadeiro, a função retorna uma string
 * "int: impossible".
 * 
 * 4 -else - se nenhum dos casos acima for verdadeiro, a função converte o número
 * inteiro em uma string usando o objeto stringstream criado anteriormente e retorna
 * uma string com o formato "int: valor_do_numero_inteiro".
 * 
 * Em resumo, este código é uma implementação de um método que converte uma string
 * para um número inteiro do tipo "int" e retorna uma string com informações sobre a
 * conversão. A função verifica se a conversão é possível e se o valor convertido
 * está dentro do limite de um inteiro de 32 bits com sinal.
 * 
 * @return std::string 
 */
std::string ScalarConverter::castingInt(void)
{
    std::cout << "********castingInt*******\n";
    std::stringstream ss;
    int n = static_cast<int>(ScalarConverter(this->_input));

    if ((this->_input.compare("0") && n == 0) || ((this->_input.compare("-2147483648")
    && n == -2147483648)))
        return("int: impossible");
    else
    {
        ss << n;
        return("int: "+ ss.str());
    }
}
/**
 * @brief Esse método tem como objetivo converter o valor de uma string de entrada
 * para um número de ponto flutuante do tipo "float" e, em seguida, retornar uma
 * string com informações sobre a conversão.
 * 
 * 1 - std::stringstream ss; - cria um objeto stringstream, que é usado para converter
 * o valor do ponto flutuante em uma string.
 * 
 * 2 - float f = static_cast<float>(ScalarConverter(this->_input));
 * - converte a string de entrada em um número de ponto flutuante do tipo "float"
 * usando um objeto ScalarConverter (que não está definido no código fornecido).
 * A função "static_cast" é usada para realizar a conversão.
 * 
 * 3 - int n = static_cast<int>(ScalarConverter(this->_input));
 * - converte a string de entrada em um número inteiro do tipo "int" usando um objeto
 * ScalarConverter (que não está definido no código fornecido).
 * A função "static_cast" é usada para realizar a conversão.
 * 
 * 4 - if(this->_input.compare("0") && f == 0)
 * - verifica se a string de entrada é diferente de "0" e se o valor do número de ponto
 * flutuante é igual a zero. Se isso for verdadeiro, a função retorna uma
 * string "float : impossible".
 * 
 * 5 - else - se nenhum dos casos acima for verdadeiro, a função converte o número
 * de ponto flutuante em uma string usando o objeto stringstream criado anteriormente
 * e retorna uma string com o formato "float: valor_do_numero_de_ponto_flutuante".
 * 
 * 6 - if (static_cast<float>(n) == f) - verifica se o valor do número de ponto
 * flutuante é igual ao valor do número inteiro. Se isso for verdadeiro,
 * adiciona ".0f" à string.
 * 
 * 7 - else - se o valor do número de ponto flutuante não for igual ao valor do
 * número inteiro, adiciona apenas "f" à string.
 * 
 * Em resumo, este código é uma implementação de um método que converte uma string
 * para um número de ponto flutuante do tipo "float" e retorna uma string com
 * informações sobre a conversão. A função verifica se a conversão é possível e
 * adiciona ".0f" à string se o valor for igual a um número inteiro, caso contrário,
 * adiciona apenas "f" à string.
 * 
 * @return std::string 
 */
std::string ScalarConverter::castingfloat(void)
{
     std::cout << "********castingFloat*******\n";
    std::stringstream ss;
    float f = static_cast<float>(ScalarConverter(this->_input));
    int n = static_cast<int>(ScalarConverter(this->_input));

    if(this->_input.compare("0") && f == 0)
        return ("float : impossible");
    else
    {
        ss << f;
        if (static_cast<float>(n) == f)
            ss << ".0f";
        else
            ss << "f";
    }
    return ("float : "+ ss.str());
}

/**
 * @brief Este método tem como objetivo converter o valor de uma string de entrada para
 * um número de ponto flutuante do tipo "double" e, em seguida, retornar uma string com
 * informações sobre a conversão.
 * 
 * 1 - std::stringstream ss; - cria um objeto stringstream, que é usado para converter
 * o valor do número de ponto flutuante em uma string.
 * 
 * 2 - double d = static_cast<double>(ScalarConverter(this->_input));
 * - converte a string de entrada em um número de ponto flutuante do tipo "double"
 * usando um objeto ScalarConverter (que não está definido no código fornecido). A função "static_cast" é usada para realizar a conversão.

    if (this->_input.compare("0") && d == 0) - verifica se a string de entrada é diferente de "0" e se o valor do número de ponto flutuante é igual a zero. Se isso for verdadeiro, a função retorna uma string "double: impossible".

    else - se nenhum dos casos acima for verdadeiro, a função converte o número de ponto flutuante em uma string usando o objeto stringstream criado anteriormente e retorna uma string com o formato "double: valor_do_numero_de_ponto_flutuante".

    if (static_cast <int>(d) == d) - verifica se o valor do número de ponto flutuante é igual ao valor do número inteiro. Se isso for verdadeiro, adiciona ".0" à string.

    return ("double: "+ ss.str()); - retorna a string final com informações sobre a conversão.

Em resumo, este código é uma implementação de um método que converte uma string para um número de ponto flutuante do tipo "double" e retorna uma string com informações sobre a conversão. A função verifica se a conversão é possível e adiciona ".0" à string se o valor for igual a um número inteiro.
 * 
 * @return std::string 
 */
std::string ScalarConverter::castingDouble(void)
{
     std::cout << "********castingDouble*******\n";
    std::stringstream ss;
    double d = static_cast<double>(ScalarConverter(this->_input));

    if (this->_input.compare("0") && d == 0)
        return("double: impossible");
    else
    {
        ss << d;
        if (static_cast <int>(d) == d)
            ss << ".0";
        return ("double: "+ ss.str());
    }
}