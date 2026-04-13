/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abignals <abignals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 16:44:22 by abignals          #+#    #+#             */
/*   Updated: 2026/04/13 18:39:57 by abignals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string _name;
        bool              _isSigned;
        const int         _toSign;
        const int         _toExec;
        
    public:
        Form();
        Form(std::string name, int toSign, int toExec);
        Form& operator=(const Form& src);
        Form(const Form& src);
        ~Form();

        std::string getName() const;
        bool        getSigned() const;
        int         getToSign() const;
        int         getToExec() const;
        void        beSigned(const Bureaucrat& Bureaucrat);

        class GradeTooHighException : public std::exception
        {
            const char *what() const throw()
            {
                return ("Form grade too high");
            }
        };
        
        class GradeTooLowException : public std::exception
        {
            const char* what() const throw()
            {
                return ("Form grade too low");
            }    
        };

        class GradeTooLowToSignException : public std::exception
        {
            const char* what() const throw()
            {
                return ("Grade too low to sign");
            }    
        };

        class AlreadySignedException : public std::exception
        {
            const char* what() const throw()
            {
                return ("Form is already signed");
            }
        };
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif //FORM_HPP