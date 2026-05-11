/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koweit <koweit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 16:00:13 by abignals          #+#    #+#             */
/*   Updated: 2026/05/11 15:43:45 by koweit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Intern.hpp"

struct Parse
{
    std::string name;
    AForm* (*create)(const std::string&);
};

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern& src)
{
    (void)src;
}

AForm* createShrubbery(const std::string& target)
{
    return new ShrubberyCreationForm(target);
}

AForm* createRobotomy(const std::string& target)
{
    return new RobotomyRequestForm(target);
}

AForm* createPresidentialPardon(const std::string& target)
{
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string formName, const std::string target) const
{
    Parse forms[3] = 
    {
        {"presidential pardon", createPresidentialPardon},
        {"robotomy request", createRobotomy},
        {"shrubbery creation", createShrubbery}
    };
    
    for (int i = 0; i < 3; i++)
    {
        if (formName == forms[i].name)
        {
            std::cout << "Intern creates " << formName << std::endl;
            return (forms[i].create(target));
        }
    }
    std::cerr << "Didn't find form called : " << formName << std::endl;  
    return (NULL);
}