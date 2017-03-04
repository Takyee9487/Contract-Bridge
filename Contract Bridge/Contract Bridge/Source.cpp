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
	bool v_rand_1, v_rand_2, v_rand_3, v_rand_4, v_rand_5, v_rand_6, v_rand_7, v_rand_8, v_rand_9, v_rand_10, v_rand_11, v_rand_12, v_rand_13, v_rand_14, v_rand_15; //用於本遊戲過程中會遇到的隨機決策
	int v_card_A_number[N_CARDS], v_card_A_color[N_CARDS]; //原型牌組
	int v_card_B_number[N_CARDS], v_card_B_color[N_CARDS]; //洗好的牌組
public:
	class Process
	{
		friend class Game;
		friend class AI;
		friend class User;
	private:
		int auction_color[40], auction_number[40]; //存放All_processes.Auction()過程中每一次玩家所喊的花色
		int play_color[52], play_number[52]; //存放All_processes.Play()過程中每一次玩家所出的的牌
		int sequence; //在play過程中出牌的順序 
		int selector; //存取是那一隊達成合約
		int final_color, final_number; //最終合約的的資訊
	public:
		class User
		{
			friend class Game;
			friend class Game::Process;
		private:
			int vCard_color[14], vCard_number[14]; //手牌,不使用vCard[0]
			int sCard_color[13], sCard_number[13]; //存放All_processes.play()過程中每一磴玩家所出的牌
			int auction_color; //最終合約的的資訊,勝利所需磴數存取於class process下較為方便
			int bid; //存取遊戲當下時贏了幾磴
		public:
			int set_data_card(); ////將手牌按照(黑桃,紅心,方塊,梅花)排列
			void show_card1();
			void show_card2();
			int redo(Game::Process::User &);
			int set_data(int, int, int, int[], int[]); //做為預防可能沒有存取到最終合約的資訊的保險
			int set_data2();
			int choose_color(int, int, int, int, int, int[], int[]);
			int select_card(int, int, int, int[], int[]);
			int id; //用來識別各個player在遊戲中的位置
		};
		class AI
		{
			friend class Game;
			friend class Game::Process;
		private:
			bool smart;
			bool v_rand_1, v_rand_2, v_rand_3;//暫時沒用
			int vCard_color[14], vCard_number[14]; //手牌,不使用vCard[0]
			int sCard_color[13], sCard_number[13]; //存放All_processes.play()過程中每一磴玩家所出的牌
			int auction_color; //存放最終合約的資訊,勝利所需磴數存取於class process下較為方便
			int bid; //存取遊戲當下時贏了幾磴
			int spade_number;
			int heart_number;
			int diamond_number;
			int club_number;
			int id; //用來識別各個player在遊戲中的位置
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
			int set_data_card(); //將手牌按照(黑桃,紅心,方塊,梅花)排列
			int reset_data(
				Game::Process::AI::color &,
				Game::Process::AI::color &,
				Game::Process::AI::color &,
				Game::Process::AI::color &);
			int set_data0(); //存取手牌中每個花色各有幾張牌
			int set_data1(
				Game::Process::AI::color &,
				Game::Process::AI::color &,
				Game::Process::AI::color &,
				Game::Process::AI::color &); //存Max_color的private
			int set_data2(
				Game::Process::AI::color &,
				Game::Process::AI::color &,
				Game::Process::AI::color &,
				Game::Process::AI::color &); //存Second_color的private
			int set_data3(
				Game::Process::AI::color &,
				Game::Process::AI::color &,
				Game::Process::AI::color &,
				Game::Process::AI::color &); //存Third_color的private
			int set_data4(
				Game::Process::AI::color &,
				Game::Process::AI::color &,
				Game::Process::AI::color &,
				Game::Process::AI::color &); //存Min_color的private
			int set_data5(int, int, int, int[], int[]); //做為預防可能沒有存取到最終合約的資訊的保險
			int set_data6();
			int set_rand();//暫時沒用
			int set_player2_smart(bool, bool, bool); //done
			int set_player3_smart(bool, bool, bool); //done
			int set_player4_smart(bool, bool, bool); //done
			int redo(
				Game &,
				Game::Process::AI::color &,
				Game::Process::AI::color &,
				Game::Process::AI::color &,
				Game::Process::AI::color &); //此函數會對前面四個函數所求得的參數進行分析,最後回傳一個值(零或一),值為一時倒牌
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
		int funa(int, int, int, int, int, int[], int[]); //將sequence和selector轉換成可以用的的值
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
		Game::Process::AI &); //預設玩家手牌+發牌
	int set_data1(); //產生v_rand_1,v_rand_2,v_rand_3
	int set_data2(); //產生原型牌組
	int set_data3(); //存洗完牌後的牌組
	int fun1(Game &); //主程式!!
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
	/*以上為本作業最終形式*/
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
			cout << "黑桃" << " " << this->vCard_number[i] << " ";
		else if (this->vCard_color[i] == 2)
			cout << "紅心" << " " << this->vCard_number[i] << " ";
		else if (this->vCard_color[i] == 3)
			cout << "方塊" << " " << this->vCard_number[i] << " ";
		else
			cout << "梅花" << " " << this->vCard_number[i] << " ";
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
			cout << "(" << i << ")" << "黑桃" << " " << this->vCard_number[i] << " ";
		else if (this->vCard_color[i] == 2)
			cout << "(" << i << ")" << "紅心" << " " << this->vCard_number[i] << " ";
		else if (this->vCard_color[i] == 3)
			cout << "(" << i << ")" << "方塊" << " " << this->vCard_number[i] << " ";
		else if (this->vCard_color[i] == 4)
			cout << "(" << i << ")" << "梅花" << " " << this->vCard_number[i] << " ";
		else
			cout << "(" << 0 << ")" << "XXXX" << " " << 'X' << " ";
		if (i == 7)
			cout << endl;
	}
	cout << endl;
	cout << "請輸入花色前的數字來出牌!!" << endl;
	cout << endl;
}
int Game::Process::User::redo(Game::Process::User &A)
{
	int a;
	cout << "以下為您的手牌!" << endl;
	cout << "+------------------------------+" << endl;
	A.show_card1();
	cout << "+------------------------------+" << endl;
	cout << "請注意!!在下一階段(叫牌)時,本程式並不會再次將手牌呈現在營幕上," << endl;
	cout << "請玩家在此時將手牌的資訊記下!!" << endl;
	cout << "是否倒牌?若要倒牌,請輸入數字1!" << " ";
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
	a代表accept,
	b代表counter,
	c代表counter_stop,
	d代表sequence,
	e代表selector,
	A[]代表auction_color[],
	B[]代表auction_number[],
	*/
	cout << "+------------------------------+" << endl;
	int number;
	if (A[b - 3] == 0)
		cout << "對手Player.3喊出了無王 " << B[b - 3] << endl;
	else if (A[b - 3] == 1)
		cout << "對手Player.3喊出了黑桃 " << B[b - 3] << endl;
	else if (A[b - 3] == 2)
		cout << "對手Player.3喊出了紅心 " << B[b - 3] << endl;
	else if (A[b - 3] == 3)
		cout << "對手Player.3喊出了方塊 " << B[b - 3] << endl;
	else if (A[b - 3] == 4)
		cout << "對手Player.3喊出了梅花 " << B[b - 3] << endl;
	else if (A[b - 3] == 5)
		cout << "對手Player.3喊出了small " << B[b - 3] << endl;
	else
		cout << "對手Player.3決定pass" << endl;
	if (A[b - 2] == 0)
		cout << "隊友Player.2喊出了無王 " << B[b - 2] << endl;
	else if (A[b - 2] == 1)
		cout << "隊友Player.2喊出了黑桃 " << B[b - 2] << endl;
	else if (A[b - 2] == 2)
		cout << "隊友Player.2喊出了紅心 " << B[b - 2] << endl;
	else if (A[b - 2] == 3)
		cout << "隊友Player.2喊出了方塊 " << B[b - 2] << endl;
	else if (A[b - 2] == 4)
		cout << "隊友Player.2喊出了梅花 " << B[b - 2] << endl;
	else if (A[b - 2] == 5)
		cout << "隊友Player.2喊出了small " << B[b - 2] << endl;
	else
		cout << "隊友Player.2決定pass" << endl;
	if (A[b - 1] == 0)
		cout << "對手Player.4喊出了無王 " << B[b - 1] << endl;
	else if (A[b - 1] == 1)
		cout << "對手Player.4喊出了黑桃 " << B[b - 1] << endl;
	else if (A[b - 1] == 2)
		cout << "對手Player.4喊出了紅心 " << B[b - 1] << endl;
	else if (A[b - 1] == 3)
		cout << "對手Player.4喊出了方塊 " << B[b - 1] << endl;
	else if (A[b - 1] == 4)
		cout << "對手Player.4喊出了梅花 " << B[b - 1] << endl;
	else if (A[b - 1] == 5)
		cout << "對手Player.4喊出了small " << B[b - 1] << endl;
	else
		cout << "對手Player.4決定pass" << endl;
	cout << "+------------------------------+" << endl;
	cout << "現在輪到玩家選擇要喊的花色和數字" << endl;
	cout << "請注意!!花色一但經過判定為正確將不能更改,請玩家慎重決定!!" << endl;
	cout << "且一定要輸入一花色!" << endl;
	cout << "首先請選擇花色:0為無王,1為黑桃,2為紅心,3為方塊,4為梅花,5為small,6為pass";
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
					cout << "已到叫牌終點!" << endl;
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
						cout << "輸入錯誤!請重新輸入 ";
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
						cout << "輸入錯誤!請重新輸入 ";
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
						cout << "輸入錯誤!請重新輸入 ";
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
						cout << "輸入錯誤!請重新輸入 ";
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
						cout << "輸入錯誤!請重新輸入 ";
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
							cout << "已到叫牌終點!" << endl;
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
								cout << "輸入錯誤!請重新輸入 ";
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
								cout << "輸入錯誤!請重新輸入 ";
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
								cout << "輸入錯誤!請重新輸入 ";
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
								cout << "輸入錯誤!請重新輸入 ";
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
								cout << "輸入錯誤!請重新輸入 ";
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
		cout << "現在請玩家輸入想要的數字" << endl;
		cout << "注意!!請玩家按照規則輸入正確的數字!" << endl;
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
						cout << "輸入錯誤!請重新輸入 ";
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
						cout << "輸入錯誤!請重新輸入 ";
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
						cout << "輸入錯誤!請重新輸入 ";
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
						cout << "輸入錯誤!請重新輸入 ";
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
						cout << "輸入錯誤!請重新輸入 ";
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
						cout << "輸入錯誤!請重新輸入 ";
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
						cout << "輸入錯誤!請重新輸入 ";
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
						cout << "輸入錯誤!請重新輸入 ";
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
						cout << "輸入錯誤!請重新輸入 ";
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
						cout << "輸入錯誤!請重新輸入 ";
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
						cout << "輸入錯誤!請重新輸入 ";
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
						cout << "輸入錯誤!請重新輸入 ";
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
						cout << "輸入錯誤!請重新輸入 ";
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
						cout << "輸入錯誤!請重新輸入 ";
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
						cout << "輸入錯誤!請重新輸入 ";
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
						cout << "輸入錯誤!請重新輸入 ";
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
						cout << "輸入錯誤!請重新輸入 ";
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
						cout << "輸入錯誤!請重新輸入 ";
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
						cout << "輸入錯誤!請重新輸入 ";
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
						cout << "輸入錯誤!請重新輸入 ";
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
						cout << "輸入錯誤!請重新輸入 ";
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
						cout << "輸入錯誤!請重新輸入 ";
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
						cout << "輸入錯誤!請重新輸入 ";
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
						cout << "輸入錯誤!請重新輸入 ";
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
						cout << "輸入錯誤!請重新輸入 ";
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
						cout << "輸入錯誤!請重新輸入 ";
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
						cout << "輸入錯誤!請重新輸入 ";
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
						cout << "輸入錯誤!請重新輸入 ";
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
						cout << "輸入錯誤!請重新輸入 ";
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
						cout << "輸入錯誤!請重新輸入 ";
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
						cout << "輸入錯誤!請重新輸入 ";
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
						cout << "輸入錯誤!請重新輸入 ";
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
						cout << "輸入錯誤!請重新輸入 ";
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
						cout << "輸入錯誤!請重新輸入 ";
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
						cout << "輸入錯誤!請重新輸入 ";
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
						cout << "輸入錯誤!請重新輸入 ";
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
							cout << "輸入錯誤!請重新輸入 ";
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
							cout << "輸入錯誤!請重新輸入 ";
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
							cout << "輸入錯誤!請重新輸入 ";
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
							cout << "輸入錯誤!請重新輸入 ";
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
							cout << "輸入錯誤!請重新輸入 ";
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
							cout << "輸入錯誤!請重新輸入 ";
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
							cout << "輸入錯誤!請重新輸入 ";
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
							cout << "輸入錯誤!請重新輸入 ";
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
							cout << "輸入錯誤!請重新輸入 ";
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
							cout << "輸入錯誤!請重新輸入 ";
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
							cout << "輸入錯誤!請重新輸入 ";
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
							cout << "輸入錯誤!請重新輸入 ";
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
							cout << "輸入錯誤!請重新輸入 ";
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
							cout << "輸入錯誤!請重新輸入 ";
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
							cout << "輸入錯誤!請重新輸入 ";
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
							cout << "輸入錯誤!請重新輸入 ";
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
							cout << "輸入錯誤!請重新輸入 ";
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
							cout << "輸入錯誤!請重新輸入 ";
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
							cout << "輸入錯誤!請重新輸入 ";
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
							cout << "輸入錯誤!請重新輸入 ";
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
							cout << "輸入錯誤!請重新輸入 ";
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
							cout << "輸入錯誤!請重新輸入 ";
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
							cout << "輸入錯誤!請重新輸入 ";
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
							cout << "輸入錯誤!請重新輸入 ";
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
							cout << "輸入錯誤!請重新輸入 ";
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
							cout << "輸入錯誤!請重新輸入 ";
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
							cout << "輸入錯誤!請重新輸入 ";
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
							cout << "輸入錯誤!請重新輸入 ";
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
							cout << "輸入錯誤!請重新輸入 ";
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
							cout << "輸入錯誤!請重新輸入 ";
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
							cout << "輸入錯誤!請重新輸入 ";
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
							cout << "輸入錯誤!請重新輸入 ";
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
							cout << "輸入錯誤!請重新輸入 ";
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
							cout << "輸入錯誤!請重新輸入 ";
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
							cout << "輸入錯誤!請重新輸入 ";
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
							cout << "輸入錯誤!請重新輸入 ";
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
		cout << "您喊出了無王 " << B[b] << endl;
	else if (A[b] == 1)
		cout << "您喊出了黑桃 " << B[b] << endl;
	else if (A[b] == 2)
		cout << "您喊出了紅心 " << B[b] << endl;
	else if (A[b] == 3)
		cout << "您喊出了方塊 " << B[b] << endl;
	else if (A[b] == 4)
		cout << "您喊出了梅花 " << B[b] << endl;
	else if (A[b] == 5)
		cout << "您喊出了small " << B[b] << endl;
	else
		cout << "您決定pass" << endl;
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
					cout << "手牌中還有同花色的牌,請重新輸入!!" << endl;
					temp2 = 1;
				}
				else if (this->vCard_color[number] == 0)
				{
					cout << "此牌已出,請重新輸入!!" << endl;
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
					cout << "此牌已出,請重新輸入!!" << endl;
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
					cout << "手牌中還有同花色的牌,請重新輸入!!" << endl;
					temp2 = 1;
				}
				else if (this->vCard_color[number] == 0)
				{
					cout << "此牌已出,請重新輸入!!" << endl;
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
					cout << "此牌已出,請重新輸入!!" << endl;
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
					cout << "手牌中還有同花色的牌,請重新輸入!!" << endl;
					temp2 = 1;
				}
				else if (this->vCard_color[number] == 0)
				{
					cout << "此牌已出,請重新輸入!!" << endl;
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
					cout << "此牌已出,請重新輸入!!" << endl;
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
	/*ary[0]會存張數最少的花色,ary[3]則反之,若花色張數相同則不移動*/
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
	/*ary[0]會存張數最少的花色,ary[3]則反之,若花色張數相同則不移動*/
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
	/*ary[0]會存張數最少的花色,ary[3]則反之,若花色張數相同則不移動*/
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
	/*ary[0]會存張數最少的花色,ary[3]則反之,若花色張數相同則不移動*/
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
//set_rand()暫時沒用
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
	a代表accept,
	b代表counter,
	c代表counter_stop,
	d代表sequence,
	e代表selector,
	A[]代表auction_color[],
	B[]代表auction_number[],
	*/
	/*
	在A[]輸入1~4會對應至牌組1~4的花色,
	若為零則為No King,
	若為五則為比小,
	若為六則代表accept,

	B[]則是要比對方多的磴數,
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
	/*以上是喊花色所考慮的簡易參數*/
	//b++在最後執行!!
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
		//參考b-3的牌!!
		else if (a == 2)
		{
			int partner_color[2]; //存取隊友叫過的花色
			int enemy1_color[2], enemy2_color[2]; //存取對方兩人叫過的花色
												  //會跟據隊友和隊手每人最近兩次叫牌進行分析
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
				//不會出現A[b-1]=6的情形,因為上上一個人必定沒有accept!!
				if (bubble_sort[0] == bubble_sort[1]) //假設找不到最佳解,此時無法明確決定要喊的花色
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
										//上一人喊的花色為梅花,固在此時喊黑桃,紅心,方塊皆可選擇線位是否要+1
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
										//上一人喊的花色為梅花,固在此時喊黑桃,紅心,方塊皆可選擇線位是否要+1
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
										//上一人喊的花色為梅花,固在此時喊黑桃,紅心,方塊皆可選擇線位是否要+1
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
					//先考慮花色,磴數看是+1或照舊!!
					//若上一個人喊無王
					if (A[b - 3] == 0)
					{
						//考慮上一位喊出的線位
						if (B[b - 3] == 1)
						{
							//一半的機率喊新的花色
							if (C.v_rand_1 || C.v_rand_15 == 1)
							{
								//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
								//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
								//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
					//若上一個人喊四花色任一
					else if (A[b - 3] == 1)
					{
						//考慮上一位喊出的線位
						if (B[b - 3] == 1)
						{
							//一半的機率喊新的花色
							if (C.v_rand_1 || C.v_rand_15 == 1)
							{
								//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
								//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
								//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
						//考慮上一位喊出的線位
						if (B[b - 3] == 1)
						{
							//一半的機率喊新的花色
							if (C.v_rand_1 || C.v_rand_15 == 1)
							{
								//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
								//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
								//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
						//考慮上一位喊出的線位
						if (B[b - 3] == 1)
						{
							//一半的機率喊新的花色
							if (C.v_rand_1 || C.v_rand_15 == 1)
							{
								//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
								//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
								//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
						//考慮上一位喊出的線位
						if (B[b - 3] == 1)
						{
							//一半的機率喊新的花色
							if (C.v_rand_1 || C.v_rand_15 == 1)
							{
								//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
										//上一人喊的花色為梅花,固在此時喊黑桃,紅心,方塊皆可選擇線位是否要+1
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
								//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
										//上一人喊的花色為梅花,固在此時喊黑桃,紅心,方塊皆可選擇線位是否要+1
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
								//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
										//上一人喊的花色為梅花,固在此時喊黑桃,紅心,方塊皆可選擇線位是否要+1
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
					//若上一個人喊small
					else
					{
						//考慮上一位喊出的線位
						if (B[b - 3] == 1)
						{
							//一半的機率喊新的花色
							if (C.v_rand_1 || C.v_rand_15 == 1)
							{
								//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
								//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
								//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
				/*假設花色最佳解為bubble_sort[0]所對應的花色!!*/
				//不會出現A[b-1]=6的情形,因為上一個人必定沒有accept!!
				if (bubble_sort[0] == bubble_sort[1]) //假設找不到最佳解,此時無法明確決定要喊的花色
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
										//上一人喊的花色為梅花,固在此時喊黑桃,紅心,方塊皆可選擇線位是否要+1
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
										//上一人喊的花色為梅花,固在此時喊黑桃,紅心,方塊皆可選擇線位是否要+1
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
										//上一人喊的花色為梅花,固在此時喊黑桃,紅心,方塊皆可選擇線位是否要+1
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
					//先考慮花色,磴數看是+1或照舊!!
					//若上一個人喊無王
					if (A[b - 3] == 0)
					{
						//考慮上一位喊出的線位
						if (B[b - 3] == 1)
						{
							//一半的機率喊新的花色
							if (C.v_rand_1 || C.v_rand_15 == 1)
							{
								//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
								//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
								//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
					//若上一個人喊四花色任一
					else if (A[b - 3] == 1)
					{
						//考慮上一位喊出的線位
						if (B[b - 3] == 1)
						{
							//一半的機率喊新的花色
							if (C.v_rand_1 || C.v_rand_15 == 1)
							{
								//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
								//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
								//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
						//考慮上一位喊出的線位
						if (B[b - 3] == 1)
						{
							//一半的機率喊新的花色
							if (C.v_rand_1 || C.v_rand_15 == 1)
							{
								//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
								//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
								//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
						//考慮上一位喊出的線位
						if (B[b - 3] == 1)
						{
							//一半的機率喊新的花色
							if (C.v_rand_1 || C.v_rand_15 == 1)
							{
								//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
								//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
								//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
						//考慮上一位喊出的線位
						if (B[b - 3] == 1)
						{
							//一半的機率喊新的花色
							if (C.v_rand_1 || C.v_rand_15 == 1)
							{
								//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
										//上一人喊的花色為梅花,固在此時喊黑桃,紅心,方塊皆可選擇線位是否要+1
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
								//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
										//上一人喊的花色為梅花,固在此時喊黑桃,紅心,方塊皆可選擇線位是否要+1
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
								//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
										//上一人喊的花色為梅花,固在此時喊黑桃,紅心,方塊皆可選擇線位是否要+1
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
					//若上一個人喊small
					else
					{
						//考慮上一位喊出的線位
						if (B[b - 3] == 1)
						{
							//一半的機率喊新的花色
							if (C.v_rand_1 || C.v_rand_15 == 1)
							{
								//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
								//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
								//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
		//參考b-2的牌!!
		else if (a == 1)
		{
			int partner_color[2]; //存取隊友叫過的花色
			int enemy1_color[2], enemy2_color[2]; //存取對方兩人叫過的花色
												  //會跟據隊友和隊手每人最近兩次叫牌進行分析
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
				//不會出現A[b-1]=6的情形,因為上上一個人必定沒有accept!!
				if (bubble_sort[0] == bubble_sort[1]) //假設找不到最佳解,此時無法明確決定要喊的花色
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
										//上一人喊的花色為梅花,固在此時喊黑桃,紅心,方塊皆可選擇線位是否要+1
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
										//上一人喊的花色為梅花,固在此時喊黑桃,紅心,方塊皆可選擇線位是否要+1
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
										//上一人喊的花色為梅花,固在此時喊黑桃,紅心,方塊皆可選擇線位是否要+1
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
					//先考慮花色,磴數看是+1或照舊!!
					//若上一個人喊無王
					if (A[b - 2] == 0)
					{
						//考慮上一位喊出的線位
						if (B[b - 2] == 1)
						{
							//一半的機率喊新的花色
							if (C.v_rand_1 || C.v_rand_15 == 1)
							{
								//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
								//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
								//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
					//若上一個人喊四花色任一
					else if (A[b - 2] == 1)
					{
						//考慮上一位喊出的線位
						if (B[b - 2] == 1)
						{
							//一半的機率喊新的花色
							if (C.v_rand_1 || C.v_rand_15 == 1)
							{
								//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
								//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
								//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
						//考慮上一位喊出的線位
						if (B[b - 2] == 1)
						{
							//一半的機率喊新的花色
							if (C.v_rand_1 || C.v_rand_15 == 1)
							{
								//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
								//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
								//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
						//考慮上一位喊出的線位
						if (B[b - 2] == 1)
						{
							//一半的機率喊新的花色
							if (C.v_rand_1 || C.v_rand_15 == 1)
							{
								//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
								//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
								//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
						//考慮上一位喊出的線位
						if (B[b - 2] == 1)
						{
							//一半的機率喊新的花色
							if (C.v_rand_1 || C.v_rand_15 == 1)
							{
								//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
										//上一人喊的花色為梅花,固在此時喊黑桃,紅心,方塊皆可選擇線位是否要+1
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
								//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
										//上一人喊的花色為梅花,固在此時喊黑桃,紅心,方塊皆可選擇線位是否要+1
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
								//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
										//上一人喊的花色為梅花,固在此時喊黑桃,紅心,方塊皆可選擇線位是否要+1
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
					//若上一個人喊small
					else
					{
						//考慮上一位喊出的線位
						if (B[b - 2] == 1)
						{
							//一半的機率喊新的花色
							if (C.v_rand_1 || C.v_rand_15 == 1)
							{
								//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
								//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
								//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
				/*假設花色最佳解為bubble_sort[0]所對應的花色!!*/
				//不會出現A[b-1]=6的情形,因為上一個人必定沒有accept!!
				if (bubble_sort[0] == bubble_sort[1]) //假設找不到最佳解,此時無法明確決定要喊的花色
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
										//上一人喊的花色為梅花,固在此時喊黑桃,紅心,方塊皆可選擇線位是否要+1
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
										//上一人喊的花色為梅花,固在此時喊黑桃,紅心,方塊皆可選擇線位是否要+1
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
										//上一人喊的花色為梅花,固在此時喊黑桃,紅心,方塊皆可選擇線位是否要+1
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
					//先考慮花色,磴數看是+1或照舊!!
					//若上一個人喊無王
					if (A[b - 2] == 0)
					{
						//考慮上一位喊出的線位
						if (B[b - 2] == 1)
						{
							//一半的機率喊新的花色
							if (C.v_rand_1 || C.v_rand_15 == 1)
							{
								//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
								//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
								//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
					//若上一個人喊四花色任一
					else if (A[b - 2] == 1)
					{
						//考慮上一位喊出的線位
						if (B[b - 2] == 1)
						{
							//一半的機率喊新的花色
							if (C.v_rand_1 || C.v_rand_15 == 1)
							{
								//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
								//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
								//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
						//考慮上一位喊出的線位
						if (B[b - 2] == 1)
						{
							//一半的機率喊新的花色
							if (C.v_rand_1 || C.v_rand_15 == 1)
							{
								//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
								//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
								//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
						//考慮上一位喊出的線位
						if (B[b - 2] == 1)
						{
							//一半的機率喊新的花色
							if (C.v_rand_1 || C.v_rand_15 == 1)
							{
								//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
								//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
								//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
						//考慮上一位喊出的線位
						if (B[b - 2] == 1)
						{
							//一半的機率喊新的花色
							if (C.v_rand_1 || C.v_rand_15 == 1)
							{
								//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
										//上一人喊的花色為梅花,固在此時喊黑桃,紅心,方塊皆可選擇線位是否要+1
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
								//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
										//上一人喊的花色為梅花,固在此時喊黑桃,紅心,方塊皆可選擇線位是否要+1
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
								//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
										//上一人喊的花色為梅花,固在此時喊黑桃,紅心,方塊皆可選擇線位是否要+1
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
					//若上一個人喊small
					else
					{
						//考慮上一位喊出的線位
						if (B[b - 2] == 1)
						{
							//一半的機率喊新的花色
							if (C.v_rand_1 || C.v_rand_15 == 1)
							{
								//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
								//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
								//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
								if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
								{
									//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
		//參考b-1的牌!!
		else
		{
			//如果沒有accept時,counter_stop=0
			//在這裡accept時,counter_stop=counter-1
			//b==0,第一個喊花色的人
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
						/*4花色其中之一,依序為Max_color,Second_color,Third_color,Min_color*/
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
				int partner_color[2]; //存取隊友叫過的花色
				int enemy1_color[2], enemy2_color[2]; //存取對方兩人叫過的花色
													  //會跟據隊友和隊手每人最近兩次叫牌進行分析
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
					if (bubble_sort[0] == bubble_sort[1]) //假設找不到最佳解,此時無法明確決定要喊的花色
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
											//上一人喊的花色為梅花,固在此時喊黑桃,紅心,方塊皆可選擇線位是否要+1
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
											//上一人喊的花色為梅花,固在此時喊黑桃,紅心,方塊皆可選擇線位是否要+1
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
											//上一人喊的花色為梅花,固在此時喊黑桃,紅心,方塊皆可選擇線位是否要+1
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
						//先考慮花色,磴數看是+1或照舊!!
						//若上一個人喊無王
						if (A[b - 1] == 0)
						{
							//考慮上一位喊出的線位
							if (B[b - 1] == 1)
							{
								//一半的機率喊新的花色
								if (C.v_rand_1 || C.v_rand_15 == 1)
								{
									//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
									if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
									{
										//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
									//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
									if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
									{
										//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
									//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
									if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
									{
										//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
						//若上一個人喊四花色任一
						else if (A[b - 1] == 1)
						{
							//考慮上一位喊出的線位
							if (B[b - 1] == 1)
							{
								//一半的機率喊新的花色
								if (C.v_rand_1 || C.v_rand_15 == 1)
								{
									//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
									if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
									{
										//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
									//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
									if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
									{
										//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
									//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
									if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
									{
										//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
							//考慮上一位喊出的線位
							if (B[b - 1] == 1)
							{
								//一半的機率喊新的花色
								if (C.v_rand_1 || C.v_rand_15 == 1)
								{
									//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
									if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
									{
										//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
									//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
									if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
									{
										//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
									//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
									if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
									{
										//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
							//考慮上一位喊出的線位
							if (B[b - 1] == 1)
							{
								//一半的機率喊新的花色
								if (C.v_rand_1 || C.v_rand_15 == 1)
								{
									//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
									if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
									{
										//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
									//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
									if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
									{
										//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
									//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
									if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
									{
										//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
							//考慮上一位喊出的線位
							if (B[b - 1] == 1)
							{
								//一半的機率喊新的花色
								if (C.v_rand_1 || C.v_rand_15 == 1)
								{
									//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
									if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
									{
										//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
											//上一人喊的花色為梅花,固在此時喊黑桃,紅心,方塊皆可選擇線位是否要+1
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
									//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
									if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
									{
										//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
											//上一人喊的花色為梅花,固在此時喊黑桃,紅心,方塊皆可選擇線位是否要+1
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
									//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
									if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
									{
										//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
											//上一人喊的花色為梅花,固在此時喊黑桃,紅心,方塊皆可選擇線位是否要+1
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
						//若上一個人喊small
						else
						{
							//考慮上一位喊出的線位
							if (B[b - 1] == 1)
							{
								//一半的機率喊新的花色
								if (C.v_rand_1 || C.v_rand_15 == 1)
								{
									//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
									if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
									{
										//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
									//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
									if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
									{
										//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
									//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
									if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
									{
										//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
					/*假設花色最佳解為bubble_sort[0]所對應的花色!!*/
					//不會出現A[b-1]=6的情形,因為上一個人必定沒有accept!!
					if (bubble_sort[0] == bubble_sort[1]) //假設找不到最佳解,此時無法明確決定要喊的花色
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
											//上一人喊的花色為梅花,固在此時喊黑桃,紅心,方塊皆可選擇線位是否要+1
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
											//上一人喊的花色為梅花,固在此時喊黑桃,紅心,方塊皆可選擇線位是否要+1
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
											//上一人喊的花色為梅花,固在此時喊黑桃,紅心,方塊皆可選擇線位是否要+1
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
						//先考慮花色,磴數看是+1或照舊!!
						//若上一個人喊無王
						if (A[b - 1] == 0)
						{
							//考慮上一位喊出的線位
							if (B[b - 1] == 1)
							{
								//一半的機率喊新的花色
								if (C.v_rand_1 || C.v_rand_15 == 1)
								{
									//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
									if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
									{
										//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
									//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
									if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
									{
										//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
									//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
									if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
									{
										//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
						//若上一個人喊四花色任一
						else if (A[b - 1] == 1)
						{
							//考慮上一位喊出的線位
							if (B[b - 1] == 1)
							{
								//一半的機率喊新的花色
								if (C.v_rand_1 || C.v_rand_15 == 1)
								{
									//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
									if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
									{
										//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
									//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
									if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
									{
										//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
									//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
									if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
									{
										//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
							//考慮上一位喊出的線位
							if (B[b - 1] == 1)
							{
								//一半的機率喊新的花色
								if (C.v_rand_1 || C.v_rand_15 == 1)
								{
									//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
									if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
									{
										//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
									//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
									if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
									{
										//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
									//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
									if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
									{
										//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
							//考慮上一位喊出的線位
							if (B[b - 1] == 1)
							{
								//一半的機率喊新的花色
								if (C.v_rand_1 || C.v_rand_15 == 1)
								{
									//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
									if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
									{
										//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
									//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
									if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
									{
										//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
									//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
									if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
									{
										//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
							//考慮上一位喊出的線位
							if (B[b - 1] == 1)
							{
								//一半的機率喊新的花色
								if (C.v_rand_1 || C.v_rand_15 == 1)
								{
									//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
									if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
									{
										//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
											//上一人喊的花色為梅花,固在此時喊黑桃,紅心,方塊皆可選擇線位是否要+1
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
									//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
									if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
									{
										//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
											//上一人喊的花色為梅花,固在此時喊黑桃,紅心,方塊皆可選擇線位是否要+1
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
									//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
									if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
									{
										//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
											//上一人喊的花色為梅花,固在此時喊黑桃,紅心,方塊皆可選擇線位是否要+1
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
						//若上一個人喊small
						else
						{
							//考慮上一位喊出的線位
							if (B[b - 1] == 1)
							{
								//一半的機率喊新的花色
								if (C.v_rand_1 || C.v_rand_15 == 1)
								{
									//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
									if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
									{
										//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
									//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
									if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
									{
										//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
									//考慮自己牌的資訊是否與最佳解重合,最後兩個條件為無王或small
									if ((best_state == D.state) || (best_state == E.state) || (a1&&b1&&c1&&d1) || e1 == 1)
									{
										//決定出最佳解時,判斷上一個人喊的花色為何,決定是否accept或喊新的花色
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
			//如果沒有accept時,counter_stop=0
		}
		else if (a == 1)
		{
			//如果沒有accept時,counter_stop=0
		}
		else
		{
			//如果沒有accept時,counter_stop=0
			//在這裡accept時,counter_stop=counter-1
			//第一個喊花色的人
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
						//4花色其中之一

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
		//無王
		if (this->auction_color == 0)
		{
			int no_trump_color[13], no_trump_number[13];
			/*
			在此段程式使用no_trump陣列代替原先的vCard陣列會造成以下錯誤:
			在電腦每次出牌時,將再一次地對vCard(手牌)陣列進行重排
			且此時會使得no_trump陣列裡的內容會有"完整的"13張牌
			以上便是遊戲過程中電鬧會重復出牌的原因

			原則上只要能排除掉被選中的牌就行
			可以在出完牌後,加上if判斷該張牌在vCard陣列中的位置後消除
			no_trump陣列的排序也需要重新考量
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
			//當局第一個出牌的
			if (b == 0)
			{
				//一律出最大牌
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
				//先判斷手上是否有和declarer所出的花色相同的牌
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
						//如果手中有牌能壓過declarer所出的牌
						if (counter2 != 0)
						{
							//如果已有人出過能壓過declarer所出的牌,true的情形下可以考慮積極出牌
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
												//此時隊友為出牌第二順位且已沒有該花色的牌
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
												此時情況有兩種
												1.隊友為莊家
												2.隊友為出牌第二順位且有該花色的牌
												if(b==2)
												else
												*/
												if (b == 2)
												{
													//如果隊友(莊家)的牌被壓過
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
											//7成5機率出同花色最大牌,或次大牌
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
												//此時隊友為出牌第二順位且已沒有該花色的牌
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
												此時情況有兩種
												1.隊友為莊家
												2.隊友為出牌第二順位且有該花色的牌
												if(b==2)
												else
												*/
												if (b == 2)
												{
													//如果隊友(莊家)的牌被壓過
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
											//同花色最大牌,或次大牌
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
												//此時隊友為出牌第二順位且已沒有該花色的牌
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
												此時情況有兩種
												1.隊友為莊家
												2.隊友為出牌第二順位且已沒有該花色的牌
												if(b==2)
												else
												*/
												if (b == 2)
												{
													//如果隊友(莊家)的牌被壓過
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
											//7成5機率出同花色最大牌,或次大牌
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
												//此時隊友為出牌第二順位且已沒有該花色的牌
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
												此時情況有兩種
												1.隊友為莊家
												2.隊友為出牌第二順位且已沒有該花色的牌
												if(b==2)
												else
												*/
												if (b == 2)
												{
													//如果隊友(莊家)的牌被壓過
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
											//3/4機率出同花色最大牌,或次大牌
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
							//出同花色數字最小的一張
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
						//如果手中有牌能壓過declarer所出的牌
						if (counter2 != 0)
						{
							//如果已有人出過能壓過declarer所出的牌,true的情形下可以考慮積極出牌
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
										//一半機率出同花色最大牌,或次大牌
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
							//出同花色數字最小的一張
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
					//出手中數字最小任意花色
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
		//四花色
		else if ((this->auction_color == 1) || (this->auction_color == 2) || (this->auction_color == 3) || (this->auction_color == 4) == 1)
		{
			int danger = 0;
			if (c == 0)
			{
				//輪到player3或player4出牌
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
				//輪到player2出牌
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
				//輪到player3或player4出牌
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
				//輪到player2出牌
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
				//輪到player3或player4出牌
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
				//輪到player2出牌
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
				//輪到player3或player4出牌
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
				//輪到player2出牌
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
			/*以上用於設定danger值為零或一*/
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
			//當局第一個出牌的
			if (b == 0)
			{
				//遊戲接近尾聲,考慮洗王
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
				//出除了王牌以外的最大牌
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
			//當局第一個出牌的
			if (b == 0)
			{
				//一律出最大牌
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
				//先判斷手上是否有和declarer所出的花色相同的牌
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
					//如果手中有牌能壓過declarer所出的牌
					if (counter2 != 0)
					{
						//如果已有人出過能壓過declarer所出的牌,true的情形下可以考慮積極出牌
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
										//一半機率出同花色最大牌,或次大牌
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
									//7成5機率出同花色最大牌,或次大牌
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
										//一半機率出同花色最大牌,或次大牌
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
						//出同花色數字最小的一張
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
					//出手中數字最小任意花色
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
				cout << "Player3出黑桃" << this->sCard_number[a] << endl;
			else if (this->sCard_color[a] == 2)
				cout << "Player3出紅心" << this->sCard_number[a] << endl;
			else if (this->sCard_color[a] == 3)
				cout << "Player3出方塊" << this->sCard_number[a] << endl;
			else if (this->sCard_color[a] == 4)
				cout << "Player3出梅花" << this->sCard_number[a] << endl;
			else
				return NULL;
		}
		else if (b == 1)
		{
			if (this->sCard_color[a] == 1)
				cout << "Player2出黑桃" << this->sCard_number[a] << endl;
			else if (this->sCard_color[a] == 2)
				cout << "Player2出紅心" << this->sCard_number[a] << endl;
			else if (this->sCard_color[a] == 3)
				cout << "Player2出方塊" << this->sCard_number[a] << endl;
			else if (this->sCard_color[a] == 4)
				cout << "Player2出梅花" << this->sCard_number[a] << endl;
			else
				return NULL;
		}
		else
		{
			if (this->sCard_color[a] == 1)
				cout << "Player4出黑桃" << this->sCard_number[a] << endl;
			else if (this->sCard_color[a] == 2)
				cout << "Player4出紅心" << this->sCard_number[a] << endl;
			else if (this->sCard_color[a] == 3)
				cout << "Player4出方塊" << this->sCard_number[a] << endl;
			else if (this->sCard_color[a] == 4)
				cout << "Player4出梅花" << this->sCard_number[a] << endl;
			else
				return NULL;
		}
	}
	else if (c == 1)
	{
		if (b == 0)
		{
			if (this->sCard_color[a] == 1)
				cout << "Player2出黑桃" << this->sCard_number[a] << endl;
			else if (this->sCard_color[a] == 2)
				cout << "Player2出紅心" << this->sCard_number[a] << endl;
			else if (this->sCard_color[a] == 3)
				cout << "Player2出方塊" << this->sCard_number[a] << endl;
			else if (this->sCard_color[a] == 4)
				cout << "Player2出梅花" << this->sCard_number[a] << endl;
			else
				return NULL;
		}
		else if (b == 1)
		{
			if (this->sCard_color[a] == 1)
				cout << "Player4出黑桃" << this->sCard_number[a] << endl;
			else if (this->sCard_color[a] == 2)
				cout << "Player4出紅心" << this->sCard_number[a] << endl;
			else if (this->sCard_color[a] == 3)
				cout << "Player4出方塊" << this->sCard_number[a] << endl;
			else if (this->sCard_color[a] == 4)
				cout << "Player4出梅花" << this->sCard_number[a] << endl;
			else
				return NULL;
		}
		else
		{
			if (this->sCard_color[a] == 1)
				cout << "Player3出黑桃" << this->sCard_number[a] << endl;
			else if (this->sCard_color[a] == 2)
				cout << "Player3出紅心" << this->sCard_number[a] << endl;
			else if (this->sCard_color[a] == 3)
				cout << "Player3出方塊" << this->sCard_number[a] << endl;
			else if (this->sCard_color[a] == 4)
				cout << "Player3出梅花" << this->sCard_number[a] << endl;
			else
				return NULL;
		}
	}
	else if (c == 2)
	{
		if (b == 0)
		{
			if (this->sCard_color[a] == 1)
				cout << "Player4出黑桃" << this->sCard_number[a] << endl;
			else if (this->sCard_color[a] == 2)
				cout << "Player4出紅心" << this->sCard_number[a] << endl;
			else if (this->sCard_color[a] == 3)
				cout << "Player4出方塊" << this->sCard_number[a] << endl;
			else if (this->sCard_color[a] == 4)
				cout << "Player4出梅花" << this->sCard_number[a] << endl;
			else
				return NULL;
		}
		else if (b == 2)
		{
			if (this->sCard_color[a] == 1)
				cout << "Player3出黑桃" << this->sCard_number[a] << endl;
			else if (this->sCard_color[a] == 2)
				cout << "Player3出紅心" << this->sCard_number[a] << endl;
			else if (this->sCard_color[a] == 3)
				cout << "Player3出方塊" << this->sCard_number[a] << endl;
			else if (this->sCard_color[a] == 4)
				cout << "Player3出梅花" << this->sCard_number[a] << endl;
			else
				return NULL;
		}
		else
		{
			if (this->sCard_color[a] == 1)
				cout << "Player2出黑桃" << this->sCard_number[a] << endl;
			else if (this->sCard_color[a] == 2)
				cout << "Player2出紅心" << this->sCard_number[a] << endl;
			else if (this->sCard_color[a] == 3)
				cout << "Player2出方塊" << this->sCard_number[a] << endl;
			else if (this->sCard_color[a] == 4)
				cout << "Player2出梅花" << this->sCard_number[a] << endl;
			else
				return NULL;
		}
	}
	else
	{
		if (b == 1)
		{
			if (this->sCard_color[a] == 1)
				cout << "Player3出黑桃" << this->sCard_number[a] << endl;
			else if (this->sCard_color[a] == 2)
				cout << "Player3出紅心" << this->sCard_number[a] << endl;
			else if (this->sCard_color[a] == 3)
				cout << "Player3出方塊" << this->sCard_number[a] << endl;
			else if (this->sCard_color[a] == 4)
				cout << "Player3出梅花" << this->sCard_number[a] << endl;
			else
				return NULL;
		}
		else if (b == 2)
		{
			if (this->sCard_color[a] == 1)
				cout << "Player2出黑桃" << this->sCard_number[a] << endl;
			else if (this->sCard_color[a] == 2)
				cout << "Player2出紅心" << this->sCard_number[a] << endl;
			else if (this->sCard_color[a] == 3)
				cout << "Player2出方塊" << this->sCard_number[a] << endl;
			else if (this->sCard_color[a] == 4)
				cout << "Player2出梅花" << this->sCard_number[a] << endl;
			else
				return NULL;
		}
		else
		{
			if (this->sCard_color[a] == 1)
				cout << "Player4出黑桃" << this->sCard_number[a] << endl;
			else if (this->sCard_color[a] == 2)
				cout << "Player4出紅心" << this->sCard_number[a] << endl;
			else if (this->sCard_color[a] == 3)
				cout << "Player4出方塊" << this->sCard_number[a] << endl;
			else if (this->sCard_color[a] == 4)
				cout << "Player4出梅花" << this->sCard_number[a] << endl;
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
	//以上用於整個遊戲過程中可能會遇到的隨機選擇
	funb(binary);
	B.set_player2_smart(binary[2], binary[1], binary[0]);
	C.set_player3_smart(binary[2], binary[1], binary[0]);
	D.set_player4_smart(binary[2], binary[1], binary[0]);
	//smart=0,1將會決定choose_color()和select_card()在運行時的決策
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
		temp1++; //用來trace是否AI真的有倒牌意願
				 //以下用來建立手牌
		A.set_data3();
		A.dealing(B, C, D, E);
		B.set_data_card();
		C.set_data_card();
		D.set_data_card();
		E.set_data_card();
		//以下是對AI的手牌做判讀以取得足夠的參數,
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
	首先,
	藉由get_data_card()使playerX.vCard[]存取playerX_card[]的值

	對所有的playerX.vCard[]判讀:
	(1)4種花色分別有多少
	(2)手牌之點數(依據player的smart將會決定是否要倒牌,此舉將會影響choose_color()的結果
	只對player1.vCard[]執行:
	(1)依花色,點數排序
	(2)顯示排序好的手牌於螢幕上

	確認不倒牌後,
	對除了player1.vCard[]的其餘vCard[]判讀:
	(1)依花色,點數進行排序(使用兩個for分別排花色和數字),並記錄最多張數,次多,直到最少,分別為何花色
	Ex:
	playerX_max_color='s'
	playerX_second_color='h'
	playerX_third_color='d'
	playerX_min_color='c'
	(2)對各花色設定其權重參數,每一花色皆有3個參數
	Ex:
	playerX_max_color_big_point
	playerX_max_color_small_point
	playerX_max_color_number

	最後,
	此時總共有(3+1)*4*3=48個參數,這些參數將用於"叫牌"階段和"出牌"階段
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
	int counter = 0; //counter用以記錄第幾位喊花色
	int counter_stop = 0;
	int temp = 0, temp1 = 0; //記錄總共run了幾輪
	this->sequence = 0;
	this->selector = 0;
	B.id = 1;
	C.id = 2;
	D.id = 3;
	E.id = 4;
	//以下先預設陣列的初始值
	for (int j = 0; j < 40; j++)
	{
		this->auction_color[j] = 7;
		this->auction_number[j] = 0;
	}
	fun_explanation3();
	do
	{
		//順時針旋轉為3,2,4,1=D,C,E,B
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
	this->funa(temp, this->sequence, this->selector, counter, counter_stop, this->auction_color, this->auction_number);//代入temp,sequence,selector
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
	//順時針旋轉為3,2,4,1=D,C,E,B
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
		/*以下部份為原始設計,在最後一輪時自動出牌
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
		此處應放置一函式用以判斷守方或攻方是否已拿到足夠的磴數
		需要的引數為:
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
	//沒人出和declarer同花色的牌或王牌
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
						cout << "此磴由player3拿下" << endl;
					}
					else if (B[4 * b + 1] == 1)
					{
						D.bid++;
						this->sequence = 1;
						cout << "此磴由player2拿下" << endl;
					}
					else if (B[4 * b + 1] > B[4 * b])
					{
						D.bid++;
						this->sequence = 1;
						cout << "此磴由player2拿下" << endl;
					}
					else
					{
						E.bid++;
						cout << "此磴由player3拿下" << endl;
					}
				}
				else if (this->sequence == 1)
				{
					if (B[4 * b] == 1)
					{
						D.bid++;
						cout << "此磴由player2拿下" << endl;
					}
					else if (B[4 * b + 1] == 1)
					{
						F.bid++;
						this->sequence = 2;
						cout << "此磴由player4拿下" << endl;
					}
					else if (B[4 * b + 1] > B[4 * b])
					{
						F.bid++;
						this->sequence = 2;
						cout << "此磴由player4拿下" << endl;
					}
					else
					{
						D.bid++;
						cout << "此磴由player2拿下" << endl;
					}
				}
				else if (this->sequence == 2)
				{
					if (B[4 * b] == 1)
					{
						F.bid++;
						cout << "此磴由player4拿下" << endl;
					}
					else if (B[4 * b + 1] == 1)
					{
						C.bid++;
						this->sequence = 3;
						cout << "此磴由玩家拿下" << endl;
					}
					else if (B[4 * b + 1] > B[4 * b])
					{
						C.bid++;
						this->sequence = 3;
						cout << "此磴由玩家拿下" << endl;
					}
					else
					{
						F.bid++;
						cout << "此磴由player4拿下" << endl;
					}
				}
				else
				{
					if (B[4 * b] == 1)
					{
						C.bid++;
						cout << "此磴由玩家拿下" << endl;
					}
					else if (B[4 * b + 1] == 1)
					{
						E.bid++;
						this->sequence = 0;
						cout << "此磴由player3拿下" << endl;
					}
					else if (B[4 * b + 1] > B[4 * b])
					{
						E.bid++;
						this->sequence = 0;
						cout << "此磴由player3拿下" << endl;
					}
					else
					{
						C.bid++;
						cout << "此磴由玩家拿下" << endl;
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
						cout << "此磴由player3拿下" << endl;
					}
					else if (B[4 * b + 1] == 2)
					{
						D.bid++;
						this->sequence = 1;
						cout << "此磴由player2拿下" << endl;
					}
					else if (B[4 * b + 1] < B[4 * b])
					{
						D.bid++;
						this->sequence = 1;
						cout << "此磴由player2拿下" << endl;
					}
					else
					{
						E.bid++;
						cout << "此磴由player3拿下" << endl;
					}
				}
				else if (this->sequence == 1)
				{
					if (B[4 * b] == 2)
					{
						D.bid++;
						cout << "此磴由player2拿下" << endl;
					}
					else if (B[4 * b + 1] == 2)
					{
						F.bid++;
						this->sequence = 2;
						cout << "此磴由player4拿下" << endl;
					}
					else if (B[4 * b + 1] < B[4 * b])
					{
						F.bid++;
						this->sequence = 2;
						cout << "此磴由player4拿下" << endl;
					}
					else
					{
						D.bid++;
						cout << "此磴由player2拿下" << endl;
					}
				}
				else if (this->sequence == 2)
				{
					if (B[4 * b] == 2)
					{
						F.bid++;
						cout << "此磴由player4拿下" << endl;
					}
					else if (B[4 * b + 1] == 2)
					{
						C.bid++;
						this->sequence = 3;
						cout << "此磴由玩家拿下" << endl;
					}
					else if (B[4 * b + 1] < B[4 * b])
					{
						C.bid++;
						this->sequence = 3;
						cout << "此磴由玩家拿下" << endl;
					}
					else
					{
						F.bid++;
						cout << "此磴由player4拿下" << endl;
					}
				}
				else
				{
					if (B[4 * b] == 2)
					{
						C.bid++;
						cout << "此磴由玩家拿下" << endl;
					}
					else if (B[4 * b + 1] == 2)
					{
						E.bid++;
						this->sequence = 0;
						cout << "此磴由player3拿下" << endl;
					}
					else if (B[4 * b + 1] < B[4 * b])
					{
						E.bid++;
						this->sequence = 0;
						cout << "此磴由player3拿下" << endl;
					}
					else
					{
						C.bid++;
						cout << "此磴由玩家拿下" << endl;
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
								cout << "此磴由player3拿下" << endl;
							}
							else if (B[4 * b + 1] == 1)
							{
								D.bid++;
								this->sequence = 1;
								cout << "此磴由player2拿下" << endl;
							}
							else if (B[4 * b + 1] > B[4 * b])
							{
								D.bid++;
								this->sequence = 1;
								cout << "此磴由player2拿下" << endl;
							}
							else
							{
								E.bid++;
								cout << "此磴由player3拿下" << endl;
							}
						}
						else
						{
							E.bid++;
							cout << "此磴由player3拿下" << endl;
						}
					}
					else
					{
						if (A[4 * b + 1] != this->final_color)
						{
							if (B[4 * b] == 1)
							{
								E.bid++;
								cout << "此磴由player3拿下" << endl;
							}
							else if (B[4 * b + 1] == 1)
							{
								D.bid++;
								this->sequence = 1;
								cout << "此磴由player2拿下" << endl;
							}
							else if (B[4 * b + 1] > B[4 * b])
							{
								D.bid++;
								this->sequence = 1;
								cout << "此磴由player2拿下" << endl;
							}
							else
							{
								E.bid++;
								cout << "此磴由player3拿下" << endl;
							}
						}
						else
						{
							D.bid++;
							this->sequence = 1;
							cout << "此磴由player2拿下" << endl;
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
								cout << "此磴由player2拿下" << endl;
							}
							else if (B[4 * b + 1] == 1)
							{
								F.bid++;
								this->sequence = 2;
								cout << "此磴由player4拿下" << endl;
							}
							else if (B[4 * b + 1] > B[4 * b])
							{
								F.bid++;
								this->sequence = 2;
								cout << "此磴由player4拿下" << endl;
							}
							else
							{
								D.bid++;
								cout << "此磴由player2拿下" << endl;
							}
						}
						else
						{
							D.bid++;
							cout << "此磴由player2拿下" << endl;
						}
					}
					else
					{
						if (A[4 * b + 1] != this->final_color)
						{
							if (B[4 * b] == 1)
							{
								D.bid++;
								cout << "此磴由player2拿下" << endl;
							}
							else if (B[4 * b + 1] == 1)
							{
								F.bid++;
								this->sequence = 2;
								cout << "此磴由player4拿下" << endl;
							}
							else if (B[4 * b + 1] > B[4 * b])
							{
								F.bid++;
								this->sequence = 2;
								cout << "此磴由player4拿下" << endl;
							}
							else
							{
								D.bid++;
								cout << "此磴由player2拿下" << endl;
							}
						}
						else
						{
							F.bid++;
							this->sequence = 2;
							cout << "此磴由player4拿下" << endl;
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
								cout << "此磴由player4拿下" << endl;
							}
							else if (B[4 * b + 1] == 1)
							{
								C.bid++;
								this->sequence = 3;
								cout << "此磴由玩家拿下" << endl;
							}
							else if (B[4 * b + 1] > B[4 * b])
							{
								C.bid++;
								this->sequence = 3;
								cout << "此磴由玩家拿下" << endl;
							}
							else
							{
								F.bid++;
								cout << "此磴由player4拿下" << endl;
							}
						}
						else
						{
							F.bid++;
							cout << "此磴由player4拿下" << endl;
						}
					}
					else
					{
						if (A[4 * b + 1] != this->final_color)
						{
							if (B[4 * b] == 1)
							{
								F.bid++;
								cout << "此磴由player4拿下" << endl;
							}
							else if (B[4 * b + 1] == 1)
							{
								C.bid++;
								this->sequence = 3;
								cout << "此磴由玩家拿下" << endl;
							}
							else if (B[4 * b + 1] > B[4 * b])
							{
								C.bid++;
								this->sequence = 3;
								cout << "此磴由玩家拿下" << endl;
							}
							else
							{
								F.bid++;
								cout << "此磴由player4拿下" << endl;
							}
						}
						else
						{
							C.bid++;
							this->sequence = 3;
							cout << "此磴由玩家拿下" << endl;
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
								cout << "此磴由玩家拿下" << endl;
							}
							else if (B[4 * b + 1] == 1)
							{
								E.bid++;
								this->sequence = 0;
								cout << "此磴由player3拿下" << endl;
							}
							else if (B[4 * b + 1] > B[4 * b])
							{
								E.bid++;
								this->sequence = 0;
								cout << "此磴由player3拿下" << endl;
							}
							else
							{
								C.bid++;
								cout << "此磴由玩家拿下" << endl;
							}
						}
						else
						{
							C.bid++;
							cout << "此磴由玩家拿下" << endl;
						}
					}
					else
					{
						if (A[4 * b + 1] != this->final_color)
						{
							if (B[4 * b] == 1)
							{
								C.bid++;
								cout << "此磴由玩家拿下" << endl;
							}
							else if (B[4 * b + 1] == 1)
							{
								E.bid++;
								this->sequence = 0;
								cout << "此磴由player3拿下" << endl;
							}
							else if (B[4 * b + 1] > B[4 * b])
							{
								E.bid++;
								this->sequence = 0;
								cout << "此磴由player3拿下" << endl;
							}
							else
							{
								C.bid++;
								cout << "此磴由玩家拿下" << endl;
							}
						}
						else
						{
							E.bid++;
							this->sequence = 0;
							cout << "此磴由player3拿下" << endl;
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
						cout << "此磴由player3拿下" << endl;
					}
					else if (B[4 * b + 2] == 1)
					{
						F.bid++;
						this->sequence = 2;
						cout << "此磴由player4拿下" << endl;
					}
					else if (B[4 * b + 2] > B[4 * b])
					{
						F.bid++;
						this->sequence = 2;
						cout << "此磴由player4拿下" << endl;
					}
					else
					{
						E.bid++;
						cout << "此磴由player3拿下" << endl;
					}
				}
				else if (this->sequence == 1)
				{
					if (B[4 * b] == 1)
					{
						D.bid++;
						cout << "此磴由player2拿下" << endl;
					}
					else if (B[4 * b + 2] == 1)
					{
						C.bid++;
						this->sequence = 3;
						cout << "此磴由玩家拿下" << endl;
					}
					else if (B[4 * b + 2] > B[4 * b])
					{
						C.bid++;
						this->sequence = 3;
						cout << "此磴由玩家拿下" << endl;
					}
					else
					{
						D.bid++;
						cout << "此磴由player2拿下" << endl;
					}
				}
				else if (this->sequence == 2)
				{
					if (B[4 * b] == 1)
					{
						F.bid++;
						cout << "此磴由player4拿下" << endl;
					}
					else if (B[4 * b + 2] == 1)
					{
						E.bid++;
						this->sequence = 0;
						cout << "此磴由player3拿下" << endl;
					}
					else if (B[4 * b + 2] > B[4 * b])
					{
						E.bid++;
						this->sequence = 0;
						cout << "此磴由player3拿下" << endl;
					}
					else
					{
						F.bid++;
						cout << "此磴由player4拿下" << endl;
					}
				}
				else
				{
					if (B[4 * b] == 1)
					{
						C.bid++;
						cout << "此磴由玩家拿下" << endl;
					}
					else if (B[4 * b + 2] == 1)
					{
						D.bid++;
						this->sequence = 1;
						cout << "此磴由player2拿下" << endl;
					}
					else if (B[4 * b + 2] > B[4 * b])
					{
						D.bid++;
						this->sequence = 1;
						cout << "此磴由player2拿下" << endl;
					}
					else
					{
						C.bid++;
						cout << "此磴由玩家拿下" << endl;
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
						cout << "此磴由player3拿下" << endl;
					}
					else if (B[4 * b + 2] == 2)
					{
						F.bid++;
						this->sequence = 2;
						cout << "此磴由player4拿下" << endl;
					}
					else if (B[4 * b + 2] < B[4 * b])
					{
						F.bid++;
						this->sequence = 2;
						cout << "此磴由player4拿下" << endl;
					}
					else
					{
						E.bid++;
						cout << "此磴由player3拿下" << endl;
					}
				}
				else if (this->sequence == 1)
				{
					if (B[4 * b] == 2)
					{
						D.bid++;
						cout << "此磴由player2拿下" << endl;
					}
					else if (B[4 * b + 2] == 2)
					{
						C.bid++;
						this->sequence = 3;
						cout << "此磴由玩家拿下" << endl;
					}
					else if (B[4 * b + 2] < B[4 * b])
					{
						C.bid++;
						this->sequence = 3;
						cout << "此磴由玩家拿下" << endl;
					}
					else
					{
						D.bid++;
						cout << "此磴由player2拿下" << endl;
					}
				}
				else if (this->sequence == 2)
				{
					if (B[4 * b] == 2)
					{
						F.bid++;
						cout << "此磴由player4拿下" << endl;
					}
					else if (B[4 * b + 2] == 2)
					{
						E.bid++;
						this->sequence = 0;
						cout << "此磴由player3拿下" << endl;
					}
					else if (B[4 * b + 2] < B[4 * b])
					{
						E.bid++;
						this->sequence = 0;
						cout << "此磴由player3拿下" << endl;
					}
					else
					{
						F.bid++;
						cout << "此磴由player4拿下" << endl;
					}
				}
				else
				{
					if (B[4 * b] == 2)
					{
						C.bid++;
						cout << "此磴由玩家拿下" << endl;
					}
					else if (B[4 * b + 2] == 2)
					{
						D.bid++;
						this->sequence = 1;
						cout << "此磴由player2拿下" << endl;
					}
					else if (B[4 * b + 2] < B[4 * b])
					{
						D.bid++;
						this->sequence = 1;
						cout << "此磴由player2拿下" << endl;
					}
					else
					{
						C.bid++;
						cout << "此磴由玩家拿下" << endl;
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
								cout << "此磴由player3拿下" << endl;
							}
							else if (B[4 * b + 2] == 1)
							{
								F.bid++;
								this->sequence = 2;
								cout << "此磴由player4拿下" << endl;
							}
							else if (B[4 * b + 2] > B[4 * b])
							{
								F.bid++;
								this->sequence = 2;
								cout << "此磴由player4拿下" << endl;
							}
							else
							{
								E.bid++;
								cout << "此磴由player3拿下" << endl;
							}
						}
						else
						{
							E.bid++;
							cout << "此磴由player3拿下" << endl;
						}
					}
					else
					{
						if (A[4 * b + 2] != this->final_color)
						{
							if (B[4 * b] == 1)
							{
								E.bid++;
								cout << "此磴由player3拿下" << endl;
							}
							else if (B[4 * b + 2] == 1)
							{
								F.bid++;
								this->sequence = 2;
								cout << "此磴由player4拿下" << endl;
							}
							else if (B[4 * b + 2] > B[4 * b])
							{
								F.bid++;
								this->sequence = 2;
								cout << "此磴由player4拿下" << endl;
							}
							else
							{
								E.bid++;
								cout << "此磴由player3拿下" << endl;
							}
						}
						else
						{
							F.bid++;
							this->sequence = 2;
							cout << "此磴由player4拿下" << endl;
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
								cout << "此磴由player2拿下" << endl;
							}
							else if (B[4 * b + 2] == 1)
							{
								C.bid++;
								this->sequence = 3;
								cout << "此磴由玩家拿下" << endl;
							}
							else if (B[4 * b + 2] > B[4 * b])
							{
								C.bid++;
								this->sequence = 3;
								cout << "此磴由玩家拿下" << endl;
							}
							else
							{
								D.bid++;
								cout << "此磴由player2拿下" << endl;
							}
						}
						else
						{
							D.bid++;
							cout << "此磴由player2拿下" << endl;
						}
					}
					else
					{
						if (A[4 * b + 2] != this->final_color)
						{
							if (B[4 * b] == 1)
							{
								D.bid++;
								cout << "此磴由player2拿下" << endl;
							}
							else if (B[4 * b + 2] == 1)
							{
								C.bid++;
								this->sequence = 3;
								cout << "此磴由玩家拿下" << endl;
							}
							else if (B[4 * b + 2] > B[4 * b])
							{
								C.bid++;
								this->sequence = 3;
								cout << "此磴由玩家拿下" << endl;
							}
							else
							{
								D.bid++;
								cout << "此磴由player2拿下" << endl;
							}
						}
						else
						{
							C.bid++;
							this->sequence = 3;
							cout << "此磴由玩家拿下" << endl;
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
								cout << "此磴由player4拿下" << endl;
							}
							else if (B[4 * b + 2] == 1)
							{
								E.bid++;
								this->sequence = 0;
								cout << "此磴由player3拿下" << endl;
							}
							else if (B[4 * b + 2] > B[4 * b])
							{
								E.bid++;
								this->sequence = 0;
								cout << "此磴由player3拿下" << endl;
							}
							else
							{
								F.bid++;
								cout << "此磴由player4拿下" << endl;
							}
						}
						else
						{
							F.bid++;
							cout << "此磴由player4拿下" << endl;
						}
					}
					else
					{
						if (A[4 * b + 2] != this->final_color)
						{
							if (B[4 * b] == 1)
							{
								F.bid++;
								cout << "此磴由player4拿下" << endl;
							}
							else if (B[4 * b + 2] == 1)
							{
								E.bid++;
								this->sequence = 0;
								cout << "此磴由player3拿下" << endl;
							}
							else if (B[4 * b + 2] > B[4 * b])
							{
								E.bid++;
								this->sequence = 0;
								cout << "此磴由player3拿下" << endl;
							}
							else
							{
								F.bid++;
								cout << "此磴由player4拿下" << endl;
							}
						}
						else
						{
							E.bid++;
							this->sequence = 0;
							cout << "此磴由player3拿下" << endl;
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
								cout << "此磴由玩家拿下" << endl;
							}
							else if (B[4 * b + 2] == 1)
							{
								D.bid++;
								this->sequence = 1;
								cout << "此磴由player2拿下" << endl;
							}
							else if (B[4 * b + 2] > B[4 * b])
							{
								D.bid++;
								this->sequence = 1;
								cout << "此磴由player2拿下" << endl;
							}
							else
							{
								C.bid++;
								cout << "此磴由玩家拿下" << endl;
							}
						}
						else
						{
							C.bid++;
							cout << "此磴由玩家拿下" << endl;
						}
					}
					else
					{
						if (A[4 * b + 2] != this->final_color)
						{
							if (B[4 * b] == 1)
							{
								C.bid++;
								cout << "此磴由玩家拿下" << endl;
							}
							else if (B[4 * b + 2] == 1)
							{
								D.bid++;
								this->sequence = 1;
								cout << "此磴由player2拿下" << endl;
							}
							else if (B[4 * b + 2] > B[4 * b])
							{
								D.bid++;
								this->sequence = 1;
								cout << "此磴由player2拿下" << endl;
							}
							else
							{
								C.bid++;
								cout << "此磴由玩家拿下" << endl;
							}
						}
						else
						{
							D.bid++;
							this->sequence = 1;
							cout << "此磴由player2拿下" << endl;
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
						cout << "此磴由player3拿下" << endl;
					}
					else if (B[4 * b + 1] == 1)
					{
						D.bid++;
						this->sequence = 1;
						cout << "此磴由player2拿下" << endl;
					}
					else if (B[4 * b + 1] > B[4 * b])
					{
						D.bid++;
						this->sequence = 1;
						cout << "此磴由player2拿下" << endl;
					}
					else
					{
						E.bid++;
						cout << "此磴由player3拿下" << endl;
					}
				}
				else if (this->sequence == 1)
				{
					if (B[4 * b] == 1)
					{
						D.bid++;
						cout << "此磴由player2拿下" << endl;
					}
					else if (B[4 * b + 1] == 1)
					{
						F.bid++;
						this->sequence = 2;
						cout << "此磴由player4拿下" << endl;
					}
					else if (B[4 * b + 1] > B[4 * b])
					{
						F.bid++;
						this->sequence = 2;
						cout << "此磴由player4拿下" << endl;
					}
					else
					{
						D.bid++;
						cout << "此磴由player2拿下" << endl;
					}
				}
				else if (this->sequence == 2)
				{
					if (B[4 * b] == 1)
					{
						F.bid++;
						cout << "此磴由player4拿下" << endl;
					}
					else if (B[4 * b + 1] == 1)
					{
						C.bid++;
						this->sequence = 3;
						cout << "此磴由玩家拿下" << endl;
					}
					else if (B[4 * b + 1] > B[4 * b])
					{
						C.bid++;
						this->sequence = 3;
						cout << "此磴由玩家拿下" << endl;
					}
					else
					{
						F.bid++;
						cout << "此磴由player4拿下" << endl;
					}
				}
				else
				{
					if (B[4 * b] == 1)
					{
						C.bid++;
						cout << "此磴由玩家拿下" << endl;
					}
					else if (B[4 * b + 1] == 1)
					{
						E.bid++;
						this->sequence = 0;
						cout << "此磴由player3拿下" << endl;
					}
					else if (B[4 * b + 1] > B[4 * b])
					{
						E.bid++;
						this->sequence = 0;
						cout << "此磴由player3拿下" << endl;
					}
					else
					{
						C.bid++;
						cout << "此磴由玩家拿下" << endl;
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
						cout << "此磴由player3拿下" << endl;
					}
					else if (B[4 * b + 1] == 2)
					{
						D.bid++;
						this->sequence = 1;
						cout << "此磴由player2拿下" << endl;
					}
					else if (B[4 * b + 1] < B[4 * b])
					{
						D.bid++;
						this->sequence = 1;
						cout << "此磴由player2拿下" << endl;
					}
					else
					{
						E.bid++;
						cout << "此磴由player3拿下" << endl;
					}
				}
				else if (this->sequence == 1)
				{
					if (B[4 * b] == 2)
					{
						D.bid++;
						cout << "此磴由player2拿下" << endl;
					}
					else if (B[4 * b + 1] == 2)
					{
						F.bid++;
						this->sequence = 2;
						cout << "此磴由player4拿下" << endl;
					}
					else if (B[4 * b + 1] < B[4 * b])
					{
						F.bid++;
						this->sequence = 2;
						cout << "此磴由player4拿下" << endl;
					}
					else
					{
						D.bid++;
						cout << "此磴由player2拿下" << endl;
					}
				}
				else if (this->sequence == 2)
				{
					if (B[4 * b] == 2)
					{
						F.bid++;
						cout << "此磴由player4拿下" << endl;
					}
					else if (B[4 * b + 1] == 2)
					{
						C.bid++;
						this->sequence = 3;
						cout << "此磴由玩家拿下" << endl;
					}
					else if (B[4 * b + 1] < B[4 * b])
					{
						C.bid++;
						this->sequence = 3;
						cout << "此磴由玩家拿下" << endl;
					}
					else
					{
						F.bid++;
						cout << "此磴由player4拿下" << endl;
					}
				}
				else
				{
					if (B[4 * b] == 2)
					{
						C.bid++;
						cout << "此磴由玩家拿下" << endl;
					}
					else if (B[4 * b + 1] == 2)
					{
						E.bid++;
						this->sequence = 0;
						cout << "此磴由player3拿下" << endl;
					}
					else if (B[4 * b + 1] < B[4 * b])
					{
						E.bid++;
						this->sequence = 0;
						cout << "此磴由player3拿下" << endl;
					}
					else
					{
						C.bid++;
						cout << "此磴由玩家拿下" << endl;
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
								cout << "此磴由player3拿下" << endl;
							}
							else if (B[4 * b + 1] == 1)
							{
								D.bid++;
								this->sequence = 1;
								cout << "此磴由player2拿下" << endl;
							}
							else if (B[4 * b + 1] > B[4 * b])
							{
								D.bid++;
								this->sequence = 1;
								cout << "此磴由player2拿下" << endl;
							}
							else
							{
								E.bid++;
								cout << "此磴由player3拿下" << endl;
							}
						}
						else
						{
							E.bid++;
							cout << "此磴由player3拿下" << endl;
						}
					}
					else
					{
						if (A[4 * b + 1] != this->final_color)
						{
							if (B[4 * b] == 1)
							{
								E.bid++;
								cout << "此磴由player3拿下" << endl;
							}
							else if (B[4 * b + 1] == 1)
							{
								D.bid++;
								this->sequence = 1;
								cout << "此磴由player2拿下" << endl;
							}
							else if (B[4 * b + 1] > B[4 * b])
							{
								D.bid++;
								this->sequence = 1;
								cout << "此磴由player2拿下" << endl;
							}
							else
							{
								E.bid++;
								cout << "此磴由player3拿下" << endl;
							}
						}
						else
						{
							D.bid++;
							this->sequence = 1;
							cout << "此磴由player2拿下" << endl;
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
								cout << "此磴由player2拿下" << endl;
							}
							else if (B[4 * b + 1] == 1)
							{
								F.bid++;
								this->sequence = 2;
								cout << "此磴由player4拿下" << endl;
							}
							else if (B[4 * b + 1] > B[4 * b])
							{
								F.bid++;
								this->sequence = 2;
								cout << "此磴由player4拿下" << endl;
							}
							else
							{
								D.bid++;
								cout << "此磴由player2拿下" << endl;
							}
						}
						else
						{
							D.bid++;
							cout << "此磴由player2拿下" << endl;
						}
					}
					else
					{
						if (A[4 * b + 1] != this->final_color)
						{
							if (B[4 * b] == 1)
							{
								D.bid++;
								cout << "此磴由player2拿下" << endl;
							}
							else if (B[4 * b + 1] == 1)
							{
								F.bid++;
								this->sequence = 2;
								cout << "此磴由player4拿下" << endl;
							}
							else if (B[4 * b + 1] > B[4 * b])
							{
								F.bid++;
								this->sequence = 2;
								cout << "此磴由player4拿下" << endl;
							}
							else
							{
								D.bid++;
								cout << "此磴由player2拿下" << endl;
							}
						}
						else
						{
							F.bid++;
							this->sequence = 2;
							cout << "此磴由player4拿下" << endl;
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
								cout << "此磴由player4拿下" << endl;
							}
							else if (B[4 * b + 1] == 1)
							{
								C.bid++;
								this->sequence = 3;
								cout << "此磴由玩家拿下" << endl;
							}
							else if (B[4 * b + 1] > B[4 * b])
							{
								C.bid++;
								this->sequence = 3;
								cout << "此磴由玩家拿下" << endl;
							}
							else
							{
								F.bid++;
								cout << "此磴由player4拿下" << endl;
							}
						}
						else
						{
							F.bid++;
							cout << "此磴由player4拿下" << endl;
						}
					}
					else
					{
						if (A[4 * b + 1] != this->final_color)
						{
							if (B[4 * b] == 1)
							{
								F.bid++;
								cout << "此磴由player4拿下" << endl;
							}
							else if (B[4 * b + 1] == 1)
							{
								C.bid++;
								this->sequence = 3;
								cout << "此磴由玩家拿下" << endl;
							}
							else if (B[4 * b + 1] > B[4 * b])
							{
								C.bid++;
								this->sequence = 3;
								cout << "此磴由玩家拿下" << endl;
							}
							else
							{
								F.bid++;
								cout << "此磴由player4拿下" << endl;
							}
						}
						else
						{
							C.bid++;
							this->sequence = 3;
							cout << "此磴由玩家拿下" << endl;
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
								cout << "此磴由玩家拿下" << endl;
							}
							else if (B[4 * b + 1] == 1)
							{
								E.bid++;
								this->sequence = 0;
								cout << "此磴由player3拿下" << endl;
							}
							else if (B[4 * b + 1] > B[4 * b])
							{
								E.bid++;
								this->sequence = 0;
								cout << "此磴由player3拿下" << endl;
							}
							else
							{
								C.bid++;
								cout << "此磴由玩家拿下" << endl;
							}
						}
						else
						{
							C.bid++;
							cout << "此磴由玩家拿下" << endl;
						}
					}
					else
					{
						if (A[4 * b + 1] != this->final_color)
						{
							if (B[4 * b] == 1)
							{
								C.bid++;
								cout << "此磴由玩家拿下" << endl;
							}
							else if (B[4 * b + 1] == 1)
							{
								E.bid++;
								this->sequence = 0;
								cout << "此磴由player3拿下" << endl;
							}
							else if (B[4 * b + 1] > B[4 * b])
							{
								E.bid++;
								this->sequence = 0;
								cout << "此磴由player3拿下" << endl;
							}
							else
							{
								C.bid++;
								cout << "此磴由玩家拿下" << endl;
							}
						}
						else
						{
							E.bid++;
							this->sequence = 0;
							cout << "此磴由player3拿下" << endl;
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
					cout << "此磴由player3拿下" << endl;
				}
				else if (temp3 == 1)
				{
					D.bid++;
					this->sequence = 1;
					cout << "此磴由player2拿下" << endl;
				}
				else if (temp3 == 2)
				{
					F.bid++;
					this->sequence = 2;
					cout << "此磴由player4拿下" << endl;
				}
				else
				{
					C.bid++;
					this->sequence = 3;
					cout << "此磴由玩家拿下" << endl;
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
					cout << "此磴由player2拿下" << endl;
				}
				else if (temp3 == 1)
				{
					F.bid++;
					this->sequence = 2;
					cout << "此磴由player4拿下" << endl;
				}
				else if (temp3 == 2)
				{
					C.bid++;
					this->sequence = 3;
					cout << "此磴由玩家拿下" << endl;
				}
				else
				{
					E.bid++;
					this->sequence = 0;
					cout << "此磴由player3拿下" << endl;
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
					cout << "此磴由player4拿下" << endl;
				}
				else if (temp3 == 1)
				{
					C.bid++;
					this->sequence = 3;
					cout << "此磴由玩家拿下" << endl;
				}
				else if (temp3 == 2)
				{
					E.bid++;
					this->sequence = 0;
					cout << "此磴由player3拿下" << endl;
				}
				else
				{
					D.bid++;
					this->sequence = 1;
					cout << "此磴由player2拿下" << endl;
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
					cout << "此磴由玩家拿下" << endl;
				}
				else if (temp3 == 1)
				{
					E.bid++;
					this->sequence = 0;
					cout << "此磴由player3拿下" << endl;
				}
				else if (temp3 == 2)
				{
					D.bid++;
					this->sequence = 1;
					cout << "此磴由player2拿下" << endl;
				}
				else
				{
					F.bid++;
					this->sequence = 2;
					cout << "此磴由player4拿下" << endl;
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
					cout << "此磴由player3拿下" << endl;
				}
				else if (temp3 == 1)
				{
					D.bid++;
					this->sequence = 1;
					cout << "此磴由player2拿下" << endl;
				}
				else if (temp3 == 2)
				{
					F.bid++;
					this->sequence = 2;
					cout << "此磴由player4拿下" << endl;
				}
				else
				{
					C.bid++;
					this->sequence = 3;
					cout << "此磴由玩家拿下" << endl;
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
					cout << "此磴由player2拿下" << endl;
				}
				else if (temp3 == 1)
				{
					F.bid++;
					this->sequence = 2;
					cout << "此磴由player4拿下" << endl;
				}
				else if (temp3 == 2)
				{
					C.bid++;
					this->sequence = 3;
					cout << "此磴由玩家拿下" << endl;
				}
				else
				{
					E.bid++;
					this->sequence = 0;
					cout << "此磴由player3拿下" << endl;
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
					cout << "此磴由player4拿下" << endl;
				}
				else if (temp3 == 1)
				{
					C.bid++;
					this->sequence = 3;
					cout << "此磴由玩家拿下" << endl;
				}
				else if (temp3 == 2)
				{
					E.bid++;
					this->sequence = 0;
					cout << "此磴由player3拿下" << endl;
				}
				else
				{
					D.bid++;
					this->sequence = 1;
					cout << "此磴由player2拿下" << endl;
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
					cout << "此磴由玩家拿下" << endl;
				}
				else if (temp3 == 1)
				{
					E.bid++;
					this->sequence = 0;
					cout << "此磴由player3拿下" << endl;
				}
				else if (temp3 == 2)
				{
					D.bid++;
					this->sequence = 1;
					cout << "此磴由player2拿下" << endl;
				}
				else
				{
					F.bid++;
					this->sequence = 2;
					cout << "此磴由player4拿下" << endl;
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
					cout << "此磴由player3拿下" << endl;
				}
				else if (temp3 == 1)
				{
					D.bid++;
					this->sequence = 1;
					cout << "此磴由player2拿下" << endl;
				}
				else if (temp3 == 2)
				{
					F.bid++;
					this->sequence = 2;
					cout << "此磴由player4拿下" << endl;
				}
				else
				{
					C.bid++;
					this->sequence = 3;
					cout << "此磴由玩家拿下" << endl;
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
					cout << "此磴由player2拿下" << endl;
				}
				else if (temp3 == 1)
				{
					F.bid++;
					this->sequence = 2;
					cout << "此磴由player4拿下" << endl;
				}
				else if (temp3 == 2)
				{
					C.bid++;
					this->sequence = 3;
					cout << "此磴由玩家拿下" << endl;
				}
				else
				{
					E.bid++;
					this->sequence = 0;
					cout << "此磴由player3拿下" << endl;
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
					cout << "此磴由player4拿下" << endl;
				}
				else if (temp3 == 1)
				{
					C.bid++;
					this->sequence = 3;
					cout << "此磴由玩家拿下" << endl;
				}
				else if (temp3 == 2)
				{
					E.bid++;
					this->sequence = 0;
					cout << "此磴由player3拿下" << endl;
				}
				else
				{
					D.bid++;
					this->sequence = 1;
					cout << "此磴由player2拿下" << endl;
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
					cout << "此磴由玩家拿下" << endl;
				}
				else if (temp3 == 1)
				{
					E.bid++;
					this->sequence = 0;
					cout << "此磴由player3拿下" << endl;
				}
				else if (temp3 == 2)
				{
					D.bid++;
					this->sequence = 1;
					cout << "此磴由player2拿下" << endl;
				}
				else
				{
					F.bid++;
					this->sequence = 2;
					cout << "此磴由player4拿下" << endl;
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
	//設定手牌
	A.vCard_number[0] = 0;
	A.vCard_color[0] = 0;
	B.vCard_number[0] = 0;
	B.vCard_color[0] = 0;
	C.vCard_number[0] = 0;
	C.vCard_color[0] = 0;
	D.vCard_number[0] = 0;
	D.vCard_color[0] = 0;
	//發牌
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
	//事實上,上面三行可和下面for迴圈合併!
	for (int i = 0; i < N_CARDS; i++)
	{
		this->v_card_A_number[i] = card_A_number[i];
		this->v_card_A_color[i] = card_A_color[i];
	}

	return NULL;
}
int Game::set_data3()
{
	//A陣列為原型牌組,B參考之
	for (int i = 0; i < N_CARDS; i++)
	{
		this->v_card_B_number[i] = this->v_card_A_number[i];
		this->v_card_B_color[i] = this->v_card_A_color[i];
	}
	//洗牌*6
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
		cout << "是否重開一局?(y)";
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
		cout << "難度設定(請輸入0~7,0最易,7最難):";
		cin >> number;
		if (number < 0 || number>7 == 1)
			cout << "輸入錯誤,請重新輸入!" << endl;
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
	//number由十進位轉二進位
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
			cout << "對方已拿下所需的" << b + 6 << "磴,玩家挑戰失敗!!" << endl;
			mark = 1;
		}
		else if ((c + d) == (8 - b))
		{
			cout << "我方已拿下所需的" << 8 - b << "磴,玩家挑戰成功!!" << endl;
			mark = 1;
		}
		else
			mark = 0;
	}
	else
	{
		if ((c + d) == (b + 6))
		{
			cout << "我方已拿下所需的" << b + 6 << "磴,玩家挑戰成功!!" << endl;
			mark = 1;
		}
		else if ((e + f) == (8 - b))
		{
			cout << "對方已拿下所需的" << 8 - b << "磴,玩家挑戰失敗!!" << endl;
			mark = 1;
		}
		else
			mark = 0;
	}
	return mark;
}//Game::Process::Play()
int fun_explanation1()
{
	cout << "歡迎遊玩四人合約橋牌(單機版)!!" << endl;
	cout << "第一部份:" << endl;
	return NULL;
}
int fun_explanation1_1()
{
	cout << "由於AI目前只開發出一種,因此難度設定一律為最簡單的模式!";
	return NULL;
}
int fun_explanation2()
{
	cout << endl;
	cout << "+-----------------------------------------+" << endl;
	cout << "第二部份:發牌與倒牌" << endl;
	return NULL;
}
int fun_explanation3()
{
	cout << "+------------------------------+" << endl;
	cout << "第三部份:叫牌" << endl;
	cout << "以下是四位玩家的位置示意圖!!" << endl;
	cout << "        " << "Player.1(使用者)" << endl;
	cout << "Player.4" << "        " << "Player.3" << endl;
	cout << "        " << "Player.2" << endl;
	cout << "叫牌為自Player.3順時針開始" << endl;
	return NULL;
}
int fun_explanation3_1(int a, int b, int c, int d, int A[], int B[])
{
	/*
	a=temp,
	b=counter_stop,
	c=sequence,
	d=selector,
	A[]代表auction_color[],
	B[]代表auction_number[],
	*/
	cout << "+------------------------------+" << endl;
	if (c == 0)
	{
		if (A[b] == 0)
			cout << "最終決定採用player.3所喊的無王" << B[b] << "作為此次遊戲的合約!!";
		else if (A[b] == 1)
			cout << "最終決定採用player.3所喊的黑桃" << B[b] << "作為此次遊戲的合約!!";
		else if (A[b] == 2)
			cout << "最終決定採用player.3所喊的紅心" << B[b] << "作為此次遊戲的合約!!";
		else if (A[b] == 3)
			cout << "最終決定採用player.3所喊的方塊" << B[b] << "作為此次遊戲的合約!!";
		else if (A[b] == 4)
			cout << "最終決定採用player.3所喊的梅花" << B[b] << "作為此次遊戲的合約!!";
		else
			cout << "最終決定採用player.3所喊的small" << B[b] << "作為此次遊戲的合約!!";
	}
	else if (c == 1)
	{
		if (A[b] == 0)
			cout << "最終決定採用player.2所喊的無王" << B[b] << "作為此次遊戲的合約!!";
		else if (A[b] == 1)
			cout << "最終決定採用player.2所喊的黑桃" << B[b] << "作為此次遊戲的合約!!";
		else if (A[b] == 2)
			cout << "最終決定採用player.2所喊的紅心" << B[b] << "作為此次遊戲的合約!!";
		else if (A[b] == 3)
			cout << "最終決定採用player.2所喊的方塊" << B[b] << "作為此次遊戲的合約!!";
		else if (A[b] == 4)
			cout << "最終決定採用player.2所喊的梅花" << B[b] << "作為此次遊戲的合約!!";
		else
			cout << "最終決定採用player.2所喊的small" << B[b] << "作為此次遊戲的合約!!";
	}
	else if (c == 2)
	{
		if (A[b] == 0)
			cout << "最終決定採用player.4所喊的無王" << B[b] << "作為此次遊戲的合約!!";
		else if (A[b] == 1)
			cout << "最終決定採用player.4所喊的黑桃" << B[b] << "作為此次遊戲的合約!!";
		else if (A[b] == 2)
			cout << "最終決定採用player.4所喊的紅心" << B[b] << "作為此次遊戲的合約!!";
		else if (A[b] == 3)
			cout << "最終決定採用player.4所喊的方塊" << B[b] << "作為此次遊戲的合約!!";
		else if (A[b] == 4)
			cout << "最終決定採用player.4所喊的梅花" << B[b] << "作為此次遊戲的合約!!";
		else
			cout << "最終決定採用player.4所喊的small" << B[b] << "作為此次遊戲的合約!!";
	}
	else
	{
		if (A[b] == 0)
			cout << "最終決定採用您所喊的無王" << B[b] << "作為此次遊戲的合約!!";
		else if (A[b] == 1)
			cout << "最終決定採用您所喊的黑桃" << B[b] << "作為此次遊戲的合約!!";
		else if (A[b] == 2)
			cout << "最終決定採用您所喊的紅心" << B[b] << "作為此次遊戲的合約!!";
		else if (A[b] == 3)
			cout << "最終決定採用您所喊的方塊" << B[b] << "作為此次遊戲的合約!!";
		else if (A[b] == 4)
			cout << "最終決定採用您所喊的梅花" << B[b] << "作為此次遊戲的合約!!";
		else
			cout << "最終決定採用您所喊的small" << B[b] << "作為此次遊戲的合約!!";
	}
	cout << endl;
	return NULL;
}
int fun_explanation4()
{
	cout << "+------------------------------+" << endl;
	cout << "第四部份:出牌" << endl;
	cout << "以下為您的手牌,在此過程中,每一輪都會顯示出您的手牌" << endl;
	return NULL;
}