#include "libft.h"
#include "testft.h"
#include <time.h>
#include <string.h>

void	setUp(void)
{
}

void	tearDown(void)
{
}

// FT_MEMSET
#define BSIZE 20
void	test_ft_memset0(void)
{
	char	b1[BSIZE];
	char	b2[BSIZE];

	memset(b1, 'B', BSIZE);
	memset(b2, 'B', BSIZE);

	memset(b1, 'A', 10);
	ft_memset(b2, 'A', 10);

	TEST_ASSERT_EQUAL_MEMORY_MESSAGE(b1, b2, BSIZE, "basic memset test (fill a buffer with 'A')");
}

void	test_ft_memset1(void)
{
	char	b1[BSIZE];
	char	b2[BSIZE];

	memset(b1, 'B', BSIZE);
	memset(b2, 'B', BSIZE);

	memset(b1, '\200', 10);
	ft_memset(b2, '\200', 10);

	TEST_ASSERT_EQUAL_MEMORY_MESSAGE(b1, b2, BSIZE, "your memset does not cast the memory into unsigned chars");
}

void	test_ft_memset2(void)
{
	char	str[] = "This is a test.";
	char	*ret = ft_memset(str, 'B', 1);

	TEST_ASSERT_EQUAL_PTR_MESSAGE(str, ret, "Return value is incorrect.");
}

void	test_ft_memset3(void)
{
	char	b1[BSIZE];

	memset(b1, 'B', BSIZE);

	char	*r1 = memset(b1, 'A', 10);
	char	*r2 = ft_memset(b1, 'A', 10);

	TEST_ASSERT_EQUAL_MESSAGE(r1, r2, "either your memset return value is incorrect, or your memset does not work");
}

void	test_ft_memset4(void)
{
	char	*c1 = (char*)malloc(sizeof(char) * (BSIZE + 1));
	char	*c2 = (char*)malloc(sizeof(char) * (BSIZE + 1));

	*c1 = 0;
	*c2 = 0;
	memset(c1, '\5', BSIZE);
	ft_memset(c2, '\5', BSIZE);

	TEST_ASSERT_EQUAL_MEMORY_MESSAGE(c1, c2, BSIZE, "basic memset test: fill a buffer with 5(int)");
	free(c1);
	free(c2);
}
void	test_ft_memset5(void)
{
	char	b1[BSIZE];
	char	b2[BSIZE];

	memset(b1, 0, sizeof(b1));
	memset(b2, 0, sizeof(b2));

	memset(b1, '\xff', (0));
	ft_memset(b2, '\xff', 0);

	TEST_ASSERT_EQUAL_MEMORY_MESSAGE(b1, b2, BSIZE, "your memset change something when call with a size of 0 !");
}

// FT_ATOI
#define mt_atoi(tested_str) \
	TEST_ASSERT_EQUAL_INT_MESSAGE(atoi(tested_str), ft_atoi(tested_str), \
	"atoi("tested_str")");

void	test_ft_atoi1(void)
{
	mt_atoi("945");
}

void	test_ft_atoi2(void)
{
	mt_atoi("-085");
}

void	test_ft_atoi3(void)
{
	mt_atoi("\t\v\f\r\n \f-06050");
}

void	test_ft_atoi4(void)
{
	mt_atoi("\t\v\f\r\n \f- \f\t\n\r    06050");
}

void	test_ft_atoi5(void)
{
	mt_atoi("\e06050");
}

void	test_ft_atoi6(void)
{
	mt_atoi("-123THERE IS A NYANCAT UNDER YOUR BED");
}

void	test_ft_atoi7(void)
{
	char	n[15];
	sprintf(n, "%i", INT_MAX);
	TEST_ASSERT_EQUAL_INT_MESSAGE(atoi(n), ft_atoi(n), "not work with int max");
}

void	test_ft_atoi8(void)
{
	char	n[15];
	sprintf(n, "%i", INT_MIN);
	TEST_ASSERT_EQUAL_INT_MESSAGE(atoi(n), ft_atoi(n), "not work with int min");
}

void	test_ft_atoi11(void)
{
	mt_atoi("99999999999999999999999999");
}

void	test_ft_atoi12(void)
{
	mt_atoi("-99999999999999999999999999");
}

void	test_ft_atoi13(void)
{
	mt_atoi("+1234");
}

void	test_ft_atoi14(void)
{
	mt_atoi("\t\v\f\r\n \f+\t\v\f\r\n \f1234");
}

void	test_ft_atoi15(void)
{
	mt_atoi("+\t\v\f\r\n \f1234");
}

void	test_ft_atoi16(void)
{
	srand(clock());
	for (int i = 0; i < 100; i++) {
		char n[15];
		sprintf(n, "%i", rand());
		TEST_ASSERT_EQUAL_INT_MESSAGE(atoi(n), ft_atoi(n), "not work with random number");
	}
}

// FT_BZERO
static void	mt_bzero(int mem_size, void *expected, void *actual, int bzero_size, char *message)
{
	bzero(expected, bzero_size);
	ft_bzero(actual, bzero_size);
	TEST_ASSERT_EQUAL_MEMORY_MESSAGE(expected, actual, mem_size, message);
}

void	test_ft_bzero1(void)
{
	char	expected[10] = "0123456789";
	char	actual[10] = "0123456789";

	bzero(expected, 10);
	ft_bzero(actual, 10);
	mt_bzero(sizeof(expected), expected, actual, 10, "bzero the entire memory.");
}

void	test_ft_bzero2(void)
{
	char	expected[10] = "0123456789";
	char	actual[10] = "0123456789";

	mt_bzero(sizeof(expected), expected, actual, 0, "bzero(mem, 0)");
}

void	test_ft_bzero3(void)
{
	char	expected[10] = "0123456789";
	char	actual[10] = "0123456789";

	mt_bzero(sizeof(expected), expected, actual, 3, "bzero only a part of the memory.");
}

// FT_ISALNUM
static void	mt_isalnum(int c, char *message)
{
	TEST_ASSERT_EQUAL_INT_MESSAGE(isalnum(c), ft_isalnum(c), message);
}

void	test_ft_isalnum1(void)
{
	mt_isalnum('a', "isalnum(a)");
}

void	test_ft_isalnum2(void)
{
	mt_isalnum('b' + 0x100, "isalnum('b' + 0x100)");
}

void	test_ft_isalnum3(void)
{
	mt_isalnum('2', "isalnum('2')");
}

void	test_ft_isalnum4(void)
{
	mt_isalnum('Z', "isalnum('Z')");
}

void	test_ft_isalnum5(void)
{
	mt_isalnum(0, "isalnum(0)");
}

void	test_ft_isalnum6(void)
{
	mt_isalnum(1, "isalnum(1)");
}

