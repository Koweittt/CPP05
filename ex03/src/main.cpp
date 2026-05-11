/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koweit <koweit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 00:07:06 by abignals          #+#    #+#             */
/*   Updated: 2026/05/11 15:48:31 by koweit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/Intern.hpp"
#include "../inc/Bureaucrat.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include <ctime>

int main() {
    std::srand(std::time(NULL));

    std::cout << "Test for Intern making PresidentialPardonForm\n" << std::endl; 
    try
    {
       Intern someRandomIntern;
       Bureaucrat B(1, "B");
       AForm* rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
       
       if (rrf)
       {
           B.signForm(*rrf);
           B.executeForm(*rrf);
           delete rrf;
       }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << "\n------------------------------------------------\n\n";

    std::cout << "Test for Intern making RobotomyRequestForm\n" << std::endl; 
    try
    {
       Intern someRandomIntern;
       Bureaucrat B(1, "B");
       AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");
       
       if (rrf)
       {
           B.signForm(*rrf);
           B.executeForm(*rrf);
           delete rrf;
       }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "\n------------------------------------------------\n\n";

    std::cout << "Test for Intern making ShrubberyCreationForm\n" << std::endl; 
    try
    {
       Intern someRandomIntern;
       Bureaucrat B(1, "B");
       AForm* rrf = someRandomIntern.makeForm("shrubbery creation", "Garden");
       
       if (rrf)
       {
           B.signForm(*rrf);
           B.executeForm(*rrf);
           delete rrf;
       }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "\n------------------------------------------------\n\n";

    std::cout << "Test for Intern making Unknown Form\n" << std::endl; 
    try
    {
       Intern someRandomIntern;
       Bureaucrat B(1, "B");
       std::cout << "Supposed to print an error : ";
       AForm* rrf = someRandomIntern.makeForm("some random form", "Target");
       
       if (rrf)
       {
           B.signForm(*rrf);
           B.executeForm(*rrf);
           delete rrf;
       }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}