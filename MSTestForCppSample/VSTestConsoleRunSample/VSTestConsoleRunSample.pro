TEMPLATE = lib
CONFIG += dll
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

VSUnitTestDir = "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\VS\UnitTest"
INCLUDEPATH += $${VSUnitTestDir}/include
LIBS += -L$${VSUnitTestDir}/lib

SOURCES += \
    baztest.cpp

#
# 実行設定に以下を設定することで、実行ボタンからのテスト実行可能
#
#　実行プログラム:
#   C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\Common7\IDE\CommonExtensions\Microsoft\TestWindow\vstest.console.exe
# コマンドライン引数:
#   VSTestConsoleRunSample.dll
# 作業ディレクトリ:
#   %{CurrentProject:BuildPath}\%{CurrentBuild:Type}
#