void	test_ft_isalnum7(void)
{
	mt_isalnum(999, "isalnum(999)");
}

void	test_ft_isalnum8(void)
{
	mt_isalnum(' ', "isalnum(' ')");
}

void	test_ft_isalnum9(void)
{
	mt_isalnum('%', "isalnum('%')");
}

void	test_ft_isalnum10(void)
{
	mt_isalnum('\n', "isalnum('\n')");
}

void	test_ft_isalnum11(void)
{
	mt_isalnum('\t', "isalnum('\t')");
}

void	test_ft_isalnum12(void)
{
	mt_isalnum(7, "isalnum(7)");
}

// FT_ISALPHA
static void	mt_isalpha(int c, char *message)
{
	TEST_ASSERT_EQUAL_INT_MESSAGE(isalpha(c), ft_isalpha(c), message);
}

void	test_ft_isalpha1(void)
{
	mt_isalpha('a', "isalpha(a)");
}

void	test_ft_isalpha2(void)
{
	mt_isalpha('b' + 0x100, "isalpha('b' + 0x100)");
}

void	test_ft_isalpha3(void)
{
	mt_isalpha('2', "isalpha('2')");
}

void	test_ft_isalpha4(void)
{
	mt_isalpha('Z', "isalpha('Z')");
}

void	test_ft_isalpha5(void)
{
	mt_isalpha(0, "isalpha(0)");
}

void	test_ft_isalpha6(void)
{
	mt_isalpha(1, "isalpha(1)");
}

void	test_ft_isalpha7(void)
{
	mt_isalpha(999, "isalpha(999)");
}

void	test_ft_isalpha8(void)
{
	mt_isalpha(' ', "isalpha(' ')");
}

void	test_ft_isalpha9(void)
{
	mt_isalpha('%', "isalpha('%')");
}

void	test_ft_isalpha10(void)
{
	mt_isalpha('\n', "isalpha('\n')");
}

void	test_ft_isalpha11(void)
{
	mt_isalpha('\t', "isalpha('\t')");
}

void	test_ft_isalpha12(void)
{
	mt_isalpha(7, "isalpha(7)");
}

// FT_ASCII
static void	mt_isacii(int c, char *message)
{
	TEST_ASSERT_EQUAL_INT_MESSAGE(isascii(c), ft_isascii(c), message);
}

void	test_ft_isascii1(void)
{
	mt_isacii('a', "isascii('a')");
}

void	test_ft_isascii2(void)
{
	mt_isacii(-42, "isascii(-42)");
}

void	test_ft_isascii3(void)
{
	mt_isacii(127, "isascii(127)");
}

void	test_ft_isascii4(void)
{
	mt_isacii(128, "isascii(128)");
}

void	test_ft_isascii5(void)
{
	mt_isacii(0, "isascii(0)");
}

void	test_ft_isascii6(void)
{
	mt_isacii('\n', "isascii('\n')");
}

// FT_ISDIGIT
static void	mt_isdigit(int c, char *message)
{
	TEST_ASSERT_EQUAL_INT_MESSAGE(isdigit(c), ft_isdigit(c), message);
}

void	test_ft_isdigit1(void)
{
	mt_isdigit('0', "isdigit('0')");
}

void	test_ft_isdigit2(void)
{
	mt_isdigit('/', "isdigit('/')");
}

void	test_ft_isdigit3(void)
{
	mt_isdigit(':', "isdigit(':')");
}

void	test_ft_isdigit4(void)
{
	mt_isdigit('9', "isdigit('9')");
}

// FT_ISPRINT
static void	mt_isprint(int c, char *message)
{
	TEST_ASSERT_EQUAL_INT_MESSAGE(isprint(c), ft_isprint(c), message);
}

void	test_ft_isprint1(void)
{
	mt_isprint(0, "isprint(0)");
}

void	test_ft_isprint2(void)
{
	mt_isprint(31, "isprint(31)");
}

void	test_ft_isprint3(void)
{
	mt_isprint(32, "isprint(32)");
}

void	test_ft_isprint4(void)
{
	mt_isprint(127, "isprint(127)");
}

void	test_ft_isprint5(void)
{
	mt_isprint(128, "isprint(128)");
}

void	test_ft_isprint6(void)
{
	mt_isprint(-1, "isprint(-1)");
}

void	test_ft_isprint7(void)
{
	mt_isprint(126, "isprint(126)");
}

// FT_MEMCCPY
static void	assert_memccpy_ptr(char *src, int c, size_t n)
{
	char	dst[] = "This is a very long long long senctence.\n";
	TEST_ASSERT_EQUAL_STRING_MESSAGE(
		memccpy(dst, src, c, n),
		ft_memccpy(dst, src, c, n),
		"Return value is incorrect."
	);
}

static void	assert_memccpy_dst(char *src, int c, size_t n)
{
	char	actual[] = "This is a very long long long senctence.\n";
	char	expected[] = "This is a very long long long senctence.\n";
	
	ft_memccpy(actual, src, c, n);
	memccpy(expected, src, c, n);
	TEST_ASSERT_EQUAL_STRING_MESSAGE(
		expected,
		actual,
		"Memory is not copied properly."
	);
}

static void	assert_memccpy(char *src, int c, size_t n)
{
	assert_memccpy_ptr(src, c, n);
	assert_memccpy_dst(src, c, n);
}

void	test_ft_memccpy1(void)
{
	char	src[] = "Hello world!";
	assert_memccpy(src, 'o', 10);
}
void	test_ft_memccpy2(void)
{
	char	src[] = "Hello world!";
	assert_memccpy(src, 'z', 10);
}

void	test_ft_memccpy3(void)
{
	char	src[] = "Hello world!";
	assert_memccpy(src, 0, 10);
}
void	test_ft_memccpy4(void)
{
	char	src[] = "Hello world!";
	assert_memccpy(src, 0, 0);
}
void	test_ft_memccpy5(void)
{
	char	src[] = "Hello world!";
	assert_memccpy(src, 0, sizeof(src));
}
void	test_ft_memccpy6(void)
{
	char	src[] = "Hello world!";
	assert_memccpy(src, 'H', 10);
}
void	test_ft_memccpy7(void)
{
	char	src[] = "Well, \200 is larger than";
	assert_memccpy(src, '\200', 20);
}
void	test_ft_memccpy8(void)
{
	char	src[] = "Well, \200 is larger than";
	assert_memccpy(src, '\200', 4);
}
void	test_ft_memccpy9(void)
{
	char src[] = "string withAinside !";
	assert_memccpy(src, 'A', 11);
}

// FT_MEMCHR

static void	assert_memchr(void *src, int c, size_t n)
{
	TEST_ASSERT_EQUAL_PTR(memchr(src, c, n), ft_memchr(src, c, n));
}

