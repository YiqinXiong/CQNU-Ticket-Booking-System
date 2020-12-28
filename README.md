# CQNU-Ticket-Booking-System
演唱会门票订票系统

## 整体思路 & 数据结构

分成 `client` 、 `concert` 和 `myTool` 三个类：

1. `myTool`  类
   - 私有一个 `vector<concert> L` 容器，用来顺序存放所有的`concert`（演唱会）类
   - 私有一个`Name` 字符串，用来存放当前登录用户的用户名
2. `concert` 类
   - 私有一个 `list<client> clist` 容器，用来存放该 `concert` （该场演唱会）的顾客
   - 私有一个 `list<client> wlist` 容器，用来存放该 `concert` （该场演唱会）的候补订票顾客
3. `client` 类
   - 存放顾客姓名 `name`、订票张数 `ordering_number` 和席位 `grade`
   - 为方便 list 容器中的 `remove` 方法的实现，重载了 `client` 类的 `==` 运算符

## main 函数结构

建立 `while(1)` 主循环，用于各程序功能的分支跳转。

## 数据存储与持久化

- 初始化类时加载文件中数据到内存中（如 vector、list等容器）

- 修改后调用类中自定义的方法将内存中数据持久化到磁盘文件中，保证磁盘文件和内存中数据的一致性，且断电和程序退出不丢失数据

