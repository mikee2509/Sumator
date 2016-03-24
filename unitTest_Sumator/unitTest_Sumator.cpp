#include "gtest/gtest.h"
#include "main.h"
#include "liczba.h"
#include "cyfra.h"

TEST(TestingCyfra, CyfraConstructor)
{
	Cyfra nowa = Cyfra(8,16);
	EXPECT_EQ(8, nowa.getDigit());
	EXPECT_EQ(16, nowa.getBase());
	EXPECT_EQ(false, nowa.getCarry());

	Cyfra druga(100, 150, true);
	EXPECT_EQ(true, druga.getCarry());
}

TEST(TestingCyfra, CyfraSetMethodes)
{
	Cyfra nowa(12, 16);
	nowa.setDigit(100);
	EXPECT_EQ(12, nowa.getDigit());
	nowa.setDigit(15);
	EXPECT_EQ(15, nowa.getDigit());
	nowa.setBase(13);
	EXPECT_EQ(16, nowa.getBase());
	nowa.setBase(254);
	EXPECT_EQ(254, nowa.getBase());
}

TEST(TestingCyfra, CyfraOperatorOverload)
{
	Cyfra pierwsza(18, 25), druga(9, 25);
	Cyfra wynik = pierwsza + druga;
	EXPECT_EQ(2, wynik.getDigit());
	EXPECT_EQ(25, wynik.getBase());
	EXPECT_EQ(true, wynik.getCarry());

	pierwsza.setDigit(1);
	wynik = pierwsza + druga;
	EXPECT_EQ(10, wynik.getDigit());
	EXPECT_EQ(25, wynik.getBase());
	EXPECT_EQ(false, wynik.getCarry());

	pierwsza = Cyfra(1, 101);
	wynik = pierwsza + druga;
	EXPECT_EQ(0, wynik.getDigit());
	EXPECT_EQ(2, wynik.getBase());
	EXPECT_EQ(false, wynik.getCarry());
}

TEST(TestingLiczba, LiczbaConstructor)
{
	Liczba nowa(16);
	EXPECT_EQ(16, nowa.getBase());
	EXPECT_EQ(NULL, nowa.ptrDigitOfNumber(0));

	nowa = Liczba(16, 3, 8, 10, 2);
	EXPECT_EQ(16, nowa.getBase());
	EXPECT_EQ(8, nowa.getDigitOfNumber(0).getDigit());
	EXPECT_EQ(10, nowa.getDigitOfNumber(1).getDigit());
	EXPECT_EQ(2, nowa.getDigitOfNumber(2).getDigit());
	EXPECT_EQ(NULL, nowa.ptrDigitOfNumber(3));
	for (int i = 0; i < 3; i++) {
		EXPECT_EQ(false, nowa.getDigitOfNumber(i).getCarry());
		EXPECT_EQ(16, nowa.getDigitOfNumber(i).getBase());
	}
		
	nowa = Liczba(16, 2, 8, 16, 2);
	EXPECT_EQ(16, nowa.getBase());
	EXPECT_EQ(8, nowa.getDigitOfNumber(0).getDigit());
	EXPECT_EQ(0, nowa.getDigitOfNumber(1).getDigit());
	EXPECT_EQ(NULL, nowa.ptrDigitOfNumber(2));
	for (int i = 0; i < 2; i++) {
		EXPECT_EQ(false, nowa.getDigitOfNumber(i).getCarry());
		EXPECT_EQ(16, nowa.getDigitOfNumber(i).getBase());
	}

	nowa = Liczba(16, 4, 1);
	EXPECT_EQ(16, nowa.getBase());
	EXPECT_EQ(1, nowa.getDigitOfNumber(0).getDigit());
	for (int i = 1; i < 4; i++) {
		EXPECT_EQ(0, nowa.getDigitOfNumber(i).getDigit());
		EXPECT_EQ(false, nowa.getDigitOfNumber(i).getCarry());
		EXPECT_EQ(16, nowa.getDigitOfNumber(i).getBase());
	}
}

TEST(TestingLiczba, LiczbaOperatorOverload)
{
	Liczba pierwsza(2, 4, 1, 0, 0, 1), druga(2, 3, 1, 1, 1);
	Liczba wynik = pierwsza + druga;
	EXPECT_EQ(10000, wynik.toLong());
}

