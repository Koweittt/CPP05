/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abignals <abignals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 18:58:16 by abignals          #+#    #+#             */
/*   Updated: 2026/04/13 18:47:25 by abignals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

int main(void)
{
    std::cout << "Test Form with a too high grade" << std::endl;
    try
    {
        Form A("TooHigh", 0, 0);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl;

    std::cout << "Test Form with a too low grade" << std::endl;
    try
    {
        Form A("TooLow", 151, 150);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    std::cout << std::endl;

    std::cout << "Test with a bureaucrat too low grade to sign" << std::endl;
    try
    {
        Form A("TooLow", 1, 1);
        Bureaucrat B(2, "Bureaucrat");

        B.signForm(A);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    std::cout << std::endl;

    std::cout << "Test to sign a form already signed" << std::endl;
    try
    {
        Form A("TooLow", 1, 1);
        Bureaucrat B(1, "Bureaucrat");

        B.signForm(A);
        B.signForm(A);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl;
    
    std::cout << "Test to sign a form" << std::endl;
    try
    {
        Form A("TooLow", 1, 1);
        Bureaucrat B(1, "Bureaucrat");

        B.signForm(A);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}