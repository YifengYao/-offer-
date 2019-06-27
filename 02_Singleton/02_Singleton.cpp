// 02_Singleton.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

//单例模式
# include <iostream>

using namespace std;
////饿汉式单例
//class Singleton {
//public:
//	static Singleton* getInstance() {
//		return instance;
//	}
//	static Singleton* distroyInstance() {
//		delete instance;
//		instance = NULL;
//	}
//private:
//	Singleton() {
//		cout << "饿汉式单例" << endl;
//	}
//	static Singleton* instance;
//};
//Singleton* Singleton::instance = new Singleton();
//int main() {
//	Singleton* s1 = Singleton::getInstance();
//	Singleton* s2 = Singleton::getInstance();
//	cout << s1 << endl;
//	cout << s2 << endl;
//	return 0;
//}
class Singleton {
public:
	static Singleton* getInstance() {
		if (instance == NULL) {
			instance = new Singleton();
			cout << "懒汉式单例创建成功" << endl;
		}
		else
			cout << "懒汉式单例已创建，无须重复创建" << endl;
		return instance;
	}
	static Singleton* destroyInstance() {
		delete instance;
		instance = NULL;
	}
private:
	Singleton() {
		cout << "懒汉式单例" << endl;
	}
	static Singleton* instance;
};
Singleton* Singleton::instance = NULL;
int main() {
	Singleton* s1 = Singleton::getInstance();
	Singleton* s2 = Singleton::getInstance();
	cout << s1 << endl;
	cout << s2 << endl;
	return 0;
}