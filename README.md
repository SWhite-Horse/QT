# my-study
# Day two
2	创建第一个gt程序
	2.1	点击创建项目后，选择项目路径以及给项目起名称
	2.2	名称-不能有中文不能有空格。
	2.3	路径 。不能有中文路径。
	2.4	默认创建有窗口类，Widget,基类有三种选择: QWidget 、QMainWindow.
		QDialog.
	2.5 	main 还数。
		2.5.1  QApplication a 应用程序对象， 有且仅有一一个。
		2.5.2  Widget w;实例化窗口对象。
		2.5.3  w.show[ ]调用 show函数显示窗口。
		2.5.4  return.exec（）让应用程序对象进入消息循环机制中，代码阻塞到当前行。
3	按钮控件常用API
	3.1	创建	QPushButton * btn = new QPushButton
	3.2	设置父亲	setParent(this)
	3.3	设置文本	setText("文字")
	3.4 	设置位置	move(宽,高)
	3.5	重新指定窗口大小	resize()
	3.6	设置窗口标题 	setWindowTitle
	3.7 	设置窗口固定大小	setFixedSize
4	对象树
	4.1	当创建的对象在堆区时候 ,如果指定的父亲是QObject派生下来的类或者QObject
	     	子类派生下来的类，可以不用管理释放的操作，将对象会放入到对象树中。。
	4.2	 一定程度上简化了内存回收机制。
5 	gt中的坐标系
	5.1	左上角为(0,0)点
	5.2	x以右为正方向。
	5.3 	y以下为正方向。
6	信号和槽
	6.1	连接函数: connect
	6.2	参数。
		6.2.1	参数1信号的发送者，
		6.2.2	参数2发送的信号 (函数地址)。
		6.2.3	参数3信号的接受者。
		6.2.4	参数4处理的槽函数(函数的地址) 。
	6.3	松散耦合~
	6.4	实现 点击按钮关闭窗口的案例。
	6.5 	connect(btn,&QPushButton::clicked, this,&Widget::close);
7	自定义信号和槽
	7.1	自定义信号
		7.1.1	写到signals 下。
		7.1.2	返回void,
		7.1.3	需要声明，不需要实现。
		7.1.4	可以有参数，可以重载。
	7.2自定义槽函数。
		7.2.1	返回void
		7.2.2	需要声明,也需要实现+
		7.2.3	可以有参数，可以重载，
		7.2.4	写到public slot下或者public 或者全局函数。
	7.3	触发自定义的信号。
		7.3.1 	emit 自定义信号。
	7.4 案例下课后，老师触发饿了信号，学生响应信号，请客吃饭+
8	当自定义信号和槽出现重载
	8.1	需要利用函数指针 明确指向函数的地址。
	8.2	void( Teacher::* tSignal )( QString )= &Teachr::hungny
	8.3	QString转成char *
		8.3.1.	ToUt8() 转为QByteArray'
		8.3.2.	Data() 转为Char *
	8.4	信号可以连接信号 。
	8.5	断开信号	disconnect
9	拓展
	9.1	信号可以连接信号。
	9.2 	一个信号可以连接多个槽函数。
	9.3	多个信号可以连接同 一个槽还数。
	9.4	信号和槽函数的参数，必须类型一一对应。
	9.5	信号和槽的参数个数，是不是要一致? 信号的参数个数可以多余槽函数的参数
		个数
	9.6	信号槽可以断开连接disconnect
10	Q14 版本写法* 
	10.1	 connect( 信号的发送者，发送的信号 SIGNAL(信号) ,信号接受者，槽函数
		 SLOT槽函数) )
	10.2	优点参数直观。
	10.3	缺点编译器不会检测参数类型。
11	Lambda 表达式。
	11.1	标识符匿名函数 。
		11.1.1	 =值传递。
		11.1.2	&引用传递。
	11.2	 ()参数 。
	11.3	 {}实现体。
	11.4 	 mutable 修饰值传递变量，可以修改拷贝出的数据,改变不了本体。
	11.5	 返回值 [ ]()>int{}

#Day Three

1 	QMainWindow
	1.1	菜单栏 最多有一个。
		1.1.1 	 QMenuBar* bar = MenuBar();
		1.1.2	 setMenuBar(bar) 。
		1.1.3	 QMenu * fileMenu = bar > addMenu("文件")创建菜单。
		1.1.4	 QAction *newAction = fleMenu ->addAction'新建");创建菜单项+
		1.1.5	添加分割线 fileMenu->addSeparator();
	1.2	工具栏 可以有多个。
		1.2.1 	gToolBar * toolbar = new gToolBar(this);
		1.2.2 	addToolBar( 默认停靠区域，toolbar ); Qt::LeftToolBarArea
		1.2.3	设置后期停靠区域， 设置浮动，设置移动。
		1.2.4	添加菜单项或者添加小控件。
	1.3	状态栏最多一个。
		1.3.1 	QStatusBar* stBar= statusBar0;+
		1.3.2	设置到窗口中setStatusBar(stBar);+u
		1.3.3	stBar->addWidgetlael);放左侧信息。
		1.3.4	stBar->addPermanentWidget/label2);放右侧信息。
	1.4	铆接部件浮动窗口可以多个。
		1.4.1 	QDockWidget 。
		1.4.2 	addDockWidget( 默认停靠区域,浮动窗口指针)。
		1.4.3	设置后期停靠区域w
	1.5	设置核心部件 只能一个
		1.5.1 	setCentralWidget(edit);



