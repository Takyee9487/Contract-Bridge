#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include<iomanip>
using namespace std;
const int N_CARDS = 53;
class Game
{
	friend class Process;
	friend class AI;
	friend class User;
private:
	bool v_rand_1, v_rand_2, v_rand_3, v_rand_4, v_rand_5, v_rand_6, v_rand_7, v_rand_8, v_rand_9, v_rand_10, v_rand_11, v_rand_12, v_rand_13, v_rand_14, v_rand_15; //�Ω󥻹C���L�{���|�J�쪺�H���M��
	int v_card_A_number[N_CARDS], v_card_A_color[N_CARDS]; //�쫬�P��
	int v_card_B_number[N_CARDS], v_card_B_color[N_CARDS]; //�~�n���P��
public:
	class Process
	{
		friend class Game;
		friend class AI;
		friend class User;
	private:
		int auction_color[40], auction_number[40]; //�s��All_processes.Auction()�L�{���C�@�����a�ҳ۪����
		int play_color[52], play_number[52]; //�s��All_processes.Play()�L�{���C�@�����a�ҥX�����P
		int sequence; //�bplay�L�{���X�P������ 
		int selector; //�s���O���@���F���X��
		int final_color, final_number; //�̲צX��������T
	public:
		class User
		{
			friend class Game;
			friend class Game::Process;
		private:
			int vCard_color[14], vCard_number[14]; //��P,���ϥ�vCard[0]
			int sCard_color[13], sCard_number[13]; //�s��All_processes.play()�L�{���C�@�E���a�ҥX���P
			int auction_color; //�̲צX��������T,�ӧQ�һ��E�Ʀs����class process�U������K
			int bid; //�s���C����U��Ĺ�F�X�E
		public:
			int set_data_card(); ////�N��P����(�®�,����,���,����)�ƦC
			void show_card1();
			void show_card2();
			int redo(Game::Process::User &);
			int set_data(int, int, int, int[], int[]); //�����w���i��S���s����̲צX������T���O�I
			int set_data2();
			int choose_color(int, int, int, int, int, int[], int[]);
			int select_card(int, int, int, int[], int[]);
			int id; //�Ψ��ѧO�U��player�b�C��������m
		};
		class AI
		{
			friend class Game;
			friend class Game::Process;
		private:
			bool smart;
			bool v_rand_1, v_rand_2, v_rand_3;//�ȮɨS��
			int vCard_color[14], vCard_number[14]; //��P,���ϥ�vCard[0]
			int sCard_color[13], sCard_number[13]; //�s��All_processes.play()�L�{���C�@�E���a�ҥX���P
			int auction_color; //�s��̲צX������T,�ӧQ�һ��E�Ʀs����class process�U������K
			int bid; //�s���C����U��Ĺ�F�X�E
			int spade_number;
			int heart_number;
			int diamond_number;
			int club_number;
			int id; //�Ψ��ѧO�U��player�b�C��������m
		public:
			class color
			{
				friend class Game;
				friend class Game::Process;
				friend class Game::Process::AI;
			private:
				int state;
				int big_point;
				int small_point;
				int number;
			};
			int set_data_card(); //�N��P����(�®�,����,���,����)�ƦC
			int reset_data(
				Game::Process::AI::color &,
				Game::Process::AI::color &,
				Game::Process::AI::color &,
				Game::Process::AI::color &);
			int set_data0(); //�s����P���C�Ӫ��U���X�i�P
			int set_data1(
				Game::Process::AI::color &,
				Game::Process::AI::color &,
				Game::Process::AI::color &,
				Game::Process::AI::color &); //�sMax_color��private
			int set_data2(
				Game::Process::AI::color &,
				Game::Process::AI::color &,
				Game::Process::AI::color &,
				Game::Process::AI::color &); //�sSecond_color��private
			int set_data3(
				Game::Process::AI::color &,
				Game::Process::AI::color &,
				Game::Process::AI::color &,
				Game::Process::AI::color &); //�sThird_color��private
			int set_data4(
				Game::Process::AI::color &,
				Game::Process::AI::color &,
				Game::Process::AI::color &,
				Game::Process::AI::color &); //�sMin_color��private
			int set_data5(int, int, int, int[], int[]); //�����w���i��S���s����̲צX������T���O�I
			int set_data6();
			int set_rand();//�ȮɨS��
			int set_player2_smart(bool, bool, bool); //done
			int set_player3_smart(bool, bool, bool); //done
			int set_player4_smart(bool, bool, bool); //done
			int redo(
				Game &,
				Game::Process::AI::color &,
				Game::Process::AI::color &,
				Game::Process::AI::color &,
				Game::Process::AI::color &); //����Ʒ|��e���|�Ө�ƩҨD�o���Ѽƶi����R,�̫�^�Ǥ@�ӭ�(�s�Τ@),�Ȭ��@�ɭ˵P
			int choose_color(
				int, int, int, int, int, int[], int[],
				Game &,
				Game::Process::AI::color &,
				Game::Process::AI::color &,
				Game::Process::AI::color &,
				Game::Process::AI::color &);
			int select_card(
				int, int, int, int, int, int, int, int, int, int[], int[],
				Game &,
				Game::Process::AI::color &,
				Game::Process::AI::color &,
				Game::Process::AI::color &,
				Game::Process::AI::color &);
		};
		int Difficulty_setting(
			Game &,
			Game::Process::AI &,
			Game::Process::AI &,
			Game::Process::AI &);
		int Set_up(
			Game &,
			Game::Process::User &,
			Game::Process::AI &,
			Game::Process::AI &,
			Game::Process::AI &,
			Game::Process::AI::color &,
			Game::Process::AI::color &,
			Game::Process::AI::color &,
			Game::Process::AI::color &);
		int Auction(
			Game &,
			Game::Process::User &,
			Game::Process::AI &,
			Game::Process::AI &,
			Game::Process::AI &,
			Game::Process::AI::color &,
			Game::Process::AI::color &,
			Game::Process::AI::color &,
			Game::Process::AI::color &);
		int Play(
			Game &,
			Game::Process::User &,
			Game::Process::AI &,
			Game::Process::AI &,
			Game::Process::AI &,
			Game::Process::AI::color &,
			Game::Process::AI::color &,
			Game::Process::AI::color &,
			Game::Process::AI::color &);
		int funa(int, int, int, int, int, int[], int[]); //�Nsequence�Mselector�ഫ���i�H�Ϊ�����
		int define_declarer(
			int, int, int, int, int, int, int[], int[],
			Game::Process::User &,
			Game::Process::AI &,
			Game::Process::AI &,
			Game::Process::AI &);
	};
	int dealing(
		Game::Process::User &,
		Game::Process::AI &,
		Game::Process::AI &,
		Game::Process::AI &); //�w�]���a��P+�o�P
	int set_data1(); //����v_rand_1,v_rand_2,v_rand_3
	int set_data2(); //���ͭ쫬�P��
	int set_data3(); //�s�~���P�᪺�P��
	int fun1(Game &); //�D�{��!!
};
int funa(int[], int[]);
int funb(int[]);
int func(int, int, int, int, int, int);
int fun_explanation1();
int fun_explanation1_1();
int fun_explanation2();
int fun_explanation3();
int fun_explanation3_1(int, int, int, int, int[], int[]);
int fun_explanation4();
char ch;
int main()
{
	Game Contract_Bridge;
	Contract_Bridge.fun1(Contract_Bridge);
	/*�H�W�����@�~�̲קΦ�*/
}
int Game::Process::User::set_data_card()
{
	int temp1, temp2, temp3;
	for (int i = 1; i < 5; i++)
	{
		for (int j = 1; j < 14; j++)
		{
			temp3 = j;
			do
			{
				if (this->vCard_color[j] == i)
				{
					if (this->vCard_color[j - 1] > this->vCard_color[j])
					{
						temp1 = this->vCard_color[j - 1];
						temp2 = this->vCard_number[j - 1];
						this->vCard_color[j - 1] = this->vCard_color[j];
						this->vCard_number[j - 1] = this->vCard_number[j];
						this->vCard_color[j] = temp1;
						this->vCard_number[j] = temp2;
						j--;
					}
				}
			} while ((this->vCard_color[j] == i) && (this->vCard_color[j - 1] > this->vCard_color[j]) == 1);
			j = temp3;
		}
	}
	for (int i = 1; i < 5; i++)
	{
		for (int j = 1; j < 14; j++)
		{
			temp3 = j;
			do
			{
				if (((this->vCard_color[j] == i) && (this->vCard_color[j + 1] == i)) == 1)
				{
					if (this->vCard_number[j] < this->vCard_number[j + 1])
					{
						temp1 = this->vCard_number[j + 1];
						this->vCard_number[j + 1] = this->vCard_number[j];
						this->vCard_number[j] = temp1;

					}
				}
				j--;
			} while (((this->vCard_color[j] == i) && (this->vCard_color[j + 1] == i)) && (this->vCard_number[j] < this->vCard_number[j + 1]) == 1);
			j = temp3;
		}
	}
	return NULL;
}
void Game::Process::User::show_card1()
{
	for (int i = 1; i < 14; i++)
	{
		if (this->vCard_color[i] == 1)
			cout << "�®�" << " " << this->vCard_number[i] << " ";
		else if (this->vCard_color[i] == 2)
			cout << "����" << " " << this->vCard_number[i] << " ";
		else if (this->vCard_color[i] == 3)
			cout << "���" << " " << this->vCard_number[i] << " ";
		else
			cout << "����" << " " << this->vCard_number[i] << " ";
		if (i == 7)
			cout << endl;
	}
	cout << endl;
}
void Game::Process::User::show_card2()
{
	for (int i = 1; i < 14; i++)
	{
		if (this->vCard_color[i] == 1)
			cout << "(" << i << ")" << "�®�" << " " << this->vCard_number[i] << " ";
		else if (this->vCard_color[i] == 2)
			cout << "(" << i << ")" << "����" << " " << this->vCard_number[i] << " ";
		else if (this->vCard_color[i] == 3)
			cout << "(" << i << ")" << "���" << " " << this->vCard_number[i] << " ";
		else if (this->vCard_color[i] == 4)
			cout << "(" << i << ")" << "����" << " " << this->vCard_number[i] << " ";
		else
			cout << "(" << 0 << ")" << "XXXX" << " " << 'X' << " ";
		if (i == 7)
			cout << endl;
	}
	cout << endl;
	cout << "�п�J���e���Ʀr�ӥX�P!!" << endl;
	cout << endl;
}
int Game::Process::User::redo(Game::Process::User &A)
{
	int a;
	cout << "�H�U���z����P!" << endl;
	cout << "+------------------------------+" << endl;
	A.show_card1();
	cout << "+------------------------------+" << endl;
	cout << "�Ъ`�N!!�b�U�@���q(�s�P)��,���{���ä��|�A���N��P�e�{�b����W," << endl;
	cout << "�Ъ��a�b���ɱN��P����T�O�U!!" << endl;
	cout << "�O�_�˵P?�Y�n�˵P,�п�J�Ʀr1!" << " ";
	cin >> a;
	return a;
}
int Game::Process::User::set_data(int a, int b, int c, int A[], int B[])
{
	/*
	a=counter_stop,
	b=sequence,
	c=selector,
	A[]=auction_color,
	B[]=auction_number,
	*/
	this->auction_color = A[a];
	//this->auction_number = B[a];
	return NULL;
}
int Game::Process::User::set_data2()
{
	for (int i = 0; i < 13; i++)
	{
		this->sCard_color[i] = 6;
		this->sCard_number[i] = 0;
	}
	return NULL;
}
int Game::Process::User::choose_color(int a, int b, int c, int d, int e, int A[], int B[])
{
	/*
	a�N��accept,
	b�N��counter,
	c�N��counter_stop,
	d�N��sequence,
	e�N��selector,
	A[]�N��auction_color[],
	B[]�N��auction_number[],
	*/
	cout << "+------------------------------+" << endl;
	int number;
	if (A[b - 3] == 0)
		cout << "���Player.3�ۥX�F�L�� " << B[b - 3] << endl;
	else if (A[b - 3] == 1)
		cout << "���Player.3�ۥX�F�®� " << B[b - 3] << endl;
	else if (A[b - 3] == 2)
		cout << "���Player.3�ۥX�F���� " << B[b - 3] << endl;
	else if (A[b - 3] == 3)
		cout << "���Player.3�ۥX�F��� " << B[b - 3] << endl;
	else if (A[b - 3] == 4)
		cout << "���Player.3�ۥX�F���� " << B[b - 3] << endl;
	else if (A[b - 3] == 5)
		cout << "���Player.3�ۥX�Fsmall " << B[b - 3] << endl;
	else
		cout << "���Player.3�M�wpass" << endl;
	if (A[b - 2] == 0)
		cout << "����Player.2�ۥX�F�L�� " << B[b - 2] << endl;
	else if (A[b - 2] == 1)
		cout << "����Player.2�ۥX�F�®� " << B[b - 2] << endl;
	else if (A[b - 2] == 2)
		cout << "����Player.2�ۥX�F���� " << B[b - 2] << endl;
	else if (A[b - 2] == 3)
		cout << "����Player.2�ۥX�F��� " << B[b - 2] << endl;
	else if (A[b - 2] == 4)
		cout << "����Player.2�ۥX�F���� " << B[b - 2] << endl;
	else if (A[b - 2] == 5)
		cout << "����Player.2�ۥX�Fsmall " << B[b - 2] << endl;
	else
		cout << "����Player.2�M�wpass" << endl;
	if (A[b - 1] == 0)
		cout << "���Player.4�ۥX�F�L�� " << B[b - 1] << endl;
	else if (A[b - 1] == 1)
		cout << "���Player.4�ۥX�F�®� " << B[b - 1] << endl;
	else if (A[b - 1] == 2)
		cout << "���Player.4�ۥX�F���� " << B[b - 1] << endl;
	else if (A[b - 1] == 3)
		cout << "���Player.4�ۥX�F��� " << B[b - 1] << endl;
	else if (A[b - 1] == 4)
		cout << "���Player.4�ۥX�F���� " << B[b - 1] << endl;
	else if (A[b - 1] == 5)
		cout << "���Player.4�ۥX�Fsmall " << B[b - 1] << endl;
	else
		cout << "���Player.4�M�wpass" << endl;
	cout << "+------------------------------+" << endl;
	cout << "�{�b���쪱�a��ܭn�۪����M�Ʀr" << endl;
	cout << "�Ъ`�N!!���@���g�L�P�w�����T�N������,�Ъ��a�V���M�w!!" << endl;
	cout << "�B�@�w�n��J�@���!" << endl;
	cout << "�����п�ܪ��:0���L��,1���®�,2������,3�����,4������,5��small,6��pass";
	int temp = 2, temp1 = 2, temp2 = 2;
	do
	{
		do
		{
			cin >> number;
			if (A[b - 1] == 0)
			{
				if (B[b - 1] == 7)
				{
					cout << "�w��s�P���I!" << endl;
					temp1 = 0;
					temp2 = 0;
				}
				else
				{
					if (number == 6)
					{
						A[b] = number;
						a++;
						c = b - 1;
						temp = 0;
						temp1 = 0;
						temp2 = 0;
					}
					else
					{
						A[b] = number;
						temp = 0;
					}
				}
			}
			else if (A[b - 1] == 1)
			{
				if (B[b - 1] == 7)
				{
					if (number == 0)
					{
						A[b] = number;
						temp = 0;
					}
					else if (number == 6)
					{
						A[b] = number;
						a++;
						c = b - 1;
						temp = 0;
						temp1 = 0;
						temp2 = 0;
					}
					else
					{
						cout << "��J���~!�Э��s��J ";
						cin >> number;
						temp = 1;
					}
				}
				else
				{
					if (number == 6)
					{
						A[b] = number;
						a++;
						c = b - 1;
						temp = 0;
						temp1 = 0;
						temp2 = 0;
					}
					else
					{
						A[b] = number;
						temp = 0;
					}
				}
			}
			else if (A[b - 1] == 2)
			{
				if (B[b - 1] == 7)
				{
					if ((number == 0) || (number == 1) == 1)
					{
						A[b] = number;
						temp = 0;
					}
					else if (number == 6)
					{
						A[b] = number;
						a++;
						c = b - 1;
						temp = 0;
						temp1 = 0;
						temp2 = 0;
					}
					else
					{
						cout << "��J���~!�Э��s��J ";
						cin >> number;
						temp = 1;
					}
				}
				else
				{
					if (number == 6)
					{
						A[b] = number;
						a++;
						c = b - 1;
						temp = 0;
						temp1 = 0;
						temp2 = 0;
					}
					else
					{
						A[b] = number;
						temp = 0;
					}
				}
			}
			else if (A[b - 1] == 3)
			{
				if (B[b - 1] == 7)
				{
					if ((number == 0) || (number == 1) || (number == 2) == 1)
					{
						A[b] = number;
						temp = 0;
					}
					else if (number == 6)
					{
						A[b] = number;
						a++;
						c = b - 1;
						temp = 0;
						temp1 = 0;
						temp2 = 0;
					}
					else
					{
						cout << "��J���~!�Э��s��J ";
						cin >> number;
						temp = 1;
					}
				}
				else
				{
					if (number == 6)
					{
						A[b] = number;
						a++;
						c = b - 1;
						temp = 0;
						temp1 = 0;
						temp2 = 0;
					}
					else
					{
						A[b] = number;
						temp = 0;
					}
				}
			}
			else if (A[b - 1] == 4)
			{
				if (B[b - 1] == 7)
				{
					if ((number == 0) || (number == 1) || (number == 2) || (number == 3) == 1)
					{
						A[b] = number;
						temp = 0;
					}
					else if (number == 6)
					{
						A[b] = number;
						a++;
						c = b - 1;
						temp = 0;
						temp1 = 0;
						temp2 = 0;
					}
					else
					{
						cout << "��J���~!�Э��s��J ";
						cin >> number;
						temp = 1;
					}
				}
				else
				{
					if (number == 6)
					{
						A[b] = number;
						a++;
						c = b - 1;
						temp = 0;
						temp1 = 0;
						temp2 = 0;
					}
					else
					{
						A[b] = number;
						temp = 0;
					}
				}
			}
			else if (A[b - 1] == 5)
			{
				if (B[b - 1] == 7)
				{
					if ((number == 0) || (number == 1) || (number == 2) || (number == 3) || (number == 4) == 1)
					{
						A[b] = number;
						temp = 0;
					}
					else if (number == 6)
					{
						A[b] = number;
						a++;
						c = b - 1;
						temp = 0;
						temp1 = 0;
						temp2 = 0;
					}
					else
					{
						cout << "��J���~!�Э��s��J ";
						cin >> number;
						temp = 1;
					}
				}
				else
				{
					if (number == 6)
					{
						A[b] = number;
						a++;
						c = b - 1;
						temp = 0;
						temp1 = 0;
						temp2 = 0;
					}
					else
					{
						A[b] = number;
						temp = 0;
					}
				}
			}
			else
			{
				if (a == 3)
				{
					d = c;
					e = c;
					temp = 0;
					temp1 = 0;
					temp2 = 0;
				}
				else
				{
					if (A[c] == 0)
					{
						if (B[c] == 7)
						{
							cout << "�w��s�P���I!" << endl;
							temp1 = 0;
							temp2 = 0;
						}
						else
						{
							if (number == 6)
							{
								A[b] = number;
								a++;
								temp = 0;
								temp1 = 0;
								temp2 = 0;
							}
							else
							{
								A[b] = number;
								temp = 0;
								a = 0;
								c = 0;
							}
						}
					}
					else if (A[c] == 1)
					{
						if (B[c] == 7)
						{
							if (number == 0)
							{
								A[b] = number;
								temp = 0;
								a = 0;
								c = 0;
							}
							else if (number == 6)
							{
								A[b] = number;
								a++;
								temp = 0;
								temp1 = 0;
								temp2 = 0;
							}
							else
							{
								cout << "��J���~!�Э��s��J ";
								cin >> number;
								temp = 1;
							}
						}
						else
						{
							if (number == 6)
							{
								A[b] = number;
								a++;
								temp = 0;
								temp1 = 0;
								temp2 = 0;
							}
							else
							{
								A[b] = number;
								temp = 0;
								a = 0;
								c = 0;
							}
						}
					}
					else if (A[c] == 2)
					{
						if (B[c] == 7)
						{
							if ((number == 0) || (number == 1) == 1)
							{
								A[b] = number;
								temp = 0;
								a = 0;
								c = 0;
							}
							else if (number == 6)
							{
								A[b] = number;
								a++;
								d = c;
								e = c;
								temp = 0;
								temp1 = 0;
								temp2 = 0;
							}
							else
							{
								cout << "��J���~!�Э��s��J ";
								cin >> number;
								temp = 1;
							}
						}
						else
						{
							if (number == 6)
							{
								A[b] = number;
								a++;
								temp = 0;
								temp1 = 0;
								temp2 = 0;
							}
							else
							{
								A[b] = number;
								temp = 0;
								a = 0;
								c = 0;
							}
						}
					}
					else if (A[c] == 3)
					{
						if (B[c] == 7)
						{
							if ((number == 0) || (number == 1) || (number == 2) == 1)
							{
								A[b] = number;
								temp = 0;
								a = 0;
								c = 0;
							}
							else if (number == 6)
							{
								A[b] = number;
								a++;
								d = c;
								e = c;
								temp = 0;
								temp1 = 0;
								temp2 = 0;
							}
							else
							{
								cout << "��J���~!�Э��s��J ";
								cin >> number;
								temp = 1;
							}
						}
						else
						{
							if (number == 6)
							{
								A[b] = number;
								a++;
								temp = 0;
								temp1 = 0;
								temp2 = 0;
							}
							else
							{
								A[b] = number;
								temp = 0;
								a = 0;
								c = 0;
							}
						}
					}
					else if (A[c] == 4)
					{
						if (B[c] == 7)
						{
							if ((number == 0) || (number == 1) || (number == 2) || (number == 3) == 1)
							{
								A[b] = number;
								temp = 0;
								a = 0;
								c = 0;
							}
							else if (number == 6)
							{
								A[b] = number;
								a++;
								d = c;
								e = c;
								temp = 0;
								temp1 = 0;
								temp2 = 0;
							}
							else
							{
								cout << "��J���~!�Э��s��J ";
								cin >> number;
								temp = 1;
							}
						}
						else
						{
							if (number == 6)
							{
								A[b] = number;
								a++;
								temp = 0;
								temp1 = 0;
								temp2 = 0;
							}
							else
							{
								A[b] = number;
								temp = 0;
								a = 0;
								c = 0;
							}
						}
					}
					else
					{
						if (B[c] == 7)
						{
							if ((number == 0) || (number == 1) || (number == 2) || (number == 3) || (number == 4) == 1)
							{
								A[b] = number;
								temp = 0;
								a = 0;
								c = 0;
							}
							else if (number == 6)
							{
								A[b] = number;
								a++;
								d = c;
								e = c;
								temp = 0;
								temp1 = 0;
								temp2 = 0;
							}
							else
							{
								cout << "��J���~!�Э��s��J ";
								cin >> number;
								temp = 1;
							}
						}
						else
						{
							if (number == 6)
							{
								A[b] = number;
								a++;
								temp = 0;
								temp1 = 0;
								temp2 = 0;
							}
							else
							{
								A[b] = number;
								temp = 0;
								a = 0;
								c = 0;
							}
						}
					}
				}
			}
			if (temp1 == 0)
				break;
		} while (temp == 1);
		if (number == 6)
			break;
		if (temp2 == 0)
			break;
		cout << "�{�b�Ъ��a��J�Q�n���Ʀr" << endl;
		cout << "�`�N!!�Ъ��a���ӳW�h��J���T���Ʀr!" << endl;
		do
		{
			if (temp == 0)
				cin >> number;
			if (A[b - 1] == 0)
			{
				if (A[b] == 0)
				{
					if ((number > B[b - 1]) && (number <= 7) == 1)
					{
						B[b] = number;
						temp = 0;
					}
					else
					{
						cout << "��J���~!�Э��s��J ";
						cin >> number;
						temp = 1;
					}
				}
				else if (A[b] == 1)
				{
					if ((number > B[b - 1]) && (number <= 7) == 1)
					{
						B[b] = number;
						temp = 0;
					}
					else
					{
						cout << "��J���~!�Э��s��J ";
						cin >> number;
						temp = 1;
					}
				}
				else if (A[b] == 2)
				{
					if ((number > B[b - 1]) && (number <= 7) == 1)
					{
						B[b] = number;
						temp = 0;
					}
					else
					{
						cout << "��J���~!�Э��s��J ";
						cin >> number;
						temp = 1;
					}
				}
				else if (A[b] == 3)
				{
					if ((number > B[b - 1]) && (number <= 7) == 1)
					{
						B[b] = number;
						temp = 0;
					}
					else
					{
						cout << "��J���~!�Э��s��J ";
						cin >> number;
						temp = 1;
					}
				}
				else if (A[b] == 4)
				{
					if ((number > B[b - 1]) && (number <= 7) == 1)
					{
						B[b] = number;
						temp = 0;
					}
					else
					{
						cout << "��J���~!�Э��s��J ";
						cin >> number;
						temp = 1;
					}
				}
				else
				{
					if ((number > B[b - 1]) && (number <= 7) == 1)
					{
						B[b] = number;
						temp = 0;
					}
					else
					{
						cout << "��J���~!�Э��s��J ";
						cin >> number;
						temp = 1;
					}
				}
			}
			else if (A[b - 1] == 1)
			{
				if (A[b] == 0)
				{
					if ((number >= B[b - 1]) && (number <= 7) == 1)
					{
						B[b] = number;
						temp = 0;
					}
					else
					{
						cout << "��J���~!�Э��s��J ";
						cin >> number;
						temp = 1;
					}
				}
				else if (A[b] == 1)
				{
					if ((number > B[b - 1]) && (number <= 7) == 1)
					{
						B[b] = number;
						temp = 0;
					}
					else
					{
						cout << "��J���~!�Э��s��J ";
						cin >> number;
						temp = 1;
					}
				}
				else if (A[b] == 2)
				{
					if ((number > B[b - 1]) && (number <= 7) == 1)
					{
						B[b] = number;
						temp = 0;
					}
					else
					{
						cout << "��J���~!�Э��s��J ";
						cin >> number;
						temp = 1;
					}
				}
				else if (A[b] == 3)
				{
					if ((number > B[b - 1]) && (ch <= 7) == 1)
					{
						B[b] = number;
						temp = 0;
					}
					else
					{
						cout << "��J���~!�Э��s��J ";
						cin >> number;
						temp = 1;
					}
				}
				else if (A[b] == 4)
				{
					if ((number > B[b - 1]) && (number <= 7) == 1)
					{
						B[b] = number;
						temp = 0;
					}
					else
					{
						cout << "��J���~!�Э��s��J ";
						cin >> number;
						temp = 1;
					}
				}
				else
				{
					if ((number > B[b - 1]) && (number <= 7) == 1)
					{
						B[b] = number;
						temp = 0;
					}
					else
					{
						cout << "��J���~!�Э��s��J ";
						cin >> number;
						temp = 1;
					}
				}
			}
			else if (A[b - 1] == 2)
			{
				if (A[b] == 0)
				{
					if ((number >= B[b - 1]) && (number <= 7) == 1)
					{
						B[b] = number;
						temp = 0;
					}
					else
					{
						cout << "��J���~!�Э��s��J ";
						cin >> number;
						temp = 1;
					}
				}
				else if (A[b] == 1)
				{
					if ((number >= B[b - 1]) && (number <= 7) == 1)
					{
						B[b] = number;
						temp = 0;
					}
					else
					{
						cout << "��J���~!�Э��s��J ";
						cin >> number;
						temp = 1;
					}
				}
				else if (A[b] == 2)
				{
					if ((number > B[b - 1]) && (number <= 7) == 1)
					{
						B[b] = number;
						temp = 0;
					}
					else
					{
						cout << "��J���~!�Э��s��J ";
						cin >> number;
						temp = 1;
					}
				}
				else if (A[b] == 3)
				{
					if ((number > B[b - 1]) && (number <= 7) == 1)
					{
						B[b] = number;
						temp = 0;
					}
					else
					{
						cout << "��J���~!�Э��s��J ";
						cin >> number;
						temp = 1;
					}
				}
				else if (A[b] == 4)
				{
					if ((number > B[b - 1]) && (number <= 7) == 1)
					{
						B[b] = number;
						temp = 0;
					}
					else
					{
						cout << "��J���~!�Э��s��J ";
						cin >> number;
						temp = 1;
					}
				}
				else
				{
					if ((number > B[b - 1]) && (number <= 7) == 1)
					{
						B[b] = number;
						temp = 0;
					}
					else
					{
						cout << "��J���~!�Э��s��J ";
						cin >> number;
						temp = 1;
					}
				}
			}
			else if (A[b - 1] == 3)
			{
				if (A[b] == 0)
				{
					if ((number >= B[b - 1]) && (number <= 7) == 1)
					{
						B[b] = number;
						temp = 0;
					}
					else
					{
						cout << "��J���~!�Э��s��J ";
						cin >> number;
						temp = 1;
					}
				}
				else if (A[b] == 1)
				{
					if ((number >= B[b - 1]) && (number <= 7) == 1)
					{
						B[b] = number;
						temp = 0;
					}
					else
					{
						cout << "��J���~!�Э��s��J ";
						cin >> number;
						temp = 1;
					}
				}
				else if (A[b] == 2)
				{
					if ((number >= B[b - 1]) && (number <= 7) == 1)
					{
						B[b] = number;
						temp = 0;
					}
					else
					{
						cout << "��J���~!�Э��s��J ";
						cin >> number;
						temp = 1;
					}
				}
				else if (A[b] == 3)
				{
					if ((number > B[b - 1]) && (number <= 7) == 1)
					{
						B[b] = number;
						temp = 0;
					}
					else
					{
						cout << "��J���~!�Э��s��J ";
						cin >> number;
						temp = 1;
					}
				}
				else if (A[b] == 4)
				{
					if ((number > B[b - 1]) && (number <= 7) == 1)
					{
						B[b] = number;
						temp = 0;
					}
					else
					{
						cout << "��J���~!�Э��s��J ";
						cin >> number;
						temp = 1;
					}
				}
				else
				{
					if ((number > B[b - 1]) && (number <= 7) == 1)
					{
						B[b] = number;
						temp = 0;
					}
					else
					{
						cout << "��J���~!�Э��s��J ";
						cin >> number;
						temp = 1;
					}
				}
			}
			else if (A[b - 1] == 4)
			{
				if (A[b] == 0)
				{
					if ((number >= B[b - 1]) && (number <= 7) == 1)
					{
						B[b] = number;
						temp = 0;
					}
					else
					{
						cout << "��J���~!�Э��s��J ";
						cin >> number;
						temp = 1;
					}
				}
				else if (A[b] == 1)
				{
					if ((number >= B[b - 1]) && (number <= 7) == 1)
					{
						B[b] = number;
						temp = 0;
					}
					else
					{
						cout << "��J���~!�Э��s��J ";
						cin >> number;
						temp = 1;
					}
				}
				else if (A[b] == 2)
				{
					if ((number >= B[b - 1]) && (number <= 7) == 1)
					{
						B[b] = number;
						temp = 0;
					}
					else
					{
						cout << "��J���~!�Э��s��J ";
						cin >> number;
						temp = 1;
					}
				}
				else if (A[b] == 3)
				{
					if ((number >= B[b - 1]) && (number <= 7) == 1)
					{
						B[b] = number;
						temp = 0;
					}
					else
					{
						cout << "��J���~!�Э��s��J ";
						cin >> number;
						temp = 1;
					}
				}
				else if (A[b] == 4)
				{
					if ((number > B[b - 1]) && (number <= 7) == 1)
					{
						B[b] = number;
						temp = 0;
					}
					else
					{
						cout << "��J���~!�Э��s��J ";
						cin >> number;
						temp = 1;
					}
				}
				else
				{
					if ((number > B[b - 1]) && (number <= 7) == 1)
					{
						B[b] = number;
						temp = 0;
					}
					else
					{
						cout << "��J���~!�Э��s��J ";
						cin >> number;
						temp = 1;
					}
				}
			}
			else if (A[b - 1] == 5)
			{
				if (A[b] == 0)
				{
					if ((number >= B[b - 1]) && (number <= 7) == 1)
					{
						B[b] = number;
						temp = 0;
					}
					else
					{
						cout << "��J���~!�Э��s��J ";
						cin >> number;
						temp = 1;
					}
				}
				else if (A[b] == 1)
				{
					if ((number >= B[b - 1]) && (number <= 7) == 1)
					{
						B[b] = number;
						temp = 0;
					}
					else
					{
						cout << "��J���~!�Э��s��J ";
						cin >> number;
						temp = 1;
					}
				}
				else if (A[b] == 2)
				{
					if ((number >= B[b - 1]) && (number <= 7) == 1)
					{
						B[b] = number;
						temp = 0;
					}
					else
					{
						cout << "��J���~!�Э��s��J ";
						cin >> number;
						temp = 1;
					}
				}
				else if (A[b] == 3)
				{
					if ((number >= B[b - 1]) && (number <= 7) == 1)
					{
						B[b] = number;
						temp = 0;
					}
					else
					{
						cout << "��J���~!�Э��s��J ";
						cin >> number;
						temp = 1;
					}
				}
				else if (A[b] == 4)
				{
					if ((number >= B[b - 1]) && (number <= 7) == 1)
					{
						B[b] = number;
						temp = 0;
					}
					else
					{
						cout << "��J���~!�Э��s��J ";
						cin >> number;
						temp = 1;
					}
				}
				else
				{
					if ((number > B[b - 1]) && (number <= 7) == 1)
					{
						B[b] = number;
						temp = 0;
					}
					else
					{
						cout << "��J���~!�Э��s��J ";
						cin >> number;
						temp = 1;
					}
				}
			}
			else
			{
				if (A[c] == 0)
				{
					if (A[b] == 0)
					{
						if ((number > B[c]) && (number <= 7) == 1)
						{
							B[b] = number;
							temp = 0;
							a = 0;
							c = 0;
						}
						else
						{
							cout << "��J���~!�Э��s��J ";
							cin >> number;
							temp = 1;
						}
					}
					else if (A[b] == 1)
					{
						if ((number > B[c]) && (number <= 7) == 1)
						{
							B[b] = number;
							temp = 0;
							a = 0;
							c = 0;
						}
						else
						{
							cout << "��J���~!�Э��s��J ";
							cin >> number;
							temp = 1;
						}
					}
					else if (A[b] == 2)
					{
						if ((number > B[c]) && (number <= 7) == 1)
						{
							B[b] = number;
							temp = 0;
							a = 0;
							c = 0;
						}
						else
						{
							cout << "��J���~!�Э��s��J ";
							cin >> number;
							temp = 1;
						}
					}
					else if (A[b] == 3)
					{
						if ((number > B[c]) && (number <= 7) == 1)
						{
							B[b] = number;
							temp = 0;
							a = 0;
							c = 0;
						}
						else
						{
							cout << "��J���~!�Э��s��J ";
							cin >> number;
							temp = 1;
						}
					}
					else if (A[b] == 4)
					{
						if ((number > B[c]) && (number <= 7) == 1)
						{
							B[b] = number;
							temp = 0;
							a = 0;
							c = 0;
						}
						else
						{
							cout << "��J���~!�Э��s��J ";
							cin >> number;
							temp = 1;
						}
					}
					else
					{
						if ((number > B[c]) && (number <= 7) == 1)
						{
							B[b] = number;
							temp = 0;
							a = 0;
							c = 0;
						}
						else
						{
							cout << "��J���~!�Э��s��J ";
							cin >> number;
							temp = 1;
						}
					}
				}
				else if (A[c] == 1)
				{
					if (A[b] == 0)
					{
						if ((number >= B[c]) && (number <= 7) == 1)
						{
							B[b] = number;
							temp = 0;
							a = 0;
							c = 0;
						}
						else
						{
							cout << "��J���~!�Э��s��J ";
							cin >> number;
							temp = 1;
						}
					}
					else if (A[b] == 1)
					{
						if ((number > B[c]) && (number <= 7) == 1)
						{
							B[b] = number;
							temp = 0;
							a = 0;
							c = 0;
						}
						else
						{
							cout << "��J���~!�Э��s��J ";
							cin >> number;
							temp = 1;
						}
					}
					else if (A[b] == 2)
					{
						if ((number > B[c]) && (number <= 7) == 1)
						{
							B[b] = number;
							temp = 0;
							a = 0;
							c = 0;
						}
						else
						{
							cout << "��J���~!�Э��s��J ";
							cin >> number;
							temp = 1;
						}
					}
					else if (A[b] == 3)
					{
						if ((number > B[c]) && (number <= 7) == 1)
						{
							B[b] = number;
							temp = 0;
							a = 0;
							c = 0;
						}
						else
						{
							cout << "��J���~!�Э��s��J ";
							cin >> number;
							temp = 1;
						}
					}
					else if (A[b] == 4)
					{
						if ((number > B[c]) && (number <= 7) == 1)
						{
							B[b] = number;
							temp = 0;
							a = 0;
							c = 0;
						}
						else
						{
							cout << "��J���~!�Э��s��J ";
							cin >> number;
							temp = 1;
						}
					}
					else
					{
						if ((number > B[c]) && (number <= 7) == 1)
						{
							B[b] = number;
							temp = 0;
							a = 0;
							c = 0;
						}
						else
						{
							cout << "��J���~!�Э��s��J ";
							cin >> number;
							temp = 1;
						}
					}
				}
				else if (A[c] == 2)
				{
					if (A[b] == 0)
					{
						if ((number >= B[c]) && (number <= 7) == 1)
						{
							B[b] = number;
							temp = 0;
							a = 0;
							c = 0;
						}
						else
						{
							cout << "��J���~!�Э��s��J ";
							cin >> number;
							temp = 1;
						}
					}
					else if (A[b] == 1)
					{
						if ((number >= B[c]) && (number <= 7) == 1)
						{
							B[b] = number;
							temp = 0;
							a = 0;
							c = 0;
						}
						else
						{
							cout << "��J���~!�Э��s��J ";
							cin >> number;
							temp = 1;
						}
					}
					else if (A[b] == 2)
					{
						if ((number > B[c]) && (number <= 7) == 1)
						{
							B[b] = number;
							temp = 0;
							a = 0;
							c = 0;
						}
						else
						{
							cout << "��J���~!�Э��s��J ";
							cin >> number;
							temp = 1;
						}
					}
					else if (A[b] == 3)
					{
						if ((number > B[c]) && (number <= 7) == 1)
						{
							B[b] = number;
							temp = 0;
							a = 0;
							c = 0;
						}
						else
						{
							cout << "��J���~!�Э��s��J ";
							cin >> number;
							temp = 1;
						}
					}
					else if (A[b] == 4)
					{
						if ((number > B[c]) && (number <= 7) == 1)
						{
							B[b] = number;
							temp = 0;
							a = 0;
							c = 0;
						}
						else
						{
							cout << "��J���~!�Э��s��J ";
							cin >> number;
							temp = 1;
						}
					}
					else
					{
						if ((number > B[c]) && (number <= 7) == 1)
						{
							B[b] = number;
							temp = 0;
							a = 0;
							c = 0;
						}
						else
						{
							cout << "��J���~!�Э��s��J ";
							cin >> number;
							temp = 1;
						}
					}
				}
				else if (A[c] == 3)
				{
					if (A[b] == 0)
					{
						if ((number >= B[c]) && (number <= 7) == 1)
						{
							B[b] = number;
							temp = 0;
							a = 0;
							c = 0;
						}
						else
						{
							cout << "��J���~!�Э��s��J ";
							cin >> number;
							temp = 1;
						}
					}
					else if (A[b] == 1)
					{
						if ((number >= B[c]) && (number <= 7) == 1)
						{
							B[b] = number;
							temp = 0;
							a = 0;
							c = 0;
						}
						else
						{
							cout << "��J���~!�Э��s��J ";
							cin >> number;
							temp = 1;
						}
					}
					else if (A[b] == 2)
					{
						if ((number >= B[c]) && (number <= 7) == 1)
						{
							B[b] = number;
							temp = 0;
							a = 0;
							c = 0;
						}
						else
						{
							cout << "��J���~!�Э��s��J ";
							cin >> number;
							temp = 1;
						}
					}
					else if (A[b] == 3)
					{
						if ((number > B[c]) && (number <= 7) == 1)
						{
							B[b] = number;
							temp = 0;
							a = 0;
							c = 0;
						}
						else
						{
							cout << "��J���~!�Э��s��J ";
							cin >> number;
							temp = 1;
						}
					}
					else if (A[b] == 4)
					{
						if ((number > B[c]) && (number <= 7) == 1)
						{
							B[b] = number;
							temp = 0;
							a = 0;
							c = 0;
						}
						else
						{
							cout << "��J���~!�Э��s��J ";
							cin >> number;
							temp = 1;
						}
					}
					else
					{
						if ((number > B[c]) && (number <= 7) == 1)
						{
							B[b] = number;
							temp = 0;
							a = 0;
							c = 0;
						}
						else
						{
							cout << "��J���~!�Э��s��J ";
							cin >> number;
							temp = 1;
						}
					}
				}
				else if (A[c] == 4)
				{
					if (A[b] == 0)
					{
						if ((number >= B[c]) && (number <= 7) == 1)
						{
							B[b] = number;
							temp = 0;
							a = 0;
							c = 0;
						}
						else
						{
							cout << "��J���~!�Э��s��J ";
							cin >> number;
							temp = 1;
						}
					}
					else if (A[b] == 1)
					{
						if ((number >= B[c]) && (number <= 7) == 1)
						{
							B[b] = number;
							temp = 0;
							a = 0;
							c = 0;
						}
						else
						{
							cout << "��J���~!�Э��s��J ";
							cin >> number;
							temp = 1;
						}
					}
					else if (A[b] == 2)
					{
						if ((number >= B[c]) && (number <= 7) == 1)
						{
							B[b] = number;
							temp = 0;
							a = 0;
							c = 0;
						}
						else
						{
							cout << "��J���~!�Э��s��J ";
							cin >> number;
							temp = 1;
						}
					}
					else if (A[b] == 3)
					{
						if ((number >= B[c]) && (number <= 7) == 1)
						{
							B[b] = number;
							temp = 0;
							a = 0;
							c = 0;
						}
						else
						{
							cout << "��J���~!�Э��s��J ";
							cin >> number;
							temp = 1;
						}
					}
					else if (A[b] == 4)
					{
						if ((number > B[c]) && (number <= 7) == 1)
						{
							B[b] = number;
							temp = 0;
							a = 0;
							c = 0;
						}
						else
						{
							cout << "��J���~!�Э��s��J ";
							cin >> number;
							temp = 1;
						}
					}
					else
					{
						if ((number > B[c]) && (number <= 7) == 1)
						{
							B[b] = number;
							temp = 0;
							a = 0;
							c = 0;
						}
						else
						{
							cout << "��J���~!�Э��s��J ";
							cin >> number;
							temp = 1;
						}
					}
				}
				else
				{
					if (A[b] == 0)
					{
						if ((number >= B[c]) && (number <= 7) == 1)
						{
							B[b] = number;
							temp = 0;
							a = 0;
							c = 0;
						}
						else
						{
							cout << "��J���~!�Э��s��J ";
							cin >> number;
							temp = 1;
						}
					}
					else if (A[b] == 1)
					{
						if ((number >= B[c]) && (number <= 7) == 1)
						{
							B[b] = number;
							temp = 0;
							a = 0;
							c = 0;
						}
						else
						{
							cout << "��J���~!�Э��s��J ";
							cin >> number;
							temp = 1;
						}
					}
					else if (A[b] == 2)
					{
						if ((number >= B[c]) && (number <= 7) == 1)
						{
							B[b] = number;
							temp = 0;
							a = 0;
							c = 0;
						}
						else
						{
							cout << "��J���~!�Э��s��J ";
							cin >> number;
							temp = 1;
						}
					}
					else if (A[b] == 3)
					{
						if ((number >= B[c]) && (number <= 7) == 1)
						{
							B[b] = number;
							temp = 0;
							a = 0;
							c = 0;
						}
						else
						{
							cout << "��J���~!�Э��s��J ";
							cin >> number;
							temp = 1;
						}
					}
					else if (A[b] == 4)
					{
						if ((number >= B[c]) && (number <= 7) == 1)
						{
							B[b] = number;
							temp = 0;
							a = 0;
							c = 0;
						}
						else
						{
							cout << "��J���~!�Э��s��J ";
							cin >> number;
							temp = 1;
						}
					}
					else
					{
						if ((number > B[c]) && (number <= 7) == 1)
						{
							B[b] = number;
							temp = 0;
							a = 0;
							c = 0;
						}
						else
						{
							cout << "��J���~!�Э��s��J ";
							cin >> number;
							temp = 1;
						}
					}
				}
			}
		} while (temp == 1);
	} while (temp == 1);
	cout << "+------------------------------+" << endl;
	if (A[b] == 0)
		cout << "�z�ۥX�F�L�� " << B[b] << endl;
	else if (A[b] == 1)
		cout << "�z�ۥX�F�®� " << B[b] << endl;
	else if (A[b] == 2)
		cout << "�z�ۥX�F���� " << B[b] << endl;
	else if (A[b] == 3)
		cout << "�z�ۥX�F��� " << B[b] << endl;
	else if (A[b] == 4)
		cout << "�z�ۥX�F���� " << B[b] << endl;
	else if (A[b] == 5)
		cout << "�z�ۥX�Fsmall " << B[b] << endl;
	else
		cout << "�z�M�wpass" << endl;
	int temp4 = 0;
	if (a != 0)
		temp4 = 1;
	return temp4;
}
int Game::Process::User::select_card(int a, int b, int c, int A[], int B[])
{
	/*
	a=i,
	b=j,
	c=temp,
	A[]=play_color[],
	B[]=play_number[],
	*/
	int temp1 = 0, temp2 = 0;
	int mark = 0;
	int number;
	for (int i = 1; i < 14; i++)
	{
		if ((this->vCard_color[i] == A[4 * a]) && (A[4 * a] != 0) == 1)
			temp1++;
	}
	if (this->auction_color == 0)
	{
		if (temp1 != 0)
		{
			do
			{
				cin >> number;
				if (this->vCard_color[number] != A[4 * a])
				{
					cout << "��P���٦��P��⪺�P,�Э��s��J!!" << endl;
					temp2 = 1;
				}
				else if (this->vCard_color[number] == 0)
				{
					cout << "���P�w�X,�Э��s��J!!" << endl;
					temp2 = 1;
				}
				else
				{
					this->sCard_color[number - 1] = this->vCard_color[number];
					A[b + 4 * a] = this->vCard_color[number];
					this->vCard_color[number] = 0;
					this->sCard_number[number - 1] = this->vCard_number[number];
					B[b + 4 * a] = this->vCard_number[number];
					this->vCard_number[number] = 0;
					mark = 1;
					break;
				}
			} while (temp2 == 1);
		}
		else
		{
			do
			{
				cin >> number;
				if (this->vCard_color[number] == 0)
				{
					cout << "���P�w�X,�Э��s��J!!" << endl;
					temp2 = 1;
				}
				else
				{
					this->sCard_color[number - 1] = this->vCard_color[number];
					A[b + 4 * a] = this->vCard_color[number];
					this->vCard_color[number] = 0;
					this->sCard_number[number - 1] = this->vCard_number[number];
					B[b + 4 * a] = this->vCard_number[number];
					this->vCard_number[number] = 0;
					break;
				}
			} while (temp2 == 1);
		}
	}
	else if (this->auction_color == 5)
	{
		if (temp1 != 0)
		{
			do
			{
				cin >> number;
				if (this->vCard_color[number] != A[4 * a])
				{
					cout << "��P���٦��P��⪺�P,�Э��s��J!!" << endl;
					temp2 = 1;
				}
				else if (this->vCard_color[number] == 0)
				{
					cout << "���P�w�X,�Э��s��J!!" << endl;
					temp2 = 1;
				}
				else
				{
					this->sCard_color[number - 1] = this->vCard_color[number];
					A[b + 4 * a] = this->vCard_color[number];
					this->vCard_color[number] = 0;
					this->sCard_number[number - 1] = this->vCard_number[number];
					B[b + 4 * a] = this->vCard_number[number];
					this->vCard_number[number] = 0;
					mark = 1;
					break;
				}
			} while (temp2 == 1);
		}
		else
		{
			do
			{
				cin >> number;
				if (this->vCard_color[number] == 0)
				{
					cout << "���P�w�X,�Э��s��J!!" << endl;
					temp2 = 1;
				}
				else
				{
					this->sCard_color[number - 1] = this->vCard_color[number];
					A[b + 4 * a] = this->vCard_color[number];
					this->vCard_color[number] = 0;
					this->sCard_number[number - 1] = this->vCard_number[number];
					B[b + 4 * a] = this->vCard_number[number];
					this->vCard_number[number] = 0;
					break;
				}
			} while (temp2 == 1);
		}
	}
	else
	{
		if (temp1 != 0)
		{
			do
			{
				cin >> number;
				if (this->vCard_color[number] != A[4 * a])
				{
					cout << "��P���٦��P��⪺�P,�Э��s��J!!" << endl;
					temp2 = 1;
				}
				else if (this->vCard_color[number] == 0)
				{
					cout << "���P�w�X,�Э��s��J!!" << endl;
					temp2 = 1;
				}
				else
				{
					this->sCard_color[number - 1] = this->vCard_color[number];
					A[b + 4 * a] = this->vCard_color[number];
					this->vCard_color[number] = 0;
					this->sCard_number[number - 1] = this->vCard_number[number];
					B[b + 4 * a] = this->vCard_number[number];
					this->vCard_number[number] = 0;
					mark = 1;
					break;
				}
			} while (temp2 == 1);
		}
		else
		{
			do
			{
				cin >> number;
				if (this->vCard_color[number] == 0)
				{
					cout << "���P�w�X,�Э��s��J!!" << endl;
					temp2 = 1;
				}
				else if (this->vCard_color[number] == this->auction_color)
				{
					this->sCard_color[number - 1] = this->vCard_color[number];
					A[b + 4 * a] = this->vCard_color[number];
					this->vCard_color[number] = 0;
					this->sCard_number[number - 1] = this->vCard_number[number];
					B[b + 4 * a] = this->vCard_number[number];
					this->vCard_number[number] = 0;
					mark = 1;
					break;
				}
				else
				{
					this->sCard_color[number - 1] = this->vCard_color[number];
					A[b + 4 * a] = this->vCard_color[number];
					this->vCard_color[number] = 0;
					this->sCard_number[number - 1] = this->vCard_number[number];
					B[b + 4 * a] = this->vCard_number[number];
					this->vCard_number[number] = 0;
					break;
				}
			} while (temp2 == 1);
		}
	}
	return mark;
}
int Game::Process::AI::set_data_card()
{
	int temp1, temp2, temp3;
	for (int i = 1; i < 5; i++)
	{
		for (int j = 1; j < 14; j++)
		{
			temp3 = j;
			do
			{
				if (this->vCard_color[j] == i)
				{
					if (this->vCard_color[j - 1] > this->vCard_color[j])
					{
						temp1 = this->vCard_color[j - 1];
						temp2 = this->vCard_number[j - 1];
						this->vCard_color[j - 1] = this->vCard_color[j];
						this->vCard_number[j - 1] = this->vCard_number[j];
						this->vCard_color[j] = temp1;
						this->vCard_number[j] = temp2;
						j--;
					}
				}
			} while ((this->vCard_color[j] == i) && (this->vCard_color[j - 1] > this->vCard_color[j]) == 1);
			j = temp3;
		}
	}
	for (int i = 1; i < 5; i++)
	{
		for (int j = 1; j < 14; j++)
		{
			temp3 = j;
			do
			{
				if (((this->vCard_color[j] == i) && (this->vCard_color[j + 1] == i)) == 1)
				{
					if (this->vCard_number[j] < this->vCard_number[j + 1])
					{
						temp1 = this->vCard_number[j + 1];
						this->vCard_number[j + 1] = this->vCard_number[j];
						this->vCard_number[j] = temp1;

					}
				}
				j--;
			} while (((this->vCard_color[j] == i) && (this->vCard_color[j + 1] == i)) && (this->vCard_number[j] < this->vCard_number[j + 1]) == 1);
			j = temp3;
		}
	}
	return NULL;
}
int Game::Process::AI::reset_data(
	Game::Process::AI::color &A,
	Game::Process::AI::color &B,
	Game::Process::AI::color &C,
	Game::Process::AI::color &D)
{
	A.state = 0;
	A.number = 0;
	A.big_point = 0;
	A.small_point = 0;
	B.state = 0;
	B.number = 0;
	B.big_point = 0;
	B.small_point = 0;
	C.state = 0;
	C.number = 0;
	C.big_point = 0;
	C.small_point = 0;
	D.state = 0;
	D.number = 0;
	D.big_point = 0;
	D.small_point = 0;
	return NULL;
}
int Game::Process::AI::set_data0()
{
	int a = 0, b = 0, c = 0, d = 0, temp = 0;
	for (int i = 1; i < 14; i++)
	{
		temp = this->vCard_color[i];
		if (temp == 1)
			a++;
		else if (temp == 2)
			b++;
		else if (temp == 3)
			c++;
		else
			d++;
	}
	this->spade_number = a;
	this->heart_number = b;
	this->diamond_number = c;
	this->club_number = d;
	return NULL;
}
int Game::Process::AI::set_data1(
	Game::Process::AI::color &A,
	Game::Process::AI::color &B,
	Game::Process::AI::color &C,
	Game::Process::AI::color &D)
{
	int temp;
	int ary[4] = { this->spade_number,this->heart_number,this->diamond_number,this->club_number };
	for (int i = 2; i >= 0; i--)
	{
		for (int j = 0; j <= i; j++)
		{
			if (ary[j] > ary[j + 1])
			{
				temp = ary[j];
				ary[j] = ary[j + 1];
				ary[j + 1] = temp;
			}
		}
	}
	/*ary[0]�|�s�i�Ƴ̤֪����,ary[3]�h�Ϥ�,�Y���i�ƬۦP�h������*/
	if (ary[3] == this->spade_number)
	{
		A.state = 1;
		A.number = this->spade_number;
		/*
		if (((A.state == B.state) || (A.state == C.state) || (A.state == D.state)) == 1)
		{
		A.state = 0;
		A.number = 0;
		}
		*/
	}
	if (ary[3] == this->heart_number)
	{
		int temp2, temp3;
		temp2 = A.state;
		temp3 = A.number;
		A.state = 2;
		A.number = this->heart_number;
		if (((ary[3] == ary[2]) || (ary[3] == ary[1]) || (ary[3] == ary[0])) == 1)
		{
			A.state = temp2;
			A.number = temp3;
		}
	}
	if (ary[3] == this->diamond_number)
	{
		int temp2, temp3;
		temp2 = A.state;
		temp3 = A.number;
		A.state = 3;
		A.number = this->diamond_number;
		if (((ary[3] == ary[2]) || (ary[3] == ary[1]) || (ary[3] == ary[0])) == 1)
		{
			A.state = temp2;
			A.number = temp3;
		}
	}
	if (ary[3] == this->club_number)
	{
		int temp2, temp3;
		temp2 = A.state;
		temp3 = A.number;
		A.state = 4;
		A.number = this->club_number;
		if (((ary[3] == ary[2]) || (ary[3] == ary[1]) || (ary[3] == ary[0])) == 1)
		{
			A.state = temp2;
			A.number = temp3;
		}
	}
	int temp1 = 0, temp2 = 0;
	for (int i = 1; i < 14; i++)
	{
		if (this->vCard_color[i] == A.state)
		{
			if (this->vCard_number[i] > 10)
				temp1 += this->vCard_number[i] - 10;
			else if (this->vCard_number[i] == 1)
				temp1 += 4;
			else if ((this->vCard_number[i] < 6) && (this->vCard_number[i] != 1) == 1)
				temp2 += 6 - this->vCard_number[i];
		}
	}
	A.big_point = temp1;
	A.small_point = temp2;
	return NULL;
}
int Game::Process::AI::set_data2(
	Game::Process::AI::color &A,
	Game::Process::AI::color &B,
	Game::Process::AI::color &C,
	Game::Process::AI::color &D)
{
	int temp;
	int ary[4] = { this->spade_number,this->heart_number,this->diamond_number,this->club_number };
	for (int i = 2; i >= 0; i--)
	{
		for (int j = 0; j <= i; j++)
		{
			if (ary[j] > ary[j + 1])
			{
				temp = ary[j];
				ary[j] = ary[j + 1];
				ary[j + 1] = temp;
			}
		}
	}
	/*ary[0]�|�s�i�Ƴ̤֪����,ary[3]�h�Ϥ�,�Y���i�ƬۦP�h������*/
	if (ary[2] == this->spade_number)
	{
		if (A.state != 1)
		{
			B.state = 1;
			B.number = this->spade_number;
			/*
			if (((B.state == A.state) || (B.state == C.state) || (B.state == D.state)) == 1)
			{
			B.state = 0;
			B.number = 0;
			}
			*/
		}
	}
	if (ary[2] == this->heart_number)
	{
		if (A.state != 2)
		{
			B.state = 2;
			B.number = this->heart_number;
		}
	}
	if (ary[2] == this->diamond_number)
	{
		if (A.state != 3)
		{
			B.state = 3;
			B.number = this->diamond_number;
		}
	}
	if (ary[2] == this->club_number)
	{
		if (A.state != 4)
		{
			B.state = 4;
			B.number = this->club_number;
		}
	}
	int temp1 = 0, temp2 = 0;
	for (int i = 1; i < 14; i++)
	{
		if (this->vCard_color[i] == B.state)
		{
			if (this->vCard_number[i] > 10)
				temp1 += this->vCard_number[i] - 10;
			else if (this->vCard_number[i] == 1)
				temp1 += 4;
			else if ((this->vCard_number[i] < 6) && (this->vCard_number[i] != 1) == 1)
				temp2 += 6 - this->vCard_number[i];
		}
	}
	B.big_point = temp1;
	B.small_point = temp2;
	return NULL;
}
int Game::Process::AI::set_data3(
	Game::Process::AI::color &A,
	Game::Process::AI::color &B,
	Game::Process::AI::color &C,
	Game::Process::AI::color &D)
{
	int temp;
	int ary[4] = { this->spade_number,this->heart_number,this->diamond_number,this->club_number };
	for (int i = 2; i >= 0; i--)
	{
		for (int j = 0; j <= i; j++)
		{
			if (ary[j] > ary[j + 1])
			{
				temp = ary[j];
				ary[j] = ary[j + 1];
				ary[j + 1] = temp;
			}
		}
	}
	/*ary[0]�|�s�i�Ƴ̤֪����,ary[3]�h�Ϥ�,�Y���i�ƬۦP�h������*/
	if (ary[1] == this->spade_number)
	{
		if ((A.state != 1) && (B.state != 1) == 1)
		{
			C.state = 1;
			C.number = this->spade_number;
		}
	}
	if (ary[1] == this->heart_number)
	{
		if ((A.state != 2) && (B.state != 2) == 1)
		{
			C.state = 2;
			C.number = this->heart_number;
		}
	}
	if (ary[1] == this->diamond_number)
	{
		if ((A.state != 3) && (B.state != 3) == 1)
		{
			C.state = 3;
			C.number = this->diamond_number;
		}
	}
	if (ary[1] == this->club_number)
	{
		if ((A.state != 4) && (B.state != 4) == 1)
		{
			C.state = 4;
			C.number = this->club_number;
		}
	}
	int temp1 = 0, temp2 = 0;
	for (int i = 1; i < 14; i++)
	{
		if (this->vCard_color[i] == C.state)
		{
			if (this->vCard_number[i] > 10)
				temp1 += this->vCard_number[i] - 10;
			else if (this->vCard_number[i] == 1)
				temp1 += 4;
			else if ((this->vCard_number[i] < 6) && (this->vCard_number[i] != 1) == 1)
				temp2 += 6 - this->vCard_number[i];
		}
	}
	C.big_point = temp1;
	C.small_point = temp2;
	return NULL;
}
int Game::Process::AI::set_data4(
	Game::Process::AI::color &A,
	Game::Process::AI::color &B,
	Game::Process::AI::color &C,
	Game::Process::AI::color &D)
{
	int temp;
	int ary[4] = { this->spade_number,this->heart_number,this->diamond_number,this->club_number };
	for (int i = 2; i >= 0; i--)
	{
		for (int j = 0; j <= i; j++)
		{
			if (ary[j] > ary[j + 1])
			{
				temp = ary[j];
				ary[j] = ary[j + 1];
				ary[j + 1] = temp;
			}
		}
	}
	/*ary[0]�|�s�i�Ƴ̤֪����,ary[3]�h�Ϥ�,�Y���i�ƬۦP�h������*/
	if (ary[0] == this->spade_number)
	{
		if ((A.state != 1) && (B.state != 1) && (C.state != 1) == 1)
		{
			D.state = 1;
			D.number = this->spade_number;
		}
	}
	if (ary[0] == this->heart_number)
	{
		if ((A.state != 2) && (B.state != 2) && (C.state != 2) == 1)
		{
			D.state = 2;
			D.number = this->heart_number;
		}
	}
	if (ary[0] == this->diamond_number)
	{
		if ((A.state != 3) && (B.state != 3) && (C.state != 3) == 1)
		{
			D.state = 3;
			D.number = this->diamond_number;
		}
	}
	if (ary[0] == this->club_number)
	{
		if ((A.state != 4) && (B.state != 4) && (C.state != 4) == 1)
		{
			D.state = 4;
			D.number = this->club_number;
		}
	}
	int temp1 = 0, temp2 = 0;
	for (int i = 1; i < 14; i++)
	{
		if (this->vCard_color[i] == D.state)
		{
			if (this->vCard_number[i] > 10)
				temp1 += this->vCard_number[i] - 10;
			else if (this->vCard_number[i] == 1)
				temp1 += 4;
			else if ((this->vCard_number[i] < 6) && (this->vCard_number[i] != 1) == 1)
				temp2 += 6 - this->vCard_number[i];
		}
	}
	D.big_point = temp1;
	D.small_point = temp2;
	return NULL;
}
int Game::Process::AI::set_data5(int a, int b, int c, int A[], int B[])
{
	/*
	a=counter_stop,
	b=sequence,
	c=selector,
	A[]=auction_color,
	B[]=auction_number,
	*/
	this->auction_color = A[a];
	//this->auction_number = B[a];
	return NULL;
}
int Game::Process::AI::set_data6()
{
	for (int i = 0; i < 13; i++)
	{
		this->sCard_color[i] = 6;
		this->sCard_number[i] = 0;
	}
	return NULL;
}
//set_rand()�ȮɨS��
int Game::Process::AI::set_rand()
{
	srand(time(0));
	this->v_rand_1 = (rand() % 2);
	this->v_rand_2 = (rand() % 2);
	this->v_rand_3 = (rand() % 2);
	return NULL;
}
int Game::Process::AI::set_player2_smart(bool a, bool b, bool c)
{
	//smart = ((!a) && b) || ((!b) && (!c));
	smart = 0;
	return NULL;
}
int Game::Process::AI::set_player3_smart(bool a, bool b, bool c)
{
	//smart = (((!a) && b && (!c)) || (a && ((!b) || c)));
	smart = 0;
	return NULL;
}
int Game::Process::AI::set_player4_smart(bool a, bool b, bool c)
{
	//smart = ((a && (!c)) || (b&&c));
	smart = 0;
	return NULL;
}
int Game::Process::AI::redo(
	Game &A,
	Game::Process::AI::color &B,
	Game::Process::AI::color &C,
	Game::Process::AI::color &D,
	Game::Process::AI::color &E)
{
	int big[4] = { B.big_point,C.big_point,D.big_point,E.big_point };
	int small[4] = { B.small_point,C.small_point,D.small_point,E.small_point };
	int sum_big = big[0] + big[1] + big[2] + big[3];
	int sum_small = small[0] + small[1] + small[2] + small[3];
	int temp;
	if ((sum_big) < 4)
	{
		if (smart == 0)
		{
			if ((sum_small) < 11)
				temp = 1;
			else
			{
				if ((A.v_rand_1&&A.v_rand_2) == 1)
					temp = 0;
				else
					temp = 1;
			}
		}
		else
		{
			if ((sum_small) <= 13)
				temp = 1;
			else if (((sum_small) < 20) && ((sum_small) > 13) == 1)
			{
				if ((A.v_rand_1 || A.v_rand_2) == 1)
					temp = 0;
				else
					temp = 1;
			}
			else
			{
				if ((A.v_rand_1&&A.v_rand_2&&A.v_rand_3) == 1)
					temp = 0;
				else
					temp = 1;
			}
		}
	}
	else
		temp = 0;
	return temp;
}
int Game::Process::AI::choose_color(
	int a, int b, int c, int d, int e, int A[], int B[],
	Game &C,
	Game::Process::AI::color &D,
	Game::Process::AI::color &E,
	Game::Process::AI::color &F,
	Game::Process::AI::color &G)
{
	/*
	a�N��accept,
	b�N��counter,
	c�N��counter_stop,
	d�N��sequence,
	e�N��selector,
	A[]�N��auction_color[],
	B[]�N��auction_number[],
	*/
	/*
	�bA[]��J1~4�|�����ܵP��1~4�����,
	�Y���s�h��No King,
	�Y�����h����p,
	�Y�����h�N��accept,

	B[]�h�O�n����h���E��,
	*/
	bool a1, b1, c1, d1, e1;
	int sum_small, sum_big;
	a1 = ((D.number <= 4) && (D.number >= 2));
	b1 = ((E.number <= 4) && (E.number >= 2));
	c1 = ((F.number <= 4) && (F.number >= 2));
	d1 = ((G.number <= 4) && (G.number >= 2));
	sum_small = D.small_point + E.small_point + F.small_point + G.small_point;
	sum_big = D.big_point + E.big_point + F.big_point + G.big_point;
	e1 = (sum_small > sum_big);
	/*�H�W�O�۪��ҦҼ{��²���Ѽ�*/
	//b++�b�̫����!!
	if (this->smart == 0)
	{
		if (a == 3)
		{
			this->auction_color = A[c];
			//this->auction_number = B[c];
			if (((d == 0) || (e == 0)) == 1)
			{
				d = c;
				e = c;
			}
		}
		//�Ѧ�b-3���P!!
		else if (a == 2)
		{
			int partner_color[2]; //�s�����ͥs�L�����
			int enemy1_color[2], enemy2_color[2]; //�s������H�s�L�����
												  //�|��ڶ��ͩM����C�H�̪�⦸�s�P�i����R
			if (b>7)
			{
				for (int i = 0; i < 2; i++)
					partner_color[i] = A[b - 2 - 4 * i];
				for (int i = 0; i < 2; i++)
				{
					enemy1_color[i] = A[b - 3 - 4 * i];
					enemy2_color[i] = A[b - 1 - 4 * i];
				}
				int temp0 = 0, temp1 = 0, temp2 = 0, temp3 = 0, temp4 = 0, temp5 = 0, temp_no = 0;
				for (int i = 0; i < 2; i++)
				{
					if (partner_color[i] == D.state)
						temp1 += i + 1;
					else if (partner_color[i] == E.state)
						temp2 += i + 1;
					else if (partner_color[i] == F.state)
						temp3 += i + 1;
					else if (partner_color[i] == G.state)
						temp4 += i + 1;
					else if (partner_color[i] == 0)
						temp0 += i + 1;
					else if (partner_color[i] == 5)
						temp5 += i + 1;
					else
						temp_no += i + 1;
					if (enemy1_color[i] == D.state)
						temp1 -= i + 1;
					else if (enemy1_color[i] == E.state)
						temp2 -= i + 1;
					else if (enemy1_color[i] == F.state)
						temp3 -= i + 1;
					else if (enemy1_color[i] == G.state)
						temp4 -= i + 1;
					else if (enemy1_color[i] == 0)
						temp0 -= i + 1;
					else if (enemy1_color[i] == 5)
						temp5 -= i + 1;
					else
						temp_no -= i + 1;
					if (enemy2_color[i] == D.state)
						temp1 -= i + 1;
					else if (enemy2_color[i] == E.state)
						temp2 -= i + 1;
					else if (enemy2_color[i] == F.state)
						temp3 -= i + 1;
					else if (enemy2_color[i] == G.state)
						temp4 -= i + 1;
					else if (enemy2_color[i] == 0)
						temp0 -= i + 1;
					else if (enemy2_color[i] == 5)
						temp5 -= i + 1;
					else
						temp_no -= i + 1;
				}
				int P[7] = { temp0,temp1,temp2,temp3,temp4,temp5,temp_no };
				int best_state;
				int bubble_sort[7] = { temp0,temp1,temp2,temp3,temp4,temp5,temp_no };
				for (int i = 6; i >= 0; i--)
				{
					for (int j = 0; j < i; j++)
					{
						int t;
						if (bubble_sort[j] < bubble_sort[j + 1])
						{
							t = bubble_sort[j + 1];
							bubble_sort[j + 1] = bubble_sort[j];
							bubble_sort[j] = t;
						}
					}
				}
				for (int i = 0; i < 7; i++)
				{
					if (bubble_sort[0] == P[i])
					{
						if (i == 0)
							best_state = 0;
						else if (i == 1)
							best_state = D.state;
						else if (i == 2)
							best_state = E.state;
						else if (i == 3)
							best_state = F.state;
						else if (i == 4)
							best_state = G.state;
						else if (i == 5)
							best_state = 5;
						else
							best_state = D.state;
						break;
					}
				}
				//���|�X�{A[b-1]=6������,�]���W�W�@�ӤH���w�S��accept!!
				if (bubble_sort[0] == bubble_sort[1]) //���]�䤣��̨θ�,���ɵL�k���T�M�w�n�۪����
				{
					if (A[b - 3] == 0)
					{
						if (B[b - 3] == 1)
						{
							if (C.v_rand_1 || C.v_rand_15 == 1)
							{
								if (a1&&b1&&c1&&d1 == 1)
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									//c = b - 1;
								}
								else if (e1 == 1)
								{
									if (C.v_rand_2 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										A[b] = 5;
										B[b] = B[b - 3] + 1;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (C.v_rand_2 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = D.state;
											B[b] = B[b - 3] + 1;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_2 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = E.state;
											B[b] = B[b - 3] + 1;
											a = 0;
											c = 0;
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else if (B[b - 2] < 3)
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3 == 1)
							{
								if (a1&&b1&&c1&&d1 == 1)
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									//c = b - 1;
								}
								else if (e1 == 1)
								{
									if (C.v_rand_4 || C.v_rand_5 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										A[b] = 5;
										B[b] = B[b - 3] + 1;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = D.state;
											B[b] = B[b - 3] + 1;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = E.state;
											B[b] = B[b - 3] + 1;
											a = 0;
											c = 0;
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3&&C.v_rand_4&&C.v_rand_5&&C.v_rand_6 == 1)
							{
								if (a1&&b1&&c1&&d1 == 1)
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									//c = b - 1;
								}
								else if (e1 == 1)
								{
									if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										A[b] = 5;
										B[b] = B[b - 3] + 1;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = D.state;
											B[b] = B[b - 3] + 1;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = E.state;
											B[b] = B[b - 3] + 1;
											a = 0;
											c = 0;
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
					}
					else if (A[b - 3] == 1)
					{
						if (B[b - 3] == 1)
						{
							if (C.v_rand_1 || C.v_rand_15 == 1)
							{
								if (a1&&b1&&c1&&d1 == 1)
								{
									if (C.v_rand_2 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										if (C.v_rand_3 == 1)
											B[b] = B[b - 3];
										else
											B[b] = B[b - 3] + 1;
										A[b] = 0;
										a = 0;
										c = 0;
									}
								}
								else if (e1 == 1)
								{
									if (C.v_rand_2 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										A[b] = 5;
										B[b] = B[b - 3] + 1;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (C.v_rand_2 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = D.state;
											B[b] = B[b - 3] + 1;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_2 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = E.state;
											B[b] = B[b - 3] + 1;
											a = 0;
											c = 0;
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else if (B[b - 3] < 3)
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3 == 1)
							{
								if (a1&&b1&&c1&&d1 == 1)
								{
									if (C.v_rand_4 || C.v_rand_5 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										if (C.v_rand_6 || C.v_rand_7 == 1)
											B[b] = B[b - 3];
										else
											B[b] = B[b - 3] + 1;
										A[b] = 0;
										a = 0;
										c = 0;
									}
								}
								else if (e1 == 1)
								{
									if (C.v_rand_4 || C.v_rand_5 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										A[b] = 5;
										B[b] = B[b - 3] + 1;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = D.state;
											B[b] = B[b - 3] + 1;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = E.state;
											B[b] = B[b - 3] + 1;
											a = 0;
											c = 0;
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3&&C.v_rand_4&&C.v_rand_5&&C.v_rand_6 == 1)
							{
								if (a1&&b1&&c1&&d1 == 1)
								{
									if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
											B[b] = B[b - 3];
										else
											B[b] = B[b - 3] + 1;
										A[b] = 0;
										a = 0;
										c = 0;
									}
								}
								else if (e1 == 1)
								{
									if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										A[b] = 5;
										B[b] = B[b - 3] + 1;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = D.state;
											B[b] = B[b - 3] + 1;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = E.state;
											B[b] = B[b - 3] + 1;
											a = 0;
											c = 0;
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
					}
					else if (A[b - 3] == 2)
					{
						if (B[b - 3] == 1)
						{
							if (C.v_rand_1 || C.v_rand_15 == 1)
							{
								if (a1&&b1&&c1&&d1 == 1)
								{
									if (C.v_rand_2 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										if (C.v_rand_3 == 1)
											B[b] = B[b - 3];
										else
											B[b] = B[b - 3] + 1;
										A[b] = 0;
										a = 0;
										c = 0;
									}
								}
								else if (e1 == 1)
								{
									if (C.v_rand_2 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										A[b] = 5;
										B[b] = B[b - 3] + 1;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (D.state == 2)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if (D.state == 1)
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_3 == 1)
													B[b] = B[b - 3];
												else
													B[b] = B[b - 3] + 1;
												A[b] = D.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = D.state;
												B[b] = B[b - 3] + 1;
												a = 0;
												c = 0;
											}
										}
									}
									else
									{
										if (E.state == 2)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if (E.state == 1)
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_3 == 1)
													B[b] = B[b - 3];
												else
													B[b] = B[b - 3] + 1;
												A[b] = E.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = E.state;
												B[b] = B[b - 3] + 1;
												a = 0;
												c = 0;
											}
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else if (B[b - 3] < 3)
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3 == 1)
							{
								if (a1&&b1&&c1&&d1 == 1)
								{
									if (C.v_rand_4 || C.v_rand_5 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										if (C.v_rand_6 || C.v_rand_7 == 1)
											B[b] = B[b - 3];
										else
											B[b] = B[b - 3] + 1;
										A[b] = 0;
										a = 0;
										c = 0;
									}
								}
								else if (e1 == 1)
								{
									if (C.v_rand_4 || C.v_rand_5 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										A[b] = 5;
										B[b] = B[b - 3] + 1;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (D.state == 2)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if (D.state == 1)
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_6 || C.v_rand_7 == 1)
													B[b] = B[b - 3];
												else
													B[b] = B[b - 3] + 1;
												A[b] = D.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = D.state;
												B[b] = B[b - 3] + 1;
												a = 0;
												c = 0;
											}
										}
									}
									else
									{
										if (E.state == 2)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if (E.state == 1)
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_6 || C.v_rand_7 == 1)
													B[b] = B[b - 3];
												else
													B[b] = B[b - 3] + 1;
												A[b] = E.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = E.state;
												B[b] = B[b - 3] + 1;
												a = 0;
												c = 0;
											}
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3&&C.v_rand_4&&C.v_rand_5&&C.v_rand_6 == 1)
							{
								if (a1&&b1&&c1&&d1 == 1)
								{
									if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
											B[b] = B[b - 3];
										else
											B[b] = B[b - 3] + 1;
										A[b] = 0;
										a = 0;
										c = 0;
									}
								}
								else if (e1 == 1)
								{
									if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										A[b] = 5;
										B[b] = B[b - 3] + 1;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (D.state == 2)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if (D.state == 1)
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
													B[b] = B[b - 3];
												else
													B[b] = B[b - 3] + 1;
												A[b] = D.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = D.state;
												B[b] = B[b - 3] + 1;
												a = 0;
												c = 0;
											}
										}
									}
									else
									{
										if (E.state == 2)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if (E.state == 1)
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
													B[b] = B[b - 3];
												else
													B[b] = B[b - 3] + 1;
												A[b] = E.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = E.state;
												B[b] = B[b - 3] + 1;
												a = 0;
												c = 0;
											}
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
					}
					else if (A[b - 3] == 3)
					{
						if (B[b - 3] == 1)
						{
							if (C.v_rand_1 || C.v_rand_15 == 1)
							{
								if (a1&&b1&&c1&&d1 == 1)
								{
									if (C.v_rand_2 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										if (C.v_rand_3 == 1)
											B[b] = B[b - 3];
										else
											B[b] = B[b - 3] + 1;
										A[b] = 0;
										a = 0;
										c = 0;
									}
								}
								else if (e1 == 1)
								{
									if (C.v_rand_2 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										A[b] = 5;
										B[b] = B[b - 3] + 1;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (D.state == 3)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if ((D.state == 1) || (D.state == 2) == 1)
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_3 == 1)
													B[b] = B[b - 3];
												else
													B[b] = B[b - 3] + 1;
												A[b] = D.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = D.state;
												B[b] = B[b - 3] + 1;
												a = 0;
												c = 0;
											}
										}
									}
									else
									{
										if (E.state == 3)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if ((E.state == 1) || (E.state == 2) == 1)
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_3 == 1)
													B[b] = B[b - 3];
												else
													B[b] = B[b - 3] + 1;
												A[b] = E.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = E.state;
												B[b] = B[b - 3] + 1;
												a = 0;
												c = 0;
											}
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else if (B[b - 3] < 3)
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3 == 1)
							{
								if (a1&&b1&&c1&&d1 == 1)
								{
									if (C.v_rand_4 || C.v_rand_5 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										if (C.v_rand_6 || C.v_rand_7 == 1)
											B[b] = B[b - 3];
										else
											B[b] = B[b - 3] + 1;
										A[b] = 0;
										a = 0;
										c = 0;
									}
								}
								else if (e1 == 1)
								{
									if (C.v_rand_4 || C.v_rand_5 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										A[b] = 5;
										B[b] = B[b - 3] + 1;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (D.state == 3)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if ((D.state == 1) || (D.state == 2) == 1)
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_6 || C.v_rand_7 == 1)
													B[b] = B[b - 3];
												else
													B[b] = B[b - 3] + 1;
												A[b] = D.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = D.state;
												B[b] = B[b - 3] + 1;
												a = 0;
												c = 0;
											}
										}
									}
									else
									{
										if (E.state == 3)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if ((E.state == 1) || (E.state == 2) == 1)
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_6 || C.v_rand_7 == 1)
													B[b] = B[b - 3];
												else
													B[b] = B[b - 3] + 1;
												A[b] = E.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = E.state;
												B[b] = B[b - 3] + 1;
												a = 0;
												c = 0;
											}
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3&&C.v_rand_4&&C.v_rand_5&&C.v_rand_6 == 1)
							{
								if (a1&&b1&&c1&&d1 == 1)
								{
									if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
											B[b] = B[b - 3];
										else
											B[b] = B[b - 3] + 1;
										A[b] = 0;
										a = 0;
										c = 0;
									}
								}
								else if (e1 == 1)
								{
									if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										A[b] = 5;
										B[b] = B[b - 3] + 1;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (D.state == 3)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if ((D.state == 1) || (D.state == 2) == 1)
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
													B[b] = B[b - 3];
												else
													B[b] = B[b - 3] + 1;
												A[b] = D.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = D.state;
												B[b] = B[b - 3] + 1;
												a = 0;
												c = 0;
											}
										}
									}
									else
									{
										if (E.state == 3)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if ((E.state == 1) || (E.state == 2) == 1)
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
													B[b] = B[b - 3];
												else
													B[b] = B[b - 3] + 1;
												A[b] = E.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = E.state;
												B[b] = B[b - 3] + 1;
												a = 0;
												c = 0;
											}
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
					}
					else if (A[b - 3] == 4)
					{
						if (B[b - 3] == 1)
						{
							if (C.v_rand_1 || C.v_rand_15 == 1)
							{
								if (a1&&b1&&c1&&d1 == 1)
								{
									if (C.v_rand_2 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										if (C.v_rand_3 == 1)
											B[b] = B[b - 3];
										else
											B[b] = B[b - 3] + 1;
										A[b] = 0;
										a = 0;
										c = 0;
									}
								}
								else if (e1 == 1)
								{
									if (C.v_rand_2 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										A[b] = 5;
										B[b] = B[b - 3] + 1;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (D.state == 4)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										//�W�@�H�۪���⬰����,�T�b���ɳ۶®�,����,����ҥi��ܽu��O�_�n+1
										else
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_3 == 1)
													B[b] = B[b - 3];
												else
													B[b] = B[b - 3] + 1;
												A[b] = D.state;
												a = 0;
												c = 0;
											}
										}
									}
									else
									{
										if (E.state == 4)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_3 == 1)
													B[b] = B[b - 3];
												else
													B[b] = B[b - 3] + 1;
												A[b] = E.state;
												a = 0;
												c = 0;
											}
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else if (B[b - 3] < 3)
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3 == 1)
							{
								if (a1&&b1&&c1&&d1 == 1)
								{
									if (C.v_rand_4 || C.v_rand_5 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										if (C.v_rand_6 || C.v_rand_7 == 1)
											B[b] = B[b - 3];
										else
											B[b] = B[b - 3] + 1;
										A[b] = 0;
										a = 0;
										c = 0;
									}
								}
								else if (e1 == 1)
								{
									if (C.v_rand_4 || C.v_rand_5 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										A[b] = 5;
										B[b] = B[b - 3] + 1;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (D.state == 4)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										//�W�@�H�۪���⬰����,�T�b���ɳ۶®�,����,����ҥi��ܽu��O�_�n+1
										else
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_6 || C.v_rand_7 == 1)
													B[b] = B[b - 3];
												else
													B[b] = B[b - 3] + 1;
												A[b] = D.state;
												a = 0;
												c = 0;
											}
										}
									}
									else
									{
										if (E.state == 4)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_6 || C.v_rand_7 == 1)
													B[b] = B[b - 3];
												else
													B[b] = B[b - 3] + 1;
												A[b] = E.state;
												a = 0;
												c = 0;
											}
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3&&C.v_rand_4&&C.v_rand_5&&C.v_rand_6 == 1)
							{
								if (a1&&b1&&c1&&d1 == 1)
								{
									if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
											B[b] = B[b - 3];
										else
											B[b] = B[b - 3] + 1;
										A[b] = 0;
										a = 0;
										c = 0;
									}
								}
								else if (e1 == 1)
								{
									if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										A[b] = 5;
										B[b] = B[b - 3] + 1;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (D.state == 4)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										//�W�@�H�۪���⬰����,�T�b���ɳ۶®�,����,����ҥi��ܽu��O�_�n+1
										else
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
													B[b] = B[b - 3];
												else
													B[b] = B[b - 3] + 1;
												A[b] = D.state;
												a = 0;
												c = 0;
											}
										}
									}
									else
									{
										if (E.state == 4)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
													B[b] = B[b - 3];
												else
													B[b] = B[b - 3] + 1;
												A[b] = E.state;
												a = 0;
												c = 0;
											}
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
					}
					else
					{
						if (B[b - 3] == 1)
						{
							if (C.v_rand_1 || C.v_rand_15 == 1)
							{
								if (a1&&b1&&c1&&d1 == 1)
								{
									if (C.v_rand_2 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										if (C.v_rand_3 == 1)
											B[b] = B[b - 3];
										else
											B[b] = B[b - 3] + 1;
										A[b] = 0;
										a = 0;
										c = 0;
									}
								}
								else if (e1 == 1)
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									//c = b - 1;
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (C.v_rand_2 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_3 == 1)
												B[b] = B[b - 3];
											else
												B[b] = B[b - 3] + 1;
											A[b] = D.state;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_2 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_3 == 1)
												B[b] = B[b - 3];
											else
												B[b] = B[b - 3] + 1;
											A[b] = E.state;
											a = 0;
											c = 0;
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else if (B[b - 3] < 3)
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3 == 1)
							{
								if (a1&&b1&&c1&&d1 == 1)
								{
									if (C.v_rand_4 || C.v_rand_5 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										if (C.v_rand_6 || C.v_rand_7 == 1)
											B[b] = B[b - 3];
										else
											B[b] = B[b - 3] + 1;
										A[b] = 0;
										a = 0;
										c = 0;
									}
								}
								else if (e1 == 1)
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									//c = b - 1;
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_6 || C.v_rand_7 == 1)
												B[b] = B[b - 3];
											else
												B[b] = B[b - 3] + 1;
											A[b] = D.state;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_6 || C.v_rand_7 == 1)
												B[b] = B[b - 3];
											else
												B[b] = B[b - 3] + 1;
											A[b] = E.state;
											a = 0;
											c = 0;
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3&&C.v_rand_4&&C.v_rand_5&&C.v_rand_6 == 1)
							{
								if (a1&&b1&&c1&&d1 == 1)
								{
									if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
											B[b] = B[b - 3];
										else
											B[b] = B[b - 3] + 1;
										A[b] = 0;
										a = 0;
										c = 0;
									}
								}
								else if (e1 == 1)
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									//c = b - 1;
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
												B[b] = B[b - 3];
											else
												B[b] = B[b - 3] + 1;
											A[b] = D.state;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
												B[b] = B[b - 3];
											else
												B[b] = B[b - 3] + 1;
											A[b] = E.state;
											a = 0;
											c = 0;
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
					}
				}
				else
				{
					//���Ҽ{���,�E�ƬݬO+1�η���!!
					//�Y�W�@�ӤH�۵L��
					if (A[b - 3] == 0)
					{
						//�Ҽ{�W�@��ۥX���u��
						if (B[b - 3] == 1)
						{
							//�@�b�����v�۷s�����
							if (C.v_rand_1 || C.v_rand_15 == 1)
							{
								//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
									if (best_state == 0)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										A[b] = best_state;
										B[b] = B[b - 3] + 1;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (C.v_rand_2 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = D.state;
											B[b] = B[b - 3] + 1;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_2 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = E.state;
											B[b] = B[b - 3] + 1;
											a = 0;
											c = 0;
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else if (B[b - 3] < 3)
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3 ||
								((D.big_point>6) || (E.big_point>6) || (F.big_point>7) || (G.big_point>7)) ||
								((D.small_point>6) || (E.small_point>6) || (F.small_point>7) || (G.small_point>7)) == 1)
							{
								//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
									if (best_state == 0)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = best_state;
											B[b] = B[b - 3] + 1;
											a = 0;
											c = 0;
										}
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = D.state;
											B[b] = B[b - 3] + 1;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = E.state;
											B[b] = B[b - 3] + 1;
											a = 0;
											c = 0;
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3&&C.v_rand_4&&C.v_rand_5&&C.v_rand_6 ||
								((D.big_point > 7) || (E.big_point > 7) || (F.big_point > 8) || (G.big_point > 8)) ||
								((D.small_point > 7) || (E.small_point > 7) || (F.small_point > 8) || (G.small_point > 8)) == 1)
							{
								//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
									if (best_state == 0)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = best_state;
											B[b] = B[b - 3] + 1;
											a = 0;
											c = 0;
										}
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = D.state;
											B[b] = B[b - 3] + 1;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = E.state;
											B[b] = B[b - 3] + 1;
											a = 0;
											c = 0;
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
					}
					//�Y�W�@�ӤH�ۥ|�����@
					else if (A[b - 3] == 1)
					{
						//�Ҽ{�W�@��ۥX���u��
						if (B[b - 3] == 1)
						{
							//�@�b�����v�۷s�����
							if (C.v_rand_1 || C.v_rand_15 == 1)
							{
								//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
									if (best_state == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else if (best_state == 0)
									{
										if (C.v_rand_2 == 1)
											B[b] = B[b - 3];
										else
											B[b] = B[b - 3] + 1;
										A[b] = best_state;
										a = 0;
										c = 0;
									}
									else
									{
										A[b] = best_state;
										B[b] = B[b - 3] + 1;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (D.state == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = D.state;
												B[b] = B[b - 3] + 1;
												a = 0;
												c = 0;
											}
										}
									}
									else
									{
										if (E.state == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = E.state;
												B[b] = B[b - 3] + 1;
												a = 0;
												c = 0;
											}
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else if (B[b - 2] < 3)
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3 ||
								((D.big_point>6) || (E.big_point>6) || (F.big_point>7) || (G.big_point>7)) ||
								((D.small_point>6) || (E.small_point>6) || (F.small_point>7) || (G.small_point>7)) == 1)
							{
								//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
									if (best_state == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else if (best_state == 0)
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_6 || C.v_rand_7 == 1)
												B[b] = B[b - 3];
											else
												B[b] = B[b - 3] + 1;
											A[b] = best_state;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = best_state;
											B[b] = B[b - 3] + 1;
											a = 0;
											c = 0;
										}
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (D.state == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = D.state;
												B[b] = B[b - 3] + 1;
												a = 0;
												c = 0;
											}
										}
									}
									else
									{
										if (E.state == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = E.state;
												B[b] = B[b - 3] + 1;
												a = 0;
												c = 0;
											}
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3&&C.v_rand_4&&C.v_rand_5&&C.v_rand_6 ||
								((D.big_point > 7) || (E.big_point > 7) || (F.big_point > 8) || (G.big_point > 8)) ||
								((D.small_point > 7) || (E.small_point > 7) || (F.small_point > 8) || (G.small_point > 8)) == 1)
							{
								//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
									if (best_state == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else if (best_state == 0)
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
												B[b] = B[b - 3];
											else
												B[b] = B[b - 3] + 1;
											A[b] = best_state;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = best_state;
											B[b] = B[b - 3] + 1;
											a = 0;
											c = 0;
										}
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (D.state == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = D.state;
												B[b] = B[b - 3] + 1;
												a = 0;
												c = 0;
											}
										}
									}
									else
									{
										if (E.state == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = E.state;
												B[b] = B[b - 3] + 1;
												a = 0;
												c = 0;
											}
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
					}
					else if (A[b - 3] == 2)
					{
						//�Ҽ{�W�@��ۥX���u��
						if (B[b - 3] == 1)
						{
							//�@�b�����v�۷s�����
							if (C.v_rand_1 || C.v_rand_15 == 1)
							{
								//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
									if (best_state == 2)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else if ((best_state == 0) || (best_state == 1) == 1)
									{
										if (C.v_rand_2 == 1)
											B[b] = B[b - 3];
										else
											B[b] = B[b - 3] + 1;
										A[b] = best_state;
										a = 0;
										c = 0;
									}
									else
									{
										A[b] = best_state;
										B[b] = B[b - 3] + 1;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (D.state == 2)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if (D.state == 1)
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_3 == 1)
													B[b] = B[b - 3];
												else
													B[b] = B[b - 3] + 1;
												A[b] = D.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = D.state;
												B[b] = B[b - 3] + 1;
												a = 0;
												c = 0;
											}
										}
									}
									else
									{
										if (E.state == 2)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if (E.state == 1)
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_3 == 1)
													B[b] = B[b - 3];
												else
													B[b] = B[b - 3] + 1;
												A[b] = E.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = E.state;
												B[b] = B[b - 3] + 1;
												a = 0;
												c = 0;
											}
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else if (B[b - 3] < 3)
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3 ||
								((D.big_point>6) || (E.big_point>6) || (F.big_point>7) || (G.big_point>7)) ||
								((D.small_point>6) || (E.small_point>6) || (F.small_point>7) || (G.small_point>7)) == 1)
							{
								//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
									if (best_state == 2)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else if ((best_state == 0) || (best_state == 1) == 1)
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_6 || C.v_rand_7 == 1)
												B[b] = B[b - 3];
											else
												B[b] = B[b - 3] + 1;
											A[b] = best_state;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = best_state;
											B[b] = B[b - 3] + 1;
											a = 0;
											c = 0;
										}
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (D.state == 2)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if (D.state == 1)
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_6 || C.v_rand_7 == 1)
													B[b] = B[b - 3];
												else
													B[b] = B[b - 3] + 1;
												A[b] = D.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = D.state;
												B[b] = B[b - 3] + 1;
												a = 0;
												c = 0;
											}
										}
									}
									else
									{
										if (E.state == 2)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if (E.state == 1)
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_6 || C.v_rand_7 == 1)
													B[b] = B[b - 3];
												else
													B[b] = B[b - 3] + 1;
												A[b] = E.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = E.state;
												B[b] = B[b - 3] + 1;
												a = 0;
												c = 0;
											}
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3&&C.v_rand_4&&C.v_rand_5&&C.v_rand_6 ||
								((D.big_point > 7) || (E.big_point > 7) || (F.big_point > 8) || (G.big_point > 8)) ||
								((D.small_point > 7) || (E.small_point > 7) || (F.small_point > 8) || (G.small_point > 8)) == 1)
							{
								//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
									if (best_state == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else if ((best_state == 0) || (best_state == 1) == 1)
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
												B[b] = B[b - 3];
											else
												B[b] = B[b - 3] + 1;
											A[b] = best_state;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = best_state;
											B[b] = B[b - 3] + 1;
											a = 0;
											c = 0;
										}
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (D.state == 2)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if (D.state == 1)
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
													B[b] = B[b - 3];
												else
													B[b] = B[b - 3] + 1;
												A[b] = D.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = D.state;
												B[b] = B[b - 3] + 1;
												a = 0;
												c = 0;
											}
										}
									}
									else
									{
										if (E.state == 2)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if (E.state == 1)
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
													B[b] = B[b - 3];
												else
													B[b] = B[b - 3] + 1;
												A[b] = E.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = E.state;
												B[b] = B[b - 3] + 1;
												a = 0;
												c = 0;
											}
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
					}
					else if (A[b - 3] == 3)
					{
						//�Ҽ{�W�@��ۥX���u��
						if (B[b - 3] == 1)
						{
							//�@�b�����v�۷s�����
							if (C.v_rand_1 || C.v_rand_15 == 1)
							{
								//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
									if (best_state == 3)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else if ((best_state == 0) || (best_state == 1) || (best_state == 2) == 1)
									{
										if (C.v_rand_2 == 1)
											B[b] = B[b - 3];
										else
											B[b] = B[b - 3] + 1;
										A[b] = best_state;
										a = 0;
										c = 0;
									}
									else
									{
										A[b] = best_state;
										B[b] = B[b - 3] + 1;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (D.state == 3)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if ((D.state == 1) || (D.state == 2) == 1)
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_3 == 1)
													B[b] = B[b - 3];
												else
													B[b] = B[b - 3] + 1;
												A[b] = D.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = D.state;
												B[b] = B[b - 3] + 1;
												a = 0;
												c = 0;
											}
										}
									}
									else
									{
										if (E.state == 3)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if ((E.state == 1) || (E.state == 2) == 1)
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_3 == 1)
													B[b] = B[b - 3];
												else
													B[b] = B[b - 3] + 1;
												A[b] = E.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = E.state;
												B[b] = B[b - 3] + 1;
												a = 0;
												c = 0;
											}
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else if (B[b - 3] < 3)
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3 ||
								((D.big_point>6) || (E.big_point>6) || (F.big_point>7) || (G.big_point>7)) ||
								((D.small_point>6) || (E.small_point>6) || (F.small_point>7) || (G.small_point>7)) == 1)
							{
								//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
									if (best_state == 3)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else if ((best_state == 0) || (best_state == 1) || (best_state == 2) == 1)
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_6 || C.v_rand_7 == 1)
												B[b] = B[b - 3];
											else
												B[b] = B[b - 3] + 1;
											A[b] = best_state;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = best_state;
											B[b] = B[b - 3] + 1;
											a = 0;
											c = 0;
										}
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (D.state == 3)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if ((D.state == 1) || (D.state == 2) == 1)
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_6 || C.v_rand_7 == 1)
													B[b] = B[b - 3];
												else
													B[b] = B[b - 3] + 1;
												A[b] = D.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = D.state;
												B[b] = B[b - 3] + 1;
												a = 0;
												c = 0;
											}
										}
									}
									else
									{
										if (E.state == 3)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if ((E.state == 1) || (E.state == 2) == 1)
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_6 || C.v_rand_7 == 1)
													B[b] = B[b - 3];
												else
													B[b] = B[b - 3] + 1;
												A[b] = E.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = E.state;
												B[b] = B[b - 3] + 1;
												a = 0;
												c = 0;
											}
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3&&C.v_rand_4&&C.v_rand_5&&C.v_rand_6 ||
								((D.big_point > 7) || (E.big_point > 7) || (F.big_point > 8) || (G.big_point > 8)) ||
								((D.small_point > 7) || (E.small_point > 7) || (F.small_point > 8) || (G.small_point > 8)) == 1)
							{
								//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
									if (best_state == 3)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else if ((best_state == 0) || (best_state == 1) || (best_state == 2) == 1)
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
												B[b] = B[b - 3];
											else
												B[b] = B[b - 3] + 1;
											A[b] = best_state;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = best_state;
											B[b] = B[b - 3] + 1;
											a = 0;
											c = 0;
										}
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (D.state == 3)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if ((D.state == 1) || (D.state == 2) == 1)
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
													B[b] = B[b - 3];
												else
													B[b] = B[b - 3] + 1;
												A[b] = D.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = D.state;
												B[b] = B[b - 3] + 1;
												a = 0;
												c = 0;
											}
										}
									}
									else
									{
										if (E.state == 3)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if ((E.state == 1) || (E.state == 2) == 1)
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
													B[b] = B[b - 3];
												else
													B[b] = B[b - 3] + 1;
												A[b] = E.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = E.state;
												B[b] = B[b - 3] + 1;
												a = 0;
												c = 0;
											}
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
					}
					else if (A[b - 3] == 4)
					{
						//�Ҽ{�W�@��ۥX���u��
						if (B[b - 3] == 1)
						{
							//�@�b�����v�۷s�����
							if (C.v_rand_1 || C.v_rand_15 == 1)
							{
								//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
									if (best_state == 4)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else if ((best_state == 0) || (best_state == 1) || (best_state == 2) || (best_state == 3) == 1)
									{
										if (C.v_rand_2 == 1)
											B[b] = B[b - 3];
										else
											B[b] = B[b - 3] + 1;
										A[b] = best_state;
										a = 0;
										c = 0;
									}
									else
									{
										A[b] = best_state;
										B[b] = B[b - 3] + 1;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (D.state == 4)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										//�W�@�H�۪���⬰����,�T�b���ɳ۶®�,����,����ҥi��ܽu��O�_�n+1
										else
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_3 == 1)
													B[b] = B[b - 3];
												else
													B[b] = B[b - 3] + 1;
												A[b] = D.state;
												a = 0;
												c = 0;
											}
										}
									}
									else
									{
										if (E.state == 4)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_3 == 1)
													B[b] = B[b - 3];
												else
													B[b] = B[b - 3] + 1;
												A[b] = E.state;
												a = 0;
												c = 0;
											}
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else if (B[b - 3] < 3)
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3 ||
								((D.big_point>6) || (E.big_point>6) || (F.big_point>7) || (G.big_point>7)) ||
								((D.small_point>6) || (E.small_point>6) || (F.small_point>7) || (G.small_point>7)) == 1)
							{
								//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
									if (best_state == 4)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else if ((best_state == 0) || (best_state == 1) || (best_state == 2) || (best_state == 3) == 1)
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_6 || C.v_rand_7 == 1)
												B[b] = B[b - 3];
											else
												B[b] = B[b - 3] + 1;
											A[b] = best_state;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = best_state;
											B[b] = B[b - 3] + 1;
											a = 0;
											c = 0;
										}
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (D.state == 4)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										//�W�@�H�۪���⬰����,�T�b���ɳ۶®�,����,����ҥi��ܽu��O�_�n+1
										else
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_6 || C.v_rand_7 == 1)
													B[b] = B[b - 3];
												else
													B[b] = B[b - 3] + 1;
												A[b] = D.state;
												a = 0;
												c = 0;
											}
										}
									}
									else
									{
										if (E.state == 4)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_6 || C.v_rand_7 == 1)
													B[b] = B[b - 3];
												else
													B[b] = B[b - 3] + 1;
												A[b] = E.state;
												a = 0;
												c = 0;
											}
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3&&C.v_rand_4&&C.v_rand_5&&C.v_rand_6 ||
								((D.big_point > 7) || (E.big_point > 7) || (F.big_point > 8) || (G.big_point > 8)) ||
								((D.small_point > 7) || (E.small_point > 7) || (F.small_point > 8) || (G.small_point > 8)) == 1)
							{
								//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
									if (best_state == 4)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else if ((best_state == 0) || (best_state == 1) || (best_state == 2) || (best_state == 3) == 1)
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
												B[b] = B[b - 3];
											else
												B[b] = B[b - 3] + 1;
											A[b] = best_state;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = best_state;
											B[b] = B[b - 3] + 1;
											a = 0;
											c = 0;
										}
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (D.state == 4)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										//�W�@�H�۪���⬰����,�T�b���ɳ۶®�,����,����ҥi��ܽu��O�_�n+1
										else
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
													B[b] = B[b - 3];
												else
													B[b] = B[b - 3] + 1;
												A[b] = D.state;
												a = 0;
												c = 0;
											}
										}
									}
									else
									{
										if (E.state == 4)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
													B[b] = B[b - 3];
												else
													B[b] = B[b - 3] + 1;
												A[b] = E.state;
												a = 0;
												c = 0;
											}
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
					}
					//�Y�W�@�ӤH��small
					else
					{
						//�Ҽ{�W�@��ۥX���u��
						if (B[b - 3] == 1)
						{
							//�@�b�����v�۷s�����
							if (C.v_rand_1 || C.v_rand_15 == 1)
							{
								//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
									if (best_state == 5)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										if (C.v_rand_2 == 1)
											B[b] = B[b - 3];
										else
											B[b] = B[b - 3] + 1;
										A[b] = best_state;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (C.v_rand_2 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_3 == 1)
												B[b] = B[b - 3];
											else
												B[b] = B[b - 3] + 1;
											A[b] = D.state;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_2 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_3 == 1)
												B[b] = B[b - 3];
											else
												B[b] = B[b - 3] + 1;
											A[b] = E.state;
											a = 0;
											c = 0;
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else if (B[b - 3] < 3)
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3 ||
								((D.big_point>6) || (E.big_point>6) || (F.big_point>7) || (G.big_point>7)) ||
								((D.small_point>6) || (E.small_point>6) || (F.small_point>7) || (G.small_point>7)) == 1)
							{
								//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
									if (best_state == 5)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
											B[b] = B[b - 3];
										else
											B[b] = B[b - 3] + 1;
										A[b] = best_state;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_6 || C.v_rand_7 == 1)
												B[b] = B[b - 3];
											else
												B[b] = B[b - 3] + 1;
											A[b] = D.state;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_6 || C.v_rand_7 == 1)
												B[b] = B[b - 3];
											else
												B[b] = B[b - 3] + 1;
											A[b] = E.state;
											a = 0;
											c = 0;
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3&&C.v_rand_4&&C.v_rand_5&&C.v_rand_6 ||
								((D.big_point > 7) || (E.big_point > 7) || (F.big_point > 8) || (G.big_point > 8)) ||
								((D.small_point > 7) || (E.small_point > 7) || (F.small_point > 8) || (G.small_point > 8)) == 1)
							{
								//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
									if (best_state == 5)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											B[b] = B[b - 3];
										else
											B[b] = B[b - 3] + 1;
										A[b] = best_state;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
												B[b] = B[b - 3];
											else
												B[b] = B[b - 3] + 1;
											A[b] = D.state;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
												B[b] = B[b - 3];
											else
												B[b] = B[b - 3] + 1;
											A[b] = E.state;
											a = 0;
											c = 0;
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
					}
				}
			}
			else
			{
				for (int i = 0; i < 2; i++)
				{
					if (b - 2 - 4 * i > 0)
						partner_color[i] = A[b - 2 - 4 * i];
				}
				for (int i = 0; i < 2; i++)
				{
					if (b - 3 - 4 * i > 0)
						enemy1_color[i] = A[b - 3 - 4 * i];
					if (b - 1 - 4 * i > 0)
						enemy2_color[i] = A[b - 1 - 4 * i];
				}
				int temp0 = 0, temp1 = 0, temp2 = 0, temp3 = 0, temp4 = 0, temp5 = 0, temp_no = 0;
				for (int i = 0; i < 2; i++)
				{
					if (partner_color[i] == D.state)
						temp1 += i + 1;
					else if (partner_color[i] == E.state)
						temp2 += i + 1;
					else if (partner_color[i] == F.state)
						temp3 += i + 1;
					else if (partner_color[i] == G.state)
						temp4 += i + 1;
					else if (partner_color[i] == 0)
						temp0 += i + 1;
					else if (partner_color[i] == 5)
						temp5 += i + 1;
					else
						temp_no += i + 1;
					if (enemy1_color[i] == D.state)
						temp1 -= i + 1;
					else if (enemy1_color[i] == E.state)
						temp2 -= i + 1;
					else if (enemy1_color[i] == F.state)
						temp3 -= i + 1;
					else if (enemy1_color[i] == G.state)
						temp4 -= i + 1;
					else if (enemy1_color[i] == 0)
						temp0 -= i + 1;
					else if (enemy1_color[i] == 5)
						temp5 -= i + 1;
					else
						temp_no -= i + 1;
					if (enemy2_color[i] == D.state)
						temp1 -= i + 1;
					else if (enemy2_color[i] == E.state)
						temp2 -= i + 1;
					else if (enemy2_color[i] == F.state)
						temp3 -= i + 1;
					else if (enemy2_color[i] == G.state)
						temp4 -= i + 1;
					else if (enemy2_color[i] == 0)
						temp0 -= i + 1;
					else if (enemy2_color[i] == 5)
						temp5 -= i + 1;
					else
						temp_no -= i + 1;
				}
				int P[7] = { temp0,temp1,temp2,temp3,temp4,temp5,temp_no };
				int best_state;
				int bubble_sort[7] = { temp0,temp1,temp2,temp3,temp4,temp5,temp_no };
				for (int i = 6; i >= 0; i--)
				{
					for (int j = 0; j < i; j++)
					{
						int t;
						if (bubble_sort[j] < bubble_sort[j + 1])
						{
							t = bubble_sort[j + 1];
							bubble_sort[j + 1] = bubble_sort[j];
							bubble_sort[j] = t;
						}
					}
				}
				for (int i = 0; i < 7; i++)
				{
					if (bubble_sort[0] == P[i])
					{
						if (i == 0)
							best_state = 0;
						else if (i == 1)
							best_state = D.state;
						else if (i == 2)
							best_state = E.state;
						else if (i == 3)
							best_state = F.state;
						else if (i == 4)
							best_state = G.state;
						else if (i == 5)
							best_state = 5;
						else
							best_state = D.state;
						break;
					}
				}
				/*���]���̨θѬ�bubble_sort[0]�ҹ��������!!*/
				//���|�X�{A[b-1]=6������,�]���W�@�ӤH���w�S��accept!!
				if (bubble_sort[0] == bubble_sort[1]) //���]�䤣��̨θ�,���ɵL�k���T�M�w�n�۪����
				{
					if (A[b - 3] == 0)
					{
						if (B[b - 3] == 1)
						{
							if (C.v_rand_1 || C.v_rand_15 == 1)
							{
								if (a1&&b1&&c1&&d1 == 1)
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									//c = b - 1;
								}
								else if (e1 == 1)
								{
									if (C.v_rand_2 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										A[b] = 5;
										B[b] = B[b - 3] + 1;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (C.v_rand_2 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = D.state;
											B[b] = B[b - 3] + 1;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_2 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = E.state;
											B[b] = B[b - 3] + 1;
											a = 0;
											c = 0;
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else if (B[b - 3] < 3)
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3 == 1)
							{
								if (a1&&b1&&c1&&d1 == 1)
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									//c = b - 1;
								}
								else if (e1 == 1)
								{
									if (C.v_rand_4 || C.v_rand_5 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										A[b] = 5;
										B[b] = B[b - 3] + 1;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = D.state;
											B[b] = B[b - 3] + 1;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = E.state;
											B[b] = B[b - 3] + 1;
											a = 0;
											c = 0;
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3&&C.v_rand_4&&C.v_rand_5&&C.v_rand_6 == 1)
							{
								if (a1&&b1&&c1&&d1 == 1)
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									//c = b - 1;
								}
								else if (e1 == 1)
								{
									if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										A[b] = 5;
										B[b] = B[b - 3] + 1;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = D.state;
											B[b] = B[b - 3] + 1;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = E.state;
											B[b] = B[b - 3] + 1;
											a = 0;
											c = 0;
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
					}
					else if (A[b - 3] == 1)
					{
						if (B[b - 3] == 1)
						{
							if (C.v_rand_1 || C.v_rand_15 == 1)
							{
								if (a1&&b1&&c1&&d1 == 1)
								{
									if (C.v_rand_2 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										if (C.v_rand_3 == 1)
											B[b] = B[b - 3];
										else
											B[b] = B[b - 3] + 1;
										A[b] = 0;
										a = 0;
										c = 0;
									}
								}
								else if (e1 == 1)
								{
									if (C.v_rand_2 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										A[b] = 5;
										B[b] = B[b - 3] + 1;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (C.v_rand_2 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = D.state;
											B[b] = B[b - 3] + 1;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_2 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = E.state;
											B[b] = B[b - 3] + 1;
											a = 0;
											c = 0;
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else if (B[b - 3] < 3)
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3 == 1)
							{
								if (a1&&b1&&c1&&d1 == 1)
								{
									if (C.v_rand_4 || C.v_rand_5 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										if (C.v_rand_6 || C.v_rand_7 == 1)
											B[b] = B[b - 3];
										else
											B[b] = B[b - 3] + 1;
										A[b] = 0;
										a = 0;
										c = 0;
									}
								}
								else if (e1 == 1)
								{
									if (C.v_rand_4 || C.v_rand_5 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										A[b] = 5;
										B[b] = B[b - 3] + 1;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = D.state;
											B[b] = B[b - 3] + 1;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = E.state;
											B[b] = B[b - 3] + 1;
											a = 0;
											c = 0;
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3&&C.v_rand_4&&C.v_rand_5&&C.v_rand_6 == 1)
							{
								if (a1&&b1&&c1&&d1 == 1)
								{
									if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
											B[b] = B[b - 3];
										else
											B[b] = B[b - 3] + 1;
										A[b] = 0;
										a = 0;
										c = 0;
									}
								}
								else if (e1 == 1)
								{
									if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										A[b] = 5;
										B[b] = B[b - 3] + 1;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = D.state;
											B[b] = B[b - 3] + 1;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = E.state;
											B[b] = B[b - 3] + 1;
											a = 0;
											c = 0;
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
					}
					else if (A[b - 3] == 2)
					{
						if (B[b - 3] == 1)
						{
							if (C.v_rand_1 || C.v_rand_15 == 1)
							{
								if (a1&&b1&&c1&&d1 == 1)
								{
									if (C.v_rand_2 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										if (C.v_rand_3 == 1)
											B[b] = B[b - 3];
										else
											B[b] = B[b - 3] + 1;
										A[b] = 0;
										a = 0;
										c = 0;
									}
								}
								else if (e1 == 1)
								{
									if (C.v_rand_2 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										A[b] = 5;
										B[b] = B[b - 3] + 1;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (D.state == 2)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if (D.state == 1)
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_3 == 1)
													B[b] = B[b - 3];
												else
													B[b] = B[b - 3] + 1;
												A[b] = D.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = D.state;
												B[b] = B[b - 3] + 1;
												a = 0;
												c = 0;
											}
										}
									}
									else
									{
										if (E.state == 2)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if (E.state == 1)
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_3 == 1)
													B[b] = B[b - 3];
												else
													B[b] = B[b - 3] + 1;
												A[b] = E.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = E.state;
												B[b] = B[b - 3] + 1;
												a = 0;
												c = 0;
											}
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else if (B[b - 3] < 3)
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3 == 1)
							{
								if (a1&&b1&&c1&&d1 == 1)
								{
									if (C.v_rand_4 || C.v_rand_5 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										if (C.v_rand_6 || C.v_rand_7 == 1)
											B[b] = B[b - 3];
										else
											B[b] = B[b - 3] + 1;
										A[b] = 0;
										a = 0;
										c = 0;
									}
								}
								else if (e1 == 1)
								{
									if (C.v_rand_4 || C.v_rand_5 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										A[b] = 5;
										B[b] = B[b - 3] + 1;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (D.state == 2)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if (D.state == 1)
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_6 || C.v_rand_7 == 1)
													B[b] = B[b - 3];
												else
													B[b] = B[b - 3] + 1;
												A[b] = D.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = D.state;
												B[b] = B[b - 3] + 1;
												a = 0;
												c = 0;
											}
										}
									}
									else
									{
										if (E.state == 2)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if (E.state == 1)
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_6 || C.v_rand_7 == 1)
													B[b] = B[b - 3];
												else
													B[b] = B[b - 3] + 1;
												A[b] = E.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = E.state;
												B[b] = B[b - 3] + 1;
												a = 0;
												c = 0;
											}
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3&&C.v_rand_4&&C.v_rand_5&&C.v_rand_6 == 1)
							{
								if (a1&&b1&&c1&&d1 == 1)
								{
									if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
											B[b] = B[b - 3];
										else
											B[b] = B[b - 3] + 1;
										A[b] = 0;
										a = 0;
										c = 0;
									}
								}
								else if (e1 == 1)
								{
									if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										A[b] = 5;
										B[b] = B[b - 3] + 1;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (D.state == 2)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if (D.state == 1)
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
													B[b] = B[b - 3];
												else
													B[b] = B[b - 3] + 1;
												A[b] = D.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = D.state;
												B[b] = B[b - 3] + 1;
												a = 0;
												c = 0;
											}
										}
									}
									else
									{
										if (E.state == 2)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if (E.state == 1)
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
													B[b] = B[b - 3];
												else
													B[b] = B[b - 3] + 1;
												A[b] = E.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = E.state;
												B[b] = B[b - 3] + 1;
												a = 0;
												c = 0;
											}
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
					}
					else if (A[b - 3] == 3)
					{
						if (B[b - 3] == 1)
						{
							if (C.v_rand_1 || C.v_rand_15 == 1)
							{
								if (a1&&b1&&c1&&d1 == 1)
								{
									if (C.v_rand_2 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										if (C.v_rand_3 == 1)
											B[b] = B[b - 3];
										else
											B[b] = B[b - 3] + 1;
										A[b] = 0;
										a = 0;
										c = 0;
									}
								}
								else if (e1 == 1)
								{
									if (C.v_rand_2 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										A[b] = 5;
										B[b] = B[b - 3] + 1;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (D.state == 3)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if ((D.state == 1) || (D.state == 2) == 1)
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_3 == 1)
													B[b] = B[b - 3];
												else
													B[b] = B[b - 3] + 1;
												A[b] = D.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = D.state;
												B[b] = B[b - 3] + 1;
												a = 0;
												c = 0;
											}
										}
									}
									else
									{
										if (E.state == 3)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if ((E.state == 1) || (E.state == 2) == 1)
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_3 == 1)
													B[b] = B[b - 3];
												else
													B[b] = B[b - 3] + 1;
												A[b] = E.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = E.state;
												B[b] = B[b - 3] + 1;
												a = 0;
												c = 0;
											}
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else if (B[b - 3] < 3)
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3 == 1)
							{
								if (a1&&b1&&c1&&d1 == 1)
								{
									if (C.v_rand_4 || C.v_rand_5 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										if (C.v_rand_6 || C.v_rand_7 == 1)
											B[b] = B[b - 3];
										else
											B[b] = B[b - 3] + 1;
										A[b] = 0;
										a = 0;
										c = 0;
									}
								}
								else if (e1 == 1)
								{
									if (C.v_rand_4 || C.v_rand_5 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										A[b] = 5;
										B[b] = B[b - 3] + 1;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (D.state == 3)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if ((D.state == 1) || (D.state == 2) == 1)
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_6 || C.v_rand_7 == 1)
													B[b] = B[b - 3];
												else
													B[b] = B[b - 3] + 1;
												A[b] = D.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = D.state;
												B[b] = B[b - 3] + 1;
												a = 0;
												c = 0;
											}
										}
									}
									else
									{
										if (E.state == 3)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if ((E.state == 1) || (E.state == 2) == 1)
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_6 || C.v_rand_7 == 1)
													B[b] = B[b - 3];
												else
													B[b] = B[b - 3] + 1;
												A[b] = E.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = E.state;
												B[b] = B[b - 3] + 1;
												a = 0;
												c = 0;
											}
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3&&C.v_rand_4&&C.v_rand_5&&C.v_rand_6 == 1)
							{
								if (a1&&b1&&c1&&d1 == 1)
								{
									if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
											B[b] = B[b - 3];
										else
											B[b] = B[b - 3] + 1;
										A[b] = 0;
										a = 0;
										c = 0;
									}
								}
								else if (e1 == 1)
								{
									if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										A[b] = 5;
										B[b] = B[b - 3] + 1;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (D.state == 3)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if ((D.state == 1) || (D.state == 2) == 1)
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
													B[b] = B[b - 3];
												else
													B[b] = B[b - 3] + 1;
												A[b] = D.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = D.state;
												B[b] = B[b - 3] + 1;
												a = 0;
												c = 0;
											}
										}
									}
									else
									{
										if (E.state == 3)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if ((E.state == 1) || (E.state == 2) == 1)
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
													B[b] = B[b - 3];
												else
													B[b] = B[b - 3] + 1;
												A[b] = E.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = E.state;
												B[b] = B[b - 3] + 1;
												a = 0;
												c = 0;
											}
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
					}
					else if (A[b - 3] == 4)
					{
						if (B[b - 3] == 1)
						{
							if (C.v_rand_1 || C.v_rand_15 == 1)
							{
								if (a1&&b1&&c1&&d1 == 1)
								{
									if (C.v_rand_2 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										if (C.v_rand_3 == 1)
											B[b] = B[b - 3];
										else
											B[b] = B[b - 3] + 1;
										A[b] = 0;
										a = 0;
										c = 0;
									}
								}
								else if (e1 == 1)
								{
									if (C.v_rand_2 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										A[b] = 5;
										B[b] = B[b - 3] + 1;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (D.state == 4)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										//�W�@�H�۪���⬰����,�T�b���ɳ۶®�,����,����ҥi��ܽu��O�_�n+1
										else
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_3 == 1)
													B[b] = B[b - 3];
												else
													B[b] = B[b - 3] + 1;
												A[b] = D.state;
												a = 0;
												c = 0;
											}
										}
									}
									else
									{
										if (E.state == 4)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_3 == 1)
													B[b] = B[b - 3];
												else
													B[b] = B[b - 3] + 1;
												A[b] = E.state;
												a = 0;
												c = 0;
											}
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else if (B[b - 3] < 3)
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3 == 1)
							{
								if (a1&&b1&&c1&&d1 == 1)
								{
									if (C.v_rand_4 || C.v_rand_5 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										if (C.v_rand_6 || C.v_rand_7 == 1)
											B[b] = B[b - 3];
										else
											B[b] = B[b - 3] + 1;
										A[b] = 0;
										a = 0;
										c = 0;
									}
								}
								else if (e1 == 1)
								{
									if (C.v_rand_4 || C.v_rand_5 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										A[b] = 5;
										B[b] = B[b - 3] + 1;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (D.state == 4)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										//�W�@�H�۪���⬰����,�T�b���ɳ۶®�,����,����ҥi��ܽu��O�_�n+1
										else
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_6 || C.v_rand_7 == 1)
													B[b] = B[b - 3];
												else
													B[b] = B[b - 3] + 1;
												A[b] = D.state;
												a = 0;
												c = 0;
											}
										}
									}
									else
									{
										if (E.state == 4)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_6 || C.v_rand_7 == 1)
													B[b] = B[b - 3];
												else
													B[b] = B[b - 3] + 1;
												A[b] = E.state;
												a = 0;
												c = 0;
											}
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3&&C.v_rand_4&&C.v_rand_5&&C.v_rand_6 == 1)
							{
								if (a1&&b1&&c1&&d1 == 1)
								{
									if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
											B[b] = B[b - 3];
										else
											B[b] = B[b - 3] + 1;
										A[b] = 0;
										a = 0;
										c = 0;
									}
								}
								else if (e1 == 1)
								{
									if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										A[b] = 5;
										B[b] = B[b - 3] + 1;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (D.state == 4)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										//�W�@�H�۪���⬰����,�T�b���ɳ۶®�,����,����ҥi��ܽu��O�_�n+1
										else
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
													B[b] = B[b - 3];
												else
													B[b] = B[b - 3] + 1;
												A[b] = D.state;
												a = 0;
												c = 0;
											}
										}
									}
									else
									{
										if (E.state == 4)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
													B[b] = B[b - 3];
												else
													B[b] = B[b - 3] + 1;
												A[b] = E.state;
												a = 0;
												c = 0;
											}
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
					}
					else
					{
						if (B[b - 3] == 1)
						{
							if (C.v_rand_1 || C.v_rand_15 == 1)
							{
								if (a1&&b1&&c1&&d1 == 1)
								{
									if (C.v_rand_2 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										if (C.v_rand_3 == 1)
											B[b] = B[b - 3];
										else
											B[b] = B[b - 3] + 1;
										A[b] = 0;
										a = 0;
										c = 0;
									}
								}
								else if (e1 == 1)
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									//c = b - 1;
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (C.v_rand_2 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_3 == 1)
												B[b] = B[b - 3];
											else
												B[b] = B[b - 3] + 1;
											A[b] = D.state;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_2 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_3 == 1)
												B[b] = B[b - 3];
											else
												B[b] = B[b - 3] + 1;
											A[b] = E.state;
											a = 0;
											c = 0;
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else if (B[b - 3] < 3)
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3 == 1)
							{
								if (a1&&b1&&c1&&d1 == 1)
								{
									if (C.v_rand_4 || C.v_rand_5 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										if (C.v_rand_6 || C.v_rand_7 == 1)
											B[b] = B[b - 3];
										else
											B[b] = B[b - 3] + 1;
										A[b] = 0;
										a = 0;
										c = 0;
									}
								}
								else if (e1 == 1)
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									//c = b - 1;
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_6 || C.v_rand_7 == 1)
												B[b] = B[b - 3];
											else
												B[b] = B[b - 3] + 1;
											A[b] = D.state;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_6 || C.v_rand_7 == 1)
												B[b] = B[b - 3];
											else
												B[b] = B[b - 3] + 1;
											A[b] = E.state;
											a = 0;
											c = 0;
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3&&C.v_rand_4&&C.v_rand_5&&C.v_rand_6 == 1)
							{
								if (a1&&b1&&c1&&d1 == 1)
								{
									if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
											B[b] = B[b - 3];
										else
											B[b] = B[b - 3] + 1;
										A[b] = 0;
										a = 0;
										c = 0;
									}
								}
								else if (e1 == 1)
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									//c = b - 1;
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
												B[b] = B[b - 3];
											else
												B[b] = B[b - 3] + 1;
											A[b] = D.state;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
												B[b] = B[b - 3];
											else
												B[b] = B[b - 3] + 1;
											A[b] = E.state;
											a = 0;
											c = 0;
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
					}
				}
				else
				{
					//���Ҽ{���,�E�ƬݬO+1�η���!!
					//�Y�W�@�ӤH�۵L��
					if (A[b - 3] == 0)
					{
						//�Ҽ{�W�@��ۥX���u��
						if (B[b - 3] == 1)
						{
							//�@�b�����v�۷s�����
							if (C.v_rand_1 || C.v_rand_15 == 1)
							{
								//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
									if (best_state == 0)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										A[b] = best_state;
										B[b] = B[b - 3] + 1;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (C.v_rand_2 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = D.state;
											B[b] = B[b - 3] + 1;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_2 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = E.state;
											B[b] = B[b - 3] + 1;
											a = 0;
											c = 0;
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else if (B[b - 3] < 3)
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3 ||
								((D.big_point>6) || (E.big_point>6) || (F.big_point>7) || (G.big_point>7)) ||
								((D.small_point>6) || (E.small_point>6) || (F.small_point>7) || (G.small_point>7)) == 1)
							{
								//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
									if (best_state == 0)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = best_state;
											B[b] = B[b - 3] + 1;
											a = 0;
											c = 0;
										}
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = D.state;
											B[b] = B[b - 3] + 1;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = E.state;
											B[b] = B[b - 3] + 1;
											a = 0;
											c = 0;
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3&&C.v_rand_4&&C.v_rand_5&&C.v_rand_6 ||
								((D.big_point > 7) || (E.big_point > 7) || (F.big_point > 8) || (G.big_point > 8)) ||
								((D.small_point > 7) || (E.small_point > 7) || (F.small_point > 8) || (G.small_point > 8)) == 1)
							{
								//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
									if (best_state == 0)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = best_state;
											B[b] = B[b - 3] + 1;
											a = 0;
											c = 0;
										}
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = D.state;
											B[b] = B[b - 3] + 1;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = E.state;
											B[b] = B[b - 3] + 1;
											a = 0;
											c = 0;
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
					}
					//�Y�W�@�ӤH�ۥ|�����@
					else if (A[b - 3] == 1)
					{
						//�Ҽ{�W�@��ۥX���u��
						if (B[b - 3] == 1)
						{
							//�@�b�����v�۷s�����
							if (C.v_rand_1 || C.v_rand_15 == 1)
							{
								//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
									if (best_state == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else if (best_state == 0)
									{
										if (C.v_rand_2 == 1)
											B[b] = B[b - 3];
										else
											B[b] = B[b - 3] + 1;
										A[b] = best_state;
										a = 0;
										c = 0;
									}
									else
									{
										A[b] = best_state;
										B[b] = B[b - 3] + 1;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (D.state == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = D.state;
												B[b] = B[b - 3] + 1;
												a = 0;
												c = 0;
											}
										}
									}
									else
									{
										if (E.state == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = E.state;
												B[b] = B[b - 3] + 1;
												a = 0;
												c = 0;
											}
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else if (B[b - 3] < 3)
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3 ||
								((D.big_point>6) || (E.big_point>6) || (F.big_point>7) || (G.big_point>7)) ||
								((D.small_point>6) || (E.small_point>6) || (F.small_point>7) || (G.small_point>7)) == 1)
							{
								//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
									if (best_state == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else if (best_state == 0)
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_6 || C.v_rand_7 == 1)
												B[b] = B[b - 3];
											else
												B[b] = B[b - 3] + 1;
											A[b] = best_state;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = best_state;
											B[b] = B[b - 3] + 1;
											a = 0;
											c = 0;
										}
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (D.state == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = D.state;
												B[b] = B[b - 3] + 1;
												a = 0;
												c = 0;
											}
										}
									}
									else
									{
										if (E.state == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = E.state;
												B[b] = B[b - 3] + 1;
												a = 0;
												c = 0;
											}
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3&&C.v_rand_4&&C.v_rand_5&&C.v_rand_6 ||
								((D.big_point > 7) || (E.big_point > 7) || (F.big_point > 8) || (G.big_point > 8)) ||
								((D.small_point > 7) || (E.small_point > 7) || (F.small_point > 8) || (G.small_point > 8)) == 1)
							{
								//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
									if (best_state == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else if (best_state == 0)
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
												B[b] = B[b - 3];
											else
												B[b] = B[b - 3] + 1;
											A[b] = best_state;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = best_state;
											B[b] = B[b - 3] + 1;
											a = 0;
											c = 0;
										}
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (D.state == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = D.state;
												B[b] = B[b - 3] + 1;
												a = 0;
												c = 0;
											}
										}
									}
									else
									{
										if (E.state == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = E.state;
												B[b] = B[b - 3] + 1;
												a = 0;
												c = 0;
											}
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
					}
					else if (A[b - 3] == 2)
					{
						//�Ҽ{�W�@��ۥX���u��
						if (B[b - 3] == 1)
						{
							//�@�b�����v�۷s�����
							if (C.v_rand_1 || C.v_rand_15 == 1)
							{
								//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
									if (best_state == 2)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else if ((best_state == 0) || (best_state == 1) == 1)
									{
										if (C.v_rand_2 == 1)
											B[b] = B[b - 3];
										else
											B[b] = B[b - 3] + 1;
										A[b] = best_state;
										a = 0;
										c = 0;
									}
									else
									{
										A[b] = best_state;
										B[b] = B[b - 3] + 1;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (D.state == 2)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if (D.state == 1)
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_3 == 1)
													B[b] = B[b - 3];
												else
													B[b] = B[b - 3] + 1;
												A[b] = D.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = D.state;
												B[b] = B[b - 3] + 1;
												a = 0;
												c = 0;
											}
										}
									}
									else
									{
										if (E.state == 2)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if (E.state == 1)
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_3 == 1)
													B[b] = B[b - 3];
												else
													B[b] = B[b - 3] + 1;
												A[b] = E.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = E.state;
												B[b] = B[b - 3] + 1;
												a = 0;
												c = 0;
											}
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else if (B[b - 3] < 3)
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3 ||
								((D.big_point>6) || (E.big_point>6) || (F.big_point>7) || (G.big_point>7)) ||
								((D.small_point>6) || (E.small_point>6) || (F.small_point>7) || (G.small_point>7)) == 1)
							{
								//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
									if (best_state == 2)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else if ((best_state == 0) || (best_state == 1) == 1)
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_6 || C.v_rand_7 == 1)
												B[b] = B[b - 3];
											else
												B[b] = B[b - 3] + 1;
											A[b] = best_state;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = best_state;
											B[b] = B[b - 3] + 1;
											a = 0;
											c = 0;
										}
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (D.state == 2)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if (D.state == 1)
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_6 || C.v_rand_7 == 1)
													B[b] = B[b - 3];
												else
													B[b] = B[b - 3] + 1;
												A[b] = D.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = D.state;
												B[b] = B[b - 3] + 1;
												a = 0;
												c = 0;
											}
										}
									}
									else
									{
										if (E.state == 2)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if (E.state == 1)
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_6 || C.v_rand_7 == 1)
													B[b] = B[b - 3];
												else
													B[b] = B[b - 3] + 1;
												A[b] = E.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = E.state;
												B[b] = B[b - 3] + 1;
												a = 0;
												c = 0;
											}
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3&&C.v_rand_4&&C.v_rand_5&&C.v_rand_6 ||
								((D.big_point > 7) || (E.big_point > 7) || (F.big_point > 8) || (G.big_point > 8)) ||
								((D.small_point > 7) || (E.small_point > 7) || (F.small_point > 8) || (G.small_point > 8)) == 1)
							{
								//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
									if (best_state == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else if ((best_state == 0) || (best_state == 1) == 1)
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
												B[b] = B[b - 3];
											else
												B[b] = B[b - 3] + 1;
											A[b] = best_state;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = best_state;
											B[b] = B[b - 3] + 1;
											a = 0;
											c = 0;
										}
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (D.state == 2)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if (D.state == 1)
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
													B[b] = B[b - 3];
												else
													B[b] = B[b - 3] + 1;
												A[b] = D.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = D.state;
												B[b] = B[b - 3] + 1;
												a = 0;
												c = 0;
											}
										}
									}
									else
									{
										if (E.state == 2)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if (E.state == 1)
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
													B[b] = B[b - 3];
												else
													B[b] = B[b - 3] + 1;
												A[b] = E.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = E.state;
												B[b] = B[b - 3] + 1;
												a = 0;
												c = 0;
											}
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
					}
					else if (A[b - 3] == 3)
					{
						//�Ҽ{�W�@��ۥX���u��
						if (B[b - 3] == 1)
						{
							//�@�b�����v�۷s�����
							if (C.v_rand_1 || C.v_rand_15 == 1)
							{
								//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
									if (best_state == 3)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else if ((best_state == 0) || (best_state == 1) || (best_state == 2) == 1)
									{
										if (C.v_rand_2 == 1)
											B[b] = B[b - 3];
										else
											B[b] = B[b - 3] + 1;
										A[b] = best_state;
										a = 0;
										c = 0;
									}
									else
									{
										A[b] = best_state;
										B[b] = B[b - 3] + 1;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (D.state == 3)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if ((D.state == 1) || (D.state == 2) == 1)
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_3 == 1)
													B[b] = B[b - 3];
												else
													B[b] = B[b - 3] + 1;
												A[b] = D.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = D.state;
												B[b] = B[b - 3] + 1;
												a = 0;
												c = 0;
											}
										}
									}
									else
									{
										if (E.state == 3)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if ((E.state == 1) || (E.state == 2) == 1)
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_3 == 1)
													B[b] = B[b - 3];
												else
													B[b] = B[b - 3] + 1;
												A[b] = E.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = E.state;
												B[b] = B[b - 3] + 1;
												a = 0;
												c = 0;
											}
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else if (B[b - 3] < 3)
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3 ||
								((D.big_point>6) || (E.big_point>6) || (F.big_point>7) || (G.big_point>7)) ||
								((D.small_point>6) || (E.small_point>6) || (F.small_point>7) || (G.small_point>7)) == 1)
							{
								//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
									if (best_state == 3)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else if ((best_state == 0) || (best_state == 1) || (best_state == 2) == 1)
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_6 || C.v_rand_7 == 1)
												B[b] = B[b - 3];
											else
												B[b] = B[b - 3] + 1;
											A[b] = best_state;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = best_state;
											B[b] = B[b - 3] + 1;
											a = 0;
											c = 0;
										}
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (D.state == 3)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if ((D.state == 1) || (D.state == 2) == 1)
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_6 || C.v_rand_7 == 1)
													B[b] = B[b - 3];
												else
													B[b] = B[b - 3] + 1;
												A[b] = D.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = D.state;
												B[b] = B[b - 3] + 1;
												a = 0;
												c = 0;
											}
										}
									}
									else
									{
										if (E.state == 3)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if ((E.state == 1) || (E.state == 2) == 1)
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_6 || C.v_rand_7 == 1)
													B[b] = B[b - 3];
												else
													B[b] = B[b - 3] + 1;
												A[b] = E.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = E.state;
												B[b] = B[b - 3] + 1;
												a = 0;
												c = 0;
											}
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3&&C.v_rand_4&&C.v_rand_5&&C.v_rand_6 ||
								((D.big_point > 7) || (E.big_point > 7) || (F.big_point > 8) || (G.big_point > 8)) ||
								((D.small_point > 7) || (E.small_point > 7) || (F.small_point > 8) || (G.small_point > 8)) == 1)
							{
								//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
									if (best_state == 3)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else if ((best_state == 0) || (best_state == 1) || (best_state == 2) == 1)
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
												B[b] = B[b - 3];
											else
												B[b] = B[b - 3] + 1;
											A[b] = best_state;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = best_state;
											B[b] = B[b - 3] + 1;
											a = 0;
											c = 0;
										}
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (D.state == 3)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if ((D.state == 1) || (D.state == 2) == 1)
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
													B[b] = B[b - 3];
												else
													B[b] = B[b - 3] + 1;
												A[b] = D.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = D.state;
												B[b] = B[b - 3] + 1;
												a = 0;
												c = 0;
											}
										}
									}
									else
									{
										if (E.state == 3)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if ((E.state == 1) || (E.state == 2) == 1)
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
													B[b] = B[b - 3];
												else
													B[b] = B[b - 3] + 1;
												A[b] = E.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = E.state;
												B[b] = B[b - 3] + 1;
												a = 0;
												c = 0;
											}
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
					}
					else if (A[b - 3] == 4)
					{
						//�Ҽ{�W�@��ۥX���u��
						if (B[b - 3] == 1)
						{
							//�@�b�����v�۷s�����
							if (C.v_rand_1 || C.v_rand_15 == 1)
							{
								//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
									if (best_state == 4)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else if ((best_state == 0) || (best_state == 1) || (best_state == 2) || (best_state == 3) == 1)
									{
										if (C.v_rand_2 == 1)
											B[b] = B[b - 3];
										else
											B[b] = B[b - 3] + 1;
										A[b] = best_state;
										a = 0;
										c = 0;
									}
									else
									{
										A[b] = best_state;
										B[b] = B[b - 3] + 1;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (D.state == 4)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										//�W�@�H�۪���⬰����,�T�b���ɳ۶®�,����,����ҥi��ܽu��O�_�n+1
										else
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_3 == 1)
													B[b] = B[b - 3];
												else
													B[b] = B[b - 3] + 1;
												A[b] = D.state;
												a = 0;
												c = 0;
											}
										}
									}
									else
									{
										if (E.state == 4)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_3 == 1)
													B[b] = B[b - 3];
												else
													B[b] = B[b - 3] + 1;
												A[b] = E.state;
												a = 0;
												c = 0;
											}
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else if (B[b - 3] < 3)
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3 ||
								((D.big_point>6) || (E.big_point>6) || (F.big_point>7) || (G.big_point>7)) ||
								((D.small_point>6) || (E.small_point>6) || (F.small_point>7) || (G.small_point>7)) == 1)
							{
								//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
									if (best_state == 4)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else if ((best_state == 0) || (best_state == 1) || (best_state == 2) || (best_state == 3) == 1)
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_6 || C.v_rand_7 == 1)
												B[b] = B[b - 3];
											else
												B[b] = B[b - 3] + 1;
											A[b] = best_state;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = best_state;
											B[b] = B[b - 3] + 1;
											a = 0;
											c = 0;
										}
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (D.state == 4)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										//�W�@�H�۪���⬰����,�T�b���ɳ۶®�,����,����ҥi��ܽu��O�_�n+1
										else
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_6 || C.v_rand_7 == 1)
													B[b] = B[b - 3];
												else
													B[b] = B[b - 3] + 1;
												A[b] = D.state;
												a = 0;
												c = 0;
											}
										}
									}
									else
									{
										if (E.state == 4)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_6 || C.v_rand_7 == 1)
													B[b] = B[b - 3];
												else
													B[b] = B[b - 3] + 1;
												A[b] = E.state;
												a = 0;
												c = 0;
											}
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3&&C.v_rand_4&&C.v_rand_5&&C.v_rand_6 ||
								((D.big_point > 7) || (E.big_point > 7) || (F.big_point > 8) || (G.big_point > 8)) ||
								((D.small_point > 7) || (E.small_point > 7) || (F.small_point > 8) || (G.small_point > 8)) == 1)
							{
								//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
									if (best_state == 4)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else if ((best_state == 0) || (best_state == 1) || (best_state == 2) || (best_state == 3) == 1)
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
												B[b] = B[b - 3];
											else
												B[b] = B[b - 3] + 1;
											A[b] = best_state;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = best_state;
											B[b] = B[b - 3] + 1;
											a = 0;
											c = 0;
										}
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (D.state == 4)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										//�W�@�H�۪���⬰����,�T�b���ɳ۶®�,����,����ҥi��ܽu��O�_�n+1
										else
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
													B[b] = B[b - 3];
												else
													B[b] = B[b - 3] + 1;
												A[b] = D.state;
												a = 0;
												c = 0;
											}
										}
									}
									else
									{
										if (E.state == 4)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
													B[b] = B[b - 3];
												else
													B[b] = B[b - 3] + 1;
												A[b] = E.state;
												a = 0;
												c = 0;
											}
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
					}
					//�Y�W�@�ӤH��small
					else
					{
						//�Ҽ{�W�@��ۥX���u��
						if (B[b - 3] == 1)
						{
							//�@�b�����v�۷s�����
							if (C.v_rand_1 || C.v_rand_15 == 1)
							{
								//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
									if (best_state == 5)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										if (C.v_rand_2 == 1)
											B[b] = B[b - 3];
										else
											B[b] = B[b - 3] + 1;
										A[b] = best_state;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (C.v_rand_2 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_3 == 1)
												B[b] = B[b - 3];
											else
												B[b] = B[b - 3] + 1;
											A[b] = D.state;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_2 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_3 == 1)
												B[b] = B[b - 3];
											else
												B[b] = B[b - 3] + 1;
											A[b] = E.state;
											a = 0;
											c = 0;
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else if (B[b - 3] < 3)
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3 ||
								((D.big_point>6) || (E.big_point>6) || (F.big_point>7) || (G.big_point>7)) ||
								((D.small_point>6) || (E.small_point>6) || (F.small_point>7) || (G.small_point>7)) == 1)
							{
								//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
									if (best_state == 5)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
											B[b] = B[b - 3];
										else
											B[b] = B[b - 3] + 1;
										A[b] = best_state;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_6 || C.v_rand_7 == 1)
												B[b] = B[b - 3];
											else
												B[b] = B[b - 3] + 1;
											A[b] = D.state;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_6 || C.v_rand_7 == 1)
												B[b] = B[b - 3];
											else
												B[b] = B[b - 3] + 1;
											A[b] = E.state;
											a = 0;
											c = 0;
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3&&C.v_rand_4&&C.v_rand_5&&C.v_rand_6 ||
								((D.big_point > 7) || (E.big_point > 7) || (F.big_point > 8) || (G.big_point > 8)) ||
								((D.small_point > 7) || (E.small_point > 7) || (F.small_point > 8) || (G.small_point > 8)) == 1)
							{
								//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
									if (best_state == 5)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											B[b] = B[b - 3];
										else
											B[b] = B[b - 3] + 1;
										A[b] = best_state;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
												B[b] = B[b - 3];
											else
												B[b] = B[b - 3] + 1;
											A[b] = D.state;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
												B[b] = B[b - 3];
											else
												B[b] = B[b - 3] + 1;
											A[b] = E.state;
											a = 0;
											c = 0;
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
					}
				}
			}
		}
		//�Ѧ�b-2���P!!
		else if (a == 1)
		{
			int partner_color[2]; //�s�����ͥs�L�����
			int enemy1_color[2], enemy2_color[2]; //�s������H�s�L�����
												  //�|��ڶ��ͩM����C�H�̪�⦸�s�P�i����R
			if (b>7)
			{
				for (int i = 0; i < 2; i++)
					partner_color[i] = A[b - 2 - 4 * i];
				for (int i = 0; i < 2; i++)
				{
					enemy1_color[i] = A[b - 3 - 4 * i];
					enemy2_color[i] = A[b - 1 - 4 * i];
				}
				int temp0 = 0, temp1 = 0, temp2 = 0, temp3 = 0, temp4 = 0, temp5 = 0, temp_no = 0;
				for (int i = 0; i < 2; i++)
				{
					if (partner_color[i] == D.state)
						temp1 += i + 1;
					else if (partner_color[i] == E.state)
						temp2 += i + 1;
					else if (partner_color[i] == F.state)
						temp3 += i + 1;
					else if (partner_color[i] == G.state)
						temp4 += i + 1;
					else if (partner_color[i] == 0)
						temp0 += i + 1;
					else if (partner_color[i] == 5)
						temp5 += i + 1;
					else
						temp_no += i + 1;
					if (enemy1_color[i] == D.state)
						temp1 -= i + 1;
					else if (enemy1_color[i] == E.state)
						temp2 -= i + 1;
					else if (enemy1_color[i] == F.state)
						temp3 -= i + 1;
					else if (enemy1_color[i] == G.state)
						temp4 -= i + 1;
					else if (enemy1_color[i] == 0)
						temp0 -= i + 1;
					else if (enemy1_color[i] == 5)
						temp5 -= i + 1;
					else
						temp_no -= i + 1;
					if (enemy2_color[i] == D.state)
						temp1 -= i + 1;
					else if (enemy2_color[i] == E.state)
						temp2 -= i + 1;
					else if (enemy2_color[i] == F.state)
						temp3 -= i + 1;
					else if (enemy2_color[i] == G.state)
						temp4 -= i + 1;
					else if (enemy2_color[i] == 0)
						temp0 -= i + 1;
					else if (enemy2_color[i] == 5)
						temp5 -= i + 1;
					else
						temp_no -= i + 1;
				}
				int P[7] = { temp0,temp1,temp2,temp3,temp4,temp5,temp_no };
				int best_state;
				int bubble_sort[7] = { temp0,temp1,temp2,temp3,temp4,temp5,temp_no };
				for (int i = 6; i >= 0; i--)
				{
					for (int j = 0; j < i; j++)
					{
						int t;
						if (bubble_sort[j] < bubble_sort[j + 1])
						{
							t = bubble_sort[j + 1];
							bubble_sort[j + 1] = bubble_sort[j];
							bubble_sort[j] = t;
						}
					}
				}
				for (int i = 0; i < 7; i++)
				{
					if (bubble_sort[0] == P[i])
					{
						if (i == 0)
							best_state = 0;
						else if (i == 1)
							best_state = D.state;
						else if (i == 2)
							best_state = E.state;
						else if (i == 3)
							best_state = F.state;
						else if (i == 4)
							best_state = G.state;
						else if (i == 5)
							best_state = 5;
						else
							best_state = D.state;
						break;
					}
				}
				//���|�X�{A[b-1]=6������,�]���W�W�@�ӤH���w�S��accept!!
				if (bubble_sort[0] == bubble_sort[1]) //���]�䤣��̨θ�,���ɵL�k���T�M�w�n�۪����
				{
					if (A[b - 2] == 0)
					{
						if (B[b - 2] == 1)
						{
							if (C.v_rand_1 || C.v_rand_15 == 1)
							{
								if (a1&&b1&&c1&&d1 == 1)
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									//c = b - 1;
								}
								else if (e1 == 1)
								{
									if (C.v_rand_2 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										A[b] = 5;
										B[b] = B[b - 2] + 1;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (C.v_rand_2 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = D.state;
											B[b] = B[b - 2] + 1;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_2 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = E.state;
											B[b] = B[b - 2] + 1;
											a = 0;
											c = 0;
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else if (B[b - 2] < 3)
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3 == 1)
							{
								if (a1&&b1&&c1&&d1 == 1)
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									//c = b - 1;
								}
								else if (e1 == 1)
								{
									if (C.v_rand_4 || C.v_rand_5 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										A[b] = 5;
										B[b] = B[b - 2] + 1;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = D.state;
											B[b] = B[b - 2] + 1;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = E.state;
											B[b] = B[b - 2] + 1;
											a = 0;
											c = 0;
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3&&C.v_rand_4&&C.v_rand_5&&C.v_rand_6 == 1)
							{
								if (a1&&b1&&c1&&d1 == 1)
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									//c = b - 1;
								}
								else if (e1 == 1)
								{
									if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										A[b] = 5;
										B[b] = B[b - 2] + 1;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = D.state;
											B[b] = B[b - 2] + 1;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = E.state;
											B[b] = B[b - 2] + 1;
											a = 0;
											c = 0;
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
					}
					else if (A[b - 2] == 1)
					{
						if (B[b - 2] == 1)
						{
							if (C.v_rand_1 || C.v_rand_15 == 1)
							{
								if (a1&&b1&&c1&&d1 == 1)
								{
									if (C.v_rand_2 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										if (C.v_rand_3 == 1)
											B[b] = B[b - 2];
										else
											B[b] = B[b - 2] + 1;
										A[b] = 0;
										a = 0;
										c = 0;
									}
								}
								else if (e1 == 1)
								{
									if (C.v_rand_2 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										A[b] = 5;
										B[b] = B[b - 2] + 1;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (C.v_rand_2 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = D.state;
											B[b] = B[b - 2] + 1;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_2 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = E.state;
											B[b] = B[b - 2] + 1;
											a = 0;
											c = 0;
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else if (B[b - 2] < 3)
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3 == 1)
							{
								if (a1&&b1&&c1&&d1 == 1)
								{
									if (C.v_rand_4 || C.v_rand_5 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										if (C.v_rand_6 || C.v_rand_7 == 1)
											B[b] = B[b - 2];
										else
											B[b] = B[b - 2] + 1;
										A[b] = 0;
										a = 0;
										c = 0;
									}
								}
								else if (e1 == 1)
								{
									if (C.v_rand_4 || C.v_rand_5 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										A[b] = 5;
										B[b] = B[b - 2] + 1;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = D.state;
											B[b] = B[b - 2] + 1;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = E.state;
											B[b] = B[b - 2] + 1;
											a = 0;
											c = 0;
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3&&C.v_rand_4&&C.v_rand_5&&C.v_rand_6 == 1)
							{
								if (a1&&b1&&c1&&d1 == 1)
								{
									if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
											B[b] = B[b - 2];
										else
											B[b] = B[b - 2] + 1;
										A[b] = 0;
										a = 0;
										c = 0;
									}
								}
								else if (e1 == 1)
								{
									if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										A[b] = 5;
										B[b] = B[b - 2] + 1;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = D.state;
											B[b] = B[b - 2] + 1;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = E.state;
											B[b] = B[b - 2] + 1;
											a = 0;
											c = 0;
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
					}
					else if (A[b - 2] == 2)
					{
						if (B[b - 2] == 1)
						{
							if (C.v_rand_1 || C.v_rand_15 == 1)
							{
								if (a1&&b1&&c1&&d1 == 1)
								{
									if (C.v_rand_2 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										if (C.v_rand_3 == 1)
											B[b] = B[b - 2];
										else
											B[b] = B[b - 2] + 1;
										A[b] = 0;
										a = 0;
										c = 0;
									}
								}
								else if (e1 == 1)
								{
									if (C.v_rand_2 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										A[b] = 5;
										B[b] = B[b - 2] + 1;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (D.state == 2)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if (D.state == 1)
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_3 == 1)
													B[b] = B[b - 2];
												else
													B[b] = B[b - 2] + 1;
												A[b] = D.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = D.state;
												B[b] = B[b - 2] + 1;
												a = 0;
												c = 0;
											}
										}
									}
									else
									{
										if (E.state == 2)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if (E.state == 1)
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_3 == 1)
													B[b] = B[b - 2];
												else
													B[b] = B[b - 2] + 1;
												A[b] = E.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = E.state;
												B[b] = B[b - 2] + 1;
												a = 0;
												c = 0;
											}
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else if (B[b - 2] < 3)
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3 == 1)
							{
								if (a1&&b1&&c1&&d1 == 1)
								{
									if (C.v_rand_4 || C.v_rand_5 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										if (C.v_rand_6 || C.v_rand_7 == 1)
											B[b] = B[b - 2];
										else
											B[b] = B[b - 2] + 1;
										A[b] = 0;
										a = 0;
										c = 0;
									}
								}
								else if (e1 == 1)
								{
									if (C.v_rand_4 || C.v_rand_5 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										A[b] = 5;
										B[b] = B[b - 2] + 1;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (D.state == 2)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if (D.state == 1)
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_6 || C.v_rand_7 == 1)
													B[b] = B[b - 2];
												else
													B[b] = B[b - 2] + 1;
												A[b] = D.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = D.state;
												B[b] = B[b - 2] + 1;
												a = 0;
												c = 0;
											}
										}
									}
									else
									{
										if (E.state == 2)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if (E.state == 1)
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_6 || C.v_rand_7 == 1)
													B[b] = B[b - 2];
												else
													B[b] = B[b - 2] + 1;
												A[b] = E.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = E.state;
												B[b] = B[b - 2] + 1;
												a = 0;
												c = 0;
											}
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3&&C.v_rand_4&&C.v_rand_5&&C.v_rand_6 == 1)
							{
								if (a1&&b1&&c1&&d1 == 1)
								{
									if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
											B[b] = B[b - 2];
										else
											B[b] = B[b - 2] + 1;
										A[b] = 0;
										a = 0;
										c = 0;
									}
								}
								else if (e1 == 1)
								{
									if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										A[b] = 5;
										B[b] = B[b - 2] + 1;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (D.state == 2)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if (D.state == 1)
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
													B[b] = B[b - 2];
												else
													B[b] = B[b - 2] + 1;
												A[b] = D.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = D.state;
												B[b] = B[b - 2] + 1;
												a = 0;
												c = 0;
											}
										}
									}
									else
									{
										if (E.state == 2)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if (E.state == 1)
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
													B[b] = B[b - 2];
												else
													B[b] = B[b - 2] + 1;
												A[b] = E.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = E.state;
												B[b] = B[b - 2] + 1;
												a = 0;
												c = 0;
											}
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
					}
					else if (A[b - 2] == 3)
					{
						if (B[b - 2] == 1)
						{
							if (C.v_rand_1 || C.v_rand_15 == 1)
							{
								if (a1&&b1&&c1&&d1 == 1)
								{
									if (C.v_rand_2 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										if (C.v_rand_3 == 1)
											B[b] = B[b - 2];
										else
											B[b] = B[b - 2] + 1;
										A[b] = 0;
										a = 0;
										c = 0;
									}
								}
								else if (e1 == 1)
								{
									if (C.v_rand_2 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										A[b] = 5;
										B[b] = B[b - 2] + 1;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (D.state == 3)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if ((D.state == 1) || (D.state == 2) == 1)
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_3 == 1)
													B[b] = B[b - 2];
												else
													B[b] = B[b - 2] + 1;
												A[b] = D.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = D.state;
												B[b] = B[b - 2] + 1;
												a = 0;
												c = 0;
											}
										}
									}
									else
									{
										if (E.state == 3)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if ((E.state == 1) || (E.state == 2) == 1)
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_3 == 1)
													B[b] = B[b - 2];
												else
													B[b] = B[b - 2] + 1;
												A[b] = E.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = E.state;
												B[b] = B[b - 2] + 1;
												a = 0;
												c = 0;
											}
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else if (B[b - 2] < 3)
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3 == 1)
							{
								if (a1&&b1&&c1&&d1 == 1)
								{
									if (C.v_rand_4 || C.v_rand_5 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										if (C.v_rand_6 || C.v_rand_7 == 1)
											B[b] = B[b - 2];
										else
											B[b] = B[b - 2] + 1;
										A[b] = 0;
										a = 0;
										c = 0;
									}
								}
								else if (e1 == 1)
								{
									if (C.v_rand_4 || C.v_rand_5 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										A[b] = 5;
										B[b] = B[b - 2] + 1;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (D.state == 3)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if ((D.state == 1) || (D.state == 2) == 1)
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_6 || C.v_rand_7 == 1)
													B[b] = B[b - 2];
												else
													B[b] = B[b - 2] + 1;
												A[b] = D.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = D.state;
												B[b] = B[b - 2] + 1;
												a = 0;
												c = 0;
											}
										}
									}
									else
									{
										if (E.state == 3)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if ((E.state == 1) || (E.state == 2) == 1)
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_6 || C.v_rand_7 == 1)
													B[b] = B[b - 2];
												else
													B[b] = B[b - 2] + 1;
												A[b] = E.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = E.state;
												B[b] = B[b - 2] + 1;
												a = 0;
												c = 0;
											}
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3&&C.v_rand_4&&C.v_rand_5&&C.v_rand_6 == 1)
							{
								if (a1&&b1&&c1&&d1 == 1)
								{
									if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
											B[b] = B[b - 2];
										else
											B[b] = B[b - 2] + 1;
										A[b] = 0;
										a = 0;
										c = 0;
									}
								}
								else if (e1 == 1)
								{
									if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										A[b] = 5;
										B[b] = B[b - 2] + 1;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (D.state == 3)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if ((D.state == 1) || (D.state == 2) == 1)
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
													B[b] = B[b - 2];
												else
													B[b] = B[b - 2] + 1;
												A[b] = D.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = D.state;
												B[b] = B[b - 2] + 1;
												a = 0;
												c = 0;
											}
										}
									}
									else
									{
										if (E.state == 3)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if ((E.state == 1) || (E.state == 2) == 1)
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
													B[b] = B[b - 2];
												else
													B[b] = B[b - 2] + 1;
												A[b] = E.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = E.state;
												B[b] = B[b - 2] + 1;
												a = 0;
												c = 0;
											}
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
					}
					else if (A[b - 2] == 4)
					{
						if (B[b - 2] == 1)
						{
							if (C.v_rand_1 || C.v_rand_15 == 1)
							{
								if (a1&&b1&&c1&&d1 == 1)
								{
									if (C.v_rand_2 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										if (C.v_rand_3 == 1)
											B[b] = B[b - 2];
										else
											B[b] = B[b - 2] + 1;
										A[b] = 0;
										a = 0;
										c = 0;
									}
								}
								else if (e1 == 1)
								{
									if (C.v_rand_2 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										A[b] = 5;
										B[b] = B[b - 2] + 1;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (D.state == 4)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										//�W�@�H�۪���⬰����,�T�b���ɳ۶®�,����,����ҥi��ܽu��O�_�n+1
										else
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_3 == 1)
													B[b] = B[b - 2];
												else
													B[b] = B[b - 2] + 1;
												A[b] = D.state;
												a = 0;
												c = 0;
											}
										}
									}
									else
									{
										if (E.state == 4)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_3 == 1)
													B[b] = B[b - 2];
												else
													B[b] = B[b - 2] + 1;
												A[b] = E.state;
												a = 0;
												c = 0;
											}
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else if (B[b - 2] < 3)
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3 == 1)
							{
								if (a1&&b1&&c1&&d1 == 1)
								{
									if (C.v_rand_4 || C.v_rand_5 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										if (C.v_rand_6 || C.v_rand_7 == 1)
											B[b] = B[b - 2];
										else
											B[b] = B[b - 2] + 1;
										A[b] = 0;
										a = 0;
										c = 0;
									}
								}
								else if (e1 == 1)
								{
									if (C.v_rand_4 || C.v_rand_5 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										A[b] = 5;
										B[b] = B[b - 2] + 1;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (D.state == 4)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										//�W�@�H�۪���⬰����,�T�b���ɳ۶®�,����,����ҥi��ܽu��O�_�n+1
										else
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_6 || C.v_rand_7 == 1)
													B[b] = B[b - 2];
												else
													B[b] = B[b - 2] + 1;
												A[b] = D.state;
												a = 0;
												c = 0;
											}
										}
									}
									else
									{
										if (E.state == 4)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_6 || C.v_rand_7 == 1)
													B[b] = B[b - 2];
												else
													B[b] = B[b - 2] + 1;
												A[b] = E.state;
												a = 0;
												c = 0;
											}
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3&&C.v_rand_4&&C.v_rand_5&&C.v_rand_6 == 1)
							{
								if (a1&&b1&&c1&&d1 == 1)
								{
									if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
											B[b] = B[b - 2];
										else
											B[b] = B[b - 2] + 1;
										A[b] = 0;
										a = 0;
										c = 0;
									}
								}
								else if (e1 == 1)
								{
									if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										A[b] = 5;
										B[b] = B[b - 2] + 1;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (D.state == 4)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										//�W�@�H�۪���⬰����,�T�b���ɳ۶®�,����,����ҥi��ܽu��O�_�n+1
										else
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
													B[b] = B[b - 2];
												else
													B[b] = B[b - 2] + 1;
												A[b] = D.state;
												a = 0;
												c = 0;
											}
										}
									}
									else
									{
										if (E.state == 4)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
													B[b] = B[b - 2];
												else
													B[b] = B[b - 2] + 1;
												A[b] = E.state;
												a = 0;
												c = 0;
											}
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
					}
					else
					{
						if (B[b - 2] == 1)
						{
							if (C.v_rand_1 || C.v_rand_15 == 1)
							{
								if (a1&&b1&&c1&&d1 == 1)
								{
									if (C.v_rand_2 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										if (C.v_rand_3 == 1)
											B[b] = B[b - 2];
										else
											B[b] = B[b - 2] + 1;
										A[b] = 0;
										a = 0;
										c = 0;
									}
								}
								else if (e1 == 1)
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									//c = b - 1;
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (C.v_rand_2 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_3 == 1)
												B[b] = B[b - 2];
											else
												B[b] = B[b - 2] + 1;
											A[b] = D.state;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_2 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_3 == 1)
												B[b] = B[b - 2];
											else
												B[b] = B[b - 2] + 1;
											A[b] = E.state;
											a = 0;
											c = 0;
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else if (B[b - 2] < 3)
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3 == 1)
							{
								if (a1&&b1&&c1&&d1 == 1)
								{
									if (C.v_rand_4 || C.v_rand_5 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										if (C.v_rand_6 || C.v_rand_7 == 1)
											B[b] = B[b - 2];
										else
											B[b] = B[b - 2] + 1;
										A[b] = 0;
										a = 0;
										c = 0;
									}
								}
								else if (e1 == 1)
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									//c = b - 1;
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_6 || C.v_rand_7 == 1)
												B[b] = B[b - 2];
											else
												B[b] = B[b - 2] + 1;
											A[b] = D.state;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_6 || C.v_rand_7 == 1)
												B[b] = B[b - 2];
											else
												B[b] = B[b - 2] + 1;
											A[b] = E.state;
											a = 0;
											c = 0;
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3&&C.v_rand_4&&C.v_rand_5&&C.v_rand_6 == 1)
							{
								if (a1&&b1&&c1&&d1 == 1)
								{
									if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
											B[b] = B[b - 2];
										else
											B[b] = B[b - 2] + 1;
										A[b] = 0;
										a = 0;
										c = 0;
									}
								}
								else if (e1 == 1)
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									//c = b - 1;
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
												B[b] = B[b - 2];
											else
												B[b] = B[b - 2] + 1;
											A[b] = D.state;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
												B[b] = B[b - 2];
											else
												B[b] = B[b - 2] + 1;
											A[b] = E.state;
											a = 0;
											c = 0;
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
					}
				}
				else
				{
					//���Ҽ{���,�E�ƬݬO+1�η���!!
					//�Y�W�@�ӤH�۵L��
					if (A[b - 2] == 0)
					{
						//�Ҽ{�W�@��ۥX���u��
						if (B[b - 2] == 1)
						{
							//�@�b�����v�۷s�����
							if (C.v_rand_1 || C.v_rand_15 == 1)
							{
								//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
									if (best_state == 0)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										A[b] = best_state;
										B[b] = B[b - 2] + 1;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (C.v_rand_2 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = D.state;
											B[b] = B[b - 2] + 1;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_2 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = E.state;
											B[b] = B[b - 2] + 1;
											a = 0;
											c = 0;
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else if (B[b - 2] < 3)
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3 ||
								((D.big_point>6) || (E.big_point>6) || (F.big_point>7) || (G.big_point>7)) ||
								((D.small_point>6) || (E.small_point>6) || (F.small_point>7) || (G.small_point>7)) == 1)
							{
								//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
									if (best_state == 0)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = best_state;
											B[b] = B[b - 2] + 1;
											a = 0;
											c = 0;
										}
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = D.state;
											B[b] = B[b - 2] + 1;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = E.state;
											B[b] = B[b - 2] + 1;
											a = 0;
											c = 0;
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3&&C.v_rand_4&&C.v_rand_5&&C.v_rand_6 ||
								((D.big_point > 7) || (E.big_point > 7) || (F.big_point > 8) || (G.big_point > 8)) ||
								((D.small_point > 7) || (E.small_point > 7) || (F.small_point > 8) || (G.small_point > 8)) == 1)
							{
								//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
									if (best_state == 0)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = best_state;
											B[b] = B[b - 2] + 1;
											a = 0;
											c = 0;
										}
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = D.state;
											B[b] = B[b - 2] + 1;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = E.state;
											B[b] = B[b - 2] + 1;
											a = 0;
											c = 0;
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
					}
					//�Y�W�@�ӤH�ۥ|�����@
					else if (A[b - 2] == 1)
					{
						//�Ҽ{�W�@��ۥX���u��
						if (B[b - 2] == 1)
						{
							//�@�b�����v�۷s�����
							if (C.v_rand_1 || C.v_rand_15 == 1)
							{
								//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
									if (best_state == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else if (best_state == 0)
									{
										if (C.v_rand_2 == 1)
											B[b] = B[b - 2];
										else
											B[b] = B[b - 2] + 1;
										A[b] = best_state;
										a = 0;
										c = 0;
									}
									else
									{
										A[b] = best_state;
										B[b] = B[b - 2] + 1;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (D.state == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = D.state;
												B[b] = B[b - 2] + 1;
												a = 0;
												c = 0;
											}
										}
									}
									else
									{
										if (E.state == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = E.state;
												B[b] = B[b - 2] + 1;
												a = 0;
												c = 0;
											}
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else if (B[b - 2] < 3)
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3 ||
								((D.big_point>6) || (E.big_point>6) || (F.big_point>7) || (G.big_point>7)) ||
								((D.small_point>6) || (E.small_point>6) || (F.small_point>7) || (G.small_point>7)) == 1)
							{
								//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
									if (best_state == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else if (best_state == 0)
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_6 || C.v_rand_7 == 1)
												B[b] = B[b - 2];
											else
												B[b] = B[b - 2] + 1;
											A[b] = best_state;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = best_state;
											B[b] = B[b - 2] + 1;
											a = 0;
											c = 0;
										}
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (D.state == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = D.state;
												B[b] = B[b - 2] + 1;
												a = 0;
												c = 0;
											}
										}
									}
									else
									{
										if (E.state == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = E.state;
												B[b] = B[b - 2] + 1;
												a = 0;
												c = 0;
											}
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3&&C.v_rand_4&&C.v_rand_5&&C.v_rand_6 ||
								((D.big_point > 7) || (E.big_point > 7) || (F.big_point > 8) || (G.big_point > 8)) ||
								((D.small_point > 7) || (E.small_point > 7) || (F.small_point > 8) || (G.small_point > 8)) == 1)
							{
								//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
									if (best_state == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else if (best_state == 0)
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
												B[b] = B[b - 2];
											else
												B[b] = B[b - 2] + 1;
											A[b] = best_state;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = best_state;
											B[b] = B[b - 2] + 1;
											a = 0;
											c = 0;
										}
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (D.state == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = D.state;
												B[b] = B[b - 2] + 1;
												a = 0;
												c = 0;
											}
										}
									}
									else
									{
										if (E.state == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = E.state;
												B[b] = B[b - 2] + 1;
												a = 0;
												c = 0;
											}
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
					}
					else if (A[b - 2] == 2)
					{
						//�Ҽ{�W�@��ۥX���u��
						if (B[b - 2] == 1)
						{
							//�@�b�����v�۷s�����
							if (C.v_rand_1 || C.v_rand_15 == 1)
							{
								//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
									if (best_state == 2)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else if ((best_state == 0) || (best_state == 1) == 1)
									{
										if (C.v_rand_2 == 1)
											B[b] = B[b - 2];
										else
											B[b] = B[b - 2] + 1;
										A[b] = best_state;
										a = 0;
										c = 0;
									}
									else
									{
										A[b] = best_state;
										B[b] = B[b - 2] + 1;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (D.state == 2)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if (D.state == 1)
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_3 == 1)
													B[b] = B[b - 2];
												else
													B[b] = B[b - 2] + 1;
												A[b] = D.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = D.state;
												B[b] = B[b - 2] + 1;
												a = 0;
												c = 0;
											}
										}
									}
									else
									{
										if (E.state == 2)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if (E.state == 1)
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_3 == 1)
													B[b] = B[b - 2];
												else
													B[b] = B[b - 2] + 1;
												A[b] = E.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = E.state;
												B[b] = B[b - 2] + 1;
												a = 0;
												c = 0;
											}
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else if (B[b - 2] < 3)
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3 ||
								((D.big_point>6) || (E.big_point>6) || (F.big_point>7) || (G.big_point>7)) ||
								((D.small_point>6) || (E.small_point>6) || (F.small_point>7) || (G.small_point>7)) == 1)
							{
								//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
									if (best_state == 2)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else if ((best_state == 0) || (best_state == 1) == 1)
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_6 || C.v_rand_7 == 1)
												B[b] = B[b - 2];
											else
												B[b] = B[b - 2] + 1;
											A[b] = best_state;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = best_state;
											B[b] = B[b - 2] + 1;
											a = 0;
											c = 0;
										}
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (D.state == 2)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if (D.state == 1)
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_6 || C.v_rand_7 == 1)
													B[b] = B[b - 2];
												else
													B[b] = B[b - 2] + 1;
												A[b] = D.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = D.state;
												B[b] = B[b - 2] + 1;
												a = 0;
												c = 0;
											}
										}
									}
									else
									{
										if (E.state == 2)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if (E.state == 1)
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_6 || C.v_rand_7 == 1)
													B[b] = B[b - 2];
												else
													B[b] = B[b - 2] + 1;
												A[b] = E.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = E.state;
												B[b] = B[b - 2] + 1;
												a = 0;
												c = 0;
											}
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3&&C.v_rand_4&&C.v_rand_5&&C.v_rand_6 ||
								((D.big_point > 7) || (E.big_point > 7) || (F.big_point > 8) || (G.big_point > 8)) ||
								((D.small_point > 7) || (E.small_point > 7) || (F.small_point > 8) || (G.small_point > 8)) == 1)
							{
								//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
									if (best_state == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else if ((best_state == 0) || (best_state == 1) == 1)
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
												B[b] = B[b - 2];
											else
												B[b] = B[b - 2] + 1;
											A[b] = best_state;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = best_state;
											B[b] = B[b - 2] + 1;
											a = 0;
											c = 0;
										}
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (D.state == 2)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if (D.state == 1)
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
													B[b] = B[b - 2];
												else
													B[b] = B[b - 2] + 1;
												A[b] = D.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = D.state;
												B[b] = B[b - 2] + 1;
												a = 0;
												c = 0;
											}
										}
									}
									else
									{
										if (E.state == 2)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if (E.state == 1)
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
													B[b] = B[b - 2];
												else
													B[b] = B[b - 2] + 1;
												A[b] = E.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = E.state;
												B[b] = B[b - 2] + 1;
												a = 0;
												c = 0;
											}
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
					}
					else if (A[b - 2] == 3)
					{
						//�Ҽ{�W�@��ۥX���u��
						if (B[b - 2] == 1)
						{
							//�@�b�����v�۷s�����
							if (C.v_rand_1 || C.v_rand_15 == 1)
							{
								//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
									if (best_state == 3)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else if ((best_state == 0) || (best_state == 1) || (best_state == 2) == 1)
									{
										if (C.v_rand_2 == 1)
											B[b] = B[b - 2];
										else
											B[b] = B[b - 2] + 1;
										A[b] = best_state;
										a = 0;
										c = 0;
									}
									else
									{
										A[b] = best_state;
										B[b] = B[b - 1] + 1;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (D.state == 3)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if ((D.state == 1) || (D.state == 2) == 1)
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_3 == 1)
													B[b] = B[b - 2];
												else
													B[b] = B[b - 2] + 1;
												A[b] = D.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = D.state;
												B[b] = B[b - 2] + 1;
												a = 0;
												c = 0;
											}
										}
									}
									else
									{
										if (E.state == 3)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if ((E.state == 1) || (E.state == 2) == 1)
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_3 == 1)
													B[b] = B[b - 2];
												else
													B[b] = B[b - 2] + 1;
												A[b] = E.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = E.state;
												B[b] = B[b - 2] + 1;
												a = 0;
												c = 0;
											}
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else if (B[b - 2] < 3)
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3 ||
								((D.big_point>6) || (E.big_point>6) || (F.big_point>7) || (G.big_point>7)) ||
								((D.small_point>6) || (E.small_point>6) || (F.small_point>7) || (G.small_point>7)) == 1)
							{
								//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
									if (best_state == 3)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else if ((best_state == 0) || (best_state == 1) || (best_state == 2) == 1)
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_6 || C.v_rand_7 == 1)
												B[b] = B[b - 2];
											else
												B[b] = B[b - 2] + 1;
											A[b] = best_state;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = best_state;
											B[b] = B[b - 2] + 1;
											a = 0;
											c = 0;
										}
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (D.state == 3)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if ((D.state == 1) || (D.state == 2) == 1)
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_6 || C.v_rand_7 == 1)
													B[b] = B[b - 2];
												else
													B[b] = B[b - 2] + 1;
												A[b] = D.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = D.state;
												B[b] = B[b - 2] + 1;
												a = 0;
												c = 0;
											}
										}
									}
									else
									{
										if (E.state == 3)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if ((E.state == 1) || (E.state == 2) == 1)
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_6 || C.v_rand_7 == 1)
													B[b] = B[b - 2];
												else
													B[b] = B[b - 2] + 1;
												A[b] = E.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = E.state;
												B[b] = B[b - 2] + 1;
												a = 0;
												c = 0;
											}
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3&&C.v_rand_4&&C.v_rand_5&&C.v_rand_6 ||
								((D.big_point > 7) || (E.big_point > 7) || (F.big_point > 8) || (G.big_point > 8)) ||
								((D.small_point > 7) || (E.small_point > 7) || (F.small_point > 8) || (G.small_point > 8)) == 1)
							{
								//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
									if (best_state == 3)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else if ((best_state == 0) || (best_state == 1) || (best_state == 2) == 1)
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
												B[b] = B[b - 2];
											else
												B[b] = B[b - 2] + 1;
											A[b] = best_state;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = best_state;
											B[b] = B[b - 2] + 1;
											a = 0;
											c = 0;
										}
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (D.state == 3)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if ((D.state == 1) || (D.state == 2) == 1)
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
													B[b] = B[b - 2];
												else
													B[b] = B[b - 2] + 1;
												A[b] = D.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = D.state;
												B[b] = B[b - 2] + 1;
												a = 0;
												c = 0;
											}
										}
									}
									else
									{
										if (E.state == 3)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if ((E.state == 1) || (E.state == 2) == 1)
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
													B[b] = B[b - 2];
												else
													B[b] = B[b - 2] + 1;
												A[b] = E.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = E.state;
												B[b] = B[b - 2] + 1;
												a = 0;
												c = 0;
											}
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
					}
					else if (A[b - 2] == 4)
					{
						//�Ҽ{�W�@��ۥX���u��
						if (B[b - 2] == 1)
						{
							//�@�b�����v�۷s�����
							if (C.v_rand_1 || C.v_rand_15 == 1)
							{
								//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
									if (best_state == 4)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else if ((best_state == 0) || (best_state == 1) || (best_state == 2) || (best_state == 3) == 1)
									{
										if (C.v_rand_2 == 1)
											B[b] = B[b - 2];
										else
											B[b] = B[b - 2] + 1;
										A[b] = best_state;
										a = 0;
										c = 0;
									}
									else
									{
										A[b] = best_state;
										B[b] = B[b - 2] + 1;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (D.state == 4)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										//�W�@�H�۪���⬰����,�T�b���ɳ۶®�,����,����ҥi��ܽu��O�_�n+1
										else
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_3 == 1)
													B[b] = B[b - 2];
												else
													B[b] = B[b - 2] + 1;
												A[b] = D.state;
												a = 0;
												c = 0;
											}
										}
									}
									else
									{
										if (E.state == 4)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_3 == 1)
													B[b] = B[b - 2];
												else
													B[b] = B[b - 2] + 1;
												A[b] = E.state;
												a = 0;
												c = 0;
											}
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else if (B[b - 2] < 3)
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3 ||
								((D.big_point>6) || (E.big_point>6) || (F.big_point>7) || (G.big_point>7)) ||
								((D.small_point>6) || (E.small_point>6) || (F.small_point>7) || (G.small_point>7)) == 1)
							{
								//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
									if (best_state == 4)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else if ((best_state == 0) || (best_state == 1) || (best_state == 2) || (best_state == 3) == 1)
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_6 || C.v_rand_7 == 1)
												B[b] = B[b - 2];
											else
												B[b] = B[b - 2] + 1;
											A[b] = best_state;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = best_state;
											B[b] = B[b - 2] + 1;
											a = 0;
											c = 0;
										}
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (D.state == 4)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										//�W�@�H�۪���⬰����,�T�b���ɳ۶®�,����,����ҥi��ܽu��O�_�n+1
										else
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_6 || C.v_rand_7 == 1)
													B[b] = B[b - 2];
												else
													B[b] = B[b - 2] + 1;
												A[b] = D.state;
												a = 0;
												c = 0;
											}
										}
									}
									else
									{
										if (E.state == 4)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_6 || C.v_rand_7 == 1)
													B[b] = B[b - 2];
												else
													B[b] = B[b - 2] + 1;
												A[b] = E.state;
												a = 0;
												c = 0;
											}
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3&&C.v_rand_4&&C.v_rand_5&&C.v_rand_6 ||
								((D.big_point > 7) || (E.big_point > 7) || (F.big_point > 8) || (G.big_point > 8)) ||
								((D.small_point > 7) || (E.small_point > 7) || (F.small_point > 8) || (G.small_point > 8)) == 1)
							{
								//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
									if (best_state == 4)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else if ((best_state == 0) || (best_state == 1) || (best_state == 2) || (best_state == 3) == 1)
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
												B[b] = B[b - 2];
											else
												B[b] = B[b - 2] + 1;
											A[b] = best_state;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = best_state;
											B[b] = B[b - 2] + 1;
											a = 0;
											c = 0;
										}
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (D.state == 4)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										//�W�@�H�۪���⬰����,�T�b���ɳ۶®�,����,����ҥi��ܽu��O�_�n+1
										else
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
													B[b] = B[b - 2];
												else
													B[b] = B[b - 2] + 1;
												A[b] = D.state;
												a = 0;
												c = 0;
											}
										}
									}
									else
									{
										if (E.state == 4)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
													B[b] = B[b - 2];
												else
													B[b] = B[b - 2] + 1;
												A[b] = E.state;
												a = 0;
												c = 0;
											}
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
					}
					//�Y�W�@�ӤH��small
					else
					{
						//�Ҽ{�W�@��ۥX���u��
						if (B[b - 2] == 1)
						{
							//�@�b�����v�۷s�����
							if (C.v_rand_1 || C.v_rand_15 == 1)
							{
								//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
									if (best_state == 5)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										if (C.v_rand_2 == 1)
											B[b] = B[b - 2];
										else
											B[b] = B[b - 2] + 1;
										A[b] = best_state;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (C.v_rand_2 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_3 == 1)
												B[b] = B[b - 2];
											else
												B[b] = B[b - 2] + 1;
											A[b] = D.state;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_2 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_3 == 1)
												B[b] = B[b - 2];
											else
												B[b] = B[b - 2] + 1;
											A[b] = E.state;
											a = 0;
											c = 0;
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else if (B[b - 2] < 3)
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3 ||
								((D.big_point>6) || (E.big_point>6) || (F.big_point>7) || (G.big_point>7)) ||
								((D.small_point>6) || (E.small_point>6) || (F.small_point>7) || (G.small_point>7)) == 1)
							{
								//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
									if (best_state == 5)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
											B[b] = B[b - 2];
										else
											B[b] = B[b - 2] + 1;
										A[b] = best_state;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_6 || C.v_rand_7 == 1)
												B[b] = B[b - 2];
											else
												B[b] = B[b - 2] + 1;
											A[b] = D.state;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_6 || C.v_rand_7 == 1)
												B[b] = B[b - 2];
											else
												B[b] = B[b - 2] + 1;
											A[b] = E.state;
											a = 0;
											c = 0;
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3&&C.v_rand_4&&C.v_rand_5&&C.v_rand_6 ||
								((D.big_point > 7) || (E.big_point > 7) || (F.big_point > 8) || (G.big_point > 8)) ||
								((D.small_point > 7) || (E.small_point > 7) || (F.small_point > 8) || (G.small_point > 8)) == 1)
							{
								//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
									if (best_state == 5)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											B[b] = B[b - 2];
										else
											B[b] = B[b - 2] + 1;
										A[b] = best_state;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
												B[b] = B[b - 2];
											else
												B[b] = B[b - 2] + 1;
											A[b] = D.state;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
												B[b] = B[b - 2];
											else
												B[b] = B[b - 2] + 1;
											A[b] = E.state;
											a = 0;
											c = 0;
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
					}
				}
			}
			else
			{
				for (int i = 0; i < 2; i++)
				{
					if (b - 2 - 4 * i > 0)
						partner_color[i] = A[b - 2 - 4 * i];
				}
				for (int i = 0; i < 2; i++)
				{
					if (b - 3 - 4 * i > 0)
						enemy1_color[i] = A[b - 3 - 4 * i];
					if (b - 1 - 4 * i > 0)
						enemy2_color[i] = A[b - 1 - 4 * i];
				}
				int temp0 = 0, temp1 = 0, temp2 = 0, temp3 = 0, temp4 = 0, temp5 = 0, temp_no = 0;
				for (int i = 0; i < 2; i++)
				{
					if (partner_color[i] == D.state)
						temp1 += i + 1;
					else if (partner_color[i] == E.state)
						temp2 += i + 1;
					else if (partner_color[i] == F.state)
						temp3 += i + 1;
					else if (partner_color[i] == G.state)
						temp4 += i + 1;
					else if (partner_color[i] == 0)
						temp0 += i + 1;
					else if (partner_color[i] == 5)
						temp5 += i + 1;
					else
						temp_no += i + 1;
					if (enemy1_color[i] == D.state)
						temp1 -= i + 1;
					else if (enemy1_color[i] == E.state)
						temp2 -= i + 1;
					else if (enemy1_color[i] == F.state)
						temp3 -= i + 1;
					else if (enemy1_color[i] == G.state)
						temp4 -= i + 1;
					else if (enemy1_color[i] == 0)
						temp0 -= i + 1;
					else if (enemy1_color[i] == 5)
						temp5 -= i + 1;
					else
						temp_no -= i + 1;
					if (enemy2_color[i] == D.state)
						temp1 -= i + 1;
					else if (enemy2_color[i] == E.state)
						temp2 -= i + 1;
					else if (enemy2_color[i] == F.state)
						temp3 -= i + 1;
					else if (enemy2_color[i] == G.state)
						temp4 -= i + 1;
					else if (enemy2_color[i] == 0)
						temp0 -= i + 1;
					else if (enemy2_color[i] == 5)
						temp5 -= i + 1;
					else
						temp_no -= i + 1;
				}
				int P[7] = { temp0,temp1,temp2,temp3,temp4,temp5,temp_no };
				int best_state;
				int bubble_sort[7] = { temp0,temp1,temp2,temp3,temp4,temp5,temp_no };
				for (int i = 6; i >= 0; i--)
				{
					for (int j = 0; j < i; j++)
					{
						int t;
						if (bubble_sort[j] < bubble_sort[j + 1])
						{
							t = bubble_sort[j + 1];
							bubble_sort[j + 1] = bubble_sort[j];
							bubble_sort[j] = t;
						}
					}
				}
				for (int i = 0; i < 7; i++)
				{
					if (bubble_sort[0] == P[i])
					{
						if (i == 0)
							best_state = 0;
						else if (i == 1)
							best_state = D.state;
						else if (i == 2)
							best_state = E.state;
						else if (i == 3)
							best_state = F.state;
						else if (i == 4)
							best_state = G.state;
						else if (i == 5)
							best_state = 5;
						else
							best_state = D.state;
						break;
					}
				}
				/*���]���̨θѬ�bubble_sort[0]�ҹ��������!!*/
				//���|�X�{A[b-1]=6������,�]���W�@�ӤH���w�S��accept!!
				if (bubble_sort[0] == bubble_sort[1]) //���]�䤣��̨θ�,���ɵL�k���T�M�w�n�۪����
				{
					if (A[b - 2] == 0)
					{
						if (B[b - 2] == 1)
						{
							if (C.v_rand_1 || C.v_rand_15 == 1)
							{
								if (a1&&b1&&c1&&d1 == 1)
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									//c = b - 1;
								}
								else if (e1 == 1)
								{
									if (C.v_rand_2 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										A[b] = 5;
										B[b] = B[b - 2] + 1;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (C.v_rand_2 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = D.state;
											B[b] = B[b - 2] + 1;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_2 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = E.state;
											B[b] = B[b - 2] + 1;
											a = 0;
											c = 0;
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else if (B[b - 2] < 3)
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3 == 1)
							{
								if (a1&&b1&&c1&&d1 == 1)
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									//c = b - 1;
								}
								else if (e1 == 1)
								{
									if (C.v_rand_4 || C.v_rand_5 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										A[b] = 5;
										B[b] = B[b - 2] + 1;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = D.state;
											B[b] = B[b - 2] + 1;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = E.state;
											B[b] = B[b - 2] + 1;
											a = 0;
											c = 0;
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3&&C.v_rand_4&&C.v_rand_5&&C.v_rand_6 == 1)
							{
								if (a1&&b1&&c1&&d1 == 1)
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									//c = b - 1;
								}
								else if (e1 == 1)
								{
									if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										A[b] = 5;
										B[b] = B[b - 2] + 1;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = D.state;
											B[b] = B[b - 2] + 1;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = E.state;
											B[b] = B[b - 2] + 1;
											a = 0;
											c = 0;
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
					}
					else if (A[b - 2] == 1)
					{
						if (B[b - 2] == 1)
						{
							if (C.v_rand_1 || C.v_rand_15 == 1)
							{
								if (a1&&b1&&c1&&d1 == 1)
								{
									if (C.v_rand_2 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										if (C.v_rand_3 == 1)
											B[b] = B[b - 2];
										else
											B[b] = B[b - 2] + 1;
										A[b] = 0;
										a = 0;
										c = 0;
									}
								}
								else if (e1 == 1)
								{
									if (C.v_rand_2 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										A[b] = 5;
										B[b] = B[b - 2] + 1;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (C.v_rand_2 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = D.state;
											B[b] = B[b - 2] + 1;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_2 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = E.state;
											B[b] = B[b - 2] + 1;
											a = 0;
											c = 0;
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else if (B[b - 2] < 3)
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3 == 1)
							{
								if (a1&&b1&&c1&&d1 == 1)
								{
									if (C.v_rand_4 || C.v_rand_5 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										if (C.v_rand_6 || C.v_rand_7 == 1)
											B[b] = B[b - 2];
										else
											B[b] = B[b - 2] + 1;
										A[b] = 0;
										a = 0;
										c = 0;
									}
								}
								else if (e1 == 1)
								{
									if (C.v_rand_4 || C.v_rand_5 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										A[b] = 5;
										B[b] = B[b - 2] + 1;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = D.state;
											B[b] = B[b - 2] + 1;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = E.state;
											B[b] = B[b - 2] + 1;
											a = 0;
											c = 0;
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3&&C.v_rand_4&&C.v_rand_5&&C.v_rand_6 == 1)
							{
								if (a1&&b1&&c1&&d1 == 1)
								{
									if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
											B[b] = B[b - 2];
										else
											B[b] = B[b - 2] + 1;
										A[b] = 0;
										a = 0;
										c = 0;
									}
								}
								else if (e1 == 1)
								{
									if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										A[b] = 5;
										B[b] = B[b - 2] + 1;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = D.state;
											B[b] = B[b - 2] + 1;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = E.state;
											B[b] = B[b - 2] + 1;
											a = 0;
											c = 0;
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
					}
					else if (A[b - 2] == 2)
					{
						if (B[b - 2] == 1)
						{
							if (C.v_rand_1 || C.v_rand_15 == 1)
							{
								if (a1&&b1&&c1&&d1 == 1)
								{
									if (C.v_rand_2 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										if (C.v_rand_3 == 1)
											B[b] = B[b - 2];
										else
											B[b] = B[b - 2] + 1;
										A[b] = 0;
										a = 0;
										c = 0;
									}
								}
								else if (e1 == 1)
								{
									if (C.v_rand_2 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										A[b] = 5;
										B[b] = B[b - 2] + 1;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (D.state == 2)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if (D.state == 1)
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_3 == 1)
													B[b] = B[b - 2];
												else
													B[b] = B[b - 2] + 1;
												A[b] = D.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = D.state;
												B[b] = B[b - 2] + 1;
												a = 0;
												c = 0;
											}
										}
									}
									else
									{
										if (E.state == 2)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if (E.state == 1)
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_3 == 1)
													B[b] = B[b - 2];
												else
													B[b] = B[b - 2] + 1;
												A[b] = E.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = E.state;
												B[b] = B[b - 2] + 1;
												a = 0;
												c = 0;
											}
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else if (B[b - 2] < 3)
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3 == 1)
							{
								if (a1&&b1&&c1&&d1 == 1)
								{
									if (C.v_rand_4 || C.v_rand_5 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										if (C.v_rand_6 || C.v_rand_7 == 1)
											B[b] = B[b - 2];
										else
											B[b] = B[b - 2] + 1;
										A[b] = 0;
										a = 0;
										c = 0;
									}
								}
								else if (e1 == 1)
								{
									if (C.v_rand_4 || C.v_rand_5 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										A[b] = 5;
										B[b] = B[b - 2] + 1;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (D.state == 2)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if (D.state == 1)
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_6 || C.v_rand_7 == 1)
													B[b] = B[b - 2];
												else
													B[b] = B[b - 2] + 1;
												A[b] = D.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = D.state;
												B[b] = B[b - 2] + 1;
												a = 0;
												c = 0;
											}
										}
									}
									else
									{
										if (E.state == 2)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if (E.state == 1)
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_6 || C.v_rand_7 == 1)
													B[b] = B[b - 2];
												else
													B[b] = B[b - 2] + 1;
												A[b] = E.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = E.state;
												B[b] = B[b - 2] + 1;
												a = 0;
												c = 0;
											}
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3&&C.v_rand_4&&C.v_rand_5&&C.v_rand_6 == 1)
							{
								if (a1&&b1&&c1&&d1 == 1)
								{
									if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
											B[b] = B[b - 2];
										else
											B[b] = B[b - 2] + 1;
										A[b] = 0;
										a = 0;
										c = 0;
									}
								}
								else if (e1 == 1)
								{
									if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										A[b] = 5;
										B[b] = B[b - 2] + 1;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (D.state == 2)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if (D.state == 1)
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
													B[b] = B[b - 2];
												else
													B[b] = B[b - 2] + 1;
												A[b] = D.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = D.state;
												B[b] = B[b - 2] + 1;
												a = 0;
												c = 0;
											}
										}
									}
									else
									{
										if (E.state == 2)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if (E.state == 1)
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
													B[b] = B[b - 2];
												else
													B[b] = B[b - 2] + 1;
												A[b] = E.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = E.state;
												B[b] = B[b - 2] + 1;
												a = 0;
												c = 0;
											}
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
					}
					else if (A[b - 2] == 3)
					{
						if (B[b - 2] == 1)
						{
							if (C.v_rand_1 || C.v_rand_15 == 1)
							{
								if (a1&&b1&&c1&&d1 == 1)
								{
									if (C.v_rand_2 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										if (C.v_rand_3 == 1)
											B[b] = B[b - 2];
										else
											B[b] = B[b - 2] + 1;
										A[b] = 0;
										a = 0;
										c = 0;
									}
								}
								else if (e1 == 1)
								{
									if (C.v_rand_2 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										A[b] = 5;
										B[b] = B[b - 2] + 1;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (D.state == 3)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if ((D.state == 1) || (D.state == 2) == 1)
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_3 == 1)
													B[b] = B[b - 2];
												else
													B[b] = B[b - 2] + 1;
												A[b] = D.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = D.state;
												B[b] = B[b - 2] + 1;
												a = 0;
												c = 0;
											}
										}
									}
									else
									{
										if (E.state == 3)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if ((E.state == 1) || (E.state == 2) == 1)
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_3 == 1)
													B[b] = B[b - 2];
												else
													B[b] = B[b - 2] + 1;
												A[b] = E.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = E.state;
												B[b] = B[b - 2] + 1;
												a = 0;
												c = 0;
											}
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else if (B[b - 2] < 3)
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3 == 1)
							{
								if (a1&&b1&&c1&&d1 == 1)
								{
									if (C.v_rand_4 || C.v_rand_5 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										if (C.v_rand_6 || C.v_rand_7 == 1)
											B[b] = B[b - 2];
										else
											B[b] = B[b - 2] + 1;
										A[b] = 0;
										a = 0;
										c = 0;
									}
								}
								else if (e1 == 1)
								{
									if (C.v_rand_4 || C.v_rand_5 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										A[b] = 5;
										B[b] = B[b - 2] + 1;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (D.state == 3)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if ((D.state == 1) || (D.state == 2) == 1)
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_6 || C.v_rand_7 == 1)
													B[b] = B[b - 2];
												else
													B[b] = B[b - 2] + 1;
												A[b] = D.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = D.state;
												B[b] = B[b - 2] + 1;
												a = 0;
												c = 0;
											}
										}
									}
									else
									{
										if (E.state == 3)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if ((E.state == 1) || (E.state == 2) == 1)
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_6 || C.v_rand_7 == 1)
													B[b] = B[b - 2];
												else
													B[b] = B[b - 2] + 1;
												A[b] = E.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = E.state;
												B[b] = B[b - 2] + 1;
												a = 0;
												c = 0;
											}
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3&&C.v_rand_4&&C.v_rand_5&&C.v_rand_6 == 1)
							{
								if (a1&&b1&&c1&&d1 == 1)
								{
									if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
											B[b] = B[b - 2];
										else
											B[b] = B[b - 2] + 1;
										A[b] = 0;
										a = 0;
										c = 0;
									}
								}
								else if (e1 == 1)
								{
									if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										A[b] = 5;
										B[b] = B[b - 2] + 1;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (D.state == 3)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if ((D.state == 1) || (D.state == 2) == 1)
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
													B[b] = B[b - 2];
												else
													B[b] = B[b - 2] + 1;
												A[b] = D.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = D.state;
												B[b] = B[b - 2] + 1;
												a = 0;
												c = 0;
											}
										}
									}
									else
									{
										if (E.state == 3)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if ((E.state == 1) || (E.state == 2) == 1)
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
													B[b] = B[b - 2];
												else
													B[b] = B[b - 2] + 1;
												A[b] = E.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = E.state;
												B[b] = B[b - 2] + 1;
												a = 0;
												c = 0;
											}
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
					}
					else if (A[b - 2] == 4)
					{
						if (B[b - 2] == 1)
						{
							if (C.v_rand_1 || C.v_rand_15 == 1)
							{
								if (a1&&b1&&c1&&d1 == 1)
								{
									if (C.v_rand_2 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										if (C.v_rand_3 == 1)
											B[b] = B[b - 2];
										else
											B[b] = B[b - 2] + 1;
										A[b] = 0;
										a = 0;
										c = 0;
									}
								}
								else if (e1 == 1)
								{
									if (C.v_rand_2 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										A[b] = 5;
										B[b] = B[b - 2] + 1;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (D.state == 4)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										//�W�@�H�۪���⬰����,�T�b���ɳ۶®�,����,����ҥi��ܽu��O�_�n+1
										else
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_3 == 1)
													B[b] = B[b - 2];
												else
													B[b] = B[b - 2] + 1;
												A[b] = D.state;
												a = 0;
												c = 0;
											}
										}
									}
									else
									{
										if (E.state == 4)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_3 == 1)
													B[b] = B[b - 2];
												else
													B[b] = B[b - 2] + 1;
												A[b] = E.state;
												a = 0;
												c = 0;
											}
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else if (B[b - 2] < 3)
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3 == 1)
							{
								if (a1&&b1&&c1&&d1 == 1)
								{
									if (C.v_rand_4 || C.v_rand_5 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										if (C.v_rand_6 || C.v_rand_7 == 1)
											B[b] = B[b - 2];
										else
											B[b] = B[b - 2] + 1;
										A[b] = 0;
										a = 0;
										c = 0;
									}
								}
								else if (e1 == 1)
								{
									if (C.v_rand_4 || C.v_rand_5 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										A[b] = 5;
										B[b] = B[b - 2] + 1;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (D.state == 4)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										//�W�@�H�۪���⬰����,�T�b���ɳ۶®�,����,����ҥi��ܽu��O�_�n+1
										else
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_6 || C.v_rand_7 == 1)
													B[b] = B[b - 2];
												else
													B[b] = B[b - 2] + 1;
												A[b] = D.state;
												a = 0;
												c = 0;
											}
										}
									}
									else
									{
										if (E.state == 4)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_6 || C.v_rand_7 == 1)
													B[b] = B[b - 2];
												else
													B[b] = B[b - 2] + 1;
												A[b] = E.state;
												a = 0;
												c = 0;
											}
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3&&C.v_rand_4&&C.v_rand_5&&C.v_rand_6 == 1)
							{
								if (a1&&b1&&c1&&d1 == 1)
								{
									if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
											B[b] = B[b - 2];
										else
											B[b] = B[b - 2] + 1;
										A[b] = 0;
										a = 0;
										c = 0;
									}
								}
								else if (e1 == 1)
								{
									if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										A[b] = 5;
										B[b] = B[b - 2] + 1;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (D.state == 4)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										//�W�@�H�۪���⬰����,�T�b���ɳ۶®�,����,����ҥi��ܽu��O�_�n+1
										else
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
													B[b] = B[b - 2];
												else
													B[b] = B[b - 2] + 1;
												A[b] = D.state;
												a = 0;
												c = 0;
											}
										}
									}
									else
									{
										if (E.state == 4)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
													B[b] = B[b - 2];
												else
													B[b] = B[b - 2] + 1;
												A[b] = E.state;
												a = 0;
												c = 0;
											}
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
					}
					else
					{
						if (B[b - 2] == 1)
						{
							if (C.v_rand_1 || C.v_rand_15 == 1)
							{
								if (a1&&b1&&c1&&d1 == 1)
								{
									if (C.v_rand_2 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										if (C.v_rand_3 == 1)
											B[b] = B[b - 2];
										else
											B[b] = B[b - 2] + 1;
										A[b] = 0;
										a = 0;
										c = 0;
									}
								}
								else if (e1 == 1)
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									//c = b - 1;
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (C.v_rand_2 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_3 == 1)
												B[b] = B[b - 2];
											else
												B[b] = B[b - 2] + 1;
											A[b] = D.state;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_2 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_3 == 1)
												B[b] = B[b - 2];
											else
												B[b] = B[b - 2] + 1;
											A[b] = E.state;
											a = 0;
											c = 0;
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else if (B[b - 2] < 3)
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3 == 1)
							{
								if (a1&&b1&&c1&&d1 == 1)
								{
									if (C.v_rand_4 || C.v_rand_5 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										if (C.v_rand_6 || C.v_rand_7 == 1)
											B[b] = B[b - 2];
										else
											B[b] = B[b - 2] + 1;
										A[b] = 0;
										a = 0;
										c = 0;
									}
								}
								else if (e1 == 1)
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									//c = b - 1;
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_6 || C.v_rand_7 == 1)
												B[b] = B[b - 2];
											else
												B[b] = B[b - 2] + 1;
											A[b] = D.state;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_6 || C.v_rand_7 == 1)
												B[b] = B[b - 2];
											else
												B[b] = B[b - 2] + 1;
											A[b] = E.state;
											a = 0;
											c = 0;
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3&&C.v_rand_4&&C.v_rand_5&&C.v_rand_6 == 1)
							{
								if (a1&&b1&&c1&&d1 == 1)
								{
									if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
											B[b] = B[b - 2];
										else
											B[b] = B[b - 2] + 1;
										A[b] = 0;
										a = 0;
										c = 0;
									}
								}
								else if (e1 == 1)
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									//c = b - 1;
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
												B[b] = B[b - 2];
											else
												B[b] = B[b - 2] + 1;
											A[b] = D.state;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
												B[b] = B[b - 2];
											else
												B[b] = B[b - 2] + 1;
											A[b] = E.state;
											a = 0;
											c = 0;
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
					}
				}
				else
				{
					//���Ҽ{���,�E�ƬݬO+1�η���!!
					//�Y�W�@�ӤH�۵L��
					if (A[b - 2] == 0)
					{
						//�Ҽ{�W�@��ۥX���u��
						if (B[b - 2] == 1)
						{
							//�@�b�����v�۷s�����
							if (C.v_rand_1 || C.v_rand_15 == 1)
							{
								//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
									if (best_state == 0)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										A[b] = best_state;
										B[b] = B[b - 2] + 1;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (C.v_rand_2 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = D.state;
											B[b] = B[b - 2] + 1;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_2 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = E.state;
											B[b] = B[b - 2] + 1;
											a = 0;
											c = 0;
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else if (B[b - 2] < 3)
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3 ||
								((D.big_point>6) || (E.big_point>6) || (F.big_point>7) || (G.big_point>7)) ||
								((D.small_point>6) || (E.small_point>6) || (F.small_point>7) || (G.small_point>7)) == 1)
							{
								//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
									if (best_state == 0)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = best_state;
											B[b] = B[b - 2] + 1;
											a = 0;
											c = 0;
										}
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = D.state;
											B[b] = B[b - 2] + 1;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = E.state;
											B[b] = B[b - 2] + 1;
											a = 0;
											c = 0;
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3&&C.v_rand_4&&C.v_rand_5&&C.v_rand_6 ||
								((D.big_point > 7) || (E.big_point > 7) || (F.big_point > 8) || (G.big_point > 8)) ||
								((D.small_point > 7) || (E.small_point > 7) || (F.small_point > 8) || (G.small_point > 8)) == 1)
							{
								//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
									if (best_state == 0)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = best_state;
											B[b] = B[b - 2] + 1;
											a = 0;
											c = 0;
										}
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = D.state;
											B[b] = B[b - 2] + 1;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = E.state;
											B[b] = B[b - 2] + 1;
											a = 0;
											c = 0;
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
					}
					//�Y�W�@�ӤH�ۥ|�����@
					else if (A[b - 2] == 1)
					{
						//�Ҽ{�W�@��ۥX���u��
						if (B[b - 2] == 1)
						{
							//�@�b�����v�۷s�����
							if (C.v_rand_1 || C.v_rand_15 == 1)
							{
								//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
									if (best_state == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else if (best_state == 0)
									{
										if (C.v_rand_2 == 1)
											B[b] = B[b - 2];
										else
											B[b] = B[b - 2] + 1;
										A[b] = best_state;
										a = 0;
										c = 0;
									}
									else
									{
										A[b] = best_state;
										B[b] = B[b - 2] + 1;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (D.state == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = D.state;
												B[b] = B[b - 2] + 1;
												a = 0;
												c = 0;
											}
										}
									}
									else
									{
										if (E.state == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = E.state;
												B[b] = B[b - 2] + 1;
												a = 0;
												c = 0;
											}
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else if (B[b - 2] < 3)
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3 ||
								((D.big_point>6) || (E.big_point>6) || (F.big_point>7) || (G.big_point>7)) ||
								((D.small_point>6) || (E.small_point>6) || (F.small_point>7) || (G.small_point>7)) == 1)
							{
								//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
									if (best_state == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else if (best_state == 0)
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_6 || C.v_rand_7 == 1)
												B[b] = B[b - 2];
											else
												B[b] = B[b - 2] + 1;
											A[b] = best_state;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = best_state;
											B[b] = B[b - 2] + 1;
											a = 0;
											c = 0;
										}
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (D.state == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = D.state;
												B[b] = B[b - 2] + 1;
												a = 0;
												c = 0;
											}
										}
									}
									else
									{
										if (E.state == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = E.state;
												B[b] = B[b - 2] + 1;
												a = 0;
												c = 0;
											}
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3&&C.v_rand_4&&C.v_rand_5&&C.v_rand_6 ||
								((D.big_point > 7) || (E.big_point > 7) || (F.big_point > 8) || (G.big_point > 8)) ||
								((D.small_point > 7) || (E.small_point > 7) || (F.small_point > 8) || (G.small_point > 8)) == 1)
							{
								//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
									if (best_state == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else if (best_state == 0)
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
												B[b] = B[b - 2];
											else
												B[b] = B[b - 2] + 1;
											A[b] = best_state;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = best_state;
											B[b] = B[b - 2] + 1;
											a = 0;
											c = 0;
										}
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (D.state == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = D.state;
												B[b] = B[b - 2] + 1;
												a = 0;
												c = 0;
											}
										}
									}
									else
									{
										if (E.state == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = E.state;
												B[b] = B[b - 2] + 1;
												a = 0;
												c = 0;
											}
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
					}
					else if (A[b - 2] == 2)
					{
						//�Ҽ{�W�@��ۥX���u��
						if (B[b - 2] == 1)
						{
							//�@�b�����v�۷s�����
							if (C.v_rand_1 || C.v_rand_15 == 1)
							{
								//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
									if (best_state == 2)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else if ((best_state == 0) || (best_state == 1) == 1)
									{
										if (C.v_rand_2 == 1)
											B[b] = B[b - 2];
										else
											B[b] = B[b - 2] + 1;
										A[b] = best_state;
										a = 0;
										c = 0;
									}
									else
									{
										A[b] = best_state;
										B[b] = B[b - 2] + 1;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (D.state == 2)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if (D.state == 1)
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_3 == 1)
													B[b] = B[b - 2];
												else
													B[b] = B[b - 2] + 1;
												A[b] = D.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = D.state;
												B[b] = B[b - 2] + 1;
												a = 0;
												c = 0;
											}
										}
									}
									else
									{
										if (E.state == 2)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if (E.state == 1)
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_3 == 1)
													B[b] = B[b - 2];
												else
													B[b] = B[b - 2] + 1;
												A[b] = E.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = E.state;
												B[b] = B[b - 2] + 1;
												a = 0;
												c = 0;
											}
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else if (B[b - 2] < 3)
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3 ||
								((D.big_point>6) || (E.big_point>6) || (F.big_point>7) || (G.big_point>7)) ||
								((D.small_point>6) || (E.small_point>6) || (F.small_point>7) || (G.small_point>7)) == 1)
							{
								//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
									if (best_state == 2)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else if ((best_state == 0) || (best_state == 1) == 1)
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_6 || C.v_rand_7 == 1)
												B[b] = B[b - 2];
											else
												B[b] = B[b - 2] + 1;
											A[b] = best_state;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = best_state;
											B[b] = B[b - 2] + 1;
											a = 0;
											c = 0;
										}
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (D.state == 2)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if (D.state == 1)
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_6 || C.v_rand_7 == 1)
													B[b] = B[b - 2];
												else
													B[b] = B[b - 2] + 1;
												A[b] = D.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = D.state;
												B[b] = B[b - 2] + 1;
												a = 0;
												c = 0;
											}
										}
									}
									else
									{
										if (E.state == 2)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if (E.state == 1)
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_6 || C.v_rand_7 == 1)
													B[b] = B[b - 2];
												else
													B[b] = B[b - 2] + 1;
												A[b] = E.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = E.state;
												B[b] = B[b - 2] + 1;
												a = 0;
												c = 0;
											}
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3&&C.v_rand_4&&C.v_rand_5&&C.v_rand_6 ||
								((D.big_point > 7) || (E.big_point > 7) || (F.big_point > 8) || (G.big_point > 8)) ||
								((D.small_point > 7) || (E.small_point > 7) || (F.small_point > 8) || (G.small_point > 8)) == 1)
							{
								//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
									if (best_state == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else if ((best_state == 0) || (best_state == 1) == 1)
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
												B[b] = B[b - 2];
											else
												B[b] = B[b - 2] + 1;
											A[b] = best_state;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = best_state;
											B[b] = B[b - 2] + 1;
											a = 0;
											c = 0;
										}
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (D.state == 2)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if (D.state == 1)
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
													B[b] = B[b - 2];
												else
													B[b] = B[b - 2] + 1;
												A[b] = D.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = D.state;
												B[b] = B[b - 2] + 1;
												a = 0;
												c = 0;
											}
										}
									}
									else
									{
										if (E.state == 2)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if (E.state == 1)
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
													B[b] = B[b - 2];
												else
													B[b] = B[b - 2] + 1;
												A[b] = E.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = E.state;
												B[b] = B[b - 2] + 1;
												a = 0;
												c = 0;
											}
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
					}
					else if (A[b - 2] == 3)
					{
						//�Ҽ{�W�@��ۥX���u��
						if (B[b - 2] == 1)
						{
							//�@�b�����v�۷s�����
							if (C.v_rand_1 || C.v_rand_15 == 1)
							{
								//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
									if (best_state == 3)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else if ((best_state == 0) || (best_state == 1) || (best_state == 2) == 1)
									{
										if (C.v_rand_2 == 1)
											B[b] = B[b - 2];
										else
											B[b] = B[b - 2] + 1;
										A[b] = best_state;
										a = 0;
										c = 0;
									}
									else
									{
										A[b] = best_state;
										B[b] = B[b - 2] + 1;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (D.state == 3)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if ((D.state == 1) || (D.state == 2) == 1)
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_3 == 1)
													B[b] = B[b - 2];
												else
													B[b] = B[b - 2] + 1;
												A[b] = D.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = D.state;
												B[b] = B[b - 2] + 1;
												a = 0;
												c = 0;
											}
										}
									}
									else
									{
										if (E.state == 3)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if ((E.state == 1) || (E.state == 2) == 1)
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_3 == 1)
													B[b] = B[b - 2];
												else
													B[b] = B[b - 2] + 1;
												A[b] = E.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = E.state;
												B[b] = B[b - 2] + 1;
												a = 0;
												c = 0;
											}
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else if (B[b - 2] < 3)
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3 ||
								((D.big_point>6) || (E.big_point>6) || (F.big_point>7) || (G.big_point>7)) ||
								((D.small_point>6) || (E.small_point>6) || (F.small_point>7) || (G.small_point>7)) == 1)
							{
								//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
									if (best_state == 3)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else if ((best_state == 0) || (best_state == 1) || (best_state == 2) == 1)
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_6 || C.v_rand_7 == 1)
												B[b] = B[b - 2];
											else
												B[b] = B[b - 2] + 1;
											A[b] = best_state;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = best_state;
											B[b] = B[b - 2] + 1;
											a = 0;
											c = 0;
										}
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (D.state == 3)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if ((D.state == 1) || (D.state == 2) == 1)
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_6 || C.v_rand_7 == 1)
													B[b] = B[b - 2];
												else
													B[b] = B[b - 2] + 1;
												A[b] = D.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = D.state;
												B[b] = B[b - 2] + 1;
												a = 0;
												c = 0;
											}
										}
									}
									else
									{
										if (E.state == 3)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if ((E.state == 1) || (E.state == 2) == 1)
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_6 || C.v_rand_7 == 1)
													B[b] = B[b - 2];
												else
													B[b] = B[b - 2] + 1;
												A[b] = E.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = E.state;
												B[b] = B[b - 2] + 1;
												a = 0;
												c = 0;
											}
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3&&C.v_rand_4&&C.v_rand_5&&C.v_rand_6 ||
								((D.big_point > 7) || (E.big_point > 7) || (F.big_point > 8) || (G.big_point > 8)) ||
								((D.small_point > 7) || (E.small_point > 7) || (F.small_point > 8) || (G.small_point > 8)) == 1)
							{
								//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
									if (best_state == 3)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else if ((best_state == 0) || (best_state == 1) || (best_state == 2) == 1)
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
												B[b] = B[b - 2];
											else
												B[b] = B[b - 2] + 1;
											A[b] = best_state;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = best_state;
											B[b] = B[b - 2] + 1;
											a = 0;
											c = 0;
										}
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (D.state == 3)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if ((D.state == 1) || (D.state == 2) == 1)
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
													B[b] = B[b - 2];
												else
													B[b] = B[b - 2] + 1;
												A[b] = D.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = D.state;
												B[b] = B[b - 2] + 1;
												a = 0;
												c = 0;
											}
										}
									}
									else
									{
										if (E.state == 3)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else if ((E.state == 1) || (E.state == 2) == 1)
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
													B[b] = B[b - 2];
												else
													B[b] = B[b - 2] + 1;
												A[b] = E.state;
												a = 0;
												c = 0;
											}
										}
										else
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												A[b] = E.state;
												B[b] = B[b - 2] + 1;
												a = 0;
												c = 0;
											}
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
					}
					else if (A[b - 2] == 4)
					{
						//�Ҽ{�W�@��ۥX���u��
						if (B[b - 2] == 1)
						{
							//�@�b�����v�۷s�����
							if (C.v_rand_1 || C.v_rand_15 == 1)
							{
								//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
									if (best_state == 4)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else if ((best_state == 0) || (best_state == 1) || (best_state == 2) || (best_state == 3) == 1)
									{
										if (C.v_rand_2 == 1)
											B[b] = B[b - 2];
										else
											B[b] = B[b - 2] + 1;
										A[b] = best_state;
										a = 0;
										c = 0;
									}
									else
									{
										A[b] = best_state;
										B[b] = B[b - 2] + 1;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (D.state == 4)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										//�W�@�H�۪���⬰����,�T�b���ɳ۶®�,����,����ҥi��ܽu��O�_�n+1
										else
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_3 == 1)
													B[b] = B[b - 2];
												else
													B[b] = B[b - 2] + 1;
												A[b] = D.state;
												a = 0;
												c = 0;
											}
										}
									}
									else
									{
										if (E.state == 4)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_3 == 1)
													B[b] = B[b - 2];
												else
													B[b] = B[b - 2] + 1;
												A[b] = E.state;
												a = 0;
												c = 0;
											}
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else if (B[b - 2] < 3)
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3 ||
								((D.big_point>6) || (E.big_point>6) || (F.big_point>7) || (G.big_point>7)) ||
								((D.small_point>6) || (E.small_point>6) || (F.small_point>7) || (G.small_point>7)) == 1)
							{
								//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
									if (best_state == 4)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else if ((best_state == 0) || (best_state == 1) || (best_state == 2) || (best_state == 3) == 1)
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_6 || C.v_rand_7 == 1)
												B[b] = B[b - 2];
											else
												B[b] = B[b - 2] + 1;
											A[b] = best_state;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = best_state;
											B[b] = B[b - 2] + 1;
											a = 0;
											c = 0;
										}
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (D.state == 4)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										//�W�@�H�۪���⬰����,�T�b���ɳ۶®�,����,����ҥi��ܽu��O�_�n+1
										else
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_6 || C.v_rand_7 == 1)
													B[b] = B[b - 2];
												else
													B[b] = B[b - 2] + 1;
												A[b] = D.state;
												a = 0;
												c = 0;
											}
										}
									}
									else
									{
										if (E.state == 4)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_6 || C.v_rand_7 == 1)
													B[b] = B[b - 2];
												else
													B[b] = B[b - 2] + 1;
												A[b] = E.state;
												a = 0;
												c = 0;
											}
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3&&C.v_rand_4&&C.v_rand_5&&C.v_rand_6 ||
								((D.big_point > 7) || (E.big_point > 7) || (F.big_point > 8) || (G.big_point > 8)) ||
								((D.small_point > 7) || (E.small_point > 7) || (F.small_point > 8) || (G.small_point > 8)) == 1)
							{
								//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
									if (best_state == 4)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else if ((best_state == 0) || (best_state == 1) || (best_state == 2) || (best_state == 3) == 1)
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
												B[b] = B[b - 2];
											else
												B[b] = B[b - 2] + 1;
											A[b] = best_state;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											A[b] = best_state;
											B[b] = B[b - 2] + 1;
											a = 0;
											c = 0;
										}
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (D.state == 4)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										//�W�@�H�۪���⬰����,�T�b���ɳ۶®�,����,����ҥi��ܽu��O�_�n+1
										else
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
													B[b] = B[b - 2];
												else
													B[b] = B[b - 2] + 1;
												A[b] = D.state;
												a = 0;
												c = 0;
											}
										}
									}
									else
									{
										if (E.state == 4)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												//c = b - 1;
											}
											else
											{
												if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
													B[b] = B[b - 2];
												else
													B[b] = B[b - 2] + 1;
												A[b] = E.state;
												a = 0;
												c = 0;
											}
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
					}
					//�Y�W�@�ӤH��small
					else
					{
						//�Ҽ{�W�@��ۥX���u��
						if (B[b - 2] == 1)
						{
							//�@�b�����v�۷s�����
							if (C.v_rand_1 || C.v_rand_15 == 1)
							{
								//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
									if (best_state == 5)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										if (C.v_rand_2 == 1)
											B[b] = B[b - 2];
										else
											B[b] = B[b - 2] + 1;
										A[b] = best_state;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (C.v_rand_2 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_3 == 1)
												B[b] = B[b - 2];
											else
												B[b] = B[b - 2] + 1;
											A[b] = D.state;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_2 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_3 == 1)
												B[b] = B[b - 2];
											else
												B[b] = B[b - 2] + 1;
											A[b] = E.state;
											a = 0;
											c = 0;
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else if (B[b - 2] < 3)
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3 ||
								((D.big_point>6) || (E.big_point>6) || (F.big_point>7) || (G.big_point>7)) ||
								((D.small_point>6) || (E.small_point>6) || (F.small_point>7) || (G.small_point>7)) == 1)
							{
								//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
									if (best_state == 5)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
											B[b] = B[b - 2];
										else
											B[b] = B[b - 2] + 1;
										A[b] = best_state;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_6 || C.v_rand_7 == 1)
												B[b] = B[b - 2];
											else
												B[b] = B[b - 2] + 1;
											A[b] = D.state;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_6 || C.v_rand_7 == 1)
												B[b] = B[b - 2];
											else
												B[b] = B[b - 2] + 1;
											A[b] = E.state;
											a = 0;
											c = 0;
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
						else
						{
							if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3&&C.v_rand_4&&C.v_rand_5&&C.v_rand_6 ||
								((D.big_point > 7) || (E.big_point > 7) || (F.big_point > 8) || (G.big_point > 8)) ||
								((D.small_point > 7) || (E.small_point > 7) || (F.small_point > 8) || (G.small_point > 8)) == 1)
							{
								//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
									if (best_state == 5)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										//c = b - 1;
									}
									else
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											B[b] = B[b - 2];
										else
											B[b] = B[b - 2] + 1;
										A[b] = best_state;
										a = 0;
										c = 0;
									}
								}
								else
								{
									if (D.big_point > E.big_point)
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
												B[b] = B[b - 2];
											else
												B[b] = B[b - 2] + 1;
											A[b] = D.state;
											a = 0;
											c = 0;
										}
									}
									else
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											//c = b - 1;
										}
										else
										{
											if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
												B[b] = B[b - 2];
											else
												B[b] = B[b - 2] + 1;
											A[b] = E.state;
											a = 0;
											c = 0;
										}
									}
								}
							}
							else
							{
								A[b] = 6;
								B[b] = 0;
								a++;
								//c = b - 1;
							}
						}
					}
				}
			}
		}
		//�Ѧ�b-1���P!!
		else
		{
			//�p�G�S��accept��,counter_stop=0
			//�b�o��accept��,counter_stop=counter-1
			//b==0,�Ĥ@�ӳ۪�⪺�H
			if (b == 0)
			{
				if ((a1&&b1&&c1&&d1&&C.v_rand_1) == 1)
				{
					//No King
					A[b] = 0;
					B[b] = 1;
				}
				else
				{
					if ((e1&&C.v_rand_2) == 1)
					{
						//small
						A[b] = 5;
						B[b] = 1;
					}
					else
					{
						/*4���䤤���@,�̧Ǭ�Max_color,Second_color,Third_color,Min_color*/
						if ((((C.v_rand_1&&C.v_rand_2&&C.v_rand_3) ||
							(C.v_rand_1&&C.v_rand_2 && (!C.v_rand_3)) ||
							(C.v_rand_1 && (!C.v_rand_2) && C.v_rand_3)) ||
							((!C.v_rand_1) && (!C.v_rand_2) && C.v_rand_3)) == 1)
						{
							A[b] = D.state;
							B[b] = 1;
						}
						else if (((C.v_rand_1 && (!C.v_rand_2) && (!C.v_rand_3)) ||
							((!C.v_rand_1) && C.v_rand_2&&C.v_rand_3)) == 1)
						{
							A[b] = E.state;
							B[b] = 1;
						}
						else if (((!C.v_rand_1) && C.v_rand_2 && (!C.v_rand_3)) == 1)
						{
							A[b] = F.state;
							B[b] = 1;
						}
						else
						{
							A[b] = G.state;
							B[b] = 1;
						}
					}
				}
			}
			else
			{
				int partner_color[2]; //�s�����ͥs�L�����
				int enemy1_color[2], enemy2_color[2]; //�s������H�s�L�����
													  //�|��ڶ��ͩM����C�H�̪�⦸�s�P�i����R
				if (b>7)
				{
					for (int i = 0; i < 2; i++)
						partner_color[i] = A[b - 2 - 4 * i];
					for (int i = 0; i < 2; i++)
					{
						enemy1_color[i] = A[b - 3 - 4 * i];
						enemy2_color[i] = A[b - 1 - 4 * i];
					}
					int temp0 = 0, temp1 = 0, temp2 = 0, temp3 = 0, temp4 = 0, temp5 = 0, temp_no = 0;
					for (int i = 0; i < 2; i++)
					{
						if (partner_color[i] == D.state)
							temp1 += i + 1;
						else if (partner_color[i] == E.state)
							temp2 += i + 1;
						else if (partner_color[i] == F.state)
							temp3 += i + 1;
						else if (partner_color[i] == G.state)
							temp4 += i + 1;
						else if (partner_color[i] == 0)
							temp0 += i + 1;
						else if (partner_color[i] == 5)
							temp5 += i + 1;
						else
							temp_no += i + 1;
						if (enemy1_color[i] == D.state)
							temp1 -= i + 1;
						else if (enemy1_color[i] == E.state)
							temp2 -= i + 1;
						else if (enemy1_color[i] == F.state)
							temp3 -= i + 1;
						else if (enemy1_color[i] == G.state)
							temp4 -= i + 1;
						else if (enemy1_color[i] == 0)
							temp0 -= i + 1;
						else if (enemy1_color[i] == 5)
							temp5 -= i + 1;
						else
							temp_no -= i + 1;
						if (enemy2_color[i] == D.state)
							temp1 -= i + 1;
						else if (enemy2_color[i] == E.state)
							temp2 -= i + 1;
						else if (enemy2_color[i] == F.state)
							temp3 -= i + 1;
						else if (enemy2_color[i] == G.state)
							temp4 -= i + 1;
						else if (enemy2_color[i] == 0)
							temp0 -= i + 1;
						else if (enemy2_color[i] == 5)
							temp5 -= i + 1;
						else
							temp_no -= i + 1;
					}
					int P[7] = { temp0,temp1,temp2,temp3,temp4,temp5,temp_no };
					int best_state;
					int bubble_sort[7] = { temp0,temp1,temp2,temp3,temp4,temp5,temp_no };
					for (int i = 6; i >= 0; i--)
					{
						for (int j = 0; j < i; j++)
						{
							int t;
							if (bubble_sort[j] < bubble_sort[j + 1])
							{
								t = bubble_sort[j + 1];
								bubble_sort[j + 1] = bubble_sort[j];
								bubble_sort[j] = t;
							}
						}
					}
					for (int i = 0; i < 7; i++)
					{
						if (bubble_sort[0] == P[i])
						{
							if (i == 0)
								best_state = 0;
							else if (i == 1)
								best_state = D.state;
							else if (i == 2)
								best_state = E.state;
							else if (i == 3)
								best_state = F.state;
							else if (i == 4)
								best_state = G.state;
							else if (i == 5)
								best_state = 5;
							else
								best_state = D.state;
							break;
						}
					}
					if (bubble_sort[0] == bubble_sort[1]) //���]�䤣��̨θ�,���ɵL�k���T�M�w�n�۪����
					{
						if (A[b - 1] == 0)
						{
							if (B[b - 1] == 1)
							{
								if (C.v_rand_1 || C.v_rand_15 == 1)
								{
									if (a1&&b1&&c1&&d1 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										c = b - 1;
									}
									else if (e1 == 1)
									{
										if (C.v_rand_2 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else
										{
											A[b] = 5;
											B[b] = B[b - 1] + 1;
										}
									}
									else
									{
										if (D.big_point > E.big_point)
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												A[b] = D.state;
												B[b] = B[b - 1] + 1;
											}
										}
										else
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												A[b] = E.state;
												B[b] = B[b - 1] + 1;
											}
										}
									}
								}
								else
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									c = b - 1;
								}
							}
							else if (B[b - 1] < 3)
							{
								if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3 == 1)
								{
									if (a1&&b1&&c1&&d1 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										c = b - 1;
									}
									else if (e1 == 1)
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else
										{
											A[b] = 5;
											B[b] = B[b - 1] + 1;
										}
									}
									else
									{
										if (D.big_point > E.big_point)
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												A[b] = D.state;
												B[b] = B[b - 1] + 1;
											}
										}
										else
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												A[b] = E.state;
												B[b] = B[b - 1] + 1;
											}
										}
									}
								}
								else
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									c = b - 1;
								}
							}
							else
							{
								if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3&&C.v_rand_4&&C.v_rand_5&&C.v_rand_6 == 1)
								{
									if (a1&&b1&&c1&&d1 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										c = b - 1;
									}
									else if (e1 == 1)
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else
										{
											A[b] = 5;
											B[b] = B[b - 1] + 1;
										}
									}
									else
									{
										if (D.big_point > E.big_point)
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												A[b] = D.state;
												B[b] = B[b - 1] + 1;
											}
										}
										else
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												A[b] = E.state;
												B[b] = B[b - 1] + 1;
											}
										}
									}
								}
								else
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									c = b - 1;
								}
							}
						}
						else if (A[b - 1] == 1)
						{
							if (B[b - 1] == 1)
							{
								if (C.v_rand_1 || C.v_rand_15 == 1)
								{
									if (a1&&b1&&c1&&d1 == 1)
									{
										if (C.v_rand_2 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else
										{
											if (C.v_rand_3 == 1)
												B[b] = B[b - 1];
											else
												B[b] = B[b - 1] + 1;
											A[b] = 0;
										}
									}
									else if (e1 == 1)
									{
										if (C.v_rand_2 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else
										{
											A[b] = 5;
											B[b] = B[b - 1] + 1;
										}
									}
									else
									{
										if (D.big_point > E.big_point)
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												A[b] = D.state;
												B[b] = B[b - 1] + 1;
											}
										}
										else
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												A[b] = E.state;
												B[b] = B[b - 1] + 1;
											}
										}
									}
								}
								else
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									c = b - 1;
								}
							}
							else if (B[b - 1] < 3)
							{
								if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3 == 1)
								{
									if (a1&&b1&&c1&&d1 == 1)
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else
										{
											if (C.v_rand_6 || C.v_rand_7 == 1)
												B[b] = B[b - 1];
											else
												B[b] = B[b - 1] + 1;
											A[b] = 0;
										}
									}
									else if (e1 == 1)
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else
										{
											A[b] = 5;
											B[b] = B[b - 1] + 1;
										}
									}
									else
									{
										if (D.big_point > E.big_point)
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												A[b] = D.state;
												B[b] = B[b - 1] + 1;
											}
										}
										else
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												A[b] = E.state;
												B[b] = B[b - 1] + 1;
											}
										}
									}
								}
								else
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									c = b - 1;
								}
							}
							else
							{
								if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3&&C.v_rand_4&&C.v_rand_5&&C.v_rand_6 == 1)
								{
									if (a1&&b1&&c1&&d1 == 1)
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else
										{
											if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
												B[b] = B[b - 1];
											else
												B[b] = B[b - 1] + 1;
											A[b] = 0;
										}
									}
									else if (e1 == 1)
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else
										{
											A[b] = 5;
											B[b] = B[b - 1] + 1;
										}
									}
									else
									{
										if (D.big_point > E.big_point)
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												A[b] = D.state;
												B[b] = B[b - 1] + 1;
											}
										}
										else
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												A[b] = E.state;
												B[b] = B[b - 1] + 1;
											}
										}
									}
								}
								else
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									c = b - 1;
								}
							}
						}
						else if (A[b - 1] == 2)
						{
							if (B[b - 1] == 1)
							{
								if (C.v_rand_1 || C.v_rand_15 == 1)
								{
									if (a1&&b1&&c1&&d1 == 1)
									{
										if (C.v_rand_2 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else
										{
											if (C.v_rand_3 == 1)
												B[b] = B[b - 1];
											else
												B[b] = B[b - 1] + 1;
											A[b] = 0;
										}
									}
									else if (e1 == 1)
									{
										if (C.v_rand_2 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else
										{
											A[b] = 5;
											B[b] = B[b - 1] + 1;
										}
									}
									else
									{
										if (D.big_point > E.big_point)
										{
											if (D.state == 2)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else if (D.state == 1)
											{
												if (C.v_rand_2 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													if (C.v_rand_3 == 1)
														B[b] = B[b - 1];
													else
														B[b] = B[b - 1] + 1;
													A[b] = D.state;
												}
											}
											else
											{
												if (C.v_rand_2 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													A[b] = D.state;
													B[b] = B[b - 1] + 1;
												}
											}
										}
										else
										{
											if (E.state == 2)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else if (E.state == 1)
											{
												if (C.v_rand_2 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													if (C.v_rand_3 == 1)
														B[b] = B[b - 1];
													else
														B[b] = B[b - 1] + 1;
													A[b] = E.state;
												}
											}
											else
											{
												if (C.v_rand_2 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													A[b] = E.state;
													B[b] = B[b - 1] + 1;
												}
											}
										}
									}
								}
								else
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									c = b - 1;
								}
							}
							else if (B[b - 1] < 3)
							{
								if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3 == 1)
								{
									if (a1&&b1&&c1&&d1 == 1)
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else
										{
											if (C.v_rand_6 || C.v_rand_7 == 1)
												B[b] = B[b - 1];
											else
												B[b] = B[b - 1] + 1;
											A[b] = 0;
										}
									}
									else if (e1 == 1)
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else
										{
											A[b] = 5;
											B[b] = B[b - 1] + 1;
										}
									}
									else
									{
										if (D.big_point > E.big_point)
										{
											if (D.state == 2)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else if (D.state == 1)
											{
												if (C.v_rand_4 || C.v_rand_5 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													if (C.v_rand_6 || C.v_rand_7 == 1)
														B[b] = B[b - 1];
													else
														B[b] = B[b - 1] + 1;
													A[b] = D.state;
												}
											}
											else
											{
												if (C.v_rand_4 || C.v_rand_5 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													A[b] = D.state;
													B[b] = B[b - 1] + 1;
												}
											}
										}
										else
										{
											if (E.state == 2)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else if (E.state == 1)
											{
												if (C.v_rand_4 || C.v_rand_5 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													if (C.v_rand_6 || C.v_rand_7 == 1)
														B[b] = B[b - 1];
													else
														B[b] = B[b - 1] + 1;
													A[b] = E.state;
												}
											}
											else
											{
												if (C.v_rand_4 || C.v_rand_5 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													A[b] = E.state;
													B[b] = B[b - 1] + 1;
												}
											}
										}
									}
								}
								else
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									c = b - 1;
								}
							}
							else
							{
								if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3&&C.v_rand_4&&C.v_rand_5&&C.v_rand_6 == 1)
								{
									if (a1&&b1&&c1&&d1 == 1)
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else
										{
											if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
												B[b] = B[b - 1];
											else
												B[b] = B[b - 1] + 1;
											A[b] = 0;
										}
									}
									else if (e1 == 1)
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else
										{
											A[b] = 5;
											B[b] = B[b - 1] + 1;
										}
									}
									else
									{
										if (D.big_point > E.big_point)
										{
											if (D.state == 2)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else if (D.state == 1)
											{
												if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
														B[b] = B[b - 1];
													else
														B[b] = B[b - 1] + 1;
													A[b] = D.state;
												}
											}
											else
											{
												if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													A[b] = D.state;
													B[b] = B[b - 1] + 1;
												}
											}
										}
										else
										{
											if (E.state == 2)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else if (E.state == 1)
											{
												if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
														B[b] = B[b - 1];
													else
														B[b] = B[b - 1] + 1;
													A[b] = E.state;
												}
											}
											else
											{
												if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													A[b] = E.state;
													B[b] = B[b - 1] + 1;
												}
											}
										}
									}
								}
								else
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									c = b - 1;
								}
							}
						}
						else if (A[b - 1] == 3)
						{
							if (B[b - 1] == 1)
							{
								if (C.v_rand_1 || C.v_rand_15 == 1)
								{
									if (a1&&b1&&c1&&d1 == 1)
									{
										if (C.v_rand_2 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else
										{
											if (C.v_rand_3 == 1)
												B[b] = B[b - 1];
											else
												B[b] = B[b - 1] + 1;
											A[b] = 0;
										}
									}
									else if (e1 == 1)
									{
										if (C.v_rand_2 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else
										{
											A[b] = 5;
											B[b] = B[b - 1] + 1;
										}
									}
									else
									{
										if (D.big_point > E.big_point)
										{
											if (D.state == 3)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else if ((D.state == 1) || (D.state == 2) == 1)
											{
												if (C.v_rand_2 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													if (C.v_rand_3 == 1)
														B[b] = B[b - 1];
													else
														B[b] = B[b - 1] + 1;
													A[b] = D.state;
												}
											}
											else
											{
												if (C.v_rand_2 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													A[b] = D.state;
													B[b] = B[b - 1] + 1;
												}
											}
										}
										else
										{
											if (E.state == 3)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else if ((E.state == 1) || (E.state == 2) == 1)
											{
												if (C.v_rand_2 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													if (C.v_rand_3 == 1)
														B[b] = B[b - 1];
													else
														B[b] = B[b - 1] + 1;
													A[b] = E.state;
												}
											}
											else
											{
												if (C.v_rand_2 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													A[b] = E.state;
													B[b] = B[b - 1] + 1;
												}
											}
										}
									}
								}
								else
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									c = b - 1;
								}
							}
							else if (B[b - 1] < 3)
							{
								if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3 == 1)
								{
									if (a1&&b1&&c1&&d1 == 1)
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else
										{
											if (C.v_rand_6 || C.v_rand_7 == 1)
												B[b] = B[b - 1];
											else
												B[b] = B[b - 1] + 1;
											A[b] = 0;
										}
									}
									else if (e1 == 1)
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else
										{
											A[b] = 5;
											B[b] = B[b - 1] + 1;
										}
									}
									else
									{
										if (D.big_point > E.big_point)
										{
											if (D.state == 3)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else if ((D.state == 1) || (D.state == 2) == 1)
											{
												if (C.v_rand_4 || C.v_rand_5 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													if (C.v_rand_6 || C.v_rand_7 == 1)
														B[b] = B[b - 1];
													else
														B[b] = B[b - 1] + 1;
													A[b] = D.state;
												}
											}
											else
											{
												if (C.v_rand_4 || C.v_rand_5 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													A[b] = D.state;
													B[b] = B[b - 1] + 1;
												}
											}
										}
										else
										{
											if (E.state == 3)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else if ((E.state == 1) || (E.state == 2) == 1)
											{
												if (C.v_rand_4 || C.v_rand_5 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													if (C.v_rand_6 || C.v_rand_7 == 1)
														B[b] = B[b - 1];
													else
														B[b] = B[b - 1] + 1;
													A[b] = E.state;
												}
											}
											else
											{
												if (C.v_rand_4 || C.v_rand_5 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													A[b] = E.state;
													B[b] = B[b - 1] + 1;
												}
											}
										}
									}
								}
								else
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									c = b - 1;
								}
							}
							else
							{
								if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3&&C.v_rand_4&&C.v_rand_5&&C.v_rand_6 == 1)
								{
									if (a1&&b1&&c1&&d1 == 1)
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else
										{
											if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
												B[b] = B[b - 1];
											else
												B[b] = B[b - 1] + 1;
											A[b] = 0;
										}
									}
									else if (e1 == 1)
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else
										{
											A[b] = 5;
											B[b] = B[b - 1] + 1;
										}
									}
									else
									{
										if (D.big_point > E.big_point)
										{
											if (D.state == 3)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else if ((D.state == 1) || (D.state == 2) == 1)
											{
												if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
														B[b] = B[b - 1];
													else
														B[b] = B[b - 1] + 1;
													A[b] = D.state;
												}
											}
											else
											{
												if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													A[b] = D.state;
													B[b] = B[b - 1] + 1;
												}
											}
										}
										else
										{
											if (E.state == 3)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else if ((E.state == 1) || (E.state == 2) == 1)
											{
												if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
														B[b] = B[b - 1];
													else
														B[b] = B[b - 1] + 1;
													A[b] = E.state;
												}
											}
											else
											{
												if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													A[b] = E.state;
													B[b] = B[b - 1] + 1;
												}
											}
										}
									}
								}
								else
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									c = b - 1;
								}
							}
						}
						else if (A[b - 1] == 4)
						{
							if (B[b - 1] == 1)
							{
								if (C.v_rand_1 || C.v_rand_15 == 1)
								{
									if (a1&&b1&&c1&&d1 == 1)
									{
										if (C.v_rand_2 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else
										{
											if (C.v_rand_3 == 1)
												B[b] = B[b - 1];
											else
												B[b] = B[b - 1] + 1;
											A[b] = 0;
										}
									}
									else if (e1 == 1)
									{
										if (C.v_rand_2 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else
										{
											A[b] = 5;
											B[b] = B[b - 1] + 1;
										}
									}
									else
									{
										if (D.big_point > E.big_point)
										{
											if (D.state == 4)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											//�W�@�H�۪���⬰����,�T�b���ɳ۶®�,����,����ҥi��ܽu��O�_�n+1
											else
											{
												if (C.v_rand_2 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													if (C.v_rand_3 == 1)
														B[b] = B[b - 1];
													else
														B[b] = B[b - 1] + 1;
													A[b] = D.state;
												}
											}
										}
										else
										{
											if (E.state == 4)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												if (C.v_rand_2 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													if (C.v_rand_3 == 1)
														B[b] = B[b - 1];
													else
														B[b] = B[b - 1] + 1;
													A[b] = E.state;
												}
											}
										}
									}
								}
								else
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									c = b - 1;
								}
							}
							else if (B[b - 1] < 3)
							{
								if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3 == 1)
								{
									if (a1&&b1&&c1&&d1 == 1)
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else
										{
											if (C.v_rand_6 || C.v_rand_7 == 1)
												B[b] = B[b - 1];
											else
												B[b] = B[b - 1] + 1;
											A[b] = 0;
										}
									}
									else if (e1 == 1)
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else
										{
											A[b] = 5;
											B[b] = B[b - 1] + 1;
										}
									}
									else
									{
										if (D.big_point > E.big_point)
										{
											if (D.state == 4)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											//�W�@�H�۪���⬰����,�T�b���ɳ۶®�,����,����ҥi��ܽu��O�_�n+1
											else
											{
												if (C.v_rand_4 || C.v_rand_5 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													if (C.v_rand_6 || C.v_rand_7 == 1)
														B[b] = B[b - 1];
													else
														B[b] = B[b - 1] + 1;
													A[b] = D.state;
												}
											}
										}
										else
										{
											if (E.state == 4)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												if (C.v_rand_4 || C.v_rand_5 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													if (C.v_rand_6 || C.v_rand_7 == 1)
														B[b] = B[b - 1];
													else
														B[b] = B[b - 1] + 1;
													A[b] = E.state;
												}
											}
										}
									}
								}
								else
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									c = b - 1;
								}
							}
							else
							{
								if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3&&C.v_rand_4&&C.v_rand_5&&C.v_rand_6 == 1)
								{
									if (a1&&b1&&c1&&d1 == 1)
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else
										{
											if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
												B[b] = B[b - 1];
											else
												B[b] = B[b - 1] + 1;
											A[b] = 0;
										}
									}
									else if (e1 == 1)
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else
										{
											A[b] = 5;
											B[b] = B[b - 1] + 1;
										}
									}
									else
									{
										if (D.big_point > E.big_point)
										{
											if (D.state == 4)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											//�W�@�H�۪���⬰����,�T�b���ɳ۶®�,����,����ҥi��ܽu��O�_�n+1
											else
											{
												if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
														B[b] = B[b - 1];
													else
														B[b] = B[b - 1] + 1;
													A[b] = D.state;
												}
											}
										}
										else
										{
											if (E.state == 4)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
														B[b] = B[b - 1];
													else
														B[b] = B[b - 1] + 1;
													A[b] = E.state;
												}
											}
										}
									}
								}
								else
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									c = b - 1;
								}
							}
						}
						else
						{
							if (B[b - 1] == 1)
							{
								if (C.v_rand_1 || C.v_rand_15 == 1)
								{
									if (a1&&b1&&c1&&d1 == 1)
									{
										if (C.v_rand_2 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else
										{
											if (C.v_rand_3 == 1)
												B[b] = B[b - 1];
											else
												B[b] = B[b - 1] + 1;
											A[b] = 0;
										}
									}
									else if (e1 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										c = b - 1;
									}
									else
									{
										if (D.big_point > E.big_point)
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												if (C.v_rand_3 == 1)
													B[b] = B[b - 1];
												else
													B[b] = B[b - 1] + 1;
												A[b] = D.state;
											}
										}
										else
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												if (C.v_rand_3 == 1)
													B[b] = B[b - 1];
												else
													B[b] = B[b - 1] + 1;
												A[b] = E.state;
											}
										}
									}
								}
								else
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									c = b - 1;
								}
							}
							else if (B[b - 1] < 3)
							{
								if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3 == 1)
								{
									if (a1&&b1&&c1&&d1 == 1)
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else
										{
											if (C.v_rand_6 || C.v_rand_7 == 1)
												B[b] = B[b - 1];
											else
												B[b] = B[b - 1] + 1;
											A[b] = 0;
										}
									}
									else if (e1 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										c = b - 1;
									}
									else
									{
										if (D.big_point > E.big_point)
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												if (C.v_rand_6 || C.v_rand_7 == 1)
													B[b] = B[b - 1];
												else
													B[b] = B[b - 1] + 1;
												A[b] = D.state;
											}
										}
										else
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												if (C.v_rand_6 || C.v_rand_7 == 1)
													B[b] = B[b - 1];
												else
													B[b] = B[b - 1] + 1;
												A[b] = E.state;
											}
										}
									}
								}
								else
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									c = b - 1;
								}
							}
							else
							{
								if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3&&C.v_rand_4&&C.v_rand_5&&C.v_rand_6 == 1)
								{
									if (a1&&b1&&c1&&d1 == 1)
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else
										{
											if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
												B[b] = B[b - 1];
											else
												B[b] = B[b - 1] + 1;
											A[b] = 0;
										}
									}
									else if (e1 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										c = b - 1;
									}
									else
									{
										if (D.big_point > E.big_point)
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
													B[b] = B[b - 1];
												else
													B[b] = B[b - 1] + 1;
												A[b] = D.state;
											}
										}
										else
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
													B[b] = B[b - 1];
												else
													B[b] = B[b - 1] + 1;
												A[b] = E.state;
											}
										}
									}
								}
								else
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									c = b - 1;
								}
							}
						}
					}
					else
					{
						//���Ҽ{���,�E�ƬݬO+1�η���!!
						//�Y�W�@�ӤH�۵L��
						if (A[b - 1] == 0)
						{
							//�Ҽ{�W�@��ۥX���u��
							if (B[b - 1] == 1)
							{
								//�@�b�����v�۷s�����
								if (C.v_rand_1 || C.v_rand_15 == 1)
								{
									//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
									if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
									{
										//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
										if (best_state == 0)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else
										{
											A[b] = best_state;
											B[b] = B[b - 1] + 1;
										}
									}
									else
									{
										if (D.big_point > E.big_point)
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												A[b] = D.state;
												B[b] = B[b - 1] + 1;
											}
										}
										else
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												A[b] = E.state;
												B[b] = B[b - 1] + 1;
											}
										}
									}
								}
								else
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									c = b - 1;
								}
							}
							else if (B[b - 1] < 3)
							{
								if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3 ||
									((D.big_point>6) || (E.big_point>6) || (F.big_point>7) || (G.big_point>7)) ||
									((D.small_point>6) || (E.small_point>6) || (F.small_point>7) || (G.small_point>7)) == 1)
								{
									//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
									if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
									{
										//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
										if (best_state == 0)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												A[b] = best_state;
												B[b] = B[b - 1] + 1;
											}
										}
									}
									else
									{
										if (D.big_point > E.big_point)
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												A[b] = D.state;
												B[b] = B[b - 1] + 1;
											}
										}
										else
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												A[b] = E.state;
												B[b] = B[b - 1] + 1;
											}
										}
									}
								}
								else
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									c = b - 1;
								}
							}
							else
							{
								if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3&&C.v_rand_4&&C.v_rand_5&&C.v_rand_6 ||
									((D.big_point > 7) || (E.big_point > 7) || (F.big_point > 8) || (G.big_point > 8)) ||
									((D.small_point > 7) || (E.small_point > 7) || (F.small_point > 8) || (G.small_point > 8)) == 1)
								{
									//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
									if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
									{
										//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
										if (best_state == 0)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												A[b] = best_state;
												B[b] = B[b - 1] + 1;
											}
										}
									}
									else
									{
										if (D.big_point > E.big_point)
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												A[b] = D.state;
												B[b] = B[b - 1] + 1;
											}
										}
										else
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												A[b] = E.state;
												B[b] = B[b - 1] + 1;
											}
										}
									}
								}
								else
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									c = b - 1;
								}
							}
						}
						//�Y�W�@�ӤH�ۥ|�����@
						else if (A[b - 1] == 1)
						{
							//�Ҽ{�W�@��ۥX���u��
							if (B[b - 1] == 1)
							{
								//�@�b�����v�۷s�����
								if (C.v_rand_1 || C.v_rand_15 == 1)
								{
									//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
									if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
									{
										//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
										if (best_state == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else if (best_state == 0)
										{
											if (C.v_rand_2 == 1)
												B[b] = B[b - 1];
											else
												B[b] = B[b - 1] + 1;
											A[b] = best_state;
										}
										else
										{
											A[b] = best_state;
											B[b] = B[b - 1] + 1;
										}
									}
									else
									{
										if (D.big_point > E.big_point)
										{
											if (D.state == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												if (C.v_rand_2 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													A[b] = D.state;
													B[b] = B[b - 1] + 1;
												}
											}
										}
										else
										{
											if (E.state == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												if (C.v_rand_2 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													A[b] = E.state;
													B[b] = B[b - 1] + 1;
												}
											}
										}
									}
								}
								else
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									c = b - 1;
								}
							}
							else if (B[b - 1] < 3)
							{
								if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3 ||
									((D.big_point>6) || (E.big_point>6) || (F.big_point>7) || (G.big_point>7)) ||
									((D.small_point>6) || (E.small_point>6) || (F.small_point>7) || (G.small_point>7)) == 1)
								{
									//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
									if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
									{
										//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
										if (best_state == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else if (best_state == 0)
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												if (C.v_rand_6 || C.v_rand_7 == 1)
													B[b] = B[b - 1];
												else
													B[b] = B[b - 1] + 1;
												A[b] = best_state;
											}
										}
										else
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												A[b] = best_state;
												B[b] = B[b - 1] + 1;
											}
										}
									}
									else
									{
										if (D.big_point > E.big_point)
										{
											if (D.state == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												if (C.v_rand_4 || C.v_rand_5 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													A[b] = D.state;
													B[b] = B[b - 1] + 1;
												}
											}
										}
										else
										{
											if (E.state == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												if (C.v_rand_4 || C.v_rand_5 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													A[b] = E.state;
													B[b] = B[b - 1] + 1;
												}
											}
										}
									}
								}
								else
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									c = b - 1;
								}
							}
							else
							{
								if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3&&C.v_rand_4&&C.v_rand_5&&C.v_rand_6 ||
									((D.big_point > 7) || (E.big_point > 7) || (F.big_point > 8) || (G.big_point > 8)) ||
									((D.small_point > 7) || (E.small_point > 7) || (F.small_point > 8) || (G.small_point > 8)) == 1)
								{
									//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
									if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
									{
										//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
										if (best_state == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else if (best_state == 0)
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
													B[b] = B[b - 1];
												else
													B[b] = B[b - 1] + 1;
												A[b] = best_state;
											}
										}
										else
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												A[b] = best_state;
												B[b] = B[b - 1] + 1;
											}
										}
									}
									else
									{
										if (D.big_point > E.big_point)
										{
											if (D.state == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													A[b] = D.state;
													B[b] = B[b - 1] + 1;
												}
											}
										}
										else
										{
											if (E.state == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													A[b] = E.state;
													B[b] = B[b - 1] + 1;
												}
											}
										}
									}
								}
								else
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									c = b - 1;
								}
							}
						}
						else if (A[b - 1] == 2)
						{
							//�Ҽ{�W�@��ۥX���u��
							if (B[b - 1] == 1)
							{
								//�@�b�����v�۷s�����
								if (C.v_rand_1 || C.v_rand_15 == 1)
								{
									//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
									if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
									{
										//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
										if (best_state == 2)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else if ((best_state == 0) || (best_state == 1) == 1)
										{
											if (C.v_rand_2 == 1)
												B[b] = B[b - 1];
											else
												B[b] = B[b - 1] + 1;
											A[b] = best_state;
										}
										else
										{
											A[b] = best_state;
											B[b] = B[b - 1] + 1;
										}
									}
									else
									{
										if (D.big_point > E.big_point)
										{
											if (D.state == 2)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else if (D.state == 1)
											{
												if (C.v_rand_2 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													if (C.v_rand_3 == 1)
														B[b] = B[b - 1];
													else
														B[b] = B[b - 1] + 1;
													A[b] = D.state;
												}
											}
											else
											{
												if (C.v_rand_2 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													A[b] = D.state;
													B[b] = B[b - 1] + 1;
												}
											}
										}
										else
										{
											if (E.state == 2)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else if (E.state == 1)
											{
												if (C.v_rand_2 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													if (C.v_rand_3 == 1)
														B[b] = B[b - 1];
													else
														B[b] = B[b - 1] + 1;
													A[b] = E.state;
												}
											}
											else
											{
												if (C.v_rand_2 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													A[b] = E.state;
													B[b] = B[b - 1] + 1;
												}
											}
										}
									}
								}
								else
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									c = b - 1;
								}
							}
							else if (B[b - 1] < 3)
							{
								if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3 ||
									((D.big_point>6) || (E.big_point>6) || (F.big_point>7) || (G.big_point>7)) ||
									((D.small_point>6) || (E.small_point>6) || (F.small_point>7) || (G.small_point>7)) == 1)
								{
									//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
									if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
									{
										//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
										if (best_state == 2)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else if ((best_state == 0) || (best_state == 1) == 1)
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												if (C.v_rand_6 || C.v_rand_7 == 1)
													B[b] = B[b - 1];
												else
													B[b] = B[b - 1] + 1;
												A[b] = best_state;
											}
										}
										else
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												A[b] = best_state;
												B[b] = B[b - 1] + 1;
											}
										}
									}
									else
									{
										if (D.big_point > E.big_point)
										{
											if (D.state == 2)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else if (D.state == 1)
											{
												if (C.v_rand_4 || C.v_rand_5 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													if (C.v_rand_6 || C.v_rand_7 == 1)
														B[b] = B[b - 1];
													else
														B[b] = B[b - 1] + 1;
													A[b] = D.state;
												}
											}
											else
											{
												if (C.v_rand_4 || C.v_rand_5 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													A[b] = D.state;
													B[b] = B[b - 1] + 1;
												}
											}
										}
										else
										{
											if (E.state == 2)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else if (E.state == 1)
											{
												if (C.v_rand_4 || C.v_rand_5 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													if (C.v_rand_6 || C.v_rand_7 == 1)
														B[b] = B[b - 1];
													else
														B[b] = B[b - 1] + 1;
													A[b] = E.state;
												}
											}
											else
											{
												if (C.v_rand_4 || C.v_rand_5 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													A[b] = E.state;
													B[b] = B[b - 1] + 1;
												}
											}
										}
									}
								}
								else
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									c = b - 1;
								}
							}
							else
							{
								if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3&&C.v_rand_4&&C.v_rand_5&&C.v_rand_6 ||
									((D.big_point > 7) || (E.big_point > 7) || (F.big_point > 8) || (G.big_point > 8)) ||
									((D.small_point > 7) || (E.small_point > 7) || (F.small_point > 8) || (G.small_point > 8)) == 1)
								{
									//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
									if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
									{
										//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
										if (best_state == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else if ((best_state == 0) || (best_state == 1) == 1)
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
													B[b] = B[b - 1];
												else
													B[b] = B[b - 1] + 1;
												A[b] = best_state;
											}
										}
										else
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												A[b] = best_state;
												B[b] = B[b - 1] + 1;
											}
										}
									}
									else
									{
										if (D.big_point > E.big_point)
										{
											if (D.state == 2)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else if (D.state == 1)
											{
												if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
														B[b] = B[b - 1];
													else
														B[b] = B[b - 1] + 1;
													A[b] = D.state;
												}
											}
											else
											{
												if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													A[b] = D.state;
													B[b] = B[b - 1] + 1;
												}
											}
										}
										else
										{
											if (E.state == 2)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else if (E.state == 1)
											{
												if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
														B[b] = B[b - 1];
													else
														B[b] = B[b - 1] + 1;
													A[b] = E.state;
												}
											}
											else
											{
												if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													A[b] = E.state;
													B[b] = B[b - 1] + 1;
												}
											}
										}
									}
								}
								else
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									c = b - 1;
								}
							}
						}
						else if (A[b - 1] == 3)
						{
							//�Ҽ{�W�@��ۥX���u��
							if (B[b - 1] == 1)
							{
								//�@�b�����v�۷s�����
								if (C.v_rand_1 || C.v_rand_15 == 1)
								{
									//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
									if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
									{
										//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
										if (best_state == 3)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else if ((best_state == 0) || (best_state == 1) || (best_state == 2) == 1)
										{
											if (C.v_rand_2 == 1)
												B[b] = B[b - 1];
											else
												B[b] = B[b - 1] + 1;
											A[b] = best_state;
										}
										else
										{
											A[b] = best_state;
											B[b] = B[b - 1] + 1;
										}
									}
									else
									{
										if (D.big_point > E.big_point)
										{
											if (D.state == 3)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else if ((D.state == 1) || (D.state == 2) == 1)
											{
												if (C.v_rand_2 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													if (C.v_rand_3 == 1)
														B[b] = B[b - 1];
													else
														B[b] = B[b - 1] + 1;
													A[b] = D.state;
												}
											}
											else
											{
												if (C.v_rand_2 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													A[b] = D.state;
													B[b] = B[b - 1] + 1;
												}
											}
										}
										else
										{
											if (E.state == 3)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else if ((E.state == 1) || (E.state == 2) == 1)
											{
												if (C.v_rand_2 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													if (C.v_rand_3 == 1)
														B[b] = B[b - 1];
													else
														B[b] = B[b - 1] + 1;
													A[b] = E.state;
												}
											}
											else
											{
												if (C.v_rand_2 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													A[b] = E.state;
													B[b] = B[b - 1] + 1;
												}
											}
										}
									}
								}
								else
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									c = b - 1;
								}
							}
							else if (B[b - 1] < 3)
							{
								if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3 ||
									((D.big_point>6) || (E.big_point>6) || (F.big_point>7) || (G.big_point>7)) ||
									((D.small_point>6) || (E.small_point>6) || (F.small_point>7) || (G.small_point>7)) == 1)
								{
									//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
									if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
									{
										//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
										if (best_state == 3)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else if ((best_state == 0) || (best_state == 1) || (best_state == 2) == 1)
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												if (C.v_rand_6 || C.v_rand_7 == 1)
													B[b] = B[b - 1];
												else
													B[b] = B[b - 1] + 1;
												A[b] = best_state;
											}
										}
										else
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												A[b] = best_state;
												B[b] = B[b - 1] + 1;
											}
										}
									}
									else
									{
										if (D.big_point > E.big_point)
										{
											if (D.state == 3)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else if ((D.state == 1) || (D.state == 2) == 1)
											{
												if (C.v_rand_4 || C.v_rand_5 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													if (C.v_rand_6 || C.v_rand_7 == 1)
														B[b] = B[b - 1];
													else
														B[b] = B[b - 1] + 1;
													A[b] = D.state;
												}
											}
											else
											{
												if (C.v_rand_4 || C.v_rand_5 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													A[b] = D.state;
													B[b] = B[b - 1] + 1;
												}
											}
										}
										else
										{
											if (E.state == 3)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else if ((E.state == 1) || (E.state == 2) == 1)
											{
												if (C.v_rand_4 || C.v_rand_5 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													if (C.v_rand_6 || C.v_rand_7 == 1)
														B[b] = B[b - 1];
													else
														B[b] = B[b - 1] + 1;
													A[b] = E.state;
												}
											}
											else
											{
												if (C.v_rand_4 || C.v_rand_5 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													A[b] = E.state;
													B[b] = B[b - 1] + 1;
												}
											}
										}
									}
								}
								else
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									c = b - 1;
								}
							}
							else
							{
								if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3&&C.v_rand_4&&C.v_rand_5&&C.v_rand_6 ||
									((D.big_point > 7) || (E.big_point > 7) || (F.big_point > 8) || (G.big_point > 8)) ||
									((D.small_point > 7) || (E.small_point > 7) || (F.small_point > 8) || (G.small_point > 8)) == 1)
								{
									//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
									if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
									{
										//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
										if (best_state == 3)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else if ((best_state == 0) || (best_state == 1) || (best_state == 2) == 1)
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
													B[b] = B[b - 1];
												else
													B[b] = B[b - 1] + 1;
												A[b] = best_state;
											}
										}
										else
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												A[b] = best_state;
												B[b] = B[b - 1] + 1;
											}
										}
									}
									else
									{
										if (D.big_point > E.big_point)
										{
											if (D.state == 3)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else if ((D.state == 1) || (D.state == 2) == 1)
											{
												if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
														B[b] = B[b - 1];
													else
														B[b] = B[b - 1] + 1;
													A[b] = D.state;
												}
											}
											else
											{
												if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													A[b] = D.state;
													B[b] = B[b - 1] + 1;
												}
											}
										}
										else
										{
											if (E.state == 3)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else if ((E.state == 1) || (E.state == 2) == 1)
											{
												if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
														B[b] = B[b - 1];
													else
														B[b] = B[b - 1] + 1;
													A[b] = E.state;
												}
											}
											else
											{
												if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													A[b] = E.state;
													B[b] = B[b - 1] + 1;
												}
											}
										}
									}
								}
								else
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									c = b - 1;
								}
							}
						}
						else if (A[b - 1] == 4)
						{
							//�Ҽ{�W�@��ۥX���u��
							if (B[b - 1] == 1)
							{
								//�@�b�����v�۷s�����
								if (C.v_rand_1 || C.v_rand_15 == 1)
								{
									//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
									if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
									{
										//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
										if (best_state == 4)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else if ((best_state == 0) || (best_state == 1) || (best_state == 2) || (best_state == 3) == 1)
										{
											if (C.v_rand_2 == 1)
												B[b] = B[b - 1];
											else
												B[b] = B[b - 1] + 1;
											A[b] = best_state;
										}
										else
										{
											A[b] = best_state;
											B[b] = B[b - 1] + 1;
										}
									}
									else
									{
										if (D.big_point > E.big_point)
										{
											if (D.state == 4)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											//�W�@�H�۪���⬰����,�T�b���ɳ۶®�,����,����ҥi��ܽu��O�_�n+1
											else
											{
												if (C.v_rand_2 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													if (C.v_rand_3 == 1)
														B[b] = B[b - 1];
													else
														B[b] = B[b - 1] + 1;
													A[b] = D.state;
												}
											}
										}
										else
										{
											if (E.state == 4)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												if (C.v_rand_2 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													if (C.v_rand_3 == 1)
														B[b] = B[b - 1];
													else
														B[b] = B[b - 1] + 1;
													A[b] = E.state;
												}
											}
										}
									}
								}
								else
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									c = b - 1;
								}
							}
							else if (B[b - 1] < 3)
							{
								if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3 ||
									((D.big_point>6) || (E.big_point>6) || (F.big_point>7) || (G.big_point>7)) ||
									((D.small_point>6) || (E.small_point>6) || (F.small_point>7) || (G.small_point>7)) == 1)
								{
									//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
									if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
									{
										//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
										if (best_state == 4)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else if ((best_state == 0) || (best_state == 1) || (best_state == 2) || (best_state == 3) == 1)
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												if (C.v_rand_6 || C.v_rand_7 == 1)
													B[b] = B[b - 1];
												else
													B[b] = B[b - 1] + 1;
												A[b] = best_state;
											}
										}
										else
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												A[b] = best_state;
												B[b] = B[b - 1] + 1;
											}
										}
									}
									else
									{
										if (D.big_point > E.big_point)
										{
											if (D.state == 4)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											//�W�@�H�۪���⬰����,�T�b���ɳ۶®�,����,����ҥi��ܽu��O�_�n+1
											else
											{
												if (C.v_rand_4 || C.v_rand_5 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													if (C.v_rand_6 || C.v_rand_7 == 1)
														B[b] = B[b - 1];
													else
														B[b] = B[b - 1] + 1;
													A[b] = D.state;
												}
											}
										}
										else
										{
											if (E.state == 4)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												if (C.v_rand_4 || C.v_rand_5 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													if (C.v_rand_6 || C.v_rand_7 == 1)
														B[b] = B[b - 1];
													else
														B[b] = B[b - 1] + 1;
													A[b] = E.state;
												}
											}
										}
									}
								}
								else
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									c = b - 1;
								}
							}
							else
							{
								if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3&&C.v_rand_4&&C.v_rand_5&&C.v_rand_6 ||
									((D.big_point > 7) || (E.big_point > 7) || (F.big_point > 8) || (G.big_point > 8)) ||
									((D.small_point > 7) || (E.small_point > 7) || (F.small_point > 8) || (G.small_point > 8)) == 1)
								{
									//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
									if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
									{
										//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
										if (best_state == 4)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else if ((best_state == 0) || (best_state == 1) || (best_state == 2) || (best_state == 3) == 1)
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
													B[b] = B[b - 1];
												else
													B[b] = B[b - 1] + 1;
												A[b] = best_state;
											}
										}
										else
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												A[b] = best_state;
												B[b] = B[b - 1] + 1;
											}
										}
									}
									else
									{
										if (D.big_point > E.big_point)
										{
											if (D.state == 4)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											//�W�@�H�۪���⬰����,�T�b���ɳ۶®�,����,����ҥi��ܽu��O�_�n+1
											else
											{
												if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
														B[b] = B[b - 1];
													else
														B[b] = B[b - 1] + 1;
													A[b] = D.state;
												}
											}
										}
										else
										{
											if (E.state == 4)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
														B[b] = B[b - 1];
													else
														B[b] = B[b - 1] + 1;
													A[b] = E.state;
												}
											}
										}
									}
								}
								else
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									c = b - 1;
								}
							}
						}
						//�Y�W�@�ӤH��small
						else
						{
							//�Ҽ{�W�@��ۥX���u��
							if (B[b - 1] == 1)
							{
								//�@�b�����v�۷s�����
								if (C.v_rand_1 || C.v_rand_15 == 1)
								{
									//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
									if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
									{
										//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
										if (best_state == 5)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else
										{
											if (C.v_rand_2 == 1)
												B[b] = B[b - 1];
											else
												B[b] = B[b - 1] + 1;
											A[b] = best_state;
										}
									}
									else
									{
										if (D.big_point > E.big_point)
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												if (C.v_rand_3 == 1)
													B[b] = B[b - 1];
												else
													B[b] = B[b - 1] + 1;
												A[b] = D.state;
											}
										}
										else
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												if (C.v_rand_3 == 1)
													B[b] = B[b - 1];
												else
													B[b] = B[b - 1] + 1;
												A[b] = E.state;
											}
										}
									}
								}
								else
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									c = b - 1;
								}
							}
							else if (B[b - 1] < 3)
							{
								if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3 ||
									((D.big_point>6) || (E.big_point>6) || (F.big_point>7) || (G.big_point>7)) ||
									((D.small_point>6) || (E.small_point>6) || (F.small_point>7) || (G.small_point>7)) == 1)
								{
									//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
									if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
									{
										//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
										if (best_state == 5)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
												B[b] = B[b - 1];
											else
												B[b] = B[b - 1] + 1;
											A[b] = best_state;
										}
									}
									else
									{
										if (D.big_point > E.big_point)
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												if (C.v_rand_6 || C.v_rand_7 == 1)
													B[b] = B[b - 1];
												else
													B[b] = B[b - 1] + 1;
												A[b] = D.state;
											}
										}
										else
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												if (C.v_rand_6 || C.v_rand_7 == 1)
													B[b] = B[b - 1];
												else
													B[b] = B[b - 1] + 1;
												A[b] = E.state;
											}
										}
									}
								}
								else
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									c = b - 1;
								}
							}
							else
							{
								if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3&&C.v_rand_4&&C.v_rand_5&&C.v_rand_6 ||
									((D.big_point > 7) || (E.big_point > 7) || (F.big_point > 8) || (G.big_point > 8)) ||
									((D.small_point > 7) || (E.small_point > 7) || (F.small_point > 8) || (G.small_point > 8)) == 1)
								{
									//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
									if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
									{
										//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
										if (best_state == 5)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
												B[b] = B[b - 1];
											else
												B[b] = B[b - 1] + 1;
											A[b] = best_state;
										}
									}
									else
									{
										if (D.big_point > E.big_point)
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
													B[b] = B[b - 1];
												else
													B[b] = B[b - 1] + 1;
												A[b] = D.state;
											}
										}
										else
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
													B[b] = B[b - 1];
												else
													B[b] = B[b - 1] + 1;
												A[b] = E.state;
											}
										}
									}
								}
								else
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									c = b - 1;
								}
							}
						}
					}
				}
				else
				{
					for (int i = 0; i < 2; i++)
					{
						if (b - 2 - 4 * i > 0)
							partner_color[i] = A[b - 2 - 4 * i];
					}
					for (int i = 0; i < 2; i++)
					{
						if (b - 3 - 4 * i > 0)
							enemy1_color[i] = A[b - 3 - 4 * i];
						if (b - 1 - 4 * i > 0)
							enemy2_color[i] = A[b - 1 - 4 * i];
					}
					int temp0 = 0, temp1 = 0, temp2 = 0, temp3 = 0, temp4 = 0, temp5 = 0, temp_no = 0;
					for (int i = 0; i < 2; i++)
					{
						if (partner_color[i] == D.state)
							temp1 += i + 1;
						else if (partner_color[i] == E.state)
							temp2 += i + 1;
						else if (partner_color[i] == F.state)
							temp3 += i + 1;
						else if (partner_color[i] == G.state)
							temp4 += i + 1;
						else if (partner_color[i] == 0)
							temp0 += i + 1;
						else if (partner_color[i] == 5)
							temp5 += i + 1;
						else
							temp_no += i + 1;
						if (enemy1_color[i] == D.state)
							temp1 -= i + 1;
						else if (enemy1_color[i] == E.state)
							temp2 -= i + 1;
						else if (enemy1_color[i] == F.state)
							temp3 -= i + 1;
						else if (enemy1_color[i] == G.state)
							temp4 -= i + 1;
						else if (enemy1_color[i] == 0)
							temp0 -= i + 1;
						else if (enemy1_color[i] == 5)
							temp5 -= i + 1;
						else
							temp_no -= i + 1;
						if (enemy2_color[i] == D.state)
							temp1 -= i + 1;
						else if (enemy2_color[i] == E.state)
							temp2 -= i + 1;
						else if (enemy2_color[i] == F.state)
							temp3 -= i + 1;
						else if (enemy2_color[i] == G.state)
							temp4 -= i + 1;
						else if (enemy2_color[i] == 0)
							temp0 -= i + 1;
						else if (enemy2_color[i] == 5)
							temp5 -= i + 1;
						else
							temp_no -= i + 1;
					}
					int P[7] = { temp0,temp1,temp2,temp3,temp4,temp5,temp_no };
					int best_state;
					int bubble_sort[7] = { temp0,temp1,temp2,temp3,temp4,temp5,temp_no };
					for (int i = 6; i >= 0; i--)
					{
						for (int j = 0; j < i; j++)
						{
							int t;
							if (bubble_sort[j] < bubble_sort[j + 1])
							{
								t = bubble_sort[j + 1];
								bubble_sort[j + 1] = bubble_sort[j];
								bubble_sort[j] = t;
							}
						}
					}
					for (int i = 0; i < 7; i++)
					{
						if (bubble_sort[0] == P[i])
						{
							if (i == 0)
								best_state = 0;
							else if (i == 1)
								best_state = D.state;
							else if (i == 2)
								best_state = E.state;
							else if (i == 3)
								best_state = F.state;
							else if (i == 4)
								best_state = G.state;
							else if (i == 5)
								best_state = 5;
							else
								best_state = D.state;
							break;
						}
					}
					/*���]���̨θѬ�bubble_sort[0]�ҹ��������!!*/
					//���|�X�{A[b-1]=6������,�]���W�@�ӤH���w�S��accept!!
					if (bubble_sort[0] == bubble_sort[1]) //���]�䤣��̨θ�,���ɵL�k���T�M�w�n�۪����
					{
						if (A[b - 1] == 0)
						{
							if (B[b - 1] == 1)
							{
								if (C.v_rand_1 || C.v_rand_15 == 1)
								{
									if (a1&&b1&&c1&&d1 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										c = b - 1;
									}
									else if (e1 == 1)
									{
										if (C.v_rand_2 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else
										{
											A[b] = 5;
											B[b] = B[b - 1] + 1;
										}
									}
									else
									{
										if (D.big_point > E.big_point)
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												A[b] = D.state;
												B[b] = B[b - 1] + 1;
											}
										}
										else
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												A[b] = E.state;
												B[b] = B[b - 1] + 1;
											}
										}
									}
								}
								else
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									c = b - 1;
								}
							}
							else if (B[b - 1] < 3)
							{
								if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3 == 1)
								{
									if (a1&&b1&&c1&&d1 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										c = b - 1;
									}
									else if (e1 == 1)
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else
										{
											A[b] = 5;
											B[b] = B[b - 1] + 1;
										}
									}
									else
									{
										if (D.big_point > E.big_point)
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												A[b] = D.state;
												B[b] = B[b - 1] + 1;
											}
										}
										else
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												A[b] = E.state;
												B[b] = B[b - 1] + 1;
											}
										}
									}
								}
								else
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									c = b - 1;
								}
							}
							else
							{
								if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3&&C.v_rand_4&&C.v_rand_5&&C.v_rand_6 == 1)
								{
									if (a1&&b1&&c1&&d1 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										c = b - 1;
									}
									else if (e1 == 1)
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else
										{
											A[b] = 5;
											B[b] = B[b - 1] + 1;
										}
									}
									else
									{
										if (D.big_point > E.big_point)
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												A[b] = D.state;
												B[b] = B[b - 1] + 1;
											}
										}
										else
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												A[b] = E.state;
												B[b] = B[b - 1] + 1;
											}
										}
									}
								}
								else
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									c = b - 1;
								}
							}
						}
						else if (A[b - 1] == 1)
						{
							if (B[b - 1] == 1)
							{
								if (C.v_rand_1 || C.v_rand_15 == 1)
								{
									if (a1&&b1&&c1&&d1 == 1)
									{
										if (C.v_rand_2 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else
										{
											if (C.v_rand_3 == 1)
												B[b] = B[b - 1];
											else
												B[b] = B[b - 1] + 1;
											A[b] = 0;
										}
									}
									else if (e1 == 1)
									{
										if (C.v_rand_2 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else
										{
											A[b] = 5;
											B[b] = B[b - 1] + 1;
										}
									}
									else
									{
										if (D.big_point > E.big_point)
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												A[b] = D.state;
												B[b] = B[b - 1] + 1;
											}
										}
										else
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												A[b] = E.state;
												B[b] = B[b - 1] + 1;
											}
										}
									}
								}
								else
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									c = b - 1;
								}
							}
							else if (B[b - 1] < 3)
							{
								if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3 == 1)
								{
									if (a1&&b1&&c1&&d1 == 1)
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else
										{
											if (C.v_rand_6 || C.v_rand_7 == 1)
												B[b] = B[b - 1];
											else
												B[b] = B[b - 1] + 1;
											A[b] = 0;
										}
									}
									else if (e1 == 1)
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else
										{
											A[b] = 5;
											B[b] = B[b - 1] + 1;
										}
									}
									else
									{
										if (D.big_point > E.big_point)
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												A[b] = D.state;
												B[b] = B[b - 1] + 1;
											}
										}
										else
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												A[b] = E.state;
												B[b] = B[b - 1] + 1;
											}
										}
									}
								}
								else
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									c = b - 1;
								}
							}
							else
							{
								if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3&&C.v_rand_4&&C.v_rand_5&&C.v_rand_6 == 1)
								{
									if (a1&&b1&&c1&&d1 == 1)
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else
										{
											if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
												B[b] = B[b - 1];
											else
												B[b] = B[b - 1] + 1;
											A[b] = 0;
										}
									}
									else if (e1 == 1)
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else
										{
											A[b] = 5;
											B[b] = B[b - 1] + 1;
										}
									}
									else
									{
										if (D.big_point > E.big_point)
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												A[b] = D.state;
												B[b] = B[b - 1] + 1;
											}
										}
										else
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												A[b] = E.state;
												B[b] = B[b - 1] + 1;
											}
										}
									}
								}
								else
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									c = b - 1;
								}
							}
						}
						else if (A[b - 1] == 2)
						{
							if (B[b - 1] == 1)
							{
								if (C.v_rand_1 || C.v_rand_15 == 1)
								{
									if (a1&&b1&&c1&&d1 == 1)
									{
										if (C.v_rand_2 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else
										{
											if (C.v_rand_3 == 1)
												B[b] = B[b - 1];
											else
												B[b] = B[b - 1] + 1;
											A[b] = 0;
										}
									}
									else if (e1 == 1)
									{
										if (C.v_rand_2 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else
										{
											A[b] = 5;
											B[b] = B[b - 1] + 1;
										}
									}
									else
									{
										if (D.big_point > E.big_point)
										{
											if (D.state == 2)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else if (D.state == 1)
											{
												if (C.v_rand_2 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													if (C.v_rand_3 == 1)
														B[b] = B[b - 1];
													else
														B[b] = B[b - 1] + 1;
													A[b] = D.state;
												}
											}
											else
											{
												if (C.v_rand_2 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													A[b] = D.state;
													B[b] = B[b - 1] + 1;
												}
											}
										}
										else
										{
											if (E.state == 2)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else if (E.state == 1)
											{
												if (C.v_rand_2 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													if (C.v_rand_3 == 1)
														B[b] = B[b - 1];
													else
														B[b] = B[b - 1] + 1;
													A[b] = E.state;
												}
											}
											else
											{
												if (C.v_rand_2 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													A[b] = E.state;
													B[b] = B[b - 1] + 1;
												}
											}
										}
									}
								}
								else
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									c = b - 1;
								}
							}
							else if (B[b - 1] < 3)
							{
								if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3 == 1)
								{
									if (a1&&b1&&c1&&d1 == 1)
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else
										{
											if (C.v_rand_6 || C.v_rand_7 == 1)
												B[b] = B[b - 1];
											else
												B[b] = B[b - 1] + 1;
											A[b] = 0;
										}
									}
									else if (e1 == 1)
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else
										{
											A[b] = 5;
											B[b] = B[b - 1] + 1;
										}
									}
									else
									{
										if (D.big_point > E.big_point)
										{
											if (D.state == 2)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else if (D.state == 1)
											{
												if (C.v_rand_4 || C.v_rand_5 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													if (C.v_rand_6 || C.v_rand_7 == 1)
														B[b] = B[b - 1];
													else
														B[b] = B[b - 1] + 1;
													A[b] = D.state;
												}
											}
											else
											{
												if (C.v_rand_4 || C.v_rand_5 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													A[b] = D.state;
													B[b] = B[b - 1] + 1;
												}
											}
										}
										else
										{
											if (E.state == 2)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else if (E.state == 1)
											{
												if (C.v_rand_4 || C.v_rand_5 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													if (C.v_rand_6 || C.v_rand_7 == 1)
														B[b] = B[b - 1];
													else
														B[b] = B[b - 1] + 1;
													A[b] = E.state;
												}
											}
											else
											{
												if (C.v_rand_4 || C.v_rand_5 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													A[b] = E.state;
													B[b] = B[b - 1] + 1;
												}
											}
										}
									}
								}
								else
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									c = b - 1;
								}
							}
							else
							{
								if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3&&C.v_rand_4&&C.v_rand_5&&C.v_rand_6 == 1)
								{
									if (a1&&b1&&c1&&d1 == 1)
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else
										{
											if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
												B[b] = B[b - 1];
											else
												B[b] = B[b - 1] + 1;
											A[b] = 0;
										}
									}
									else if (e1 == 1)
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else
										{
											A[b] = 5;
											B[b] = B[b - 1] + 1;
										}
									}
									else
									{
										if (D.big_point > E.big_point)
										{
											if (D.state == 2)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else if (D.state == 1)
											{
												if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
														B[b] = B[b - 1];
													else
														B[b] = B[b - 1] + 1;
													A[b] = D.state;
												}
											}
											else
											{
												if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													A[b] = D.state;
													B[b] = B[b - 1] + 1;
												}
											}
										}
										else
										{
											if (E.state == 2)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else if (E.state == 1)
											{
												if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
														B[b] = B[b - 1];
													else
														B[b] = B[b - 1] + 1;
													A[b] = E.state;
												}
											}
											else
											{
												if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													A[b] = E.state;
													B[b] = B[b - 1] + 1;
												}
											}
										}
									}
								}
								else
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									c = b - 1;
								}
							}
						}
						else if (A[b - 1] == 3)
						{
							if (B[b - 1] == 1)
							{
								if (C.v_rand_1 || C.v_rand_15 == 1)
								{
									if (a1&&b1&&c1&&d1 == 1)
									{
										if (C.v_rand_2 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else
										{
											if (C.v_rand_3 == 1)
												B[b] = B[b - 1];
											else
												B[b] = B[b - 1] + 1;
											A[b] = 0;
										}
									}
									else if (e1 == 1)
									{
										if (C.v_rand_2 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else
										{
											A[b] = 5;
											B[b] = B[b - 1] + 1;
										}
									}
									else
									{
										if (D.big_point > E.big_point)
										{
											if (D.state == 3)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else if ((D.state == 1) || (D.state == 2) == 1)
											{
												if (C.v_rand_2 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													if (C.v_rand_3 == 1)
														B[b] = B[b - 1];
													else
														B[b] = B[b - 1] + 1;
													A[b] = D.state;
												}
											}
											else
											{
												if (C.v_rand_2 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													A[b] = D.state;
													B[b] = B[b - 1] + 1;
												}
											}
										}
										else
										{
											if (E.state == 3)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else if ((E.state == 1) || (E.state == 2) == 1)
											{
												if (C.v_rand_2 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													if (C.v_rand_3 == 1)
														B[b] = B[b - 1];
													else
														B[b] = B[b - 1] + 1;
													A[b] = E.state;
												}
											}
											else
											{
												if (C.v_rand_2 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													A[b] = E.state;
													B[b] = B[b - 1] + 1;
												}
											}
										}
									}
								}
								else
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									c = b - 1;
								}
							}
							else if (B[b - 1] < 3)
							{
								if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3 == 1)
								{
									if (a1&&b1&&c1&&d1 == 1)
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else
										{
											if (C.v_rand_6 || C.v_rand_7 == 1)
												B[b] = B[b - 1];
											else
												B[b] = B[b - 1] + 1;
											A[b] = 0;
										}
									}
									else if (e1 == 1)
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else
										{
											A[b] = 5;
											B[b] = B[b - 1] + 1;
										}
									}
									else
									{
										if (D.big_point > E.big_point)
										{
											if (D.state == 3)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else if ((D.state == 1) || (D.state == 2) == 1)
											{
												if (C.v_rand_4 || C.v_rand_5 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													if (C.v_rand_6 || C.v_rand_7 == 1)
														B[b] = B[b - 1];
													else
														B[b] = B[b - 1] + 1;
													A[b] = D.state;
												}
											}
											else
											{
												if (C.v_rand_4 || C.v_rand_5 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													A[b] = D.state;
													B[b] = B[b - 1] + 1;
												}
											}
										}
										else
										{
											if (E.state == 3)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else if ((E.state == 1) || (E.state == 2) == 1)
											{
												if (C.v_rand_4 || C.v_rand_5 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													if (C.v_rand_6 || C.v_rand_7 == 1)
														B[b] = B[b - 1];
													else
														B[b] = B[b - 1] + 1;
													A[b] = E.state;
												}
											}
											else
											{
												if (C.v_rand_4 || C.v_rand_5 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													A[b] = E.state;
													B[b] = B[b - 1] + 1;
												}
											}
										}
									}
								}
								else
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									c = b - 1;
								}
							}
							else
							{
								if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3&&C.v_rand_4&&C.v_rand_5&&C.v_rand_6 == 1)
								{
									if (a1&&b1&&c1&&d1 == 1)
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else
										{
											if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
												B[b] = B[b - 1];
											else
												B[b] = B[b - 1] + 1;
											A[b] = 0;
										}
									}
									else if (e1 == 1)
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else
										{
											A[b] = 5;
											B[b] = B[b - 1] + 1;
										}
									}
									else
									{
										if (D.big_point > E.big_point)
										{
											if (D.state == 3)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else if ((D.state == 1) || (D.state == 2) == 1)
											{
												if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
														B[b] = B[b - 1];
													else
														B[b] = B[b - 1] + 1;
													A[b] = D.state;
												}
											}
											else
											{
												if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													A[b] = D.state;
													B[b] = B[b - 1] + 1;
												}
											}
										}
										else
										{
											if (E.state == 3)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else if ((E.state == 1) || (E.state == 2) == 1)
											{
												if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
														B[b] = B[b - 1];
													else
														B[b] = B[b - 1] + 1;
													A[b] = E.state;
												}
											}
											else
											{
												if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													A[b] = E.state;
													B[b] = B[b - 1] + 1;
												}
											}
										}
									}
								}
								else
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									c = b - 1;
								}
							}
						}
						else if (A[b - 1] == 4)
						{
							if (B[b - 1] == 1)
							{
								if (C.v_rand_1 || C.v_rand_15 == 1)
								{
									if (a1&&b1&&c1&&d1 == 1)
									{
										if (C.v_rand_2 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else
										{
											if (C.v_rand_3 == 1)
												B[b] = B[b - 1];
											else
												B[b] = B[b - 1] + 1;
											A[b] = 0;
										}
									}
									else if (e1 == 1)
									{
										if (C.v_rand_2 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else
										{
											A[b] = 5;
											B[b] = B[b - 1] + 1;
										}
									}
									else
									{
										if (D.big_point > E.big_point)
										{
											if (D.state == 4)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											//�W�@�H�۪���⬰����,�T�b���ɳ۶®�,����,����ҥi��ܽu��O�_�n+1
											else
											{
												if (C.v_rand_2 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													if (C.v_rand_3 == 1)
														B[b] = B[b - 1];
													else
														B[b] = B[b - 1] + 1;
													A[b] = D.state;
												}
											}
										}
										else
										{
											if (E.state == 4)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												if (C.v_rand_2 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													if (C.v_rand_3 == 1)
														B[b] = B[b - 1];
													else
														B[b] = B[b - 1] + 1;
													A[b] = E.state;
												}
											}
										}
									}
								}
								else
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									c = b - 1;
								}
							}
							else if (B[b - 1] < 3)
							{
								if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3 == 1)
								{
									if (a1&&b1&&c1&&d1 == 1)
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else
										{
											if (C.v_rand_6 || C.v_rand_7 == 1)
												B[b] = B[b - 1];
											else
												B[b] = B[b - 1] + 1;
											A[b] = 0;
										}
									}
									else if (e1 == 1)
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else
										{
											A[b] = 5;
											B[b] = B[b - 1] + 1;
										}
									}
									else
									{
										if (D.big_point > E.big_point)
										{
											if (D.state == 4)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											//�W�@�H�۪���⬰����,�T�b���ɳ۶®�,����,����ҥi��ܽu��O�_�n+1
											else
											{
												if (C.v_rand_4 || C.v_rand_5 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													if (C.v_rand_6 || C.v_rand_7 == 1)
														B[b] = B[b - 1];
													else
														B[b] = B[b - 1] + 1;
													A[b] = D.state;
												}
											}
										}
										else
										{
											if (E.state == 4)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												if (C.v_rand_4 || C.v_rand_5 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													if (C.v_rand_6 || C.v_rand_7 == 1)
														B[b] = B[b - 1];
													else
														B[b] = B[b - 1] + 1;
													A[b] = E.state;
												}
											}
										}
									}
								}
								else
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									c = b - 1;
								}
							}
							else
							{
								if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3&&C.v_rand_4&&C.v_rand_5&&C.v_rand_6 == 1)
								{
									if (a1&&b1&&c1&&d1 == 1)
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else
										{
											if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
												B[b] = B[b - 1];
											else
												B[b] = B[b - 1] + 1;
											A[b] = 0;
										}
									}
									else if (e1 == 1)
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else
										{
											A[b] = 5;
											B[b] = B[b - 1] + 1;
										}
									}
									else
									{
										if (D.big_point > E.big_point)
										{
											if (D.state == 4)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											//�W�@�H�۪���⬰����,�T�b���ɳ۶®�,����,����ҥi��ܽu��O�_�n+1
											else
											{
												if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
														B[b] = B[b - 1];
													else
														B[b] = B[b - 1] + 1;
													A[b] = D.state;
												}
											}
										}
										else
										{
											if (E.state == 4)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
														B[b] = B[b - 1];
													else
														B[b] = B[b - 1] + 1;
													A[b] = E.state;
												}
											}
										}
									}
								}
								else
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									c = b - 1;
								}
							}
						}
						else
						{
							if (B[b - 1] == 1)
							{
								if (C.v_rand_1 || C.v_rand_15 == 1)
								{
									if (a1&&b1&&c1&&d1 == 1)
									{
										if (C.v_rand_2 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else
										{
											if (C.v_rand_3 == 1)
												B[b] = B[b - 1];
											else
												B[b] = B[b - 1] + 1;
											A[b] = 0;
										}
									}
									else if (e1 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										c = b - 1;
									}
									else
									{
										if (D.big_point > E.big_point)
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												if (C.v_rand_3 == 1)
													B[b] = B[b - 1];
												else
													B[b] = B[b - 1] + 1;
												A[b] = D.state;
											}
										}
										else
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												if (C.v_rand_3 == 1)
													B[b] = B[b - 1];
												else
													B[b] = B[b - 1] + 1;
												A[b] = E.state;
											}
										}
									}
								}
								else
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									c = b - 1;
								}
							}
							else if (B[b - 1] < 3)
							{
								if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3 == 1)
								{
									if (a1&&b1&&c1&&d1 == 1)
									{
										if (C.v_rand_4 || C.v_rand_5 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else
										{
											if (C.v_rand_6 || C.v_rand_7 == 1)
												B[b] = B[b - 1];
											else
												B[b] = B[b - 1] + 1;
											A[b] = 0;
										}
									}
									else if (e1 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										c = b - 1;
									}
									else
									{
										if (D.big_point > E.big_point)
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												if (C.v_rand_6 || C.v_rand_7 == 1)
													B[b] = B[b - 1];
												else
													B[b] = B[b - 1] + 1;
												A[b] = D.state;
											}
										}
										else
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												if (C.v_rand_6 || C.v_rand_7 == 1)
													B[b] = B[b - 1];
												else
													B[b] = B[b - 1] + 1;
												A[b] = E.state;
											}
										}
									}
								}
								else
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									c = b - 1;
								}
							}
							else
							{
								if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3&&C.v_rand_4&&C.v_rand_5&&C.v_rand_6 == 1)
								{
									if (a1&&b1&&c1&&d1 == 1)
									{
										if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else
										{
											if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
												B[b] = B[b - 1];
											else
												B[b] = B[b - 1] + 1;
											A[b] = 0;
										}
									}
									else if (e1 == 1)
									{
										A[b] = 6;
										B[b] = 0;
										a++;
										c = b - 1;
									}
									else
									{
										if (D.big_point > E.big_point)
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
													B[b] = B[b - 1];
												else
													B[b] = B[b - 1] + 1;
												A[b] = D.state;
											}
										}
										else
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
													B[b] = B[b - 1];
												else
													B[b] = B[b - 1] + 1;
												A[b] = E.state;
											}
										}
									}
								}
								else
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									c = b - 1;
								}
							}
						}
					}
					else
					{
						//���Ҽ{���,�E�ƬݬO+1�η���!!
						//�Y�W�@�ӤH�۵L��
						if (A[b - 1] == 0)
						{
							//�Ҽ{�W�@��ۥX���u��
							if (B[b - 1] == 1)
							{
								//�@�b�����v�۷s�����
								if (C.v_rand_1 || C.v_rand_15 == 1)
								{
									//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
									if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
									{
										//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
										if (best_state == 0)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else
										{
											A[b] = best_state;
											B[b] = B[b - 1] + 1;
										}
									}
									else
									{
										if (D.big_point > E.big_point)
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												A[b] = D.state;
												B[b] = B[b - 1] + 1;
											}
										}
										else
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												A[b] = E.state;
												B[b] = B[b - 1] + 1;
											}
										}
									}
								}
								else
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									c = b - 1;
								}
							}
							else if (B[b - 1] < 3)
							{
								if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3 ||
									((D.big_point>6) || (E.big_point>6) || (F.big_point>7) || (G.big_point>7)) ||
									((D.small_point>6) || (E.small_point>6) || (F.small_point>7) || (G.small_point>7)) == 1)
								{
									//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
									if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
									{
										//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
										if (best_state == 0)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												A[b] = best_state;
												B[b] = B[b - 1] + 1;
											}
										}
									}
									else
									{
										if (D.big_point > E.big_point)
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												A[b] = D.state;
												B[b] = B[b - 1] + 1;
											}
										}
										else
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												A[b] = E.state;
												B[b] = B[b - 1] + 1;
											}
										}
									}
								}
								else
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									c = b - 1;
								}
							}
							else
							{
								if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3&&C.v_rand_4&&C.v_rand_5&&C.v_rand_6 ||
									((D.big_point > 7) || (E.big_point > 7) || (F.big_point > 8) || (G.big_point > 8)) ||
									((D.small_point > 7) || (E.small_point > 7) || (F.small_point > 8) || (G.small_point > 8)) == 1)
								{
									//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
									if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
									{
										//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
										if (best_state == 0)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												A[b] = best_state;
												B[b] = B[b - 1] + 1;
											}
										}
									}
									else
									{
										if (D.big_point > E.big_point)
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												A[b] = D.state;
												B[b] = B[b - 1] + 1;
											}
										}
										else
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												A[b] = E.state;
												B[b] = B[b - 1] + 1;
											}
										}
									}
								}
								else
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									c = b - 1;
								}
							}
						}
						//�Y�W�@�ӤH�ۥ|�����@
						else if (A[b - 1] == 1)
						{
							//�Ҽ{�W�@��ۥX���u��
							if (B[b - 1] == 1)
							{
								//�@�b�����v�۷s�����
								if (C.v_rand_1 || C.v_rand_15 == 1)
								{
									//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
									if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
									{
										//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
										if (best_state == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else if (best_state == 0)
										{
											if (C.v_rand_2 == 1)
												B[b] = B[b - 1];
											else
												B[b] = B[b - 1] + 1;
											A[b] = best_state;
										}
										else
										{
											A[b] = best_state;
											B[b] = B[b - 1] + 1;
										}
									}
									else
									{
										if (D.big_point > E.big_point)
										{
											if (D.state == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												if (C.v_rand_2 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													A[b] = D.state;
													B[b] = B[b - 1] + 1;
												}
											}
										}
										else
										{
											if (E.state == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												if (C.v_rand_2 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													A[b] = E.state;
													B[b] = B[b - 1] + 1;
												}
											}
										}
									}
								}
								else
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									c = b - 1;
								}
							}
							else if (B[b - 1] < 3)
							{
								if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3 ||
									((D.big_point>6) || (E.big_point>6) || (F.big_point>7) || (G.big_point>7)) ||
									((D.small_point>6) || (E.small_point>6) || (F.small_point>7) || (G.small_point>7)) == 1)
								{
									//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
									if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
									{
										//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
										if (best_state == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else if (best_state == 0)
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												if (C.v_rand_6 || C.v_rand_7 == 1)
													B[b] = B[b - 1];
												else
													B[b] = B[b - 1] + 1;
												A[b] = best_state;
											}
										}
										else
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												A[b] = best_state;
												B[b] = B[b - 1] + 1;
											}
										}
									}
									else
									{
										if (D.big_point > E.big_point)
										{
											if (D.state == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												if (C.v_rand_4 || C.v_rand_5 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													A[b] = D.state;
													B[b] = B[b - 1] + 1;
												}
											}
										}
										else
										{
											if (E.state == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												if (C.v_rand_4 || C.v_rand_5 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													A[b] = E.state;
													B[b] = B[b - 1] + 1;
												}
											}
										}
									}
								}
								else
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									c = b - 1;
								}
							}
							else
							{
								if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3&&C.v_rand_4&&C.v_rand_5&&C.v_rand_6 ||
									((D.big_point > 7) || (E.big_point > 7) || (F.big_point > 8) || (G.big_point > 8)) ||
									((D.small_point > 7) || (E.small_point > 7) || (F.small_point > 8) || (G.small_point > 8)) == 1)
								{
									//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
									if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
									{
										//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
										if (best_state == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else if (best_state == 0)
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
													B[b] = B[b - 1];
												else
													B[b] = B[b - 1] + 1;
												A[b] = best_state;
											}
										}
										else
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												A[b] = best_state;
												B[b] = B[b - 1] + 1;
											}
										}
									}
									else
									{
										if (D.big_point > E.big_point)
										{
											if (D.state == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													A[b] = D.state;
													B[b] = B[b - 1] + 1;
												}
											}
										}
										else
										{
											if (E.state == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													A[b] = E.state;
													B[b] = B[b - 1] + 1;
												}
											}
										}
									}
								}
								else
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									c = b - 1;
								}
							}
						}
						else if (A[b - 1] == 2)
						{
							//�Ҽ{�W�@��ۥX���u��
							if (B[b - 1] == 1)
							{
								//�@�b�����v�۷s�����
								if (C.v_rand_1 || C.v_rand_15 == 1)
								{
									//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
									if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
									{
										//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
										if (best_state == 2)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else if ((best_state == 0) || (best_state == 1) == 1)
										{
											if (C.v_rand_2 == 1)
												B[b] = B[b - 1];
											else
												B[b] = B[b - 1] + 1;
											A[b] = best_state;
										}
										else
										{
											A[b] = best_state;
											B[b] = B[b - 1] + 1;
										}
									}
									else
									{
										if (D.big_point > E.big_point)
										{
											if (D.state == 2)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else if (D.state == 1)
											{
												if (C.v_rand_2 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													if (C.v_rand_3 == 1)
														B[b] = B[b - 1];
													else
														B[b] = B[b - 1] + 1;
													A[b] = D.state;
												}
											}
											else
											{
												if (C.v_rand_2 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													A[b] = D.state;
													B[b] = B[b - 1] + 1;
												}
											}
										}
										else
										{
											if (E.state == 2)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else if (E.state == 1)
											{
												if (C.v_rand_2 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													if (C.v_rand_3 == 1)
														B[b] = B[b - 1];
													else
														B[b] = B[b - 1] + 1;
													A[b] = E.state;
												}
											}
											else
											{
												if (C.v_rand_2 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													A[b] = E.state;
													B[b] = B[b - 1] + 1;
												}
											}
										}
									}
								}
								else
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									c = b - 1;
								}
							}
							else if (B[b - 1] < 3)
							{
								if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3 ||
									((D.big_point>6) || (E.big_point>6) || (F.big_point>7) || (G.big_point>7)) ||
									((D.small_point>6) || (E.small_point>6) || (F.small_point>7) || (G.small_point>7)) == 1)
								{
									//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
									if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
									{
										//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
										if (best_state == 2)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else if ((best_state == 0) || (best_state == 1) == 1)
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												if (C.v_rand_6 || C.v_rand_7 == 1)
													B[b] = B[b - 1];
												else
													B[b] = B[b - 1] + 1;
												A[b] = best_state;
											}
										}
										else
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												A[b] = best_state;
												B[b] = B[b - 1] + 1;
											}
										}
									}
									else
									{
										if (D.big_point > E.big_point)
										{
											if (D.state == 2)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else if (D.state == 1)
											{
												if (C.v_rand_4 || C.v_rand_5 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													if (C.v_rand_6 || C.v_rand_7 == 1)
														B[b] = B[b - 1];
													else
														B[b] = B[b - 1] + 1;
													A[b] = D.state;
												}
											}
											else
											{
												if (C.v_rand_4 || C.v_rand_5 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													A[b] = D.state;
													B[b] = B[b - 1] + 1;
												}
											}
										}
										else
										{
											if (E.state == 2)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else if (E.state == 1)
											{
												if (C.v_rand_4 || C.v_rand_5 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													if (C.v_rand_6 || C.v_rand_7 == 1)
														B[b] = B[b - 1];
													else
														B[b] = B[b - 1] + 1;
													A[b] = E.state;
												}
											}
											else
											{
												if (C.v_rand_4 || C.v_rand_5 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													A[b] = E.state;
													B[b] = B[b - 1] + 1;
												}
											}
										}
									}
								}
								else
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									c = b - 1;
								}
							}
							else
							{
								if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3&&C.v_rand_4&&C.v_rand_5&&C.v_rand_6 ||
									((D.big_point > 7) || (E.big_point > 7) || (F.big_point > 8) || (G.big_point > 8)) ||
									((D.small_point > 7) || (E.small_point > 7) || (F.small_point > 8) || (G.small_point > 8)) == 1)
								{
									//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
									if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
									{
										//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
										if (best_state == 1)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else if ((best_state == 0) || (best_state == 1) == 1)
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
													B[b] = B[b - 1];
												else
													B[b] = B[b - 1] + 1;
												A[b] = best_state;
											}
										}
										else
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												A[b] = best_state;
												B[b] = B[b - 1] + 1;
											}
										}
									}
									else
									{
										if (D.big_point > E.big_point)
										{
											if (D.state == 2)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else if (D.state == 1)
											{
												if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
														B[b] = B[b - 1];
													else
														B[b] = B[b - 1] + 1;
													A[b] = D.state;
												}
											}
											else
											{
												if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													A[b] = D.state;
													B[b] = B[b - 1] + 1;
												}
											}
										}
										else
										{
											if (E.state == 2)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else if (E.state == 1)
											{
												if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
														B[b] = B[b - 1];
													else
														B[b] = B[b - 1] + 1;
													A[b] = E.state;
												}
											}
											else
											{
												if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													A[b] = E.state;
													B[b] = B[b - 1] + 1;
												}
											}
										}
									}
								}
								else
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									c = b - 1;
								}
							}
						}
						else if (A[b - 1] == 3)
						{
							//�Ҽ{�W�@��ۥX���u��
							if (B[b - 1] == 1)
							{
								//�@�b�����v�۷s�����
								if (C.v_rand_1 || C.v_rand_15 == 1)
								{
									//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
									if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
									{
										//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
										if (best_state == 3)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else if ((best_state == 0) || (best_state == 1) || (best_state == 2) == 1)
										{
											if (C.v_rand_2 == 1)
												B[b] = B[b - 1];
											else
												B[b] = B[b - 1] + 1;
											A[b] = best_state;
										}
										else
										{
											A[b] = best_state;
											B[b] = B[b - 1] + 1;
										}
									}
									else
									{
										if (D.big_point > E.big_point)
										{
											if (D.state == 3)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else if ((D.state == 1) || (D.state == 2) == 1)
											{
												if (C.v_rand_2 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													if (C.v_rand_3 == 1)
														B[b] = B[b - 1];
													else
														B[b] = B[b - 1] + 1;
													A[b] = D.state;
												}
											}
											else
											{
												if (C.v_rand_2 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													A[b] = D.state;
													B[b] = B[b - 1] + 1;
												}
											}
										}
										else
										{
											if (E.state == 3)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else if ((E.state == 1) || (E.state == 2) == 1)
											{
												if (C.v_rand_2 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													if (C.v_rand_3 == 1)
														B[b] = B[b - 1];
													else
														B[b] = B[b - 1] + 1;
													A[b] = E.state;
												}
											}
											else
											{
												if (C.v_rand_2 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													A[b] = E.state;
													B[b] = B[b - 1] + 1;
												}
											}
										}
									}
								}
								else
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									c = b - 1;
								}
							}
							else if (B[b - 1] < 3)
							{
								if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3 ||
									((D.big_point>6) || (E.big_point>6) || (F.big_point>7) || (G.big_point>7)) ||
									((D.small_point>6) || (E.small_point>6) || (F.small_point>7) || (G.small_point>7)) == 1)
								{
									//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
									if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
									{
										//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
										if (best_state == 3)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else if ((best_state == 0) || (best_state == 1) || (best_state == 2) == 1)
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												if (C.v_rand_6 || C.v_rand_7 == 1)
													B[b] = B[b - 1];
												else
													B[b] = B[b - 1] + 1;
												A[b] = best_state;
											}
										}
										else
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												A[b] = best_state;
												B[b] = B[b - 1] + 1;
											}
										}
									}
									else
									{
										if (D.big_point > E.big_point)
										{
											if (D.state == 3)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else if ((D.state == 1) || (D.state == 2) == 1)
											{
												if (C.v_rand_4 || C.v_rand_5 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													if (C.v_rand_6 || C.v_rand_7 == 1)
														B[b] = B[b - 1];
													else
														B[b] = B[b - 1] + 1;
													A[b] = D.state;
												}
											}
											else
											{
												if (C.v_rand_4 || C.v_rand_5 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													A[b] = D.state;
													B[b] = B[b - 1] + 1;
												}
											}
										}
										else
										{
											if (E.state == 3)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else if ((E.state == 1) || (E.state == 2) == 1)
											{
												if (C.v_rand_4 || C.v_rand_5 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													if (C.v_rand_6 || C.v_rand_7 == 1)
														B[b] = B[b - 1];
													else
														B[b] = B[b - 1] + 1;
													A[b] = E.state;
												}
											}
											else
											{
												if (C.v_rand_4 || C.v_rand_5 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													A[b] = E.state;
													B[b] = B[b - 1] + 1;
												}
											}
										}
									}
								}
								else
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									c = b - 1;
								}
							}
							else
							{
								if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3&&C.v_rand_4&&C.v_rand_5&&C.v_rand_6 ||
									((D.big_point > 7) || (E.big_point > 7) || (F.big_point > 8) || (G.big_point > 8)) ||
									((D.small_point > 7) || (E.small_point > 7) || (F.small_point > 8) || (G.small_point > 8)) == 1)
								{
									//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
									if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
									{
										//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
										if (best_state == 3)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else if ((best_state == 0) || (best_state == 1) || (best_state == 2) == 1)
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
													B[b] = B[b - 1];
												else
													B[b] = B[b - 1] + 1;
												A[b] = best_state;
											}
										}
										else
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												A[b] = best_state;
												B[b] = B[b - 1] + 1;
											}
										}
									}
									else
									{
										if (D.big_point > E.big_point)
										{
											if (D.state == 3)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else if ((D.state == 1) || (D.state == 2) == 1)
											{
												if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
														B[b] = B[b - 1];
													else
														B[b] = B[b - 1] + 1;
													A[b] = D.state;
												}
											}
											else
											{
												if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													A[b] = D.state;
													B[b] = B[b - 1] + 1;
												}
											}
										}
										else
										{
											if (E.state == 3)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else if ((E.state == 1) || (E.state == 2) == 1)
											{
												if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
														B[b] = B[b - 1];
													else
														B[b] = B[b - 1] + 1;
													A[b] = E.state;
												}
											}
											else
											{
												if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													A[b] = E.state;
													B[b] = B[b - 1] + 1;
												}
											}
										}
									}
								}
								else
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									c = b - 1;
								}
							}
						}
						else if (A[b - 1] == 4)
						{
							//�Ҽ{�W�@��ۥX���u��
							if (B[b - 1] == 1)
							{
								//�@�b�����v�۷s�����
								if (C.v_rand_1 || C.v_rand_15 == 1)
								{
									//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
									if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
									{
										//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
										if (best_state == 4)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else if ((best_state == 0) || (best_state == 1) || (best_state == 2) || (best_state == 3) == 1)
										{
											if (C.v_rand_2 == 1)
												B[b] = B[b - 1];
											else
												B[b] = B[b - 1] + 1;
											A[b] = best_state;
										}
										else
										{
											A[b] = best_state;
											B[b] = B[b - 1] + 1;
										}
									}
									else
									{
										if (D.big_point > E.big_point)
										{
											if (D.state == 4)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											//�W�@�H�۪���⬰����,�T�b���ɳ۶®�,����,����ҥi��ܽu��O�_�n+1
											else
											{
												if (C.v_rand_2 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													if (C.v_rand_3 == 1)
														B[b] = B[b - 1];
													else
														B[b] = B[b - 1] + 1;
													A[b] = D.state;
												}
											}
										}
										else
										{
											if (E.state == 4)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												if (C.v_rand_2 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													if (C.v_rand_3 == 1)
														B[b] = B[b - 1];
													else
														B[b] = B[b - 1] + 1;
													A[b] = E.state;
												}
											}
										}
									}
								}
								else
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									c = b - 1;
								}
							}
							else if (B[b - 1] < 3)
							{
								if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3 ||
									((D.big_point>6) || (E.big_point>6) || (F.big_point>7) || (G.big_point>7)) ||
									((D.small_point>6) || (E.small_point>6) || (F.small_point>7) || (G.small_point>7)) == 1)
								{
									//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
									if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
									{
										//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
										if (best_state == 4)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else if ((best_state == 0) || (best_state == 1) || (best_state == 2) || (best_state == 3) == 1)
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												if (C.v_rand_6 || C.v_rand_7 == 1)
													B[b] = B[b - 1];
												else
													B[b] = B[b - 1] + 1;
												A[b] = best_state;
											}
										}
										else
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												A[b] = best_state;
												B[b] = B[b - 1] + 1;
											}
										}
									}
									else
									{
										if (D.big_point > E.big_point)
										{
											if (D.state == 4)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											//�W�@�H�۪���⬰����,�T�b���ɳ۶®�,����,����ҥi��ܽu��O�_�n+1
											else
											{
												if (C.v_rand_4 || C.v_rand_5 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													if (C.v_rand_6 || C.v_rand_7 == 1)
														B[b] = B[b - 1];
													else
														B[b] = B[b - 1] + 1;
													A[b] = D.state;
												}
											}
										}
										else
										{
											if (E.state == 4)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												if (C.v_rand_4 || C.v_rand_5 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													if (C.v_rand_6 || C.v_rand_7 == 1)
														B[b] = B[b - 1];
													else
														B[b] = B[b - 1] + 1;
													A[b] = E.state;
												}
											}
										}
									}
								}
								else
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									c = b - 1;
								}
							}
							else
							{
								if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3&&C.v_rand_4&&C.v_rand_5&&C.v_rand_6 ||
									((D.big_point > 7) || (E.big_point > 7) || (F.big_point > 8) || (G.big_point > 8)) ||
									((D.small_point > 7) || (E.small_point > 7) || (F.small_point > 8) || (G.small_point > 8)) == 1)
								{
									//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
									if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
									{
										//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
										if (best_state == 4)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else if ((best_state == 0) || (best_state == 1) || (best_state == 2) || (best_state == 3) == 1)
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
													B[b] = B[b - 1];
												else
													B[b] = B[b - 1] + 1;
												A[b] = best_state;
											}
										}
										else
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												A[b] = best_state;
												B[b] = B[b - 1] + 1;
											}
										}
									}
									else
									{
										if (D.big_point > E.big_point)
										{
											if (D.state == 4)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											//�W�@�H�۪���⬰����,�T�b���ɳ۶®�,����,����ҥi��ܽu��O�_�n+1
											else
											{
												if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
														B[b] = B[b - 1];
													else
														B[b] = B[b - 1] + 1;
													A[b] = D.state;
												}
											}
										}
										else
										{
											if (E.state == 4)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
												{
													A[b] = 6;
													B[b] = 0;
													a++;
													c = b - 1;
												}
												else
												{
													if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
														B[b] = B[b - 1];
													else
														B[b] = B[b - 1] + 1;
													A[b] = E.state;
												}
											}
										}
									}
								}
								else
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									c = b - 1;
								}
							}
						}
						//�Y�W�@�ӤH��small
						else
						{
							//�Ҽ{�W�@��ۥX���u��
							if (B[b - 1] == 1)
							{
								//�@�b�����v�۷s�����
								if (C.v_rand_1 || C.v_rand_15 == 1)
								{
									//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
									if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
									{
										//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
										if (best_state == 5)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else
										{
											if (C.v_rand_2 == 1)
												B[b] = B[b - 1];
											else
												B[b] = B[b - 1] + 1;
											A[b] = best_state;
										}
									}
									else
									{
										if (D.big_point > E.big_point)
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												if (C.v_rand_3 == 1)
													B[b] = B[b - 1];
												else
													B[b] = B[b - 1] + 1;
												A[b] = D.state;
											}
										}
										else
										{
											if (C.v_rand_2 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												if (C.v_rand_3 == 1)
													B[b] = B[b - 1];
												else
													B[b] = B[b - 1] + 1;
												A[b] = E.state;
											}
										}
									}
								}
								else
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									c = b - 1;
								}
							}
							else if (B[b - 1] < 3)
							{
								if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3 ||
									((D.big_point>6) || (E.big_point>6) || (F.big_point>7) || (G.big_point>7)) ||
									((D.small_point>6) || (E.small_point>6) || (F.small_point>7) || (G.small_point>7)) == 1)
								{
									//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
									if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
									{
										//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
										if (best_state == 5)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
												B[b] = B[b - 1];
											else
												B[b] = B[b - 1] + 1;
											A[b] = best_state;
										}
									}
									else
									{
										if (D.big_point > E.big_point)
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												if (C.v_rand_6 || C.v_rand_7 == 1)
													B[b] = B[b - 1];
												else
													B[b] = B[b - 1] + 1;
												A[b] = D.state;
											}
										}
										else
										{
											if (C.v_rand_4 || C.v_rand_5 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												if (C.v_rand_6 || C.v_rand_7 == 1)
													B[b] = B[b - 1];
												else
													B[b] = B[b - 1] + 1;
												A[b] = E.state;
											}
										}
									}
								}
								else
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									c = b - 1;
								}
							}
							else
							{
								if (C.v_rand_1&&C.v_rand_2&&C.v_rand_3&&C.v_rand_4&&C.v_rand_5&&C.v_rand_6 ||
									((D.big_point > 7) || (E.big_point > 7) || (F.big_point > 8) || (G.big_point > 8)) ||
									((D.small_point > 7) || (E.small_point > 7) || (F.small_point > 8) || (G.small_point > 8)) == 1)
								{
									//�Ҽ{�ۤv�P����T�O�_�P�̨θѭ��X,�̫��ӱ��󬰵L����small
									if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
									{
										//�M�w�X�̨θѮ�,�P�_�W�@�ӤH�۪���⬰��,�M�w�O�_accept�γ۷s�����
										if (best_state == 5)
										{
											A[b] = 6;
											B[b] = 0;
											a++;
											c = b - 1;
										}
										else
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
												B[b] = B[b - 1];
											else
												B[b] = B[b - 1] + 1;
											A[b] = best_state;
										}
									}
									else
									{
										if (D.big_point > E.big_point)
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
													B[b] = B[b - 1];
												else
													B[b] = B[b - 1] + 1;
												A[b] = D.state;
											}
										}
										else
										{
											if (C.v_rand_7 || C.v_rand_8 || C.v_rand_9 == 1)
											{
												A[b] = 6;
												B[b] = 0;
												a++;
												c = b - 1;
											}
											else
											{
												if (C.v_rand_10 || C.v_rand_11 || C.v_rand_12 == 1)
													B[b] = B[b - 1];
												else
													B[b] = B[b - 1] + 1;
												A[b] = E.state;
											}
										}
									}
								}
								else
								{
									A[b] = 6;
									B[b] = 0;
									a++;
									c = b - 1;
								}
							}
						}
					}
				}
			}
		}
	}
	else
	{
		if (a == 3)
		{
			this->auction_color = A[c];
			//this->auction_number = B[c];
			if (((d == 0) || (e == 0)) == 1)
			{
				d = c;
				e = c;
			}
		}
		else if (a == 2)
		{
			//�p�G�S��accept��,counter_stop=0
		}
		else if (a == 1)
		{
			//�p�G�S��accept��,counter_stop=0
		}
		else
		{
			//�p�G�S��accept��,counter_stop=0
			//�b�o��accept��,counter_stop=counter-1
			//�Ĥ@�ӳ۪�⪺�H
			if (b == 0)
			{
				bool a1, b1, c1, d1, e1;
				int sum_small, sum_big;
				a1 = ((D.number <= 4) && (D.number >= 2));
				b1 = ((E.number <= 4) && (E.number >= 2));
				c1 = ((F.number <= 4) && (F.number >= 2));
				d1 = ((G.number <= 4) && (G.number >= 2));
				sum_small = D.small_point + E.small_point + F.small_point + G.small_point;
				sum_big = D.big_point + E.big_point + F.big_point + G.big_point;
				e1 = (sum_small > sum_big);
				if ((a1&&b1&&c1&&d1&&C.v_rand_1&&C.v_rand_2) == 1)
				{
					//No King
					A[b] = 0;
					B[b] = 1;
					b++;
				}
				else
				{
					if ((e1&&C.v_rand_2) == 1)
					{
						//small
						A[b] = 5;
						B[b] = 1;
						b++;
					}
					else
					{
						//4���䤤���@

					}
				}
			}
			else
			{

			}
			c = b - 1;
		}
	}
	int temp = 0;
	if (a != 0)
		temp = 1;
	return temp;
}
int Game::Process::AI::select_card(
	int a, int b, int c, int d, int e, int f, int g, int h, int h1, int A[], int B[],
	Game &C,
	Game::Process::AI::color &D,
	Game::Process::AI::color &E,
	Game::Process::AI::color &F,
	Game::Process::AI::color &G)
{
	/*
	a=i,
	b=j,
	c=sequence,
	d=player1.bid,
	e=player2.bid,
	f=player3.bid,
	g=player4.bid,
	h=final_number,
	h1=selector,
	A[]=play_color[],
	B[]=play_number[],
	*/
	int mark = 0;
	if (this->smart == 0)
	{
		//�L��
		if (this->auction_color == 0)
		{
			int no_trump_color[13], no_trump_number[13];
			/*
			�b���q�{���ϥ�no_trump�}�C�N�������vCard�}�C�|�y���H�U���~:
			�b�q���C���X�P��,�N�A�@���a��vCard(��P)�}�C�i�歫��
			�B���ɷ|�ϱono_trump�}�C�̪����e�|��"���㪺"13�i�P
			�H�W�K�O�C���L�{���q�x�|���_�X�P����]

			��h�W�u�n��ư����Q�襤���P�N��
			�i�H�b�X���P��,�[�Wif�P�_�ӱi�P�bvCard�}�C������m�����
			no_trump�}�C���ƧǤ]�ݭn���s�Ҷq
			*/
			for (int i = 0; i < 13; i++)
			{
				no_trump_color[i] = this->vCard_color[i + 1];
				no_trump_number[i] = this->vCard_number[i + 1];
			}
			for (int i = 1; i < 13; i++)
			{
				int temp1, temp2, temp3;
				temp3 = i;
				do
				{
					if ((no_trump_number[i] > no_trump_number[i - 1]) || (no_trump_number[i] == 1) == 1)
					{
						temp1 = no_trump_number[i];
						temp2 = no_trump_color[i];
						no_trump_number[i] = no_trump_number[i - 1];
						no_trump_color[i] = no_trump_color[i - 1];
						no_trump_number[i - 1] = temp1;
						no_trump_color[i - 1] = temp2;
						if (i > 1)
							i--;
						else
							break;
					}
					else
						break;
				} while ((no_trump_number[i] > no_trump_number[i + 1]) || (no_trump_number[i] == 1) == 1);
				i = temp3;
			}
			//���Ĥ@�ӥX�P��
			if (b == 0)
			{
				//�@�ߥX�̤j�P
				for (int i = 0; i < 13; i++)
				{
					if (no_trump_number[i] != 0)
					{
						A[b + 4 * a] = no_trump_color[i];
						this->sCard_color[a] = no_trump_color[i];
						B[b + 4 * a] = no_trump_number[i];
						this->sCard_number[a] = no_trump_number[i];
						for (int j = 0; j < 13; j++)
						{
							if ((no_trump_color[i] == this->vCard_color[j + 1]) && (no_trump_number[i] == this->vCard_number[j + 1]) == 1)
							{
								this->vCard_color[j + 1] = 0;
								this->vCard_number[j + 1] = 0;
							}
						}
						break;
					}
				}
				mark = 1;
			}
			else
			{
				int counter = 0, counter2 = 0;
				//���P�_��W�O�_���Mdeclarer�ҥX�����ۦP���P
				for (int i = 0; i < 13; i++)
				{
					if (no_trump_color[i] == A[4 * a])
					{
						counter++;
						if ((no_trump_number[i] > B[4 * a]) && (B[4 * a] != 1) == 1)
							counter2++;
					}
				}
				if (counter != 0)
				{
					if (a > 2)
					{
						int counter3 = 0;
						for (int i = 0; i > -8; i--)
						{
							if (A[b - 1 + 4 * a] == A[4 * a])
							{
								if ((B[b - 1 + 4 * a] > B[4 * a]) && (B[4 * a] != 1) == 1)
									counter3++;
							}
						}
						//�p�G�⤤���P�����Ldeclarer�ҥX���P
						if (counter2 != 0)
						{
							//�p�G�w���H�X�L�����Ldeclarer�ҥX���P,true�����ΤU�i�H�Ҽ{�n���X�P
							if (counter3 != 0)
							{
								if (counter > 1)
								{
									if (a > 7)
									{
										if (b > 1)
										{
											if (A[b + 4 * a - 2] != A[4 * a])
											{
												//���ɶ��ͬ��X�P�ĤG����B�w�S���Ӫ�⪺�P
												if (C.v_rand_1 || C.v_rand_2 == 1)
												{
													for (int i = 0; i < 13; i++)
													{
														if (no_trump_color[i] == A[4 * a])
														{
															A[b + 4 * a] = no_trump_color[i];
															this->sCard_color[a] = no_trump_color[i];
															B[b + 4 * a] = no_trump_number[i];
															this->sCard_number[a] = no_trump_number[i];
															for (int i = 0; i < 13; i++)
															{
																for (int j = 0; j < 13; j++)
																{
																	if ((no_trump_color[j] == this->vCard_color[i + 1]) && (no_trump_number[j] == this->vCard_number[i + 1]) == 1)
																	{
																		this->vCard_color[i + 1] = 0;
																		this->vCard_number[i + 1] = 0;
																	}
																}
															}
															break;
														}
													}
												}
												else
												{
													int counter4 = 0;
													for (int i = 0; i < 13; i++)
													{
														if (no_trump_color[i] == A[4 * a])
														{
															counter4++;
															if (counter4 == 2)
															{
																A[b + 4 * a] = no_trump_color[i];
																this->sCard_color[a] = no_trump_color[i];
																B[b + 4 * a] = no_trump_number[i];
																this->sCard_number[a] = no_trump_number[i];
																for (int i = 0; i < 13; i++)
																{
																	for (int j = 0; j < 13; j++)
																	{
																		if ((no_trump_color[j] == this->vCard_color[i + 1]) && (no_trump_number[j] == this->vCard_number[i + 1]) == 1)
																		{
																			this->vCard_color[i + 1] = 0;
																			this->vCard_number[i + 1] = 0;
																		}
																	}
																}
																break;
															}
														}
													}
												}
											}
											else
											{
												/*
												���ɱ��p�����
												1.���ͬ����a
												2.���ͬ��X�P�ĤG����B���Ӫ�⪺�P
												if(b==2)
												else
												*/
												if (b == 2)
												{
													//�p�G����(���a)���P�Q���L
													if ((A[b + 4 * a - 1] == A[4 * a]) && ((B[b + 4 * a - 1] > B[4 * a]) || (B[b + 4 * a - 1] == 1)) == 1)
													{
														if (B[b + 4 * a - 1] == 1)
														{
															for (int i = 12; i >= 0; i--)
															{
																if (no_trump_color[i] == A[4 * a])
																{
																	A[b + 4 * a] = no_trump_color[i];
																	this->sCard_color[a] = no_trump_color[i];
																	B[b + 4 * a] = no_trump_number[i];
																	this->sCard_number[a] = no_trump_number[i];
																	for (int i = 0; i < 13; i++)
																	{
																		for (int j = 0; j < 13; j++)
																		{
																			if ((no_trump_color[j] == this->vCard_color[i + 1]) && (no_trump_number[j] == this->vCard_number[i + 1]) == 1)
																			{
																				this->vCard_color[i + 1] = 0;
																				this->vCard_number[i + 1] = 0;
																			}
																		}
																	}
																	break;
																}
															}
														}
														else
														{
															for (int i = 0; i < 13; i++)
															{
																if (((no_trump_color[i] == A[4 * a]) && ((no_trump_number[i] == 1) || (no_trump_number[i] > B[b + 4 * a - 1]) && (B[b + 4 * a - 1] != 1))) == 1)
																{
																	A[b + 4 * a] = no_trump_color[i];
																	this->sCard_color[a] = no_trump_color[i];
																	B[b + 4 * a] = no_trump_number[i];
																	this->sCard_number[a] = no_trump_number[i];
																	for (int i = 0; i < 13; i++)
																	{
																		for (int j = 0; j < 13; j++)
																		{
																			if ((no_trump_color[j] == this->vCard_color[i + 1]) && (no_trump_number[j] == this->vCard_number[i + 1]) == 1)
																			{
																				this->vCard_color[i + 1] = 0;
																				this->vCard_number[i + 1] = 0;
																			}
																		}
																	}
																	break;
																}
															}
															if (B[b + 4 * a] == 0)
															{
																for (int i = 12; i >= 0; i--)
																{
																	if (no_trump_color[i] == A[4 * a])
																	{
																		A[b + 4 * a] = no_trump_color[i];
																		this->sCard_color[a] = no_trump_color[i];
																		B[b + 4 * a] = no_trump_number[i];
																		this->sCard_number[a] = no_trump_number[i];
																		for (int i = 0; i < 13; i++)
																		{
																			for (int j = 0; j < 13; j++)
																			{
																				if ((no_trump_color[j] == this->vCard_color[i + 1]) && (no_trump_number[j] == this->vCard_number[i + 1]) == 1)
																				{
																					this->vCard_color[i + 1] = 0;
																					this->vCard_number[i + 1] = 0;
																				}
																			}
																		}
																		break;
																	}
																}
															}
														}
													}
													else
													{
														if ((C.v_rand_1 || C.v_rand_2 || C.v_rand_3) == 1)
														{
															for (int i = 12; i >= 0; i--)
															{
																if (no_trump_color[i] == A[4 * a])
																{
																	A[b + 4 * a] = no_trump_color[i];
																	this->sCard_color[a] = no_trump_color[i];
																	B[b + 4 * a] = no_trump_number[i];
																	this->sCard_number[a] = no_trump_number[i];
																	for (int i = 0; i < 13; i++)
																	{
																		for (int j = 0; j < 13; j++)
																		{
																			if ((no_trump_color[j] == this->vCard_color[i + 1]) && (no_trump_number[j] == this->vCard_number[i + 1]) == 1)
																			{
																				this->vCard_color[i + 1] = 0;
																				this->vCard_number[i + 1] = 0;
																			}
																		}
																	}
																	break;
																}
															}
														}
														else
														{
															for (int i = 0; i < 13; i++)
															{
																if (((no_trump_color[i] == A[4 * a]) && ((no_trump_number[i] == 1) || (no_trump_number[i] > B[b + 4 * a - 1]) && (B[b + 4 * a - 1] != 1))) == 1)
																{
																	A[b + 4 * a] = no_trump_color[i];
																	this->sCard_color[a] = no_trump_color[i];
																	B[b + 4 * a] = no_trump_number[i];
																	this->sCard_number[a] = no_trump_number[i];
																	for (int i = 0; i < 13; i++)
																	{
																		for (int j = 0; j < 13; j++)
																		{
																			if ((no_trump_color[j] == this->vCard_color[i + 1]) && (no_trump_number[j] == this->vCard_number[i + 1]) == 1)
																			{
																				this->vCard_color[i + 1] = 0;
																				this->vCard_number[i + 1] = 0;
																			}
																		}
																	}
																	break;
																}
															}
															if (B[b + 4 * a] == 0)
															{
																for (int i = 12; i >= 0; i--)
																{
																	if (no_trump_color[i] == A[4 * a])
																	{
																		A[b + 4 * a] = no_trump_color[i];
																		this->sCard_color[a] = no_trump_color[i];
																		B[b + 4 * a] = no_trump_number[i];
																		this->sCard_number[a] = no_trump_number[i];
																		for (int i = 0; i < 13; i++)
																		{
																			for (int j = 0; j < 13; j++)
																			{
																				if ((no_trump_color[j] == this->vCard_color[i + 1]) && (no_trump_number[j] == this->vCard_number[i + 1]) == 1)
																				{
																					this->vCard_color[i + 1] = 0;
																					this->vCard_number[i + 1] = 0;
																				}
																			}
																		}
																		break;
																	}
																}
															}
														}
													}
												}
												else
												{
													for (int i = 12; i >= 0; i--)
													{
														if (no_trump_color[i] == A[4 * a])
														{
															if (A[b + 4 * a - 1] != A[4 * a])
															{
																if ((no_trump_number[i] > B[4 * a]) && (B[4 * a] != 1) == 1)
																{
																	A[b + 4 * a] = no_trump_color[i];
																	this->sCard_color[a] = no_trump_color[i];
																	B[b + 4 * a] = no_trump_number[i];
																	this->sCard_number[a] = no_trump_number[i];
																	for (int i = 0; i < 13; i++)
																	{
																		for (int j = 0; j < 13; j++)
																		{
																			if ((no_trump_color[j] == this->vCard_color[i + 1]) && (no_trump_number[j] == this->vCard_number[i + 1]) == 1)
																			{
																				this->vCard_color[i + 1] = 0;
																				this->vCard_number[i + 1] = 0;
																			}
																		}
																	}
																	break;
																}
															}
															else
															{
																if ((((B[b + 4 * a - 2] > B[b + 4 * a - 1]) && (B[b + 4 * a - 2] > B[b + 4 * a])) || (B[b + 4 * a - 2] == 1)) == 1)
																{
																	A[b + 4 * a] = no_trump_color[i];
																	this->sCard_color[a] = no_trump_color[i];
																	B[b + 4 * a] = no_trump_number[i];
																	this->sCard_number[a] = no_trump_number[i];
																	for (int i = 0; i < 13; i++)
																	{
																		for (int j = 0; j < 13; j++)
																		{
																			if ((no_trump_color[j] == this->vCard_color[i + 1]) && (no_trump_number[j] == this->vCard_number[i + 1]) == 1)
																			{
																				this->vCard_color[i + 1] = 0;
																				this->vCard_number[i + 1] = 0;
																			}
																		}
																	}
																	break;
																}
																else
																{
																	if ((no_trump_number[i] > B[4 * a]) && (B[4 * a] != 1) == 1)
																	{
																		if ((no_trump_number[i] > B[b + 4 * a - 1]) && (B[b + 4 * a - 1] != 1) == 1)
																		{
																			A[b + 4 * a] = no_trump_color[i];
																			this->sCard_color[a] = no_trump_color[i];
																			B[b + 4 * a] = no_trump_number[i];
																			this->sCard_number[a] = no_trump_number[i];
																			for (int i = 0; i < 13; i++)
																			{
																				for (int j = 0; j < 13; j++)
																				{
																					if ((no_trump_color[j] == this->vCard_color[i + 1]) && (no_trump_number[j] == this->vCard_number[i + 1]) == 1)
																					{
																						this->vCard_color[i + 1] = 0;
																						this->vCard_number[i + 1] = 0;
																					}
																				}
																			}
																			break;
																		}
																	}
																}
															}
														}
													}
													if (B[b + 4 * a] == 0)
													{
														for (int i = 12; i >= 0; i--)
														{
															if (no_trump_color[i] == A[4 * a])
															{
																A[b + 4 * a] = no_trump_color[i];
																this->sCard_color[a] = no_trump_color[i];
																B[b + 4 * a] = no_trump_number[i];
																this->sCard_number[a] = no_trump_number[i];
																for (int i = 0; i < 13; i++)
																{
																	for (int j = 0; j < 13; j++)
																	{
																		if ((no_trump_color[j] == this->vCard_color[i + 1]) && (no_trump_number[j] == this->vCard_number[i + 1]) == 1)
																		{
																			this->vCard_color[i + 1] = 0;
																			this->vCard_number[i + 1] = 0;
																		}
																	}
																}
																break;
															}
														}
													}
												}
											}
										}
										else
										{
											//7��5���v�X�P���̤j�P,�Φ��j�P
											if ((counter2 != 1) && (C.v_rand_1 || C.v_rand_2) == 1)
											{
												for (int i = 0; i < 13; i++)
												{
													if (no_trump_color[i] == A[4 * a])
													{
														A[b + 4 * a] = no_trump_color[i];
														this->sCard_color[a] = no_trump_color[i];
														B[b + 4 * a] = no_trump_number[i];
														this->sCard_number[a] = no_trump_number[i];
														for (int i = 0; i < 13; i++)
														{
															for (int j = 0; j < 13; j++)
															{
																if ((no_trump_color[j] == this->vCard_color[i + 1]) && (no_trump_number[j] == this->vCard_number[i + 1]) == 1)
																{
																	this->vCard_color[i + 1] = 0;
																	this->vCard_number[i + 1] = 0;
																}
															}
														}
														break;
													}
												}
											}
											else
											{
												int counter4 = 0;
												for (int i = 0; i < 13; i++)
												{
													if (no_trump_color[i] == A[4 * a])
													{
														counter4++;
														if (counter4 == 2)
														{
															A[b + 4 * a] = no_trump_color[i];
															this->sCard_color[a] = no_trump_color[i];
															B[b + 4 * a] = no_trump_number[i];
															this->sCard_number[a] = no_trump_number[i];
															for (int i = 0; i < 13; i++)
															{
																for (int j = 0; j < 13; j++)
																{
																	if ((no_trump_color[j] == this->vCard_color[i + 1]) && (no_trump_number[j] == this->vCard_number[i + 1]) == 1)
																	{
																		this->vCard_color[i + 1] = 0;
																		this->vCard_number[i + 1] = 0;
																	}
																}
															}
															break;
														}
													}
												}
											}
										}
									}
									else
									{
										if (b > 1)
										{
											if (A[b + 4 * a - 2] != A[4 * a])
											{
												//���ɶ��ͬ��X�P�ĤG����B�w�S���Ӫ�⪺�P
												if (C.v_rand_1&&C.v_rand_2 == 1)
												{
													for (int i = 0; i < 13; i++)
													{
														if (no_trump_color[i] == A[4 * a])
														{
															A[b + 4 * a] = no_trump_color[i];
															this->sCard_color[a] = no_trump_color[i];
															B[b + 4 * a] = no_trump_number[i];
															this->sCard_number[a] = no_trump_number[i];
															for (int i = 0; i < 13; i++)
															{
																for (int j = 0; j < 13; j++)
																{
																	if ((no_trump_color[j] == this->vCard_color[i + 1]) && (no_trump_number[j] == this->vCard_number[i + 1]) == 1)
																	{
																		this->vCard_color[i + 1] = 0;
																		this->vCard_number[i + 1] = 0;
																	}
																}
															}
															break;
														}
													}
												}
												else
												{
													int counter4 = 0;
													for (int i = 0; i < 13; i++)
													{
														if (no_trump_color[i] == A[4 * a])
														{
															counter4++;
															if (counter4 == 2)
															{
																A[b + 4 * a] = no_trump_color[i];
																this->sCard_color[a] = no_trump_color[i];
																B[b + 4 * a] = no_trump_number[i];
																this->sCard_number[a] = no_trump_number[i];
																for (int i = 0; i < 13; i++)
																{
																	for (int j = 0; j < 13; j++)
																	{
																		if ((no_trump_color[j] == this->vCard_color[i + 1]) && (no_trump_number[j] == this->vCard_number[i + 1]) == 1)
																		{
																			this->vCard_color[i + 1] = 0;
																			this->vCard_number[i + 1] = 0;
																		}
																	}
																}
																break;
															}
														}
													}
												}
											}
											else
											{
												/*
												���ɱ��p�����
												1.���ͬ����a
												2.���ͬ��X�P�ĤG����B���Ӫ�⪺�P
												if(b==2)
												else
												*/
												if (b == 2)
												{
													//�p�G����(���a)���P�Q���L
													if ((A[b + 4 * a - 1] == A[4 * a]) && ((B[b + 4 * a - 1] > B[4 * a]) || (B[b + 4 * a - 1] == 1)) == 1)
													{
														if (B[b + 4 * a - 1] == 1)
														{
															for (int i = 12; i >= 0; i--)
															{
																if (no_trump_color[i] == A[4 * a])
																{
																	A[b + 4 * a] = no_trump_color[i];
																	this->sCard_color[a] = no_trump_color[i];
																	B[b + 4 * a] = no_trump_number[i];
																	this->sCard_number[a] = no_trump_number[i];
																	for (int i = 0; i < 13; i++)
																	{
																		for (int j = 0; j < 13; j++)
																		{
																			if ((no_trump_color[j] == this->vCard_color[i + 1]) && (no_trump_number[j] == this->vCard_number[i + 1]) == 1)
																			{
																				this->vCard_color[i + 1] = 0;
																				this->vCard_number[i + 1] = 0;
																			}
																		}
																	}
																	break;
																}
															}
														}
														else
														{
															for (int i = 0; i < 13; i++)
															{
																if (((no_trump_color[i] == A[4 * a]) && ((no_trump_number[i] == 1) || (no_trump_number[i] > B[b + 4 * a - 1]) && (B[b + 4 * a - 1] != 1))) == 1)
																{
																	A[b + 4 * a] = no_trump_color[i];
																	this->sCard_color[a] = no_trump_color[i];
																	B[b + 4 * a] = no_trump_number[i];
																	this->sCard_number[a] = no_trump_number[i];
																	for (int i = 0; i < 13; i++)
																	{
																		for (int j = 0; j < 13; j++)
																		{
																			if ((no_trump_color[j] == this->vCard_color[i + 1]) && (no_trump_number[j] == this->vCard_number[i + 1]) == 1)
																			{
																				this->vCard_color[i + 1] = 0;
																				this->vCard_number[i + 1] = 0;
																			}
																		}
																	}
																	break;
																}
															}
															if (B[b + 4 * a] == 0)
															{
																for (int i = 12; i >= 0; i--)
																{
																	if (no_trump_color[i] == A[4 * a])
																	{
																		A[b + 4 * a] = no_trump_color[i];
																		this->sCard_color[a] = no_trump_color[i];
																		B[b + 4 * a] = no_trump_number[i];
																		this->sCard_number[a] = no_trump_number[i];
																		for (int i = 0; i < 13; i++)
																		{
																			for (int j = 0; j < 13; j++)
																			{
																				if ((no_trump_color[j] == this->vCard_color[i + 1]) && (no_trump_number[j] == this->vCard_number[i + 1]) == 1)
																				{
																					this->vCard_color[i + 1] = 0;
																					this->vCard_number[i + 1] = 0;
																				}
																			}
																		}
																		break;
																	}
																}
															}
														}
													}
													else
													{
														if ((C.v_rand_1 || C.v_rand_2 || C.v_rand_3) == 1)
														{
															for (int i = 12; i >= 0; i--)
															{
																if (no_trump_color[i] == A[4 * a])
																{
																	A[b + 4 * a] = no_trump_color[i];
																	this->sCard_color[a] = no_trump_color[i];
																	B[b + 4 * a] = no_trump_number[i];
																	this->sCard_number[a] = no_trump_number[i];
																	for (int i = 0; i < 13; i++)
																	{
																		for (int j = 0; j < 13; j++)
																		{
																			if ((no_trump_color[j] == this->vCard_color[i + 1]) && (no_trump_number[j] == this->vCard_number[i + 1]) == 1)
																			{
																				this->vCard_color[i + 1] = 0;
																				this->vCard_number[i + 1] = 0;
																			}
																		}
																	}
																	break;
																}
															}
														}
														else
														{
															for (int i = 0; i < 13; i++)
															{
																if (((no_trump_color[i] == A[4 * a]) && ((no_trump_number[i] == 1) || (no_trump_number[i] > B[b + 4 * a - 1]) && (B[b + 4 * a - 1] != 1))) == 1)
																{
																	A[b + 4 * a] = no_trump_color[i];
																	this->sCard_color[a] = no_trump_color[i];
																	B[b + 4 * a] = no_trump_number[i];
																	this->sCard_number[a] = no_trump_number[i];
																	for (int i = 0; i < 13; i++)
																	{
																		for (int j = 0; j < 13; j++)
																		{
																			if ((no_trump_color[j] == this->vCard_color[i + 1]) && (no_trump_number[j] == this->vCard_number[i + 1]) == 1)
																			{
																				this->vCard_color[i + 1] = 0;
																				this->vCard_number[i + 1] = 0;
																			}
																		}
																	}
																	break;
																}
															}
															if (B[b + 4 * a] == 0)
															{
																for (int i = 12; i >= 0; i--)
																{
																	if (no_trump_color[i] == A[4 * a])
																	{
																		A[b + 4 * a] = no_trump_color[i];
																		this->sCard_color[a] = no_trump_color[i];
																		B[b + 4 * a] = no_trump_number[i];
																		this->sCard_number[a] = no_trump_number[i];
																		for (int i = 0; i < 13; i++)
																		{
																			for (int j = 0; j < 13; j++)
																			{
																				if ((no_trump_color[j] == this->vCard_color[i + 1]) && (no_trump_number[j] == this->vCard_number[i + 1]) == 1)
																				{
																					this->vCard_color[i + 1] = 0;
																					this->vCard_number[i + 1] = 0;
																				}
																			}
																		}
																		break;
																	}
																}
															}
														}
													}
												}
												else
												{
													for (int i = 12; i >= 0; i--)
													{
														if (no_trump_color[i] == A[4 * a])
														{
															if (A[b + 4 * a - 1] != A[4 * a])
															{
																if ((no_trump_number[i] > B[4 * a]) && (B[4 * a] != 1) == 1)
																{
																	A[b + 4 * a] = no_trump_color[i];
																	this->sCard_color[a] = no_trump_color[i];
																	B[b + 4 * a] = no_trump_number[i];
																	this->sCard_number[a] = no_trump_number[i];
																	for (int i = 0; i < 13; i++)
																	{
																		for (int j = 0; j < 13; j++)
																		{
																			if ((no_trump_color[j] == this->vCard_color[i + 1]) && (no_trump_number[j] == this->vCard_number[i + 1]) == 1)
																			{
																				this->vCard_color[i + 1] = 0;
																				this->vCard_number[i + 1] = 0;
																			}
																		}
																	}
																	break;
																}
															}
															else
															{
																if ((((B[b + 4 * a - 2] > B[b + 4 * a - 1]) && (B[b + 4 * a - 2] > B[b + 4 * a])) || (B[b + 4 * a - 2] == 1)) == 1)
																{
																	A[b + 4 * a] = no_trump_color[i];
																	this->sCard_color[a] = no_trump_color[i];
																	B[b + 4 * a] = no_trump_number[i];
																	this->sCard_number[a] = no_trump_number[i];
																	for (int i = 0; i < 13; i++)
																	{
																		for (int j = 0; j < 13; j++)
																		{
																			if ((no_trump_color[j] == this->vCard_color[i + 1]) && (no_trump_number[j] == this->vCard_number[i + 1]) == 1)
																			{
																				this->vCard_color[i + 1] = 0;
																				this->vCard_number[i + 1] = 0;
																			}
																		}
																	}
																	break;
																}
																else
																{
																	if ((no_trump_number[i] > B[4 * a]) && (B[4 * a] != 1) == 1)
																	{
																		if ((no_trump_number[i] > B[b + 4 * a - 1]) && (B[b + 4 * a - 1] != 1) == 1)
																		{
																			A[b + 4 * a] = no_trump_color[i];
																			this->sCard_color[a] = no_trump_color[i];
																			B[b + 4 * a] = no_trump_number[i];
																			this->sCard_number[a] = no_trump_number[i];
																			for (int i = 0; i < 13; i++)
																			{
																				for (int j = 0; j < 13; j++)
																				{
																					if ((no_trump_color[j] == this->vCard_color[i + 1]) && (no_trump_number[j] == this->vCard_number[i + 1]) == 1)
																					{
																						this->vCard_color[i + 1] = 0;
																						this->vCard_number[i + 1] = 0;
																					}
																				}
																			}
																			break;
																		}
																	}
																}
															}
														}
													}
													if (B[b + 4 * a] == 0)
													{
														for (int i = 12; i >= 0; i--)
														{
															if (no_trump_color[i] == A[4 * a])
															{
																A[b + 4 * a] = no_trump_color[i];
																this->sCard_color[a] = no_trump_color[i];
																B[b + 4 * a] = no_trump_number[i];
																this->sCard_number[a] = no_trump_number[i];
																for (int i = 0; i < 13; i++)
																{
																	for (int j = 0; j < 13; j++)
																	{
																		if ((no_trump_color[j] == this->vCard_color[i + 1]) && (no_trump_number[j] == this->vCard_number[i + 1]) == 1)
																		{
																			this->vCard_color[i + 1] = 0;
																			this->vCard_number[i + 1] = 0;
																		}
																	}
																}
																break;
															}
														}
													}
												}
											}
										}
										else
										{
											//�P���̤j�P,�Φ��j�P
											if (counter2 != 1)
											{
												int counter4 = 0;
												for (int i = 0; i < 13; i++)
												{
													if (no_trump_color[i] == A[4 * a])
													{
														counter4++;
														if (counter4 == counter2)
														{
															A[b + 4 * a] = no_trump_color[i];
															this->sCard_color[a] = no_trump_color[i];
															B[b + 4 * a] = no_trump_number[i];
															this->sCard_number[a] = no_trump_number[i];
															for (int i = 0; i < 13; i++)
															{
																for (int j = 0; j < 13; j++)
																{
																	if ((no_trump_color[j] == this->vCard_color[i + 1]) && (no_trump_number[j] == this->vCard_number[i + 1]) == 1)
																	{
																		this->vCard_color[i + 1] = 0;
																		this->vCard_number[i + 1] = 0;
																	}
																}
															}
															break;
														}
													}
												}
											}
											else
											{
												for (int i = 0; i < 13; i++)
												{
													if (no_trump_color[i] == A[4 * a])
													{
														A[b + 4 * a] = no_trump_color[i];
														this->sCard_color[a] = no_trump_color[i];
														B[b + 4 * a] = no_trump_number[i];
														this->sCard_number[a] = no_trump_number[i];
														for (int i = 0; i < 13; i++)
														{
															for (int j = 0; j < 13; j++)
															{
																if ((no_trump_color[j] == this->vCard_color[i + 1]) && (no_trump_number[j] == this->vCard_number[i + 1]) == 1)
																{
																	this->vCard_color[i + 1] = 0;
																	this->vCard_number[i + 1] = 0;
																}
															}
														}
														break;
													}
												}
											}
										}
									}
								}
								else
								{
									for (int i = 0; i < 13; i++)
									{
										if (no_trump_color[i] == A[4 * a])
										{
											A[b + 4 * a] = no_trump_color[i];
											this->sCard_color[a] = no_trump_color[i];
											B[b + 4 * a] = no_trump_number[i];
											this->sCard_number[a] = no_trump_number[i];
											for (int i = 0; i < 13; i++)
											{
												for (int j = 0; j < 13; j++)
												{
													if ((no_trump_color[j] == this->vCard_color[i + 1]) && (no_trump_number[j] == this->vCard_number[i + 1]) == 1)
													{
														this->vCard_color[i + 1] = 0;
														this->vCard_number[i + 1] = 0;
													}
												}
											}
											break;
										}
									}
								}
							}
							else
							{
								if (counter > 1)
								{
									if (a > 7)
									{
										if (b > 1)
										{
											if (A[b + 4 * a - 2] != A[4 * a])
											{
												//���ɶ��ͬ��X�P�ĤG����B�w�S���Ӫ�⪺�P
												if (C.v_rand_1 || C.v_rand_2 == 1)
												{
													for (int i = 0; i < 13; i++)
													{
														if (no_trump_color[i] == A[4 * a])
														{
															A[b + 4 * a] = no_trump_color[i];
															this->sCard_color[a] = no_trump_color[i];
															B[b + 4 * a] = no_trump_number[i];
															this->sCard_number[a] = no_trump_number[i];
															for (int i = 0; i < 13; i++)
															{
																for (int j = 0; j < 13; j++)
																{
																	if ((no_trump_color[j] == this->vCard_color[i + 1]) && (no_trump_number[j] == this->vCard_number[i + 1]) == 1)
																	{
																		this->vCard_color[i + 1] = 0;
																		this->vCard_number[i + 1] = 0;
																	}
																}
															}
															break;
														}
													}
												}
												else
												{
													int counter4 = 0;
													for (int i = 0; i < 13; i++)
													{
														if (no_trump_color[i] == A[4 * a])
														{
															counter4++;
															if (counter4 == 2)
															{
																A[b + 4 * a] = no_trump_color[i];
																this->sCard_color[a] = no_trump_color[i];
																B[b + 4 * a] = no_trump_number[i];
																this->sCard_number[a] = no_trump_number[i];
																for (int i = 0; i < 13; i++)
																{
																	for (int j = 0; j < 13; j++)
																	{
																		if ((no_trump_color[j] == this->vCard_color[i + 1]) && (no_trump_number[j] == this->vCard_number[i + 1]) == 1)
																		{
																			this->vCard_color[i + 1] = 0;
																			this->vCard_number[i + 1] = 0;
																		}
																	}
																}
																break;
															}
														}
													}
												}
											}
											else
											{
												/*
												���ɱ��p�����
												1.���ͬ����a
												2.���ͬ��X�P�ĤG����B�w�S���Ӫ�⪺�P
												if(b==2)
												else
												*/
												if (b == 2)
												{
													//�p�G����(���a)���P�Q���L
													if ((A[b + 4 * a - 1] == A[4 * a]) && ((B[b + 4 * a - 1] > B[4 * a]) || (B[b + 4 * a - 1] == 1)) == 1)
													{
														if (B[b + 4 * a - 1] == 1)
														{
															for (int i = 12; i >= 0; i--)
															{
																if (no_trump_color[i] == A[4 * a])
																{
																	A[b + 4 * a] = no_trump_color[i];
																	this->sCard_color[a] = no_trump_color[i];
																	B[b + 4 * a] = no_trump_number[i];
																	this->sCard_number[a] = no_trump_number[i];
																	for (int i = 0; i < 13; i++)
																	{
																		for (int j = 0; j < 13; j++)
																		{
																			if ((no_trump_color[j] == this->vCard_color[i + 1]) && (no_trump_number[j] == this->vCard_number[i + 1]) == 1)
																			{
																				this->vCard_color[i + 1] = 0;
																				this->vCard_number[i + 1] = 0;
																			}
																		}
																	}
																	break;
																}
															}
														}
														else
														{
															for (int i = 0; i < 13; i++)
															{
																if (((no_trump_color[i] == A[4 * a]) && ((no_trump_number[i] == 1) || (no_trump_number[i] > B[b + 4 * a - 1]) && (B[b + 4 * a - 1] != 1))) == 1)
																{
																	A[b + 4 * a] = no_trump_color[i];
																	this->sCard_color[a] = no_trump_color[i];
																	B[b + 4 * a] = no_trump_number[i];
																	this->sCard_number[a] = no_trump_number[i];
																	for (int i = 0; i < 13; i++)
																	{
																		for (int j = 0; j < 13; j++)
																		{
																			if ((no_trump_color[j] == this->vCard_color[i + 1]) && (no_trump_number[j] == this->vCard_number[i + 1]) == 1)
																			{
																				this->vCard_color[i + 1] = 0;
																				this->vCard_number[i + 1] = 0;
																			}
																		}
																	}
																	break;
																}
															}
															if (B[b + 4 * a] == 0)
															{
																for (int i = 12; i >= 0; i--)
																{
																	if (no_trump_color[i] == A[4 * a])
																	{
																		A[b + 4 * a] = no_trump_color[i];
																		this->sCard_color[a] = no_trump_color[i];
																		B[b + 4 * a] = no_trump_number[i];
																		this->sCard_number[a] = no_trump_number[i];
																		for (int i = 0; i < 13; i++)
																		{
																			for (int j = 0; j < 13; j++)
																			{
																				if ((no_trump_color[j] == this->vCard_color[i + 1]) && (no_trump_number[j] == this->vCard_number[i + 1]) == 1)
																				{
																					this->vCard_color[i + 1] = 0;
																					this->vCard_number[i + 1] = 0;
																				}
																			}
																		}
																		break;
																	}
																}
															}
														}
													}
													else
													{
														if ((C.v_rand_1 || C.v_rand_2 || C.v_rand_3) == 1)
														{
															for (int i = 12; i >= 0; i--)
															{
																if (no_trump_color[i] == A[4 * a])
																{
																	A[b + 4 * a] = no_trump_color[i];
																	this->sCard_color[a] = no_trump_color[i];
																	B[b + 4 * a] = no_trump_number[i];
																	this->sCard_number[a] = no_trump_number[i];
																	for (int i = 0; i < 13; i++)
																	{
																		for (int j = 0; j < 13; j++)
																		{
																			if ((no_trump_color[j] == this->vCard_color[i + 1]) && (no_trump_number[j] == this->vCard_number[i + 1]) == 1)
																			{
																				this->vCard_color[i + 1] = 0;
																				this->vCard_number[i + 1] = 0;
																			}
																		}
																	}
																	break;
																}
															}
														}
														else
														{
															for (int i = 0; i < 13; i++)
															{
																if (((no_trump_color[i] == A[4 * a]) && ((no_trump_number[i] == 1) || (no_trump_number[i] > B[b + 4 * a - 1]) && (B[b + 4 * a - 1] != 1))) == 1)
																{
																	A[b + 4 * a] = no_trump_color[i];
																	this->sCard_color[a] = no_trump_color[i];
																	B[b + 4 * a] = no_trump_number[i];
																	this->sCard_number[a] = no_trump_number[i];
																	for (int i = 0; i < 13; i++)
																	{
																		for (int j = 0; j < 13; j++)
																		{
																			if ((no_trump_color[j] == this->vCard_color[i + 1]) && (no_trump_number[j] == this->vCard_number[i + 1]) == 1)
																			{
																				this->vCard_color[i + 1] = 0;
																				this->vCard_number[i + 1] = 0;
																			}
																		}
																	}
																	break;
																}
															}
															if (B[b + 4 * a] == 0)
															{
																for (int i = 12; i >= 0; i--)
																{
																	if (no_trump_color[i] == A[4 * a])
																	{
																		A[b + 4 * a] = no_trump_color[i];
																		this->sCard_color[a] = no_trump_color[i];
																		B[b + 4 * a] = no_trump_number[i];
																		this->sCard_number[a] = no_trump_number[i];
																		for (int i = 0; i < 13; i++)
																		{
																			for (int j = 0; j < 13; j++)
																			{
																				if ((no_trump_color[j] == this->vCard_color[i + 1]) && (no_trump_number[j] == this->vCard_number[i + 1]) == 1)
																				{
																					this->vCard_color[i + 1] = 0;
																					this->vCard_number[i + 1] = 0;
																				}
																			}
																		}
																		break;
																	}
																}
															}
														}
													}
												}
												else
												{
													if (C.v_rand_1&&C.v_rand_2 == 1)
													{
														for (int i = 0; i < 13; i++)
														{
															if (no_trump_color[i] == A[4 * a])
															{
																A[b + 4 * a] = no_trump_color[i];
																this->sCard_color[a] = no_trump_color[i];
																B[b + 4 * a] = no_trump_number[i];
																this->sCard_number[a] = no_trump_number[i];
																for (int i = 0; i < 13; i++)
																{
																	for (int j = 0; j < 13; j++)
																	{
																		if ((no_trump_color[j] == this->vCard_color[i + 1]) && (no_trump_number[j] == this->vCard_number[i + 1]) == 1)
																		{
																			this->vCard_color[i + 1] = 0;
																			this->vCard_number[i + 1] = 0;
																		}
																	}
																}
																break;
															}
														}
													}
													else
													{
														int counter4 = 0;
														for (int i = 0; i < 13; i++)
														{
															if (no_trump_color[i] == A[4 * a])
															{
																counter4++;
																if (counter4 == 2)
																{
																	A[b + 4 * a] = no_trump_color[i];
																	this->sCard_color[a] = no_trump_color[i];
																	B[b + 4 * a] = no_trump_number[i];
																	this->sCard_number[a] = no_trump_number[i];
																	for (int i = 0; i < 13; i++)
																	{
																		for (int j = 0; j < 13; j++)
																		{
																			if ((no_trump_color[j] == this->vCard_color[i + 1]) && (no_trump_number[j] == this->vCard_number[i + 1]) == 1)
																			{
																				this->vCard_color[i + 1] = 0;
																				this->vCard_number[i + 1] = 0;
																			}
																		}
																	}
																	break;
																}
															}
														}
													}
												}
											}
										}
										else
										{
											//7��5���v�X�P���̤j�P,�Φ��j�P
											if ((counter2 > 1) && (C.v_rand_1 || C.v_rand_2) == 1)
											{
												for (int i = 0; i < 13; i++)
												{
													if (no_trump_color[i] == A[4 * a])
													{
														A[b + 4 * a] = no_trump_color[i];
														this->sCard_color[a] = no_trump_color[i];
														B[b + 4 * a] = no_trump_number[i];
														this->sCard_number[a] = no_trump_number[i];
														for (int i = 0; i < 13; i++)
														{
															for (int j = 0; j < 13; j++)
															{
																if ((no_trump_color[j] == this->vCard_color[i + 1]) && (no_trump_number[j] == this->vCard_number[i + 1]) == 1)
																{
																	this->vCard_color[i + 1] = 0;
																	this->vCard_number[i + 1] = 0;
																}
															}
														}
														break;
													}
												}
											}
											else
											{
												int counter4 = 0;
												for (int i = 0; i < 13; i++)
												{
													if (no_trump_color[i] == A[4 * a])
													{
														counter4++;
														if (counter4 == 2)
														{
															A[b + 4 * a] = no_trump_color[i];
															this->sCard_color[a] = no_trump_color[i];
															B[b + 4 * a] = no_trump_number[i];
															this->sCard_number[a] = no_trump_number[i];
															for (int i = 0; i < 13; i++)
															{
																for (int j = 0; j < 13; j++)
																{
																	if ((no_trump_color[j] == this->vCard_color[i + 1]) && (no_trump_number[j] == this->vCard_number[i + 1]) == 1)
																	{
																		this->vCard_color[i + 1] = 0;
																		this->vCard_number[i + 1] = 0;
																	}
																}
															}
															break;
														}
													}
												}
											}
										}
									}
									else
									{
										if (b > 1)
										{
											if (A[b + 4 * a - 2] != A[4 * a])
											{
												//���ɶ��ͬ��X�P�ĤG����B�w�S���Ӫ�⪺�P
												if (C.v_rand_1&&C.v_rand_2 == 1)
												{
													for (int i = 0; i < 13; i++)
													{
														if (no_trump_color[i] == A[4 * a])
														{
															A[b + 4 * a] = no_trump_color[i];
															this->sCard_color[a] = no_trump_color[i];
															B[b + 4 * a] = no_trump_number[i];
															this->sCard_number[a] = no_trump_number[i];
															for (int i = 0; i < 13; i++)
															{
																for (int j = 0; j < 13; j++)
																{
																	if ((no_trump_color[j] == this->vCard_color[i + 1]) && (no_trump_number[j] == this->vCard_number[i + 1]) == 1)
																	{
																		this->vCard_color[i + 1] = 0;
																		this->vCard_number[i + 1] = 0;
																	}
																}
															}
															break;
														}
													}
												}
												else
												{
													int counter4 = 0;
													for (int i = 0; i < 13; i++)
													{
														if (no_trump_color[i] == A[4 * a])
														{
															counter4++;
															if (counter4 == 2)
															{
																A[b + 4 * a] = no_trump_color[i];
																this->sCard_color[a] = no_trump_color[i];
																B[b + 4 * a] = no_trump_number[i];
																this->sCard_number[a] = no_trump_number[i];
																for (int i = 0; i < 13; i++)
																{
																	for (int j = 0; j < 13; j++)
																	{
																		if ((no_trump_color[j] == this->vCard_color[i + 1]) && (no_trump_number[j] == this->vCard_number[i + 1]) == 1)
																		{
																			this->vCard_color[i + 1] = 0;
																			this->vCard_number[i + 1] = 0;
																		}
																	}
																}
																break;
															}
														}
													}
												}
											}
											else
											{
												/*
												���ɱ��p�����
												1.���ͬ����a
												2.���ͬ��X�P�ĤG����B�w�S���Ӫ�⪺�P
												if(b==2)
												else
												*/
												if (b == 2)
												{
													//�p�G����(���a)���P�Q���L
													if ((A[b + 4 * a - 1] == A[4 * a]) && ((B[b + 4 * a - 1] > B[4 * a]) || (B[b + 4 * a - 1] == 1)) == 1)
													{
														if (B[b + 4 * a - 1] == 1)
														{
															for (int i = 12; i >= 0; i--)
															{
																if (no_trump_color[i] == A[4 * a])
																{
																	A[b + 4 * a] = no_trump_color[i];
																	this->sCard_color[a] = no_trump_color[i];
																	B[b + 4 * a] = no_trump_number[i];
																	this->sCard_number[a] = no_trump_number[i];
																	for (int i = 0; i < 13; i++)
																	{
																		for (int j = 0; j < 13; j++)
																		{
																			if ((no_trump_color[j] == this->vCard_color[i + 1]) && (no_trump_number[j] == this->vCard_number[i + 1]) == 1)
																			{
																				this->vCard_color[i + 1] = 0;
																				this->vCard_number[i + 1] = 0;
																			}
																		}
																	}
																	break;
																}
															}
														}
														else
														{
															for (int i = 0; i < 13; i++)
															{
																if (((no_trump_color[i] == A[4 * a]) && ((no_trump_number[i] == 1) || (no_trump_number[i] > B[b + 4 * a - 1]) && (B[b + 4 * a - 1] != 1))) == 1)
																{
																	A[b + 4 * a] = no_trump_color[i];
																	this->sCard_color[a] = no_trump_color[i];
																	B[b + 4 * a] = no_trump_number[i];
																	this->sCard_number[a] = no_trump_number[i];
																	for (int i = 0; i < 13; i++)
																	{
																		for (int j = 0; j < 13; j++)
																		{
																			if ((no_trump_color[j] == this->vCard_color[i + 1]) && (no_trump_number[j] == this->vCard_number[i + 1]) == 1)
																			{
																				this->vCard_color[i + 1] = 0;
																				this->vCard_number[i + 1] = 0;
																			}
																		}
																	}
																	break;
																}
															}
															if (B[b + 4 * a] == 0)
															{
																for (int i = 12; i >= 0; i--)
																{
																	if (no_trump_color[i] == A[4 * a])
																	{
																		A[b + 4 * a] = no_trump_color[i];
																		this->sCard_color[a] = no_trump_color[i];
																		B[b + 4 * a] = no_trump_number[i];
																		this->sCard_number[a] = no_trump_number[i];
																		for (int i = 0; i < 13; i++)
																		{
																			for (int j = 0; j < 13; j++)
																			{
																				if ((no_trump_color[j] == this->vCard_color[i + 1]) && (no_trump_number[j] == this->vCard_number[i + 1]) == 1)
																				{
																					this->vCard_color[i + 1] = 0;
																					this->vCard_number[i + 1] = 0;
																				}
																			}
																		}
																		break;
																	}
																}
															}
														}
													}
													else
													{
														if ((C.v_rand_1 || C.v_rand_2 || C.v_rand_3) == 1)
														{
															for (int i = 12; i >= 0; i--)
															{
																if (no_trump_color[i] == A[4 * a])
																{
																	A[b + 4 * a] = no_trump_color[i];
																	this->sCard_color[a] = no_trump_color[i];
																	B[b + 4 * a] = no_trump_number[i];
																	this->sCard_number[a] = no_trump_number[i];
																	for (int i = 0; i < 13; i++)
																	{
																		for (int j = 0; j < 13; j++)
																		{
																			if ((no_trump_color[j] == this->vCard_color[i + 1]) && (no_trump_number[j] == this->vCard_number[i + 1]) == 1)
																			{
																				this->vCard_color[i + 1] = 0;
																				this->vCard_number[i + 1] = 0;
																			}
																		}
																	}
																	break;
																}
															}
														}
														else
														{
															for (int i = 0; i < 13; i++)
															{
																if (((no_trump_color[i] == A[4 * a]) && ((no_trump_number[i] == 1) || (no_trump_number[i] > B[b + 4 * a - 1]) && (B[b + 4 * a - 1] != 1))) == 1)
																{
																	A[b + 4 * a] = no_trump_color[i];
																	this->sCard_color[a] = no_trump_color[i];
																	B[b + 4 * a] = no_trump_number[i];
																	this->sCard_number[a] = no_trump_number[i];
																	for (int i = 0; i < 13; i++)
																	{
																		for (int j = 0; j < 13; j++)
																		{
																			if ((no_trump_color[j] == this->vCard_color[i + 1]) && (no_trump_number[j] == this->vCard_number[i + 1]) == 1)
																			{
																				this->vCard_color[i + 1] = 0;
																				this->vCard_number[i + 1] = 0;
																			}
																		}
																	}
																	break;
																}
															}
															if (B[b + 4 * a] == 0)
															{
																for (int i = 12; i >= 0; i--)
																{
																	if (no_trump_color[i] == A[4 * a])
																	{
																		A[b + 4 * a] = no_trump_color[i];
																		this->sCard_color[a] = no_trump_color[i];
																		B[b + 4 * a] = no_trump_number[i];
																		this->sCard_number[a] = no_trump_number[i];
																		for (int i = 0; i < 13; i++)
																		{
																			for (int j = 0; j < 13; j++)
																			{
																				if ((no_trump_color[j] == this->vCard_color[i + 1]) && (no_trump_number[j] == this->vCard_number[i + 1]) == 1)
																				{
																					this->vCard_color[i + 1] = 0;
																					this->vCard_number[i + 1] = 0;
																				}
																			}
																		}
																		break;
																	}
																}
															}
														}
													}
												}
												else
												{
													if (C.v_rand_1&&C.v_rand_2 == 1)
													{
														for (int i = 0; i < 13; i++)
														{
															if (no_trump_color[i] == A[4 * a])
															{
																A[b + 4 * a] = no_trump_color[i];
																this->sCard_color[a] = no_trump_color[i];
																B[b + 4 * a] = no_trump_number[i];
																this->sCard_number[a] = no_trump_number[i];
																for (int i = 0; i < 13; i++)
																{
																	for (int j = 0; j < 13; j++)
																	{
																		if ((no_trump_color[j] == this->vCard_color[i + 1]) && (no_trump_number[j] == this->vCard_number[i + 1]) == 1)
																		{
																			this->vCard_color[i + 1] = 0;
																			this->vCard_number[i + 1] = 0;
																		}
																	}
																}
																break;
															}
														}
													}
													else
													{
														int counter4 = 0;
														for (int i = 0; i < 13; i++)
														{
															if (no_trump_color[i] == A[4 * a])
															{
																counter4++;
																if (counter4 == 2)
																{
																	A[b + 4 * a] = no_trump_color[i];
																	this->sCard_color[a] = no_trump_color[i];
																	B[b + 4 * a] = no_trump_number[i];
																	this->sCard_number[a] = no_trump_number[i];
																	for (int i = 0; i < 13; i++)
																	{
																		for (int j = 0; j < 13; j++)
																		{
																			if ((no_trump_color[j] == this->vCard_color[i + 1]) && (no_trump_number[j] == this->vCard_number[i + 1]) == 1)
																			{
																				this->vCard_color[i + 1] = 0;
																				this->vCard_number[i + 1] = 0;
																			}
																		}
																	}
																	break;
																}
															}
														}
													}
												}
											}
										}
										else
										{
											//3/4���v�X�P���̤j�P,�Φ��j�P
											if ((counter2 > 1) && (C.v_rand_1&&C.v_rand_2) == 1)
											{
												int counter4 = 0;
												for (int i = 0; i < 13; i++)
												{
													if (no_trump_color[i] == A[4 * a])
													{
														counter4++;
														if (counter4 == counter2)
														{
															A[b + 4 * a] = no_trump_color[i];
															this->sCard_color[a] = no_trump_color[i];
															B[b + 4 * a] = no_trump_number[i];
															this->sCard_number[a] = no_trump_number[i];
															for (int i = 0; i < 13; i++)
															{
																for (int j = 0; j < 13; j++)
																{
																	if ((no_trump_color[j] == this->vCard_color[i + 1]) && (no_trump_number[j] == this->vCard_number[i + 1]) == 1)
																	{
																		this->vCard_color[i + 1] = 0;
																		this->vCard_number[i + 1] = 0;
																	}
																}
															}
															break;
														}
													}
												}
											}
											else
											{
												for (int i = 0; i < 13; i++)
												{
													if (no_trump_color[i] == A[4 * a])
													{
														A[b + 4 * a] = no_trump_color[i];
														this->sCard_color[a] = no_trump_color[i];
														B[b + 4 * a] = no_trump_number[i];
														this->sCard_number[a] = no_trump_number[i];
														for (int i = 0; i < 13; i++)
														{
															for (int j = 0; j < 13; j++)
															{
																if ((no_trump_color[j] == this->vCard_color[i + 1]) && (no_trump_number[j] == this->vCard_number[i + 1]) == 1)
																{
																	this->vCard_color[i + 1] = 0;
																	this->vCard_number[i + 1] = 0;
																}
															}
														}
														break;
													}
												}
											}
										}
									}
								}
								else
								{
									for (int i = 0; i < 13; i++)
									{
										if (no_trump_color[i] == A[4 * a])
										{
											A[b + 4 * a] = no_trump_color[i];
											this->sCard_color[a] = no_trump_color[i];
											B[b + 4 * a] = no_trump_number[i];
											this->sCard_number[a] = no_trump_number[i];
											for (int i = 0; i < 13; i++)
											{
												for (int j = 0; j < 13; j++)
												{
													if ((no_trump_color[j] == this->vCard_color[i + 1]) && (no_trump_number[j] == this->vCard_number[i + 1]) == 1)
													{
														this->vCard_color[i + 1] = 0;
														this->vCard_number[i + 1] = 0;
													}
												}
											}
											break;
										}
									}
								}
							}
						}
						else
						{
							//�X�P���Ʀr�̤p���@�i
							for (int i = 12; i >= 0; i--)
							{
								if (no_trump_color[i] == A[4 * a])
								{
									A[b + 4 * a] = no_trump_color[i];
									this->sCard_color[a] = no_trump_color[i];
									B[b + 4 * a] = no_trump_number[i];
									this->sCard_number[a] = no_trump_number[i];
									for (int i = 0; i < 13; i++)
									{
										for (int j = 0; j < 13; j++)
										{
											if ((no_trump_color[j] == this->vCard_color[i + 1]) && (no_trump_number[j] == this->vCard_number[i + 1]) == 1)
											{
												this->vCard_color[i + 1] = 0;
												this->vCard_number[i + 1] = 0;
											}
										}
									}
									break;
								}
							}
						}
					}
					else
					{
						int counter3 = 0;
						for (int i = 0; i > -8; i--)
						{
							if (b - 1 + 4 * a >= 0)
							{
								if (A[b - 1 + 4 * a] == A[4 * a])
								{
									if (B[b - 1 + 4 * a] > B[4 * a])
										counter3++;
								}
							}
						}
						//�p�G�⤤���P�����Ldeclarer�ҥX���P
						if (counter2 != 0)
						{
							//�p�G�w���H�X�L�����Ldeclarer�ҥX���P,true�����ΤU�i�H�Ҽ{�n���X�P
							if (counter3 != 0)
							{
								if (b > 1)
								{
									if (A[b + 4 * a - 2] != A[4 * a])
									{
										if (C.v_rand_1 == 1)
										{
											for (int i = 0; i < 13; i++)
											{
												if (no_trump_color[i] == A[4 * a])
												{
													A[b + 4 * a] = no_trump_color[i];
													this->sCard_color[a] = no_trump_color[i];
													B[b + 4 * a] = no_trump_number[i];
													this->sCard_number[a] = no_trump_number[i];
													for (int j = 0; j < 13; j++)
													{
														if ((no_trump_color[i] == this->vCard_color[j + 1]) && (no_trump_number[i] == this->vCard_number[j + 1]) == 1)
														{
															this->vCard_color[j + 1] = 0;
															this->vCard_number[j + 1] = 0;
														}
													}
													break;
												}
											}
										}
										else
										{
											int counter4 = 0;
											for (int i = 0; i < 13; i++)
											{
												if (no_trump_color[i] == A[4 * a])
												{
													counter4++;
													if (counter4 == 1)
													{
														A[b + 4 * a] = no_trump_color[i];
														this->sCard_color[a] = no_trump_color[i];
														B[b + 4 * a] = no_trump_number[i];
														this->sCard_number[a] = no_trump_number[i];
														for (int j = 0; j < 13; j++)
														{
															if ((no_trump_color[i] == this->vCard_color[j + 1]) && (no_trump_number[i] == this->vCard_number[j + 1]) == 1)
															{
																this->vCard_color[j + 1] = 0;
																this->vCard_number[j + 1] = 0;
															}
														}
														break;
													}
												}
											}
										}
									}
									else
									{
										for (int i = 0; i < 13; i++)
										{
											if ((this->vCard_color[i] == A[4 * a]) && (this->vCard_number[i] > A[b + 4 * a - 2]) && (B[b + 4 * a - 2]<B[4 * a]) && (B[b + 4 * a - 2] != 1) == 1)
											{
												A[b + 4 * a] = no_trump_color[i];
												this->sCard_color[a] = no_trump_color[i];
												B[b + 4 * a] = no_trump_number[i];
												this->sCard_number[a] = no_trump_number[i];
												for (int j = 0; j < 13; j++)
												{
													if ((no_trump_color[i] == this->vCard_color[j + 1]) && (no_trump_number[i] == this->vCard_number[j + 1]) == 1)
													{
														this->vCard_color[j + 1] = 0;
														this->vCard_number[j + 1] = 0;
													}
												}
												break;
											}
										}
										if (B[b + 4 * a] == 0)
										{
											for (int i = 12; i >= 0; i--)
											{
												if (this->vCard_color[i] == A[4 * a])
												{
													A[b + 4 * a] = no_trump_color[i];
													this->sCard_color[a] = no_trump_color[i];
													B[b + 4 * a] = no_trump_number[i];
													this->sCard_number[a] = no_trump_number[i];
													for (int j = 0; j < 13; j++)
													{
														if ((no_trump_color[i] == this->vCard_color[j + 1]) && (no_trump_number[i] == this->vCard_number[j + 1]) == 1)
														{
															this->vCard_color[j + 1] = 0;
															this->vCard_number[j + 1] = 0;
														}
													}
													break;
												}
											}
										}
									}
								}
								else
								{
									for (int i = 0; i < 13; i++)
									{
										if (no_trump_color[i] == A[4 * a])
										{
											A[b + 4 * a] = no_trump_color[i];
											this->sCard_color[a] = no_trump_color[i];
											B[b + 4 * a] = no_trump_number[i];
											this->sCard_number[a] = no_trump_number[i];
											for (int j = 0; j < 13; j++)
											{
												if ((no_trump_color[i] == this->vCard_color[j + 1]) && (no_trump_number[i] == this->vCard_number[j + 1]) == 1)
												{
													this->vCard_color[j + 1] = 0;
													this->vCard_number[j + 1] = 0;
												}
											}
											break;
										}
									}
								}
							}
							else
							{
								if (counter > 1)
								{
									if (b > 1)
									{
										if (A[b + 4 * a - 2] != A[4 * a])
										{
											if (C.v_rand_1 == 1)
											{
												for (int i = 0; i < 13; i++)
												{
													if (no_trump_color[i] == A[4 * a])
													{
														A[b + 4 * a] = no_trump_color[i];
														this->sCard_color[a] = no_trump_color[i];
														B[b + 4 * a] = no_trump_number[i];
														this->sCard_number[a] = no_trump_number[i];
														for (int j = 0; j < 13; j++)
														{
															if ((no_trump_color[i] == this->vCard_color[j + 1]) && (no_trump_number[i] == this->vCard_number[j + 1]) == 1)
															{
																this->vCard_color[j + 1] = 0;
																this->vCard_number[j + 1] = 0;
															}
														}
														break;
													}
												}
											}
											else
											{
												int counter4 = 0;
												for (int i = 0; i < 13; i++)
												{
													if (no_trump_color[i] == A[4 * a])
													{
														counter4++;
														if (counter4 == 1)
														{
															A[b + 4 * a] = no_trump_color[i];
															this->sCard_color[a] = no_trump_color[i];
															B[b + 4 * a] = no_trump_number[i];
															this->sCard_number[a] = no_trump_number[i];
															for (int j = 0; j < 13; j++)
															{
																if ((no_trump_color[i] == this->vCard_color[j + 1]) && (no_trump_number[i] == this->vCard_number[j + 1]) == 1)
																{
																	this->vCard_color[j + 1] = 0;
																	this->vCard_number[j + 1] = 0;
																}
															}
															break;
														}
													}
												}
											}
										}
										else
										{
											for (int i = 0; i < 13; i++)
											{
												if ((this->vCard_color[i] == A[4 * a]) && (this->vCard_number[i] > A[b + 4 * a - 2]) == 1)
												{
													A[b + 4 * a] = no_trump_color[i];
													this->sCard_color[a] = no_trump_color[i];
													B[b + 4 * a] = no_trump_number[i];
													this->sCard_number[a] = no_trump_number[i];
													for (int j = 0; j < 13; j++)
													{
														if ((no_trump_color[i] == this->vCard_color[j + 1]) && (no_trump_number[i] == this->vCard_number[j + 1]) == 1)
														{
															this->vCard_color[j + 1] = 0;
															this->vCard_number[j + 1] = 0;
														}
													}
													break;
												}
											}
											if (B[b + 4 * a] == 0)
											{
												for (int i = 12; i >= 0; i--)
												{
													if (this->vCard_color[i] == A[4 * a])
													{
														A[b + 4 * a] = no_trump_color[i];
														this->sCard_color[a] = no_trump_color[i];
														B[b + 4 * a] = no_trump_number[i];
														this->sCard_number[a] = no_trump_number[i];
														for (int j = 0; j < 13; j++)
														{
															if ((no_trump_color[i] == this->vCard_color[j + 1]) && (no_trump_number[i] == this->vCard_number[j + 1]) == 1)
															{
																this->vCard_color[j + 1] = 0;
																this->vCard_number[j + 1] = 0;
															}
														}
														break;
													}
												}
											}
										}
									}
									else
									{
										//�@�b���v�X�P���̤j�P,�Φ��j�P
										if (counter2 > 1)
										{
											for (int i = 12; i >= 0; i--)
											{
												if (no_trump_color[i] == A[4 * a])
												{
													if ((no_trump_number[i] > B[4 * a]) == 1)
													{
														A[b + 4 * a] = no_trump_color[i];
														this->sCard_color[a] = no_trump_color[i];
														B[b + 4 * a] = no_trump_number[i];
														this->sCard_number[a] = no_trump_number[i];
														for (int j = 0; j < 13; j++)
														{
															if ((no_trump_color[i] == this->vCard_color[j + 1]) && (no_trump_number[i] == this->vCard_number[j + 1]) == 1)
															{
																this->vCard_color[j + 1] = 0;
																this->vCard_number[j + 1] = 0;
															}
														}
														break;
													}
												}
											}
										}
										else
										{
											for (int i = 0; i < 13; i++)
											{
												if (no_trump_color[i] == A[4 * a])
												{
													A[b + 4 * a] = no_trump_color[i];
													this->sCard_color[a] = no_trump_color[i];
													B[b + 4 * a] = no_trump_number[i];
													this->sCard_number[a] = no_trump_number[i];
													for (int j = 0; j < 13; j++)
													{
														if ((no_trump_color[i] == this->vCard_color[j + 1]) && (no_trump_number[i] == this->vCard_number[j + 1]) == 1)
														{
															this->vCard_color[j + 1] = 0;
															this->vCard_number[j + 1] = 0;
														}
													}
													break;
												}
											}
										}
									}
								}
								else
								{
									for (int i = 0; i < 13; i++)
									{
										if (no_trump_color[i] == A[4 * a])
										{
											A[b + 4 * a] = no_trump_color[i];
											this->sCard_color[a] = no_trump_color[i];
											B[b + 4 * a] = no_trump_number[i];
											this->sCard_number[a] = no_trump_number[i];
											for (int j = 0; j < 13; j++)
											{
												if ((no_trump_color[i] == this->vCard_color[j + 1]) && (no_trump_number[i] == this->vCard_number[j + 1]) == 1)
												{
													this->vCard_color[j + 1] = 0;
													this->vCard_number[j + 1] = 0;
												}
											}
											break;
										}
									}
								}
							}
						}
						else
						{
							//�X�P���Ʀr�̤p���@�i
							for (int i = 12; i >= 0; i--)
							{
								if (no_trump_color[i] == A[4 * a])
								{
									A[b + 4 * a] = no_trump_color[i];
									this->sCard_color[a] = no_trump_color[i];
									B[b + 4 * a] = no_trump_number[i];
									this->sCard_number[a] = no_trump_number[i];
									for (int j = 0; j < 13; j++)
									{
										if ((no_trump_color[i] == this->vCard_color[j + 1]) && (no_trump_number[i] == this->vCard_number[j + 1]) == 1)
										{
											this->vCard_color[j + 1] = 0;
											this->vCard_number[j + 1] = 0;
										}
									}
									break;
								}
							}
						}
					}
					mark = 1;
				}
				else
				{
					//�X�⤤�Ʀr�̤p���N���
					for (int i = 12; i >= 0; i--)
					{
						if (no_trump_number[i] != 0)
						{
							A[b + 4 * a] = no_trump_color[i];
							this->sCard_color[a] = no_trump_color[i];
							B[b + 4 * a] = no_trump_number[i];
							this->sCard_number[a] = no_trump_number[i];
							for (int j = 0; j < 13; j++)
							{
								if ((no_trump_color[i] == this->vCard_color[j + 1]) && (no_trump_number[i] == this->vCard_number[j + 1]) == 1)
								{
									this->vCard_color[j + 1] = 0;
									this->vCard_number[j + 1] = 0;
								}
							}
							break;
						}
					}
				}
			}
		}
		//�|���
		else if ((this->auction_color == 1) || (this->auction_color == 2) || (this->auction_color == 3) || (this->auction_color == 4) == 1)
		{
			int danger = 0;
			if (c == 0)
			{
				//����player3��player4�X�P
				if ((b == 0) || (b == 2) == 1)
				{
					if (h1 > 2)
					{
						if ((d + e) >= (5 - h))
							danger = 1;
					}
					else
					{
						if ((d + e) >= (h - 2))
							danger = 1;
					}
				}
				//����player2�X�P
				else
				{
					if (h1 > 2)
					{
						if ((f + g) >= (h - 2))
							danger = 1;
					}
					else
					{
						if ((f + g) >= (5 - h))
							danger = 1;
					}
				}
			}
			else if (c == 1)
			{
				//����player3��player4�X�P
				if ((b == 1) || (b == 3) == 1)
				{
					if (h1 > 2)
					{
						if ((d + e) >= (5 - h))
							danger = 1;
					}
					else
					{
						if ((d + e) >= (h - 2))
							danger = 1;
					}
				}
				//����player2�X�P
				else
				{
					if (h1 > 2)
					{
						if ((f + g) >= (h - 2))
							danger = 1;
					}
					else
					{
						if ((f + g) >= (5 - h))
							danger = 1;
					}
				}
			}
			else if (c == 2)
			{
				//����player3��player4�X�P
				if ((b == 0) || (b == 2) == 1)
				{
					if (h1 > 2)
					{
						if ((d + e) >= (5 - h))
							danger = 1;
					}
					else
					{
						if ((d + e) >= (h - 2))
							danger = 1;
					}
				}
				//����player2�X�P
				else
				{
					if (h1 > 2)
					{
						if ((f + g) >= (h - 2))
							danger = 1;
					}
					else
					{
						if ((f + g) >= (5 - h))
							danger = 1;
					}
				}
			}
			else
			{
				//����player3��player4�X�P
				if ((b == 1) || (b == 3) == 1)
				{
					if (h1 > 2)
					{
						if ((d + e) >= (5 - h))
							danger = 1;
					}
					else
					{
						if ((d + e) >= (h - 2))
							danger = 1;
					}
				}
				//����player2�X�P
				else
				{
					if (h1 > 2)
					{
						if ((f + g) >= (h - 2))
							danger = 1;
					}
					else
					{
						if ((f + g) >= (5 - h))
							danger = 1;
					}
				}
			}
			/*�H�W�Ω�]�wdanger�Ȭ��s�Τ@*/
			int counter1 = 0;
			if (a == 0)
			{
				for (int i = 1; i < 14; i++)
				{
					int temp1, temp2, temp3, temp4 = 0;
					temp3 = i;
					do
					{
						if (((this->vCard_number[i] > this->vCard_number[i - 1]) || (this->vCard_number[i] == 1)) && (this->vCard_number[i - 1] != 0) == 1)
						{

							temp1 = this->vCard_number[i];
							temp2 = this->vCard_color[i];
							this->vCard_number[i] = this->vCard_number[i - 1];
							this->vCard_color[i] = this->vCard_color[i - 1];
							this->vCard_number[i - 1] = temp1;
							this->vCard_color[i - 1] = temp2;
							if (i > 2)
								i--;
							else
								break;
						}
						else
							break;
					} while (((this->vCard_number[i] > this->vCard_number[i + 1]) || (this->vCard_number[i] == 1)) && (this->vCard_number[i - 1] != 0) == 1);
					i = temp3;
				}
			}
			for (int i = 1; i < 14; i++)
			{
				if (this->vCard_color[i] == this->auction_color)
					counter1++;
			}
			//���Ĥ@�ӥX�P��
			if (b == 0)
			{
				//�C��������n,�Ҽ{�~��
				if (a > 8)
				{
					if (counter1 > 1)
					{
						if (C.v_rand_5&&C.v_rand_6 == 1 == 1)
						{
							for (int i = 1; i < 14; i++)
							{
								if ((this->vCard_number[i] != 0) && (this->vCard_color[i] == this->auction_color) == 1)
								{
									A[b + 4 * a] = this->vCard_color[i];
									this->sCard_color[a] = this->vCard_color[i];
									this->vCard_color[i] = 0;
									B[b + 4 * a] = this->vCard_number[i];
									this->sCard_number[a] = this->vCard_number[i];
									this->vCard_number[i] = 0;
									break;
								}
							}
						}
						else
						{
							for (int i = 1; i < 14; i++)
							{
								if ((this->vCard_number[i] != 0) && (this->vCard_color[i] != this->auction_color) == 1)
								{
									A[b + 4 * a] = this->vCard_color[i];
									this->sCard_color[a] = this->vCard_color[i];
									this->vCard_color[i] = 0;
									B[b + 4 * a] = this->vCard_number[i];
									this->sCard_number[a] = this->vCard_number[i];
									this->vCard_number[i] = 0;
									break;
								}
							}
						}
					}
					else
					{
						for (int i = 1; i < 14; i++)
						{
							if ((this->vCard_number[i] != 0) && (this->vCard_color[i] != this->auction_color) == 1)
							{
								A[b + 4 * a] = this->vCard_color[i];
								this->sCard_color[a] = this->vCard_color[i];
								this->vCard_color[i] = 0;
								B[b + 4 * a] = this->vCard_number[i];
								this->sCard_number[a] = this->vCard_number[i];
								this->vCard_number[i] = 0;
								break;
							}
						}
					}
				}
				//�X���F���P�H�~���̤j�P
				else
				{
					for (int i = 1; i < 14; i++)
					{
						if ((this->vCard_number[i] != 0) && (this->vCard_color[i] != this->auction_color) == 1)
						{
							A[b + 4 * a] = this->vCard_color[i];
							this->sCard_color[a] = this->vCard_color[i];
							this->vCard_color[i] = 0;
							B[b + 4 * a] = this->vCard_number[i];
							this->sCard_number[a] = this->vCard_number[i];
							this->vCard_number[i] = 0;
							break;
						}
					}
				}
				mark = 1;
			}
			else
			{
				int counter2 = 0, counter3 = 0, counter4 = 0;
				for (int i = 1; i < 14; i++)
				{
					if (this->vCard_color[i] == A[4 * a])
						counter2++;
				}
				for (int i = -1; i >= -8; i--)
				{
					if (A[b + 4 * a + i] == this->auction_color)
					{
						counter4++;
						if (B[b + 4 * a + i] > 8)
							counter3++;
					}
				}
				if (counter2 != 0)
				{
					if (danger != 0)
					{
						if (counter2 > 1)
						{
							if (b > 1)
							{
								if (A[b + 4 * a - 2] == A[4 * a])
								{
									for (int i = 1; i < 14; i++)
									{
										if ((this->vCard_color[i] == A[4 * a]) && (this->vCard_number[i] > B[b + 4 * a - 2]) && (B[b + 4 * a - 2] < B[4 * a]) && (B[b + 4 * a - 2] != 1) == 1)
										{
											A[b + 4 * a] = this->vCard_color[i];
											this->sCard_color[a] = this->vCard_color[i];
											this->vCard_color[i] = 0;
											B[b + 4 * a] = this->vCard_number[i];
											this->sCard_number[a] = this->vCard_number[i];
											this->vCard_number[i] = 0;
											break;
										}
									}
									if (B[b + 4 * a] == 0)
									{
										for (int i = 13; i >= 1; i--)
										{
											if (this->vCard_color[i] == A[4 * a])
											{
												A[b + 4 * a] = this->vCard_color[i];
												this->sCard_color[a] = this->vCard_color[i];
												this->vCard_color[i] = 0;
												B[b + 4 * a] = this->vCard_number[i];
												this->sCard_number[a] = this->vCard_number[i];
												this->vCard_number[i] = 0;
												break;
											}
										}
									}
								}
								else
								{
									if ((C.v_rand_4 == 1) || (C.v_rand_13 == 1) == 1)
									{
										for (int i = 1; i < 14; i++)
										{
											if (this->vCard_color[i] == A[4 * a])
											{
												A[b + 4 * a] = this->vCard_color[i];
												this->sCard_color[a] = this->vCard_color[i];
												this->vCard_color[i] = 0;
												B[b + 4 * a] = this->vCard_number[i];
												this->sCard_number[a] = this->vCard_number[i];
												this->vCard_number[i] = 0;
												break;
											}
										}
									}
									else
									{
										for (int i = 13; i >= 1; i--)
										{
											if (this->vCard_color[i] == A[4 * a])
											{
												A[b + 4 * a] = this->vCard_color[i];
												this->sCard_color[a] = this->vCard_color[i];
												this->vCard_color[i] = 0;
												B[b + 4 * a] = this->vCard_number[i];
												this->sCard_number[a] = this->vCard_number[i];
												this->vCard_number[i] = 0;
												break;
											}
										}
									}
								}
							}
							else
							{
								if ((C.v_rand_4 == 1) || (C.v_rand_10 == 1) == 1)
								{
									for (int i = 1; i < 14; i++)
									{
										if (this->vCard_color[i] == A[4 * a])
										{
											A[b + 4 * a] = this->vCard_color[i];
											this->sCard_color[a] = this->vCard_color[i];
											this->vCard_color[i] = 0;
											B[b + 4 * a] = this->vCard_number[i];
											this->sCard_number[a] = this->vCard_number[i];
											this->vCard_number[i] = 0;
											break;
										}
									}
								}
								else
								{
									for (int i = 13; i >= 1; i--)
									{
										if (this->vCard_color[i] == A[4 * a])
										{
											A[b + 4 * a] = this->vCard_color[i];
											this->sCard_color[a] = this->vCard_color[i];
											this->vCard_color[i] = 0;
											B[b + 4 * a] = this->vCard_number[i];
											this->sCard_number[a] = this->vCard_number[i];
											this->vCard_number[i] = 0;
											break;
										}
									}
								}
							}
						}
						else
						{
							for (int i = 1; i < 14; i++)
							{
								if (this->vCard_color[i] == A[4 * a])
								{
									A[b + 4 * a] = this->vCard_color[i];
									this->sCard_color[a] = this->vCard_color[i];
									this->vCard_color[i] = 0;
									B[b + 4 * a] = this->vCard_number[i];
									this->sCard_number[a] = this->vCard_number[i];
									this->vCard_number[i] = 0;
									break;
								}
							}
						}
					}
					else
					{
						if (counter2 > 1)
						{
							if (b > 1)
							{
								if (A[b + 4 * a - 2] == A[4 * a])
								{
									for (int i = 1; i < 14; i++)
									{
										if ((this->vCard_color[i] == A[4 * a]) && (this->vCard_number[i] > B[b + 4 * a - 2]) && (B[b + 4 * a - 2] < B[4 * a]) && (B[b + 4 * a - 2] != 1) == 1)
										{
											A[b + 4 * a] = this->vCard_color[i];
											this->sCard_color[a] = this->vCard_color[i];
											this->vCard_color[i] = 0;
											B[b + 4 * a] = this->vCard_number[i];
											this->sCard_number[a] = this->vCard_number[i];
											this->vCard_number[i] = 0;
											break;
										}
									}
									if (B[b + 4 * a] == 0)
									{
										for (int i = 13; i >= 1; i--)
										{
											if (this->vCard_color[i] == A[4 * a])
											{
												A[b + 4 * a] = this->vCard_color[i];
												this->sCard_color[a] = this->vCard_color[i];
												this->vCard_color[i] = 0;
												B[b + 4 * a] = this->vCard_number[i];
												this->sCard_number[a] = this->vCard_number[i];
												this->vCard_number[i] = 0;
												break;
											}
										}
									}
								}
								else
								{
									if (C.v_rand_4 == 1)
									{
										for (int i = 1; i < 14; i++)
										{
											if (this->vCard_color[i] == A[4 * a])
											{
												A[b + 4 * a] = this->vCard_color[i];
												this->sCard_color[a] = this->vCard_color[i];
												this->vCard_color[i] = 0;
												B[b + 4 * a] = this->vCard_number[i];
												this->sCard_number[a] = this->vCard_number[i];
												this->vCard_number[i] = 0;
												break;
											}
										}
									}
									else
									{
										for (int i = 13; i >= 1; i--)
										{
											if (this->vCard_color[i] == A[4 * a])
											{
												A[b + 4 * a] = this->vCard_color[i];
												this->sCard_color[a] = this->vCard_color[i];
												this->vCard_color[i] = 0;
												B[b + 4 * a] = this->vCard_number[i];
												this->sCard_number[a] = this->vCard_number[i];
												this->vCard_number[i] = 0;
												break;
											}
										}
									}
								}
							}
							else
							{
								if (C.v_rand_4 == 1)
								{
									for (int i = 1; i < 14; i++)
									{
										if (this->vCard_color[i] == A[4 * a])
										{
											A[b + 4 * a] = this->vCard_color[i];
											this->sCard_color[a] = this->vCard_color[i];
											this->vCard_color[i] = 0;
											B[b + 4 * a] = this->vCard_number[i];
											this->sCard_number[a] = this->vCard_number[i];
											this->vCard_number[i] = 0;
											break;
										}
									}
								}
								else
								{
									for (int i = 13; i >= 1; i--)
									{
										if (this->vCard_color[i] == A[4 * a])
										{
											A[b + 4 * a] = this->vCard_color[i];
											this->sCard_color[a] = this->vCard_color[i];
											this->vCard_color[i] = 0;
											B[b + 4 * a] = this->vCard_number[i];
											this->sCard_number[a] = this->vCard_number[i];
											this->vCard_number[i] = 0;
											break;
										}
									}
								}
							}
						}
						else
						{
							for (int i = 1; i < 14; i++)
							{
								if (this->vCard_color[i] == A[4 * a])
								{
									A[b + 4 * a] = this->vCard_color[i];
									this->sCard_color[a] = this->vCard_color[i];
									this->vCard_color[i] = 0;
									B[b + 4 * a] = this->vCard_number[i];
									this->sCard_number[a] = this->vCard_number[i];
									this->vCard_number[i] = 0;
									break;
								}
							}
						}
					}
					mark = 1;
				}
				else
				{
					if (danger != 0)
					{
						if (counter1 != 0)
						{
							if ((b>1) && (A[b + 4 * a - 2] != this->auction_color) && (counter3 != 0) == 1)
							{
								for (int i = 13; i >= 1; i--)
								{
									if ((this->vCard_color[i] != 0) && (this->vCard_color[i] == this->auction_color) == 1)
									{
										A[b + 4 * a] = this->vCard_color[i];
										this->sCard_color[a] = this->vCard_color[i];
										this->vCard_color[i] = 0;
										B[b + 4 * a] = this->vCard_number[i];
										this->sCard_number[a] = this->vCard_number[i];
										this->vCard_number[i] = 0;
										break;
									}
									if (B[b + 4 * a] == 0)
									{
										for (int i = 13; i >= 1; i--)
										{
											if (this->vCard_color[i] == A[4 * a])
											{
												A[b + 4 * a] = this->vCard_color[i];
												this->sCard_color[a] = this->vCard_color[i];
												this->vCard_color[i] = 0;
												B[b + 4 * a] = this->vCard_number[i];
												this->sCard_number[a] = this->vCard_number[i];
												this->vCard_number[i] = 0;
												break;
											}
										}
									}
								}
								mark = 1;
							}
							else
							{
								for (int i = 13; i >= 1; i--)
								{
									if ((this->vCard_color[i] != 0) && (this->vCard_color[i] != this->auction_color) == 1)
									{
										A[b + 4 * a] = this->vCard_color[i];
										this->sCard_color[a] = this->vCard_color[i];
										this->vCard_color[i] = 0;
										B[b + 4 * a] = this->vCard_number[i];
										this->sCard_number[a] = this->vCard_number[i];
										this->vCard_number[i] = 0;
										break;
									}
									if (B[b + 4 * a] == 0)
									{
										for (int i = 13; i >= 1; i--)
										{
											if (this->vCard_color[i] == A[4 * a])
											{
												A[b + 4 * a] = this->vCard_color[i];
												this->sCard_color[a] = this->vCard_color[i];
												this->vCard_color[i] = 0;
												B[b + 4 * a] = this->vCard_number[i];
												this->sCard_number[a] = this->vCard_number[i];
												this->vCard_number[i] = 0;
												break;
											}
										}
									}
								}
							}
						}
						else
						{
							for (int i = 13; i >= 1; i--)
							{
								if (this->vCard_color[i] != 0)
								{
									A[b + 4 * a] = this->vCard_color[i];
									this->sCard_color[a] = this->vCard_color[i];
									this->vCard_color[i] = 0;
									B[b + 4 * a] = this->vCard_number[i];
									this->sCard_number[a] = this->vCard_number[i];
									this->vCard_number[i] = 0;
									break;
								}
							}
						}
					}
					else
					{
						for (int i = 13; i >= 1; i--)
						{
							if ((this->vCard_color[i] != 0) && (this->vCard_color[i] != this->auction_color) == 1)
							{
								A[b + 4 * a] = this->vCard_color[i];
								this->sCard_color[a] = this->vCard_color[i];
								this->vCard_color[i] = 0;
								B[b + 4 * a] = this->vCard_number[i];
								this->sCard_number[a] = this->vCard_number[i];
								this->vCard_number[i] = 0;
								break;
							}
							if (B[b + 4 * a] == 0)
							{
								for (int i = 13; i >= 1; i--)
								{
									if (this->vCard_color[i] == A[4 * a])
									{
										A[b + 4 * a] = this->vCard_color[i];
										this->sCard_color[a] = this->vCard_color[i];
										this->vCard_color[i] = 0;
										B[b + 4 * a] = this->vCard_number[i];
										this->sCard_number[a] = this->vCard_number[i];
										this->vCard_number[i] = 0;
										break;
									}
								}
							}
						}
					}
				}
			}
		}
		//small
		else
		{
			int small_color[13], small_number[13];
			for (int i = 0; i < 13; i++)
			{
				small_color[i] = this->vCard_color[i + 1];
				small_number[i] = this->vCard_number[i + 1];
			}
			for (int i = 1; i < 13; i++)
			{
				int temp1, temp2, temp3;
				temp3 = i;
				do
				{
					if ((small_number[i] < small_number[i - 1]) || (small_number[i - 1] == 1) == 1)
					{
						temp1 = small_number[i];
						temp2 = small_color[i];
						small_number[i] = small_number[i - 1];
						small_color[i] = small_color[i - 1];
						small_number[i - 1] = temp1;
						small_color[i - 1] = temp2;
						if (i > 1)
							i--;
						else
							break;
					}
					else
						break;
				} while ((small_number[i] < small_number[i + 1]) || (small_number[i - 1] == 1) == 1);
				i = temp3;
			}
			//���Ĥ@�ӥX�P��
			if (b == 0)
			{
				//�@�ߥX�̤j�P
				for (int i = 0; i < 13; i++)
				{
					if (small_number[i] != 0)
					{
						A[b + 4 * a] = small_color[i];
						this->sCard_color[a] = small_color[i];
						B[b + 4 * a] = small_number[i];
						this->sCard_number[a] = small_number[i];
						for (int j = 0; j < 13; j++)
						{
							if ((small_color[i] == this->vCard_color[j + 1]) && (small_number[i] == this->vCard_number[j + 1]) == 1)
							{
								this->vCard_color[j + 1] = 0;
								this->vCard_number[j + 1] = 0;
							}
						}
						break;
					}
				}
				mark = 1;
			}
			else
			{
				int counter = 0, counter2 = 0;
				//���P�_��W�O�_���Mdeclarer�ҥX�����ۦP���P
				for (int i = 0; i < 13; i++)
				{
					if (small_color[i] == A[4 * a])
					{
						counter++;
						if (small_number[i] > B[4 * a])
							counter2++;
					}
				}
				if (counter != 0)
				{
					int counter3 = 0;
					for (int i = 0; i > -8; i--)
					{
						if (b - 1 + 4 * a >= 0)
						{
							if (A[b - 1 + 4 * a] == A[4 * a])
							{
								if (A[b - 1 + 4 * a] > A[4 * a])
									counter3++;
							}
						}
					}
					//�p�G�⤤���P�����Ldeclarer�ҥX���P
					if (counter2 != 0)
					{
						//�p�G�w���H�X�L�����Ldeclarer�ҥX���P,true�����ΤU�i�H�Ҽ{�n���X�P
						if (counter3 != 0)
						{
							for (int i = 0; i < 13; i++)
							{
								if (small_color[i] == A[4 * a])
								{
									A[b + 4 * a] = small_color[i];
									this->sCard_color[a] = small_color[i];
									B[b + 4 * a] = small_number[i];
									this->sCard_number[a] = small_number[i];
									for (int j = 0; j < 13; j++)
									{
										if ((small_color[i] == this->vCard_color[j + 1]) && (small_number[i] == this->vCard_number[j + 1]) == 1)
										{
											this->vCard_color[j + 1] = 0;
											this->vCard_number[j + 1] = 0;
										}
									}
									break;
								}
							}
						}
						else
						{
							if (counter > 1)
							{
								if (a > 7)
								{
									if (b > 1)
									{
										if (A[b + 4 * a - 2] == A[4 * a])
										{
											for (int i = 0; i < 13; i++)
											{
												if ((small_color[i] == A[4 * a]) && (small_number[i] < B[b + 4 * a - 2]) && (B[b + 4 * a - 2] > B[4 * a]) && (B[b + 4 * a - 2] != 2) == 1)
												{
													A[b + 4 * a] = small_color[i];
													this->sCard_color[a] = small_color[i];
													B[b + 4 * a] = small_number[i];
													this->sCard_number[a] = small_number[i];
													for (int j = 0; j < 13; j++)
													{
														if ((small_color[i] == this->vCard_color[j + 1]) && (small_number[i] == this->vCard_number[j + 1]) == 1)
														{
															this->vCard_color[j + 1] = 0;
															this->vCard_number[j + 1] = 0;
														}
													}
													break;
												}
											}
											if (B[b + 4 * a] == 0)
											{
												for (int i = 12; i >= 0; i--)
												{
													A[b + 4 * a] = small_color[i];
													this->sCard_color[a] = small_color[i];
													B[b + 4 * a] = small_number[i];
													this->sCard_number[a] = small_number[i];
													for (int j = 0; j < 13; j++)
													{
														if ((small_color[i] == this->vCard_color[j + 1]) && (small_number[i] == this->vCard_number[j + 1]) == 1)
														{
															this->vCard_color[j + 1] = 0;
															this->vCard_number[j + 1] = 0;
														}
													}
													break;
												}
											}
										}
										else
										{
											for (int i = 0; i < 13; i++)
											{
												if (small_color[i] == A[4 * a])
												{
													A[b + 4 * a] = small_color[i];
													this->sCard_color[a] = small_color[i];
													B[b + 4 * a] = small_number[i];
													this->sCard_number[a] = small_number[i];
													for (int j = 0; j < 13; j++)
													{
														if ((small_color[i] == this->vCard_color[j + 1]) && (small_number[i] == this->vCard_number[j + 1]) == 1)
														{
															this->vCard_color[j + 1] = 0;
															this->vCard_number[j + 1] = 0;
														}
													}
													break;
												}
											}
										}
									}
									else
									{
										//�@�b���v�X�P���̤j�P,�Φ��j�P
										if (C.v_rand_1 || C.v_rand_2 == 1)
										{
											for (int i = 0; i < 13; i++)
											{
												if (small_color[i] == A[4 * a])
												{
													A[b + 4 * a] = small_color[i];
													this->sCard_color[a] = small_color[i];
													B[b + 4 * a] = small_number[i];
													this->sCard_number[a] = small_number[i];
													for (int j = 0; j < 13; j++)
													{
														if ((small_color[i] == this->vCard_color[j + 1]) && (small_number[i] == this->vCard_number[j + 1]) == 1)
														{
															this->vCard_color[j + 1] = 0;
															this->vCard_number[j + 1] = 0;
														}
													}
													break;
												}
											}
										}
										else
										{
											int counter4 = 0;
											for (int i = 0; i < 13; i++)
											{
												if (small_color[i] == A[4 * a])
												{
													counter4++;
													if (counter4 == 1)
													{
														A[b + 4 * a] = small_color[i];
														this->sCard_color[a] = small_color[i];
														B[b + 4 * a] = small_number[i];
														this->sCard_number[a] = small_number[i];
														for (int j = 0; j < 13; j++)
														{
															if ((small_color[i] == this->vCard_color[j + 1]) && (small_number[i] == this->vCard_number[j + 1]) == 1)
															{
																this->vCard_color[j + 1] = 0;
																this->vCard_number[j + 1] = 0;
															}
														}
														break;
													}
												}
											}
										}
									}
									//7��5���v�X�P���̤j�P,�Φ��j�P
								}
								else
								{
									if (b > 1)
									{
										if (A[b + 4 * a - 2] == A[4 * a])
										{
											for (int i = 0; i < 13; i++)
											{
												if ((small_color[i] == A[4 * a]) && (small_number[i] < B[b + 4 * a - 2]) && (B[b + 4 * a - 2] > B[4 * a]) == 1)
												{
													A[b + 4 * a] = small_color[i];
													this->sCard_color[a] = small_color[i];
													B[b + 4 * a] = small_number[i];
													this->sCard_number[a] = small_number[i];
													for (int j = 0; j < 13; j++)
													{
														if ((small_color[i] == this->vCard_color[j + 1]) && (small_number[i] == this->vCard_number[j + 1]) == 1)
														{
															this->vCard_color[j + 1] = 0;
															this->vCard_number[j + 1] = 0;
														}
													}
													break;
												}
											}
											if (B[b + 4 * a] == 0)
											{
												for (int i = 12; i >= 0; i--)
												{
													A[b + 4 * a] = small_color[i];
													this->sCard_color[a] = small_color[i];
													B[b + 4 * a] = small_number[i];
													this->sCard_number[a] = small_number[i];
													for (int j = 0; j < 13; j++)
													{
														if ((small_color[i] == this->vCard_color[j + 1]) && (small_number[i] == this->vCard_number[j + 1]) == 1)
														{
															this->vCard_color[j + 1] = 0;
															this->vCard_number[j + 1] = 0;
														}
													}
													break;
												}
											}
										}
										else
										{
											for (int i = 0; i < 13; i++)
											{
												if (small_color[i] == A[4 * a])
												{
													A[b + 4 * a] = small_color[i];
													this->sCard_color[a] = small_color[i];
													B[b + 4 * a] = small_number[i];
													this->sCard_number[a] = small_number[i];
													for (int j = 0; j < 13; j++)
													{
														if ((small_color[i] == this->vCard_color[j + 1]) && (small_number[i] == this->vCard_number[j + 1]) == 1)
														{
															this->vCard_color[j + 1] = 0;
															this->vCard_number[j + 1] = 0;
														}
													}
													break;
												}
											}
										}
									}
									else
									{
										//�@�b���v�X�P���̤j�P,�Φ��j�P
										if (C.v_rand_1 == 1)
										{
											for (int i = 0; i < 13; i++)
											{
												if (small_color[i] == A[4 * a])
												{
													A[b + 4 * a] = small_color[i];
													this->sCard_color[a] = small_color[i];
													B[b + 4 * a] = small_number[i];
													this->sCard_number[a] = small_number[i];
													for (int j = 0; j < 13; j++)
													{
														if ((small_color[i] == this->vCard_color[j + 1]) && (small_number[i] == this->vCard_number[j + 1]) == 1)
														{
															this->vCard_color[j + 1] = 0;
															this->vCard_number[j + 1] = 0;
														}
													}
													break;
												}
											}
										}
										else
										{
											int counter4 = 0;
											for (int i = 0; i < 13; i++)
											{
												if (small_color[i] == A[4 * a])
												{
													counter4++;
													if (counter4 == 1)
													{
														A[b + 4 * a] = small_color[i];
														this->sCard_color[a] = small_color[i];
														B[b + 4 * a] = small_number[i];
														this->sCard_number[a] = small_number[i];
														for (int j = 0; j < 13; j++)
														{
															if ((small_color[i] == this->vCard_color[j + 1]) && (small_number[i] == this->vCard_number[j + 1]) == 1)
															{
																this->vCard_color[j + 1] = 0;
																this->vCard_number[j + 1] = 0;
															}
														}
														break;
													}
												}
											}
										}
									}
								}
							}
							else
							{
								for (int i = 0; i < 13; i++)
								{
									if (small_color[i] == A[4 * a])
									{
										A[b + 4 * a] = small_color[i];
										this->sCard_color[a] = small_color[i];
										B[b + 4 * a] = small_number[i];
										this->sCard_number[a] = small_number[i];
										for (int j = 0; j < 13; j++)
										{
											if ((small_color[i] == this->vCard_color[j + 1]) && (small_number[i] == this->vCard_number[j + 1]) == 1)
											{
												this->vCard_color[j + 1] = 0;
												this->vCard_number[j + 1] = 0;
											}
										}
										break;
									}
								}
							}
						}
					}
					else
					{
						//�X�P���Ʀr�̤p���@�i
						for (int i = 12; i >= 0; i--)
						{
							if (small_color[i] == A[4 * a])
							{
								A[b + 4 * a] = small_color[i];
								this->sCard_color[a] = small_color[i];
								B[b + 4 * a] = small_number[i];
								this->sCard_number[a] = small_number[i];
								for (int j = 0; j < 13; j++)
								{
									if ((small_color[i] == this->vCard_color[j + 1]) && (small_number[i] == this->vCard_number[j + 1]) == 1)
									{
										this->vCard_color[j + 1] = 0;
										this->vCard_number[j + 1] = 0;
									}
								}
								break;
							}
						}
					}
					mark = 1;
				}
				else
				{
					//�X�⤤�Ʀr�̤p���N���
					for (int i = 12; i >= 0; i--)
					{
						if (small_number[i] != 0)
						{
							A[b + 4 * a] = small_color[i];
							this->sCard_color[a] = small_color[i];
							B[b + 4 * a] = small_number[i];
							this->sCard_number[a] = small_number[i];
							for (int j = 0; j < 13; j++)
							{
								if ((small_color[i] == this->vCard_color[j + 1]) && (small_number[i] == this->vCard_number[j + 1]) == 1)
								{
									this->vCard_color[j + 1] = 0;
									this->vCard_number[j + 1] = 0;
								}
							}
							break;
						}
					}
				}
			}
		}
	}
	//smart==1
	else
	{

	}
	//cout and define the colutions
	if (c == 0)
	{
		if (b == 0)
		{
			if (this->sCard_color[a] == 1)
				cout << "Player3�X�®�" << this->sCard_number[a] << endl;
			else if (this->sCard_color[a] == 2)
				cout << "Player3�X����" << this->sCard_number[a] << endl;
			else if (this->sCard_color[a] == 3)
				cout << "Player3�X���" << this->sCard_number[a] << endl;
			else if (this->sCard_color[a] == 4)
				cout << "Player3�X����" << this->sCard_number[a] << endl;
			else
				return NULL;
		}
		else if (b == 1)
		{
			if (this->sCard_color[a] == 1)
				cout << "Player2�X�®�" << this->sCard_number[a] << endl;
			else if (this->sCard_color[a] == 2)
				cout << "Player2�X����" << this->sCard_number[a] << endl;
			else if (this->sCard_color[a] == 3)
				cout << "Player2�X���" << this->sCard_number[a] << endl;
			else if (this->sCard_color[a] == 4)
				cout << "Player2�X����" << this->sCard_number[a] << endl;
			else
				return NULL;
		}
		else
		{
			if (this->sCard_color[a] == 1)
				cout << "Player4�X�®�" << this->sCard_number[a] << endl;
			else if (this->sCard_color[a] == 2)
				cout << "Player4�X����" << this->sCard_number[a] << endl;
			else if (this->sCard_color[a] == 3)
				cout << "Player4�X���" << this->sCard_number[a] << endl;
			else if (this->sCard_color[a] == 4)
				cout << "Player4�X����" << this->sCard_number[a] << endl;
			else
				return NULL;
		}
	}
	else if (c == 1)
	{
		if (b == 0)
		{
			if (this->sCard_color[a] == 1)
				cout << "Player2�X�®�" << this->sCard_number[a] << endl;
			else if (this->sCard_color[a] == 2)
				cout << "Player2�X����" << this->sCard_number[a] << endl;
			else if (this->sCard_color[a] == 3)
				cout << "Player2�X���" << this->sCard_number[a] << endl;
			else if (this->sCard_color[a] == 4)
				cout << "Player2�X����" << this->sCard_number[a] << endl;
			else
				return NULL;
		}
		else if (b == 1)
		{
			if (this->sCard_color[a] == 1)
				cout << "Player4�X�®�" << this->sCard_number[a] << endl;
			else if (this->sCard_color[a] == 2)
				cout << "Player4�X����" << this->sCard_number[a] << endl;
			else if (this->sCard_color[a] == 3)
				cout << "Player4�X���" << this->sCard_number[a] << endl;
			else if (this->sCard_color[a] == 4)
				cout << "Player4�X����" << this->sCard_number[a] << endl;
			else
				return NULL;
		}
		else
		{
			if (this->sCard_color[a] == 1)
				cout << "Player3�X�®�" << this->sCard_number[a] << endl;
			else if (this->sCard_color[a] == 2)
				cout << "Player3�X����" << this->sCard_number[a] << endl;
			else if (this->sCard_color[a] == 3)
				cout << "Player3�X���" << this->sCard_number[a] << endl;
			else if (this->sCard_color[a] == 4)
				cout << "Player3�X����" << this->sCard_number[a] << endl;
			else
				return NULL;
		}
	}
	else if (c == 2)
	{
		if (b == 0)
		{
			if (this->sCard_color[a] == 1)
				cout << "Player4�X�®�" << this->sCard_number[a] << endl;
			else if (this->sCard_color[a] == 2)
				cout << "Player4�X����" << this->sCard_number[a] << endl;
			else if (this->sCard_color[a] == 3)
				cout << "Player4�X���" << this->sCard_number[a] << endl;
			else if (this->sCard_color[a] == 4)
				cout << "Player4�X����" << this->sCard_number[a] << endl;
			else
				return NULL;
		}
		else if (b == 2)
		{
			if (this->sCard_color[a] == 1)
				cout << "Player3�X�®�" << this->sCard_number[a] << endl;
			else if (this->sCard_color[a] == 2)
				cout << "Player3�X����" << this->sCard_number[a] << endl;
			else if (this->sCard_color[a] == 3)
				cout << "Player3�X���" << this->sCard_number[a] << endl;
			else if (this->sCard_color[a] == 4)
				cout << "Player3�X����" << this->sCard_number[a] << endl;
			else
				return NULL;
		}
		else
		{
			if (this->sCard_color[a] == 1)
				cout << "Player2�X�®�" << this->sCard_number[a] << endl;
			else if (this->sCard_color[a] == 2)
				cout << "Player2�X����" << this->sCard_number[a] << endl;
			else if (this->sCard_color[a] == 3)
				cout << "Player2�X���" << this->sCard_number[a] << endl;
			else if (this->sCard_color[a] == 4)
				cout << "Player2�X����" << this->sCard_number[a] << endl;
			else
				return NULL;
		}
	}
	else
	{
		if (b == 1)
		{
			if (this->sCard_color[a] == 1)
				cout << "Player3�X�®�" << this->sCard_number[a] << endl;
			else if (this->sCard_color[a] == 2)
				cout << "Player3�X����" << this->sCard_number[a] << endl;
			else if (this->sCard_color[a] == 3)
				cout << "Player3�X���" << this->sCard_number[a] << endl;
			else if (this->sCard_color[a] == 4)
				cout << "Player3�X����" << this->sCard_number[a] << endl;
			else
				return NULL;
		}
		else if (b == 2)
		{
			if (this->sCard_color[a] == 1)
				cout << "Player2�X�®�" << this->sCard_number[a] << endl;
			else if (this->sCard_color[a] == 2)
				cout << "Player2�X����" << this->sCard_number[a] << endl;
			else if (this->sCard_color[a] == 3)
				cout << "Player2�X���" << this->sCard_number[a] << endl;
			else if (this->sCard_color[a] == 4)
				cout << "Player2�X����" << this->sCard_number[a] << endl;
			else
				return NULL;
		}
		else
		{
			if (this->sCard_color[a] == 1)
				cout << "Player4�X�®�" << this->sCard_number[a] << endl;
			else if (this->sCard_color[a] == 2)
				cout << "Player4�X����" << this->sCard_number[a] << endl;
			else if (this->sCard_color[a] == 3)
				cout << "Player4�X���" << this->sCard_number[a] << endl;
			else if (this->sCard_color[a] == 4)
				cout << "Player4�X����" << this->sCard_number[a] << endl;
			else
				return NULL;
		}
	}
	return mark;
}
int Game::Process::Difficulty_setting(
	Game &A,
	Game::Process::AI &B,
	Game::Process::AI &C,
	Game::Process::AI &D)
{
	fun_explanation1();
	int binary[3];
	A.set_data1();
	//�H�W�Ω��ӹC���L�{���i��|�J�쪺�H�����
	funb(binary);
	B.set_player2_smart(binary[2], binary[1], binary[0]);
	C.set_player3_smart(binary[2], binary[1], binary[0]);
	D.set_player4_smart(binary[2], binary[1], binary[0]);
	//smart=0,1�N�|�M�wchoose_color()�Mselect_card()�b�B��ɪ��M��
	fun_explanation1_1();
	return NULL;
}
int Game::Process::Set_up(
	Game &A,
	Game::Process::User &B,
	Game::Process::AI &C,
	Game::Process::AI &D,
	Game::Process::AI &E,
	Game::Process::AI::color &F,
	Game::Process::AI::color &G,
	Game::Process::AI::color &H,
	Game::Process::AI::color &I)
{
	int temp = 0;
	int temp1 = 0;
	fun_explanation2();
	do
	{
		temp1++; //�Ψ�trace�O�_AI�u�����˵P�N�@
				 //�H�U�Ψӫإߤ�P
		A.set_data3();
		A.dealing(B, C, D, E);
		B.set_data_card();
		C.set_data_card();
		D.set_data_card();
		E.set_data_card();
		//�H�U�O��AI����P���PŪ�H���o�������Ѽ�,
		C.reset_data(F, G, H, I);
		C.set_data0();
		C.set_data1(F, G, H, I);
		C.set_data2(F, G, H, I);
		C.set_data3(F, G, H, I);
		C.set_data4(F, G, H, I);
		temp = C.redo(A, F, G, H, I);
		if (temp == 1)
			continue;
		D.reset_data(F, G, H, I);
		D.set_data0();
		D.set_data1(F, G, H, I);
		D.set_data2(F, G, H, I);
		D.set_data3(F, G, H, I);
		D.set_data4(F, G, H, I);
		temp = D.redo(A, F, G, H, I);
		if (temp == 1)
			continue;
		E.reset_data(F, G, H, I);
		E.set_data0();
		E.set_data1(F, G, H, I);
		E.set_data2(F, G, H, I);
		E.set_data3(F, G, H, I);
		E.set_data4(F, G, H, I);
		temp = E.redo(A, F, G, H, I);
		if (temp == 1)
			continue;
		//cout << temp1 << endl;
		temp = B.redo(B);
	} while (temp == 1);
	return NULL;
	/*
	����,
	�ǥ�get_data_card()��playerX.vCard[]�s��playerX_card[]����

	��Ҧ���playerX.vCard[]�PŪ:
	(1)4�ت����O���h��
	(2)��P���I��(�̾�player��smart�N�|�M�w�O�_�n�˵P,���|�N�|�v�Tchoose_color()�����G
	�u��player1.vCard[]����:
	(1)�̪��,�I�ƱƧ�
	(2)��ܱƧǦn����P��ù��W

	�T�{���˵P��,
	�ﰣ�Fplayer1.vCard[]����lvCard[]�PŪ:
	(1)�̪��,�I�ƶi��Ƨ�(�ϥΨ��for���O�ƪ��M�Ʀr),�ðO���̦h�i��,���h,����̤�,���O������
	Ex:
	playerX_max_color='s'
	playerX_second_color='h'
	playerX_third_color='d'
	playerX_min_color='c'
	(2)��U���]�w���v���Ѽ�,�C�@���Ҧ�3�ӰѼ�
	Ex:
	playerX_max_color_big_point
	playerX_max_color_small_point
	playerX_max_color_number

	�̫�,
	�����`�@��(3+1)*4*3=48�ӰѼ�,�o�ǰѼƱN�Ω�"�s�P"���q�M"�X�P"���q
	*/
}
int Game::Process::Auction(
	Game &A,
	Game::Process::User &B,
	Game::Process::AI &C,
	Game::Process::AI &D,
	Game::Process::AI &E,
	Game::Process::AI::color &F,
	Game::Process::AI::color &G,
	Game::Process::AI::color &H,
	Game::Process::AI::color &I)
{
	int accept = 0;
	int counter = 0; //counter�ΥH�O���ĴX��۪��
	int counter_stop = 0;
	int temp = 0, temp1 = 0; //�O���`�@run�F�X��
	this->sequence = 0;
	this->selector = 0;
	B.id = 1;
	C.id = 2;
	D.id = 3;
	E.id = 4;
	//�H�U���w�]�}�C����l��
	for (int j = 0; j < 40; j++)
	{
		this->auction_color[j] = 7;
		this->auction_number[j] = 0;
	}
	fun_explanation3();
	do
	{
		//���ɰw���ର3,2,4,1=D,C,E,B
		if (counter != 0)
			counter++;
		temp1 = D.choose_color(accept, counter, counter_stop, this->sequence, this->selector, this->auction_color, this->auction_number, A, F, G, H, I);
		if (temp1 == 1)
		{
			accept++;
			if (accept == 1)
				counter_stop = counter - 1;
		}
		else
		{
			accept = 0;
			counter_stop = 0;
		}
		if (accept == 3)
		{
			this->sequence = counter_stop;
			this->selector = counter_stop;
			break;
		}
		counter++;
		temp1 = C.choose_color(accept, counter, counter_stop, this->sequence, this->selector, this->auction_color, this->auction_number, A, F, G, H, I);
		if (temp1 == 1)
		{
			accept++;
			if (accept == 1)
				counter_stop = counter - 1;
		}
		else
		{
			accept = 0;
			counter_stop = 0;
		}
		if (accept == 3)
		{
			this->sequence = counter_stop;
			this->selector = counter_stop;
			break;
		}
		counter++;
		temp1 = E.choose_color(accept, counter, counter_stop, this->sequence, this->selector, this->auction_color, this->auction_number, A, F, G, H, I);
		if (temp1 == 1)
		{
			accept++;
			if (accept == 1)
				counter_stop = counter - 1;
		}
		else
		{
			accept = 0;
			counter_stop = 0;
		}
		if (accept == 3)
		{
			this->sequence = counter_stop;
			this->selector = counter_stop;
			break;
		}
		counter++;
		temp1 = B.choose_color(accept, counter, counter_stop, this->sequence, this->selector, this->auction_color, this->auction_number);
		if (temp1 == 1)
		{
			accept++;
			if (accept == 1)
				counter_stop = counter - 1;
		}
		else
		{
			accept = 0;
			counter_stop = 0;
		}
		if (accept < 3)
			temp++;
	} while (accept < 3);
	C.set_data5(counter_stop, this->sequence, this->selector, this->auction_color, this->auction_number);
	D.set_data5(counter_stop, this->sequence, this->selector, this->auction_color, this->auction_number);
	E.set_data5(counter_stop, this->sequence, this->selector, this->auction_color, this->auction_number);
	B.set_data(counter_stop, this->sequence, this->selector, this->auction_color, this->auction_number);
	this->funa(temp, this->sequence, this->selector, counter, counter_stop, this->auction_color, this->auction_number);//�N�Jtemp,sequence,selector
	fun_explanation3_1(temp, counter_stop, this->sequence, this->selector, this->auction_color, this->auction_number);
	return NULL;
}
int Game::Process::Play(
	Game &A,
	Game::Process::User &B,
	Game::Process::AI &C,
	Game::Process::AI &D,
	Game::Process::AI &E,
	Game::Process::AI::color &F,
	Game::Process::AI::color &G,
	Game::Process::AI::color &H,
	Game::Process::AI::color &I)
{
	//���ɰw���ର3,2,4,1=D,C,E,B
	fun_explanation4();
	cout << "+------------------------------+" << endl;
	B.show_card1();

	int mark1, mark2, mark3, mark4, mark5 = 0;
	int temp = 0, temp1 = 0;
	int j;
	B.bid = 0;
	C.bid = 0;
	D.bid = 0;
	E.bid = 0;
	for (int i = 0; i < 52; i++)
	{
		this->play_color[i] = 0;
		this->play_number[i] = 0;
	}
	for (int i = 0; i < 13; i++)
	{
		j = 0, mark1 = 0, mark2 = 0, mark3 = 0, mark4 = 0;
		cout << "+------------------------------+" << endl;
		B.show_card2();
		cout << "+------------------------------+" << endl;
		/*�H�U��������l�]�p,�b�̫�@���ɦ۰ʥX�P
		if (i == 12)
		{
		if (this->sequence == 0)
		{
		//mark1 = D.select_card();
		//mark2 = C.select_card();
		//mark3 = E.select_card();
		//mark4 = B.select_card();
		this->play_color[j + 4 * i] = D.vCard_color[i];
		j++;

		j++;
		if (mark2 == 1)
		temp1++;

		j++;
		if (mark3 == 1)
		temp1++;

		if (mark4 == 1)
		temp1++;
		}
		else if (this->sequence == 1)
		{

		j++;

		j++;
		if (mark2 == 1)
		temp1++;

		j++;
		if (mark3 == 1)
		temp1++;

		if (mark4 == 1)
		temp1++;
		}
		else if (this->sequence == 2)
		{

		j++;

		j++;
		if (mark2 == 1)
		temp1++;

		j++;
		if (mark3 == 1)
		temp1++;

		if (mark4 == 1)
		temp1++;
		}
		else
		{

		j++;

		j++;
		if (mark2 == 1)
		temp1++;

		j++;
		if (mark3 == 1)
		temp1++;

		if (mark4 == 1)
		temp1++;
		}
		}
		else
		{
		if (this->sequence == 0)
		{
		mark1 = D.select_card(i, j, this->sequence, B.bid, C.bid, D.bid, E.bid, this->final_number, this->selector, this->play_color, this->play_number, A, F, G, H, I);
		j++;
		mark2 = C.select_card(i, j, this->sequence, B.bid, C.bid, D.bid, E.bid, this->final_number, this->selector, this->play_color, this->play_number, A, F, G, H, I);
		j++;
		if (mark2 == 1)
		temp1++;
		mark3 = E.select_card(i, j, this->sequence, B.bid, C.bid, D.bid, E.bid, this->final_number, this->selector, this->play_color, this->play_number, A, F, G, H, I);
		j++;
		if (mark3 == 1)
		temp1++;
		mark4 = B.select_card(i, j, temp, this->play_color, this->play_number);
		if (mark4 == 1)
		temp1++;
		}
		else if (this->sequence == 1)
		{
		mark1 = C.select_card(i, j, this->sequence, B.bid, C.bid, D.bid, E.bid, this->final_number, this->selector, this->play_color, this->play_number, A, F, G, H, I);
		j++;
		mark2 = E.select_card(i, j, this->sequence, B.bid, C.bid, D.bid, E.bid, this->final_number, this->selector, this->play_color, this->play_number, A, F, G, H, I);
		j++;
		if (mark2 == 1)
		temp1++;
		mark3 = B.select_card(i, j, temp, this->play_color, this->play_number);
		j++;
		if (mark3 == 1)
		temp1++;
		mark4 = D.select_card(i, j, this->sequence, B.bid, C.bid, D.bid, E.bid, this->final_number, this->selector, this->play_color, this->play_number, A, F, G, H, I);
		if (mark4 == 1)
		temp1++;
		}
		else if (this->sequence == 2)
		{
		mark1 = E.select_card(i, j, this->sequence, B.bid, C.bid, D.bid, E.bid, this->final_number, this->selector, this->play_color, this->play_number, A, F, G, H, I);
		j++;
		mark2 = B.select_card(i, j, temp, this->play_color, this->play_number);
		j++;
		if (mark2 == 1)
		temp1++;
		mark3 = D.select_card(i, j, this->sequence, B.bid, C.bid, D.bid, E.bid, this->final_number, this->selector, this->play_color, this->play_number, A, F, G, H, I);
		j++;
		if (mark3 == 1)
		temp1++;
		mark4 = C.select_card(i, j, this->sequence, B.bid, C.bid, D.bid, E.bid, this->final_number, this->selector, this->play_color, this->play_number, A, F, G, H, I);
		if (mark4 == 1)
		temp1++;
		}
		else
		{
		mark1 = B.select_card(i, j, temp, this->play_color, this->play_number);
		j++;
		mark2 = D.select_card(i, j, this->sequence, B.bid, C.bid, D.bid, E.bid, this->final_number, this->selector, this->play_color, this->play_number, A, F, G, H, I);
		j++;
		if (mark2 == 1)
		temp1++;
		mark3 = C.select_card(i, j, this->sequence, B.bid, C.bid, D.bid, E.bid, this->final_number, this->selector, this->play_color, this->play_number, A, F, G, H, I);
		j++;
		if (mark3 == 1)
		temp1++;
		mark4 = E.select_card(i, j, this->sequence, B.bid, C.bid, D.bid, E.bid, this->final_number, this->selector, this->play_color, this->play_number, A, F, G, H, I);
		if (mark4 == 1)
		temp1++;
		}
		}
		*/
		if (this->sequence == 0)
		{
			mark1 = D.select_card(i, j, this->sequence, B.bid, C.bid, D.bid, E.bid, this->final_number, this->selector, this->play_color, this->play_number, A, F, G, H, I);
			j++;
			mark2 = C.select_card(i, j, this->sequence, B.bid, C.bid, D.bid, E.bid, this->final_number, this->selector, this->play_color, this->play_number, A, F, G, H, I);
			j++;
			if (mark2 == 1)
				temp1++;
			mark3 = E.select_card(i, j, this->sequence, B.bid, C.bid, D.bid, E.bid, this->final_number, this->selector, this->play_color, this->play_number, A, F, G, H, I);
			j++;
			if (mark3 == 1)
				temp1++;
			mark4 = B.select_card(i, j, temp, this->play_color, this->play_number);
			if (mark4 == 1)
				temp1++;
		}
		else if (this->sequence == 1)
		{
			mark1 = C.select_card(i, j, this->sequence, B.bid, C.bid, D.bid, E.bid, this->final_number, this->selector, this->play_color, this->play_number, A, F, G, H, I);
			j++;
			mark2 = E.select_card(i, j, this->sequence, B.bid, C.bid, D.bid, E.bid, this->final_number, this->selector, this->play_color, this->play_number, A, F, G, H, I);
			j++;
			if (mark2 == 1)
				temp1++;
			mark3 = B.select_card(i, j, temp, this->play_color, this->play_number);
			j++;
			if (mark3 == 1)
				temp1++;
			mark4 = D.select_card(i, j, this->sequence, B.bid, C.bid, D.bid, E.bid, this->final_number, this->selector, this->play_color, this->play_number, A, F, G, H, I);
			if (mark4 == 1)
				temp1++;
		}
		else if (this->sequence == 2)
		{
			mark1 = E.select_card(i, j, this->sequence, B.bid, C.bid, D.bid, E.bid, this->final_number, this->selector, this->play_color, this->play_number, A, F, G, H, I);
			j++;
			mark2 = B.select_card(i, j, temp, this->play_color, this->play_number);
			j++;
			if (mark2 == 1)
				temp1++;
			mark3 = D.select_card(i, j, this->sequence, B.bid, C.bid, D.bid, E.bid, this->final_number, this->selector, this->play_color, this->play_number, A, F, G, H, I);
			j++;
			if (mark3 == 1)
				temp1++;
			mark4 = C.select_card(i, j, this->sequence, B.bid, C.bid, D.bid, E.bid, this->final_number, this->selector, this->play_color, this->play_number, A, F, G, H, I);
			if (mark4 == 1)
				temp1++;
		}
		else
		{
			mark1 = B.select_card(i, j, temp, this->play_color, this->play_number);
			j++;
			mark2 = D.select_card(i, j, this->sequence, B.bid, C.bid, D.bid, E.bid, this->final_number, this->selector, this->play_color, this->play_number, A, F, G, H, I);
			j++;
			if (mark2 == 1)
				temp1++;
			mark3 = C.select_card(i, j, this->sequence, B.bid, C.bid, D.bid, E.bid, this->final_number, this->selector, this->play_color, this->play_number, A, F, G, H, I);
			j++;
			if (mark3 == 1)
				temp1++;
			mark4 = E.select_card(i, j, this->sequence, B.bid, C.bid, D.bid, E.bid, this->final_number, this->selector, this->play_color, this->play_number, A, F, G, H, I);
			if (mark4 == 1)
				temp1++;
		}
		cout << "+------------------------------+" << endl;
		this->define_declarer(temp1, i, j, mark2, mark3, mark4, this->play_color, this->play_number, B, C, D, E);
		mark5 = func(this->selector, this->final_number, B.bid, C.bid, D.bid, E.bid);
		if (mark5 == 1)
			break;
		/*
		mark5=fun();
		if(mark5==1)
		break;
		���B����m�@�禡�ΥH�P�_�u��Χ��O�_�w���쨬�����E��
		�ݭn���޼Ƭ�:
		this->selector,this->final_number,B.bid,C.bid,D.bid,E.bid;
		*/
	}
	return NULL;
}
int Game::Process::funa(int a, int b, int c, int d, int e, int A[], int B[])
{
	/*
	a=temp,
	b=sequence,
	c=selector,
	d=counter,
	e=counter_stop,
	A[]=auction_color,
	B[]=auction_number,
	*/
	this->sequence = d + 1 - 4 * a;
	this->selector = d + 1 - 4 * a;
	if (this->sequence == 4)
		this->sequence = 0;
	if ((this->selector == 0) || (this->selector == 4) == 1)
		this->selector = 3;
	else if (this->selector == 1)
		this->selector = 2;
	else if (this->selector == 2)
		this->selector = 4;
	else
		this->selector = 1;
	this->final_color = A[e];
	this->final_number = B[e];
	return NULL;
}//Game::Process::Auction()
int Game::Process::define_declarer(
	int a, int b, int c, int d, int e, int f, int A[], int B[],
	Game::Process::User &C,
	Game::Process::AI &D,
	Game::Process::AI &E,
	Game::Process::AI &F)
{
	/*
	a=temp1,
	b=i,
	c=j,
	d=mark2,
	e=mark3,
	f=mark4,
	A[]=play_color[],
	B[]=play_number[],
	*/
	//�S�H�X�Mdeclarer�P��⪺�P�Τ��P
	int G[4] = { 1,d,e,f }, H[4], I[4];
	for (int i = 0; i < 4; i++)
	{
		if (G[i] == 1)
		{
			H[i] = A[i + b * 4];
			I[i] = B[i + b * 4];
		}
		else
		{
			H[i] = 0;
			I[i] = 0;
		}
	}
	if (a == 0)
	{
		if (this->sequence == 0)
			E.bid++;
		else if (this->sequence == 1)
			D.bid++;
		else if (this->sequence == 2)
			F.bid++;
		else
			C.bid++;
	}
	else if (a == 1)
	{
		if (d == 1)
		{
			if (this->final_color == 0)
			{
				if (this->sequence == 0)
				{
					if (B[4 * b] == 1)
					{
						E.bid++;
						cout << "���E��player3���U" << endl;
					}
					else if (B[4 * b + 1] == 1)
					{
						D.bid++;
						this->sequence = 1;
						cout << "���E��player2���U" << endl;
					}
					else if (B[4 * b + 1] > B[4 * b])
					{
						D.bid++;
						this->sequence = 1;
						cout << "���E��player2���U" << endl;
					}
					else
					{
						E.bid++;
						cout << "���E��player3���U" << endl;
					}
				}
				else if (this->sequence == 1)
				{
					if (B[4 * b] == 1)
					{
						D.bid++;
						cout << "���E��player2���U" << endl;
					}
					else if (B[4 * b + 1] == 1)
					{
						F.bid++;
						this->sequence = 2;
						cout << "���E��player4���U" << endl;
					}
					else if (B[4 * b + 1] > B[4 * b])
					{
						F.bid++;
						this->sequence = 2;
						cout << "���E��player4���U" << endl;
					}
					else
					{
						D.bid++;
						cout << "���E��player2���U" << endl;
					}
				}
				else if (this->sequence == 2)
				{
					if (B[4 * b] == 1)
					{
						F.bid++;
						cout << "���E��player4���U" << endl;
					}
					else if (B[4 * b + 1] == 1)
					{
						C.bid++;
						this->sequence = 3;
						cout << "���E�Ѫ��a���U" << endl;
					}
					else if (B[4 * b + 1] > B[4 * b])
					{
						C.bid++;
						this->sequence = 3;
						cout << "���E�Ѫ��a���U" << endl;
					}
					else
					{
						F.bid++;
						cout << "���E��player4���U" << endl;
					}
				}
				else
				{
					if (B[4 * b] == 1)
					{
						C.bid++;
						cout << "���E�Ѫ��a���U" << endl;
					}
					else if (B[4 * b + 1] == 1)
					{
						E.bid++;
						this->sequence = 0;
						cout << "���E��player3���U" << endl;
					}
					else if (B[4 * b + 1] > B[4 * b])
					{
						E.bid++;
						this->sequence = 0;
						cout << "���E��player3���U" << endl;
					}
					else
					{
						C.bid++;
						cout << "���E�Ѫ��a���U" << endl;
					}
				}
			}
			else if (this->final_color == 5)
			{
				if (this->sequence == 0)
				{
					if (B[4 * b] == 2)
					{
						E.bid++;
						cout << "���E��player3���U" << endl;
					}
					else if (B[4 * b + 1] == 2)
					{
						D.bid++;
						this->sequence = 1;
						cout << "���E��player2���U" << endl;
					}
					else if (B[4 * b + 1] < B[4 * b])
					{
						D.bid++;
						this->sequence = 1;
						cout << "���E��player2���U" << endl;
					}
					else
					{
						E.bid++;
						cout << "���E��player3���U" << endl;
					}
				}
				else if (this->sequence == 1)
				{
					if (B[4 * b] == 2)
					{
						D.bid++;
						cout << "���E��player2���U" << endl;
					}
					else if (B[4 * b + 1] == 2)
					{
						F.bid++;
						this->sequence = 2;
						cout << "���E��player4���U" << endl;
					}
					else if (B[4 * b + 1] < B[4 * b])
					{
						F.bid++;
						this->sequence = 2;
						cout << "���E��player4���U" << endl;
					}
					else
					{
						D.bid++;
						cout << "���E��player2���U" << endl;
					}
				}
				else if (this->sequence == 2)
				{
					if (B[4 * b] == 2)
					{
						F.bid++;
						cout << "���E��player4���U" << endl;
					}
					else if (B[4 * b + 1] == 2)
					{
						C.bid++;
						this->sequence = 3;
						cout << "���E�Ѫ��a���U" << endl;
					}
					else if (B[4 * b + 1] < B[4 * b])
					{
						C.bid++;
						this->sequence = 3;
						cout << "���E�Ѫ��a���U" << endl;
					}
					else
					{
						F.bid++;
						cout << "���E��player4���U" << endl;
					}
				}
				else
				{
					if (B[4 * b] == 2)
					{
						C.bid++;
						cout << "���E�Ѫ��a���U" << endl;
					}
					else if (B[4 * b + 1] == 2)
					{
						E.bid++;
						this->sequence = 0;
						cout << "���E��player3���U" << endl;
					}
					else if (B[4 * b + 1] < B[4 * b])
					{
						E.bid++;
						this->sequence = 0;
						cout << "���E��player3���U" << endl;
					}
					else
					{
						C.bid++;
						cout << "���E�Ѫ��a���U" << endl;
					}
				}
			}
			else
			{
				if (this->sequence == 0)
				{
					if (A[4 * b] == this->final_color)
					{
						if (A[4 * b + 1] == this->final_color)
						{
							if (B[4 * b] == 1)
							{
								E.bid++;
								cout << "���E��player3���U" << endl;
							}
							else if (B[4 * b + 1] == 1)
							{
								D.bid++;
								this->sequence = 1;
								cout << "���E��player2���U" << endl;
							}
							else if (B[4 * b + 1] > B[4 * b])
							{
								D.bid++;
								this->sequence = 1;
								cout << "���E��player2���U" << endl;
							}
							else
							{
								E.bid++;
								cout << "���E��player3���U" << endl;
							}
						}
						else
						{
							E.bid++;
							cout << "���E��player3���U" << endl;
						}
					}
					else
					{
						if (A[4 * b + 1] != this->final_color)
						{
							if (B[4 * b] == 1)
							{
								E.bid++;
								cout << "���E��player3���U" << endl;
							}
							else if (B[4 * b + 1] == 1)
							{
								D.bid++;
								this->sequence = 1;
								cout << "���E��player2���U" << endl;
							}
							else if (B[4 * b + 1] > B[4 * b])
							{
								D.bid++;
								this->sequence = 1;
								cout << "���E��player2���U" << endl;
							}
							else
							{
								E.bid++;
								cout << "���E��player3���U" << endl;
							}
						}
						else
						{
							D.bid++;
							this->sequence = 1;
							cout << "���E��player2���U" << endl;
						}
					}
				}
				else if (this->sequence == 1)
				{
					if (A[4 * b] == this->final_color)
					{
						if (A[4 * b + 1] == this->final_color)
						{
							if (B[4 * b] == 1)
							{
								D.bid++;
								cout << "���E��player2���U" << endl;
							}
							else if (B[4 * b + 1] == 1)
							{
								F.bid++;
								this->sequence = 2;
								cout << "���E��player4���U" << endl;
							}
							else if (B[4 * b + 1] > B[4 * b])
							{
								F.bid++;
								this->sequence = 2;
								cout << "���E��player4���U" << endl;
							}
							else
							{
								D.bid++;
								cout << "���E��player2���U" << endl;
							}
						}
						else
						{
							D.bid++;
							cout << "���E��player2���U" << endl;
						}
					}
					else
					{
						if (A[4 * b + 1] != this->final_color)
						{
							if (B[4 * b] == 1)
							{
								D.bid++;
								cout << "���E��player2���U" << endl;
							}
							else if (B[4 * b + 1] == 1)
							{
								F.bid++;
								this->sequence = 2;
								cout << "���E��player4���U" << endl;
							}
							else if (B[4 * b + 1] > B[4 * b])
							{
								F.bid++;
								this->sequence = 2;
								cout << "���E��player4���U" << endl;
							}
							else
							{
								D.bid++;
								cout << "���E��player2���U" << endl;
							}
						}
						else
						{
							F.bid++;
							this->sequence = 2;
							cout << "���E��player4���U" << endl;
						}
					}
				}
				else if (this->sequence == 2)
				{
					if (A[4 * b] == this->final_color)
					{
						if (A[4 * b + 1] == this->final_color)
						{
							if (B[4 * b] == 1)
							{
								F.bid++;
								cout << "���E��player4���U" << endl;
							}
							else if (B[4 * b + 1] == 1)
							{
								C.bid++;
								this->sequence = 3;
								cout << "���E�Ѫ��a���U" << endl;
							}
							else if (B[4 * b + 1] > B[4 * b])
							{
								C.bid++;
								this->sequence = 3;
								cout << "���E�Ѫ��a���U" << endl;
							}
							else
							{
								F.bid++;
								cout << "���E��player4���U" << endl;
							}
						}
						else
						{
							F.bid++;
							cout << "���E��player4���U" << endl;
						}
					}
					else
					{
						if (A[4 * b + 1] != this->final_color)
						{
							if (B[4 * b] == 1)
							{
								F.bid++;
								cout << "���E��player4���U" << endl;
							}
							else if (B[4 * b + 1] == 1)
							{
								C.bid++;
								this->sequence = 3;
								cout << "���E�Ѫ��a���U" << endl;
							}
							else if (B[4 * b + 1] > B[4 * b])
							{
								C.bid++;
								this->sequence = 3;
								cout << "���E�Ѫ��a���U" << endl;
							}
							else
							{
								F.bid++;
								cout << "���E��player4���U" << endl;
							}
						}
						else
						{
							C.bid++;
							this->sequence = 3;
							cout << "���E�Ѫ��a���U" << endl;
						}
					}
				}
				else
				{
					if (A[4 * b] == this->final_color)
					{
						if (A[4 * b + 1] == this->final_color)
						{
							if (B[4 * b] == 1)
							{
								C.bid++;
								cout << "���E�Ѫ��a���U" << endl;
							}
							else if (B[4 * b + 1] == 1)
							{
								E.bid++;
								this->sequence = 0;
								cout << "���E��player3���U" << endl;
							}
							else if (B[4 * b + 1] > B[4 * b])
							{
								E.bid++;
								this->sequence = 0;
								cout << "���E��player3���U" << endl;
							}
							else
							{
								C.bid++;
								cout << "���E�Ѫ��a���U" << endl;
							}
						}
						else
						{
							C.bid++;
							cout << "���E�Ѫ��a���U" << endl;
						}
					}
					else
					{
						if (A[4 * b + 1] != this->final_color)
						{
							if (B[4 * b] == 1)
							{
								C.bid++;
								cout << "���E�Ѫ��a���U" << endl;
							}
							else if (B[4 * b + 1] == 1)
							{
								E.bid++;
								this->sequence = 0;
								cout << "���E��player3���U" << endl;
							}
							else if (B[4 * b + 1] > B[4 * b])
							{
								E.bid++;
								this->sequence = 0;
								cout << "���E��player3���U" << endl;
							}
							else
							{
								C.bid++;
								cout << "���E�Ѫ��a���U" << endl;
							}
						}
						else
						{
							E.bid++;
							this->sequence = 0;
							cout << "���E��player3���U" << endl;
						}
					}
				}
			}
		}
		else if (e == 1)
		{
			if (this->final_color == 0)
			{
				if (this->sequence == 0)
				{
					if (B[4 * b] == 1)
					{
						E.bid++;
						cout << "���E��player3���U" << endl;
					}
					else if (B[4 * b + 2] == 1)
					{
						F.bid++;
						this->sequence = 2;
						cout << "���E��player4���U" << endl;
					}
					else if (B[4 * b + 2] > B[4 * b])
					{
						F.bid++;
						this->sequence = 2;
						cout << "���E��player4���U" << endl;
					}
					else
					{
						E.bid++;
						cout << "���E��player3���U" << endl;
					}
				}
				else if (this->sequence == 1)
				{
					if (B[4 * b] == 1)
					{
						D.bid++;
						cout << "���E��player2���U" << endl;
					}
					else if (B[4 * b + 2] == 1)
					{
						C.bid++;
						this->sequence = 3;
						cout << "���E�Ѫ��a���U" << endl;
					}
					else if (B[4 * b + 2] > B[4 * b])
					{
						C.bid++;
						this->sequence = 3;
						cout << "���E�Ѫ��a���U" << endl;
					}
					else
					{
						D.bid++;
						cout << "���E��player2���U" << endl;
					}
				}
				else if (this->sequence == 2)
				{
					if (B[4 * b] == 1)
					{
						F.bid++;
						cout << "���E��player4���U" << endl;
					}
					else if (B[4 * b + 2] == 1)
					{
						E.bid++;
						this->sequence = 0;
						cout << "���E��player3���U" << endl;
					}
					else if (B[4 * b + 2] > B[4 * b])
					{
						E.bid++;
						this->sequence = 0;
						cout << "���E��player3���U" << endl;
					}
					else
					{
						F.bid++;
						cout << "���E��player4���U" << endl;
					}
				}
				else
				{
					if (B[4 * b] == 1)
					{
						C.bid++;
						cout << "���E�Ѫ��a���U" << endl;
					}
					else if (B[4 * b + 2] == 1)
					{
						D.bid++;
						this->sequence = 1;
						cout << "���E��player2���U" << endl;
					}
					else if (B[4 * b + 2] > B[4 * b])
					{
						D.bid++;
						this->sequence = 1;
						cout << "���E��player2���U" << endl;
					}
					else
					{
						C.bid++;
						cout << "���E�Ѫ��a���U" << endl;
					}
				}
			}
			else if (this->final_color == 5)
			{
				if (this->sequence == 0)
				{
					if (B[4 * b] == 2)
					{
						E.bid++;
						cout << "���E��player3���U" << endl;
					}
					else if (B[4 * b + 2] == 2)
					{
						F.bid++;
						this->sequence = 2;
						cout << "���E��player4���U" << endl;
					}
					else if (B[4 * b + 2] < B[4 * b])
					{
						F.bid++;
						this->sequence = 2;
						cout << "���E��player4���U" << endl;
					}
					else
					{
						E.bid++;
						cout << "���E��player3���U" << endl;
					}
				}
				else if (this->sequence == 1)
				{
					if (B[4 * b] == 2)
					{
						D.bid++;
						cout << "���E��player2���U" << endl;
					}
					else if (B[4 * b + 2] == 2)
					{
						C.bid++;
						this->sequence = 3;
						cout << "���E�Ѫ��a���U" << endl;
					}
					else if (B[4 * b + 2] < B[4 * b])
					{
						C.bid++;
						this->sequence = 3;
						cout << "���E�Ѫ��a���U" << endl;
					}
					else
					{
						D.bid++;
						cout << "���E��player2���U" << endl;
					}
				}
				else if (this->sequence == 2)
				{
					if (B[4 * b] == 2)
					{
						F.bid++;
						cout << "���E��player4���U" << endl;
					}
					else if (B[4 * b + 2] == 2)
					{
						E.bid++;
						this->sequence = 0;
						cout << "���E��player3���U" << endl;
					}
					else if (B[4 * b + 2] < B[4 * b])
					{
						E.bid++;
						this->sequence = 0;
						cout << "���E��player3���U" << endl;
					}
					else
					{
						F.bid++;
						cout << "���E��player4���U" << endl;
					}
				}
				else
				{
					if (B[4 * b] == 2)
					{
						C.bid++;
						cout << "���E�Ѫ��a���U" << endl;
					}
					else if (B[4 * b + 2] == 2)
					{
						D.bid++;
						this->sequence = 1;
						cout << "���E��player2���U" << endl;
					}
					else if (B[4 * b + 2] < B[4 * b])
					{
						D.bid++;
						this->sequence = 1;
						cout << "���E��player2���U" << endl;
					}
					else
					{
						C.bid++;
						cout << "���E�Ѫ��a���U" << endl;
					}
				}
			}
			else
			{
				if (this->sequence == 0)
				{
					if (A[4 * b] == this->final_color)
					{
						if (A[4 * b + 2] == this->final_color)
						{
							if (B[4 * b] == 1)
							{
								E.bid++;
								cout << "���E��player3���U" << endl;
							}
							else if (B[4 * b + 2] == 1)
							{
								F.bid++;
								this->sequence = 2;
								cout << "���E��player4���U" << endl;
							}
							else if (B[4 * b + 2] > B[4 * b])
							{
								F.bid++;
								this->sequence = 2;
								cout << "���E��player4���U" << endl;
							}
							else
							{
								E.bid++;
								cout << "���E��player3���U" << endl;
							}
						}
						else
						{
							E.bid++;
							cout << "���E��player3���U" << endl;
						}
					}
					else
					{
						if (A[4 * b + 2] != this->final_color)
						{
							if (B[4 * b] == 1)
							{
								E.bid++;
								cout << "���E��player3���U" << endl;
							}
							else if (B[4 * b + 2] == 1)
							{
								F.bid++;
								this->sequence = 2;
								cout << "���E��player4���U" << endl;
							}
							else if (B[4 * b + 2] > B[4 * b])
							{
								F.bid++;
								this->sequence = 2;
								cout << "���E��player4���U" << endl;
							}
							else
							{
								E.bid++;
								cout << "���E��player3���U" << endl;
							}
						}
						else
						{
							F.bid++;
							this->sequence = 2;
							cout << "���E��player4���U" << endl;
						}
					}
				}
				else if (this->sequence == 1)
				{
					if (A[4 * b] == this->final_color)
					{
						if (A[4 * b + 2] == this->final_color)
						{
							if (B[4 * b] == 1)
							{
								D.bid++;
								cout << "���E��player2���U" << endl;
							}
							else if (B[4 * b + 2] == 1)
							{
								C.bid++;
								this->sequence = 3;
								cout << "���E�Ѫ��a���U" << endl;
							}
							else if (B[4 * b + 2] > B[4 * b])
							{
								C.bid++;
								this->sequence = 3;
								cout << "���E�Ѫ��a���U" << endl;
							}
							else
							{
								D.bid++;
								cout << "���E��player2���U" << endl;
							}
						}
						else
						{
							D.bid++;
							cout << "���E��player2���U" << endl;
						}
					}
					else
					{
						if (A[4 * b + 2] != this->final_color)
						{
							if (B[4 * b] == 1)
							{
								D.bid++;
								cout << "���E��player2���U" << endl;
							}
							else if (B[4 * b + 2] == 1)
							{
								C.bid++;
								this->sequence = 3;
								cout << "���E�Ѫ��a���U" << endl;
							}
							else if (B[4 * b + 2] > B[4 * b])
							{
								C.bid++;
								this->sequence = 3;
								cout << "���E�Ѫ��a���U" << endl;
							}
							else
							{
								D.bid++;
								cout << "���E��player2���U" << endl;
							}
						}
						else
						{
							C.bid++;
							this->sequence = 3;
							cout << "���E�Ѫ��a���U" << endl;
						}
					}
				}
				else if (this->sequence == 2)
				{
					if (A[4 * b] == this->final_color)
					{
						if (A[4 * b + 2] == this->final_color)
						{
							if (B[4 * b] == 1)
							{
								F.bid++;
								cout << "���E��player4���U" << endl;
							}
							else if (B[4 * b + 2] == 1)
							{
								E.bid++;
								this->sequence = 0;
								cout << "���E��player3���U" << endl;
							}
							else if (B[4 * b + 2] > B[4 * b])
							{
								E.bid++;
								this->sequence = 0;
								cout << "���E��player3���U" << endl;
							}
							else
							{
								F.bid++;
								cout << "���E��player4���U" << endl;
							}
						}
						else
						{
							F.bid++;
							cout << "���E��player4���U" << endl;
						}
					}
					else
					{
						if (A[4 * b + 2] != this->final_color)
						{
							if (B[4 * b] == 1)
							{
								F.bid++;
								cout << "���E��player4���U" << endl;
							}
							else if (B[4 * b + 2] == 1)
							{
								E.bid++;
								this->sequence = 0;
								cout << "���E��player3���U" << endl;
							}
							else if (B[4 * b + 2] > B[4 * b])
							{
								E.bid++;
								this->sequence = 0;
								cout << "���E��player3���U" << endl;
							}
							else
							{
								F.bid++;
								cout << "���E��player4���U" << endl;
							}
						}
						else
						{
							E.bid++;
							this->sequence = 0;
							cout << "���E��player3���U" << endl;
						}
					}
				}
				else
				{
					if (A[4 * b] == this->final_color)
					{
						if (A[4 * b + 2] == this->final_color)
						{
							if (B[4 * b] == 1)
							{
								C.bid++;
								cout << "���E�Ѫ��a���U" << endl;
							}
							else if (B[4 * b + 2] == 1)
							{
								D.bid++;
								this->sequence = 1;
								cout << "���E��player2���U" << endl;
							}
							else if (B[4 * b + 2] > B[4 * b])
							{
								D.bid++;
								this->sequence = 1;
								cout << "���E��player2���U" << endl;
							}
							else
							{
								C.bid++;
								cout << "���E�Ѫ��a���U" << endl;
							}
						}
						else
						{
							C.bid++;
							cout << "���E�Ѫ��a���U" << endl;
						}
					}
					else
					{
						if (A[4 * b + 2] != this->final_color)
						{
							if (B[4 * b] == 1)
							{
								C.bid++;
								cout << "���E�Ѫ��a���U" << endl;
							}
							else if (B[4 * b + 2] == 1)
							{
								D.bid++;
								this->sequence = 1;
								cout << "���E��player2���U" << endl;
							}
							else if (B[4 * b + 2] > B[4 * b])
							{
								D.bid++;
								this->sequence = 1;
								cout << "���E��player2���U" << endl;
							}
							else
							{
								C.bid++;
								cout << "���E�Ѫ��a���U" << endl;
							}
						}
						else
						{
							D.bid++;
							this->sequence = 1;
							cout << "���E��player2���U" << endl;
						}
					}
				}
			}
		}
		else
		{
			if (this->final_color == 0)
			{
				if (this->sequence == 0)
				{
					if (B[4 * b] == 1)
					{
						E.bid++;
						cout << "���E��player3���U" << endl;
					}
					else if (B[4 * b + 1] == 1)
					{
						D.bid++;
						this->sequence = 1;
						cout << "���E��player2���U" << endl;
					}
					else if (B[4 * b + 1] > B[4 * b])
					{
						D.bid++;
						this->sequence = 1;
						cout << "���E��player2���U" << endl;
					}
					else
					{
						E.bid++;
						cout << "���E��player3���U" << endl;
					}
				}
				else if (this->sequence == 1)
				{
					if (B[4 * b] == 1)
					{
						D.bid++;
						cout << "���E��player2���U" << endl;
					}
					else if (B[4 * b + 1] == 1)
					{
						F.bid++;
						this->sequence = 2;
						cout << "���E��player4���U" << endl;
					}
					else if (B[4 * b + 1] > B[4 * b])
					{
						F.bid++;
						this->sequence = 2;
						cout << "���E��player4���U" << endl;
					}
					else
					{
						D.bid++;
						cout << "���E��player2���U" << endl;
					}
				}
				else if (this->sequence == 2)
				{
					if (B[4 * b] == 1)
					{
						F.bid++;
						cout << "���E��player4���U" << endl;
					}
					else if (B[4 * b + 1] == 1)
					{
						C.bid++;
						this->sequence = 3;
						cout << "���E�Ѫ��a���U" << endl;
					}
					else if (B[4 * b + 1] > B[4 * b])
					{
						C.bid++;
						this->sequence = 3;
						cout << "���E�Ѫ��a���U" << endl;
					}
					else
					{
						F.bid++;
						cout << "���E��player4���U" << endl;
					}
				}
				else
				{
					if (B[4 * b] == 1)
					{
						C.bid++;
						cout << "���E�Ѫ��a���U" << endl;
					}
					else if (B[4 * b + 1] == 1)
					{
						E.bid++;
						this->sequence = 0;
						cout << "���E��player3���U" << endl;
					}
					else if (B[4 * b + 1] > B[4 * b])
					{
						E.bid++;
						this->sequence = 0;
						cout << "���E��player3���U" << endl;
					}
					else
					{
						C.bid++;
						cout << "���E�Ѫ��a���U" << endl;
					}
				}
			}
			else if (this->final_color == 5)
			{
				if (this->sequence == 0)
				{
					if (B[4 * b] == 2)
					{
						E.bid++;
						cout << "���E��player3���U" << endl;
					}
					else if (B[4 * b + 1] == 2)
					{
						D.bid++;
						this->sequence = 1;
						cout << "���E��player2���U" << endl;
					}
					else if (B[4 * b + 1] < B[4 * b])
					{
						D.bid++;
						this->sequence = 1;
						cout << "���E��player2���U" << endl;
					}
					else
					{
						E.bid++;
						cout << "���E��player3���U" << endl;
					}
				}
				else if (this->sequence == 1)
				{
					if (B[4 * b] == 2)
					{
						D.bid++;
						cout << "���E��player2���U" << endl;
					}
					else if (B[4 * b + 1] == 2)
					{
						F.bid++;
						this->sequence = 2;
						cout << "���E��player4���U" << endl;
					}
					else if (B[4 * b + 1] < B[4 * b])
					{
						F.bid++;
						this->sequence = 2;
						cout << "���E��player4���U" << endl;
					}
					else
					{
						D.bid++;
						cout << "���E��player2���U" << endl;
					}
				}
				else if (this->sequence == 2)
				{
					if (B[4 * b] == 2)
					{
						F.bid++;
						cout << "���E��player4���U" << endl;
					}
					else if (B[4 * b + 1] == 2)
					{
						C.bid++;
						this->sequence = 3;
						cout << "���E�Ѫ��a���U" << endl;
					}
					else if (B[4 * b + 1] < B[4 * b])
					{
						C.bid++;
						this->sequence = 3;
						cout << "���E�Ѫ��a���U" << endl;
					}
					else
					{
						F.bid++;
						cout << "���E��player4���U" << endl;
					}
				}
				else
				{
					if (B[4 * b] == 2)
					{
						C.bid++;
						cout << "���E�Ѫ��a���U" << endl;
					}
					else if (B[4 * b + 1] == 2)
					{
						E.bid++;
						this->sequence = 0;
						cout << "���E��player3���U" << endl;
					}
					else if (B[4 * b + 1] < B[4 * b])
					{
						E.bid++;
						this->sequence = 0;
						cout << "���E��player3���U" << endl;
					}
					else
					{
						C.bid++;
						cout << "���E�Ѫ��a���U" << endl;
					}
				}
			}
			else
			{
				if (this->sequence == 0)
				{
					if (A[4 * b] == this->final_color)
					{
						if (A[4 * b + 1] == this->final_color)
						{
							if (B[4 * b] == 1)
							{
								E.bid++;
								cout << "���E��player3���U" << endl;
							}
							else if (B[4 * b + 1] == 1)
							{
								D.bid++;
								this->sequence = 1;
								cout << "���E��player2���U" << endl;
							}
							else if (B[4 * b + 1] > B[4 * b])
							{
								D.bid++;
								this->sequence = 1;
								cout << "���E��player2���U" << endl;
							}
							else
							{
								E.bid++;
								cout << "���E��player3���U" << endl;
							}
						}
						else
						{
							E.bid++;
							cout << "���E��player3���U" << endl;
						}
					}
					else
					{
						if (A[4 * b + 1] != this->final_color)
						{
							if (B[4 * b] == 1)
							{
								E.bid++;
								cout << "���E��player3���U" << endl;
							}
							else if (B[4 * b + 1] == 1)
							{
								D.bid++;
								this->sequence = 1;
								cout << "���E��player2���U" << endl;
							}
							else if (B[4 * b + 1] > B[4 * b])
							{
								D.bid++;
								this->sequence = 1;
								cout << "���E��player2���U" << endl;
							}
							else
							{
								E.bid++;
								cout << "���E��player3���U" << endl;
							}
						}
						else
						{
							D.bid++;
							this->sequence = 1;
							cout << "���E��player2���U" << endl;
						}
					}
				}
				else if (this->sequence == 1)
				{
					if (A[4 * b] == this->final_color)
					{
						if (A[4 * b + 1] == this->final_color)
						{
							if (B[4 * b] == 1)
							{
								D.bid++;
								cout << "���E��player2���U" << endl;
							}
							else if (B[4 * b + 1] == 1)
							{
								F.bid++;
								this->sequence = 2;
								cout << "���E��player4���U" << endl;
							}
							else if (B[4 * b + 1] > B[4 * b])
							{
								F.bid++;
								this->sequence = 2;
								cout << "���E��player4���U" << endl;
							}
							else
							{
								D.bid++;
								cout << "���E��player2���U" << endl;
							}
						}
						else
						{
							D.bid++;
							cout << "���E��player2���U" << endl;
						}
					}
					else
					{
						if (A[4 * b + 1] != this->final_color)
						{
							if (B[4 * b] == 1)
							{
								D.bid++;
								cout << "���E��player2���U" << endl;
							}
							else if (B[4 * b + 1] == 1)
							{
								F.bid++;
								this->sequence = 2;
								cout << "���E��player4���U" << endl;
							}
							else if (B[4 * b + 1] > B[4 * b])
							{
								F.bid++;
								this->sequence = 2;
								cout << "���E��player4���U" << endl;
							}
							else
							{
								D.bid++;
								cout << "���E��player2���U" << endl;
							}
						}
						else
						{
							F.bid++;
							this->sequence = 2;
							cout << "���E��player4���U" << endl;
						}
					}
				}
				else if (this->sequence == 2)
				{
					if (A[4 * b] == this->final_color)
					{
						if (A[4 * b + 1] == this->final_color)
						{
							if (B[4 * b] == 1)
							{
								F.bid++;
								cout << "���E��player4���U" << endl;
							}
							else if (B[4 * b + 1] == 1)
							{
								C.bid++;
								this->sequence = 3;
								cout << "���E�Ѫ��a���U" << endl;
							}
							else if (B[4 * b + 1] > B[4 * b])
							{
								C.bid++;
								this->sequence = 3;
								cout << "���E�Ѫ��a���U" << endl;
							}
							else
							{
								F.bid++;
								cout << "���E��player4���U" << endl;
							}
						}
						else
						{
							F.bid++;
							cout << "���E��player4���U" << endl;
						}
					}
					else
					{
						if (A[4 * b + 1] != this->final_color)
						{
							if (B[4 * b] == 1)
							{
								F.bid++;
								cout << "���E��player4���U" << endl;
							}
							else if (B[4 * b + 1] == 1)
							{
								C.bid++;
								this->sequence = 3;
								cout << "���E�Ѫ��a���U" << endl;
							}
							else if (B[4 * b + 1] > B[4 * b])
							{
								C.bid++;
								this->sequence = 3;
								cout << "���E�Ѫ��a���U" << endl;
							}
							else
							{
								F.bid++;
								cout << "���E��player4���U" << endl;
							}
						}
						else
						{
							C.bid++;
							this->sequence = 3;
							cout << "���E�Ѫ��a���U" << endl;
						}
					}
				}
				else
				{
					if (A[4 * b] == this->final_color)
					{
						if (A[4 * b + 1] == this->final_color)
						{
							if (B[4 * b] == 1)
							{
								C.bid++;
								cout << "���E�Ѫ��a���U" << endl;
							}
							else if (B[4 * b + 1] == 1)
							{
								E.bid++;
								this->sequence = 0;
								cout << "���E��player3���U" << endl;
							}
							else if (B[4 * b + 1] > B[4 * b])
							{
								E.bid++;
								this->sequence = 0;
								cout << "���E��player3���U" << endl;
							}
							else
							{
								C.bid++;
								cout << "���E�Ѫ��a���U" << endl;
							}
						}
						else
						{
							C.bid++;
							cout << "���E�Ѫ��a���U" << endl;
						}
					}
					else
					{
						if (A[4 * b + 1] != this->final_color)
						{
							if (B[4 * b] == 1)
							{
								C.bid++;
								cout << "���E�Ѫ��a���U" << endl;
							}
							else if (B[4 * b + 1] == 1)
							{
								E.bid++;
								this->sequence = 0;
								cout << "���E��player3���U" << endl;
							}
							else if (B[4 * b + 1] > B[4 * b])
							{
								E.bid++;
								this->sequence = 0;
								cout << "���E��player3���U" << endl;
							}
							else
							{
								C.bid++;
								cout << "���E�Ѫ��a���U" << endl;
							}
						}
						else
						{
							E.bid++;
							this->sequence = 0;
							cout << "���E��player3���U" << endl;
						}
					}
				}
			}
		}
	}
	else
	{
		if (this->final_color == 0)
		{
			if (this->sequence == 0)
			{
				int temp1 = 0, j = 1, temp2, temp3;
				for (int i = 0; i < 4; i++)
				{
					temp2 = 0;
					temp1 = j;
					do
					{
						if ((I[i] > I[i + j]) && (I[i + j] != 1) == 1)
						{
							temp2 = 1;
							if (i + j < 3)
								j++;
							else
								break;
						}
						else
						{
							if (I[i] == 1)
							{
								temp2 = 1;
								break;
							}
							else
							{
								temp2 = 0;
								break;
							}
						}
					} while ((I[i] > I[i + j]) && (I[i + j] != 1) == 1);
					j = temp1;
					if (temp2 == 1)
					{
						temp3 = i;
						break;
					}
				}
				if (temp3 == 0)
				{
					E.bid++;
					cout << "���E��player3���U" << endl;
				}
				else if (temp3 == 1)
				{
					D.bid++;
					this->sequence = 1;
					cout << "���E��player2���U" << endl;
				}
				else if (temp3 == 2)
				{
					F.bid++;
					this->sequence = 2;
					cout << "���E��player4���U" << endl;
				}
				else
				{
					C.bid++;
					this->sequence = 3;
					cout << "���E�Ѫ��a���U" << endl;
				}
			}
			else if (this->sequence == 1)
			{
				int temp1 = 0, j = 1, temp2, temp3;
				for (int i = 0; i < 4; i++)
				{
					temp2 = 0;
					temp1 = j;
					do
					{
						if ((I[i] > I[i + j]) && (I[i + j] != 1) == 1)
						{
							temp2 = 1;
							if (i + j < 3)
								j++;
							else
								break;
						}
						else
						{
							if (I[i] == 1)
							{
								temp2 = 1;
								break;
							}
							else
							{
								temp2 = 0;
								break;
							}
						}
					} while ((I[i] > I[i + j]) && (I[i + j] != 1) == 1);
					j = temp1;
					if (temp2 == 1)
					{
						temp3 = i;
						break;
					}
				}
				if (temp3 == 0)
				{
					D.bid++;
					cout << "���E��player2���U" << endl;
				}
				else if (temp3 == 1)
				{
					F.bid++;
					this->sequence = 2;
					cout << "���E��player4���U" << endl;
				}
				else if (temp3 == 2)
				{
					C.bid++;
					this->sequence = 3;
					cout << "���E�Ѫ��a���U" << endl;
				}
				else
				{
					E.bid++;
					this->sequence = 0;
					cout << "���E��player3���U" << endl;
				}
			}
			else if (this->sequence == 2)
			{
				int temp1 = 0, j = 1, temp2, temp3;
				for (int i = 0; i < 4; i++)
				{
					temp2 = 0;
					temp1 = j;
					do
					{
						if ((I[i] > I[i + j]) && (I[i + j] != 1) == 1)
						{
							temp2 = 1;
							if (i + j < 3)
								j++;
							else
								break;
						}
						else
						{
							if (I[i] == 1)
							{
								temp2 = 1;
								break;
							}
							else
							{
								temp2 = 0;
								break;
							}
						}
					} while ((I[i] > I[i + j]) && (I[i + j] != 1) == 1);
					j = temp1;
					if (temp2 == 1)
					{
						temp3 = i;
						break;
					}
				}
				if (temp3 == 0)
				{
					F.bid++;
					cout << "���E��player4���U" << endl;
				}
				else if (temp3 == 1)
				{
					C.bid++;
					this->sequence = 3;
					cout << "���E�Ѫ��a���U" << endl;
				}
				else if (temp3 == 2)
				{
					E.bid++;
					this->sequence = 0;
					cout << "���E��player3���U" << endl;
				}
				else
				{
					D.bid++;
					this->sequence = 1;
					cout << "���E��player2���U" << endl;
				}
			}
			else
			{
				int temp1 = 0, j = 1, temp2, temp3;
				for (int i = 0; i < 4; i++)
				{
					temp2 = 0;
					temp1 = j;
					do
					{
						if ((I[i] > I[i + j]) && (I[i + j] != 1) == 1)
						{
							temp2 = 1;
							if (i + j < 3)
								j++;
							else
								break;
						}
						else
						{
							if (I[i] == 1)
							{
								temp2 = 1;
								break;
							}
							else
							{
								temp2 = 0;
								break;
							}
						}
					} while ((I[i] > I[i + j]) && (I[i + j] != 1) == 1);
					j = temp1;
					if (temp2 == 1)
					{
						temp3 = i;
						break;
					}
				}
				if (temp3 == 0)
				{
					C.bid++;
					cout << "���E�Ѫ��a���U" << endl;
				}
				else if (temp3 == 1)
				{
					E.bid++;
					this->sequence = 0;
					cout << "���E��player3���U" << endl;
				}
				else if (temp3 == 2)
				{
					D.bid++;
					this->sequence = 1;
					cout << "���E��player2���U" << endl;
				}
				else
				{
					F.bid++;
					this->sequence = 2;
					cout << "���E��player4���U" << endl;
				}
			}
		}
		else if (this->final_color == 5)
		{
			if (this->sequence == 0)
			{
				int temp1 = 0, j = 1, temp2, temp3;
				for (int i = 0; i < 4; i++)
				{
					temp2 = 0;
					temp1 = j;
					do
					{
						if ((I[i] < I[i + j]) && (I[i + j] != 0) && (I[i + j] != 2) == 1)
						{
							temp2 = 1;
							if (i + j < 3)
								j++;
							else
								break;
						}
						else
						{
							if (I[i] == 2)
							{
								temp2 = 1;
								break;
							}
							else
							{
								temp2 = 0;
								break;
							}
						}
					} while ((I[i] < I[i + j]) && (I[i + j] != 0) && (I[i + j] != 2) == 1);
					j = temp1;
					if (temp2 == 1)
					{
						temp3 = i;
						break;
					}
				}
				if (temp3 == 0)
				{
					E.bid++;
					cout << "���E��player3���U" << endl;
				}
				else if (temp3 == 1)
				{
					D.bid++;
					this->sequence = 1;
					cout << "���E��player2���U" << endl;
				}
				else if (temp3 == 2)
				{
					F.bid++;
					this->sequence = 2;
					cout << "���E��player4���U" << endl;
				}
				else
				{
					C.bid++;
					this->sequence = 3;
					cout << "���E�Ѫ��a���U" << endl;
				}
			}
			else if (this->sequence == 1)
			{
				int temp1 = 0, j = 1, temp2, temp3;
				for (int i = 0; i < 4; i++)
				{
					temp2 = 0;
					temp1 = j;
					do
					{
						if ((I[i] < I[i + j]) && (I[i + j] != 0) && (I[i + j] != 2) == 1)
						{
							temp2 = 1;
							if (i + j < 3)
								j++;
							else
								break;
						}
						else
						{
							if (I[i] == 2)
							{
								temp2 = 1;
								break;
							}
							else
							{
								temp2 = 0;
								break;
							}
						}
					} while ((I[i] < I[i + j]) && (I[i + j] != 0) && (I[i + j] != 2) == 1);
					j = temp1;
					if (temp2 == 1)
					{
						temp3 = i;
						break;
					}
				}
				if (temp3 == 0)
				{
					D.bid++;
					cout << "���E��player2���U" << endl;
				}
				else if (temp3 == 1)
				{
					F.bid++;
					this->sequence = 2;
					cout << "���E��player4���U" << endl;
				}
				else if (temp3 == 2)
				{
					C.bid++;
					this->sequence = 3;
					cout << "���E�Ѫ��a���U" << endl;
				}
				else
				{
					E.bid++;
					this->sequence = 0;
					cout << "���E��player3���U" << endl;
				}
			}
			else if (this->sequence == 2)
			{
				int temp1 = 0, j = 1, temp2, temp3;
				for (int i = 0; i < 4; i++)
				{
					temp2 = 0;
					temp1 = j;
					do
					{
						if ((I[i] < I[i + j]) && (I[i + j] != 0) && (I[i + j] != 2) == 1)
						{
							temp2 = 1;
							if (i + j < 3)
								j++;
							else
								break;
						}
						else
						{
							if (I[i] == 2)
							{
								temp2 = 1;
								break;
							}
							else
							{
								temp2 = 0;
								break;
							}
						}
					} while ((I[i] < I[i + j]) && (I[i + j] != 0) && (I[i + j] != 2) == 1);
					j = temp1;
					if (temp2 == 1)
					{
						temp3 = i;
						break;
					}
				}
				if (temp3 == 0)
				{
					F.bid++;
					cout << "���E��player4���U" << endl;
				}
				else if (temp3 == 1)
				{
					C.bid++;
					this->sequence = 3;
					cout << "���E�Ѫ��a���U" << endl;
				}
				else if (temp3 == 2)
				{
					E.bid++;
					this->sequence = 0;
					cout << "���E��player3���U" << endl;
				}
				else
				{
					D.bid++;
					this->sequence = 1;
					cout << "���E��player2���U" << endl;
				}
			}
			else
			{
				int temp1 = 0, j = 1, temp2, temp3;
				for (int i = 0; i < 4; i++)
				{
					temp2 = 0;
					temp1 = j;
					do
					{
						if ((I[i] < I[i + j]) && (I[i + j] != 0) && (I[i + j] != 2) == 1)
						{
							temp2 = 1;
							if (i + j < 3)
								j++;
							else
								break;
						}
						else
						{
							if (I[i] == 2)
							{
								temp2 = 1;
								break;
							}
							else
							{
								temp2 = 0;
								break;
							}
						}
					} while ((I[i] < I[i + j]) && (I[i + j] != 0) && (I[i + j] != 2) == 1);
					j = temp1;
					if (temp2 == 1)
					{
						temp3 = i;
						break;
					}
				}
				if (temp3 == 0)
				{
					C.bid++;
					cout << "���E�Ѫ��a���U" << endl;
				}
				else if (temp3 == 1)
				{
					E.bid++;
					this->sequence = 0;
					cout << "���E��player3���U" << endl;
				}
				else if (temp3 == 2)
				{
					D.bid++;
					this->sequence = 1;
					cout << "���E��player2���U" << endl;
				}
				else
				{
					F.bid++;
					this->sequence = 2;
					cout << "���E��player4���U" << endl;
				}
			}
		}
		else
		{
			if (this->sequence == 0)
			{
				int temp1 = 0, j = 1, temp2, temp3;
				for (int i = 0; i < 4; i++)
				{
					temp2 = 0;
					temp1 = j;
					do
					{
						if (H[i] == this->final_color)
						{
							if (H[i + j] == this->final_color)
							{
								if ((I[i] > I[i + j]) && (I[i + j] != 1) == 1)
								{
									temp2 = 1;
									if (i + j < 3)
										j++;
									else
										break;
								}
								else
								{
									if (I[i] == 1)
									{
										temp2 = 1;
										break;
									}
									else
									{
										temp2 = 0;
										break;
									}
								}
							}
							else
							{
								temp2 = 1;
								if (i + j < 3)
									j++;
								else
									break;
							}
						}
						else
						{
							if (H[i + j] != this->final_color)
							{
								if ((I[i] > I[i + j]) && (I[i + j] != 1) == 1)
								{
									temp2 = 1;
									if (i + j < 3)
										j++;
									else
										break;
								}
								else
								{
									if (I[i] == 1)
									{
										temp2 = 1;
										break;
									}
									else
									{
										temp2 = 0;
										break;
									}
								}
							}
							else
							{
								temp2 = 0;
								break;
							}
						}
					} while (temp2 == 1);
					j = temp1;
					if (temp2 == 1)
					{
						temp3 = i;
						break;
					}
				}
				if (temp3 == 0)
				{
					E.bid++;
					cout << "���E��player3���U" << endl;
				}
				else if (temp3 == 1)
				{
					D.bid++;
					this->sequence = 1;
					cout << "���E��player2���U" << endl;
				}
				else if (temp3 == 2)
				{
					F.bid++;
					this->sequence = 2;
					cout << "���E��player4���U" << endl;
				}
				else
				{
					C.bid++;
					this->sequence = 3;
					cout << "���E�Ѫ��a���U" << endl;
				}
			}
			else if (this->sequence == 1)
			{
				int temp1 = 0, j = 1, temp2, temp3;
				for (int i = 0; i < 4; i++)
				{
					temp2 = 0;
					temp1 = j;
					do
					{
						if (H[i] == this->final_color)
						{
							if (H[i + j] == this->final_color)
							{
								if ((I[i] > I[i + j]) && (I[i + j] != 1) == 1)
								{
									temp2 = 1;
									if (i + j < 3)
										j++;
									else
										break;
								}
								else
								{
									if (I[i] == 1)
									{
										temp2 = 1;
										break;
									}
									else
									{
										temp2 = 0;
										break;
									}
								}
							}
							else
							{
								temp2 = 1;
								if (i + j < 3)
									j++;
								else
									break;
							}
						}
						else
						{
							if (H[i + j] != this->final_color)
							{
								if ((I[i] > I[i + j]) && (I[i + j] != 1) == 1)
								{
									temp2 = 1;
									if (i + j < 3)
										j++;
									else
										break;
								}
								else
								{
									if (I[i] == 1)
									{
										temp2 = 1;
										break;
									}
									else
									{
										temp2 = 0;
										break;
									}
								}
							}
							else
							{
								temp2 = 0;
								break;
							}
						}
					} while (temp2 == 1);
					j = temp1;
					if (temp2 == 1)
					{
						temp3 = i;
						break;
					}
				}
				if (temp3 == 0)
				{
					D.bid++;
					cout << "���E��player2���U" << endl;
				}
				else if (temp3 == 1)
				{
					F.bid++;
					this->sequence = 2;
					cout << "���E��player4���U" << endl;
				}
				else if (temp3 == 2)
				{
					C.bid++;
					this->sequence = 3;
					cout << "���E�Ѫ��a���U" << endl;
				}
				else
				{
					E.bid++;
					this->sequence = 0;
					cout << "���E��player3���U" << endl;
				}
			}
			else if (this->sequence == 2)
			{
				int temp1 = 0, j = 1, temp2, temp3;
				for (int i = 0; i < 4; i++)
				{
					temp2 = 0;
					temp1 = j;
					do
					{
						if (H[i] == this->final_color)
						{
							if (H[i + j] == this->final_color)
							{
								if ((I[i] > I[i + j]) && (I[i + j] != 1) == 1)
								{
									temp2 = 1;
									if (i + j < 3)
										j++;
									else
										break;
								}
								else
								{
									if (I[i] == 1)
									{
										temp2 = 1;
										break;
									}
									else
									{
										temp2 = 0;
										break;
									}
								}
							}
							else
							{
								temp2 = 1;
								if (i + j < 3)
									j++;
								else
									break;
							}
						}
						else
						{
							if (H[i + j] != this->final_color)
							{
								if ((I[i] > I[i + j]) && (I[i + j] != 1) == 1)
								{
									temp2 = 1;
									if (i + j < 3)
										j++;
									else
										break;
								}
								else
								{
									if (I[i] == 1)
									{
										temp2 = 1;
										break;
									}
									else
									{
										temp2 = 0;
										break;
									}
								}
							}
							else
							{
								temp2 = 0;
								break;
							}
						}
					} while (temp2 == 1);
					j = temp1;
					if (temp2 == 1)
					{
						temp3 = i;
						break;
					}
				}
				if (temp3 == 0)
				{
					F.bid++;
					cout << "���E��player4���U" << endl;
				}
				else if (temp3 == 1)
				{
					C.bid++;
					this->sequence = 3;
					cout << "���E�Ѫ��a���U" << endl;
				}
				else if (temp3 == 2)
				{
					E.bid++;
					this->sequence = 0;
					cout << "���E��player3���U" << endl;
				}
				else
				{
					D.bid++;
					this->sequence = 1;
					cout << "���E��player2���U" << endl;
				}
			}
			else
			{
				int temp1 = 0, j = 1, temp2, temp3;
				for (int i = 0; i < 4; i++)
				{
					temp2 = 0;
					temp1 = j;
					do
					{
						if (H[i] == this->final_color)
						{
							if (H[i + j] == this->final_color)
							{
								if ((I[i] > I[i + j]) && (I[i + j] != 1) == 1)
								{
									temp2 = 1;
									if (i + j < 3)
										j++;
									else
										break;
								}
								else
								{
									if (I[i] == 1)
									{
										temp2 = 1;
										break;
									}
									else
									{
										temp2 = 0;
										break;
									}
								}
							}
							else
							{
								temp2 = 1;
								if (i + j < 3)
									j++;
								else
									break;
							}
						}
						else
						{
							if (H[i + j] != this->final_color)
							{
								if ((I[i] > I[i + j]) && (I[i + j] != 1) == 1)
								{
									temp2 = 1;
									if (i + j < 3)
										j++;
									else
										break;
								}
								else
								{
									if (I[i] == 1)
									{
										temp2 = 1;
										break;
									}
									else
									{
										temp2 = 0;
										break;
									}
								}
							}
							else
							{
								temp2 = 0;
								break;
							}
						}
					} while (temp2 == 1);
					j = temp1;
					if (temp2 == 1)
					{
						temp3 = i;
						break;
					}
				}
				if (temp3 == 0)
				{
					C.bid++;
					cout << "���E�Ѫ��a���U" << endl;
				}
				else if (temp3 == 1)
				{
					E.bid++;
					this->sequence = 0;
					cout << "���E��player3���U" << endl;
				}
				else if (temp3 == 2)
				{
					D.bid++;
					this->sequence = 1;
					cout << "���E��player2���U" << endl;
				}
				else
				{
					F.bid++;
					this->sequence = 2;
					cout << "���E��player4���U" << endl;
				}
			}
		}
	}
	return NULL;
}
int Game::dealing(
	Game::Process::User &A,
	Game::Process::AI &B,
	Game::Process::AI &C,
	Game::Process::AI &D)
{
	//�]�w��P
	A.vCard_number[0] = 0;
	A.vCard_color[0] = 0;
	B.vCard_number[0] = 0;
	B.vCard_color[0] = 0;
	C.vCard_number[0] = 0;
	C.vCard_color[0] = 0;
	D.vCard_number[0] = 0;
	D.vCard_color[0] = 0;
	//�o�P
	int j = 1;
	for (int i = 1; i <= N_CARDS - 4; i += 4)
	{
		A.vCard_number[j] = v_card_B_number[i];
		A.vCard_color[j] = v_card_B_color[i];
		B.vCard_number[j] = v_card_B_number[i + 1];
		B.vCard_color[j] = v_card_B_color[i + 1];
		C.vCard_number[j] = v_card_B_number[i + 2];
		C.vCard_color[j] = v_card_B_color[i + 2];
		D.vCard_number[j] = v_card_B_number[i + 3];
		D.vCard_color[j] = v_card_B_color[i + 3];
		j++;
	}
	return NULL;
}
int Game::set_data1()
{
	srand(time(0));
	this->v_rand_1 = (rand() % 2);
	this->v_rand_2 = (rand() % 2);
	this->v_rand_3 = (rand() % 2);
	this->v_rand_4 = (rand() % 2);
	this->v_rand_5 = (rand() % 2);
	this->v_rand_6 = (rand() % 2);
	this->v_rand_7 = (rand() % 2);
	this->v_rand_8 = (rand() % 2);
	this->v_rand_9 = (rand() % 2);
	this->v_rand_10 = (rand() % 2);
	this->v_rand_11 = (rand() % 2);
	this->v_rand_12 = (rand() % 2);
	this->v_rand_13 = (rand() % 2);
	this->v_rand_14 = (rand() % 2);
	this->v_rand_15 = (rand() % 2);
	return NULL;
}
int Game::set_data2()
{
	int card_A_number[N_CARDS];
	int card_A_color[N_CARDS];
	funa(card_A_color, card_A_number);
	//�ƹ�W,�W���T��i�M�U��for�j��X��!
	for (int i = 0; i < N_CARDS; i++)
	{
		this->v_card_A_number[i] = card_A_number[i];
		this->v_card_A_color[i] = card_A_color[i];
	}

	return NULL;
}
int Game::set_data3()
{
	//A�}�C���쫬�P��,B�ѦҤ�
	for (int i = 0; i < N_CARDS; i++)
	{
		this->v_card_B_number[i] = this->v_card_A_number[i];
		this->v_card_B_color[i] = this->v_card_A_color[i];
	}
	//�~�P*6
	for (int i = 0; i < 6; i++)
	{
		for (int i = 1, j, temp1, temp2; i < N_CARDS; i++)
		{
			j = (rand() % N_CARDS);
			if (j == 0)continue;
			temp1 = this->v_card_B_number[i];
			temp2 = this->v_card_B_color[i];
			this->v_card_B_number[i] = this->v_card_B_number[j];
			this->v_card_B_color[i] = this->v_card_B_color[j];
			this->v_card_B_number[j] = temp1;
			this->v_card_B_color[j] = temp2;
		}
	}
	return NULL;
}
int Game::fun1(Game &A)
{
	Game::Process All_processes;
	Game::Process::AI player2, player3, player4;
	Game::Process::User player1;
	Game::Process::AI::color Max_color, Second_color, Third_color, Min_color;
	A.set_data2();
	do
	{
		All_processes.Difficulty_setting(
			A,
			player2,
			player3,
			player4);
		All_processes.Set_up(
			A,
			player1,
			player2,
			player3,
			player4,
			Max_color,
			Second_color,
			Third_color,
			Min_color);
		All_processes.Auction(
			A,
			player1,
			player2,
			player3,
			player4,
			Max_color,
			Second_color,
			Third_color,
			Min_color);
		All_processes.Play(
			A,
			player1,
			player2,
			player3,
			player4,
			Max_color,
			Second_color,
			Third_color,
			Min_color);
		cout << "�O�_���}�@��?(y)";
		cin >> ch;
	} while (ch == 'y');
	system("pause");
	return NULL;
}
int funa(int A[], int B[])
{
	B[0] = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 1; j < 14; j++)
			B[i * 13 + j] = j;
	}
	for (int i = 0, temp; i < 4; i++)
	{
		if (i == 0)
			temp = 1;
		else if (i == 1)
			temp = 2;
		else if (i == 2)
			temp = 3;
		else
			temp = 4;
		for (int j = 1; j < 14; j++)
			A[i * 13 + j] = temp;
	}
	return NULL;
} //Game::set_data2()
int funb(int A[])
{
	int number;
	int a, b, c;
	do
	{
		cout << "���׳]�w(�п�J0~7,0�̩�,7����):";
		cin >> number;
		if (number < 0 || number>7 == 1)
			cout << "��J���~,�Э��s��J!" << endl;
	} while (number < 0 || number>7 == 1);
	for (int i = 0; i < 3; i++)
	{
		int temp = pow(2, i + 1);
		if (temp > number)
		{
			for (int j = i; j > -1; j--)
			{
				if (number < pow(2, j))
				{
					A[j] = 0;
					continue;
				}
				number = number - pow(2, j);
				A[j] = 1;
			}

		}
	}
	//number�ѤQ�i����G�i��
	a = A[2];
	b = A[1];
	c = A[0];
	return NULL;
} //Game::Process::AI::select_card()
int func(int a, int b, int c, int d, int e, int f)
{
	/*
	a=selector,
	b=final_number,
	c=B.bid,
	d=C.bid,
	e=D.bid,
	f=E.bid,
	*/
	int mark;
	if ((a == 0) || (a == 2) == 1)
	{
		if ((e + f) == (b + 6))
		{
			cout << "���w���U�һݪ�" << b + 6 << "�E,���a�D�ԥ���!!" << endl;
			mark = 1;
		}
		else if ((c + d) == (8 - b))
		{
			cout << "�ڤ�w���U�һݪ�" << 8 - b << "�E,���a�D�Ԧ��\!!" << endl;
			mark = 1;
		}
		else
			mark = 0;
	}
	else
	{
		if ((c + d) == (b + 6))
		{
			cout << "�ڤ�w���U�һݪ�" << b + 6 << "�E,���a�D�Ԧ��\!!" << endl;
			mark = 1;
		}
		else if ((e + f) == (8 - b))
		{
			cout << "���w���U�һݪ�" << 8 - b << "�E,���a�D�ԥ���!!" << endl;
			mark = 1;
		}
		else
			mark = 0;
	}
	return mark;
}//Game::Process::Play()
int fun_explanation1()
{
	cout << "�w��C���|�H�X�����P(�����)!!" << endl;
	cout << "�Ĥ@����:" << endl;
	return NULL;
}
int fun_explanation1_1()
{
	cout << "�ѩ�AI�ثe�u�}�o�X�@��,�]�����׳]�w�@�߬���²�檺�Ҧ�!";
	return NULL;
}
int fun_explanation2()
{
	cout << endl;
	cout << "+-----------------------------------------+" << endl;
	cout << "�ĤG����:�o�P�P�˵P" << endl;
	return NULL;
}
int fun_explanation3()
{
	cout << "+------------------------------+" << endl;
	cout << "�ĤT����:�s�P" << endl;
	cout << "�H�U�O�|�쪱�a����m�ܷN��!!" << endl;
	cout << "        " << "Player.1(�ϥΪ�)" << endl;
	cout << "Player.4" << "        " << "Player.3" << endl;
	cout << "        " << "Player.2" << endl;
	cout << "�s�P����Player.3���ɰw�}�l" << endl;
	return NULL;
}
int fun_explanation3_1(int a, int b, int c, int d, int A[], int B[])
{
	/*
	a=temp,
	b=counter_stop,
	c=sequence,
	d=selector,
	A[]�N��auction_color[],
	B[]�N��auction_number[],
	*/
	cout << "+------------------------------+" << endl;
	if (c == 0)
	{
		if (A[b] == 0)
			cout << "�̲רM�w�ĥ�player.3�ҳ۪��L��" << B[b] << "�@�������C�����X��!!";
		else if (A[b] == 1)
			cout << "�̲רM�w�ĥ�player.3�ҳ۪��®�" << B[b] << "�@�������C�����X��!!";
		else if (A[b] == 2)
			cout << "�̲רM�w�ĥ�player.3�ҳ۪�����" << B[b] << "�@�������C�����X��!!";
		else if (A[b] == 3)
			cout << "�̲רM�w�ĥ�player.3�ҳ۪����" << B[b] << "�@�������C�����X��!!";
		else if (A[b] == 4)
			cout << "�̲רM�w�ĥ�player.3�ҳ۪�����" << B[b] << "�@�������C�����X��!!";
		else
			cout << "�̲רM�w�ĥ�player.3�ҳ۪�small" << B[b] << "�@�������C�����X��!!";
	}
	else if (c == 1)
	{
		if (A[b] == 0)
			cout << "�̲רM�w�ĥ�player.2�ҳ۪��L��" << B[b] << "�@�������C�����X��!!";
		else if (A[b] == 1)
			cout << "�̲רM�w�ĥ�player.2�ҳ۪��®�" << B[b] << "�@�������C�����X��!!";
		else if (A[b] == 2)
			cout << "�̲רM�w�ĥ�player.2�ҳ۪�����" << B[b] << "�@�������C�����X��!!";
		else if (A[b] == 3)
			cout << "�̲רM�w�ĥ�player.2�ҳ۪����" << B[b] << "�@�������C�����X��!!";
		else if (A[b] == 4)
			cout << "�̲רM�w�ĥ�player.2�ҳ۪�����" << B[b] << "�@�������C�����X��!!";
		else
			cout << "�̲רM�w�ĥ�player.2�ҳ۪�small" << B[b] << "�@�������C�����X��!!";
	}
	else if (c == 2)
	{
		if (A[b] == 0)
			cout << "�̲רM�w�ĥ�player.4�ҳ۪��L��" << B[b] << "�@�������C�����X��!!";
		else if (A[b] == 1)
			cout << "�̲רM�w�ĥ�player.4�ҳ۪��®�" << B[b] << "�@�������C�����X��!!";
		else if (A[b] == 2)
			cout << "�̲רM�w�ĥ�player.4�ҳ۪�����" << B[b] << "�@�������C�����X��!!";
		else if (A[b] == 3)
			cout << "�̲רM�w�ĥ�player.4�ҳ۪����" << B[b] << "�@�������C�����X��!!";
		else if (A[b] == 4)
			cout << "�̲רM�w�ĥ�player.4�ҳ۪�����" << B[b] << "�@�������C�����X��!!";
		else
			cout << "�̲רM�w�ĥ�player.4�ҳ۪�small" << B[b] << "�@�������C�����X��!!";
	}
	else
	{
		if (A[b] == 0)
			cout << "�̲רM�w�ĥαz�ҳ۪��L��" << B[b] << "�@�������C�����X��!!";
		else if (A[b] == 1)
			cout << "�̲רM�w�ĥαz�ҳ۪��®�" << B[b] << "�@�������C�����X��!!";
		else if (A[b] == 2)
			cout << "�̲רM�w�ĥαz�ҳ۪�����" << B[b] << "�@�������C�����X��!!";
		else if (A[b] == 3)
			cout << "�̲רM�w�ĥαz�ҳ۪����" << B[b] << "�@�������C�����X��!!";
		else if (A[b] == 4)
			cout << "�̲רM�w�ĥαz�ҳ۪�����" << B[b] << "�@�������C�����X��!!";
		else
			cout << "�̲רM�w�ĥαz�ҳ۪�small" << B[b] << "�@�������C�����X��!!";
	}
	cout << endl;
	return NULL;
}
int fun_explanation4()
{
	cout << "+------------------------------+" << endl;
	cout << "�ĥ|����:�X�P" << endl;
	cout << "�H�U���z����P,�b���L�{��,�C�@�����|��ܥX�z����P" << endl;
	return NULL;
}