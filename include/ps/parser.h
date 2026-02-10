/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 03:47:46 by kiroussa          #+#    #+#             */
/*   Updated: 2023/11/22 01:55:25 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <ps/stack.h>

# include <ft/string/parse.h>
# include <ft/string.h>

t_stack	*ps_parse_stack(int argc, char **argv);

#endif // PARSER_H
