#include "item.h"
#include "item19/temporary_obj.h"

void CItem::test_item_9()
{
    
}

void copyTest(const CTemporaryObj& obj)
{
    std::cout << "Enter copyTest with const parameter" << std::endl;
    std::cout << "The address of obj is " << &obj << std::endl;
}

void copyTest2(CTemporaryObj& obj)
{
    std::cout << "Enter copyTest" << std::endl;
    std::cout << "The address of obj is " << & obj << std::endl;
}

void CItem::test_item_19()
{
    // function out of class
    copyTest(3);
    // copyTest2(4);
    // class's inner function, success
    CTemporaryObj obj(3);
    std::cout << "Is same" << obj.IsSame(3) << std::endl;
}

CTemporaryObj returnTmpTest()
{
    CTemporaryObj tmpObj(5);
    return tmpObj;
}

void CItem::test_item_20()
{
    // CTemporaryObj obj1(6);
    CTemporaryObj tmpObj = returnTmpTest();
}

void CItem::test_item_24()
{
    CTemporaryObj obj1(1);
    CTemporaryObj obj2(2);

    // typedef void(*Fun)(void);
    std::cout << (int)(*(int*)&obj1) << std::endl;
    // Fun pFun1 = (Fun)*((int*)*(int*)(&obj1) + 1);
    // pFun1();
    std::cout << (int)(*(int*)&obj2) << std::endl;
}
