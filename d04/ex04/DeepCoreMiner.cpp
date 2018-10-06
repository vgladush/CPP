/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DeepCoreMiner.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 23:12:56 by vgladush          #+#    #+#             */
/*   Updated: 2018/08/12 14:07:26 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DeepCoreMiner.hpp"

DeepCoreMiner::DeepCoreMiner() {}

DeepCoreMiner::DeepCoreMiner(DeepCoreMiner const & cpy) {
	(void)cpy;
}

DeepCoreMiner::~DeepCoreMiner() {}

void	DeepCoreMiner::operator=(DeepCoreMiner const & cpy) {
	(void)cpy;
}

void	DeepCoreMiner::mine(IAsteroid* ast) {
	std::cout << "* mining deep ... got " << ast->beMined(this) << " ! *" << std::endl;
}
