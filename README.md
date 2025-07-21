# ADS1256的STM32驱动，基于STM32F407和HAL

作者使用了CMake环境编译，若使用Keil Arm MDK，请使用根目录下的`ADS1256.ioc`重新生成MDK环境下的代码。

## 项目结构

```bash
ADS1256_STM32hal
├─.vscode           #编译配置、编译任务、调试任务等
├─ADS1256           #核心驱动
├─cmake             #Cube MX自动生成的cmake文件
│  └─stm32cubemx
└─Core              #主程序
   ├─Inc
   └─Src
```
