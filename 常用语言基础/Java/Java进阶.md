目标

- [ ] 能够理解注释、关键字、常量的概念并使用

- [ ] 理解变量的概念，并能够正确定义和使用

- [ ] 熟记`Java`的八种数据类型 以及其 取值范围

- [ ] 理解类型转换的概念并能够正确应用类型转换

- [ ] 理解标识符的概念，能够正确定义标识符

----

##### 面向对象

1. 类与对象

   1. 类

      - [ ] 属性

      - [ ] 行为

   2. 抽象：就是提取相同属性和行为的过程

   3. 对象：某一类事物的某个具体存在

2. 类的定义和使用

   - [ ] 属性 = 成员变量
   - [ ] 行为 = 成员方法
   - [ ] 使用  ： 类名 对象名 = new 类名
   - [ ] <font color=red>P95 , 96, 97  类的创建过程的内存图解</font>
   - [ ] 引用其实是传递地址值
   - [ ] 使用变量遵循就近原则，如果没有就去本类的成员变量那里找，然后去父类那里找
   - [ ] 成员变量和局部变量的区别
     - [ ]  定义位置：
       - [ ] 成员变量：类中，方法外
       - [ ] 局部变量：方法中，或 形式参数
     - [ ]  初始化值 ： 
       - [ ] 成员变量：有默认初始化值
       - [ ] 局部变量：无默认初始化值，必须先赋值再使用
     - [ ]  作用范围：
       - [ ] 成员变量：在类中
       - [ ] 局部变量：在方法中
     - [ ]   内存位置：
       - [ ] 成员变量 ： 堆内存【堆：创建对象的】
       - [ ] 局部变量 ： 栈内存【栈：调用方法】
     - [ ]  生命周期：
       - [ ] 成员变量 ： 随着对象的创建而存在，随着对象的消失而消失
       - [ ] 局部变量 ：随着方法的调用而存在，随着方法的调用完毕而消失
     - [ ] 如果重名：采用就近原则

3. 封装概述

   - [ ] 功能打包到设备中，提供使用这些功能的界面
   - [ ] 安全性：
   - [ ] 复用性：
   - [ ] 简单化：

4. private关键字

   私有的，一种访问权限修饰符，用来修饰类的成员

   特点：被修饰的成员只能在本类中访问

   用法：

   - [ ] private 数据类型 变量名
   - [ ] private 返回值类型 方法名 （参数列表 ） { }【】

   如果在其他类中访问private 数据 ：类中提供公共的访问方式

   一般 private 用来修饰 成员对象

   一般 public 用来修饰 成员方法

5. this关键字

   this 表示本类对象的引用，避免 局部变量和 成员变量的重名，`this.age` 表示是成员变量

   每一个普通方法都有一个this，谁调用方法，this就指向谁

   使用：

   - [ ] this.属性名 :
   - [ ] this.方法名（参数） ：

6. 标准代码： `JavaBean`

   构造方法：用来初始化对象

   - [ ] ```java
     /**
     修饰符 构造方法名 (参数列表){
     	// 方法体
     }
     
     要求 ：
     1. 方法名 必须 和 类名相同 (包括大小写)
     2. 没有返回值
     3. 没有返回值类型
     
     注意事项：
     1. 若未提供任何构造方法，系统会给出默认无参构造
     2. 若已提供任何构造方法，系统不再提供无参构造
     3. 构造方法可以重载
     */
     ```

   标准代码：`java`语言编写类的标准规范，符合`JavaBean`标准的类，必须是具体的、公共的，并且具有无参数的构造方法，提供用来操作成员变量的 set 和 get 方法

   `java` 中封装的概念： 将一系列相关事物共同属性和行为提取出来，放到一个类中，隐藏对象的属性和实现细节，仅对外提供公共的访问方式。

   封装的关键是：决不能让类中的方法直接访问其他类的数据（属性），程序仅通过对象的方法与对象的数据进行交互

