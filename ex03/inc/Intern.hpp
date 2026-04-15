/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abignals <abignals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 15:49:57 by abignals          #+#    #+#             */
/*   Updated: 2026/04/15 16:03:05 by abignals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class Intern
{
    private:
        Intern();
        ~Intern();

    public:
        AForm* makeForm(const std::string formName, const std::string other) const;

        class NameNotFoundException : public std::exception
        {
            const char * what() const throw()
            {
                return ("Form name not found");
            }
        };
};

#endif //INTERN_HPP