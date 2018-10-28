/*	通常在头文件中包含:
 *	函数原型
 *	结构声明
 *	#define 或者 const定义的符号常量
 *	类声明
 *	模板声明
 *	内联函数
 */




#ifndef COORDIN_H_	//	只有以前没有使用预处理编译指令#define 定义名称COORDIN_H_才处理ifdef endif 间的语句
#define COORDIN_H_	//	这个方法并不能防止包含这个头文件两次，但是它能够使得编译器忽略多余的包含

struct polar {
	double distance;
	double angle;
};

struct rect {
	double x;
	double y;
};

polar rect_to_polar(rect xypos);
void show_polar(polar dapos);

#endif
