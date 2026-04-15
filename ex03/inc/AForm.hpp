/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abignals <abignals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 16:44:22 by abignals          #+#    #+#             */
/*   Updated: 2026/04/15 15:11:43 by abignals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"


class Bureaucrat;

class AForm
{
    private:
        const std::string _name;
        bool              _isSigned;
        const int         _toSign;
        const int         _toExec;
        
    public:
        AForm();
        AForm(std::string name, int toSign, int toExec);
        AForm& operator=(const AForm& src);
        AForm(const AForm& src);
        virtual ~AForm();

        std::string         getName() const;
        bool                getSigned() const;
        int                 getToSign() const;
        int                 getToExec() const;
        void                beSigned(const Bureaucrat& Bureaucrat);
        virtual void        execute(Bureaucrat const& executor) const = 0;
        void                checkSignAndGrade(const Bureaucrat& executor, int ToExec) const;

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

        class NotSignedException : public std::exception
        {
            const char* what() const throw()
            {
                return ("Form is not signed");
            }
        };
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif //AFORM_HPP