void	test_ft_memchr1(void)
{
	char	src[] = "Hello world!";

	assert_memchr(src, 'l', 10);
}

void	test_ft_memchr2(void)
{
	char	src[] = "Hello world!";

	assert_memchr(src, '=', 10);
}

void	test_ft_memchr3(void)
{
	char	src[] = "hello world!";

	assert_memchr(src, 0, 20);
}

void	test_ft_memchr4(void)
{
	char	src[] = "Hello world!";

	assert_memchr(src, '!', 10);
}

void	test_ft_memchr5(void)
{
	char	src[] = "Hello world!";

	assert_memchr(src, 'y', 100);
}

void	test_ft_memchr6(void)
{
	char			char_tab[10];
	int				int_tab[10];
	unsigned long	long_tab[10];
	int				i;

	i = 0;
	while (i < 10)
	{
		char_tab[i] = (char) rand();
		int_tab[i] = rand();
		long_tab[i] = (unsigned long) rand() * 10000;
		i++;
	}

	assert_memchr(char_tab, char_tab[7], sizeof(char_tab));
	assert_memchr(int_tab, int_tab[7], sizeof(int_tab));
	assert_memchr(long_tab, rand(), sizeof(long_tab));
}

void	test_ft_memchr7(void)
{
	assert_memchr(NULL, 0, 0);
}

// FT_MEMCMP

static void	assert_memcmp(void *b1, void *b2, size_t n)
{
	TEST_ASSERT_EQUAL(memcmp(b1, b2, n), ft_memcmp(b1, b2, n));
}

void	test_ft_memcmp1(void)
{
	int	b1[100];
	int	b2[100];

	memset(b1, 300, 100);
	memset(b2, 300, 50);
	memset(b2 + 50, 500, 50);

	assert_memcmp(b1, b2, 100);
	assert_memcmp(b1, b2, 50);
}

void	test_ft_memcmp2(void)
{
	assert_memcmp("ab\0ab", "ab\0ab", 6);
}

void	test_ft_memcmp3(void)
{
	assert_memcmp("ab\0ab", "ab\0ac", 6);
}

void	test_ft_memcmp4(void)
{
	char			char1_tab[10];
	char			char2_tab[10];
	int				int1_tab[10];
	int				int2_tab[10];
	unsigned long	long1_tab[10];
	unsigned long	long2_tab[10];
	int				i;

	i = 0;
	while (i < 10)
	{
		char1_tab[i] = (char) rand();
		char2_tab[i] = (char) rand();
		int1_tab[i] = rand();
		int2_tab[i] = rand();
		long1_tab[i] = (unsigned long) rand() * 10000;
		long2_tab[i] = (unsigned long) rand() * 10000;
		i++;
	}

	assert_memcmp(char1_tab, char2_tab, 10);
	assert_memcmp(int1_tab, int2_tab, 10);
	assert_memcmp(long1_tab, long2_tab, 10);
}

void	test_ft_memcmp5(void)
{
	assert_memcmp("aaa", "aab", 4);
}

void	test_ft_memcmp6(void)
{
	assert_memcmp("aab", "aac", 2);
}

void	test_ft_memcmp7(void)
{
	assert_memcmp("aww", "bpp", 0);
}

void	test_ft_memcmp8(void)
{
	assert_memcmp("\200", "\0", 1);
}

// FT_MEMCPY
void	test_ft_memcpy1(void)
{
	char	b1[100];
	char	b2[100];

	memset(b1, 42, 100);
	memset(b2, 65, 100);

	ft_memcpy(b1, b2, 100);
	TEST_ASSERT_EQUAL_INT(0, memcmp(b1, b2, 100));
	TEST_ASSERT_EQUAL_INT(0, memcmp(b1, ft_memcpy(b1, b2, 100), 100));
}

// FT_MEMMOVE

void	test_ft_memmove1(void)
{
	char	src[100];
	char	dst[100];

	memset(src, 42, 100);
	memset(dst, 65, 100);
	TEST_ASSERT_EQUAL_PTR_MESSAGE(dst, ft_memmove(dst, src, 100), "Return value is incorrect.");
}

void	test_ft_memmove2(void)
{
	char	testA1[] = "abcdef";
	char	testA2[] = "abcdef";

	ft_memmove(testA1 + 1, testA1, 5);
	ft_memmove(testA1 + 1, testA1, 0);
	memmove(testA2 + 1, testA2, 5);
	memmove(testA2 + 1, testA2, 0);
	TEST_ASSERT_EQUAL_STRING_MESSAGE(testA2, testA1, "Cannot handle when dst > src");
}

void	test_ft_memmove3(void)
{
	char	testB1[] = "abcdef";
	char	testB2[] = "abcdef";

	ft_memmove(testB1, testB1 + 1, 5);
	ft_memmove(testB1, testB1 + 1, 0);
	memmove(testB2, testB2 + 1, 5);
	memmove(testB2, testB2 + 1, 0);
	TEST_ASSERT_EQUAL_STRING_MESSAGE(testB2, testB1, "Cannot handle when dst < src");
}

// FT_STRCAT
void	test_ft_strcat1(void)
{
	char	s1[] = "Hello \0 1234567890";
	char	s2[] = "Hello \0 1234567890";
	char	s3[] = "world!";

	TEST_ASSERT_EQUAL_STRING(strcat(s1, s3), ft_strcat(s2, s3));
}

void	test_ft_strcat2(void)
{
	char	buf[9];

	bzero(buf, 9);
	ft_strcat(buf, "");
	ft_strcat(buf, "Bon");
	ft_strcat(buf, "j");
	ft_strcat(buf, "our.");
	ft_strcat(buf, "");
	TEST_ASSERT_EQUAL_STRING_MESSAGE("Bonjour.", buf, "Cannot concate string properly.");
	TEST_ASSERT_EQUAL_PTR_MESSAGE(buf, ft_strcat(buf, ""), "Return value is not correct.");
}

// FT_STRCHR
static void	assert_strchr(int c)
{
	const char	src[] = "Hello world!";
	TEST_ASSERT_EQUAL_PTR(strchr(src, c), ft_strchr(src, c));
}

void	test_ft_strchr1(void)
{
	assert_strchr('l');
}

void	test_ft_strchr2(void)
{
	assert_strchr('=');
}

void	test_ft_strchr3(void)
{
	assert_strchr(0);
}

void	test_ft_strchr4(void)
{
	assert_strchr('!');
}

void	test_ft_strchr5(void)
{
	assert_strchr('H');
}

// FT_STRCMP
static void	assert_strcmp(char *s1, char *s2, char *message)
{
	TEST_ASSERT_EQUAL_INT_MESSAGE(strcmp(s1, s2), ft_strcmp(s1, s2), message);
}

void test_ft_strcmp1(void)
{
	assert_strcmp("", "", "strcmp(\"\", \"\")");
}