7. 继承

   基本概念

   - [ ] 什么是继承

     类与类之间产生父子关系，被继承的叫基类、超类、父类；继承的叫子类、派生类。

   - [ ] 使用场景

     多个类存在相同的属性和行为时，提高代码复用，

     extends

   - [ ] 优缺点

     - 优点：功能复用、便于扩展新功能、结构清晰，简化认识，易维护性
     - 缺点：打破了封装性、高耦合性

   - [ ] 继承关系中类成员的使用

     1. 成员变量的使用

        子父类中都定义了同名的成员变量，如何使用？<font color=red>就近原则</font>

         使用本类 `this.price`

         使用父类`super.price`   <font color=red>也可以调用方法super.方法( )</font>

     2. this 和 super的区别

        this <font color=red>本质是对象</font>

        super<font color=red> 父类内存空间的标识</font> 

   - [ ] 方法重写

     <font color=red>方法名、参数列表、返回值类型</font>都相同

     父类私有方法不能重写

     <font color=blue>子类方法访问权限不能小于父类方法</font> private -> 默认 -> protected  ->  public

     <font color=red>子类不能抛出比父类更大的异常</font>

   - [ ] Java中继承的特点

     

   成员特点

   - [ ] 成员变量 【<font color=red>this 和 super的区别</font>】
   - [ ] 成员方法 【<font color=red>重载与重写的区别</font>】
   - [ ] 构造方法 

   重点

   - [ ] 继承之后，类发生了什么变化

     <font color=red>子类拥有了父类的非私有成员（成员变量、成员方法）</font>

   - [ ] 继承关系中对象是怎么创建的？

   - [ ] Java中继承的特点是什么，这样设计的好处有哪些？

   代码编写

   - [ ] 定义类与类的继承关系并使用

   - [ ] super关键字的使用

   - [ ] `java`中四种访问权限的使用

     private -> 默认 -> protected  ->  public

     

     |           | 本类 | 本包 | 子类 | 其他类 |
     | --------- | ---- | ---- | ---- | ------ |
     | private   | √    |      |      |        |
     | 默认      | √    | √    |      |        |
     | protected | √    | √    | √    |        |
     | public    | √    | √    | √    | √      |

