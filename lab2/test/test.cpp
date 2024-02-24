#include "C:\PPOIS\2курс 3 сем\laba2\laba2\Human.cpp"
#include "C:\PPOIS\2курс 3 сем\laba2\laba2\Builder.cpp"
#include "C:\PPOIS\2курс 3 сем\laba2\laba2\OfficeWorker.cpp"
#include "C:\PPOIS\2курс 3 сем\laba2\laba2\ResidentialBuilding.cpp"
#include "C:\PPOIS\2курс 3 сем\laba2\laba2\Apartment.cpp"
#include "C:\PPOIS\2курс 3 сем\laba2\laba2\Cottage.cpp"
#include "C:\PPOIS\2курс 3 сем\laba2\laba2\Object.cpp"
#include "C:\PPOIS\2курс 3 сем\laba2\laba2\Worker.cpp"
#include "C:\PPOIS\2курс 3 сем\laba2\laba2\PrivateHouse.cpp"
#include "gtest/gtest.h"
#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>
#include <string>

using namespace std;

TEST(HumanTest, DisplayInfo) {
    Human human("John Doe", 30);
    testing::internal::CaptureStdout();
    human.displayInfo();
    string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "This is a human.\n");
}

TEST(BuilderTest, Tools) {
    Builder builder("Sasha", 40, 8, 6000, { "во", "ып" });
    builder.setTools({ "drill", "saw" });
    ASSERT_EQ(builder.getTools().size(), 2);
}

TEST(OfficeWorkerTest, SetOfficeNumber) {
    OfficeWorker officeWorker("German", 28, 3, 6000, 101);
    officeWorker.setOfficeNumber(102);
    EXPECT_EQ(officeWorker.getOfficeNumber(), 102);
}

TEST(ApartmentTest, SetFloorAmount) {
    Apartment apartment;
    apartment.setFloorAmount(5);
    EXPECT_EQ(apartment.getFloorAmount(), 5);
}

TEST(CottageTest, SetBedroomsAmount) {
    Cottage cottage;
    cottage.setBedroomsAmount(3);
    EXPECT_EQ(cottage.getBedroomsAmount(), 3);
}
