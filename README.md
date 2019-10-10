


# CQSDK
- 自主知识产权
- 基于VC++
- 下载即用
- 不含有任何依赖
- 基于官方SDK 9.18
- 在事件里,e对象提供你想要的任何操作

## 上手指南
[下载](https://github.com/MikuPy2001/CQSDK/releases)后双击打开极速开始插件之旅

## 使用要求
- VS2019
- Windows SDK
- 平台工具集(v142)

## 如何生成
- 推荐直接查看appinfo.h跟着源码注释阅读
- 全部阅读并根据提示修改完毕后就可以尝试生成

## 部署
- SDK已经集成了部署工具CQJSON,编译即可完成部署
- 如不使用,请根据源码编写app.json并与项目生成的app.json一同放入酷Q指定目录

## 参考文献
- 你可以在[这里](https://mikupy2001.github.io/cqsdk-help/ "DOCS")查看SDK全部函数和类,以及帮助

## 高级部分
有的人会问,教练啊,VS好大啊,装不起啊,window SDK我也没有啊,平台工具集是个什么鬼啊.

那太棒了,这里喵可以教你如何构建自己的项目

首先,你的构建工具至少要支持以下2点
- C++11
- std

接下来简单一点,你只需要知道下载后的目录分别是干什么的就大功告成了

- CQ_APP 这是项目源码目录,包含有示例项目
- CQ_LIB 这是SDK预编译好的LIB,有发布版和debug版
- CQ_SDK 这是SDK头文件

只要在你的构建工具中将以上三个目录有机组织一下,喵相信难不倒聪明的你的

最后,请生成名称为APP的DLL文件,这是酷Q的规定

你也可以在你的构建工具中使用CQJSON.EXE用于构建JSON

使用方法如下

`CQ_Json.exe <CQ_APP目录> <DLL生成目录> (酷Q目录)`

酷Q目录参数通常不是必须,且会被源码中的宏替换

## 历史归档

当前目标

1. CQMsgCode 重写

2. winSpeak 继续支持

3. 下列函数未有EX版本
    ```
    #define	EVE_GroupUpload(Name)
    #define	EVE_System_GroupMemberDecrease(Name)
    #define	EVE_System_GroupMemberIncrease(Name)
    ```

4. 首页文档

5. 跟进到9.25
