@echo off

echo --------------���� ��ʼ�� �������--------------
rd /s /q %~dp0\CQAPP\
del /s /q %~dp0\CQAPP.zip
mkdir %~dp0\CQAPP\
IF %ERRORLEVEL% NEQ 0 PAUSE

echo --------------���ڸ��� APP �������--------------
copy %~dp0\CQAPP.sln %~dp0\CQAPP\
IF %ERRORLEVEL% NEQ 0 PAUSE
copy %~dp0\SdkConfig.props %~dp0\CQAPP\
IF %ERRORLEVEL% NEQ 0 PAUSE

echo --------------���ڸ��� APP ��Ŀ�ļ�--------------
mkdir %~dp0\CQAPP\CQ_APP\
IF %ERRORLEVEL% NEQ 0 PAUSE
copy %~dp0\CQ_APP\*.vcxproj %~dp0\CQAPP\CQ_APP\
IF %ERRORLEVEL% NEQ 0 PAUSE
copy %~dp0\CQ_APP\*.filters %~dp0\CQAPP\CQ_APP\
IF %ERRORLEVEL% NEQ 0 PAUSE
copy %~dp0\CQ_APP\*.user %~dp0\CQAPP\CQ_APP\
IF %ERRORLEVEL% NEQ 0 PAUSE

echo --------------���ڸ��� APP Դ��--------------
copy %~dp0\CQ_APP\*.h %~dp0\CQAPP\CQ_APP\
IF %ERRORLEVEL% NEQ 0 PAUSE
copy %~dp0\CQ_APP\*.cpp %~dp0\CQAPP\CQ_APP\
IF %ERRORLEVEL% NEQ 0 PAUSE


echo --------------���ڸ��� SDKͷ�ļ�--------------
mkdir %~dp0\CQAPP\CQ_SDK\
IF %ERRORLEVEL% NEQ 0 PAUSE
copy %~dp0\CQ_SDK\*.h %~dp0\CQAPP\CQ_SDK\
IF %ERRORLEVEL% NEQ 0 PAUSE

echo --------------���ڸ��� SDK���ļ�--------------
mkdir %~dp0\CQAPP\CQ_LIB\
IF %ERRORLEVEL% NEQ 0 PAUSE
copy %~dp0\CQ_LIB\*.lib %~dp0\CQAPP\CQ_LIB\
IF %ERRORLEVEL% NEQ 0 PAUSE
copy %~dp0\CQ_LIB\*.pdb %~dp0\CQAPP\CQ_LIB\
IF %ERRORLEVEL% NEQ 0 PAUSE


echo --------------���ڸ��� ���𹤾�CQJSON--------------
copy %~dp0\..\cqsdk-json\bin\Release\CQ_Json.exe %~dp0\CQAPP\
IF %ERRORLEVEL% NEQ 0 PAUSE
copy %~dp0\..\cqsdk-json\bin\Release\Newtonsoft.Json.dll %~dp0\CQAPP\
IF %ERRORLEVEL% NEQ 0 PAUSE

echo --------------������β--------------
echo ^> ���ing...
bandizip c CQAPP.zip CQAPP
IF %ERRORLEVEL% NEQ 0 PAUSE
echo ^> �ļ����ɳɹ�:%~dp0\CQAPP.zip
echo ^> ɾ����ʱ�ļ�ing...
rd /s /q %~dp0\CQAPP\
echo ^> Releases��������: Done.
PAUSE>nul