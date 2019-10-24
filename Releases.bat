@echo off

del /s /q %~dp0\CQAPP.zip
mkdir %~dp0\CQAPP\

echo --------------正在复制 APP 解决方案--------------
copy %~dp0\CQAPP.sln %~dp0\CQAPP\
copy %~dp0\SdkConfig.props %~dp0\CQAPP\

echo --------------正在复制 APP 项目文件--------------
copy %~dp0\CQ_APP\*.vcxproj %~dp0\CQAPP\CQ_APP\
copy %~dp0\CQ_APP\*.filters %~dp0\CQAPP\CQ_APP\
copy %~dp0\CQ_APP\*.user %~dp0\CQAPP\CQ_APP\

echo --------------正在复制 APP 源码--------------
mkdir %~dp0\CQAPP\CQ_APP\
copy %~dp0\CQ_APP\*.h %~dp0\CQAPP\CQ_APP\
copy %~dp0\CQ_APP\*.cpp %~dp0\CQAPP\CQ_APP\


echo --------------正在复制 SDK头文件--------------
mkdir %~dp0\CQAPP\CQ_SDK\
copy %~dp0\CQ_SDK\*.h %~dp0\CQAPP\CQ_SDK\

echo --------------正在复制 SDK库文件--------------
mkdir %~dp0\CQAPP\CQ_LIB\
copy %~dp0\CQ_LIB\*.lib %~dp0\CQAPP\CQ_LIB\
copy %~dp0\CQ_LIB\*.pdb %~dp0\CQAPP\CQ_LIB\


echo --------------正在复制 部署工具CQJSON--------------
copy %~dp0\..\cqsdk-json\bin\Release\CQ_Json.exe %~dp0\CQAPP\
copy %~dp0\..\cqsdk-json\bin\Release\Newtonsoft.Json.dll %~dp0\CQAPP\

echo --------------正在收尾--------------
echo ^> 打包ing...
bandizip c CQAPP.zip CQAPP
echo ^> 文件生成成功:%~dp0\CQAPP.zip
echo ^> 删除临时文件ing...
rd /s /q %~dp0\CQAPP\
echo ^> Releases发布助手: Done.
PAUSE>nul