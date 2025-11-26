# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sevyesil <sevyesil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/26 00:00:00 by sevyesil          #+#    #+#              #
#    Updated: 2025/11/26 14:53:22 by sevyesil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c \
       parse_first_line.c \
       parse_map_body.c \
       map_parser.c \
       read_file.c \
       read_stdin.c \
       read_fd_to_buffer.c \
       append_buf.c \
       allocate_dp.c \
       init_dp_borders.c \
       fill_dp_table.c \
       find_max_square.c \
       print_map.c \
       get_line_len.c \
       is_printable.c \
       validate_chars.c \
       strict_atoi.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