8. <font color=red>多态</font>

   - [ ] 多态的概述

     同一对象在不同情况下表现出不同的状态或行为

     <font color=red>Java中实现多态的步骤</font>

     > 要有继承（或实现）关系
     >
     > 要有方法重写  (加  @Override )
     >
     > 父类引用指向子类对象（is a 关系） Animal a = new Dog( );

     <font color=red>父类引用指向子类对象的内存图</font>

     >  Animal a = new Dog( );
     >
     > 多态中调用成员方法是
     >
     >  【编译看左】：左边的类型有没有这个成员
     >
     > 【运行看右】：运行时具体用的是右边类中的该成员

   - [ ] 多态的使用场景及其内存图解

     父类可以作为形参的类型，这样可以接收其任意子类对象。

     <font color=red>P122 多态关系中成员方法内存图</font>

     多态中父类和子类成员变量同名怎么办？

     > 成员变量不能重写，该是谁的就是谁的
     >
     > Animal  a = new Dog( );    `//  a.name = Animal`
     >
     > 【编译看左】：
     >
     > 【运行看左】：

     <font color=red>P123 多态关系中成员变量内存图</font>

   - [ ] 多态的好处和弊端

     好处：

     >  可维护性
     >
     >  可扩展性

     坏处：

     > 父类不能使用子类的特有方法
     >
     > 除非【类型转换】

     类型转换的注意事项

     > 只能在继承层次内进行转换
     >
     > 将父类对象转换成子类之前，使用 `instanceof` 进行检查
     >
     >  `instanceof` : 测试它左边的对象是否是它右边的类的实例 
     >
     > `if (animal instanceof Dog)`
     >
     > {
     >
     > ​	Dog dog = (Dog) animal;  // 类型转换
     >
     > }

   - [ ] 抽象类概述

     有一些行为方法，具体对象都要有不同的重写，那就在父类中先不写，占个位置，抽象方法

     当需要定义一个方法，却不缺名

     含有抽象方法的类就是抽象类，【只有方法声明，没有方法体的方法】

     用abstract描述

     `public abstract class Animal{ }`

   - [ ] 抽象类的特点

     抽象类的特点

     >  修饰符：
     >
     > ​	必须abstract 关键字修饰：修饰class 以及 方法名
     >
     > 抽象类不能被实例化
     >
     > ​	所以可以通过创建其子类对象来完成初始化操作
     >
     > 抽象类子类的两个选择：
     >
     > ​	如果是普通类，需要重写父类的所有抽象方法
     >
     > ​	如果是抽象类，则不用重写抽象方法

     抽象类成员的特点

     - [ ] <font color=red>成员变量</font>

       可以有普通的成员变量

       也可以有成员常量（final 修饰）

     - [ ] <font color=red>成员方法</font>

       可以有普通方法，也可以有抽象方法

       抽象类不一定有抽象方法，有抽象方法的类一定是抽象类（或接口）

     - [ ] <font color=red>构造方法</font>

       像普通类一样有构造方法，且可以重载

       <font color=red>重载</font>的意思是：无参构造函数 + 有参构造函数

       子类可以用父类的构造方法，也可以自己写，用快捷键 alt + insert

   - [ ] final关键字

     用来修饰类、方法、变量

     > final 类：不能被继承的，但是可以继承别人
     >
     > final方法：不能被重写
     >
     > final变量：常量，

   - [ ] static关键字

     用来修饰类的成员

     > 成员变量：类变量
     >
     > ​	               被本类所有对象共享, 大家都是中国人，国家属性就不要一个个写了
     >
     > ​        注意：修改有风险，所以加 final，一般是公共的静态常量
     >
     > ​					public final static String NAME=" " ; 
     >
     > 成员方法：类方法【静态方法】
     >
     > ​		特点：没有this关键字，不能访问非静态成员。
     >
     > ​        使用场景：只需要访问静态成员；不需要访问对象状态，所需参数都由参数列表提供			                   

     调用方式：

     > 不要先 new 出对象，直接 类名.方法（）就可以访问	

   - [ ] 接口概述

     用于描述类具有什么功能，但并不给出具体实现，类要遵从接口描述的统一规则进行定义，所以，接口是对外提供的一组规则、标准。

     <font color=red>接口不能实例化</font>

     接口的定义

     > 使用关键字 interface ： interface 接口名{ }
     >
     > 类和接口之间是实现关系，用implements表示：class 类名 implements 接口名
     >
     >  
     >
     >  接口属于 扩展，谁要实现什么功能就去实现什么接口，不是共性内容

   - [ ] 接口成员的特点

     成员变量

     > 有默认 public abstract final

     成员方法

     > `JDK` 7及以前，公有的、抽象方法：
     >
     > public abstract 返回值类型  方法名（）
     >
     > `JDK` 8以后，可以由默认方法和静态方法：【很多类实现的时候接口代码一样，可以使用默认方法】
     >
     > static 返回值类型 方法名()
     >
     > default 返回值类型 方法名()
     >
     > `JDK` 9以后，可以有私有方法：【私有方法只能在接口里面用，用来帮助实现接口中其他方法，属于其他方法的 【公共部分】】
     >
     > private 返回值类型 方法名（） 

