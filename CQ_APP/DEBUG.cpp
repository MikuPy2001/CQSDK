


//本文件讲述如何在开发阶段捕获可能存在的报错
//本篇章是高级篇章



//要求如下:
//1.修改设置 [菜单栏]->[项目]->[CQ_APP 属性]
//            ->[C/C++]->[代码生成]->[启用C++异常]
//            ->改为[是,但有SHE异常(/EHa)
//2.在代码中尽量不要使用C++的异常,否则行为未定义



//启用方法
//1.首先定义如下常量
//#define CQDEBUG
//2.正常导入CQSDK.h
#include <CQSDK.h>
//3.由于本模式下会导入Windows.h,
//  所以请将CQSDK.h放在导入列表尾部,
//  以免发生各种意外.



EVE_GroupMsg_EX(Throwable) {
	//使用CQTry和CQTryEnd包围住可能会出现异常的代码
	//CQTry
	int i = 0;
	int o = 0 / i;//除0异常
	//CQTryEnd(Throwable,异常)
}
//请不要在正式发布文件中使用本代码
