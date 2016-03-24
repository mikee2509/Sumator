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
	Liczba pierwsza(16, 6, 4, 1, 5, 4, 8, 4), druga(16, 6, 14, 7, 15, 1, 6, 7);
	Liczba wynik = pierwsza + druga;
	EXPECT_EQ(1, wynik.getDigitOfNumber(0).getDigit());
	EXPECT_EQ(2, wynik.getDigitOfNumber(1).getDigit());
	EXPECT_EQ(9, wynik.getDigitOfNumber(2).getDigit());
	EXPECT_EQ(4, wynik.getDigitOfNumber(3).getDigit());
	EXPECT_EQ(5, wynik.getDigitOfNumber(4).getDigit());
	EXPECT_EQ(14, wynik.getDigitOfNumber(5).getDigit());
	EXPECT_EQ(11, wynik.getDigitOfNumber(6).getDigit());
	EXPECT_EQ("01020904051411", wynik.toString());
	EXPECT_EQ(1020904051411, wynik.toLongLong());
	for (int i = 0; i < 7; i++) {
		EXPECT_EQ(false, wynik.getDigitOfNumber(i).getCarry());
		EXPECT_EQ(16, wynik.getDigitOfNumber(i).getBase());
	}

	pierwsza = Liczba(2, 9, 1, 0, 1, 1, 0, 1, 1, 1, 0);
	druga = Liczba(2, 12, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0);
	wynik = pierwsza + druga;
	EXPECT_EQ("110111001010", wynik.toString());
	EXPECT_EQ(110111001010, wynik.toLongLong());
	for (int i = 0; i < 12; i++) {
		EXPECT_EQ(false, wynik.getDigitOfNumber(i).getCarry());
		EXPECT_EQ(2, wynik.getDigitOfNumber(i).getBase());
	}

	pierwsza = Liczba(255, 4, 225, 34, 98, 236);
	druga = Liczba(255, 4, 159, 205, 1, 59);
	wynik = pierwsza + druga;
	EXPECT_EQ("001129239100040", wynik.toString());
	EXPECT_EQ(1129239100040, wynik.toLongLong());
	for (int i = 0; i < 4; i++) {
		EXPECT_EQ(false, wynik.getDigitOfNumber(i).getCarry());
		EXPECT_EQ(255, wynik.getDigitOfNumber(i).getBase());
	}
}

TEST(TestingLiczba, LiczbaSetMethodes)
{
	Liczba nowa(100, 4, 99, 98, 97, 96);
	nowa.setNumberL(1129239100040, 255);
	EXPECT_EQ(1, nowa.getDigitOfNumber(0).getDigit());
	EXPECT_EQ(129, nowa.getDigitOfNumber(1).getDigit());
	EXPECT_EQ(239, nowa.getDigitOfNumber(2).getDigit());
	EXPECT_EQ(100, nowa.getDigitOfNumber(3).getDigit());
	EXPECT_EQ(40, nowa.getDigitOfNumber(4).getDigit());

	nowa.setNumber(11010, 2);
	EXPECT_EQ(1, nowa.getDigitOfNumber(0).getDigit());
	EXPECT_EQ(1, nowa.getDigitOfNumber(1).getDigit());
	EXPECT_EQ(0, nowa.getDigitOfNumber(2).getDigit());
	EXPECT_EQ(1, nowa.getDigitOfNumber(3).getDigit());
	EXPECT_EQ(0, nowa.getDigitOfNumber(4).getDigit());
}
