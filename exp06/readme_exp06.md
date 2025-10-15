# 🚀 zzu数据结构实验（六） 哈夫曼树及哈夫曼编码算法实现

## 🌈 1 项目目录结构和cmake文件

&emsp;&emsp;项目在[zzu_DataStructure_Experiment](https://github.com/haozheguo/zzu_DataStructure_Experiment)目录下的exp06文件夹。对应的文件结构为：

```cpp
exp06/
├── Huffman.cpp        --> cmake项目函数实现文件
├── Huffman.h          --> cmake项目函数声明文件
├── main.cpp           --> cmake项目函数测试文件
├── CMakeLists.txt     --> cmake项目配置文件
├── HuffmanSingle.cpp  --> 单个完整的函数实现和测试文件
└── readme_exp06.md    --> exp06项目运行操作和结果记录文件
```

&emsp;&emsp;CMakeLists.txt文件为：

```cpp
cmake_minimum_required(VERSION 3.10)

project(zzu_exp06)

set(CMAKE_BUILD_TYPE Debug)

add_executable(Huffman Huffman.h Huffman.cpp main.cpp)
```

## 💫 2 实验运行配置和结果截图

&emsp;&emsp;有两种方法执行，分别是cmake方式和单独运行单个文件：

### ✨ 2.1 cmake运行程序

> ⚠️ 前提是电脑上已经正确配置c/c++环境和cmake工具。mac用户可参考我的博客：[MacBook使用杂记](https://blog.csdn.net/qq_60587145/article/details/152934108?sharetype=blogdetail&sharerId=152934108&sharerefer=PC&sharesource=qq_60587145&spm=1011.2480.3001.8118)

&emsp;&emsp;:one: 首先打开终端，切换到项目目录，创建构建（build）目录:

```cpp
cd Path/To/exp06
mkdir build
cd build
```

&emsp;&emsp;:two: 接着运行CMake 生成构建文件并编译：

```cpp
cmake ..
make
```

&emsp;&emsp;如果成功，会看到：

```bash
[100%] Built target Huffman
```

&emsp;&emsp;:three: 最后运行程序：编译完成后，在 build/ 目录中会生成一个可执行文件，执行运行命令：

```cpp
./Huffman
```

&emsp;&emsp;若程序正确运行，得到以下实验结果：
![在这里插入图片描述](https://i-blog.csdnimg.cn/direct/bb707a76817240148a3f8fe38f12c771.png)
![在这里插入图片描述](https://i-blog.csdnimg.cn/direct/08aa9f797e304e8caa757417842943d9.png)

### 🧠 2.2 单个cpp文件运行

> ⚠️ 以下命令适用于已经配置好c/c++编译的Mac系统。其他平台用户建议直接使用IDE（如Devc++、Vscode等）运行按钮运行。

&emsp;&emsp;:one: 打开终端，切换到项目目录，使用mac自带c++编译工具`clang++`编译：

```cpp
cd Path/To/exp06
clang++ -std=c++17 HuffmanSingle.cpp -o HuffmanSingle
```

&emsp;&emsp;:two: 运行编译好的可执行程序`HuffmanSingle`：

```bash
./HuffmanSingle
```

&emsp;&emsp;若程序正确运行，得到以下实验结果：
![在这里插入图片描述](https://i-blog.csdnimg.cn/direct/bb707a76817240148a3f8fe38f12c771.png)
![在这里插入图片描述](https://i-blog.csdnimg.cn/direct/08aa9f797e304e8caa757417842943d9.png)

