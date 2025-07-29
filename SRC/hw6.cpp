#include<iostream>
#include<stdio.h>
#include<string>
#include<stdlib.h>
#include<time.h>
#include<iomanip>

using namespace std;

void display(int[],int[],int[],int[],int[], int[], int[], int[], int[]);//顯示卡牌板
void endofgame(int[], int[], int[], int[]);//結算分數

int x[77];
int card[76];

int main()
{
	//卡牌資料庫
	static int a=4;
	char playernumber[100];
	cout << "welcome to play coloretto" << endl;
	//玩家人數為四
	if (a == 4)
	{
		int cardnumber, washcard[76];
		cardnumber = 0;
		while (cardnumber++, cardnumber <= 76)
		{
			if (9 >= cardnumber && cardnumber >= 1)
			{
				card[cardnumber] = 1;//1 for red
			}
			if (18 >= cardnumber && cardnumber >= 10)
			{
				card[cardnumber] = 2;//2 for yellow
			}
			if (27 >= cardnumber && cardnumber >= 19)
			{
				card[cardnumber] = 3;//3 for green
			}
			if (36 >= cardnumber && cardnumber >= 28)
			{
				card[cardnumber] = 4;//4 for blue
			}
			if (45 >= cardnumber && cardnumber >= 37)
			{
				card[cardnumber] = 5;//5 for purple
			}
			if (54 >= cardnumber && cardnumber >= 46)
			{
				card[cardnumber] = 6;//6 for brown
			}
			if (63 >= cardnumber && cardnumber >= 55)
			{
				card[cardnumber] = 7;//7 for gray
			}
			if (73 >= cardnumber && cardnumber >= 64)//兩分卡
			{
				card[cardnumber] = 8;//8 for plus two
			}
			if (76 >= cardnumber && cardnumber >= 74)//鬼牌
			{
				card[cardnumber] = 9;//9 for rainbow
			}
		}
		cout << "waiting for a moment" << endl;
		while (true)
		{
			for (int i = 1; i <= 76; i++)//洗牌
			{
				x[i] = i;
			}
			srand((unsigned)time(NULL));
			for (int i2 = 1; i2 <= 10000; i2++)
			{
				int a1, a2;
				a1 = rand() % 76 + 1;
				a2 = rand() % 76 + 1;
				int temp = x[a1];
				x[a1] = x[a2];
				x[a2] = temp;
			}
			if (card[x[1]] != 8 && card[x[1]] != 9 && card[x[2]] != 8 && card[x[2]] != 9 && card[x[3]] != 8 && card[x[3]] != 9 && card[x[4]] != 8 && card[x[4]] != 9&& card[x[1]] != card[x[2]]  && card[x[1]] != card[x[3]] && card[x[1]] != card[x[4]] && card[x[2]] != card[x[3]] && card[x[2]] != card[x[4]] && card[x[3]] != card[x[4]])//確保前四張牌不會是給牌或加二，也不重複
			{
				break;
			}
		}
		
		for (int i = 1; i <= 76; i++)
		{
			cout << card[x[i]] << endl;
		}
		int row1[3], row2[3], row3[3], row4[3];
		int row1counter=0, row2counter=0, row3counter=0, row4counter=0;
		int you[76], player1[76], player2[76], player3[76];
		int youcounter=1, player1counter=1, player2counter=1, player3counter=1;
		int pickyou = 0, pickplayer1 = 0, pickplayer2 = 0, pickplayer3 = 0;//使用者或ai是否執行過拿取某一航的動作
		int prooffourdraw = 0;
		int chosenrow[5];
		chosenrow[1] = 0;
		chosenrow[2] = 0;
		chosenrow[3] = 0;
		chosenrow[4] = 0;
		//第一次介面輸出
		you[0] = card[x[1]];
		player1[0] = card[x[2]];
		player2[0] = card[x[3]];
		player3[0] = card[x[4]];

		display(row1, row2, row3, row4, chosenrow, you, player1, player2, player3);
		for (int counter = 5; counter <= 76;)
		{
			cout << "please enter \"draw\" to draw a card and 1~4 to put the card to the row or enter 1~4 to choose whitch row you want to choose" << endl;
			static char move[4];
			if (pickyou == 0)
			{
				while (true)//使用者之動作及顯示表
				{
					cin.getline(move, 256);
					if (chosenrow[1] == 1)
					{
						prooffourdraw++;
					}
					if (chosenrow[2] == 1)
					{
						prooffourdraw++;
					}
					if (chosenrow[3] == 1)
					{
						prooffourdraw++;
					}
					if (chosenrow[4] == 1)
					{
						prooffourdraw++;
					}
					if (prooffourdraw < 3||(row1counter<3&& row2counter < 3 && row3counter < 3 && row4counter < 3))
					{
						if (move[0] == 'd'&& move[1] == 'r'&& move[2] == 'a'&& move[3] == 'w'&&strlen(move)==4)
						{
							switch (card[x[counter]])//使用者抽到的牌
							{
							case 1:
								cout << "the card is red" << endl;
								break;
							case 2:
								cout << "the card is yellow" << endl;
								break;
							case 3:
								cout << "the card is green" << endl;
								break;
							case 4:
								cout << "the card is blue" << endl;
								break;
							case 5:
								cout << "the card is purple" << endl;
								break;
							case 6:
								cout << "the card is brown" << endl;
								break;
							case 7:
								cout << "the card is gray" << endl;
								break;
							case 8:
								cout << "the card is plus two point card" << endl;
								break;
							case 9:
								cout << "the card is rainbow" << endl;
								break;
							}
							counter++;
							while (true)//使用者要放牌至哪一行
							{
								cout << "please enter 1~4 to put the card to the row " << endl;
								cin.clear();
								cin.getline(move, 256);
								if (strlen(move) == 1 && (move[0] == '1' || move[0] == '2' || move[0] == '3' || move[0] == '4'))
								{

									if (move[0] == '1' &&row1counter < 3 && chosenrow[1] == 0)
									{
										row1[row1counter] = card[x[counter - 1]];
										row1counter++;
									}
									else if (move[0] == '2' &&row2counter < 3 && chosenrow[2] == 0)
									{
										row2[row2counter] = card[x[counter - 1]];
										row2counter++;
									}
									else if (move[0] == '3' &&row1counter < 3 && chosenrow[3] == 0)
									{
										row3[row3counter] = card[x[counter - 1]];
										row3counter++;
									}
									else if (move[0] == '4' &&row1counter < 3 && chosenrow[4] == 0)
									{
										row4[row4counter] = card[x[counter - 1]];
										row4counter++;
									}
									else
									{
										cout << "this row is full or was chosen" << endl;
										continue;
									}
									display(row1, row2, row3, row4, chosenrow, you, player1, player2, player3);
									cin.clear();
									break;
								}
							}
							break;
						}
					}
					if (strlen(move) == 1 && (move[0] == '1' || move[0] == '2' || move[0] == '3' || move[0] == '4'))//使用者拿了哪一行，並把卡牌資料儲存及重置
					{
						if ((move[0] == '1'&&chosenrow[1] == 1) || (move[0] == '2'&&chosenrow[2] == 1) || (move[0] == '3'&&chosenrow[3] == 1) || (move[0] == '4'&&chosenrow[4] == 1))
						{
							cout << "this row was chosen" << endl;
							cout << "please enter \"draw\" to draw a card and 1~4 to put the card to the row or enter 1~4 to choose whitch row you want to choose" << endl;
							cin.clear();
							continue;
						}
						if (move[0] == '1'&&row1counter > 0)
						{
							for (int i = row1counter; i >= 0; i--)
							{
								you[youcounter] = row1[i];
								youcounter++;
								row1[i] = 0;
								chosenrow[1] = 1;
							}
							row1counter = 0;
						}
						else if (move[0] == '2'&&row2counter > 0)
						{
							for (int i = row2counter; i >= 0; i--)
							{
								you[youcounter] = row2[i];
								youcounter++;
								row2[i] = 0;
								chosenrow[2] = 1;
							}
							row2counter = 0;
						}
						else if (move[0] == '3'&&row3counter > 0)
						{
							for (int i = row3counter; i >= 0; i--)
							{
								you[youcounter] = row3[i];
								youcounter++;
								row3[i] = 0;
								chosenrow[3] = 1;
							}
							row3counter = 0;
						}
						else if (move[0] == '4'&&row4counter > 0)
						{
							for (int i = row4counter; i >= 0; i--)
							{
								you[youcounter] = row4[i];
								youcounter++;
								row4[i] = 0;
								chosenrow[4] = 1;
							}
							row4counter = 0;
						}
						else
						{
							cout << "you can not choose empty row" << endl;
							cin.clear();
							continue;
						}
						if (chosenrow[1] == 1 && chosenrow[2] == 1 && chosenrow[3] == 1 && chosenrow[4] == 1)
						{
							chosenrow[1] = 0;
							chosenrow[2] = 0;
							chosenrow[3] = 0;
							chosenrow[4] = 0;
							pickyou = 0;
							pickplayer1 = 0;
							pickplayer2 = 0;
							pickplayer3 = 0;
							break;
						}
						display(row1, row2, row3, row4, chosenrow, you, player1, player2, player3);
						pickyou = 1;
					}
					prooffourdraw = 0;
					cin.clear();
					cout << "please enter \"draw\" to draw a card and 1~4 to put the card to the row or enter 1~4 to choose whitch row you want to choose" << endl;
				}
			}
			if (pickplayer1 == 0)
			{
				if ((row1counter == 0 || chosenrow[1] == 1) && (row2counter == 0 || chosenrow[2] == 1) && (row3counter == 0 || chosenrow[3] == 1) && (row4counter == 0 || chosenrow[4] == 1))//ai1的動作
				{
					row1[row1counter] = card[x[counter]];
					row1counter++;
					counter++;
					display(row1, row2, row3, row4, chosenrow, you, player1, player2, player3);
				}
				else
				{
					if (row1counter != 0)
					{
						for (int i = row1counter; i >= 0; i--)
						{
							player1[player1counter] = row1[i];
							player1counter++;
							row1[i] = 0;
							chosenrow[1] = 1;
						}
						row1counter = 0;
					}
					else if (row2counter != 0)
					{
						for (int i = row2counter; i >= 0; i--)
						{
							player1[player1counter] = row2[i];
							player1counter++;
							row2[i] = 0;
							chosenrow[2] = 1;
						}
						row2counter = 0;
					}
					else if (row3counter != 0)
					{
						for (int i = row3counter; i >= 0; i--)
						{
							player1[player1counter] = row3[i];
							player1counter++;
							row3[i] = 0;
							chosenrow[3] = 1;
						}
						row3counter = 0;
					}
					else if (row4counter != 0)
					{
						for (int i = row4counter; i >= 0; i--)
						{
							player1[player1counter] = row4[i];
							player1counter++;
							row4[i] = 0;
							chosenrow[4] = 1;
						}
						row4counter = 0;
					}
					if (chosenrow[1] == 1 && chosenrow[2] == 1 && chosenrow[3] == 1 && chosenrow[4] == 1)
					{
						chosenrow[1] = 0;
						chosenrow[2] = 0;
						chosenrow[3] = 0;
						chosenrow[4] = 0;
						pickyou = 0;
						pickplayer1 = 0;
						pickplayer2 = 0;
						pickplayer3 = 0;
					}
					display(row1, row2, row3, row4, chosenrow, you, player1, player2, player3);
					pickplayer1 = 1;
				}
			}
			if (pickplayer2 == 0)
			{
				if ((row1counter == 0 || chosenrow[1] == 1) && (row2counter == 0 || chosenrow[2] == 1) && (row3counter == 0 || chosenrow[3] == 1) && (row4counter == 0 || chosenrow[4] == 1))//ai2的動作
				{
					row2[row2counter] = card[x[counter]];
					row2counter++;
					counter++;
					display(row1, row2, row3, row4, chosenrow, you, player1, player2, player3);
				}
				else
				{
					if (row1counter != 0)
					{
						for (int i = row1counter; i >= 0; i--)
						{
							player2[player2counter] = row1[i];
							player2counter++;
							row1[i] = 0;
							chosenrow[1] = 1;
						}
						row1counter = 0;
					}
					else if (row2counter != 0)
					{
						for (int i = row2counter; i >= 0; i--)
						{
							player2[player2counter] = row2[i];
							player2counter++;
							row2[i] = 0;
							chosenrow[2] = 1;
						}
						row2counter = 0;
					}
					else if (row3counter != 0)
					{
						for (int i = row3counter; i >= 0; i--)
						{
							player2[player2counter] = row3[i];
							player2counter++;
							row3[i] = 0;
							chosenrow[3] = 1;
						}
						row3counter = 0;
					}
					else if (row4counter != 0)
					{
						for (int i = row4counter; i >= 0; i--)
						{
							player2[player2counter] = row4[i];
							player2counter++;
							row4[i] = 0;
							chosenrow[4] = 1;
						}
						row4counter = 0;
					}
					if (chosenrow[1] == 1 && chosenrow[2] == 1 && chosenrow[3] == 1 && chosenrow[4] == 1)
					{
						chosenrow[1] = 0;
						chosenrow[2] = 0;
						chosenrow[3] = 0;
						chosenrow[4] = 0;
						pickyou = 0;
						pickplayer1 = 0;
						pickplayer2 = 0;
						pickplayer3 = 0;
					}
					display(row1, row2, row3, row4, chosenrow, you, player1, player2, player3);
					pickplayer2 = 1;
				}
			}
			if (pickplayer3 == 0)
			{
				if ((row1counter == 0 || chosenrow[1] == 1) && (row2counter == 0 || chosenrow[2] == 1) && (row3counter == 0 || chosenrow[3] == 1) && (row4counter == 0 || chosenrow[4] == 1))//ai3的動作
				{
					row3[row3counter] = card[x[counter]];
					row3counter++;
					counter++;
					display(row1, row2, row3, row4, chosenrow, you, player1, player2, player3);
				}
				else
				{
					if (row1counter != 0)
					{
						for (int i = row1counter; i >= 0; i--)
						{
							player3[player3counter] = row1[i];
							player3counter++;
							row1[i] = 0;
							chosenrow[1] = 1;
						}
						row1counter = 0;
					}
					else if (row2counter != 0)
					{
						for (int i = row2counter; i >= 0; i--)
						{
							player3[player3counter] = row2[i];
							player3counter++;
							row2[i] = 0;
							chosenrow[2] = 1;
						}
						row2counter = 0;
					}
					else if (row3counter != 0)
					{
						for (int i = row3counter; i >= 0; i--)
						{
							player3[player3counter] = row3[i];
							player3counter++;
							row3[i] = 0;
							chosenrow[3] = 1;
						}
						row3counter = 0;
					}
					else if (row4counter != 0)
					{
						for (int i = row4counter; i >= 0; i--)
						{
							player3[player3counter] = row4[i];
							player3counter++;
							row4[i] = 0;
							chosenrow[4] = 1;
						}
						row4counter = 0;
					}
					if (chosenrow[1] == 1 && chosenrow[2] == 1 && chosenrow[3] == 1 && chosenrow[4] == 1)
					{
						chosenrow[1] = 0;
						chosenrow[2] = 0;
						chosenrow[3] = 0;
						chosenrow[4] = 0;
						pickyou = 0;
						pickplayer1 = 0;
						pickplayer2 = 0;
						pickplayer3 = 0;
					}
					display(row1, row2, row3, row4, chosenrow, you, player1, player2, player3);
					pickplayer3 = 1;
				}
			}

			if (counter >= 60 && chosenrow[1] == 1 && chosenrow[2] == 1 &&	chosenrow[3] == 1 && chosenrow[4] == 1)//結束機制
			{
				break;
			}
		}
		//結算分數
		endofgame(you,player1,player2,player3);
		
		system("pause");
		return 0;
	}
}

