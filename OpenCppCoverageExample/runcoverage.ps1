# カバレッジをバイナリで出力する
OpenCppCoverage-x64/OpenCppCoverage.exe --sources=ConsoleApp --sources=Shared --export_type=binary:ConsoleApp.cov -- Debug/ConsoleApp.exe
OpenCppCoverage-x64/OpenCppCoverage.exe --sources=ConsoleApp2 --sources=Shared --export_type=binary:ConsoleApp2.cov -- Debug/ConsoleApp2.exe
# カバレッジレポートのマージ
OpenCppCoverage-x64/OpenCppCoverage.exe --input_coverage=ConsoleApp.cov --input_coverage=ConsoleApp2.cov