9. Java常用工具之<font color=red>`API`</font>

   理解什么是`API`

   > Java 中 API 指的是 `API文档`

   使用：

   >  使用步骤：
   >
   > 1. 查找类
   > 2. 查看模块名
   > 3. 查看构造方法
   > 4. 找到符合需要的方法
   > 5. 根据方法创建对象并使用

   Java 中组件的层次结构

   模块 -> 包 -> 类或接口

   举例:

   > 顶层父类：Object
   >
   > ​	`hashCode( ) ` 返回对象的哈希码值，该方法通过对象的地址值进行计算，不同对象的返回值一般不同
   >
   > ​	`getClass()` 返回调用此方法对象的运行时类对象（调用者的字节码文件对象）同一个类字节码文件一样
   >
   > ​	`String toString( )` 返回该对象的字符串表示  
   >
   > ​              `getClass().getName() + '@' + Integer.toHexString(hashCode())`
   >
   > ​	boolean equals( ) 返回其它某个对象是否与此对象“相等”。默认情况下比较两个对象的引用，建议重写
   >
   > 控制台录入：Scanner
   >
   > 。。。
   >
   > 字符串处理：String
   >
   > 。。。
   >
   > 字符串处理：`StringBuilder`  和 `StringBuffer`
   >
   > 可变字符序列；StringBuilder 快于 StringBuffer
   >
   > 
   >
   > 日期获取：Data 和 Calendar
   >
   > 基本类型的包装类
   >
   > 1. 装箱
   > 2. 拆箱
   >
   > 成员方法：
   >
   > ​	static 基本类型  ` parseXXX(String)`  ：把字符串转换为其他类型
   >
   > ​	把字符串转换为其他类型

   ```java
   int a = 10;
   Integer i1 = new Integer(a);  // 装箱
   int b = i1.intValue();        // 拆箱
   //---------------------------------------
   Integer i2 = 30;              // JDK5 之后自动拆装箱
   int c = i2;
   //----------------------------------------
   String a = "10";
   int num = Integer.parseInt(a);  // 除了Character类以外，其他包装类都有parseXXX（）方法
   System.out.println("num :" + (num + 100));  
   ```

   `JavaBean`类中重写Object类的方法

   ```java
   // 定义标准 java bean 类Student，属性: id,name,score
   
   // 重写 toString():
   //      该对象的字符串表现形式，一般都是包含所有属性值且具有一定的格式的字符串
   
   // 重写equals(): 比较属性值相不相同
   ```

   <font color=red>通过快捷键的方法生成</font>

   `右键 -> Generate -> equals() and hashCode ->选择模板`

10. Java常用工具之<font color=red>集合</font>

    ![1587033023515](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1587033023515.png)

    ![1587033099055](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1587033099055.png)

    什么是集合？

    常用集合

    > List
    >
    > Set
    >
    > Map

    根据`API`文档使用步骤查找集合类

    > 查找集合类
    >
    > 查看该集合所属接口名
    >
    > 查看构造方法
    >
    > **创建集合对象**
    >
    > **创建元素对象**
    >
    > **添加元素到集合中**
    >
    > **遍历集合**

    代码

    > 记住集合体系中各接口集合的特点
    >
    > 练习集合的基本操作

    集合简介

    - [ ] 集合和数组的区别：

      > 元素类型：
      >
      > ​	集合：引用类型（存储基本类型时自动装箱）
      >
      > ​    数组：基本类型、引用类型
      >
      > 元素个数：
      >
      > ​    集合：不固定
      >
      > ​    数组：固定
      >
      > 集合的好处：不收容器大小限制。

      Java 集合的体系结构

      > 单列集合:
      >
      > ​	Collection：
      >
      > ​         List ( 接口 ) : `ArrayList` （子类）
      >
      > ​	     Set ( 接口 ): `HashSet`  （子类）
      >
      > 双列集合：
      >
      > ​	Map ( 接口 ): `HashMap`

    - [ ] List 集合的特点和应用

      > 特点：可重复、有序（存取顺序相同）
      >
      > 应用：`List list = new ArrayList( ) ;`
      >
      > 

    - [ ] 增强`for` 循环和迭代器

    - [ ] 泛型简介

    - [ ] Collections 工具类

    - [ ] Set 集合的特点

    - [ ] Map 集合的特点和应用

11. Java常用工具之<font color=red>`IO`流</font>