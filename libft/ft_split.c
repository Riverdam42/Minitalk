/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkawano <kkawano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 22:01:47 by kkawano           #+#    #+#             */
/*   Updated: 2021/08/15 00:29:23 by kkawano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_free(char **block_p)
{
	size_t	i;

	i = 0;
	while (block_p[i])
	{
		free(block_p[i]);
		i++;
	}
	free(block_p);
	return (NULL);
}

static size_t	chunk_n(const char *s, char c)
{
	size_t	i;
	size_t	chunk;

	i = 0;
	chunk = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			if (s[i + 1] == c || s[i + 1] == '\0')
				chunk++;
		}
		i++;
	}
	return (chunk);
}

static char	*make_string(const char *s, size_t str_n, char c)
{
	size_t	i;
	size_t	j;
	char	*string;

	i = 0;
	j = 0;
	string = malloc(sizeof(char) * (str_n + 1));
	if (!string)
		return (NULL);
	while (s[i] == c)
		i++;
	str_n += i;
	while (i < str_n)
	{
		string[j] = s[i];
		j++;
		i++;
	}
	string[j] = '\0';
	return (string);
}

static size_t	str_count(const char *s, char c)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (s[i] == c)
		i++;
	while (s[i + len] != c && s[i + len])
	{
		len++;
	}
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**block_p;
	size_t	block_n;
	size_t	str_n;
	size_t	i;

	if (!s)
		return (NULL);
	block_n = chunk_n(s, c);
	block_p = (char **)malloc(sizeof(char *) * (block_n + 1));
	if (!block_p)
		return (NULL);
	i = 0;
	while (i < block_n)
	{
		str_n = str_count(s, c);
		block_p[i] = make_string(s, str_n, c);
		if (!block_p[i])
			ft_free(block_p);
		while (*s == c)
			s++;
		s += str_n;
		i++;
	}
	block_p[block_n] = NULL;
	return (block_p);
}

// static void		*ft_free(char **block)
// {
//     size_t    i;

//     i = 0;
//     while (block[i])
//     {
//         free(block[i]);
//         i++;
//     }
//     free(block);
//     return (NULL);
// }

// static char	*make_string(const char *s, int i, int str_n)
// {
// 	size_t		i;
// 	char	*string;

// 	i = 0;
// 	string = malloc(sizeof(char) * (str_n + 1));
// 	if (!string)
// 		return (NULL);
// 	while (str_n > 0)
// 	{
// 		string[i] = s[i - str_n];
// 		i++;
// 		str_n--;
// 	}
// 	string[i] = '\0';
// 	return (string);
// }

// static char	**chase_letter(const char *s, char **block_p, char c)
// {
// 	size_t		i;
// 	int		str_n;
// 	int		follow;
// 	char	*str;

// 	i = 0;
// 	str_n = 0;
// 	follow = 0;
// 	while (s[i])
// 	{
// 		if (s[i] != c)
// 			str_n++;
// 		if ((s[i] == c || s[i + 1] == '\0') && str_n != 0)
// 		{
// 		if (s[i] != c && s[i + 1] == '\0')
// 				i++;
// 			str = make_string(s, i, str_n);
// 			if (str == NULL)
// 			{
// 				ft_free(block_p);
// 				return (NULL);
// 			}
// 			block_p[follow++] = str;
// 			str_n = 0;
// 		}
// 		i++;
// 	}
// 	return (block_p);
// }

// char 	**ft_split(char const *s, char c)
// {
// 	int		block_n;
// 	char	**result;
// 	char	**block_p;
// 	size_t		i;

// 	if (!s)
// 		return (NULL);
// 	block_n = 0;
// 	i = 0;
// 	while (s[i])
// 	{
// 		if (s[i] != c)
// 		{
// 			if (s[i + 1] == c || s[i + 1] == '\0')
// 				block_n++;
// 		}
// 		i++;
// 	}
// 	block_p = (char **)malloc(sizeof(char *) * (block_n + 1));
// 	if (!block_p)
// 		return (NULL);
// 	result = chase_letter(s, block_p, c);
// 	if (result == NULL)
// 		return (ft_free(block_p));
// 	result[block_n] = NULL;
// 	return (result);
// }

// #include <stdio.h>

// int		main(void)
// {
// 	char **tab;
// 	tab = ft_split("kawano   kosuke 42 Tokyo", ' ');
// 	printf("----result-----\n");

// 	int i;
// 	i = 0;
// 	while (tab[i])
// 	{
// 		printf("%s\n", tab[i]);
// 		i++;
// 	}
// 	//system("leaks a.out");
// 	return (0);
// }

// int		main(void)
// {
// 	char **split_str;
// 	//char const *s = "  tripouille  42  ";
// 	//char c = ' ';
// 	int i;

// 	//split_str = ft_split(s, c);
// 	split_str = ft_split("--1-2--3---4----5-----42", '-');
// 	//printf("s = roppongi  42tokyo japan\n");
// 	printf("---result---\n");
// 	i = 0;
// 	while (split_str[i])
// 	{
// 		printf("%s\n", split_str[i]);
// 		i++;
// 	}
// 	return (0);
// }
