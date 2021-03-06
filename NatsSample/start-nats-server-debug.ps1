# natsu-server起動スクリプト
$nats_server_program = "./nats-server-v2.1.8-windows-386/nats-server.exe"

# 引数なしで起動した場合、0.0.0.0:4222でリッスンする
# --addrオプションでリッスンするアドレスを指定できる
# --portオプションでリッスンするポートを指定できる
# Ctrl+Cで終了する
# --log <file> でログファイルに出力する
# --debug
# --trace
#Start-Process -FilePath $nats_server_program -ArgumentList "--addr 127.0.0.1 --port 4222" -NoNewWindow -Wait
Start-Process -FilePath $nats_server_program -ArgumentList "--addr 127.0.0.1 --port 4222 --debug --trace" -NoNewWindow -Wait
