/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abignals <abignals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 16:00:10 by abignals          #+#    #+#             */
/*   Updated: 2026/04/15 15:06:28 by abignals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class AForm;

class ShrubberyCreationForm : public AForm
{
    private:
        std::string _target;
    
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string& target);
        ShrubberyCreationForm(const ShrubberyCreationForm& src);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& src);
        ~ShrubberyCreationForm();

        const std::string   getTarget() const;
        void                execute(Bureaucrat const& executor) const;

        class ErrorCreatingFileException : public std::exception
        {
            const char* what() const throw()
            {
                return ("Failed to create out file");
            }    
        };
};

#endif //SHRUBBERYCREATIONFORM_HPP