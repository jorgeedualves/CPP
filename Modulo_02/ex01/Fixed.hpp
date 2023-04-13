/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:01:54 by joeduard          #+#    #+#             */
/*   Updated: 2023/04/13 16:51:53 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed{

/**
 * @brief 
 * Fixed() é o construtor padrão sem argumentos.
   Fixed(Fixed const &src) é o construtor de cópia que recebe um objeto Fixed como parâmetro.
   Fixed(int const n) é um construtor explícito que recebe um inteiro como parâmetro.
   Fixed(float const f) é um construtor explícito que recebe um número de ponto flutuante como parâmetro.
   ~Fixed() é o destrutor que libera qualquer recurso alocado pela classe.
   operator= é o operador de atribuição que recebe um objeto Fixed como parâmetro e retorna uma referência a um objeto Fixed.
   getRawBits() retorna o valor inteiro dos bits brutos armazenados na classe.
   setRawBits(int const raw) define os bits brutos armazenados na classe para um valor inteiro fornecido.
   toFloat() retorna o valor do número de ponto fixo como um número de ponto flutuante.
   toInt() retorna o valor do número de ponto fixo como um inteiro.
 * 
 */
public:
    Fixed(void);
    Fixed(Fixed const &src);
    explicit Fixed(int const n);
    explicit Fixed(float const f);
    ~Fixed(void);

    Fixed &operator=(Fixed const &src);

    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;

/**
 * @brief 
 * _rawBits: um inteiro que armazena o valor do número de ponto fixo em um formato de ponto fixo com
 * a quantidade fixa de bits fracionais.
   _fractionalBits: um inteiro constante e estático que representa a quantidade fixa de bits fracionais.
 * 
 */
private:
    int _rawBits;
    static int const _fractionalBits;
};

/**
 * @brief sobrecarga do operador de fluxo de saída (<<) definida fora da classe Fixed que permite que um objeto Fixed seja impresso na tela usando o operador <<.
 * 
 * @param o 
 * @param i 
 * @return std::ostream& 
 */
std::ostream &operator<<(std::ostream &output_stream, Fixed const &fixed_number);

#endif