/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 03:32:38 by vgladush          #+#    #+#             */
/*   Updated: 2018/08/15 14:52:31 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : Form(target, 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &cpy) : Form(cpy) {}

void	ShrubberyCreationForm::operator=(ShrubberyCreationForm const &cpy) {
	Form::operator=(cpy);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void	ShrubberyCreationForm::execute(Bureaucrat const & bur) const {
	if (!this->getSigned())
		throw Form::FormNotSignedException();
	else if (this->getGradeExecute() < bur.getGrade())
		throw Form::GradeTooHighException();
  std::string filenm = this->getName() + "_shrubbery";
	std::ofstream fl(filenm.c_str());

	fl << std::endl << "                                             I" << std::endl <<
"                                       I   II III III I" << std::endl <<
"                                    I  III II III II  I" << std::endl <<
"                                   III IIIIII I IIII I     I" << std::endl <<
"                                 I  IIIIIIIII IIIIII I I  II" << std::endl <<
"                                I I II IIIIIIIAIIIAI I    II" << std::endl <<
"                          I I   I   III IIIIAAIIIIAI I  IIII" << std::endl <<
"                           II  III  IIAIIIIIAII AIAIIIIIIII   II" << std::endl <<
"                             II III  IAIIIIIAII AAIII II  I   II I" << std::endl <<
"                             IIIIIII IIAIIIAAIIIAAIII  I  I  IIIII  I" << std::endl <<
"                            IIIIIIIIIIIAIIAAAIIIIAIII IAIII IIIIIIII" << std::endl <<
"                         I   IIAAAIIIIAAAIAAAAIAIAIIIIIAIIIAIIAAI" << std::endl <<
"                I           IIIIAAAIIIIAAAAAAAIAIAIAI IIIIAAIII I I" << std::endl <<
"                 II     III  IIIIIIAAI AAIAAXAAAAIAAIIAAIAAIIIIII I   IIII" << std::endl <<
"                 IAI   IIIIIIIIIIIAAAAAIAIXIXAAXAIAXAAIIAAAIIAII IIIIIII" << std::endl <<
"                  IAII   III IIIIAIAIAAAAAXAXAAXAIAAAIAAAAIIIAIIIIIIIIII" << std::endl <<
"                   IIIII   IIAIIIIIIIAAXAAAXAAXXXAIXAIAXIAAAIAIIA  I II     I" << std::endl <<
"                    IIAIIIAIIIIAAAIIIAAAAAXAXXXXAAXAAAAAAAIAIIIII III" << std::endl <<
"       I         I      IIIIIAAIAIIIAAAAAXXAXXXXAXAAXAXXIAAIAIIIIIIAII     IIII  IIII" << std::endl <<
"      II   II   IIIIIIIAAAAIAAAAAIIIAXXXXXXXXXXXAAAAAAAXAAAAAAAAAIIIAAAAAIIIIII" << std::endl <<
"       IIIIIIIIIIIIAAAAAAXAAAAIIIAIIIAXXXMXXXMXAAXXIAXXAXAAAAIII IIII      IIII I" << std::endl <<
"         IIIAAAAIIIIAIAA  AXAAXAIIIAAAIXAAMXMMMXXAAXXXXXXAAIIIIIAIIIIIIIIIIIIIII" << std::endl <<
"     II   IIAAAAAIII     IIAXXAXXAAIAAAAXIAMMMMXAAAXMMXAIIAAAI     IAIIIIIAII" << std::endl <<
"         IIIIIIAAAAAAAIIIIIIAAAIAAXMMXXXXXXMMMMMXXMMXAIAAAAAIII    IIAAAAIIII" << std::endl <<
"            IIIIIAXXAAAAIAIIIIIAAAIAXAAAXXXXMMMXXMMMAAAAAAAAAIAIIIIAAAIAIII" << std::endl <<
"        II         IAXAAXXXXAAAAAXXAAXAAIMMMMMXXMMMAIAAAAIAAXXAAAAAAI  II" << std::endl <<
"          IIIIIIIIIIIAAAXXXXXXXXAAXXXMXXXAMMMMMMMXXAAAXAAAAAXAAAAAIIIIIIIIIIIIIIIIIII" << std::endl <<
"IIIAIIIIIIIIAAAAAAXXXXXXXXXXXXXAXXAXAXXMXXMMMMMMXMXXXXAAAAAAAIIAIIAAAAAAAAAAIIIIII" << std::endl <<
"       IIIIIIIIAAAAAAAAAXAXAAAAXMMMXXAAMXIAMMMMMMMXMXXXXXXXXXXXAAAIIIIIIIIIIAIAII" << std::endl <<
"      II  I IIIAIIIIAIAAXAAAAXXXXXXXMXXXMMAMMMMXIAMXAXXXXXXXXXXXAAAAAAAAAIAAIIIIII I" << std::endl <<
"                    IIAAAAXXXXXXXAXXMMMMMXMMWWMMMXXXXXAAAAAAAAAXXXAAAAAII" << std::endl <<
"                 IIIAAAXXXXAAAXAXIAAIAXMMAAMWWMXAXXAXXXAXAAXXAXAXXXAIIIIIII    I  I" << std::endl <<
"        IIIIIIAAAAAAAAAAAI IAIAAA IIAXXAXMXMWMMIAAAAXXXXXAXAIAAAXAAAAAAAAIIIII" << std::endl <<
"       IIIIIIAAAIIIII IIIIIIAXAAIAAAAXXXAIMMMMXIAIXAXXXAAXXXXXAIIIAAAIAAIAIIIII    II" << std::endl <<
"         III I      IIIIIIIAXAAAAIIAAIIIAAAMMMAAAAAIIIAXXXMXXXXAIII  IIIII  IIIII" << std::endl <<
"                  II  IIIAAAAAAAIIAI   IIIMMMMXAIIAIIIIIAAXXXXXXXAAII  IIII" << std::endl <<
"                      IIAAAAAIIIIIII   IIIXMMMAIIAIIAIII IAAAAAXXAAAIAII" << std::endl <<
"                     IAAAIAAI   I      I  AMMMAIII IAI    IIIAAAAAAAAIIIIIII" << std::endl <<
"                    IIII   II            IIMMMIIIIIII     I   IAAAAAAAI I" << std::endl <<
"                             I             MMMI                 IIAAIIIIIIII" << std::endl <<
"                                           MMMI                   IIIIII    I" << std::endl <<
"                                           MMMI                         I   I" << std::endl <<
"                                           MMMA" << std::endl <<
"                                           MMMA" << std::endl <<
"                                           MMMX" << std::endl;
	fl.close();
}
