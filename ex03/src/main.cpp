/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abignals <abignals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 18:58:16 by abignals          #+#    #+#             */
/*   Updated: 2026/04/15 15:26:56 by abignals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include <ctime>

int main(void)
{
    std::srand(std::time(NULL));

    std::cout << "Test for PresidentialPardonForm" << std::endl; 
    try
    {
       PresidentialPardonForm A;
       Bureaucrat B(150, "B");
       std::cout << "First test Bureaucrat too low grade, can't sign supposed to throw exception : ";
       B.signForm(A);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "Test with a non-signed Form" << std::endl;
    try
    {
       PresidentialPardonForm A;
       Bureaucrat B(1, "B");
       std::cout << "Can't execute because not signed, supposed to throw exception : ";
       B.executeForm(A);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
       PresidentialPardonForm A;
       Bureaucrat B(1, "B");
       std::cout << "Supposed to work : " << std::endl;
       B.signForm(A);
       B.executeForm(A);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    ///////////////////////////////////////////////////
    std::cout << std::endl;

    std::cout << "Test for RobotomyRequestForm" << std::endl; 
    try
    {
       RobotomyRequestForm A;
       Bureaucrat B(150, "B");
       std::cout << "First test Bureaucrat too low grade, can't sign supposed to throw exception : ";
       B.signForm(A);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "Test with a non-signed Form" << std::endl;
    try
    {
       RobotomyRequestForm A;
       Bureaucrat B(1, "B");
       std::cout << "Can't execute because not signed, supposed to throw exception : ";
       B.executeForm(A);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
       RobotomyRequestForm A;
       Bureaucrat B(1, "B");
       std::cout << "Supposed to work : " << std::endl;
       B.signForm(A);
       B.executeForm(A);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    ////////////////////////////////////////////
    std::cout << std::endl;

    std::cout << "Test for ShrubberyCreationForm" << std::endl; 
    try
    {
       ShrubberyCreationForm A;
       Bureaucrat B(150, "B");
       std::cout << "First test Bureaucrat too low grade, can't sign supposed to throw exception : ";
       B.signForm(A);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "Test with a non-signed Form" << std::endl;
    try
    {
       ShrubberyCreationForm A;
       Bureaucrat B(1, "B");
       std::cout << "Can't execute because not signed, supposed to throw exception : ";
       B.executeForm(A);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
       ShrubberyCreationForm A;
       Bureaucrat B(1, "B");
       std::cout << "Supposed to work : " << std::endl;
       B.signForm(A);
       B.executeForm(A);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}