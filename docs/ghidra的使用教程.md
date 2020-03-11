## ghidra的使用教程

### 0x01 下载Ghidra
##### 从地址 https://github.com/NationalSecurityAgency/ghidra/releases 下载
##### 目前我下载了ghidra_9.1-BETA_DEV 版本，解压如下图所示
![doc15.png](https://gitee.com/hackrom/kovytzyhack/raw/master/images/doc15.png "doc15.png")

### 0x02 安装java环境
##### 目前我下载了jdk-11.0.1_windows-x64_bin.zip这个版本，直接解压到C盘即可，如下图所示
![doc16.png](https://gitee.com/hackrom/kovytzyhack/raw/master/images/doc16.png "doc16.png")

### 0x03 运行Ghidra
##### 点击下图ghidraRun.bat，即可以运行
![doc17.png](https://gitee.com/hackrom/kovytzyhack/raw/master/images/doc17.png "doc17.png")
##### 会弹出下图，提示输入回车键
![doc18.png](https://gitee.com/hackrom/kovytzyhack/raw/master/images/doc18.png "doc18.png")
##### 按了回车键后，会弹出下图所示，然后选择java的环境，即C:\jdk-11.0.1，点击打开
![doc19.png](https://gitee.com/hackrom/kovytzyhack/raw/master/images/doc19.png "doc19.png")
##### 然后，点击“同意”
![doc20.png](https://gitee.com/hackrom/kovytzyhack/raw/master/images/doc20.png "doc20.png")
![doc21.png](https://gitee.com/hackrom/kovytzyhack/raw/master/images/doc21.png "doc21.png")

### 0x04 用Ghidra加载游戏ROM
##### 按照下图所示，新建工程
![doc22.png](https://gitee.com/hackrom/kovytzyhack/raw/master/images/doc22.png "doc22.png")
##### 选择好工程目录（自己创建目录 ）
![doc23.png](https://gitee.com/hackrom/kovytzyhack/raw/master/images/doc23.png "doc23.png")
##### 工程建好了，然后把游戏文件ytzy_v201cn_d.rom ，拖到工程里，如下图所示
![doc24.png](https://gitee.com/hackrom/kovytzyhack/raw/master/images/doc24.png "doc24.png")
##### 接着，选择CPU的型号，如下图所示
![doc25.png](https://gitee.com/hackrom/kovytzyhack/raw/master/images/doc25.png "doc25.png")
##### 接着输入基地址0x100000，如下图所示
![doc26.png](https://gitee.com/hackrom/kovytzyhack/raw/master/images/doc26.png "doc26.png")
##### 最后，点击OK，即配置完成。
![doc27.png](https://gitee.com/hackrom/kovytzyhack/raw/master/images/doc27.png "doc27.png")

### 0x05 Ghidra反汇编代码
##### 如下图所示，点击那个图片，就可以进入反汇编界面。
![doc28.png](https://gitee.com/hackrom/kovytzyhack/raw/master/images/doc28.png "doc28.png")
##### 下图就是自动分析汇编，编译C代码。
![doc29.png](https://gitee.com/hackrom/kovytzyhack/raw/master/images/doc29.png "doc29.png")
##### 按G键，跳到地址0x1a0f12，去修改warring的字样。
![doc30.png](https://gitee.com/hackrom/kovytzyhack/raw/master/images/doc30.png "doc30.png")

##### 心林，2020-03-10
