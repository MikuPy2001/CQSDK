


# CQSDK
- 自主知识产权
- 基于VC++
- 下载即用
- 不含有任何依赖
- 基于官方SDK 9.18

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



## 历史归档
[DOCS](https://mikupy2001.github.io/CQSDK/DOCS/index.html "DOCS")


## 当前目标

1. CQMsgCode 重写

2. winSpeak 继续支持

3. 下列函数未有EX版本
    ```
    #define	EVE_GroupUpload(Name)
    #define	EVE_System_GroupMemberDecrease(Name)
    #define	EVE_System_GroupMemberIncrease(Name)
    ```

4. 首页文档
