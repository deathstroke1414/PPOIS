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
    string name = human.getName();
    int age = human.getAge();
    EXPECT_EQ(name, "John Doe");
    EXPECT_EQ(age, 30);
    human.setFIO("Johny Doe");
    human.setAge(31);
    name = human.getName();
    age = human.getAge();
    EXPECT_EQ(name, "Johny Doe");
    EXPECT_EQ(age, 31);
}

TEST(BuilderTest, Tools) {
    Builder builder("Sasha", 40, 8, 6000, { "во", "ып" });
    builder.setTools({ "drill", "saw" });
    ASSERT_EQ(builder.getTools().size(), 2);
}

TEST(OfficeWorkerTest, SetOfficeNumber) {
    OfficeWorker officeWorker("German", 28, 3, 6000, 101);
    officeWorker.displayInfo();
    officeWorker.setOfficeNumber(102);
    EXPECT_EQ(officeWorker.getOfficeNumber(), 102);
}

TEST(ApartmentTest, SetFloorAmount) {
    Apartment apartment;
    apartment.displayInfo();
    apartment.setBicycleParking(true);
    apartment.setGarbageChute(false);
    apartment.setFloorAmount(5);
    EXPECT_EQ(apartment.getFloorAmount(), 5);
}

TEST(CottageTest, SetBedroomsAmount) {
    Cottage cottage;
    cottage.setBedroomsAmount(3);
    cottage.displayInfo();
    EXPECT_EQ(cottage.getBedroomsAmount(), 3);
}

TEST(ObjectTest, TestMethods) {
    Object object;
    Worker* worker = new Worker("Joe", 18, 99, 132.1);
    worker->displayInfo();
    worker->getSalary();
    int expected = 99;
    EXPECT_EQ(expected, worker->getExperience());
    object.getId();
    object.displayInfo();
    object.addWorker(worker);

    EXPECT_EQ(object.getWorkers().size(), 1);
}


TEST(PrivateHouseTest, ParametersTest) {
    PrivateHouse prHouse;
    prHouse.displayInfo();
    prHouse.setRoomsAmount(3);
    prHouse.setBathroomsAmount(1);

}

TEST(ResidentialBuildingTest, ParametersTest) {
    ResidentialBuilding resBuilding;
    resBuilding.displayInfo();
    resBuilding.setGasPresence(false);
    resBuilding.setHeater(true);
    bool actual = resBuilding.getGasPresence();
    bool expected = false;
    EXPECT_EQ(expected, actual);
}

TEST(PrivateHouseTest, DisplayInfo) {
    PrivateHouse house;
    // Ожидается, что метод просто выведет информацию о частном доме без ошибок
    ASSERT_NO_THROW(house.displayInfo());
}

TEST(CottageTest, DefaultConstructor) {
    Cottage cottage;

    // Ожидаем, что все значения по умолчанию установлены правильно
    ASSERT_EQ(cottage.getBedroomsAmount(), 0);
}

// Тестирование метода displayInfo
TEST(CottageTest, DisplayInfo) {
    Cottage cottage;
    // Ожидаем, что метод просто выведет информацию о коттедже без ошибок
    ASSERT_NO_THROW(cottage.displayInfo());
}