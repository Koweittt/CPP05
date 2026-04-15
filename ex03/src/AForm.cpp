/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abignals <abignals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 16:54:24 by abignals          #+#    #+#             */
/*   Updated: 2026/04/13 18:49:06 by abignals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AForm.hpp"

AForm::AForm() : _name("Random AForm"), _isSigned(false), _toSign(150), _toExec(150) {}

AForm::AForm(std::string name, int toSign, int toExec) :
_name(name), _isSigned(false), _toSign(toSign), _toExec(toExec)
{
    if (toSign > 150 || toExec > 150)
        throw GradeTooLowException();
    else if (toSign < 1 || toExec < 1)
        throw GradeTooHighException();
}

AForm::AForm(const AForm& src) : _name(src._name), _isSigned(src._isSigned), _toSign(src._toSign), _toExec(src._toExec) 
{}

AForm& AForm::operator=(const AForm&src)
{
    if (this != &src)
    {
        this->_isSigned = src._isSigned;
    }
    return (*this);
}

AForm::~AForm() {};

std::string AForm::getName() const
{
    return this->_name;
}

bool AForm::getSigned() const
{
    return this->_isSigned;
}

int AForm::getToExec() const 
{
    return this->_toExec;
}

int AForm::getToSign() const 
{
    return this->_toSign;
}

void AForm::beSigned(const Bureaucrat& Bur)
{
    if (this->_isSigned == true)
        throw AlreadySignedException();
    else if (Bur.getGrade() > this->_toSign)
        throw GradeTooLowToSignException();
    else
        this->_isSigned = true;
}
std::ostream& operator<<(std::ostream& os, const AForm& src)
{
    if (src.getSigned() == true)
        std::cout << "This form name is " << src.getName() << " it is signed, required " << src.getToSign() << " to be signed and " << src.getToExec() << "to be executed" << std::endl;
    else
        std::cout << "This form name is " << src.getName() << " isn't signed, require " << src.getToSign() << " to be signed and " << src.getToExec() << "to be executed" << std::endl;
    return (os);
}

void AForm::checkSignAndGrade(const Bureaucrat& executor, int ToExec) const
{
    if (_isSigned == false)
        throw NotSignedException();
    if (executor.getGrade() > ToExec)
        throw GradeTooLowException();
}

