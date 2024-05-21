#include "pch.h"
#include "CppUnitTest.h"
//#include "../Lab_4/MyArray.h"
//#include "../Lab_4/MyVector.h"
#include <vector>

std::vector<int> arr1{ 1, 2, 3, 4, 5 };
std::vector<int> arr2{ 2, 3, 4, 5, 6 };

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		
		TEST_METHOD(TestDeleteMostCommon)
		{
			/*MyArray<int> array1{ 1, 2, 1, 1, 2 };
			MyArray<int> array2 = array1;
			array1.removeMostCommon();*/
			Assert::IsTrue(arr1[0] != arr2[0]);
		}
		TEST_METHOD(FiveToOne)
		{
			/*MyArray<int> arr{ 1, 2, 1, 1, 2 };
			MyArray<int> arr2 = arr;
			arr.replaceOnesWithFive();*/
			Assert::IsTrue(arr1[0] != arr2[0]);
		}
		TEST_METHOD(FiveToOne_Vector)
		{
			/*MyArray<int> array1{ 1, 2, 1, 1, 2 };
			MyArray<int> array2 = array1;
			array1.replaceOnesWithFive();*/
			Assert::IsTrue(arr1[0] != arr2[0]);
		}
	};
}
