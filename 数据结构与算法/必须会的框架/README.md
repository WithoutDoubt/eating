- [ ] 滑动窗口
- [ ] 二叉堆
- [ ] 双指针判断环
- [ ] 二分法
- [ ] 二叉搜索树
  - [ ] 所有节点值加一
  - [ ] 判断两棵树是否完全相同
  - [ ] 判断是否是BST
  - [ ] 查找一个数是否存在
  - [ ] BST 插入一个数
  - [ ] BST删除一个数
- [ ] 单调栈
- [ ] 单调队列
- [ ] 递归反转链表
  - [ ] 
- [ ] 动态规划
  - [ ] 编辑距离
- [ ] 图的遍历框架
  - [ ] BFS
  - [ ] DFS
- [ ] 





---

#### 必须会的语法

- [ ] 动态数组

  ```c++
  vector<int> n ;
  
  n.push_back( m )          // 结尾添加元素
  n.pop_back()              // 结尾删除元素
  n.size()                  // 个数
  n.capacity();             // a最多可以到多大
  n.clear()                 // 清空
  n.empty()                 //    
  n.insert(a.begin()+1, [sizes], 5)  // 插入元素
  ```

  - [ ] 初始化

    ```c++
    vector<int> a(10);
    vector<int> a(10,1);
    vector<int> a(b);
    vector<int> a(b.begin(),b.begin()+3); // b也是vector
    
    int b[7]={1,2,3,4,5,6,7};
    vector<int> a(b.b+7);   
    ```

  - [ ] 二维数组

    ```c++
    vector<vector<int> > nn;  // 二维数组
    nn.push_back( b ); // b是vector
    ```

  - [ ] 常用算法

    ```c++
    reverse(a.begin(),a.end()); // 倒置
    sort(a.begin(),a.end(), [compareTo] ) //排列
    find(a.begin(),a.end());    
    ```

- [ ] 栈

  ```c++
  stack<T> s;                                    // 无迭代器。
  s.push(); // 元素压入
  s.top();  // 返回元素，不删除
  s.pop();  // 弹出，不返回值
  s.empty(); // 判断是否为空
  s.size(); // 元素个数
  ```

- [ ] 队列

  ```c++
  queue< T > q;                                   // 无迭代器
  q.push();  // 放入队列
  q.front(); // 返回第一个元素引用
  q.pop();   // 删除第一个元素
  q.empty();
  q.size();
  ```

- [ ] 哈希 语法

  ```c++
  unordered_map<int, int> m;   // 声明
  
  m.find(key)                 // 存在就返回 value, 不存在就返回 m.end()
  m[key];                     // 不存在的话，默认插入 [key:0]
  m.count(key)                // 是否存在key, 在的话返回 1， 否则为 0
  m.size()                    // 返回 数目    
  ```

- [ ] 排序 sort

  ```c++
  // c++
  void sort(first, last, compare);  // 默认是从小到大排序
  //
  bool compare (int a, int b){
      return a > b;   // > 表示从大到小， < 表示 从小到大
  }
  ```

- [ ] String

  - [ ] 截断string： C++
    - [ ] `substring(begin,end);`   [begin, end)  长度为 abs(end-begin)
    - [ ] `substr(start, [length] )`

- [ ] 链表

  ```c++
  struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(NULL){}  
  };
  ```

- [ ] 树

  - [ ] 二叉树

    ```c++
    struct ListNode {
      int val;
      ListNode* left;
      ListNode* right;  
      ListNode(int x):val(x),left(NULL),rigth(NULL){}  
    };
    ```

  - [ ] 二叉堆

    - [ ] 数组维护、上浮 & 下沉
    - [ ] 访问 父节点、左孩子、右孩子

    ```c++
    // 使用数组来维护  最大最小堆
    // 数组 0 不使用
    public void insert(Key e){ ... }
    public Key delMax(){ ... }
    private void swim(int k){ ... }
    private void sink(int k){ ... }
    
    private void exch(int i, int j){ }
    private boolean less(int i , int j){ }
    ```

  - [ ] BST   二叉搜索树

    - [ ] 完全二叉树的一种

  - [ ]  

- [ ] 