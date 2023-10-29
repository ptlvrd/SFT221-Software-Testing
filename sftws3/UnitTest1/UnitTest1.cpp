#include "pch.h"
#include "pch.h"
#include "CppUnitTest.h"
#include "sftws3_r.h"
#include <cstring>
#include <cctype>


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
bool stringIsValid(const string& tempString);

namespace blackBoxString {
	TEST_CLASS(stringTest) {
    public:
		TEST_METHOD(testStringIsValid) {
			bool isValid = stringIsValid("1234567890`123456789012"); //checking to see if a long string is allowed 
			Assert::IsTrue(isValid);
	}
	};

	TEST_CLASS(stringTest2)//testing to check a string with spaces 
	{
public:
	TEST_METHOD(testStringIsValid) {
		bool isValid = stringIsValid("vrunda patel");  
		Assert::IsTrue(isValid);
	}
	};

	TEST_CLASS(stringTest3)//failling on purpose to see that the test is working
	{
	public:
		TEST_METHOD(testStringIsValid) {
			bool isValid = stringIsValid("hi");
			Assert::IsTrue(!isValid);
		}
	};
}
namespace whiteBoxString {
	TEST_CLASS(StringTest1)
	{
	public:
		TEST_METHOD(TestStringIsValid)
		{
			bool isValid = stringIsValid(" "); //checking to see if a space would be treated as invalid emty string
			Assert::IsTrue(!isValid);
		}
	};

	TEST_CLASS(StringTest2)
	{
	public:
		TEST_METHOD(TestStringIsValid)
		{
			bool isValid = stringIsValid("\n");  //checking to see if it rejects the newline character and shows it as invalid
			Assert::IsTrue(!isValid);
		}
	};

	TEST_CLASS(StringTest3)
	{
	public:
		TEST_METHOD(TestStringIsValid)
		{
			bool isValid = stringIsValid(" \n");  //checking to see if it rejects the  whitespace and newline character and shows it as invalid
			Assert::IsTrue(!isValid);
		}
	};


}
bool stringIsValid(const string& tempString) {
	return !tempString.empty();
}
namespace blackBoxPostal {
	TEST_CLASS(PostalTest1)
	{
	public:
		TEST_METHOD(stringIsValidPostalCode)
		{
			bool isValid = postIsValid("m1j3e5"); //chekcing valid postal code format without space
			Assert::IsTrue(isValid);
		}
	};

	TEST_CLASS(PostalTest2)
	{
	public:
		TEST_METHOD(stringIsValidPostalCode)
		{
			bool isValid = postIsValid("m1j 3e5"); //chekcing valid postal code format with space
			Assert::IsTrue(isValid);
		}
	};

	TEST_CLASS(PostalTest3)
	{
	public:
		TEST_METHOD(stringIsValidPostalCode)
		{
			bool isValid = postIsValid("m1j 3e"); //chekcing invalid postal code format with missing one digit
			Assert::IsTrue(!isValid);
		}
	};

}
namespace whiteBoxPostal {
	TEST_CLASS(PostalTest1)
	{
	public:
		TEST_METHOD(stringIsValidPostalCode)
		{
			bool isValid = postIsValid("m1j 3e55"); //chekcing invalid postal code format with too many digits
			Assert::IsTrue(!isValid);
		}
	};

	TEST_CLASS(PostalTest2)
	{
	public:
		TEST_METHOD(stringIsValidPostalCode)
		{
			bool isValid = postIsValid("1234567"); //chekcing invalid postal code format with all digit, no letters
			Assert::IsTrue(!isValid);
		}
	};

	TEST_CLASS(PostalTest3)
	{
	public:
		TEST_METHOD(stringIsValidPostalCode)
		{
			bool isValid = postIsValid("m1j e5e"); //chekcing invalid postal code format with letters in the wrong place
			Assert::IsTrue(!isValid);
		}
	};
}
bool stringIsValidPostalCode(int valid)
{
	return valid;
}