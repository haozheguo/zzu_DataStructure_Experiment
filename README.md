<div align="center">
  <p align="center">
    <h2>📚 zzu_DataStructure_Experiment</h2>
    <h2>🐑 郑州大学数据结构课程实验</h2>
</p>
  <div align='center'>
      <img src=https://img.shields.io/badge/Language-C++-brightgreen.svg >
      <img src=https://img.shields.io/github/forks/haozheguo/zzu_DataStructure_Experiment.svg?style=dark >
      <img src=https://img.shields.io/github/stars/haozheguo/zzu_DataStructure_Experiment.svg?style=dark >
      <img src=https://img.shields.io/badge/License-Apache-turquoise.svg >
  </div>
</div>

📚 **zzu\_DataStructure\_Experiment**: It is a repository for learning and practicing core data structures. It features implementations, examples, and test cases for arrays, linked lists, stacks, queues, trees, graphs, and more, helping users strengthen coding and algorithm skills.

♥️ Please consider to leave a ⭐️ Star to support me, my bro ~ ♥️

🐑 **zzu\_DataStructure\_Experiment**：是一个用于学习和练习核心数据结构的代码仓库。它包含zzu的所有数据结构实验，涉及数组、链表、栈、队列、树、图等多种数据结构的实现、示例和测试用例，帮助读者强化编程能力并提升算法思维。

♥️ 如果你觉得项目对你有用，请留下一个 ⭐️ Star来支持作者，不胜感激～ ♥️

## 🎨 实验代码配套博客解读


| 📖 实验名称                                                                                                   | 📖 博客链接                                                                                                                                              |
| :------------------------------------------------------------------------------------------------------------ | :------------------------------------------------------------------------------------------------------------------------------------------------------- |
| ✔️[exp01 顺序表的基本操作和实现](https://github.com/haozheguo/zzu_DataStructure_Experiment/tree/main/exp01) | [zzu数据结构实验（一）顺序表的基本操作和实现](https://blog.csdn.net/qq_60587145/article/details/152922364?spm=1001.2014.3001.5502)                       |
| ✔️[exp02 单链表的基本操作和实现](https://github.com/haozheguo/zzu_DataStructure_Experiment/tree/main/exp02) | [zzu数据结构实验（二）单链表的基本操作](https://blog.csdn.net/qq_60587145/article/details/153042030?spm=1001.2014.3001.5502)                             |
| ✔️[exp03 栈的基本操作和实现](https://github.com/haozheguo/zzu_DataStructure_Experiment/tree/main/exp03)     | [zzu数据结构实验（三）栈的基本操作（应用：括号匹配和中心对称检验）](https://blog.csdn.net/qq_60587145/article/details/153139975?spm=1011.2415.3001.5331) |
| ✔️[exp04 队列的基本操作和实现](https://github.com/haozheguo/zzu_DataStructure_Experiment/tree/main/exp04)   | [zzu数据结构实验（四） 队列的基本操作和实现（应用：中心对称检验）](https://blog.csdn.net/qq_60587145/article/details/153209129?spm=1001.2014.3001.5502)  |

## 💫 实验运行配置

&emsp;&emsp;这里以`exp01`为例，介绍如何进行实验运行配置。这里有两种方法执行，分别是`cmake方式`和`单独运行单个文件`：

### ✨ 方式1 cmake运行exp01程序

> ⚠️ 前提是电脑上已经正确配置c/c++环境和cmake工具。mac用户可参考我的博客：[MacBook使用杂记](https://blog.csdn.net/qq_60587145/article/details/152934108?sharetype=blogdetail&sharerId=152934108&sharerefer=PC&sharesource=qq_60587145&spm=1011.2480.3001.8118)

&emsp;&emsp;1️⃣ 首先打开终端，切换到项目目录，创建构建（build）目录:

```cpp
cd Path/To/exp01
mkdir build
cd build
```

&emsp;&emsp;2️⃣  接着运行CMake 生成构建文件并编译：

```cpp
cmake ..
make
```

&emsp;&emsp;3️⃣ 如果成功，会看到：

```bash
[100%] Built target SeqList.exe
```

&emsp;&emsp;4️⃣ 最后运行程序：编译完成后，在 build/ 目录中会生成一个可执行文件，执行运行命令：

```cpp
./SeqList.exe
```

### 🧠 方式2 单个cpp文件运行

> ⚠️ 以下命令适用于已经配置好c/c++编译的Mac系统。其他平台用户建议直接使用IDE（如Devc++、Vscode等）运行按钮运行。

&emsp;&emsp;1️⃣  打开终端，切换到项目目录，使用mac自带c++编译工具`clang++`编译：

```cpp
cd Path/To/exp01
clang++ -std=c++17 SeqListSingle.cpp -o SeqListSingle
```

&emsp;&emsp;2️⃣ 运行编译好的可执行程序`SeqListSingle`：

```cpp
./SeqListSingle
```

&emsp;&emsp;3️⃣ 若程序正确运行，得到以下实验结果：
![在这里插入图片描述](https://i-blog.csdnimg.cn/direct/01687137d0814a9fbad75aa1b824549c.png)