void display(int a[], int b[], int c[], int d[], int e[],int f[],int g[],int h[],int j[])
{
	int redinrow[5] = { 0 }, yellowinrow[5] = { 0 }, greeninrow[5] = { 0 }, blueinrow[5] = { 0 }, purpleinrow[5] = { 0 }, browninrow[5] = { 0 }, grayinrow[5] = { 0 }, plustwoinrow[5] = { 0 }, rainbowinrow[5] = { 0 };
	int redinplayer[5] = { 0 }, yellowinplayer[5] = { 0 }, greeninplayer[5] = { 0 }, blueinplayer[5] = { 0 }, purpleinplayer[5] = { 0 }, browninplayer[5] = { 0 }, grayinplayer[5] = { 0 }, plustwoinplayer[5] = { 0 }, rainbowinplayer[5] = { 0 };
	for (int i = 0; i < 3; i++)
	{
		switch (a[i])
		{
		case 1:
			redinrow[1]++;
			break;
		case 2:
			yellowinrow[1]++;
			break;
		case 3:
			greeninrow[1]++;
			break;
		case 4:
			blueinrow[1]++;
			break;
		case 5:
			purpleinrow[1]++;
			break;
		case 6:
			browninrow[1]++;
			break;
		case 7:
			grayinrow[1]++;
			break;
		case 8:
			plustwoinrow[1]++;
			break;
		case 9:
			rainbowinrow[1]++;
			break;
		}
		switch (b[i])
		{
		case 1:
			redinrow[2]++;
			break;
		case 2:
			yellowinrow[2]++;
			break;
		case 3:
			greeninrow[2]++;
			break;
		case 4:
			blueinrow[2]++;
			break;
		case 5:
			purpleinrow[2]++;
			break;
		case 6:
			browninrow[2]++;
			break;
		case 7:
			grayinrow[2]++;
			break;
		case 8:
			plustwoinrow[2]++;
			break;
		case 9:
			rainbowinrow[2]++;
			break;
		}
		switch (c[i])
		{
		case 1:
			redinrow[3]++;
			break;
		case 2:
			yellowinrow[3]++;
			break;
		case 3:
			greeninrow[3]++;
			break;
		case 4:
			blueinrow[3]++;
			break;
		case 5:
			purpleinrow[3]++;
			break;
		case 6:
			browninrow[3]++;
			break;
		case 7:
			grayinrow[3]++;
			break;
		case 8:
			plustwoinrow[3]++;
			break;
		case 9:
			rainbowinrow[3]++;
			break;
		}
		switch (d[i])
		{
		case 1:
			redinrow[4]++;
			break;
		case 2:
			yellowinrow[4]++;
			break;
		case 3:
			greeninrow[4]++;
			break;
		case 4:
			blueinrow[4]++;
			break;
		case 5:
			purpleinrow[4]++;
			break;
		case 6:
			browninrow[4]++;
			break;
		case 7:
			grayinrow[4]++;
			break;
		case 8:
			plustwoinrow[4]++;
			break;
		case 9:
			rainbowinrow[4]++;
			break;
		}
	}
	if (e[1] != 1 && e[2] != 1 && e[3] != 1 && e[4] != 1)
	{
		cout <<                        setw(15) << "row1"          << setw(21) << "row2"         << setw(27) << "row3"         << setw(33) << "row4"          << endl;
		cout << setw(7) << "red"    << setw(15) << redinrow[1]     << setw(21) << redinrow[2]    << setw(27) << redinrow[3]    << setw(33) << redinrow[4]     << endl;
		cout << setw(7) << "yellow" << setw(15) << yellowinrow[1]  << setw(21) << yellowinrow[2] << setw(27) << yellowinrow[3] << setw(33) << yellowinrow[4]  << endl;
		cout << setw(7) << "green"  << setw(15) << greeninrow[1]   << setw(21) << greeninrow[2]  << setw(27) << greeninrow[3]  << setw(33) << greeninrow[4]   << endl;
		cout << setw(7) << "blue"   << setw(15) << blueinrow[1]    << setw(21) << blueinrow[2]   << setw(27) << blueinrow[3]   << setw(33) << blueinrow[4]    << endl;
		cout << setw(7) << "purple" << setw(15) << purpleinrow[1]  << setw(21) << purpleinrow[2] << setw(27) << purpleinrow[3] << setw(33) << purpleinrow[4]  << endl;
		cout << setw(7) << "brown"  << setw(15) << browninrow[1]   << setw(21) << browninrow[2]  << setw(27) << browninrow[3]  << setw(33) << browninrow[4]   << endl;
		cout << setw(7) << "gray"   << setw(15) << grayinrow[1]    << setw(21) << grayinrow[2]   << setw(27) << grayinrow[3]   << setw(33) << grayinrow[4]    << endl;
		cout << setw(7) << "plustwo"<< setw(15) << plustwoinrow[1] << setw(21) << plustwoinrow[2]<< setw(27) << plustwoinrow[3]<< setw(33) << plustwoinrow[4] << endl;
		cout << setw(7) << "rainbow"<< setw(15) << rainbowinrow[1] << setw(21) << rainbowinrow[2]<< setw(27) << rainbowinrow[3]<< setw(33) << rainbowinrow[4] << endl;
	}
	if (e[1] != 0 && e[2] != 1 && e[3] != 1 && e[4] != 1)
	{
		cout                      << setw(15) << "row1" << setw(21) << "row2" << setw(27) << "row3" << setw(33) << "row4" << endl;
		cout << setw(7) << "red" << setw(15) << "" << setw(21) << redinrow[2] << setw(27) << redinrow[3] << setw(33) << redinrow[4] << endl;
		cout << setw(7) << "yellow" << setw(15) << "" << setw(21) << yellowinrow[2] << setw(27) << yellowinrow[3] << setw(33) << yellowinrow[4] << endl;
		cout << setw(7) << "green" << setw(15) << "" << setw(21) << greeninrow[2] << setw(27) << greeninrow[3] << setw(33) << greeninrow[4] << endl;
		cout << setw(7) << "blue" << setw(15) << "" << setw(21) << blueinrow[2] << setw(27) << blueinrow[3] << setw(33) << blueinrow[4] << endl;
		cout << setw(7) << "purple" << setw(15) << "" << setw(21) << purpleinrow[2] << setw(27) << purpleinrow[3] << setw(33) << purpleinrow[4] << endl;
		cout << setw(7) << "brown" << setw(15) << "" << setw(21) << browninrow[2] << setw(27) << browninrow[3] << setw(33) << browninrow[4] << endl;
		cout << setw(7) << "gray" << setw(15) << "" << setw(21) << grayinrow[2] << setw(27) << grayinrow[3] << setw(33) << grayinrow[4] << endl;
		cout << setw(7) << "plustwo" << setw(15) << "" << setw(21) << plustwoinrow[2] << setw(27) << plustwoinrow[3] << setw(33) << plustwoinrow[4] << endl;
		cout << setw(7) << "rainbow" << setw(15) << "" << setw(21) << rainbowinrow[2] << setw(27) << rainbowinrow[3] << setw(33) << rainbowinrow[4] << endl;
	}
	if (e[1] != 1 && e[2] != 0 && e[3] != 1 && e[4] != 1)
	{
		cout << setw(15) << "row1" << setw(21) << "row2" << setw(27) << "row3" << setw(33) << "row4" << endl;
		cout << setw(7) << "red" << setw(15) << redinrow[1] << setw(21) << "" << setw(27) << redinrow[3] << setw(33) << redinrow[4] << endl;
		cout << setw(7) << "yellow" << setw(15) << yellowinrow[1] << setw(21) << "" << setw(27) << yellowinrow[3] << setw(33) << yellowinrow[4] << endl;
		cout << setw(7) << "green" << setw(15) << greeninrow[1] << setw(21) << "" << setw(27) << greeninrow[3] << setw(33) << greeninrow[4] << endl;
		cout << setw(7) << "blue" << setw(15) << blueinrow[1] << setw(21) << "" << setw(27) << blueinrow[3] << setw(33) << blueinrow[4] << endl;
		cout << setw(7) << "purple" << setw(15) << purpleinrow[1] << setw(21) << "" << setw(27) << purpleinrow[3] << setw(33) << purpleinrow[4] << endl;
		cout << setw(7) << "brown" << setw(15) << browninrow[1] << setw(21) << "" << setw(27) << browninrow[3] << setw(33) << browninrow[4] << endl;
		cout << setw(7) << "gray" << setw(15) << grayinrow[1] << setw(21) << "" << setw(27) << grayinrow[3] << setw(33) << grayinrow[4] << endl;
		cout << setw(7) << "plustwo" << setw(15) << plustwoinrow[1] << setw(21) << "" << setw(27) << plustwoinrow[3] << setw(33) << plustwoinrow[4] << endl;
		cout << setw(7) << "rainbow" << setw(15) << rainbowinrow[1] << setw(21) << "" << setw(27) << rainbowinrow[3] << setw(33) << rainbowinrow[4] << endl;
	}
	if (e[1] != 1 && e[2] != 1 && e[3] != 0 && e[4] != 1)
	{
		cout << setw(15) << "row1" << setw(21) << "row2" << setw(27) << "row3" << setw(33) << "row4" << endl;
		cout << setw(7) << "red" << setw(15) << redinrow[1] << setw(21) << redinrow[2] << setw(27) << "" << setw(33) << redinrow[4] << endl;
		cout << setw(7) << "yellow" << setw(15) << yellowinrow[1] << setw(21) << yellowinrow[2] << setw(27) << "" << setw(33) << yellowinrow[4] << endl;
		cout << setw(7) << "green" << setw(15) << greeninrow[1] << setw(21) << greeninrow[2] << setw(27) << "" << setw(33) << greeninrow[4] << endl;
		cout << setw(7) << "blue" << setw(15) << blueinrow[1] << setw(21) << blueinrow[2] << setw(27) << "" << setw(33) << blueinrow[4] << endl;
		cout << setw(7) << "purple" << setw(15) << purpleinrow[1] << setw(21) << purpleinrow[2] << setw(27) << "" << setw(33) << purpleinrow[4] << endl;
		cout << setw(7) << "brown" << setw(15) << browninrow[1] << setw(21) << browninrow[2] << setw(27) << "" << setw(33) << browninrow[4] << endl;
		cout << setw(7) << "gray" << setw(15) << grayinrow[1] << setw(21) << grayinrow[2] << setw(27) << "" << setw(33) << grayinrow[4] << endl;
		cout << setw(7) << "plustwo" << setw(15) << plustwoinrow[1] << setw(21) << plustwoinrow[2] << setw(27) << "" << setw(33) << plustwoinrow[4] << endl;
		cout << setw(7) << "rainbow" << setw(15) << rainbowinrow[1] << setw(21) << rainbowinrow[2] << setw(27) << "" << setw(33) << rainbowinrow[4] << endl;
	}
	if (e[1] != 1 && e[2] != 1 && e[3] != 1 && e[4] != 0)
	{
		cout << setw(15) << "row1" << setw(21) << "row2" << setw(27) << "row3" << setw(33) << "row4" << endl;
		cout << setw(7) << "red" << setw(15) << redinrow[1] << setw(21) << redinrow[2] << setw(27) << redinrow[3] << setw(33) << "" << endl;
		cout << setw(7) << "yellow" << setw(15) << yellowinrow[1] << setw(21) << yellowinrow[2] << setw(27) << yellowinrow[3] << setw(33) << "" << endl;
		cout << setw(7) << "green" << setw(15) << greeninrow[1] << setw(21) << greeninrow[2] << setw(27) << greeninrow[3] << setw(33) << "" << endl;
		cout << setw(7) << "blue" << setw(15) << blueinrow[1] << setw(21) << blueinrow[2] << setw(27) << blueinrow[3] << setw(33) << "" << endl;
		cout << setw(7) << "purple" << setw(15) << purpleinrow[1] << setw(21) << purpleinrow[2] << setw(27) << purpleinrow[3] << setw(33) << "" << endl;
		cout << setw(7) << "brown" << setw(15) << browninrow[1] << setw(21) << browninrow[2] << setw(27) << browninrow[3] << setw(33) << "" << endl;
		cout << setw(7) << "gray" << setw(15) << grayinrow[1] << setw(21) << grayinrow[2] << setw(27) << grayinrow[3] << setw(33) << "" << endl;
		cout << setw(7) << "plustwo" << setw(15) << plustwoinrow[1] << setw(21) << plustwoinrow[2] << setw(27) << plustwoinrow[3] << setw(33) << "" << endl;
		cout << setw(7) << "rainbow" << setw(15) << rainbowinrow[1] << setw(21) << rainbowinrow[2] << setw(27) << rainbowinrow[3] << setw(33) << "" << endl;
	}
	if (e[1] != 0 && e[2] != 0 && e[3] != 1 && e[4] != 1)
	{
		cout << setw(15) << "row1" << setw(21) << "row2" << setw(27) << "row3" << setw(33) << "row4" << endl;
		cout << setw(7) << "red" << setw(15) << "" << setw(21) << "" << setw(27) << redinrow[3] << setw(33) << redinrow[4] << endl;
		cout << setw(7) << "yellow" << setw(15) << "" << setw(21) << "" << setw(27) << yellowinrow[3] << setw(33) << yellowinrow[4] << endl;
		cout << setw(7) << "green" << setw(15) << "" << setw(21) << "" << setw(27) << greeninrow[3] << setw(33) << greeninrow[4] << endl;
		cout << setw(7) << "blue" << setw(15) << "" << setw(21) << "" << setw(27) << blueinrow[3] << setw(33) << blueinrow[4] << endl;
		cout << setw(7) << "purple" << setw(15) << "" << setw(21) << "" << setw(27) << purpleinrow[3] << setw(33) << purpleinrow[4] << endl;
		cout << setw(7) << "brown" << setw(15) << "" << setw(21) << "" << setw(27) << browninrow[3] << setw(33) << browninrow[4] << endl;
		cout << setw(7) << "gray" << setw(15) << "" << setw(21) << "" << setw(27) << grayinrow[3] << setw(33) << grayinrow[4] << endl;
		cout << setw(7) << "plustwo" << setw(15) << "" << setw(21) << "" << setw(27) << plustwoinrow[3] << setw(33) << plustwoinrow[4] << endl;
		cout << setw(7) << "rainbow" << setw(15) << "" << setw(21) << "" << setw(27) << rainbowinrow[3] << setw(33) << rainbowinrow[4] << endl;
	}
	if (e[1] != 0 && e[2] != 1 && e[3] != 0 && e[4] != 1)
	{
		cout << setw(15) << "row1" << setw(21) << "row2" << setw(27) << "row3" << setw(33) << "row4" << endl;
		cout << setw(7) << "red" << setw(15) << "" << setw(21) << redinrow[2] << setw(27) << "" << setw(33) << redinrow[4] << endl;
		cout << setw(7) << "yellow" << setw(15) << "" << setw(21) << yellowinrow[2] << setw(27) << "" << setw(33) << yellowinrow[4] << endl;
		cout << setw(7) << "green" << setw(15) << "" << setw(21) << greeninrow[2] << setw(27) << "" << setw(33) << greeninrow[4] << endl;
		cout << setw(7) << "blue" << setw(15) << "" << setw(21) << blueinrow[2] << setw(27) << "" << setw(33) << blueinrow[4] << endl;
		cout << setw(7) << "purple" << setw(15) << "" << setw(21) << purpleinrow[2] << setw(27) << "" << setw(33) << purpleinrow[4] << endl;
		cout << setw(7) << "brown" << setw(15) << "" << setw(21) << browninrow[2] << setw(27) << "" << setw(33) << browninrow[4] << endl;
		cout << setw(7) << "gray" << setw(15) << "" << setw(21) << grayinrow[2] << setw(27) << "" << setw(33) << grayinrow[4] << endl;
		cout << setw(7) << "plustwo" << setw(15) << "" << setw(21) << plustwoinrow[2] << setw(27) << "" << setw(33) << plustwoinrow[4] << endl;
		cout << setw(7) << "rainbow" << setw(15) << "" << setw(21) << rainbowinrow[2] << setw(27) << "" << setw(33) << rainbowinrow[4] << endl;
	}
	if (e[1] != 0 && e[2] != 1 && e[3] != 1 && e[4] != 0)
	{
		cout << setw(15) << "row1" << setw(21) << "row2" << setw(27) << "row3" << setw(33) << "row4" << endl;
		cout << setw(7) << "red" << setw(15) << "" << setw(21) << redinrow[2] << setw(27) << redinrow[3] << setw(33) << "" << endl;
		cout << setw(7) << "yellow" << setw(15) << "" << setw(21) << yellowinrow[2] << setw(27) << yellowinrow[3] << setw(33) << "" << endl;
		cout << setw(7) << "green" << setw(15) << "" << setw(21) << greeninrow[2] << setw(27) << greeninrow[3] << setw(33) << "" << endl;
		cout << setw(7) << "blue" << setw(15) << "" << setw(21) << blueinrow[2] << setw(27) << blueinrow[3] << setw(33) << "" << endl;
		cout << setw(7) << "purple" << setw(15) << "" << setw(21) << purpleinrow[2] << setw(27) << purpleinrow[3] << setw(33) << "" << endl;
		cout << setw(7) << "brown" << setw(15) << "" << setw(21) << browninrow[2] << setw(27) << browninrow[3] << setw(33) << "" << endl;
		cout << setw(7) << "gray" << setw(15) << "" << setw(21) << grayinrow[2] << setw(27) << grayinrow[3] << setw(33) << "" << endl;
		cout << setw(7) << "plustwo" << setw(15) << "" << setw(21) << plustwoinrow[2] << setw(27) << plustwoinrow[3] << setw(33) << "" << endl;
		cout << setw(7) << "rainbow" << setw(15) << "" << setw(21) << rainbowinrow[2] << setw(27) << rainbowinrow[3] << setw(33) << "" << endl;
	}
	if (e[1] != 1 && e[2] != 0 && e[3] != 0 && e[4] != 1)
	{
		cout << setw(15) << "row1" << setw(21) << "row2" << setw(27) << "row3" << setw(33) << "row4" << endl;
		cout << setw(7) << "red" << setw(15) << redinrow[1] << setw(21) << "" << setw(27) << "" << setw(33) << redinrow[4] << endl;
		cout << setw(7) << "yellow" << setw(15) << yellowinrow[1] << setw(21) << "" << setw(27) << "" << setw(33) << yellowinrow[4] << endl;
		cout << setw(7) << "green" << setw(15) << greeninrow[1] << setw(21) << "" << setw(27) << "" << setw(33) << greeninrow[4] << endl;
		cout << setw(7) << "blue" << setw(15) << blueinrow[1] << setw(21) << "" << setw(27) << "" << setw(33) << blueinrow[4] << endl;
		cout << setw(7) << "purple" << setw(15) << purpleinrow[1] << setw(21) << "" << setw(27) << "" << setw(33) << purpleinrow[4] << endl;
		cout << setw(7) << "brown" << setw(15) << browninrow[1] << setw(21) << "" << setw(27) << "" << setw(33) << browninrow[4] << endl;
		cout << setw(7) << "gray" << setw(15) << grayinrow[1] << setw(21) << "" << setw(27) << "" << setw(33) << grayinrow[4] << endl;
		cout << setw(7) << "plustwo" << setw(15) << plustwoinrow[1] << setw(21) << "" << setw(27) << "" << setw(33) << plustwoinrow[4] << endl;
		cout << setw(7) << "rainbow" << setw(15) << rainbowinrow[1] << setw(21) << "" << setw(27) << "" << setw(33) << rainbowinrow[4] << endl;
	}
	if (e[1] != 1 && e[2] != 0 && e[3] != 1 && e[4] != 0)
	{
		cout << setw(15) << "row1" << setw(21) << "row2" << setw(27) << "row3" << setw(33) << "row4" << endl;
		cout << setw(7) << "red" << setw(15) << redinrow[1] << setw(21) << "" << setw(27) << redinrow[3] << setw(33) << "" << endl;
		cout << setw(7) << "yellow" << setw(15) << yellowinrow[1] << setw(21) << "" << setw(27) << yellowinrow[3] << setw(33) << "" << endl;
		cout << setw(7) << "green" << setw(15) << greeninrow[1] << setw(21) << "" << setw(27) << greeninrow[3] << setw(33) << "" << endl;
		cout << setw(7) << "blue" << setw(15) << blueinrow[1] << setw(21) << "" << setw(27) << blueinrow[3] << setw(33) << "" << endl;
		cout << setw(7) << "purple" << setw(15) << purpleinrow[1] << setw(21) << "" << setw(27) << purpleinrow[3] << setw(33) << "" << endl;
		cout << setw(7) << "brown" << setw(15) << browninrow[1] << setw(21) << "" << setw(27) << browninrow[3] << setw(33) << "" << endl;
		cout << setw(7) << "gray" << setw(15) << grayinrow[1] << setw(21) << "" << setw(27) << grayinrow[3] << setw(33) << "" << endl;
		cout << setw(7) << "plustwo" << setw(15) << plustwoinrow[1] << setw(21) << "" << setw(27) << plustwoinrow[3] << setw(33) << "" << endl;
		cout << setw(7) << "rainbow" << setw(15) << rainbowinrow[1] << setw(21) << "" << setw(27) << rainbowinrow[3] << setw(33) << "" << endl;
	}
	if (e[1] != 1 && e[2] != 1 && e[3] != 0 && e[4] != 0)

	{
		cout << setw(15) << "row1" << setw(21) << "row2" << setw(27) << "row3" << setw(33) << "row4" << endl;
		cout << setw(7) << "red" << setw(15) << redinrow[1] << setw(21) << redinrow[2] << setw(27) << "" << setw(33) << "" << endl;
		cout << setw(7) << "yellow" << setw(15) << yellowinrow[1] << setw(21) << yellowinrow[2] << setw(27) << "" << setw(33) << "" << endl;
		cout << setw(7) << "green" << setw(15) << greeninrow[1] << setw(21) << greeninrow[2] << setw(27) << "" << setw(33) << "" << endl;
		cout << setw(7) << "blue" << setw(15) << blueinrow[1] << setw(21) << blueinrow[2] << setw(27) << "" << setw(33) << "" << endl;
		cout << setw(7) << "purple" << setw(15) << purpleinrow[1] << setw(21) << purpleinrow[2] << setw(27) << "" << setw(33) << "" << endl;
		cout << setw(7) << "brown" << setw(15) << browninrow[1] << setw(21) << browninrow[2] << setw(27) << "" << setw(33) << "" << endl;
		cout << setw(7) << "gray" << setw(15) << grayinrow[1] << setw(21) << grayinrow[2] << setw(27) << "" << setw(33) << "" << endl;
		cout << setw(7) << "plustwo" << setw(15) << plustwoinrow[1] << setw(21) << plustwoinrow[2] << setw(27) << "" << setw(33) << "" << endl;
		cout << setw(7) << "rainbow" << setw(15) << rainbowinrow[1] << setw(21) << rainbowinrow[2] << setw(27) << "" << setw(33) << "" << endl;
	}
	if (e[1] != 0 && e[2] != 0 && e[3] != 0 && e[4] != 1)
	{
		cout << setw(15) << "row1" << setw(21) << "row2" << setw(27) << "row3" << setw(33) << "row4" << endl;
		cout << setw(7) << "red" << setw(15) << "" << setw(21) << "" << setw(27) << "" << setw(33) << redinrow[4] << endl;
		cout << setw(7) << "yellow" << setw(15) << "" << setw(21) <<"" << setw(27) << "" << setw(33) << yellowinrow[4] << endl;
		cout << setw(7) << "green" << setw(15) << "" << setw(21) <<"" << setw(27) << "" << setw(33) << greeninrow[4] << endl;
		cout << setw(7) << "blue" << setw(15) << "" << setw(21) << "" << setw(27) << "" << setw(33) << blueinrow[4] << endl;
		cout << setw(7) << "purple" << setw(15) << "" << setw(21) << "" << setw(27) << "" << setw(33) << purpleinrow[4] << endl;
		cout << setw(7) << "brown" << setw(15) << "" << setw(21) << "" << setw(27) << "" << setw(33) << browninrow[4] << endl;
		cout << setw(7) << "gray" << setw(15) << "" << setw(21) << "" << setw(27) <<"" << setw(33) << grayinrow[4] << endl;
		cout << setw(7) << "plustwo" << setw(15) << "" << setw(21) << "" << setw(27) << "" << setw(33) << plustwoinrow[4] << endl;
		cout << setw(7) << "rainbow" << setw(15) << "" << setw(21) <<"" << setw(27) << "" << setw(33) << rainbowinrow[4] << endl;
	}
	if (e[1] != 0 && e[2] != 0 && e[3] != 1 && e[4] != 0)
	{
		cout << setw(15) << "row1" << setw(21) << "row2" << setw(27) << "row3" << setw(33) << "row4" << endl;
		cout << setw(7) << "red" << setw(15) << "" << setw(21) << "" << setw(27) << redinrow[3] << setw(33) << "" << endl;
		cout << setw(7) << "yellow" << setw(15) << "" << setw(21) <<"" << setw(27) << yellowinrow[3] << setw(33) << "" << endl;
		cout << setw(7) << "green" << setw(15) << "" << setw(21) << "" << setw(27) << greeninrow[3] << setw(33) << "" << endl;
		cout << setw(7) << "blue" << setw(15) << ""<< setw(21) << "" << setw(27) << blueinrow[3] << setw(33) << "" << endl;
		cout << setw(7) << "purple" << setw(15) << "" << setw(21) << "" << setw(27) << purpleinrow[3] << setw(33) << "" << endl;
		cout << setw(7) << "brown" << setw(15) <<"" << setw(21) << "" << setw(27) << browninrow[3] << setw(33) << "" << endl;
		cout << setw(7) << "gray" << setw(15) <<"" << setw(21) << "" << setw(27) << grayinrow[3] << setw(33) << "" << endl;
		cout << setw(7) << "plustwo" << setw(15) <<"" << setw(21) << "" << setw(27) << plustwoinrow[3] << setw(33) << "" << endl;
		cout << setw(7) << "rainbow" << setw(15) << "" << setw(21) << "" << setw(27) << rainbowinrow[3] << setw(33) << "" << endl;
	}
	if (e[1] != 0 && e[2] != 1 && e[3] != 0 && e[4] != 0)
	{
		cout << setw(15) << "row1" << setw(21) << "row2" << setw(27) << "row3" << setw(33) << "row4" << endl;
		cout << setw(7) << "red" << setw(15) << "" << setw(21) << redinrow[2] << setw(27) << "" << setw(33) << "" << endl;
		cout << setw(7) << "yellow" << setw(15) << "" << setw(21) << yellowinrow[2] << setw(27) << "" << setw(33) <<"" << endl;
		cout << setw(7) << "green" << setw(15) << "" << setw(21) << greeninrow[2] << setw(27) <<"" << setw(33) << "" << endl;
		cout << setw(7) << "blue" << setw(15) <<"" << setw(21) << blueinrow[2] << setw(27) << "" << setw(33) << "" << endl;
		cout << setw(7) << "purple" << setw(15) <<"" << setw(21) << purpleinrow[2] << setw(27) << "" << setw(33) <<"" << endl;
		cout << setw(7) << "brown" << setw(15) << "" << setw(21) << browninrow[2] << setw(27) << "" << setw(33) << "" << endl;
		cout << setw(7) << "gray" << setw(15) <<"" << setw(21) << grayinrow[2] << setw(27) << "" << setw(33) <<"" << endl;
		cout << setw(7) << "plustwo" << setw(15) << "" << setw(21) << plustwoinrow[2] << setw(27) << "" << setw(33) << "" << endl;
		cout << setw(7) << "rainbow" << setw(15) <<"" << setw(21) << rainbowinrow[2] << setw(27) << "" << setw(33) << "" << endl;
	}
	if (e[1] != 1 && e[2] != 0 && e[3] != 0 && e[4] != 0)
	{
		cout << setw(15) << "row1" << setw(21) << "row2" << setw(27) << "row3" << setw(33) << "row4" << endl;
		cout << setw(7) << "red" << setw(15) << redinrow[1] << setw(21) << "" << setw(27) << "" << setw(33) << "" << endl;
		cout << setw(7) << "yellow" << setw(15) << yellowinrow[1] << setw(21) << "" << setw(27) << "" << setw(33) << "" << endl;
		cout << setw(7) << "green" << setw(15) << greeninrow[1] << setw(21) << "" << setw(27) <<"" << setw(33) << "" << endl;
		cout << setw(7) << "blue" << setw(15) << blueinrow[1] << setw(21) << "" << setw(27) << "" << setw(33) <<"" << endl;
		cout << setw(7) << "purple" << setw(15) << purpleinrow[1] << setw(21) <<"" << setw(27) <<"" << setw(33) << "" << endl;
		cout << setw(7) << "brown" << setw(15) << browninrow[1] << setw(21) << "" << setw(27) << "" << setw(33) <<"" << endl;
		cout << setw(7) << "gray" << setw(15) << grayinrow[1] << setw(21) << "" << setw(27) <<"" << setw(33) << "" << endl;
		cout << setw(7) << "plustwo" << setw(15) << plustwoinrow[1] << setw(21) << "" << setw(27) <<"" << setw(33) << "" << endl;
		cout << setw(7) << "rainbow" << setw(15) << rainbowinrow[1] << setw(21) << "" << setw(27) << "" << setw(33) << "" << endl;
	}
	for (int i = 0; i <= 76; i++)
	{
		switch (f[i])
		{
		case 1:
			redinplayer[1]++;
			break;
		case 2:
			yellowinplayer[1]++;
			break;
		case 3:
			greeninplayer[1]++;
			break;
		case 4:
			blueinplayer[1]++;
			break;
		case 5:
			purpleinplayer[1]++;
			break;
		case 6:
			browninplayer[1]++;
			break;
		case 7:
			grayinplayer[1]++;
			break;
		case 8:
			plustwoinplayer[1]++;
			break;
		case 9:
			rainbowinplayer[1]++;
			break;
		}
		switch (g[i])
		{
		case 1:
			redinplayer[2]++;
			break;
		case 2:
			yellowinplayer[2]++;
			break;
		case 3:
			greeninplayer[2]++;
			break;
		case 4:
			blueinplayer[2]++;
			break;
		case 5:
			purpleinplayer[2]++;
			break;
		case 6:
			browninplayer[2]++;
			break;
		case 7:
			grayinplayer[2]++;
			break;
		case 8:
			plustwoinplayer[2]++;
			break;
		case 9:
			rainbowinplayer[2]++;
			break;
		}
		switch (h[i])
		{
		case 1:
			redinplayer[3]++;
			break;
		case 2:
			yellowinplayer[3]++;
			break;
		case 3:
			greeninplayer[3]++;
			break;
		case 4:
			blueinplayer[3]++;
			break;
		case 5:
			purpleinplayer[3]++;
			break;
		case 6:
			browninplayer[3]++;
			break;
		case 7:
			grayinplayer[3]++;
			break;
		case 8:
			plustwoinplayer[3]++;
			break;
		case 9:
			rainbowinplayer[3]++;
			break;
		}
		switch (j[i])
		{
		case 1:
			redinplayer[4]++;
			break;
		case 2:
			yellowinplayer[4]++;
			break;
		case 3:
			greeninplayer[4]++;
			break;
		case 4:
			blueinplayer[4]++;
			break;
		case 5:
			purpleinplayer[4]++;
			break;
		case 6:
			browninplayer[4]++;
			break;
		case 7:
			grayinplayer[4]++;
			break;
		case 8:
			plustwoinplayer[4]++;
			break;
		case 9:
			rainbowinplayer[4]++;
			break;
		}
	}
	cout << setw(15) << "you" << setw(21) << "player1" << setw(27) << "player2" << setw(33) << "player3" << endl;
	cout << setw(7) << "red" << setw(15) << redinplayer[1] << setw(21) << redinplayer[2] << setw(27) << redinplayer[3] << setw(33) << redinplayer[4] << endl;
	cout << setw(7) << "yellow" << setw(15) << yellowinplayer[1] << setw(21) << yellowinplayer[2] << setw(27) << yellowinplayer[3] << setw(33) << yellowinplayer[4] << endl;
	cout << setw(7) << "green" << setw(15) << greeninplayer[1] << setw(21) << greeninplayer[2] << setw(27) << greeninplayer[3] << setw(33) << greeninplayer[4] << endl;
	cout << setw(7) << "blue" << setw(15) << blueinplayer[1] << setw(21) << blueinplayer[2] << setw(27) << blueinplayer[3] << setw(33) << blueinplayer[4] << endl;
	cout << setw(7) << "purple" << setw(15) << purpleinplayer[1] << setw(21) << purpleinplayer[2] << setw(27) << purpleinplayer[3] << setw(33) << purpleinplayer[4] << endl;
	cout << setw(7) << "brown" << setw(15) << browninplayer[1] << setw(21) << browninplayer[2] << setw(27) << browninplayer[3] << setw(33) << browninplayer[4] << endl;
	cout << setw(7) << "gray" << setw(15) << grayinplayer[1] << setw(21) << grayinplayer[2] << setw(27) << grayinplayer[3] << setw(33) << grayinplayer[4] << endl;
	cout << setw(7) << "plustwo" << setw(15) << plustwoinplayer[1] << setw(21) << plustwoinplayer[2] << setw(27) << plustwoinplayer[3] << setw(33) << plustwoinplayer[4] << endl;
	cout << setw(7) << "rainbow" << setw(15) << rainbowinplayer[1] << setw(21) << rainbowinplayer[2] << setw(27) << rainbowinplayer[3] << setw(33) << rainbowinplayer[4] << endl;
	return;
}
void endofgame(int f[], int g[], int h[], int j[])
{
	int redinplayer[5] = { 0 }, yellowinplayer[5] = { 0 }, greeninplayer[5] = { 0 }, blueinplayer[5] = { 0 }, purpleinplayer[5] = { 0 }, browninplayer[5] = { 0 }, grayinplayer[5] = { 0 }, plustwoinplayer[5] = { 0 }, rainbowinplayer[5] = { 0 };
	for (int i = 0; i <= 76; i++)
	{
		switch (f[i])
		{
		case 1:
			redinplayer[1]++;
			break;
		case 2:
			yellowinplayer[1]++;
			break;
		case 3:
			greeninplayer[1]++;
			break;
		case 4:
			blueinplayer[1]++;
			break;
		case 5:
			purpleinplayer[1]++;
			break;
		case 6:
			browninplayer[1]++;
			break;
		case 7:
			grayinplayer[1]++;
			break;
		case 8:
			plustwoinplayer[1]++;
			break;
		case 9:
			rainbowinplayer[1]++;
			break;
		}
		switch (g[i])
		{
		case 1:
			redinplayer[2]++;
			break;
		case 2:
			yellowinplayer[2]++;
			break;
		case 3:
			greeninplayer[2]++;
			break;
		case 4:
			blueinplayer[2]++;
			break;
		case 5:
			purpleinplayer[2]++;
			break;
		case 6:
			browninplayer[2]++;
			break;
		case 7:
			grayinplayer[2]++;
			break;
		case 8:
			plustwoinplayer[2]++;
			break;
		case 9:
			rainbowinplayer[2]++;
			break;
		}
		switch (h[i])
		{
		case 1:
			redinplayer[3]++;
			break;
		case 2:
			yellowinplayer[3]++;
			break;
		case 3:
			greeninplayer[3]++;
			break;
		case 4:
			blueinplayer[3]++;
			break;
		case 5:
			purpleinplayer[3]++;
			break;
		case 6:
			browninplayer[3]++;
			break;
		case 7:
			grayinplayer[3]++;
			break;
		case 8:
			plustwoinplayer[3]++;
			break;
		case 9:
			rainbowinplayer[3]++;
			break;
		}
		switch (j[i])
		{
		case 1:
			redinplayer[4]++;
			break;
		case 2:
			yellowinplayer[4]++;
			break;
		case 3:
			greeninplayer[4]++;
			break;
		case 4:
			blueinplayer[4]++;
			break;
		case 5:
			purpleinplayer[4]++;
			break;
		case 6:
			browninplayer[4]++;
			break;
		case 7:
			grayinplayer[4]++;
			break;
		case 8:
			plustwoinplayer[4]++;
			break;
		case 9:
			rainbowinplayer[4]++;
			break;
		}
	}
	int numberyou[10] = {redinplayer[1] ,yellowinplayer[1] ,greeninplayer[1],blueinplayer[1],purpleinplayer[1], browninplayer[1] ,grayinplayer[1] ,plustwoinplayer[1] ,rainbowinplayer[1] };
	int numberplayer1[10] = { redinplayer[2] ,yellowinplayer[2] ,greeninplayer[2],blueinplayer[2],purpleinplayer[2], browninplayer[2] ,grayinplayer[2] ,plustwoinplayer[2] ,rainbowinplayer[2] };
	int numberplayer2[10] = { redinplayer[3] ,yellowinplayer[3] ,greeninplayer[3],blueinplayer[3],purpleinplayer[3], browninplayer[3] ,grayinplayer[3] ,plustwoinplayer[3] ,rainbowinplayer[3] };
	int numberplayer3[10] = { redinplayer[4] ,yellowinplayer[4] ,greeninplayer[4],blueinplayer[4],purpleinplayer[4], browninplayer[4] ,grayinplayer[4] ,plustwoinplayer[4] ,rainbowinplayer[4] };

	for (int i=0;i<=7;i++)
	{
		for (int j = i + 1; j <= 7; j++)
		{
			if (numberyou[i] < numberyou[j])
			{
				int temp = numberyou[i];
				numberyou[i] = numberyou[j];
				numberyou[j] = temp;
			}
		}
	}
	for (int i = 0; i <= 7; i++)
	{
		for (int j = i + 1; j <= 7; j++)
		{
			if (numberplayer1[i] < numberplayer1[j])
			{
				int temp = numberplayer1[i];
				numberplayer1[i] = numberplayer1[j];
				numberplayer1[j] = temp;
			}
		}
	}
	for (int i = 0; i <= 7; i++)
	{
		for (int j = i + 1; j <= 7; j++)
		{
			if (numberplayer2[i] < numberplayer2[j])
			{
				int temp = numberplayer2[i];
				numberplayer2[i] = numberplayer2[j];
				numberplayer2[j] = temp;
			}
		}
	}
	for (int i = 0; i <= 7; i++)
	{
		for (int j = i + 1; j <= 7; j++)
		{
			if (numberplayer3[i] < numberplayer3[j])
			{
				int temp = numberplayer3[i];
				numberplayer3[i] = numberplayer3[j];
				numberplayer3[j] = temp;
			}
		}
	}
	numberyou[1] = numberyou[1] + rainbowinplayer[1];
	numberplayer1[1] = numberplayer1[1] + rainbowinplayer[2];
	numberplayer2[1] = numberplayer2[1] + rainbowinplayer[3];
	numberplayer3[1] = numberplayer3[1] + rainbowinplayer[4];
	int totalyou=0,totalplayer1=0,totalplayer2=0,totalplayer3=0;
	//記得去填變數
	for (int i = 1; i <= 4; i++)
	{
		switch (i)
		{
		case 1:
			for (int k = 1; k <= 3; k++)
			{
				switch (numberyou[k])
				{
				case 0:
					break;
				case 1:
					totalyou += 1;
					break;
				case 2:
					totalyou += 3;
					break;
				case 3:
					totalyou += 6;
					break;
				case 4:
					totalyou += 10;
					break;
				case 5:
					totalyou += 15;
					break;
				case 6:
					totalyou += 21;
					break;
				}
			}
			for (int k = 4; k <= 7; k++)
			{
				switch (numberyou[k])
				{
				case 0:
					break;
				case 1:
					totalyou -= 1;
					break;
				case 2:
					totalyou -= 3;
					break;
				case 3:
					totalyou -= 6;
					break;
				case 4:
					totalyou -= 10;
					break;
				case 5:
					totalyou -= 15;
					break;
				case 6:
					totalyou -= 21;
					break;
				}
			}
		case 2:
			for (int k = 1; k <= 3; k++)
			{
				switch (numberplayer1[k])
				{
				case 0:
					break;
				case 1:
					totalplayer1 += 1;
					break;
				case 2:
					totalplayer1 += 3;
					break;
				case 3:
					totalplayer1 += 6;
					break;
				case 4:
					totalplayer1 += 10;
					break;
				case 5:
					totalplayer1 += 15;
					break;
				case 6:
					totalplayer1 += 21;
					break;
				}
			}
			for (int k = 4; k <= 7; k++)
			{
				switch (numberplayer1[k])
				{
				case 0:
					break;
				case 1:
					totalplayer1 -= 1;
					break;
				case 2:
					totalplayer1 -= 3;
					break;
				case 3:
					totalplayer1 -= 6;
					break;
				case 4:
					totalplayer1 -= 10;
					break;
				case 5:
					totalplayer1 -= 15;
					break;
				case 6:
					totalplayer1 -= 21;
					break;
				}
			}
		case 3:
			for (int k = 1; k <= 3; k++)
			{
				switch (numberplayer2[k])
				{
				case 0:
					break;
				case 1:
					totalplayer2 += 1;
					break;
				case 2:
					totalplayer2 += 3;
					break;
				case 3:
					totalplayer2 += 6;
					break;
				case 4:
					totalplayer2 += 10;
					break;
				case 5:
					totalplayer2 += 15;
					break;
				case 6:
					totalplayer2 += 21;
					break;
				}
			}
			for (int k = 4; k <= 7; k++)
			{
				switch (numberplayer2[k])
				{
				case 0:
					break;
				case 1:
					totalplayer2 -= 1;
					break;
				case 2:
					totalplayer2 -= 3;
					break;
				case 3:
					totalplayer2 -= 6;
					break;
				case 4:
					totalplayer2 -= 10;
					break;
				case 5:
					totalplayer2 -= 15;
					break;
				case 6:
					totalplayer2 -= 21;
					break;
				}
			}
		case 4:
			for (int k = 1; k <= 3; k++)
			{
				switch (numberplayer3[k])
				{
				case 0:
					break;
				case 1:
					totalplayer3 += 1;
					break;
				case 2:
					totalplayer3 += 3;
					break;
				case 3:
					totalplayer3 += 6;
					break;
				case 4:
					totalplayer3 += 10;
					break;
				case 5:
					totalplayer3 += 15;
					break;
				case 6:
					totalplayer3 += 21;
					break;
				}
			}
			for (int k = 4; k <= 7; k++)
			{
				switch (numberplayer3[k])
				{
				case 0:
					break;
				case 1:
					totalplayer3 -= 1;
					break;
				case 2:
					totalplayer3 -= 3;
					break;
				case 3:
					totalplayer3 -= 6;
					break;
				case 4:
					totalplayer3 -= 10;
					break;
				case 5:
					totalplayer3 -= 15;
					break;
				case 6:
					totalplayer3 -= 21;
					break;
				}
			}
		}
	}
	totalyou = totalyou + 2 * numberyou[8];
	totalplayer1 = totalplayer1 + 2 * numberplayer1[8];
	totalplayer2= totalplayer2 + 2 * numberplayer2[8];
	totalplayer3 = totalplayer3 + 2 * numberplayer3[8];
	int ranking[5];
	ranking[1] = totalyou;
	ranking[2] = totalplayer1;
	ranking[3] = totalplayer2;
	ranking[4] = totalplayer3;
	for (int i = 1; i <= 4; i++)
	{
		for (int j = i + 1; j <= 4; j++)
		{
			if (ranking[i] < ranking[j])
			{
				int temp = ranking[i];
				ranking[i] = ranking[j];
				ranking[j] = temp;
			}
		}
	}
	cout << setw(10) << "player" << setw(20) << "score" << endl;
	cout << setw(10) << "you" << setw(20) << totalyou << endl;
	cout << setw(10) << "player1" << setw(20) << totalplayer1 << endl;
	cout << setw(10) << "player2" << setw(20) <<totalplayer2 << endl;
	cout << setw(10) << "player3" << setw(20) << totalplayer3 << endl;
	cout << setw(10) << "ranking" <<setw(20)<<"score" <<endl;
	cout << setw(10) << "1" << setw(20) << ranking[1] << endl;
	cout << setw(10) << "2" << setw(20) << ranking[2] << endl;
	cout << setw(10) << "3" << setw(20) << ranking[3] << endl;
	cout << setw(10) << "4" << setw(20) << ranking[4] << endl;
}