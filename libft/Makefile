SOURCES = ft_toupper.c ft_tolower.c ft_strrchr.c ft_strnstr.c ft_strncmp.c
SOURCES+= ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_memset.c ft_memmove.c
SOURCES+= ft_memcmp.c ft_memchr.c ft_isprint.c ft_isdigit.c ft_isascii.c
SOURCES+= ft_isalnum.c ft_calloc.c ft_bzero.c ft_isalpha.c ft_strlen.c
SOURCES+= ft_memcpy.c ft_strdup.c ft_substr.c ft_strtrim.c ft_strmapi.c
SOURCES+= ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c
SOURCES+= ft_putnbr_fd.c ft_strjoin.c ft_itoa.c ft_split.c ft_atoi.c
SOURCES+= ft_strcmp.c ft_split_free.c ft_atol.c ft_split_quotes.c

SOURCES_BONUS	=	ft_lstnew.c ft_lstadd_front.c ft_lstlast.c
SOURCES_BONUS	+=	ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c
SOURCES_BONUS	+=	ft_lstmap.c ft_lstsize.c

OBJECTS = $(SOURCES:.c=.o)
OBJECTS_BONUS	= 	$(SOURCES_BONUS:.c=.o)
NAME = libft.a

CC = gcc
AR = ar
RM = rm -f

CFLAGS = -Wall -Wextra -Werror -g
ARFLAGS = rcs

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJECTS)
			$(AR) $(ARFLAGS) $(NAME) $(OBJECTS)

bonus:			$(NAME) $(OBJECTS_BONUS)
				$(AR) $(ARFLAGS) $(NAME) $(OBJECTS_BONUS)

clean:
			$(RM) $(OBJECTS) $(OBJECTS_BONUS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus
