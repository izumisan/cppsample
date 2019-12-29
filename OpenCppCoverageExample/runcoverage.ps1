$env:PATH = "OpenCppCoverage-x64;" + "$env:PATH"

# カバレッジをバイナリで出力する
OpenCppCoverage.exe --sources=ConsoleApp --sources=Shared --export_type=binary:ConsoleApp.cov -- Debug/ConsoleApp.exe
OpenCppCoverage.exe --sources=ConsoleApp2 --sources=Shared --export_type=binary:ConsoleApp2.cov -- Debug/ConsoleApp2.exe
# カバレッジレポートのマージ
OpenCppCoverage.exe --input_coverage=ConsoleApp.cov --input_coverage=ConsoleApp2.cov
