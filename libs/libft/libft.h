/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasferre <vasferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:36:13 by vasferre          #+#    #+#             */
/*   Updated: 2023/06/01 18:54:22 by vasferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdint.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

typedef struct s_list
{
	void				*content;
	struct s_list		*next;
}						t_list;

int		ft_isprint(int c);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
int		ft_isalpha(int b);
int		ft_isdigit(int b);
int		ft_isascii(int b);
int		ft_isalnum(int b);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t nitems, size_t size);
void	ft_bzero(void *ptr, size_t n);
int		ft_toupper(int c);
int		ft_tolower(int c);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
int		ft_memcmp(const void *str1, const void *str2, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *str, int c, size_t n);
char	*ft_strdup(const char *s);
int		ft_strlen(const char *str);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_strnstr(const char *s1, const char *s2, size_t n);
char	*ft_strrchr(const char *str, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	*ft_strchr(const char *str, int c);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
int		ft_lstsize(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
int		ft_format(va_list args, const char format);
int		ft_printf(const char *str, ...);
int		ft_hex_len(unsigned int num);
void	ft_put_hex(unsigned int num, const char format);
int		ft_prthex(unsigned int num, const char format);
int		ft_lenptr(uintptr_t num);
void	ft_putptr(uintptr_t ptr);
int		ft_print_ptr(unsigned long long ptr);
int		ft_prtchr(char c);
void	ft_putstr(char *str);
int		ft_prtstr(char *str);
int		ft_prtnum(int n);
int		ft_num_len(unsigned int num);
char	*ft_uitoa(unsigned int n);
int		ft_print_unsigned(unsigned int n);
//get_next_line
char	*get_next_line(int fd);
char	*ft_new_str(char *str);

#endif
