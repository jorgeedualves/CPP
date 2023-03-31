/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strReplace.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 22:18:43 by joeduard          #+#    #+#             */
/*   Updated: 2023/03/30 22:21:09 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strReplace.hpp"

std::string replaced(const std::string& str, const std::string oldStr, const std::string newStr, size_t strPos)
{
    std::string strReplaced;

    if(str.empty() || oldStr.empty() || newStr.empty())
        return (str);
    strPos = str.find(oldStr, strPos);
    std::cout << "0: " << strPos << std::endl;
    if(strPos == std::string::npos)
        return(str);
    strReplaced = str.substr(0, strPos); // Hi w
    std::cout << "[" << strReplaced << "]";
    strReplaced.append (newStr); // X
     std::cout << "(" << strReplaced << ")";
    strReplaced.append(str.substr(strPos + oldStr.length()));
     std::cout << "{" << strReplaced << "}" << std::endl;
    return (strReplaced);
}

std::string replace(const std::string& str, const std::string oldStr, const std:: string newStr)
{
    std::string strReplaced;
    if (str.empty() || oldStr.empty() || newStr.empty())
        return (str);
    strReplaced.assign(str);
    size_t pos = strReplaced.find(oldStr);
    while (pos != std::string::npos)
    {
      strReplaced = replaced(strReplaced, oldStr, newStr, pos);
      pos = strReplaced.find(oldStr, pos + newStr.length());   
    }
    return (strReplaced); 
}

//  argc_2 = argv[1] file a ser lido " Hi world, Hello Jorge como vai"
//     argc_3 = argv[2] s1 com o texto para ser procurado    " Hello Jorge"
//     argc_4 = argv[3] s2 com o texto será substituir o s1  " Ola alexandre"