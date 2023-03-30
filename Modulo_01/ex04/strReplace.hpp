/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strReplace.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:57:40 by joeduard          #+#    #+#             */
/*   Updated: 2023/03/29 23:14:15 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRREPLACE_HPP
#define STRREPLACE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

std::string replaced(const std::string& str, const std::string oldStr, const std::string newStr, size_t size);
std::string replace(const std::string& str, const std::string oldStr, const std:: string newStd);
 
#endif