void test_ft_strcmp2(void)
{
	assert_strcmp("abc", "abc", "strcmp(\"abc\", \"abc\")");
}

void test_ft_strcmp3(void)
{
	assert_strcmp("abc", "abd", "strcmp(\"abc\", \"abd\")");
}

void test_ft_strcmp4(void)
{
	assert_strcmp("\200", "\0", "strcmp(\"\\200\", \"\\0\")");
}

void test_ft_strcmp5(void)
{
	assert_strcmp("a", "abcde", "strcmp(\"a\", \"abcde\")");
}

// FT_STRDUP
void	test_ft_strdup1(void)
{
	char	expected[] = "Hello world!\n";
	char	*actual = ft_strdup(expected);

	TEST_ASSERT_EQUAL_STRING_MESSAGE(expected, actual, "Not duplicate normal string properly.");
	TEST_ASSERT_TRUE_MESSAGE(expected != actual, "You should return a new string instead of the source.");
	free(actual);
}

void	test_ft_strdup2(void)
{
	char	expected[] = "";
	char	*actual = ft_strdup(expected);

	TEST_ASSERT_EQUAL_STRING_MESSAGE(expected, actual, "Not duplicate an empty string properly.");
	TEST_ASSERT_TRUE_MESSAGE(expected != actual, "You should return a new string instead of the source.");
	free(actual);
}

// FT_STRLCAT
static void	assert_strlcat(char *dst1, char *dst2, char *src, size_t dstsize)
{
	TEST_ASSERT_EQUAL_INT_MESSAGE(strlcat(dst1, src, dstsize), ft_strlcat(dst2, src, dstsize),
		"Return value is incorrect.");
	TEST_ASSERT_EQUAL_STRING_MESSAGE(dst1, dst2, "Not concatenate string properly.");
}

void	test_ft_strlcat1(void)
{
	char	dst1[10];
	char	dst2[10];

	bzero(dst1, sizeof(dst1));
	bzero(dst2, sizeof(dst2));
	strcpy(dst1, "abc");
	strcpy(dst2, "abc");
	assert_strlcat(dst1, dst2, "abcdefghijklmnop", 10);
	assert_strlcat(dst1, dst2, "abcd", 2);
}

void	test_ft_strlcat2(void)
{
	char	dst1[10];
	char	dst2[10];

	bzero(dst1, sizeof(dst1));
	bzero(dst2, sizeof(dst2));
	assert_strlcat(dst1, dst2, "abc", 10);
	assert_strlcat(dst1, dst2, "def", 10);
}

void	test_ft_strlcat3(void)
{
	char	dst1[10];
	char	dst2[10];

	bzero(dst1, 10);
	bzero(dst2, 10);
	memset(dst1, 'a', 9);
	memset(dst2, 'a', 9);
	assert_strlcat(dst1, dst2, "ccc", 10);
}

void	test_ft_strlcat4(void)
{
	char	dst1[] = "abc\0\0\0";
	char	dst2[] = "abc\0\0\0";
	assert_strlcat(dst1, dst2, "ccc", 0);
}

void	test_ft_strlcat5(void)
{
	char	dst1[] = "abc\0\0\0";
	char	dst2[] = "abc\0\0\0";
	assert_strlcat(dst1, dst2, "ccc", 1);
}

void	test_ft_strlcat6(void)
{
	char	dst1[] = "abc\0\0\0";
	char	dst2[] = "abc\0\0\0";
	assert_strlcat(dst1, dst2, "ccc", 6);
}

void	test_ft_strlcat10(void)
{
	char	dst1[] = "abc\0\0\0";
	char	dst2[] = "abc\0\0\0";
	assert_strlcat(dst1, dst2, "ccc", 10);
}

// FT_STRLEN
static void	assert_strlen(char *s, char *message)
{
	TEST_ASSERT_EQUAL_INT_MESSAGE(strlen(s), ft_strlen(s), message);
}

void	test_ft_strlen1(void)
{
	assert_strlen("", "strlen(\"\")");
}

void	test_ft_strlen2(void)
{
	assert_strlen("aaa\0aaa", "strlen(\"aaa\\0aaa\")");
}

void	test_ft_strlen3(void)
{
	assert_strlen("hello", "strlen(\"hello\")");
}

void	test_ft_strlen4(void)
{
	int test_len = 10 * 1000 * 1000;
	char *str = malloc(sizeof(char) * test_len);;

	memset(str, 'a', test_len);
	str[test_len - 1] = '\0';
	assert_strlen(str, "Not work with 10 million-chars string.");
	free(str);
}

// FT_STRNCAT
static void	assert_strncat(char *dst1, char *dst2, char *src, size_t n)
{
	strncat(dst1, src, n);
	ft_strncat(dst2, src, n);
	TEST_ASSERT_EQUAL_STRING_MESSAGE(dst1, dst2, "Not concatenate string properly.");
}

void	test_ft_strncat1(void)
{
	char	dst1[] = "1234567890123456789";
	char	dst2[] = "1234567890123456789";

	strcpy(dst1, "To be ");
	strcpy(dst2, "To be ");
	assert_strncat(dst1, dst2, "or not to be", 6);
}

void	test_ft_strncat2(void)
{
	char	dst1[20];
	char	dst2[20];

	strcpy(dst1, "To be ");
	strcpy(dst2, "To be ");

	assert_strncat(dst1, dst2, "or not to be", 6);
	assert_strncat(dst1, dst2, "efefef", 0);
	assert_strncat(dst1, dst2, "", 0);
}

// FT_STRNCMP
static void	assert_strncmp(char *s1, char *s2, size_t n, char *message)
{
	TEST_ASSERT_EQUAL_INT_MESSAGE(strncmp(s1, s2, n), ft_strncmp(s1, s2, n), message);
}

void	test_ft_strncmp1(void)
{
	assert_strncmp("\200", "\0", 1, "strncmp(\"\\200\", \"\\0\", 1)");
}

void	test_ft_strncmp2(void)
{
	assert_strncmp("abc", "abcde", 3, "strncmp(\"abc\", \"abcde\", 3)");
}

void	test_ft_strncmp3(void)
{
	assert_strncmp("abc", "abc\0defg", 100, "strncmp(\"abc\", \"abc\\0defg\", 100)");
}

void	test_ft_strncmp4(void)
{
	assert_strncmp("ab\0cde", "abcc\0e", 20, "strncmp(\"ab\\0cde\", \"abcc\\0e\")");
}

void	test_ft_strncmp5(void)
{
	assert_strncmp("q", "a", 0, "strncmp(\"q\", \"a\", 0)");
}

// FT_STRNCPY
static void	assert_strncpy(char *dst1, char *dst2, char *src, size_t n)
{
	TEST_ASSERT_EQUAL_STRING(strncpy(dst1, src, n), ft_strncpy(dst2, src, n));
}

