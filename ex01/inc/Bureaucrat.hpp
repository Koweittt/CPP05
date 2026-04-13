/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abignals <abignals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 18:59:06 by abignals          #+#    #+#             */
/*   Updated: 2026/04/13 18:46:39 by abignals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <ostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
    private:
        int                 _grade;
        std::string const   _name;
        
    public:
        Bureaucrat();
        Bureaucrat(int grade, std::string name);
        Bureaucrat(const Bureaucrat& src);
        Bureaucrat& operator=(const Bureaucrat& src);
        ~Bureaucrat();

        int getGrade() const;
        std::string getName() const;
        void incrementGrade();
        void decrementGrade();

        void signForm(Form& form);

    class GradeTooHighException : public std::exception
    {
        virtual const char* what() const throw()
        {
            return ("Grade too high !");
        }
    };
    
    class GradeTooLowException : public std::exception
    {
        virtual const char* what() const throw()
        {
            return ("Grade too low !");
        }
    };
};

std::ostream& operator<<(std::ostream &os, const Bureaucrat& src);

#endif //BUREAUCRAT_HPP