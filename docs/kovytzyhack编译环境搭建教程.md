##kovytzyhack编译环境搭建教程

### 0x01 准备工具
##### 下载 https://pan.baidu.com/s/1tjFW5EHMZfxa0xKfC7cLEg 提取码：m73h
![doc1.png](https://gitee.com/hackrom/kovytzyhack/raw/master/images/doc1.png "doc1.png")

### 0x02 安装CMAKE
##### 直接双击默认安装，我安装以下位置
![doc2.png](https://gitee.com/hackrom/kovytzyhack/raw/master/images/doc2.png "doc2.png")

### 0x03 安装m68k-elf-gcc
##### 直接双击默认安装，我安装以下位置
![doc3.png](https://gitee.com/hackrom/kovytzyhack/raw/master/images/doc3.png "doc3.png")

### 0x04 安装python
##### 直接双击默认安装，我安装以下位置
![doc4.png](https://gitee.com/hackrom/kovytzyhack/raw/master/images/doc4.png "doc4.png")

### 0x05 配置环境
##### 点在“我的电脑”右击，选择“属性”
![doc5.png](https://gitee.com/hackrom/kovytzyhack/raw/master/images/doc5.png "doc5.png")
![doc6.png](https://gitee.com/hackrom/kovytzyhack/raw/master/images/doc6.png "doc6.png")
![doc7.png](https://gitee.com/hackrom/kovytzyhack/raw/master/images/doc7.png "doc7.png")

##### 最终我们要把cmake、m68k-elf-gcc和pthon的路径写入path里面，以分号分隔，如下面的字符串所示。
`C:\Python27;C:\Program Files\CMake\bin;C:\SysGCC\m68k-elf\bin;`

### 0x06 验证编译环境
##### 进入运行界面，输入cmd
![doc8.png](https://gitee.com/hackrom/kovytzyhack/raw/master/images/doc8.png "doc8.png")
##### 测试cmake是正常，如下图所示
![doc9.png](https://gitee.com/hackrom/kovytzyhack/raw/master/images/doc9.png "doc9.png")
##### 测试make是正常，如下图所示
![doc10.png](https://gitee.com/hackrom/kovytzyhack/raw/master/images/doc10.png "doc10.png")
##### 测试python是正常，如下图所示
![doc11.png](https://gitee.com/hackrom/kovytzyhack/raw/master/images/doc11.png "doc11.png")

### 0x07 编译代码
##### 进入工程，双击build.bat
![doc12.png](https://gitee.com/hackrom/kovytzyhack/raw/master/images/doc12.png "doc12.png")
##### 如果显示下图所示，表示编译成功
![doc13.png](https://gitee.com/hackrom/kovytzyhack/raw/master/images/doc13.png "doc13.png")
##### libkov.exe和libkov.dll，需要自行放置工程里，最终生成的rom文件就是ytzy_v201cn_o.rom
![doc14.png](https://gitee.com/hackrom/kovytzyhack/raw/master/images/doc14.png "doc14.png")

##### 心林，2020-03-11
