# 回车科技iOS情感计算本地算法SDK

- [回车科技iOS情感计算本地算法SDK](#回车科技ios情感计算本地算法sdk)
  - [版本需求](#版本需求)
  - [安装](#安装)
    - [Swift Package Manager](#swift-package-manager)
  - [使用](#使用)
    - [使用流程](#使用流程)
    - [头文件引用](#头文件引用)
    - [接口头文件查看](#接口头文件查看)
    - [初始化SDK](#初始化sdk)
    - [设置授权信息](#设置授权信息)
      - [授权失败](#授权失败)
    - [实时数据计算](#实时数据计算)
      - [数据转化](#数据转化)
      - [心率计算](#心率计算)
      - [双通道脑电计算](#双通道脑电计算)
      - [单通道脑电计算](#单通道脑电计算)
      - [压电压阻计算](#压电压阻计算)
    - [报表获取](#报表获取)
      - [心率报表](#心率报表)
      - [双通道脑电报表](#双通道脑电报表)
      - [单通道脑电报表](#单通道脑电报表)
      - [压电压阻报表](#压电压阻报表)
      - [睡眠报表](#睡眠报表)
      - [放松度报表](#放松度报表)
      - [注意力报表](#注意力报表)
      - [压力报表](#压力报表)
      - [心流报表](#心流报表)
      - [和谐度报表](#和谐度报表)
      - [愉悦度报表](#愉悦度报表)
      - [激活度报表](#激活度报表)
  - [注意事项](#注意事项)


回车情感计算根据回车产品采集的脑电、心率以及压电压阻进行数据分析，同时能给出包括：放松度、注意力、愉悦值，压力值、激动度（内测）在内的多种情绪情感值。详情请查看[官网](https://www.entertech.cn/)。

在开始开发前，请先查看回车[开发文档](https://docs.affectivecloud.com/)，了解情感计算算法所能提供的服务具体说明，确定好你的应用中所需要的服务。你还需要联系管理员获取算法授权文件，然后再进行开发。

为了方便你进行 iOS 平台的快速开发，我们提供了情感云快速开发 SDK，通过本 SDK 你可以快速地将情感云的能力集成到你的 app 中。

## 版本需求
- iOS 14 及以上（不支持模拟器）
- Xcode 13 及以上
- Swift 5.5 及以上

## 安装
### Swift Package Manager

Package添加下面这行到你的 Package.swift：
```
.package(name: "Enter-Native-SDK-iOS", url: "https://github.com/Entertech/Enter-Native-SDK-iOS.git", from: "1.0.1")
```

Project添加下面的链接到你的 Package Dependencies 中：
```
https://github.com/Entertech/Enter-Native-SDK-iOS.git
```

## 使用

### 使用流程
SDK在使用过程中，按照 初始化->进行授权->实时数据计算->获取报表->释放（ARC自动释放） 的流程进行。

### 头文件引用
XCODE 13版本及以上创建的工程可以直接添加以下头文件：
```
import AffectiveAlgorithmSDK_iOS
```
早期版本工程可以在Bridge-Header.h中添加以下头文件：
```
#import <AffectiveAlgorithmSDK_iOS/AffectiveWrapper.h>
```

### 接口头文件查看
所有用到的接口和封装对象都在[AffectiveWrapper.h](https://github.com/Entertech/Enter-Native-SDK-iOS/blob/main/Sources/AffectiveAlgorithmSDK_iOS.xcframework/ios-arm64/AffectiveAlgorithmSDK_iOS.framework/Headers/AffectiveWrapper.h)中。

### 初始化SDK
`AffectiveHandler` 是整个 SDK 的入口类，你需要先初始化 `AffectiveHandler`。
```swift
class Demo {
    var handler: AffectiveHandler?
    
    init {
        handler = AffectiveHandler()
    }
    
    ......
}

```

### 设置授权信息
如果你获得了回车科技的授权，会得到一个授权文件`ENTERTECH_NATIVE_SDK_LICENSE.txt`，你需要将该文件加入工程，然后在初始化 SDK 之前设置授权信息：
```swift
    // 获取授权文件路径
    guard let path = Bundle.main.path(forResource: "ENTERTECH_NATIVE_SDK_LICENSE", ofType: "txt") else {
        return false
    }
    // 验证授权
    guard let auth = handler?.auth(fromBundle: path), auth else {
        //验证失败
        return false
    }

```

#### 授权失败
- 无法找到path
    - 如果加入了文件还是无法找到path，请检查是否添加了`Copy items if needed`和`Add to targets`。
- auth 返回false
    - 确认授权文件是否有改动。
    
### 实时数据计算
将蓝牙数据的回调`Data`类型数据传入，关于蓝牙部分请参考[回车蓝牙SDK](https://github.com/Entertech/Enter-Biomodule-BLE-iOS-SDK.git)

#### 数据转化
因为算法用Objective-C封装，需要对蓝牙传过来的`Data`类型转化才可使用，此处data为蓝牙回调数据。
```swift
    // 心率转化, 心率只有首个字节是有效数据
    let mutableArray = NSMutableArray()
    if let hr = data.first {
        mutableArray.add(NSNumber(value: hr))
    }
    
    // 脑波，压电压阻转化
    let mutableArray = NSMutableArray()
    data.forEach { byte in
        mutableArray.add(NSNumber(value: byte))
    }


```

#### 心率计算
心率累计3组数据数据进行一次计算并返回结果，不计算时返回nil。
```swift
    // 先判断是否可用， 未通过授权是不可用状态
    guard let hrEnable = handler?.getHREnable(), hrEnable else {
        return
    }
    if let result = handler?.appendHR(mutableArray) {
        // 此处对 result 进行处理, result 类型`HRAffectiveResOC` 在上方`接口头文件查看`可找到查看入口
    }
```

#### 双通道脑电计算
双通道脑电累计50组数据进行一次计算并返回结果，不计算时返回nil。
```swift
    // 先判断是否可用， 未通过授权是不可用状态
    guard let eegEnable = handler?.getEEGEnable(), eegEnable else {
        return
    }
    if let result = handler?.appendEEG(mutableArray) {
        // 此处对 result 进行处理, result 类型`EEGAffectiveResOC` 在上方`接口头文件查看`可找到查看入口
    }
```

#### 单通道脑电计算
单通道脑电累计30组数据进行一次计算并返回结果，不计算时返回nil。
```swift
    // 先判断是否可用， 未通过授权是不可用状态
    guard let sceegEnable = handler?.getSCEEGEnable(), sceegEnable else {
        return
    }
    if let result = handler?.appendSCEEG(mutableArray) {
        // 此处对 result 进行处理, result 类型`SCEEGAffectiveResOC` 在上方`接口头文件查看`可找到查看入口
    }
```

#### 压电压阻计算
压电压阻累计15组数据进行一次计算并返回结果，不计算时返回nil。
```swift
    // 先判断是否可用， 未通过授权是不可用状态
    guard let peprEnable = handler?.getPEPREnable(), peprEnable else {
        return
    }
    if let result = handler?.appendPEPR(mutableArray) {
        // 此处对 result 进行处理, result 类型`PEPRAffectiveResOC` 在上方`接口头文件查看`可找到查看入口
    }
```

### 报表获取
完成数据计算后可以获取报表，不进行计算直接获取报表，会得到空报表。

#### 心率报表
```swift
    // 先判断是否可用， 未通过授权是不可用状态
    guard let hrEnable = handler?.getHREnable(), hrEnable else {
        return
    }
    if let report = handler?.getHRReport() {
        // 此处对 report 进行处理, report 类型`HRReportResOC` 在上方`接口头文件查看`可找到查看入口
    }
```

#### 双通道脑电报表
```swift
    // 先判断是否可用， 未通过授权是不可用状态
    guard let eegEnable = handler?.getEEGEnable(), eegEnable else {
        return
    }
    if let report = handler?.getEEGReport() {
        // 此处对 report 进行处理, report 类型`EEGReprotResOC` 在上方`接口头文件查看`可找到查看入口
    }
```

#### 单通道脑电报表
```swift
    // 先判断是否可用， 未通过授权是不可用状态
    guard let sceegEnable = handler?.getSCEEGEnable(), sceegEnable else {
        return
    }
    if let report = handler?.getSCEEGReport() {
        // 此处对 report 进行处理, report 类型`SCEEGReportResOC` 在上方`接口头文件查看`可找到查看入口
    }
```

#### 压电压阻报表
```swift
    // 先判断是否可用， 未通过授权是不可用状态
    guard let peprEnable = handler?.getPEPREnable(), peprEnable else {
        return
    }
    if let report = handler?.getPEPRReport() {
        // 此处对 report 进行处理, report 类型`PEPRReportResOC` 在上方`接口头文件查看`可找到查看入口
    }
```

#### 睡眠报表
```swift
    // 先判断是否可用， 未通过授权是不可用状态
    guard let sleepEnable = handler?.getSleepEnable(), sleepEnable else {
        return
    }
    if let report = handler?.getSleepReport() {
        // 此处对 report 进行处理, report 类型`SleepReportResOC` 在上方`接口头文件查看`可找到查看入口
    }
```

#### 放松度报表
```swift
    // 先判断是否可用， 未通过授权是不可用状态
    guard let relaxEnable = handler?.getRelaxationEnable(), relaxEnable else {
        return
    }
    if let report = handler?.getRelaxationReport() {
        // 此处对 report 进行处理, report 类型`RelaxationReportResOC` 在上方`接口头文件查看`可找到查看入口
    }
```

#### 注意力报表
```swift
    // 先判断是否可用， 未通过授权是不可用状态
    guard let attentionEnable = handler?.getAttentionEnable(), attentionEnable else {
        return
    }
    if let report = handler?.getAttentionReport() {
        // 此处对 report 进行处理, report 类型`AttentionReportResOC` 在上方`接口头文件查看`可找到查看入口
    }
```

#### 压力报表
```swift
    // 先判断是否可用， 未通过授权是不可用状态
    guard let pressureEnable = handler?.getPressureEnable(), pressureEnable else {
        return
    }
    if let report = handler?.getPressureReport() {
        // 此处对 report 进行处理, report 类型`PressureReportResOC` 在上方`接口头文件查看`可找到查看入口
    }
```

#### 心流报表
```swift
    // 先判断是否可用， 未通过授权是不可用状态
    guard let flowEnable = handler?.getFlowEnable(), flowEnable else {
        return
    }
    if let report = handler?.getFlowReport() {
        // 此处对 report 进行处理, report 类型`FlowReportResOC` 在上方`接口头文件查看`可找到查看入口
    }
```

#### 和谐度报表
```swift
    // 先判断是否可用， 未通过授权是不可用状态
    guard let coherenceEnable = handler?.getCoherenceEnable(), coherenceEnable else {
        return
    }
    if let report = handler?.getCoherenceReport() {
        // 此处对 report 进行处理, report 类型`CoherenceReportResOC` 在上方`接口头文件查看`可找到查看入口
    }
```

#### 愉悦度报表
```swift
    // 先判断是否可用， 未通过授权是不可用状态
    guard let pleasureEnable = handler?.getPleasureEnable(), pleasureEnable else {
        return
    }
    if let report = handler?.getPleasureReport() {
        // 此处对 report 进行处理, report 类型`PleasureReportResOC` 在上方`接口头文件查看`可找到查看入口
    }
```

#### 激活度报表
```swift
    // 先判断是否可用， 未通过授权是不可用状态
    guard let arousalEnable = handler?.getArousalEnable(), arousalEnable else {
        return
    }
    if let report = handler?.getArousalReport() {
        // 此处对 report 进行处理, report 类型`ArousalReportResOC` 在上方`接口头文件查看`可找到查看入口
    }
```
## 注意事项
- 注意循环引用等问题引起内存无法释放，会导致内存溢出。
- 计算过程中释放可能会导致内存错误，请确保没有数据后（大约停止蓝牙给数据1秒后）再进行释放


