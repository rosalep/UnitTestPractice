/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, mixed_case_password)
{
	Password my_password;
	bool mixed = my_password.has_mixed_case("Hello");
	ASSERT_EQ(true, mixed);

}

TEST(PasswordTest, mixed_case2_password)
{
	Password my_password;
	bool mixed = my_password.has_mixed_case("HeLlO");
	ASSERT_EQ(true, mixed);

}

TEST(PasswordTest, mixed_case3_password)
{
	Password my_password;
	bool mixed = my_password.has_mixed_case("This is a mixed case.");
	ASSERT_EQ(true, mixed);

}

TEST(PasswordTest, not_mixed_case_password)
{
	Password my_password;
	bool mixed = my_password.has_mixed_case("hello");
	ASSERT_EQ(false, mixed);

}

TEST(PasswordTest, not_mixed_case2_password)
{
	Password my_password;
	bool mixed = my_password.has_mixed_case("not mixed case");
	ASSERT_EQ(false, mixed);
}

TEST(PasswordTest, not_mixed_case3_password)
{
	Password my_password;
	bool mixed = my_password.has_mixed_case("");
	ASSERT_EQ(false, mixed);
}

TEST(PasswordTest, not_mixed_case4_password)
{
	Password my_password;
	bool mixed = my_password.has_mixed_case("./.' ,.");
	ASSERT_EQ(false, mixed);
}

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual); // assert that actual should be equal to 1
}

TEST(PasswordTest, three_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("aaab");
	ASSERT_EQ(3, actual); // assert that actual should be equal to 3
}

TEST(PasswordTest, start_lower_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("aAb");
	ASSERT_EQ(1, actual); // assert that actual should be equal to 1
}

TEST(PasswordTest, all_lower_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("aaa");
	ASSERT_EQ(3, actual); // assert that actual should be equal to 3
}

TEST(PasswordTest, start_capital_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Aab");
	ASSERT_EQ(1, actual); // assert that actual should be equal to 1
}

TEST(PasswordTest, nothing_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("");
	ASSERT_EQ(0, actual); // assert that actual should be equal to 0
}

TEST(PasswordTest, empty_char_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("aa a ba");
	ASSERT_EQ(2, actual); // assert that actual should be equal to 2
}

TEST(PasswordTest, all_upper_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("AAA");
	ASSERT_EQ(3, actual); // assert that actual should be equal to 3
}