void	test_ft_strncpy1(void)
{
	char	dst1[6];
	char	dst2[6];

	memset(dst1, 33, 6);
	memset(dst2, 33, 6);
	assert_strncpy(dst1, dst2, "abc\0\0", 6);
}

void	test_ft_strncpy2(void)
{
	char	dst1[6];
	char	dst2[6];

	memset(dst1, 33, 6);
	memset(dst2, 33, 6);
	assert_strncpy(dst1, dst2, "abcdefghi", 6);
}

// FT_STRNSTR
static void	assert_strnstr(const char *haystack, const char *needle, size_t len, char *message)
{
	TEST_ASSERT_EQUAL_STRING_MESSAGE(strnstr(haystack, needle, len), ft_strnstr(haystack, needle, len), message);
}

void	test_ft_strnstr1(void)
{
	char	haystack[10];

	bzero(haystack, 10);
	strcpy(haystack, "un deux 9");
	assert_strnstr(haystack, "deux", 10, "Your function cannot neither find the string nor point to the correct position.");
}

void	test_ft_strnstr2(void)
{
	char	haystack[10];

	bzero(haystack, 10);
	strcpy(haystack, "un deux 9");
	assert_strnstr(haystack, "9", 3, "Should return NULL when a string is not found in range.");
}

void	test_ft_strnstr3(void)
{
	char	haystack[10];

	bzero(haystack, 10);
	strcpy(haystack, "un deux 9");
	assert_strnstr(haystack, "", 6, "Should return haystack when needle is an empty string.");
}

void	test_ft_strnstr4(void)
{
	char	haystack[10];

	bzero(haystack, 10);
	strcpy(haystack, "un deux 9");
	assert_strnstr(haystack, "9", 10, "Your function cannot neither find the string nor point to the correct position.");
}

void	test_ft_strnstr5(void)
{
	char	haystack[10];

	bzero(haystack, 10);
	strcpy(haystack, "un deux 9");
	assert_strnstr(haystack, "9", 8, "Should return NULL when a string is not found in range.");
}

void	test_ft_strnstr6(void)
{
	char	haystack[10];

	bzero(haystack, 10);
	strcpy(haystack, "un deux 9");
	assert_strnstr(haystack, "96", 10, "Should return NULL when a string is not found.");
}

void	test_ft_strnstr7(void)
{
	char	haystack[] = "un\0deux 9";

	assert_strnstr(haystack, "deux", 10, "Should return NULL when a string is not found.");
}

void	test_ft_strnstr8(void)
{
	char	haystack[] = "ozarabozaraboze123";

	assert_strnstr(haystack, "ozaraboze", 15, "Your function cannot neither find the string nor point to the correct position.");
}

// FT_STRRCHR
static void	assert_strrchr(int c, char *message)
{
	const char	buf[] = "Habcdedcba";
	TEST_ASSERT_EQUAL_STRING_MESSAGE(strrchr(buf, c), ft_strrchr(buf, c), message);
}

void	test_ft_strrchr1(void)
{
	assert_strrchr('a', "strrchr(\"Habcdedcba\", 'a')");
}

void	test_ft_strrchr2(void)
{
	assert_strrchr(0, "strrchr(\"Habcdedcba\", 0)");
}

void	test_ft_strrchr3(void)
{
	assert_strrchr('z', "strrchr(\"Habcdedcba\", 'z')");
}

void	test_ft_strrchr4(void)
{
	assert_strrchr('H', "strrchr(\"Habcdedcba\", 'H')");
}

// FT_STRSTR
# define assert_strstr(s1, s2) \
	TEST_ASSERT_EQUAL_STRING_MESSAGE(strstr(s1, s2), ft_strstr(s1, s2), \
	"strstr(\""s1"\", \""s2"\")");

void	test_ft_strstr1(void)
{
	assert_strstr("Ceci n'est pas une pipe.", "une");
}

void	test_ft_strstr2(void)
{
	assert_strstr("Ceci n'est pas une pipe.", "C");
}

void	test_ft_strstr3(void)
{
	assert_strstr("Ceci n'est pas une pipe.", ".");
}

void	test_ft_strstr4(void)
{
	assert_strstr("Ceci n'est pas une pipe.", "");
}

void	test_ft_strstr5(void)
{
	assert_strstr("Ceci n'est pas une pipe.", "aaaaa");
}

void	test_ft_strstr6(void)
{
	assert_strstr("ozarabozaraboze", "ozaraboze");
}

