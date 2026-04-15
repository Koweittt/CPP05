/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abignals <abignals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 16:00:10 by abignals          #+#    #+#             */
/*   Updated: 2026/04/14 16:47:30 by abignals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("UnknownTarget") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src) : AForm(src), _target(src._target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& src)
{
    if (this != &src)
    {
        AForm::operator=(src);
        this->_target = src._target;
    }
    return (*this);
}

const std::string RobotomyRequestForm::getTarget() const
{
    return (this->_target);
}

void RobotomyRequestForm::execute(const Bureaucrat& Bur) const
{
    checkSignAndGrade(Bur, this->getToExec());
    std::cout << "* some drilling noise *" << std::endl;
    if (std::rand() % 2 == 0)
        std::cout << this->getTarget() << " has been robotomized" << std::endl;
    else
        std::cout << "failed to robotomize " << this->getTarget() << std::endl;
}
