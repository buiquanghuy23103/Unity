# What this repo about?

This repo is a fork of the [Unity Test Project](https://github.com/ThrowTheSwitch/Unity), one of the main projects of ThrowTheSwitch.org.
Unity Test is a unit testing framework built for C, with a focus on working with embedded toolchains.


## Documentation

The `docs` folder contains a [getting started guide][] and much more tips about using Unity.

## How to run the test

1. Go to `test_libft`
2. Create symbolic link `libft.a` and `libft.h` to your static library and header respectively.
3. Type `make` and hit Enter. That will be all :)

## How to write a test

1. Go to `test_libft/test`
2. Create a C file whose name follows the format `test_yourLogin.c`. By doing this, if someone want to contact you regarding your test file, they know how to reach you. Below is an example of a test file:

```java
#include "libft.h"
#include "unity.h"

void setUp(void)
{
}

void tearDown(void)
{
}
void test_strlen(void)
{
	TEST_ASSERT_EQUAL(3, ft_strlen("abc"));
}
``` 
Please note that even though `setup()` and `tearDown()` are empty, you should not remove it. Otherwise, the test will not run. Please refer to the [documentation](https://github.com/ThrowTheSwitch/Unity/blob/master/docs/UnityGettingStartedGuide.md) for more information.
## Recommendation

It is recommended that each Hiver has his/her own test file and don't modify the others to avoid conflicts. You can provide feedbacks to others' tests by leaving a comment on GitHub and don't forget to [enable GitHub notification](https://docs.github.com/en/account-and-profile/managing-subscriptions-and-notifications-on-github/setting-up-notifications/configuring-notifications).

## How to contribute to the project

If you want to make your test files visible on this GitHub, please follow [this instruction on how to contribute to a GitHub project](https://www.dataschool.io/how-to-contribute-on-github/)
