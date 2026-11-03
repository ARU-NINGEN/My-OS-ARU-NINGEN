# 1. ソースコードをオブジェクトファイルにコンパイル
gcc -c main.c -o main.o

# 2. ヘッダーを剥がして純粋な機械語（バイナリ）に変換
objcopy -O binary main.o main.bin
