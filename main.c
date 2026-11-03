// VGAテキストバッファの開始アドレス
#define VGA_ADDRESS 0xB8000

// 色属性（0x0F = 黒背景に明るい白文字）
#define WHITE_ON_BLACK 0x0F

void kmain(void) {
    // メモリ番地 0xB8000 をポインタとして扱う
    volatile char *video_memory = (volatile char *)VGA_ADDRESS;
    
    // 表示したい文字列
    const char *str = "Hello, world!";
    
    int i = 0;
    // 文字列の終わり（'\0'）まで1文字ずつ書き込む
    while (str[i] != '\0') {
        video_memory[i * 2]     = str[i];           // 文字データ
        video_memory[i * 2 + 1] = WHITE_ON_BLACK;  // 色データ
        i++;
    }

    // 処理が終わった後、CPUを停止状態にする
    while (1) {
        __asm__ __volatile__("hlt");
    }
}
