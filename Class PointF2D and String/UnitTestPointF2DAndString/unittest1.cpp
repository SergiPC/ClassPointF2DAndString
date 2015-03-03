#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Class PointF2D and String/PointF2D.cpp"
#include "../Class PointF2D and String/String.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestPointF2DAndString
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Test_operatorMinus)
		{
			PointF2D t, f, p;
			p.x = p.y = f.x = f.y = 3;
			t = p - f;

			Assert::IsTrue(t.x == 0 && t.y == 0);
		}

		TEST_METHOD(Test_operatorPlus)
		{
			PointF2D t, f, p;
			t = p + f;

			Assert::IsTrue(p.x + f.x == t.x && p.y + f.y == t.y);
		}

		TEST_METHOD(TestMethod_operatorPlusEqual)
		{
			PointF2D f, p;
			f.x = 5.0f;
			f.y = 6.0f;
			p.x = 7.0f;
			p.y = 8.0f;

			f += p;

			Assert::AreEqual(f.x, 12.0f && p.y, 14.0f);
		}

		TEST_METHOD(TestMethod_operatorMinusEqual)
		{
			PointF2D f, p;
			f.x = 8.0f;
			f.y = 7.0f;
			p.x = 6.0f;
			p.y = 5.0f;

			f -= p;

			Assert::AreEqual(f.x, 2.0f && p.y, 2.0f);
		}

		TEST_METHOD(TestMethod_operatorEqualEqual)
		{
			PointF2D f, p;
			f.x = 5.0f;
			f.y = 6.0f;
			p.x = 5.0f;
			p.y = 6.0f;

			Assert::IsTrue(f == p);
		}

		TEST_METHOD(TestMethod_operatorNotEqual)
		{
			PointF2D f, p;
			f.x = 5.0f;
			f.y = 6.0f;
			p.x = 7.0f;
			p.y = 8.0f;

			Assert::IsTrue(f != p);
		}

		TEST_METHOD(TestMethod_isZero)
		{
			PointF2D p;
			p.x = p.y = 0.0f;

			Assert::IsTrue(p.isZero());
		}

		TEST_METHOD(TestMethod_setZero)
		{
			PointF2D p;
			p.setZero();

			Assert::IsTrue(p.isZero());
		}

		TEST_METHOD(TestMethod_distanceTo)
		{
			PointF2D f, p;
			f.x = 0;
			f.y = 0;
			p.x = 2;
			p.y = 0;

			Assert::IsTrue(f.distanceTo(p) == 2);
		}

		// - - - - - - - - - - - - [String] - - - - - - - - - - - 

		TEST_METHOD(Test_constructEmpty)
		{
			String* s = new String;

			Assert::IsTrue(s->size == 1);
			Assert::AreEqual(s->str, "");
		}

		TEST_METHOD(Test_constructFormat)
		{
			String* s = new String("hello", " world");

			Assert::AreEqual(s->size, 6);
			Assert::AreEqual(s->str, "hello");
		}

		TEST_METHOD(Test_constructCopy)
		{
			String s = "hello";
			String* a = new String(s);

			Assert::IsTrue(a->size == 6);
			Assert::AreEqual(a->str, "hello");
		}

		TEST_METHOD(Test_Destructors)
		{
			String* s = new String("hello");
			s->~String();

			Assert::IsTrue(s->str == NULL);
		}

		TEST_METHOD(Test_operatorEqualEqual)
		{
			String* s = new String("hello");

			Assert::IsTrue(*s == "hello");
		}

		TEST_METHOD(Test_operatorEqualEqualClass)
		{
			String* s = new String("hello");
			String* a = new String("hello");

			Assert::IsTrue(*s == *a);			
		}

		TEST_METHOD(Test_operatorNotEqual)
		{
			String* s = new String("hello");

			Assert::IsTrue(*s != "hello");
		}

		TEST_METHOD(Test_operatorNotEqualClass)
		{
			String* s = new String("hello");
			String* a = new String("world");

			Assert::IsTrue(*s != *a);
		}

		TEST_METHOD(Test_operatorEqual)
		{
			String* s = new String();

			*s = "hello";

			Assert::IsTrue(s->str == "hello");
		}

		TEST_METHOD(Test_operatorEqualClass)
		{
			String* s = new String("hello");
			String* a = new String();

			a = s;

			Assert::IsTrue(a->str == "hello");
		}

		TEST_METHOD(Test_operatorPlusEqual)
		{
			String* s = new String("hello");

			*s = " world";

			Assert::IsTrue(s->str == "hello world");
		}

		TEST_METHOD(Test_operatorPlusEqualClass)
		{
			String* s = new String("hello");
			String* a = new String(" world");

			*a += *s;

			Assert::IsTrue(s->str == "hello world");
		}

		TEST_METHOD(Test_operatorLength)
		{
			String* s = new String("hello");

			Assert::IsTrue(s->length() == 5);
		}

		TEST_METHOD(Test_operatorCapacity)
		{
			String* s = new String("hello");

			Assert::IsTrue(s->capacity() == 6);
		}

		TEST_METHOD(Test_operatorGetString)
		{
			String* s = new String("hello");

			Assert::IsTrue(s->getString() == "hello");
		}

		TEST_METHOD(Test_operatorClear)
		{
			String* s = new String("hello");
			s->clear();

			Assert::AreEqual(s->str, "");
		}
	};
}