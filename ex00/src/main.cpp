/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abignals <abignals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 18:58:16 by abignals          #+#    #+#             */
/*   Updated: 2026/04/10 20:10:51 by abignals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

int main(void)
{

    std::cout << "Test exception too low" << std::endl;
    try
    {
        Bureaucrat John(160, "John");
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;

    std::cout << "Test exception too high" << std::endl;
    try
    {
        Bureaucrat John(0, "John");
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    
    std::cout << std::endl;

    std::cout << "Test working Bureaucrats" << std::endl;
    try
    {
        Bureaucrat John(1, "John");
        Bureaucrat Johnny(150, "Johnny");

        std::cout << John << std::endl;
        std::cout << Johnny << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;

    std::cout << "Test increment and exception" << std::endl;
    try
    {
        Bureaucrat A(2, "A");
        std::cout << A << "(supposed to be 2)" << std::endl;
        A.incrementGrade();
        std::cout << A << "(supposed to be 1)" << std::endl;
        std::cout << "Supposed to throw exception : ";
        A.incrementGrade();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;

    std::cout << "Test decrement and exception" << std::endl;
    try
    {
        Bureaucrat B(149, "B");
        std::cout << B << "(supposed to be 149)" << std::endl;
        B.decrementGrade();
        std::cout << B << "(supposed to be 150)" << std::endl;
        std::cout << "Supposed to throw exception : ";
        B.decrementGrade();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}