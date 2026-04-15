/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abignals <abignals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 16:00:10 by abignals          #+#    #+#             */
/*   Updated: 2026/04/15 15:04:15 by abignals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class AForm;

class PresidentialPardonForm : public AForm
{
    private:
        std::string _target;
    
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const std::string& target);
        PresidentialPardonForm(const PresidentialPardonForm& src);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& src);
        ~PresidentialPardonForm();

        const std::string   getTarget() const;
        void                execute(Bureaucrat const& executor) const;
};

#endif //PRESIDENTIALPARDONFORM_HPP