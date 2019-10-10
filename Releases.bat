mkdir %~dp0\CQAPP\
copy %~dp0\CQAPP.sln %~dp0\CQAPP\
copy %~dp0\SdkConfig.props %~dp0\CQAPP\

copy %~dp0\..\cqsdk-json\bin\Release\CQ_Json.exe %~dp0\CQAPP\
copy %~dp0\..\cqsdk-json\bin\Release\Newtonsoft.Json.dll %~dp0\CQAPP\


mkdir %~dp0\CQAPP\CQ_APP\
copy %~dp0\CQ_APP\*.h %~dp0\CQAPP\CQ_APP\
copy %~dp0\CQ_APP\*.cpp %~dp0\CQAPP\CQ_APP\
::1
copy %~dp0\CQ_APP\*.vcxproj %~dp0\CQAPP\CQ_APP\
copy %~dp0\CQ_APP\*.filters %~dp0\CQAPP\CQ_APP\
copy %~dp0\CQ_APP\*.user %~dp0\CQAPP\CQ_APP\


mkdir %~dp0\CQAPP\CQ_LIB\
copy %~dp0\CQ_LIB\*.lib %~dp0\CQAPP\CQ_LIB\


mkdir %~dp0\CQAPP\CQ_SDK\
copy %~dp0\CQ_SDK\*.h %~dp0\CQAPP\CQ_SDK\

bandizip c CQAPP.zip CQAPP