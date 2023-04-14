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

    /**
     * @brief 
     * operadores de comparação para verificar se um objeto "Fixed" é maior, menor, maior ou igual,
     * menor ou igual, igual ou diferente de outro objeto "Fixed".
     * 
     * @param src 
     * @return true 
     * @return false 
     */ 
    bool operator>(Fixed const &src) const;
    bool operator<(Fixed const &src) const;
    bool operator>=(Fixed const &src) const;
    bool operator<=(Fixed const &src) const;
    bool operator==(Fixed const &src) const;
    bool operator!=(Fixed const &src) const;

    /**
     * @brief operadores aritméticos para adicionar, subtrair, multiplicar e dividir dois objetos "Fixed".
     * 
     * @param src 
     * @return Fixed& 
     */
    Fixed operator+(Fixed const &src);
    Fixed operator-(Fixed const &src);
    Fixed operator*(Fixed const &src);
    Fixed operator/(Fixed const &src);

    /**
     * @brief operadores de pré-incremento e pós-incremento, bem como operadores de pré-decremento
     * e pós-decremento.
     * 
     * @return Fixed& 
     */
    Fixed &operator++(void);
    Fixed operator++(int);
    Fixed &operator--(void);
    Fixed operator--(int);

    /**
     * @brief funções estáticas para obter o valor mínimo e máximo entre dois objetos "Fixed".
     * 
     * @param lhs 
     * @param rhs 
     * @return Fixed& 
     */
    static Fixed &min(Fixed &lhs, Fixed &rhs);
    static Fixed const &min(Fixed const &lhs, Fixed const &rhs);
    static Fixed &max(Fixed &lhs, Fixed &rhs);
    static Fixed const &max(Fixed const &lhs, Fixed const &rhs);

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