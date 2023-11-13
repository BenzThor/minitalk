/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:30:19 by tbenz             #+#    #+#             */
/*   Updated: 2023/11/13 12:57:51 by tbenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

// include libraries
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdarg.h>

// define default BUFFER_SIZE for get_next_line if not defined dur. compilation
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

/*		a struct that links to another struct resulting in a linked list	*/
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/*		determine if a char is...		*/

/* determines if a character is a printable (ASCII 32 - 126)
	Return values:
	1: printable;		0: not printable*/
int		ft_isprint(int c);
/* determines if a character is a digit (ASCII 48 - 57)
	Return values:
	1: digit;		0: not a digit*/
int		ft_isdigit(int c);
/* determines if a character is an ASCII character (ASCII 0 - 127)
	Return values:
	1: ASCII;		0: not ASCII*/
int		ft_isascii(int c);
/* determines if a character is part of alphabet (ASCII 65 - 90 and 97 - 122)
	Return values:
	1: alphabet character;		0: not an alphabet character*/
int		ft_isalpha(int c);
/* determines if a character is alphanumberic (see ft_isalpha and ft_isdigit)
	Return values:
	1: alphanumeric;		0: not alphanumeric*/
int		ft_isalnum(int c);

/*		convert char to upper-/lowercase		*/

// converts a lowercase character to upperc. and returns the character as an int
int		ft_toupper(int c);
// converts an upperc. character to lowerc. and returns the character as an int
int		ft_tolower(int c);

/*		string manipulation		*/


size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strdup(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

/*		put functions		*/

void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
char	*ft_itoa(int n);
int		ft_atoi(const char *nptr);

/*		memory manipulation 	*/

void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);

/*		list functions 	*/

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));

/*		get_next_line functions		*/

typedef struct s_list1
{
	char			*str_buf;
	struct s_list1	*next;
}	t_list1;

t_list1	*ft_lstlast_gnl(t_list1 *lst);
void	copy_str(t_list1 *list, char *str);
void	ft_add_elem(t_list1 **lst, char *buf, int fd);
char	*get_next_line(int fd);
int		ft_lst_strlen(t_list1 *lst);
int		ft_check(t_list1 *list);

/*		printf functions		*/

void	ft_check_prntf(char s, int *len, va_list *args);
void	ft_putchar(int c, int *len);
void	ft_putstr(char *s, int *len);
void	ft_putptr(void *ptr, int *len);
void	ft_putnbr(int n, int *len);
void	ft_putuns(unsigned int n, int *len);
void	ft_puthex(char s, unsigned int nbr, int *len);
int		ft_printf(const char *s, ...);

#endif
