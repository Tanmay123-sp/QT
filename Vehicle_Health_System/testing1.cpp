#include<gtest/gtest.h>
#include"mainwindow.h"
#include"filter_details.h"
#include"fluid_details.h"
#include"api.h"
#include<vector>

using namespace::testing;

// TEST(test1,WhengetFilterListisCalledThenCheckList){
//     api obj;

//     std::vector<Filter_details*> ExpectedVec ;

//     QStringList filterNames = {"Cabin Air Filter", "Oil Filter", "Fuel Filter"};

//     for (const QString& name : filterNames) {

//         Filter_details* newFilter = new Filter_details(name,100);
//         // newFilter->setName(name);
//         // newFilter->setStatus(status);

//         newFilter->setCurrentDate(QDate::currentDate());
//         ExpectedVec.push_back(newFilter);
//         // Filter_details::addFilterDetailsToList(newFilter);
//     }
//     EXPECT_EQ(ExpectedVec.size(),obj.getFilterList().size());
//     }

// TEST(test1,WhengetFluidListisCalledThenCheckList){
//     api obj;

//     std::vector<Fluid_details*> ExpectedVec ;

//     QStringList fluidNames = {"Cabin Air Filter", "Oil Filter", "Fuel Filter"};

//     for (const QString& name : fluidNames) {
//         Fluid_details* newFluid = new Fluid_details();
//         newFluid->setName(name);
//         newFluid->setStatus(100);
//         newFluid->setCurrentDate(QDate::currentDate());
//         // Fluid_details::addFluidDetailsToList(newFluid);
//     }
//     EXPECT_EQ(ExpectedVec.size(),obj.getFluidList().size());
// }


class testing1 : public ::testing ::Test{
protected:
    testing1(){

        filter=new Filter_details();
        fluid = new Fluid_details();
    }
    ~testing1(){
        delete filter;
        delete fluid;
    }
    Filter_details *filter;
    Fluid_details *fluid;
};

// TEST_F(testing1,WhengetNameisCalledThenReturnCorrectName){
//     void name = ptrFilter->setName("Tanmay");
//     QString ExpectedName = "Tanmay";
//     EXPECT_EQ(ExpectedName,name);

// }

TEST_F(testing1, WhenSetterfunctionIsCalledCheckitwithCorrectValues) {

    Filter_details* filter1 = new Filter_details("New Filter",2);
    // filter->setName("New Filter");
    // filter->setStatus(2);
    filter1->setCurrentDate(QDate(2023, 4, 29));

    EXPECT_EQ(filter1->getName(), "New Filter");
    EXPECT_EQ(filter1->getStatus(), 2);
    EXPECT_EQ(filter1->getCurrentDate(), QDate(2023, 4, 29));

}

TEST_F(testing1, WhenSetStatusIsCalledThenCheckIfItIsCorrect) {
    // Test the setStatus method
    Filter_details* filter = new Filter_details("Test Filter", 5);
    Filter_details* result = filter->setStatus(3);

    EXPECT_EQ(filter->getStatus(), 2);
    EXPECT_EQ(result, filter);

}

TEST_F(testing1, WhenCreateAndAddFilterDetailsIsCalledThenCheckIt) {
    // Test the createAndAddFilterDetails method
    QStringList names = {"Filter A", "Filter B", "Filter C"};
    int status = 3;

    Filter_details::createAndAddFilterDetails(names, status);

    EXPECT_EQ(Filter_details::FilterList.size(), 3);
    for (int i = 0; i < Filter_details::FilterList.size(); ++i) {
        EXPECT_EQ(Filter_details::FilterList[i]->getName(), names[i]);
        EXPECT_EQ(Filter_details::FilterList[i]->getStatus(), status);
        EXPECT_EQ(Filter_details::FilterList[i]->getCurrentDate(), QDate::currentDate());
    }

    // Clean up the memory
    for (Filter_details* filter : Filter_details::FilterList) {
        delete filter;
    }
    Filter_details::FilterList.clear();
}

//fluid test

TEST_F(testing1, WhenSetterfunctionOfFluidIsCalledCheckitwithCorrectValues) {
    // Test the getter and setter methods
    Fluid_details* fluid1 = new Fluid_details("New Fluid",2);

    // fluid->setName("New Fluid");
    // fluid->setStatus(2);
    fluid1->setCurrentDate(QDate(2023, 4, 29));

    EXPECT_EQ(fluid1->getName(), "New Fluid");
    EXPECT_EQ(fluid1->getStatus(), 2);
    EXPECT_EQ(fluid1->getCurrentDate(), QDate(2023, 4, 29));

}

TEST_F(testing1, WhenSetStatusofFluidisCalledCheckValue) {
    // Test the setStatus method

    Fluid_details* result = new Fluid_details("New Fluid",5);
    // Fluid_details* value = new Fluid_details();
    result->setStatus(3);
    EXPECT_EQ(result->getStatus(), 2);
    // EXPECT_EQ(result->getStatus(), value);

    delete result;
    // delete value;

}

TEST_F(testing1, WhenAddFluidDetailsToListTestIsCalledCheckIfItIsCorrect) {
    // Test the addFluidDetailsToList method
    Fluid_details* fluid1 = new Fluid_details();
    Fluid_details* fluid2 = new Fluid_details();

    Fluid_details::addFluidDetailsToList(fluid1);
    Fluid_details::addFluidDetailsToList(fluid2);

    EXPECT_EQ(Fluid_details::FluidList.size(), 2);
    EXPECT_EQ(Fluid_details::FluidList[0], fluid1);
    EXPECT_EQ(Fluid_details::FluidList[1], fluid2);

    // Clean up the memory
    // for (Fluid_details* fluid : Fluid_details::FluidList) {
    //     delete fluid;
    // }
    Fluid_details::FluidList.clear();
}

// TEST_F(testing1, WhenCreateAndAddFluidDetailsisCalledThenCheck) {
//     // Test the createAndAddFluidDetails method
//     QStringList names = {"Fluid A", "Fluid B", "Fluid C"};
//     int status = 3;

//     Fluid_details::createAndAddFluidDetails(names, status);

//     EXPECT_EQ(Fluid_details::FluidList.size(), 3);
//     for (int i = 0; i < Fluid_details::FluidList.size(); ++i) {
//         EXPECT_EQ(Fluid_details::FluidList[i]->getName(), names[i]);
//         EXPECT_EQ(Fluid_details::FluidList[i]->getStatus(), status);
//         EXPECT_EQ(Fluid_details::FluidList[i]->getCurrentDate(), QDate::currentDate());
//     }

//     // Clean up the memory
//     // for (Fluid_details* fluid : Fluid_details::FluidList) {
//     //     delete fluid;
//     // }
//     Fluid_details::FluidList.clear();
// }
