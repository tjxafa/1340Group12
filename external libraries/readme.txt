[Versions that support MinGW]
TDM-GCC version 4.8.1 and above, supporting 32-bit and 64-bit.

[Compiler Versions Supported]
IDEs using TDM-GCC 4.8.1 and above are supported. For example:
● Code::Blocks 13.12 or later
● DevCpp version 5.8.0 and above
Also additionally supported are
● DevCpp 5.4.0 GCC MinGW 4.7.2 (C/C++ programming environment for students in the 13th Blue Bridge Cup Competition)
● C-Free 5.0 (built-in GCC MinGW 3.4.5)

[File List]
include header file
lib32 32-bit library files
lib64 64-bit library files
lib-for-devcpp_5.4.0 only for DevCpp 5.4.0 MinGW 4.7.2 and C-Free 5.0

[Installation method]
Copy the header files in the include folder and the library files in the lib32/lib64 folder to the header files and library files folders of MinGW respectively, add the link option: -leasyx, and then compile.
For detailed steps, please refer to: https://go.easyx.cn/easyx-for-mingw


EasyX for MinGW
ver：20220901
------------------------------------

[支持 MinGW 的版本]
TDM-GCC 4.8.1 及以上版本，支持 32 位和 64 位。

[支持编译器的版本]
使用 TDM-GCC 4.8.1 及以上版本的集成开发环境都可以支持。例如：
● Code::Blocks 13.12 及以上版本
● DevCpp 5.8.0 及以上版本
同时额外支持：
● DevCpp 5.4.0 GCC MinGW 4.7.2（第十三届蓝桥杯大赛学生机 C/C++ 编程环境）
● C-Free 5.0（内置 GCC MinGW 3.4.5）

[文件列表]
include			头文件
lib32			32 位库文件
lib64			64 位库文件
lib-for-devcpp_5.4.0	仅适用于 DevCpp 5.4.0 MinGW 4.7.2 和 C-Free 5.0

[安装方法]
将 include 文件夹下的头文件和 lib32/lib64 文件夹下的库文件，分别拷贝到 MinGW 的头文件和库文件文件夹中，链接选项增加：-leasyx，然后编译即可。
详细步骤请参考：https://go.easyx.cn/easyx-for-mingw