void	test_ft_strstr7(void)
{
	assert_strstr("Ceci n'est pas une pipe.", "BWAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
}

void	test_ft_strstr8(void)
{
	assert_strstr("", "");
}

void	test_ft_strstr9(void)
{
	assert_strstr("J'ai fait pipapipapou en LV2", "pipapou");
}

// FT_TOLOWER
void	test_ft_tolower1(void)
{
	TEST_ASSERT_EQUAL(tolower('#'), ft_tolower('#'));
	TEST_ASSERT_EQUAL(tolower('1'), ft_tolower('1'));
}
void	test_ft_tolower2(void)
{
	TEST_ASSERT_EQUAL(tolower('a'), ft_tolower('a'));
	TEST_ASSERT_EQUAL(tolower('z'), ft_tolower('z'));
}
void	test_ft_tolower3(void)
{
	TEST_ASSERT_EQUAL(tolower('A'), ft_tolower('A'));
	TEST_ASSERT_EQUAL(tolower('Z'), ft_tolower('Z'));
}

// FT_TOUPPER
void	test_ft_toupper1(void)
{
	TEST_ASSERT_EQUAL(toupper('#'), ft_toupper('#'));
	TEST_ASSERT_EQUAL(toupper('1'), ft_toupper('1'));
}
void	test_ft_toupper2(void)
{
	TEST_ASSERT_EQUAL(toupper('A'), ft_toupper('A'));
	TEST_ASSERT_EQUAL(toupper('Z'), ft_toupper('Z'));
}
void	test_ft_toupper3(void)
{
	TEST_ASSERT_EQUAL(toupper('a'), ft_toupper('a'));
	TEST_ASSERT_EQUAL(toupper('z'), ft_toupper('z'));
}

// FT_ITOA
static void	assert_itoa(int num, char *expected)
{
	char	*actual = ft_itoa(num);

	TEST_ASSERT_EQUAL_STRING(expected, actual);
	free(actual);
}

void	test_ft_itoa1(void)
{
	assert_itoa(0, "0");
}

void	test_ft_itoa2(void)
{
	assert_itoa(1, "1");
}

void	test_ft_itoa3(void)
{
	assert_itoa(-1234, "-1234");
}

void	test_ft_itoa4(void)
{
	assert_itoa(123456000, "123456000");
}

void	test_ft_itoa5(void)
{
	assert_itoa(-2147483648, "-2147483648");
}

void	test_ft_itoa6(void)
{
	assert_itoa(2147483647, "2147483647");
}

// FT_MEMALLOC
void	test_ft_memalloc1(void)
{
	void	*expected;
	void	*actual;
	const int	size = 100;

	expected = malloc(size);
	bzero(expected, size);
	actual = ft_memalloc(size);

	TEST_ASSERT_NOT_NULL(expected);
	TEST_ASSERT_NOT_NULL(actual);

	TEST_ASSERT_EQUAL_MEMORY_MESSAGE(expected, actual, size, "Every bytes in newly allocated memory should be 0.");

	free(expected);
	free(actual);
}

void	test_ft_memalloc2(void)
{
	char	*actual = ft_memalloc(ULONG_MAX);
	TEST_ASSERT_NULL(actual);
}

// FT_MEMDEL
void	test_ft_memdel1(void)
{
	int		*mem;

	mem = (int *)malloc(sizeof(int) * 3);
	mem[0] = 949;
	mem[1] = 859;
	mem[2] = 442;
	ft_memdel((void **)&mem);
	TEST_ASSERT_NULL(mem);
}

// FT_PUTCHAR_FD
void	test_ft_putchar_fd1(void)
{
	int		filedes[2];
	char	str[100];

	pipe(filedes);
	ft_putchar_fd('a', filedes[1]);
	ft_putchar_fd('b', filedes[1]);
	str[read(filedes[0], str, 100)] = '\0';
	close(filedes[0]);
	close(filedes[1]);
	TEST_ASSERT_EQUAL_STRING("ab", str);
}

// FT_PUTCHAR
void	test_ft_putchar1(void)
{
	int		out;
	int		filedes[2];
	char	buf[4];

	out = dup(STDOUT_FILENO);
	pipe(filedes);
	dup2(filedes[1], STDOUT_FILENO);
	ft_putchar('a');
	ft_putchar('b');
	ft_putchar('c');
	dup2(out, STDOUT_FILENO);
	buf[read(filedes[0], buf, 3)] = '\0';
	close(filedes[0]);
	close(filedes[1]);
	close(out);
	TEST_ASSERT_EQUAL_STRING("abc", buf);
}

// FT_PUTENDL_FD
void	test_ft_putendl_fd1(void)
{
	int		p[2];
	char	buf[100];

	pipe(p);
	ft_putendl_fd("A QUE KOUKOU", p[1]);
	buf[read(p[0], buf, 100)] = 0;
	close(p[0]);
	close(p[1]);
	TEST_ASSERT_EQUAL_STRING(buf, "A QUE KOUKOU\n");
}

// FT_PUTENDL
void	test_ft_putendl1(void)
{
	int		out;
	int		p[2];
	char	buf[4];

	out = dup(1);
	pipe(p);
	dup2(p[1], 1);
	ft_putendl("aa");
	dup2(out, 1);
	read(p[0], buf, 3);
	buf[3] = 0;
	close(p[0]);
	close(p[1]);
	close(out);
	TEST_ASSERT_EQUAL_STRING(buf, "aa\n");
}

// FT_PUTNBR_FD
void	test_ft_putnbr_fd1(void)
{
	int		p[2];
	char	buf[100];

	pipe(p);
	ft_putnbr_fd(0, p[1]);
	ft_putnbr_fd(1, p[1]);
	ft_putnbr_fd(-1, p[1]);
	ft_putnbr_fd(56, p[1]);
	ft_putnbr_fd(-1230, p[1]);
	ft_putnbr_fd(10203, p[1]);
	ft_putnbr_fd(2147483647, p[1]);
	ft_putnbr_fd(-2147483648, p[1]);
	buf[read(p[0], buf, 100)] = 0;
	close(p[0]);
	close(p[1]);
	TEST_ASSERT_EQUAL_STRING(buf, "01-156-1230102032147483647-2147483648");
}

// FT_PUTNBR
void	test_ft_putnbr(void)
{
	int		out;
	int		p[2];
	char	buf[100];

	out = dup(1);
	pipe(p);
	dup2(p[1], 1);
	ft_putnbr(0);
	ft_putnbr(1);
	ft_putnbr(-1);
	ft_putnbr(12300);
	ft_putnbr(10203);
	ft_putnbr(-56);
	ft_putnbr(2147483647);
	ft_putnbr(-2147483648);
	dup2(out, 1);
	buf[read(p[0], buf, 100)] = 0;
	close(p[0]);
	close(p[1]);
	close(out);
	TEST_ASSERT_EQUAL_STRING(buf, "01-11230010203-562147483647-2147483648");
}

// FT_PUTSTR_FD
void	test_ft_putstr_fd1(void)
{
	int		p[2];
	char	buf[100];

	pipe(p);
	ft_putstr_fd("A QUE KOUKOU", p[1]);
	buf[read(p[0], buf, 100)] = 0;
	close(p[0]);
	close(p[1]);
	TEST_ASSERT_EQUAL_STRING(buf, "A QUE KOUKOU");
}

// FT_PUTSTR
void	test_ft_putstr1(void)
{
	int		out;
	int		p[2];
	char	buf[4];

	out = dup(1);
	pipe(p);
	dup2(p[1], 1);
	ft_putstr("abc");
	dup2(out, 1);
	read(p[0], buf, 3);
	buf[3] = 0;
	close(p[0]);
	close(p[1]);
	close(out);
	TEST_ASSERT_EQUAL_STRING(buf, "abc");
}

// FT_STRCLR
void	test_ft_strclr1(void)
{
	char	str[] = "tttttt";

	ft_strclr(str);
	TEST_ASSERT_EQUAL_MEMORY(str, "\0\0\0\0\0\0", 7);
}

// FT_STRDEL
void	test_ft_strdel1(void)
{
	char	*str;

	str = malloc(123);
	ft_strdel(&str);
	TEST_ASSERT_NULL(str);
}

// FT_STREQU
void	test_ft_strequ1(void)
{
	TEST_ASSERT_EQUAL_INT(1, ft_strequ("", ""));
}

void	test_ft_strequ2(void)
{
	TEST_ASSERT_EQUAL_INT(1, ft_strequ("abcDEF", "abcDEF"));
}

void	test_ft_strequ3(void)
{
	TEST_ASSERT_EQUAL_INT(0, ft_strequ("abcDEF", "abcDEf"));
}

// FT_STRITER
static void	convert_to_upper(char *c)
{
	*c = toupper(*c);
}
void	test_ft_striter(void)
{
	char	str[] = "aBcDeF";

	ft_striter(str, &convert_to_upper);
	TEST_ASSERT_EQUAL_STRING("ABCDEF", str);
}

// FT_STRITERI
static void	iteri_test(unsigned int i, char *c)
{
	*c = *c + i;
}

void	test_ft_striteri1(void)
{
	char str[] = "aaaaaa";

	ft_striteri(str, &iteri_test);
	TEST_ASSERT_EQUAL_STRING("abcdef", str);
}

// FT_STRJOIN
static void	assert_strjoin(char *s1, char *s2, char *expected)
{
	char	*actual = ft_strjoin(s1, s2);
	TEST_ASSERT_EQUAL_STRING(expected, actual);
	free(actual);
}

void	test_ft_strjoin1(void)
{
	assert_strjoin("abc", "def", "abcdef");
}

void	test_ft_strjoin2(void)
{
	assert_strjoin("", "", "");
}

// FT_STRMAP
static char	map_test(char c)
{
	return ((char)toupper(c));
}
void	test_ft_strmap1(void)
{
	char	input[] = "Hello, my name is Huy!\n";
	char	*str;

	str = ft_strmap(input, &map_test);
	TEST_ASSERT_EQUAL_STRING("HELLO, MY NAME IS HUY!\n", str);
	ft_strdel(&str);
}

// FT_STRMAPI
static char	mapi_test(unsigned int i, char c)
{
	return (c + i);
}

void	test_ft_strmapi1(void)
{
	char	input[] = "aaaaaa";
	char	*str;

	str = ft_strmapi(input, &mapi_test);
	TEST_ASSERT_EQUAL_STRING("abcdef", str);
	ft_strdel(&str);
}

// FT_STRNEQU
void	test_ft_strnequ1(void)
{
	TEST_ASSERT_EQUAL_INT(1, ft_strnequ("ededeqdf", "", 0));
}

void	test_ft_strnequ2(void)
{
	TEST_ASSERT_EQUAL_INT(1, ft_strnequ("abcde", "abdfe", 2));
}

void	test_ft_strnequ3(void)
{
	TEST_ASSERT_EQUAL_INT(1, ft_strnequ("abc", "abc", 100));
}

void	test_ft_strnequ4(void)
{
	TEST_ASSERT_EQUAL_INT(0, ft_strnequ("abcde", "abdde", 5));
}

// FT_STRNEW
void	test_ft_strnew1(void)
{
	int		str_len = 100;
	char	*actual;
	char	*expected;

	actual = ft_strnew(str_len);
	expected = malloc(sizeof(char) * (str_len + 1));
	bzero(expected, sizeof(char) * (str_len + 1));
	TEST_ASSERT_EQUAL_MEMORY(expected, actual, str_len + 1);
	free(actual);
}

void	test_ft_strnew2(void)
{
	char	*actual = ft_strnew(0);
	TEST_ASSERT_NOT_NULL(actual);
	free(actual);
}

void	test_ft_strnew3(void)
{
	char	*actual = ft_strnew(ULONG_MAX - 1);
	TEST_ASSERT_NULL(actual);
}

// FT_STRSPLIT

static void	assert_strsplit(char *expected[], char *src, char c, int array_len)
{
	int		i;
	char	**actual;
	char	message[] = "Element # is incorrect.";

	i = 0;
	actual = ft_strsplit(src, c);
	TEST_ASSERT_NOT_NULL(actual);
	while(i < array_len)
	{
		message[8] = i + '0';
		TEST_ASSERT_EQUAL_STRING_MESSAGE(expected[i], actual[i], message);
		free(actual[i]);
		i++;
	}
	free(actual);
}

void	test_ft_strsplit1(void)
{
	char	*expected[] = {"salut", "!", NULL};
	assert_strsplit(expected, "***salut****!**", '*', 3);
}

void	test_ft_strsplit2(void)
{
	char	*expected[] = {NULL};
	assert_strsplit(expected, "*****", '*', 1);
}

void	test_ft_strsplit3(void)
{
	char	*expected[] = { "coucou", NULL };
	assert_strsplit(expected, "coucou", '*', 2);
}

void	test_ft_strsplit4(void)
{
	char	*expected[] = { "salut", NULL };
	assert_strsplit(expected, "salut****", '*', 2);
}

void	test_ft_strsplit5(void)
{
	char	*expected[] = { NULL };
	assert_strsplit(expected, "", '*', 1);
}

// FT_STRSUB
void	test_ft_strsub1(void)
{
	char	str[] = "Un jour je serai, le meilleur dresseur !";
	char	*actual = ft_strsub(str, 0, (size_t)-10);
	TEST_ASSERT_NULL(actual);
	free(actual);
}

void	test_ft_strsub2(void)
{
	char	str[] = "Un jour je serai, le meilleur dresseur !";
	char	*actual = ft_strsub(str, 8, 8);
	TEST_ASSERT_EQUAL_STRING("je serai", actual);
	free(actual);
}

void	test_ft_strsub3(void)
{
	char	str[] = "Un jour je serai, le meilleur dresseur !";
	char	*actual = ft_strsub(str, 0, 0);
	TEST_ASSERT_EQUAL_STRING("", actual);
	free(actual);
}

// FT_STRTRIM
void	test_ft_strtrim1(void)
{
	char	*actual = ft_strtrim("\t\n  \tAAA \t BBB\t\n  \t");
	TEST_ASSERT_EQUAL_STRING("AAA \t BBB", actual);
	free(actual);
}

void	test_ft_strtrim2(void)
{
	char	*actual = ft_strtrim("\t\t\n\t\t   ");
	TEST_ASSERT_EQUAL_STRING("", actual);
	free(actual);
}

void	test_ft_strtrim3(void)
{
	char	*actual = ft_strtrim("");
	TEST_ASSERT_EQUAL_STRING("", actual);
	free(actual);
}

void	test_ft_strtrim4(void)
{
	char	*actual = ft_strtrim("abc");
	TEST_ASSERT_EQUAL_STRING("abc", actual);
	free(actual);
}

// FT_LSTADD
void	test_ft_lstadd1(void)
{
	t_list	*lst;
	t_list	*lst2;

	lst = malloc(sizeof(t_list));
	lst2 = malloc(sizeof(t_list));
	bzero(lst, sizeof(t_list));
	bzero(lst2, sizeof(t_list));
	ft_lstadd(&lst, lst2);
	TEST_ASSERT_EQUAL_PTR_MESSAGE(lst, lst2, "Your pointer does not point to the beginning of the list.");
	TEST_ASSERT_NOT_NULL(lst->next);
	free(lst->next);
	free(lst);
}

// FT_LSTDEL
static int	lstdel_count = 0;
static void	lstdel_test(void *content, size_t content_size)
{
	(void) content;
	(void) content_size;
	lstdel_count++;
}

void	test_ft_lstdel1(void)
{
	t_list	*lst;
	int		data;

	lst = malloc(sizeof(t_list));
	bzero(lst, sizeof(t_list));
	lst->next = malloc(sizeof(t_list));
	bzero(lst->next, sizeof(t_list));
	lst->content = &data;
	lst->next->content = &data;
	ft_lstdel(&lst, &lstdel_test);
	TEST_ASSERT_NULL(lst);
	TEST_ASSERT_EQUAL_INT_MESSAGE(2, lstdel_count, "The number of items deleted is not equal to the number of list items.");
}

// FT_LSTDELONE
static int	lstdelone_count = 0;
static void	lstdelone_test(void *content, size_t content_size)
{
	(void) content;
	(void) content_size;
	lstdelone_count++;
}
void	test_ft_lstdelone1(void)
{
	t_list	*lst;
	int		data;

	lst = malloc(sizeof(t_list));
	bzero(lst, sizeof(t_list));
	lst->next = malloc(sizeof(t_list));
	bzero(lst->next, sizeof(t_list));
	lst->content = &data;
	lst->next->content = &data;
	ft_lstdelone(&lst, &lstdelone_test);
	TEST_ASSERT_NULL(lst);
	TEST_ASSERT_EQUAL_INT_MESSAGE(1, lstdelone_count, "The number of items deleted is not equal to the number of list items.");
	free(lst);
}

// FT_LSTITER
static void	lstiter_test(t_list *item)
{
	item->content_size = 42;
}
void	test_ft_lstiter1(void)
{
	t_list	*lst;
	int		data;

	data = 42;
	lst = malloc(sizeof(t_list));
	bzero(lst, sizeof(t_list));
	lst->next = malloc(sizeof(t_list));
	bzero(lst->next, sizeof(t_list));
	lst->content = &data;
	lst->next->content = &data;
	ft_lstiter(lst, &lstiter_test);
	TEST_ASSERT_EQUAL_INT_MESSAGE(42, lst->content_size, "Element 0 should have content_size=42");
	TEST_ASSERT_EQUAL_INT_MESSAGE(42, lst->next->content_size, "Element 1 should have content_size=42");
	free(lst->next);
	free(lst);
}

// FT_LSTMAP
static t_list	*lstmap_test_fn(t_list *list)
{
	t_list	*l2;
	int		data;

	data = 9;
	l2 = malloc(sizeof(t_list));
	bzero(l2, sizeof(t_list));
	l2->content = &data;
	l2->content_size = list->content_size * 2;
	return (l2);
}

void	test_ft_lstmap1(void)
{
	t_list	*lst;
	t_list	*map;
	int		data;

	data = 123;
	lst = malloc(sizeof(t_list));
	bzero(lst, sizeof(t_list));
	lst->next = malloc(sizeof(t_list));
	bzero(lst->next, sizeof(t_list));
	lst->content = &data;
	lst->content_size = 21;
	lst->next->content = &data;
	lst->next->content_size = 100;
	map = ft_lstmap(lst, lstmap_test_fn);
	TEST_ASSERT_EQUAL_INT_MESSAGE(42, map->content_size, "content_size of element 0 of the new list is incorrect.");
	TEST_ASSERT_EQUAL_INT_MESSAGE(200, map->next->content_size, "content_size of element 1 of the new list is incorrect.");
	free(lst->next);
	free(lst);
	free(map->next);
	free(map);
}

// FT_LST_PUSH_BACK
static void	del_str_lst(void *s, size_t size)
{
	if (size > 0)
		free(s);
}
void	test_ft_lst_push_back1(void)
{
	t_list	*lst;

	lst = NULL;
	ft_lst_push_back(&lst, strdup("one"), 4 * sizeof(char));
	ft_lst_push_back(&lst, strdup("two"), 4 * sizeof(char));
	ft_lst_push_back(&lst, strdup("three"), 6 * sizeof(char));
	TEST_ASSERT_EQUAL_STRING("one", lst->content);
	TEST_ASSERT_EQUAL_STRING("two", lst->next->content);
	TEST_ASSERT_EQUAL_STRING("three", lst->next->next->content);
	ft_lstdel(&lst, del_str_lst);
}

void	test_ft_lst_push_back2(void)
{
	t_list	*lst;

	lst = NULL;
	ft_lst_push_back(&lst, strdup("one"), 4);
	TEST_ASSERT_NOT_NULL_MESSAGE(lst, "If list is null, you must initialize it.");
	TEST_ASSERT_EQUAL_STRING_MESSAGE("one", lst->content, "Data in list is not created properly.");
	ft_lstdel(&lst, del_str_lst);
}

// FT_LST_LEN
void	test_ft_lst_len1(void)
{
	t_list	*lst;

	lst = NULL;
	TEST_ASSERT_EQUAL_INT(0, ft_lst_len(lst));
}

void	test_ft_lst_len2(void)
{
	t_list	*lst;

	lst = NULL;
	ft_lst_push_back(&lst, strdup("one"), 4 * sizeof(char));
	ft_lst_push_back(&lst, strdup("two"), 4 * sizeof(char));
	ft_lst_push_back(&lst, strdup("three"), 6 * sizeof(char));
	TEST_ASSERT_EQUAL_INT(3, ft_lst_len(lst));
	ft_lstdel(&lst, del_str_lst);
}

// FT_LST_GET
void	test_ft_lst_get1(void)
{
	t_list	*lst;

	lst = NULL;
	ft_lst_push_back(&lst, strdup("one"), 4 * sizeof(char));
	ft_lst_push_back(&lst, strdup("two"), 4 * sizeof(char));
	ft_lst_push_back(&lst, strdup("three"), 6 * sizeof(char));
	TEST_ASSERT_EQUAL_STRING("one", ft_lst_get(lst, 0)->content);
	TEST_ASSERT_EQUAL_STRING("two", ft_lst_get(lst, 1)->content);
	TEST_ASSERT_EQUAL_STRING("two", ft_lst_get(lst, -2)->content);
	TEST_ASSERT_EQUAL_STRING("three", ft_lst_get(lst, 2)->content);
	TEST_ASSERT_EQUAL_STRING("three", ft_lst_get(lst, -1)->content);
	ft_lstdel(&lst, del_str_lst);
}

// FT_LST_POP
void	test_ft_lst_pop1(void)
{
	t_list	*lst;

	lst = NULL;
	ft_lst_push_back(&lst, strdup("one"), 4 * sizeof(char));
	ft_lst_push_back(&lst, strdup("two"), 4 * sizeof(char));
	ft_lst_push_back(&lst, strdup("three"), 6 * sizeof(char));
	TEST_ASSERT_EQUAL_STRING("one", ft_lst_pop_front(&lst)->content);
	TEST_ASSERT_EQUAL_STRING("two", lst->content);
	ft_lstdel(&lst, del_str_lst);
}