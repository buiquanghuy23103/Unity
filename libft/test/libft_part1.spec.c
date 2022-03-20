#include "libft.h"
#include "testft.h"
#include <time.h>

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

	TEST_ASSERT_EQUAL_MEMORY_MESSAGE(b1, b2, 20, "basic memset test (fill a buffer with 'A')");
}

void	test_ft_memset1(void)
{
	char	b1[BSIZE];
	char	b2[BSIZE];

	memset(b1, 'B', BSIZE);
	memset(b2, 'B', BSIZE);

	memset(b1, '\200', 10);
	ft_memset(b2, '\200', 10);

	TEST_ASSERT_EQUAL_MEMORY_MESSAGE(b1, b2, 20, "your memset does not cast the memory into unsigned chars");
}

void	test_ft_memset2(void)
{
	char	*r1 = memset("", 'B', (0));
	char	*r2 = memset("", 'B', (0));

	TEST_ASSERT_EQUAL_MESSAGE(r1, r2, "either your memset return value is incorrect, or your memset does not work");
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

	TEST_ASSERT_EQUAL_MEMORY_MESSAGE(c1, c2, BSIZE, "basic memset test (fill a buffer with 'A')");
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
void	mt_bzero(int mem_size, void *expected, void *actual, int bzero_size, char *message)
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
