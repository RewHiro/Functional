#include <iostream>

//�@�֐��|�C���^�Ɗ֐��I�u�W�F�N�g

// MEMO
// int*a(); -> void�^�̃|�C���g
//int c = 0;
//int*a(){
//	return &c;
//}
// int(*b)(); -> void�^
//�@�D�揇�ʂɂ����()�����Ȃ��Ƃ����Ȃ�

//�@�֐��|�C���^�̍\��
//�@�߂�l (*�֐��|�C���^��)(����);
//�@void (*Func)();

//�@void�^�̊֐��|�C���^
void(*Func)();
void One(){
	std::cout << "1��������܂���" << std::endl;
}
void Two(){
	std::cout << "2��������܂���" << std::endl;
}
void Alert(){
	std::cout << "1,2�ȊO" << std::endl;
}

//�@int�^�̊֐��|�C���^
int(*Func1)();
int a(){ return 1; }
int b(){ return 2; }

//�@int�^�����t���̊֐��|�C���^
int(*Func2)(int,int);
int Add(int a,int b){
	return a + b;
}
int Diff(int a,int b){
	return a > b ? a - b : b - a;
}

void FuncPtr(){
	// �߂�l���قȂ�̂ŃG���[
	//�@Func1 = One;

	//�@�������قȂ�̂ŃG���[
	//Func2 = a;

	// �߂�l�A�������֐��|�C���^�Ɗ֐��ɍ����Ă��Ȃ��ƃG���[���N����
	Func2 = Add;

	int num = 0;
	std::cout << "1,2��I�����Ă��������B" << std::endl;
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

//�@�֐��I�u�W�F�N�g
class FuncObject{
	float x, y;
	FuncObject* test_this = this;
public:
	FuncObject():
		x(0),
		y(0)
	{}

	//�@this
	FuncObject& This(){
		return *test_this;
	}

	void Show(){
		std::cout << "x:" << x << "y:" << y << std::endl;
	}

	//�֐��I�u�W�F�N�g�̒�`
	void operator()(){
		std::cout << "x:" << x << "y:" << y << std::endl;
	}
	//�@�Q�Ɩ���
	FuncObject operator()(float x, float y){
		this->x = x;
		this->y = y;
		return *this;
	}
	//�@�Q�Ƃ���(�A�����ă��\�b�h���g�p�������Ƃ��ɎQ�Ƃɂ���)
	//FuncObject& operator()(float x, float y){
	//	this->x = x;
	//	this->y = y;
	//	return *this;
	//}

};

int main(){

	//FuncPtr();

	//�@�֐��̂悤�ɐU�镑���I�u�W�F�N�g -> �֐��̂悤�ɐU�镑���N���X�̗����ł���������
	FuncObject obj;
	
	//�@(5,5)�̎��_�ŕʂ�FuncObject������Ă��܂�����(�Q�Ɩ����̏ꍇ)
	obj(1, 1)(5,5)();
	obj.Show();

	obj(12,15).Show();
	obj(10, 12)();
}

//�@�֐��|�C���^�Ɗ֐��I�u�W�F�N�g�̔�r
//
//�@inline���̉�
//�@�֐��|�C���^ -> inline���ł��Ȃ�
//�@�֐��I�u�W�F�N�g -> inline���ł���
//�@�܂�inline���ł���֐��I�u�W�F�N�g�̕��������Ȃ̂Ŋ֐��I�u�W�F�N�g���g�p������������

//�@�⑫
//�@�ŋ߂̃R���p�C���͊֐��|�C���^��inline�����ł���B
//�@�������S�Ă̊��̃R���p�C�����K������Ă�킯�ł͂Ȃ��̂łȂ�ׂ��֐��I�u�W�F�N�g���g�p������������

//�@�Q�lURL�Fhttp://d.hatena.ne.jp/mickey24/20110211/stl_algorithms_and_functors