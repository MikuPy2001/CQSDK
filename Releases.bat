@echo off

del /s /q %~dp0\CQAPP.zip
mkdir %~dp0\CQAPP\

echo --------------���ڸ��� APP �������--------------
copy %~dp0\CQAPP.sln %~dp0\CQAPP\
copy %~dp0\SdkConfig.props %~dp0\CQAPP\

echo --------------���ڸ��� APP ��Ŀ�ļ�--------------
copy %~dp0\CQ_APP\*.vcxproj %~dp0\CQAPP\CQ_APP\
copy %~dp0\CQ_APP\*.filters %~dp0\CQAPP\CQ_APP\
copy %~dp0\CQ_APP\*.user %~dp0\CQAPP\CQ_APP\

echo --------------���ڸ��� APP Դ��--------------
mkdir %~dp0\CQAPP\CQ_APP\
copy %~dp0\CQ_APP\*.h %~dp0\CQAPP\CQ_APP\
copy %~dp0\CQ_APP\*.cpp %~dp0\CQAPP\CQ_APP\


echo --------------���ڸ��� SDKͷ�ļ�--------------
mkdir %~dp0\CQAPP\CQ_SDK\
copy %~dp0\CQ_SDK\*.h %~dp0\CQAPP\CQ_SDK\

echo --------------���ڸ��� SDK���ļ�--------------
mkdir %~dp0\CQAPP\CQ_LIB\
copy %~dp0\CQ_LIB\*.lib %~dp0\CQAPP\CQ_LIB\
copy %~dp0\CQ_LIB\*.pdb %~dp0\CQAPP\CQ_LIB\


echo --------------���ڸ��� ���𹤾�CQJSON--------------
copy %~dp0\..\cqsdk-json\bin\Release\CQ_Json.exe %~dp0\CQAPP\
copy %~dp0\..\cqsdk-json\bin\Release\Newtonsoft.Json.dll %~dp0\CQAPP\

echo --------------������β--------------
echo ^> ���ing...
bandizip c CQAPP.zip CQAPP
echo ^> �ļ����ɳɹ�:%~dp0\CQAPP.zip
echo ^> ɾ����ʱ�ļ�ing...
rd /s /q %~dp0\CQAPP\
echo ^> Releases��������: Done.
PAUSE>nul