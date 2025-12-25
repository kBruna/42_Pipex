# Libft

## 42's Common Core Libft

### ------------- Basic Functions List #<ctype.h> -----------------

- [x] `ft_atoi` - [Test OK](#ft_atoi)

	`int	ft_atoi(const char *nptr);`

Converts the initial portion of the string pointed to by nptr to int.

Return value: Converted Value or 0 on error.



- [x] `ft_bzero` - [Test OK](#ft_bzero)

	`void	ft_bzero(void *s, size_t n);`

Erases the data in the n bytes of the memory starting at the location pointed to by s, by writing zeros (bytes containing '\0') to that area.

Return value: None.



- [x] `ft_isalnum` - [Test OK](#ft_isalnum)

	`int	ft_isalnum(int c);`

Checks for an alphabetic character; it is equivalent to (isalpha(c) || isdigit(c)).



- [x] `ft_isalpha` - [Test OK](#ft_isalpha)

	`int	ft_isalpha(int c);`

Checks for an alphabetic character; in the standard "C" locale, it is equivalent to (isupper || islower(c)).



- [x] `ft_isascii` - [Test OK](#ft_isascii)

	`int	ft_isascii(int c);`

Checks whether c is a 7-bit unsigned char value that fits into the ASCII character set.



- [x] `ft_isdigit` - [Test OK](#ft_isdigit))

	`int	ft_isdigit(int c);`

Checks for a digit (0 through 9).



- [x] `ft_isprint` - [Test OK](#ft_isprint)

	`int	ft_isprint(int c);`
	
Checks for any printable character except space.



- [x] `ft_memcpy` - [Test OK](#ft_memcpy)

	`void	*ft_memcpy(void *dest, const void *src, size_t n);`

Function copies n bytes from memory area src to memory area dest. The memory areas must not overlap. Use memmove if the memory areas do overlap.

Return value: Pointer to dest.



- [x] `ft_memchr` - [Test OK](#ft_memchr)

	`void	*ft_memchr(const void *s, int c, size_t n);`

The function scans the initial n bytes of the memory area pointed to by s for the first instance of c. Both c and the bytes of the memory area pointed to by s are interpreted as unsigned char.

Return value: Pointer to matching type to the matching byte or NULL of the character does not occur in the given memory area.



- [x] `ft_memcmp` - [Test OK](#ft_memcmp)

	`int	ft_memcmp(const void *s1, const void *s2, size_t n);`

Function compares the first n bytes (each interpreted as unsigned char) of the memory areas s1 and s2.

Return value: Function returns an integer less than, equal to, or than greater zero if the first n bytes of s1 is found, respectively, to be less than, to match, or be greater than the first n bytes of s2. For a non-zero return value, the sign is determined by the sign of the difference between the first pair of bytes (interpreted as unsigned char) that differ is s1 and s2. If n is zero, the return value is zero.



- [x] `ft_memmove` - [Test OK](#ft_memmove)

	`void	ft_memmove(void *dest, const void *src, size_t n);`

Function copies n bytes from memory area src to memory area dest. The memory areas may overlap: copying takes place as though the bytes in src are first copied into a temporary array that does not overlap src or dest, and the bytes are then copied from the temporary array to dest.

Return value: Function returns a pointer to dest.



- [x] `ft_memset` - [Test OK](#ft_memset)

	`void	ft_memset(void *s, int c, size_t n);`

Function fills the first n bytes of the memory area pointed to by s, with the constant byte c.

Return value: Function returns a pointer to memory area s.



- [x] `ft_strlen` - [Test OK](#ft_strlen)

	`size_t	ft_strlen(const char *s);`

Function calculates the lenght of the string pointed to by s, excluding the terminating null byte ('\0').

Return value: Function returns the number of bytes in the string pointed to by s.



- [x] `ft_strlcpy` - [Test OK](#ft_strlcpy)

	`size_t	ft_strlcpy(char *dst, const char *src, size_t size);`
	
Function copy strings up to size - 1 characters from the NUL-terminated string src to dst. Guarantee to NUL-terminate the result (as long as size is larger than 0). Note that a byte for the NUL should be included in size. Only operate on true "C" strings. That means that src must be NUL-terminated.

Return value: The length of src (size_t).



- [x] `ft_strlcat` - [Test OK](#ft_strlcat)

	`size_t	ft_strlcat(char *dst, const char *src, size_t size);`

Function appends the NUL-terminated string src to the end of dst. Will append at most size - strlen(dst) - 1 bytes. Guarantee to NUL-terminate the result (as long as size is larger than 0 and as long as there is at least one byte free is dst). Note that a byte for the NUL should be included in size. Only operates on true "C" strings. That means that both src and dst must be NUL-terminated.

Return values: For sucessful concatenation: size_t src + dst.



- [x] `ft_strchr` - [Test OK](#ft_strchr)

	`char	*ft_strchr(const char *s, int c);`

Function returns a pointer to the first occurrence of the character c in the string s.
Return value: Pointer to the matched character or NULL if the character is not found. The terminating null byte is considered part of the string, so that if c is specified as '\0', these functions return a pointer to the terminator.



- [x] `ft_strncmp` - [Test OK](#ft_strncmp)

	`int	ft_strncmp(const char *s1, const char *s2, size_t n);`

Function compares the first (at most) n bytes of s1 and s2. The locale is not taken into account. The comparison is done using unsigned characters.

Return value: Function return an integer less than, equal to, or greater than zero if s1 (or the first n bytes thereof) is found, respectively, to be less than, to match, or be greater than s2.



- [x] `ft_strnstr` - [Test OK](#ft_strnstr)

	`char	*ft_strnstr(const char *big, const char *little, size_t len);`
	
Function locates the first occurrence of the null-terminated string little in the string big, where not more than len characters are searched. Characters that appear after a '\0' character are not searched.

Return value: If little is an empty string, big is returned; if little occurs nowhere in big, NULL is returned; otherwise a pointer to the first character of the first occurrence of little is returned.



- [x] `ft_strrchr` - [Test OK](#ft_strrchr)

	`char	*ft_strrchr(const char *s, int c);`
	
Function returns a pointer to the last occurrence of the caracter c in the string s.
Return Values: Pointer to the matched character or NULL if the character is not found. The terminating null byte is considered part of the string, so that if c is specified as '\0', these functions return a pointer to the terminator.



- [x] `ft_tolower` - [Test OK](#ft_tolower)

	`int	ft_tolower(int c);`
	
If c is an uppercase letter, returns its lowercase equivalent, if a lowercase representation exists in the current locale. Otherwise returns c.



- [x] `ft_toupper` - [Test OK](#ft_toupper)

	`int	ft_toupper(int c);`

If c is an lowercase letter, returns its uppercase equivalent, if a uppercase representation exists in the current locale. Otherwise returns c.



##### with malloc()

 - [x] `ft_calloc` - [Test OK](#ft_calloc)

	`void	*ft_calloc(size_t nmemb, size_t size);`

- If (nmemb || size) = 0; return (\*unique) -> free()



 - [x] `ft_strdup` - [Test OK](#ft_strdup)

	`char	*ft_strdup(const char *s)

	`char	ft_strdub(const char *s);`

- strlcpy, strlcat, bzero -> #include <bsd/string.h> -> cc -lbsd



### --------------- Extra Functions ------------


- [x] `ft_itoa` - [Test OK](#ft_itoa)

	`char	*ft_itoa(int n);`


- [x] `ft_putchar_fd` - [Test OK](#ft_putchar_fd)

	`void	ft_putchar_fd(char c, int fd);`


- [x] `ft_putendl_fd` - [Test OK](#ft_putendl_fd)

	`void	ft_putendl_fd(char *s, int fd);`


- [x] `ft_putnbr_fd` - [Test OK](#ft_putnbr_fd)

	`void	ft_putnbr_fd(int n, int fd);`


- [x] `ft_putstr_fd` - [Test OK](#ft_putstr_fd))

	`void	ft_putstr_fd(char *s, int fd);`


- [x] `ft_split` - [Test OK](#ft_split)

	`char **ft_split(char const *s, char c);`


- [x] `ft_striteri` - [Test OK](#ft_striteri)

	`void	ft_striteri(char *s, void (*f)(unsigned int, char*));`


- [x] `ft_strjoin` - [Test OK](#ft_strjoin)

	`char	ft_strjoin(char const *s1, char const *s2);`


- [x] `ft_strmapi` - [Test OK](#ft_strmapi)

	`char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));`


- [x] `ft_strtrin` - [Test OK](#ft_strtrim)

	`char	*ft_strtrim(char const *s1, char const *set);`


- [x] `ft_substr` - [Test OK](#ft_substr)

	`char	*ft_substr(char const *s, insigned int start, size_t len);`


### ------------------ Bonus ---------------

	typedef struct	s_list
	{
		void		*content;
		struct s_list	*next;
	}		t_list;


- [x] `ft_lstnew` - [Test OK](#ft_lstnew)

	`t_list	*ft_lstnew(void *content);`


- [x] `ft_lstadd_front` - [Test OK](#ft_lstadd_front)

	`void	ft_lstadd_front(t_list **lst, t_list *new);`


- [x] `ft_lstsize` - [Test OK](#ft_lstsize)

	`int	ft_lstsize(t_list *lst);`


- [x] `ft_lstlast` - [Test OK](#ft_lstlast)

	`t_list	*ft_lstlast(t_list *lst);`


- [x] `ft_lstadd_back` - [Test OK](#ft_lstadd_back)

	`void	ft_lstadd_back(t_list **lst, t_list new);`


- [x] `ft_lstdelone` - [Test OK](#ft_lstdelone)

	`void	ft_delone(t_list *lst, void (*del)(void *));`


- [x] `ft_lstclear` - [Test OK](#ft_lstclear)

	`void	ft_lstclear(t_list **lst, void (*f)(void *));`


- [x] `ft_lstiter` - [Test OK](#ft_lstiter)

	`void	ft_lstiter(t_list *lst, void (*f)(void *));`


- [x] `ft_lstmap` - [Test OK](#ft_lstmap)

	`t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));`


## --------- Tests ----------

### ft_atoi

	int main(void)
	{
	    char    *str1 = "+42lyon1";
	    char    *str2 = "+1";
	    char    *str2 = "-1";
	
	    printf("Original function: \t%d\t%d\t%d\n", atoi(str1), 
	atoi(str2), atoi(str3));
	    printf("My function: \t\t%d\t%d\t%d\n", ft_atoi(str1), 
	ft_atoi(str2), ft_atoi(str3));
	    return (0);
	}

-------------------------

### ft_bzero

	#include <stdio.h>
	#include <string.h>
	#include <bsd/string.h>
	int     main(void)
	{
	        char    str_orig1[] = "ABCDEFGHIJKLMNOPQRSTUVXWYZ";
	        char    str_my1[] = "ABCDEFGHIJKLMNOPQRSTUVXWYZ";
	        char    str_my2[] = "Hello []$^&*()_+{}| World!";
	        char    str_orig2[] = "Hello []$^&*()_+{}| World!";
		int n = 5;
	
		ft_bzero(&str_my1[n], n);
		ft_bzero(&str_my2[n], n);
		bzero(&str_orig1[n], n);
		bzero(&str_orig2[n], n);
	    
		printf("\nOriginal Function:\n\tString 01: %.30s\n\t
		String 02: %.30s", str_orig1, str_orig2);
	
		printf("\n\nMy function:\n\tString 01: %.30s\n\t
		String 02: %.30s\n", str_my2,  str_my1);
    
		return (0)
	}
	    
--------------------------

### ft_calloc

	#include <stdio.h>
	#include <stdlib.h>
	int main(void)
	{
	    int str_size = 10;
	    char    *test1;
	    char    *test2;
	
	    test1 = (char *)calloc(str_size, sizeof(char));
	    test2 = (char *)ft_calloc(str_size, sizeof(char));
    
	    if (test1 != NULL)
	        printf("Calloc Allocated!\n");
	    else
	        printf("Calloc Failled!\n");
	    if (test2 != NULL)
	        printf("FT_Calloc Allocated!\n");
	    else
	        printf("Calloc Failled!\n");

	    free(test1);
	    free(test2);
	    return (0);
	}
	
-----------------------------

### ft_isnum

	#include <ctype.h>
	#include <stdio.h>
	int     main(void)
	{
		int     test = '0';
		int     test2 = '9';
		char    test3 = 'a';
		char    test4 = '=';
		char    test5 = '!';
		char    test6 = '#';

		printf("Teste 1 Valor [%d] :\n\tOriginal: %d", test, isalnum(test));
		printf("\n\tft_isdigit: %d\n\n", ft_isalnum(test));
	       
		printf("Teste 2 Valor [%d] :\n\tOriginal: %d", test2, isalnum(test2));
		printf("\n\tft_isdigit: %d\n\n", ft_isalnum(test2));
	       
		printf("Teste 3 Valor [%c] :\n\tOriginal: %d", test3, isalnum(test3));
		printf("\n\tft_isdigit: %d\n\n", ft_isalnum(test3));
	       
		printf("Teste 4 Valor [%c] :\n\tOriginal: %d", test4, isalnum(test4));
		printf("\n\tft_isdigit: %d\n\n", ft_isalnum(test4));
	       
		printf("Teste 5 Valor [%c] :\n\tOriginal: %d", test5, isalnum(test5));
		printf("\n\tft_isdigit: %d\n\n", ft_isalnum(test5));
	       
		printf("Teste 6 Valor [%c] :\n\tOriginal: %d", test6, isalnum(test6));
		printf("\n\tft_isdigit: %d\n\n", ft_isalnum(test6));

		return (0);
	}
	
-----------------------------

### ft_isalpha

	#include <ctype.h>
	#include <stdio.h>
	int main(void)
	{
	    char    test = '1';
	    char    test2 = 'a';
	    char    test3 = 'A';
	    char    test4 = 'b';
	    char    test5 = '!';
	    char    test6 = '$';
	    char    test7 = '^';

	    printf("Teste 1:\n\tOriginal 1: %d\n", isalpha(test));
	    printf("\tft_isalpha 1: %d\n\n", ft_isalpha(test));

	    printf("Teste 2:\n\tOriginal a: %d\n", isalpha(test2));
	    printf("\tft_isalpha a: %d\n\n", ft_isalpha(test2));
	    
	    printf("Teste 3:\n\tOriginal A: %d\n", isalpha(test3));
	    printf("\tft_isalpha A: %d\n\n", ft_isalpha(test3));
	    
	    printf("Teste 4:\n\tOriginal b: %d\n", isalpha(test4));
	    printf("\tft_isalpha b: %d\n\n", ft_isalpha(test4));
	    
	    printf("Teste 5:\n\tOriginal !: %d\n", isalpha(test5));
	    printf("\tft_isalpha !: %d\n\n", ft_isalpha(test5));
	    
	    printf("Teste 6:\n\tOriginal $: %d\n", isalpha(test6));
	    printf("\tft_isalpha $: %d\n\n", ft_isalpha(test6));
	    
	    printf("Teste 7:\n\tOriginal ^: %d\n", isalpha(test7));
	    printf("\tft_isalpha ^: %d\n\n", ft_isalpha(test7));

	    return (0);
	}

---------------------------------

### ft_isascii

	#include <ctype.h>
	#include <stdio.h>
	int     main(void)
	{
		char    test = ;
		char    test2 = 9;
		char    test3 = 'a';
		char    test4 = '=';
		char    test5 = '!';
		char    test6 = '#';

		printf("Teste 1 Valor [%d] :\n\tOriginal: %d", test, isascii(test));
		printf("\n\tft_isascii: %d\n\n", ft_isascii(test));
		printf("Teste 2 Valor [%d] :\n\tOriginal: %d", test2, isascii(test2));
		printf("\n\tft_isascii: %d\n\n", ft_isascii(test2));
		printf("Teste 3 Valor [%c] :\n\tOriginal: %d", test3, isascii(test3));
		printf("\n\tft_isascii: %d\n\n", ft_isascii(test3));
		printf("Teste 4 Valor [%c] :\n\tOriginal: %d", test4, isascii(test4));
		printf("\n\tft_isascii: %d\n\n", ft_isascii(test4));
		printf("Teste 5 Valor [%c] :\n\tOriginal: %d", test5, isascii(test5));
		printf("\n\tft_isascii: %d\n\n", ft_isascii(test5));
		printf("Teste 6 Valor [%c] :\n\tOriginal: %d", test6, isascii(test6));
		printf("\n\tft_isascii: %d\n\n", ft_isascii(test6));

		return (0);
	}

--------------------------------

### ft_isdigit

	#include <ctype.h>
	#include <stdio.h>
	int     main(void)
	{
		int     test = 0;
		int     test2 = 9;
		char    test3 = '1';
		int    test4 = '2';
		int    test5 = '5';
		char    test6 = '#';

		printf("Teste 1 Valor [%d] :\n\tOriginal: %d", test, isdigit(test));
		printf("\n\tft_isdigit: %d\n\n", ft_isdigit(test));
		printf("Teste 2 Valor [%d] :\n\tOriginal: %d", test2, isdigit(test2));
		printf("\n\tft_isdigit: %d\n\n", ft_isdigit(test2));
		printf("Teste 3 Valor [%c] :\n\tOriginal: %d", test3, isdigit(test3));
		printf("\n\tft_isdigit: %d\n\n", ft_isdigit(test3));
		printf("Teste 4 Valor [%d] :\n\tOriginal: %d", test4, isdigit(test4));
		printf("\n\tft_isdigit: %d\n\n", ft_isdigit(test4));
		printf("Teste 5 Valor [%d] :\n\tOriginal: %d", test5, isdigit(test5));
		printf("\n\tft_isdigit: %d\n\n", ft_isdigit(test5));
		printf("Teste 6 Valor [%c] :\n\tOriginal: %d", test6, isdigit(test6));
		printf("\n\tft_isdigit: %d\n\n", ft_isdigit(test6));

		return (0);
	}
	
------------------------------------

### ft_isprint

	#include <ctype.h>
	#include <stdio.h>
	int     main(void)
	{
		int     test = '0';
		int     test2 = '9';
		char    test3 = ' ';
		char    test4 = '\n';
		char    test5 = '!';
		char    test6 = '#';

		printf("Teste 1 Valor [%d] :\n\tOriginal: %d", test, isprint(test));
		printf("\n\tft_isprint: %d\n\n", ft_isprint(test));
		printf("Teste 2 Valor [%d] :\n\tOriginal: %d", test2, isprint(test2));
		printf("\n\tft_isprint: %d\n\n", ft_isprint(test2));
		printf("Teste 3 Valor [%c] :\n\tOriginal: %d", test3, isprint(test3));
		printf("\n\tft_isprint: %d\n\n", ft_isprint(test3));
		printf("Teste 4 Valor [%c] :\n\tOriginal: %d", test4, isprint(test4));
		printf("\n\tft_isprint: %d\n\n", ft_isprint(test4));
		printf("Teste 5 Valor [%c] :\n\tOriginal: %d", test5, isprint(test5));
		printf("\n\tft_isprint: %d\n\n", ft_isprint(test5));
		printf("Teste 6 Valor [%c] :\n\tOriginal: %d", test6, isprint(test6));
		printf("\n\tft_isprint: %d\n\n", ft_isprint(test6));

		return (0);
	}
	
-----------------------------------

### ft_itoa

	#include <stdio.h>
	int main(void)
	{
	    int in1 = 0;
	    int in2 = 987654321;
	    int in3 = -34567890;

	    printf("Return: %s\n", ft_itoa(in1));
	    printf("Return: %s\n", ft_itoa(in2));
	    printf("Return: %s\n", ft_itoa(in3));

	    return (0);
	}
	
--------------------------------

### ft_memcpy

	#include <stdio.h>
	#include <string.h>
	int     main(void)
	{
	    int    str_orig1[] = {1,2,3,4,5,6,7,8,9};
	    int    str_orig2[] = {10,11,12,13,14,0,15,16};

	    int    str_cp1_dest1[100];
	    int    str_cp1_dest2[100];
	    int    str_cp2_dest1[100];
	    int    str_cp2_dest2[100];

	    int size_len1 = 9;
	    int size_len2 = 8;

	    memcpy(&str_cp1_dest1, &str_orig1, sizeof(int) * 3);
	    memcpy(&str_cp1_dest2, &str_orig2, sizeof(int) * 4);
	    ft_memcpy(&str_cp2_dest1, &str_orig1, sizeof(int) * 3);
	    ft_memcpy(&str_cp2_dest2, &str_orig2, sizeof(int) * 4);

	    printf("\nOriginal String:\n\tString 01:\n");
	    for (int i = 0; i < size_len1; i++)
		printf("str[%d] = %d\n", i, str_orig1[i]);
	    printf("\n\tString 02:\n");
	    for (int i = 0; i < size_len2; i++)
		printf("str[%d] = %d\n", i, str_orig2[i]);
	    printf("\nOriginal Function:\n\tString 01:\n");
	    for (int i = 0; i < size_len1; i++)
		printf("str[%d] = %d\n", i, str_cp1_dest1[i]);
	    printf("\n\tString 02:\n");
	    for (int i = 0; i < size_len2; i++)
		printf("str[%d] = %d\n", i, str_cp1_dest2[i]);
	    printf("\nMy_Function:\n\tString 01:\n");
	    for (int i = 0; i < size_len1; i++)
		printf("str[%d] = %d\n", i, str_cp2_dest1[i]);
	    printf("\n\tString 02:\n");
	    for (int i = 0; i < size_len2; i++)
		printf("str[%d] = %d\n", i, str_cp2_dest2[i]);
	    return (0);
	}
	
-----------------------------------

### ft_memmove

	#include <stddef.h>
	#include <stdio.h>
	#include <string.h>
	#include <bsd/string.h>

	int     main(void)
	{
		char    str_orig1[] = "ABC";
		char    str_orig2[] = "Hello []$^&*()_+{}| World!";

		char    str_cp1_dest1[100];
		char    str_cp1_dest2[100];
		char    str_cp2_dest1[100];
		char    str_cp2_dest2[100];

		memmove(str_cp1_dest1, str_orig1, sizeof(char) * 3);
		memmove(&str_orig2[0], &str_orig2[6], sizeof(char) * 5);
		ft_memmove(str_cp2_dest1, str_orig1, sizeof(char) * 3);
		ft_memmove(&str_orig2[0], &str_orig2[6], sizeof(char) * 5);

		printf("\nOriginal Function:\n\tString 01: %s\n\tString 02: 
	%s\n", str_cp1_dest1, str_cp1_dest2);
		printf("\n\nMy function:\n\tString 01: %s\n\tString 02: 
	%s\n\n", str_cp2_dest1, str_cp2_dest2);
		return (0);
	}

-----------------------------------

### ft_memset

	#include <stdio.h>
	#include <string.h>
	int main(void)
	{
	    int n = 5;
	    char    c = 'a';
	    char    str1[] = "Test of the ft_memset function.";
	    char    str2[] = "Test of the ft_memset function.";
	    char    str3[] = "Test of the ft_memset function.";

	    ft_memset(str2, c, n);
	    memset(str3, c, n);
	    
	    printf("\nOriginal string:\n\t%s", str1);
	    printf("\nReturn original function: \n\t%s", str2);
	    printf("\nReturn my_funcion: \n\t%s\n", str3);

	    return (0);
	}

------------------------------------

### ft_split

	#include <stdio.h>
	int main(void)
	{
	    char    *str = "-----Hello-World!---alo";
	    char    **strstr;
	    char    z = '-';
	    size_t  ctrl = 0;

	    strstr = ft_split(str, z);
	    while(strstr[ctrl] != NULL)
	    {
		printf("string %ld: %s\n", ctrl, strstr[ctrl]);
		ctrl++;
	    }
	    ctrl = 0;
	    return (0);
	}

------------------------------------

### ft_strchr

	#include <stdio.h>
	#include <string.h>
	int main(void)
	{
	    char    *str = "Hello World!";
	    char    c = 'l';

	    printf("\nOriginal Function: \t%s", strchr(str, c + 256));
	    printf("\nMy function: \t\t%s\n", ft_strchr(str, c + 256));

	    return (0);
	}

------------------------------------

### ft_strdup

	#include <stdio.h>
	#include <bsd/string.h>
	int main(void)
	{
	    char    *str1 = "Hello World!";
	    char    *str2 = "";
	    char    *str3 = "Put a long string here";

	    char    *ptr_og1 = strdup(str1);
	    char    *ptr_og2 = strdup(str2);
	    char    *ptr_og3 = strdup(str3);
	    char    *ptr_ft1 = ft_strdup(str1);
	    char    *ptr_ft2 = ft_strdup(str2);
	    char    *ptr_ft3 = ft_strdup(str3);

	    printf("Original Function: str1 =  %s\n", ptr_og1);
	    printf("Original Function: str1 address = %p\n", (void *)&str1);
	    printf("Original Function: str1 copy address = %p\n\n", (void *)&ptr_og1);
	    printf("Original Function: str2 =  %s\n", ptr_og2);
	    printf("Original Function: str2 address =  %p\n", (void *)&str2);
	    printf("Original Function: str2 copy address =  %p\n\n", (void *)&ptr_og2);
	    printf("Original Function: str3 =  %s\n", ptr_og3);
	    printf("My function: str1 = \t%s\n", ptr_ft1);
	    printf("My function: str1 address = \t%p\n\n", (void *)ptr_ft1);
	    printf("My function: str2 = \t%s\n", ptr_ft2);
	    printf("My function: str2 address = \t%p\n\n", (void *)&ptr_ft2);
	    printf("My function: str3 = \t%s\n", ptr_ft3);

	    free(ptr_og1);
	    free(ptr_og2);
	    free(ptr_og3);
	    free(ptr_ft1);
	    free(ptr_ft2);
	    free(ptr_ft3);
	    return (0);
	}

-----------------------------------

### ft_striteri

	#include <stdio.h>
	void    test_func(unsigned int i, char *c) 
	{
	    *c += i;
	}

	int main(void)
	{
	    char    *str1 = "0000000000";
	    char    *str2 = "1111111111";

	    ft_striteri(str1, test_func);
	    ft_striteri(str2, test_func);

	    printf("STR 1 : %s", str1);
	    printf("STR 2 : %s", str2);
	    return (0);
	}

-------------------------------------

### ft_strjoin

	#include <stdio.h>
	int main(void)
	{
	    char    *str1 = "Helloo0o0o0o0";
	    char    *str2 = "-World!!!!!!!!!";
	    char    *str3;

	    str3 = ft_strjoin(str1, str2);
	    printf("Final String: %s\n", str3);
	    
	    return (0);
	}

-------------------------------------

### ft_strlcat

	#include <bsd/string.h>
	#include <stdio.h>
	int main(void)
	{
	    char    *org = "This-is-the-original string.";
	    char    dest1[50] = "Hello World!";
	    char    dest2[50] = "Hello World!";

	    int int_org = strlcat(dest1, org, 40);
	    int int_myft = ft_strlcat(dest2, org, 40);

	    printf("\nOriginal str: %s\n", org);
	    printf("\nStrlcat: %s\n\tReturn: %d\n", dest1, int_org);
	    printf("\nft_strlcat: %s\n\tReturn: %d\n", dest2, int_myft);

	    return (0);
	}

---------------------------------------

### ft_strlcpy

#include <stdio.h>
#include <string.h>
#include <bsd/string.h>
int ft_strlen(char *str);

int ft_strlen(char *str)
{
    int i;
    int len;

    while (str[i] != '\0')
    {
        len++;
        i++;
    }
    return (len);
}

int main(void)
{
    char    str_orig1[] = "ABC";
    char    str_orig2[] = "Hello []$^&*()_+{}| World!";

    char    str_cp1_dest1[100];
    char    str_cp1_dest2[100];
    char    str_cp2_dest1[100];
    char    str_cp2_dest2[100];

    unsigned int    orig_1 = strlcpy(str_cp1_dest1, str_orig1, 2);
    unsigned int    orig_2 = strlcpy(str_cp1_dest2, str_orig2, 10);
    unsigned int    myfunc_1 = ft_strlcpy(str_cp2_dest1, str_orig1, 2);
    unsigned int    myfunc_2 = ft_strlcpy(str_cp2_dest2, str_orig2, 10);

    printf("\nOriginal Function:\n\tString 01: %s\t\tReturn : %d 
\n\tString 02: %s\t\tReturn : %d", str_cp1_dest1, orig_1, str_cp1_dest2, orig_2);
    printf("\n\nMy function:\n\tString 01: %s \t\tReturn : %d\n\tString 02: 
%s\t\tReturn : %d\n", str_cp2_dest1, myfunc_1, str_cp2_dest2, myfunc_2);
    return (0);
}

-------------------------------------------

### ft_strlen

	#include <stdlib.h>
	#include <stdio.h>
	int main(int argc, char **argv)
	{
	    if (argc > 0)
	    {
		printf("Strlen = %d", ft_strlen(argv[1]));
	    }
	    return (0);
	}

-------------------------------------------

### ft_strmapi

	#include <stdio.h>
	char    test_func(unsigned int i, char c) 
	{
	    if (i % 2 == 0 && c >= 'a' && c <= 'z')
		return c - 32;  // uppercase for even indexes
	    return c;           // leave other characters unchanged
	}


	int main(void)
	{
	    char    *str1 = "this is a lowercase string";
	    char    *str2 = "THIS IS A UPPERCASE STRING!";

	    printf("STR 1 : %s", ft_strmapi(str1, test_func));
	    printf("STR 2 : %s", ft_strmapi(str2, test_func));
	    return (0);
	}

---------------------------------------------

### ft_strncmp

	#include <stdio.h>
	#include <string.h>
	int main(void)
	{
	    char    *str1 = "Hello World!";
	    char    *str2 = "Hello Wor1ld!";
	    int index = 50;

	    printf("Original Function: \t%d\n", strncmp(str1, str2, index));
	    printf("\n\tMy Function: \t%d\n", ft_strncmp(str1, str2, index));

	    return (0);
	}

---------------------------------------------

### ft_strnstr

	#include <stdio.h>
	#include <bsd/string.h>

	int main(void)
	{
	    char    *org = "";
	    char    *find = "";
	    int n = 7;

	    printf("Original function: \t%s\n", strnstr(org, find, n));
	    printf("\tMy Function: \t%s\n", ft_strnstr(org, find, n));

	    return (0);
	}

---------------------------------------------

### ft_strrchr

#include <stdio.h>
#include <string.h>
int main(void)
{
    char  *str = "Hello World!";
   char  c = 'l';

   printf("\nOriginal Function: \t%s", strrchr(str, c + 256));
   printf("\nMy function: \t\t%s\n", ft_strrchr(str, c + 256));

   return (0);
}

---------------------------------------------

### ft_substr

	#include <stdio.h>
	int main(void)
	{
	    char    *str1 = "This is a test string!";
	    char    *str2 = "Hello World!";
	    char    *ret1;
	    char    *ret2;
	    char    *ret3;
	    char    *ret4;
	    char    *ret5;
	    char    *ret6;
	    char    *ret7;

	    ret1 = ft_substr(str1, 10, 12);
	    ret2 = ft_substr(str2, 0, 12);
	    ret3 = ft_substr(str1, -1, 5);
	    ret4 = ft_substr(str2, 0, 0);
	    ret5 = ft_substr("", 0, 5);
	    ret6 = ft_substr(str1, 24, 1);
	    ret7 = ft_substr(str1, 0, -1);

	    printf("ft_substr: ");
	    printf("1 %s |", (ret1[0] == '\0') ? "KO" : ret1);
	    printf("2 %s |", (ret2[0] == '\0') ? "KO" : ret2);
	    printf("3 %s |", (ret3 == NULL) ? "OK" : ret3);
	    printf("4 %s |", (ret4 == NULL) ? "OK" : ret4);
	    printf("5 %s |", (ret5 == NULL) ? "OK" : ret5);
	    printf("6 %s |", (ret6 == NULL) ? "OK" : ret6);
	    printf("7 %s", (ret7 == NULL) ? "OK" : ret7);
	    printf("\n");

	    free(ret1);
	    free(ret2);
	    free(ret3);
	    free(ret4);
	    free(ret5);
	    free(ret6);
	    free(ret7);
	    return (0);
	}

----------------------------------------------

	#include <ctype.h>
	#include <stdio.h>
	int     main(void)
	{
		char    test1 = '0';
		char    test2 = '9';
		char    test3 = 'a';
		char    test4 = 'A';
		char    test5 = '!';
		char    test6 = '#';

		char    *test[6] = { &test1, &test2, &test3, &test4, &test5, &test6 };

		int     var_origin1;
		int     var_origin2;
		int     var_origin3;
		int     var_origin4;
		int     var_origin5;
		int     var_origin6;

		int     *var_origin[6] = { &var_origin1, &var_origin2, &var_origin3,
		&var_origin4, &var_origin5, &var_origin6 };

		int     var_my_function1;
		int     var_my_function2;
		int     var_my_function3;
		int     var_my_function4;
		int     var_my_function5;
		int     var_my_function6;

		int     *var_my_func[6] = { &var_my_function1, &var_my_function2, 
	    &var_my_function3, &var_my_function4, &var_my_function5, &var_my_function6 };
		for (int i = 0; i <= 5; i++)
		{
		        *(var_origin[i]) = tolower(*(test[i]));
		        *(var_my_func[i]) = ft_tolower(*(test[i]));
		}

		printf("Teste 1 Valor [%c] :\n\tOriginal: %c", test1, var_origin1);
		printf("\n\tft_my_function: %c\n\n", var_my_function1);
		printf("Teste 2 Valor [%c] :\n\tOriginal: %c", test2, var_origin2);
		printf("\n\tft_my_function: %c\n\n", var_my_function2);
		printf("Teste 3 Valor [%c] :\n\tOriginal: %c", test3, var_origin3);
		printf("\n\tft_my_function: %c\n\n", var_my_function3);
		printf("Teste 4 Valor [%c] :\n\tOriginal: %c", test4, var_origin4);
		printf("\n\tft_my_function: %c\n\n", var_my_function4);
		printf("Teste 5 Valor [%c] :\n\tOriginal: %c", test5, var_origin5);
		printf("\n\tft_my_function: %c\n\n", var_my_function5);
		printf("Teste 6 Valor [%c] :\n\tOriginal: %c", test6, var_origin6);
		printf("\n\tft_my_function: %c\n\n", var_my_function6);

		return (0);
	}

------------------------------------------

	#include <ctype.h>
	#include <stdio.h>
	int     main(void)
	{
		char    test1 = '0';
		char    test2 = '9';
		char    test3 = 'a';
		char    test4 = '=';
		char    test5 = '!';
		char    test6 = '#';

	    char    *test[6] = { &test1, &test2, &test3, &test4, &test5, &test6 };

		int var_origin1;
		int var_origin2;
		int var_origin3;
		int var_origin4;
		int var_origin5;
		int var_origin6;

	    int *var_origin[6] = { &var_origin1, &var_origin2, &var_origin3, 
	    &var_origin4, &var_origin5, &var_origin6 };
	    
		int var_my_function1;
		int var_my_function2;
		int var_my_function3;
		int var_my_function4;
		int var_my_function5;
		int var_my_function6;

	    int *var_my_func[6] = { &var_my_function1, &var_my_function2, 
	    &var_my_function3, &var_my_function4, &var_my_function5, &var_my_function6 };

	    for (int i = 0; i <= 5; i++)
	    {
		*(var_origin[i]) = toupper(*(test[i]));
		*(var_my_func[i]) = ft_toupper(*(test[i]));
	    }

	    printf("Teste 1 Valor [%c] :\n\tOriginal: %c", test1, var_origin1);
		printf("\n\tft_my_function: %c\n\n", var_my_function1);
		printf("Teste 2 Valor [%c] :\n\tOriginal: %c", test2, var_origin2);
		printf("\n\tft_my_function: %c\n\n", var_my_function2);
		printf("Teste 3 Valor [%c] :\n\tOriginal: %c", test3, var_origin3);
		printf("\n\tft_my_function: %c\n\n", var_my_function3);
		printf("Teste 4 Valor [%c] :\n\tOriginal: %c", test4, var_origin4);
		printf("\n\tft_my_function: %c\n\n", var_my_function4);
		printf("Teste 5 Valor [%c] :\n\tOriginal: %c", test5, var_origin5);
		printf("\n\tft_my_function: %c\n\n", var_my_function5);
		printf("Teste 6 Valor [%c] :\n\tOriginal: %c", test6, var_origin6);
		printf("\n\tft_my_function: %c\n\n", var_my_function6);

		return (0);
	}

----------------------------------


