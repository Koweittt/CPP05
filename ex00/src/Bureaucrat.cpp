/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abignals <abignals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 19:02:01 by abignals          #+#    #+#             */
/*   Updated: 2026/04/10 20:01:51 by abignals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _grade(150), _name("Unknown") {}

Bureaucrat::Bureaucrat(int grade, std::string name) : _name(name) 
{
    _grade = grade;
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) : _grade(src._grade), _name(src._name) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src)
{
    if (this != &src)
    {
        this->_grade = src._grade;
    }
    return (*this);
}

Bureaucrat::~Bureaucrat() {}

int Bureaucrat::getGrade() const
{
    return (_grade);
}

std::string Bureaucrat::getName() const
{
    return (_name);
}

void Bureaucrat::incrementGrade()
{
    if (_grade <= 1)
        throw GradeTooHighException();
    _grade--;
}

void Bureaucrat::decrementGrade()
{
    if (_grade >= 150)
        throw GradeTooHighException();
    _grade++;
}

std::ostream& operator<<(std::ostream &os, const Bureaucrat& src)
{
    std::cout << src.getName() << ", bureaucrat grade " << src.getGrade() << ".";
    return (os);
}
