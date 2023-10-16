#include "pch.h"
#include "CppUnitTest.h"
#include "../labor52/labor52.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			double x = 2.0;
			double eps = 0.0001;

			double expected = 0.312153;

			
			double result = lnTaylor(x, eps);

			
			Assert::AreEqual(expected, result, 0.00001);
		}
	};
}
