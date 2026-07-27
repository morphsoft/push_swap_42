/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvaini-d <hvaini-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 20:27:06 by joaopedr          #+#    #+#             */
/*   Updated: 2026/06/23 16:14:42 by hvaini-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_buffer
{
	int				fd;
	char			*content;
	struct s_buffer	*next;
}					t_buffer;

typedef struct s_fmt
{
	int		minus;
	int		zero;
	int		hash;
	int		plus;
	int		space;
	int		width;
	int		precision;
	int		has_precision;
	char	conv;
}					t_fmt;

typedef struct s_nfmt
{
	int	len;
	int	zpad;
	int	sign;
	int	prefix;
	int	pad;
}					t_nfmt;

int			ft_isalpha(int argument);
int			ft_isdigit(int argument);
int			ft_isalnum(int argument);
int			ft_isascii(int argument);
void		*ft_memset(void *pointer, int value, size_t count);
void		ft_bzero(void *pointer, size_t count);
void		*ft_memcpy(void *destination, const void *source, size_t count);
void		*ft_memmove(void *destination, const void *source, size_t count);
size_t		ft_strlcpy(char *destination, const char *source, size_t size);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
size_t		ft_strlen(const char *argument);
int			ft_isprint(int argument);
size_t		ft_strlcat(char *destination, const char *source, size_t size);
int			ft_toupper(int argument);
int			ft_tolower(int argument);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
void		*ft_memchr(const void *pointer, int value, size_t count);
int			ft_memcmp(const void *pointer1, const void *pointer2, size_t count);
char		*ft_strnstr(const char *big, const char *little, size_t len);
int			ft_atoi(const char *str);
void		*ft_calloc(size_t count, size_t size);
char		*ft_strdup(const char *s1);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
char		*ft_gnl(int fd);
char		*ft_read_file(int fd, char *buffer);
char		*ft_extract_line(char *buffer);
char		*ft_update_buffer(char *buffer);
size_t		ft_strlen(const char *s);
char		*ft_strchr(const char *s, int c);
char		*ft_strjoin(char const *s1, char const *s2);
t_buffer	*ft_create_buffer(int fd, t_buffer *buffer_list);
void		ft_clear_gnl_buffer(t_buffer **buffer_list);
int			ft_printf(const char *format, ...);
int			ft_putptr(void *ptr);
int			ft_puthex(unsigned long number, char format);
int			ft_putunbr(unsigned int number);
int			ft_putnbr(int number);
int			ft_putstr(char *str);
int			ft_putchar(char c);
int			ft_sqrt(int nb);
int			pf_max(int a, int b);
int			pf_repeat(char c, int n);
int			pf_putnstr(const char *s, int n);
int			pf_u64_to_base(unsigned long long n, const char *base, char *buf);
void		pf_init_fmt(t_fmt *fmt);
void		pf_parse(const char **format, t_fmt *fmt);
int			pf_print_char(char c, t_fmt *fmt);
int			pf_print_string(char *s, t_fmt *fmt);
int			pf_print_pointer(void *ptr, t_fmt *fmt);
int			pf_print_signed(long value, t_fmt *fmt);
int			pf_print_unsigned(unsigned long long value, t_fmt *fmt, char conv);
int			pf_dispatch(t_fmt *fmt, va_list *args);

#endif
