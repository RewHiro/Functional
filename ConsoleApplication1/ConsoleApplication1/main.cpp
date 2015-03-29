#include <iostream>

//　関数ポインタと関数オブジェクト

// MEMO
// int*a(); -> void型のポイント
//int c = 0;
//int*a(){
//	return &c;
//}
// int(*b)(); -> void型
//　優先順位によって()をつけないといけない

//　関数ポインタの構造
//　戻り値 (*関数ポインタ名)(引数);
//　void (*Func)();

//　void型の関数ポインタ
void(*Func)();
void One(){
	std::cout << "1が押されました" << std::endl;
}
void Two(){
	std::cout << "2が押されました" << std::endl;
}
void Alert(){
	std::cout << "1,2以外" << std::endl;
}

//　int型の関数ポインタ
int(*Func1)();
int a(){ return 1; }
int b(){ return 2; }

//　int型引数付きの関数ポインタ
int(*Func2)(int,int);
int Add(int a,int b){
	return a + b;
}
int Diff(int a,int b){
	return a > b ? a - b : b - a;
}

void FuncPtr(){
	// 戻り値が異なるのでエラー
	//　Func1 = One;

	//　引数が異なるのでエラー
	//Func2 = a;

	// 戻り値、引数が関数ポインタと関数に合っていないとエラーが起こる
	Func2 = Add;

	int num = 0;
	std::cout << "1,2を選択してください。" << std::endl;
	std::cin >> num;

	switch (num){
	case 1:
		Func = One;
		break;
	case 2:
		Func = Two;
		break;
	default:
		Func = Alert;
		break;
	}
	Func();
}

//　関数オブジェクト
class FuncObject{
	float x, y;
	FuncObject* test_this = this;
public:
	FuncObject():
		x(0),
		y(0)
	{}

	//　this
	FuncObject& This(){
		return *test_this;
	}

	void Show(){
		std::cout << "x:" << x << "y:" << y << std::endl;
	}

	//関数オブジェクトの定義
	void operator()(){
		std::cout << "x:" << x << "y:" << y << std::endl;
	}
	//　参照無し
	FuncObject operator()(float x, float y){
		this->x = x;
		this->y = y;
		return *this;
	}
	//　参照あり(連続してメソッドを使用したいときに参照にする)
	//FuncObject& operator()(float x, float y){
	//	this->x = x;
	//	this->y = y;
	//	return *this;
	//}

};

int main(){

	//FuncPtr();

	//　関数のように振る舞うオブジェクト -> 関数のように振る舞うクラスの理解でもいいかも
	FuncObject obj;
	
	//　(5,5)の時点で別のFuncObjectが作られてしまう感じ(参照無しの場合)
	obj(1, 1)(5,5)();
	obj.Show();

	obj(12,15).Show();
	obj(10, 12)();
}

//　関数ポインタと関数オブジェクトの比較
//
//　inline化の可否
//　関数ポインタ -> inline化できない
//　関数オブジェクト -> inline化できる
//　つまりinline化できる関数オブジェクトの方が高速なので関数オブジェクトを使用した方がいい

//　補足
//　最近のコンパイラは関数ポインタはinline化ができる。
//　しかし全ての環境のコンパイラが適応されてるわけではないのでなるべく関数オブジェクトを使用した方がいい

//　参考URL：http://d.hatena.ne.jp/mickey24/20110211/stl_algorithms_and_functors