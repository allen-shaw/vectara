# Vim Setting

## Shortcut Key

### Normal Mode

#### Move

1. 数字+hjkl: 跳过多行移动
2. w, b: 往前/后跳一个单词，同样 数字+w/b 跳过n个字符
3. $: 行尾字符; ^: 行首字符; 0: 行首
4. G: 最后一行; gg: 首行
5. {: 上一段; }: 下一段
6. 数字n+gg: 跳到某一行
7. /[pattern] + enter + n/N: 查找

#### Copy/Cut And Paste

1. dd/yy: 剪切/复制当前行; 数字+dd/yy: 剪切/复制n行
2. p: 粘贴到下一行

### Insert Mode

1. i: 进入insert mode; I: 跳到行头同时进入insert mode(类似于^+i); A: 跳到行尾进入insert mode
2. o: insert到下一行; O: insert到上一行
3. u: undo; Ctrl+r: redo
4. ESC: 退出insert mode, 建议将ESC mapping到 jk
5. c+ NAVIGATION: 删除到NAVIGATION的地方. 比如c+w/b删除前后一个单词,c+$/^删除到行尾/首
6. c+iw: 删除当前词
7. d + NAVIGATION: 剪切到NAVIGATION的地方. 比如c+w/b剪切前后一个单词,c+$/^剪切到行尾/首;d+iw:剪切当前词
  
### Command Mode

1. 使用":"进入command mode
2. %/A/B/g: 将所有A替换成B
  
### Visual Mode

#### Visual line mode: 一般用在多行缩进处理

### 退出Vim

1. :w/:q/:wq 退出并保存
2. :wqa 退出所有窗口


# 一些概念

## Operator

1. d: delete
2. c: change
3. y: copy

## Motion

$, ^, G, gg 等

## Leader Key

一般是remap成空格键
