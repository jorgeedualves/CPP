/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 21:28:58 by joeduard          #+#    #+#             */
/*   Updated: 2023/05/10 12:38:49 by joeduard         ###   ########.fr       */
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

std::string ScalarConverter::castingInt(void)
{
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

std::string ScalarConverter::castingfloat(void)
{
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

std::string ScalarConverter::castingDouble(void)
{
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