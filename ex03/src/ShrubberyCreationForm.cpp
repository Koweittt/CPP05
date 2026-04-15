/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abignals <abignals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 16:00:10 by abignals          #+#    #+#             */
/*   Updated: 2026/04/14 16:47:30 by abignals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("UnknownTarget") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src) : AForm(src), _target(src._target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src)
{
    if (this != &src)
    {
        AForm::operator=(src);
        this->_target = src._target;
    }
    return (*this);
}

const std::string ShrubberyCreationForm::getTarget() const
{
    return (this->_target);
}

void    ShrubberyCreationForm::execute(const Bureaucrat& Bur) const
{
    checkSignAndGrade(Bur, this->getToExec());
    std::ofstream out((this->_target + "_shrubbery").c_str());
    if (!out)
        throw ErrorCreatingFileException();
    out << " \\ | /  " << std::endl 
        << "  \\|/    " << std::endl 
        << "   |     " << std::endl;
    out.close();
}