/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 20:20:27 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/01/18 21:25:34 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# ifdef USE_MATH
#  include <math.h>
# endif
# include "structs.h"

# define PI		3.14159265358979323846

void		*ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);
void		*ft_memmove(void *dst, const void *src, size_t len);
char		*ft_strdup(const char *s);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memset(void *b, int c, size_t len);
void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int nb, int fd);
void		ft_putstr_fd(char *s, int fd);
char		*ft_strchr(const char *s, int c);
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlen(const char *s);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strrchr(const char *s, int c);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int			ft_tolower(int c);
int			ft_toupper(int c);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
int			ft_atoi(const char *str);
int			ft_atoi_hex(const char *str);
char		*ft_itoa(int n);
char		**ft_split(char const *s, char c);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstadd_front(t_list **lst, t_list *new);
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstnew(void *content);
int			ft_lstsize(t_list *lst);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/*Gets numbers of strings inside of string arrays.
String arrays must be null-ended.*/
size_t		ft_strarrlen(char **arr);
//Free all the arrays inside double array.
void		ft_free_str_arr(char **str_arr);
/*Hexadecimal version of atoi().
It works both of uppercase and lowercase versions.*/
int			ft_atoi_hex(const char *str);
//Degree to Radian conversions.
double		ft_deg_to_rad(double deg);
//Radian to Degree conversions.
double		ft_rad_to_deg(double rad);

//----------------------------- Mapping ----------------------------------

//Initializes map from given values to use inside map function.
t_map		ft_map_init(double min_i, double max_i, double min_o, double max_o);
/*Gives normalized value (0 to 1 range value)
of given value inside specified range.*/
double		ft_normalize(double val, double min, double max);
/*Gets normalized value (0 to 1 range value)
and gives the value corresponding on specified range.*/
double		ft_lerp(double val, double min, double max);
//This function uses t_map to convert value from one range to another.
double		ft_map(double val, t_map map);

t_vec2		ft_vec2_set(double x, double y);
t_vec2		ft_vec2_sub(t_vec2	vec1, t_vec2 vec2);
t_vec2		ft_vec2_add(t_vec2 vec1, t_vec2 vec2);
t_vec2		ft_vec2_mul(t_vec2 vec, double mul);
t_vec2		ft_vec2_div(t_vec2 vec, double div);

t_vec3		ft_vec3_set(double x, double y, double z);
t_vec3		ft_vec3_sub(t_vec3	vec1, t_vec3 vec2);
t_vec3		ft_vec3_add(t_vec3 vec1, t_vec3 vec2);
t_vec3		ft_vec3_mul(t_vec3 vec, double mul);
t_vec3		ft_vec3_div(t_vec3 vec, double div);

t_vec4		ft_vec4_set(double x, double y, double z, double w);
t_vec4		ft_vec4_add(t_vec4 vec1, t_vec4 vec2);
t_vec4		ft_vec4_sub(t_vec4 vec1, t_vec4 vec2);
t_vec4		ft_vec4_mul(t_vec4 vec, double mul);
t_vec4		ft_vec4_div(t_vec4 vec, double div);

t_vec2		ft_vec2_norm(t_vec2 vec);

double		ft_vec2_dot(t_vec2 vec1, t_vec2 vec2);
double		ft_get_dist2(t_vec2 point1, t_vec2 point);
double		ft_vec2_mag(t_vec2 vec);

t_vec3		ft_vec3_norm(t_vec3 vec);
t_vec3		ft_vec3_cross(t_vec3 vec1, t_vec3 vec2);

double		ft_vec3_dot(t_vec3 vec1, t_vec3 vec2);
double		ft_get_dist3(t_vec3 point1, t_vec3 point);
double		ft_vec3_mag(t_vec3 vec);

t_vec4		ft_vec4_norm(t_vec4 vec);

double		ft_vec4_dot(t_vec4 vec1, t_vec4 vec2);
double		ft_vec4_mag(t_vec4 vec);

//------------------------------ Basic Matrix Functions ---------------------

//3D matrix row setter.
void		ft_set_row3(t_mtx3 *mtx, int row_val, t_vec3 row);
//Get values in row of 3D matrix.
t_vec3		ft_get_row3(t_mtx3 mtx, int row_val);
//3D matrix 3D vector multiplication.
t_vec3		ft_mtx_vec_mul3(t_mtx3 mtx, t_vec3 vec);
//3D matrix 3D matrix multiplication.
t_mtx3		ft_mtx_mtx_mul3(t_mtx3 mtx1, t_mtx3 mtx2);

//4D matrix row setter.
void		ft_set_row4(t_mtx4 *mtx, int row_val, t_vec4 row);
//Get values in row of 4D matrix.
t_vec4		ft_get_row4(t_mtx4 mtx, int row_val);
//4D matrix 4D vector multiplication.
t_vec4		ft_mtx_vec_mul4(t_mtx4 mtx, t_vec4 vec);
//4D matrix 4D matrix multiplication.
t_mtx4		ft_mtx_mtx_mul4(t_mtx4 mtx1, t_mtx4 mtx2);

//3D vector to 4D vector conversion.
t_vec4		ft_vec3_to_vec4(t_vec3 vec3, double w);
//4D vector to 3D vector conversion.
t_vec3		ft_vec4_to_vec3(t_vec4 vec4);

//------------------------- Color Functions ---------------------------

/*4 channel int value color setter.
a = Alpha, r = Red, g = Green, b = Blue*/
t_color		ft_set_color(__uint8_t a, __uint8_t r, __uint8_t g, __uint8_t b);
//Returns gradient value from given normalized value.
t_color		ft_get_gradient_val(t_color from, t_color to, double value);
//Gradient initializer.
t_gradient	ft_set_gradient(t_color from, t_color to);
//Gradient inverter.
t_gradient	ft_inv_gradient(t_gradient in);

void		ft_put_pixel(t_img *img, int x, int y, t_color color);
void		ft_draw_line(t_data *dt, t_vec3 pt1, t_vec3 pt2, t_color color);
void		ft_draw_tri(t_data *data, t_tri *tris, int j, t_color color);
void		ft_fill_img(t_data *data, t_color color);

#endif