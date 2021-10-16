#include <iostream>
#include <stdio.h>
#include <ctime>
#include<locale.h>
using  namespace std;
const int CrakChance = 15;  //% вероятность появления Всемогущегокряка
const int VsegoYtok = 168;
const int VsegoDay = 8;
int numdayhunter = 0;
const int icanbeat = 70;  //требуемое количество ,,баллов,, чтобы быть не пойманной 
const int icandoit = 50;  //% вероятность не сбежать для уток, которые могут это сделать
const int icanmigr = 5; // % вероятность мигрирования утки, которая модет мигрировать
int ytokonday[4][VsegoDay + 1] = { 0 };
int gdehuntJ1 = -1;int gdehuntJ2 = -1;int gdehuntN1 = -1;int gdehuntN2 = -1;
string formakrilev[5] = { "ydlin","paryashie","ellipt","ckorostn","zavisnie" };
string colorytok[6] = { "white","black","red","orange","blue","yellow" };
string formalap[3] = { "short","long","middle" };
string okraskrilev[6] = { "white","black","red","orange","blue","yellow" };
string sexorint[2] = { "samka","samec" };
string nameofytki[18] = { "Ivan","Rodion","Porfirii","Sofia","Avdotya","Semen","Pulcheria","Katerina","Arkady","Dmitry","Marfa","Andrey","Lizaveta","Alexander","Nicodemus","Ilya","Amalia","Alena" };
string Place[4] = { " Озеро Аргентино "," Озеро Байкал "," Ферма JAMYHYP ", " Ферма NUDYWIJ " };//если переменная podrez(J/N)==0, то утка еще ни разу не была на ферме, если 1, то утка была на ферме J/N, если 2, то утке подвесили грузик/подрезали крылья

    class Ytka {
protected:
	Ytka* next{};int weight;string name;string homelake;string myplace;
public:
	int podrezN;int podrezJ;      
	friend class Lake;
	Ytka() : name(nameofytki[rand() % 18]), weight(1 + rand() % 15), podrezN(0), podrezJ(0){};
	virtual ~Ytka() {};
	virtual void taklabout() = 0;virtual int itfly() = 0;virtual int itcrak() = 0;
	virtual int itswim() = 0;virtual int itrun() = 0;virtual int itpolz() = 0;
	virtual int itmigr() = 0;virtual int itwherei() = 0;virtual int impeg() = 0;
	virtual int impeg1() = 0;virtual int imnir() = 0;virtual int imhox() = 0;
	virtual int imlay() = 0;virtual int imjel() = 0;virtual int get_lovkost() = 0;
	virtual int get_podrezJ() = 0;virtual int get_podrezN() = 0;
};
    class peganki :public Ytka {
	int fly;int razmaxk;string formak;
    public:
	peganki() : fly(1), razmaxk(5 + rand() % 95),
		formak(formakrilev[rand() % 5]) {};
	virtual ~peganki() {};
	virtual void taklabout() {
		cout << "__________________________________________";
		cout << endl << "  Пеганка";
	   cout << endl << "Имя:  " << name;
	   cout << endl << "Вес:  " << weight<<" kilo";
		cout << endl <<"Размах крыльев:  "<<razmaxk << " cm";
		cout << endl << "Форма крыльев:  "<<formak;
		cout << endl << "  Умеет летать ";
		if ((podrezJ >= 2) || (podrezN >= 2)) { cout << endl << "У меня крылья подрезаны емае!"; };
		cout << endl;
		cout << "__________________________________________";
		cout << endl;
	};
	virtual int itfly() { return 1; };virtual int itcrak() { return 0; };
	virtual int itswim() { return 0; };virtual int itrun() { return 0; };
	virtual int itpolz() { return 0; };virtual int itmigr() { return 0; };
	virtual int itwherei() { return 0; };virtual int impeg() { return 1; }
	virtual int impeg1() { return 0; }virtual int imnir() { return 0; }
	virtual int imhox() { return 0; }virtual int imlay() { return 0; }
	virtual int imjel() { return 0; }virtual int get_lovkost() { return 0; }
	virtual int get_podrezJ() {return podrezJ;}virtual int get_podrezN() { return podrezN; }
};
    class peganki1 :public Ytka {
	int crak;
	string sex;
	string okrask;
public:
	peganki1() :crak(1), sex(sexorint[rand() % 2]), okrask(okraskrilev[rand() % 6]) {};
	virtual ~peganki1() {};
	virtual void taklabout() {
		cout << "__________________________________________";
		cout << endl << "  Пеганка1";
		cout << endl << "Имя:  " << name;
		cout << endl << "Вес:  " << weight << " kilo";
		cout << endl << "Пол:  " << sex;
		cout << endl << "Окрас крыльев:  " << okrask;
		cout << endl << "  Умеет крякать";
		cout << endl;
		cout << "__________________________________________";
		cout << endl;
	};
	virtual int itfly() { return 0; };virtual int itcrak() { return 1; };
	virtual int itswim() { return 0; };virtual int itrun() { return 0; };
	virtual int itpolz() { return 0; };virtual int itmigr() { return 0; };
	virtual int itwherei() { return 0; };virtual int impeg() { return 0; }
	virtual int impeg1() { return 1; }virtual int imnir() { return 0; }
	virtual int imhox() { return 0; }virtual int imlay() { return 0; }
	virtual int imjel() { return 0; }virtual int get_lovkost() { return 0; }
	virtual int get_podrezJ() { return podrezJ; }virtual int get_podrezN() { return podrezN; }
};
    class nirky :public Ytka {
	int run;
	int heightholk;
	int razmerlap;
public:
	nirky() : run(1), heightholk(10 + rand() % 50), razmerlap(1 + rand() % 9) {};
	virtual ~nirky() {};
	virtual void taklabout() {
		cout << "__________________________________________";
		cout << endl << "  Нырка";
		cout << endl << "Имя:  " << name;
		cout << endl << "Вес:  " << weight<<" kilo";
		cout << endl << "Высота холки:  " << heightholk << " cm";
		cout << endl << "Размер лап:  " << razmerlap << " cm";
		cout << endl << "Умеет бегать";
		cout << endl;
		cout << "__________________________________________";
		cout << endl;
	};
    virtual int itfly() { return 0; };virtual int itcrak() { return 0; };
	virtual int itswim() { return 0; };virtual int itrun() { return 1; };
	virtual int itpolz() { return 0; };virtual int itmigr() { return 0; };
	virtual int itwherei() { return 0; };virtual int impeg() { return 0; }
	virtual int impeg1() { return 0; }virtual int imnir() { return 1; }
	virtual int imhox() { return 0; }virtual int imlay() { return 0; }
	virtual int imjel() { return 0; }virtual int get_lovkost() { return 0; }
	virtual int get_podrezJ() { return podrezJ; }virtual int get_podrezN() { return podrezN; }
};
    class hoxlytka :public Ytka {
	int swim;	
	int wherei;
	int lovk;
	string okrask;
public:
	hoxlytka(): swim(1), lovk (1 + rand() % 10), okrask(okraskrilev[rand() % 6]),wherei(1) {};
	virtual ~hoxlytka() {};
	virtual void taklabout() {
		cout << "__________________________________________";
		cout<< endl <<"  Хохлатая утка  ";
		cout << endl << "Имя:  " << name;
		cout << endl << "Вес:  " << weight<<" kilo";
		cout << endl << "Ловкость:  " << lovk << "/10";
		cout << endl << "окрас крыльев:  " << okrask;
		cout << endl << "  Умеет плавать";
		cout << endl << "  живет на "<< myplace;
	    if ((podrezJ >= 2) || (podrezN >= 2)) { cout << endl << "гиря на лапе, не поплаваешь..."; };
		cout << endl;
		cout << "__________________________________________";
		cout << endl;
	};
	virtual int itfly() { return 0; };virtual int itcrak() { return 0; };
	virtual int itswim() { return 1; };virtual int itrun() { return 0; };
	virtual int itpolz() { return 0; };virtual int itmigr() { return 0; };
	virtual int itwherei() { return 1; };virtual int impeg() { return 0; }
	virtual int impeg1() { return 0; }virtual int imnir() { return 0; }
	virtual int imhox() { return 1; }virtual int imlay() { return 0; }
	virtual int imjel() { return 0; }virtual int get_lovkost() { return lovk; }
	virtual int get_podrezJ() { return podrezJ; }virtual int get_podrezN() { return podrezN; }
};
    class laysanytka :public Ytka {
	int polz;
	int razmerkluv;
	string formlap;
public:
	laysanytka() : polz(1), razmerkluv(1 + rand() % 10), formlap(formalap[rand() % 3]) {};
	virtual ~laysanytka() {};
	virtual void taklabout() {
		cout << "__________________________________________";
		cout << endl << "  Лайсанская кряква";
		cout << endl << "Имя:  " << name;
		cout << endl << "Вес:  " << weight<<" kilo";
		cout << endl << "Размер клюва:  "<< razmerkluv<<" cm";
		cout << endl << "Форма лап:  " << formlap;
		cout << endl << "  Умеет ползать";
		cout << endl;
		cout << "__________________________________________";
		cout << endl;
	};
	virtual int itfly() { return 0; };virtual int itcrak() { return 0; };
	virtual int itswim() { return 0; };virtual int itrun() { return 0; };
	virtual int itpolz() { return 1; };virtual int itmigr() { return 0; };
	virtual int itwherei() { return 0; };virtual int impeg() { return 0; }
	virtual int impeg1() { return 0; }virtual int imnir() { return 0; }
	virtual int imhox() { return 0; }virtual int imlay() { return 1; }
	virtual int imjel() { return 0; }virtual int get_lovkost() { return 0; }
	virtual int get_podrezJ() { return podrezJ; }virtual int get_podrezN() { return podrezN; }
};
    class jeltshirok :public Ytka {
	int migr;
	int razmaxk;
	string color;
public:
	jeltshirok() :migr(1), razmaxk(5 + rand() % 95), color(colorytok[rand() % 6]) {};
	virtual ~jeltshirok() {};
	virtual void taklabout() {
		cout << "__________________________________________";
		cout << endl << "Желтоклювый чирок" ;
		cout << endl << "Имя:  " << name;
		cout << endl << "Вес:  " << weight<<" kilo";
		cout << endl << "Размах крыльев:  " << razmaxk << " cm";
		cout << endl << "Цвет:  " << color;
		cout << endl << "  Умеет мигрировать";
		cout << endl;
		cout << "__________________________________________";
		cout << endl;
		};
	virtual int itfly() { return 0; };virtual int itcrak() { return 0; };
	virtual int itswim() { return 0; };virtual int itrun() { return 0; };
	virtual int itpolz() { return 0; };virtual int itmigr() { return 1; };
	virtual int itwherei() { return 0; };virtual int impeg() { return 0; }
	virtual int impeg1() { return 0; }virtual int imnir() { return 0; }
	virtual int imhox() { return 0; }virtual int imlay() { return 0; }
	virtual int imjel() { return 1; }virtual int get_lovkost() { return 0; }
	virtual int get_podrezJ() { return podrezJ; }virtual int get_podrezN() { return podrezN; }
};
	class Lake {

		Ytka* head;//указатель на первую утку в списке на объетке
		int kolytok;//кол-во уток на объекте
		int sfly;//кол-во летающих уток 
		int scrak;//кол-во крякающих уток 
		int sswim;//кол-во плавающих уток 
		int srun;//кол-во бегающих уток 
		int spolz;//кол-во ползающих уток 
		int smigr;//кол-во мигрирующих уток 
		int swherei;//кол-во, которые знают, где находятся
		int peghere;//кол-во Пеганок на объекте
		int peg1here;//кол-во Пеганок1
		int nirhere;//кол-во нырок
		int hoxhere;//кол-во хохлатых уток
		int layhere;//кол-во Лайсанских крякв
		int jelhere;//кол-во Желтоклювых чирок

     public:
		string nameLake;//название объекта
		Lake() : head(NULL), kolytok(0), sfly(0), scrak(0), sswim(0), spolz(0), srun(0), smigr(0), swherei(0), peghere(0), peg1here(0), nirhere(0), hoxhere(0), layhere(0), jelhere(0) {};
		~Lake()
		{Ytka* prev = NULL;
			if (head) {
				while (head->next) {
					prev = head;
					head = head->next;
					delete prev;
					prev = NULL;
				};
				delete head;
			}
         };

		void dobav(Ytka* node) {
			Ytka* prev = NULL;
			if (head == NULL)
			{
				head = node;
				head->next = NULL;
				kolytok++;
				sfly += (node->itfly());
				scrak += (node->itcrak());
				sswim += (node->itswim());
				srun += (node->itrun());
				spolz += (node->itpolz());
				smigr += (node->itmigr());
				swherei += (node->itwherei());
				peghere += (node->impeg());
				peg1here += (node->impeg1());
				nirhere += (node->imnir());
				hoxhere += (node->imhox());
				layhere += (node->imlay());
				jelhere += (node->imjel());

			}
			else {
				prev = head;
				while ((prev) && (prev->next)) { prev = prev->next; };
				if ((prev) && ((prev->next) == NULL)) {
					prev->next = node;
				}
				kolytok++;
				sfly += (node->itfly());
				scrak += (node->itcrak());
				sswim += (node->itswim());
				srun += (node->itrun());
				spolz += (node->itpolz());
				smigr += (node->itmigr());
				swherei += (node->itwherei());
				peghere += (node->impeg());
				peg1here += (node->impeg1());
				nirhere += (node->imnir());
				hoxhere += (node->imhox());
				layhere += (node->imlay());
				jelhere += (node->imjel());

			};
		}
		void opis_ytok() {
			Ytka* prev = head;
			while (prev) { prev->taklabout(); prev = prev->next; }
		}
	    void getinfo() {
			cout << endl << "_____________|" << nameLake << "|_____________" << endl;
			cout << "Уток     : " << kolytok << endl;
			if (peghere) { cout << "Пеганок: " << peghere << endl; };
			if (peg1here) { cout << "Пеганок1: " << peg1here << endl; };
			if (nirhere) { cout << "Нырок: " << nirhere << endl; };
			if (hoxhere) { cout << "Хохлатых: " << hoxhere << endl; };
			if (layhere) { cout << "Лайсанских: " << layhere << endl; };
			if (jelhere) { cout << "Желтоклювых: " << jelhere << endl; };
			cout << "Умеют-" << endl;
			if (sfly)cout << "летать:              " << sfly << " уток" << endl;
			if (scrak)cout << "крякать:             " << scrak << " уток" << endl;
			if (sswim)cout << "плавать:             " << sswim << " уток" << endl;
			if (spolz)cout << "ползать:             " << spolz << " уток" << endl;
			if (srun)cout << "бегать:              " << srun << " уток" << endl;
			if (smigr)cout << "мигрировать:         " << smigr << " уток" << endl;
			if (swherei)cout << "знают, где живут " << swherei << " уток" << endl;
			cout << "_______________________________________" << endl;
		};
		int get_kolytok() { return kolytok; };
		int get_sfly() { return sfly; };
		int get_scrak() { return scrak; };
		int get_sswim() { return sswim; };
		int get_srun() { return srun; };
		int get_spolz() { return spolz; };
		int get_smigr() { return smigr; };
		int get_wherei() { return swherei; };
		string get_nameLake() { return nameLake; };         //удаляет утку с фермы\озера, возвращает ссылку на удаленную утку
		Ytka* kick(int i) {
			Ytka* prev=NULL;
			Ytka * tmp;
			tmp = head;
			if (!i)   //если удаляемая утка в начале списка
			{
				head = head->next;
				tmp->next = NULL;
				kolytok = kolytok - 1;
				sfly -= (tmp->itfly());
				scrak -= (tmp->itcrak());
				srun -= (tmp->itrun());
				sswim -= (tmp->itswim());
				spolz -= (tmp->itpolz());
				smigr -= (tmp->itmigr());
				swherei -= (tmp->itwherei());
				peghere -= (tmp->impeg());
				peg1here -= (tmp->impeg1());
				nirhere -= (tmp->imnir());
				hoxhere -= (tmp->imhox());
				layhere -= (tmp->imlay());
				jelhere -= (tmp->imjel());
				return tmp;
			}
			while (i != 1){
				tmp = tmp->next;
				i--;
			}
			prev = tmp;
			tmp = tmp->next;
			prev->next = tmp->next;
			tmp->next = NULL;
			kolytok = kolytok - 1;
			sfly -= (tmp->itfly());
			scrak -= (tmp->itcrak());
			srun -= (tmp->itrun());
			sswim -= (tmp->itswim());
			spolz -= (tmp->itpolz());
			smigr -= (tmp->itmigr());
			swherei -= (tmp->itwherei());
			peghere -= (tmp->impeg());
			peg1here -= (tmp->impeg1());
			nirhere -= (tmp->imnir());
			hoxhere -= (tmp->imhox());
			layhere -= (tmp->imlay());
			jelhere -= (tmp->imjel());
             return tmp;
		};
	                                                           //функция описывает шансы уток убежать\улететь\уплыть от охотников	                                                      
		int Strongytki(Lake* node, int idytki) {
			int totalchance = 0;
			Ytka* tmp = head;
			for (int i = 0; i < idytki; i++) { tmp->next; }
			if (head->itfly()) { totalchance = totalchance + rand() % 81; }; // шанс утки улететь от охотника от 0 до 80
			if (head->itcrak()) { totalchance = totalchance + rand() % 71; };//шанс утки оглушить охотника кряканием и скрыться от 0 до 70
			if (head->itswim()) { totalchance = totalchance + rand() % 75; };//шанс утки уплыть от охотника от 0 до 74
			if (head->itpolz()) { totalchance = totalchance + rand() % 72; };//шанс утки уползти от охотника от 0 до 71
			if (head->itrun()) { totalchance = totalchance + rand() % 77; };//шанс утки уползти от охотника от 0 до 76
			if (head->get_lovkost() > 0) { int a = (head->get_lovkost()); totalchance = totalchance + a * (1 + rand() % 6); };//дополнительный супер шанс утки, если  она обладает  ловкостью
			if (totalchance >= icanbeat) { return 1; }
			else { return 0; };
		};
		                                            //присваивает уткам их домашнее озеро(при i=1) и их текущее озеро(если такое свойство есть у утки)(при i=0)
		void checkplace(int i) {
            Ytka* prev = head;
			while (prev) {
				if (i == 1) {
					if (prev->itwherei() == 1) { prev->myplace = nameLake; prev = prev->next; }
					else { prev = prev->next; };
				};
				if (i == 0) { prev->homelake = nameLake; prev = prev->next; };
			}
		}
		                                          //функция описывающая бегство уток с ферм ( i управляет тем, к какой ферме выполнять условия) 0-JAMYHYP, 1-NUDYWIJ
		int leave_farm(Lake* node1, Lake* node2, int i) {
			int kto_to_sbegal = 0;
			if (i == 0) {
				Ytka* node = head;
				int idytki = 0;
				while (node != NULL) {
					if ((node->itwherei() == 0) && (node->itfly() == 1)&&(node->podrezJ<2)) {
						int chance = rand() % 101;
						if (chance >= icandoit) {
							int lakego = rand() % 2;
							if (lakego == 0) {
								Ytka* spasennaia = kick(idytki);
								node1->dobav(spasennaia); kto_to_sbegal++;
								cout << endl << " Утка " << spasennaia->name << ", вес  " << spasennaia->weight << " Смогла улететь с "<<nameLake<<" на " << node1->nameLake << endl;
								spasennaia->homelake = node1->nameLake;
								idytki--;
							};
							if (lakego == 1) {
								Ytka* spasennaia = kick(idytki);
								node2->dobav(spasennaia); kto_to_sbegal++;
								cout << endl << " Утка " << spasennaia->name << ", вес  " << spasennaia->weight << " смогла улететь с " << nameLake << " на " << node2->nameLake << endl;
								spasennaia->homelake = node2->nameLake;
								idytki--;
							};
						}
						else { if (node->next) { node = node->next; } else { break; }; };
					}
					else { if (node->next) { node = node->next; } else { break; }; };
					if (node->next) { node = node->next; }else { break; };
					idytki++;
				};
			};
			if (i == 1) {
				Ytka* node = head;
				int idytki = 0;
				while (node != NULL) {
					if ((node->itswim() == 1) && (node->itwherei() == 1) && (node->podrezN < 2)) {
						int chance = rand() % 101;
						if (chance >= icandoit) {
							if (node1->nameLake == node->homelake) {
								Ytka* spasennaia = kick(idytki);
								node1->dobav(spasennaia); kto_to_sbegal++;
								cout << endl << " Утка " << spasennaia->name << ", вес " << spasennaia->weight << " смогла уплыть с " << nameLake << " на свое родное " << node1->nameLake << endl;
								spasennaia->homelake = node1->nameLake;
								idytki--;
							}
							if (node2->nameLake == node->homelake) {
								Ytka* spasennaia = kick(idytki);
								node2->dobav(spasennaia); kto_to_sbegal++;
								cout << endl << " Утка " << spasennaia->name << ", вес " << spasennaia->weight << " смогла уплыть с " << nameLake << " на свое родное " << node2->nameLake << endl;
								spasennaia->homelake = node2->nameLake;
								idytki--;
							};
						}
						else { if (node->next) { node = node->next; } else { break; }; };
					}
					else { if (node->next) { node = node->next; } else { break; }; };
					idytki++;
					if (node->next) { node = node->next; }else { break; };
				};
			}; return kto_to_sbegal;
    };
		void migration(Lake* node1) {
			Ytka* node = head;
			int idytki = 0;
			while (node) {
				if (node->itmigr() == 1) {
					if (rand() % 101 <= icanmigr) {
						Ytka* leaver = kick(idytki);
						node1->dobav(leaver);
						cout<<endl <<"Утка "<< leaver->name<<" мигрировала на  "<<node1->nameLake<<endl;
					}
					else { if (node->next) { node = node->next; idytki++; } else { break; } };
				}
				else { if (node->next) { node = node->next; idytki++; } else { break; } };
				if (node->next) { node = node->next; }
				else { break; };
			}
		}

	};

		void hunt(Lake* node1, Lake* node2, Lake* node3, Lake* node4) {
			int sravneniesytokonday = 0;
			Lake* placehunt[2] = { node1,node2 };
			if (node1->get_kolytok() == 0) {
				gdehuntJ1 = 1;
				gdehuntJ2 = 1;
				gdehuntN1 = 1;
				gdehuntN2 = 1;
			};
			if (node2->get_kolytok() == 0) {
				gdehuntJ1 = 0;
				gdehuntJ2 = 0;
				gdehuntN1 = 0;
				gdehuntN2 = 0;
			}
			else {
				gdehuntJ1 =0+ rand() % 2;
				gdehuntJ2 =0+ rand() % 2;
				gdehuntN1 =0+ rand() % 2;
				gdehuntN2 =0+ rand() % 2;
			};
			ytokonday[0][numdayhunter] = 2 + rand() % 6;
			ytokonday[1][numdayhunter] = 1 + rand() % 8;
			ytokonday[2][numdayhunter] = 3 + rand() % 3;
			ytokonday[3][numdayhunter] = 2 + rand() % 4;
		for (int i = 1; i <= (ytokonday[0][numdayhunter] - sravneniesytokonday); ) {          //Охотник 1 с фермы JAMYHYP
				if (placehunt[gdehuntJ1]->get_kolytok() == 0) { 
					cout << "Охонтик 1 с фермы JAMYHYP не поймал ни одной утки на " << placehunt[gdehuntJ1]->nameLake << endl; 
					ytokonday[0][numdayhunter] = 0; break; };
				if (placehunt[gdehuntJ1]->get_kolytok() < (ytokonday[0][numdayhunter] - sravneniesytokonday)) {
					ytokonday[0][numdayhunter] = placehunt[gdehuntJ1]->get_kolytok(); };
				int idytki = rand() % (placehunt[gdehuntJ1]->get_kolytok());
				if (placehunt[gdehuntJ1]->Strongytki(placehunt[gdehuntJ1], idytki) == 1) {
					ytokonday[0][numdayhunter]--;
					if (ytokonday[0][numdayhunter] == 0) { cout << "Охотник 1 с фермы JAMYHYP не поймал ни одной утки на "<< placehunt[gdehuntJ1]->nameLake << endl; ytokonday[0][numdayhunter] = 0; break;};
				}
				else {
					Ytka* poimanay = placehunt[gdehuntJ1]->kick(idytki);
					if ((poimanay->itswim()==1)||(poimanay->itfly()==1)){poimanay->podrezJ++; }
					node3->dobav(poimanay);
					sravneniesytokonday++;
				}
			  if (sravneniesytokonday >= (ytokonday[0][numdayhunter])) { cout << "Охотник 1 с фермы JAMYHYP поймал " << ytokonday[0][numdayhunter] << " уток"<<" на " << placehunt[gdehuntJ1]->nameLake << endl; };
		}; sravneniesytokonday = 0;
		for (int i = 1; i <= (ytokonday[1][numdayhunter] - sravneniesytokonday); ) {                   //Охотник 2 с фермы JAMYHYP
			if (placehunt[gdehuntJ2]->get_kolytok() == 0) { cout << "Охотник 2 с фермы JAMYHYP не поймал ни одной утки на " << placehunt[gdehuntJ2]->nameLake << endl; ytokonday[1][numdayhunter] = 0; break; };
			if (placehunt[gdehuntJ2]->get_kolytok() < (ytokonday[1][numdayhunter] - sravneniesytokonday)) { ytokonday[1][numdayhunter] = placehunt[gdehuntJ2]->get_kolytok(); };
			int idytki = rand() % (placehunt[gdehuntJ2]->get_kolytok());
			if (placehunt[gdehuntJ2]->Strongytki(placehunt[gdehuntJ2], idytki) == 1) {
				ytokonday[1][numdayhunter]--;
				if (ytokonday[1][numdayhunter] == 0) { cout << "Охотник 2 с фермы NUDYWIJ не поймал ни одной утки на " << placehunt[gdehuntJ2]->nameLake << endl; ytokonday[1][numdayhunter] = 0;  break;};
			}
			else {
				Ytka* poimanay = placehunt[gdehuntJ2]->kick(idytki);
				if ((poimanay->itswim() == 1) || (poimanay->itfly() == 1)) { poimanay->podrezJ++; }
				node3->dobav(poimanay);
				sravneniesytokonday++;
			}
			if (sravneniesytokonday >= ytokonday[1][numdayhunter]) { cout << "Охотник 2 с фермы JAMYHYP поймал " << ytokonday[1][numdayhunter] << " уток" << " на " << placehunt[gdehuntJ2]->nameLake << endl; };
		}; sravneniesytokonday = 0;
	    for (int i = 1; i <= (ytokonday[2][numdayhunter] - sravneniesytokonday); ) {//Охотник 1 с фермы NUDYWIJ
		if (placehunt[gdehuntN1]->get_kolytok() == 0) { cout << "Охотник 1 с фермы NUDYWIJ не поймал ни одной утки на " << placehunt[gdehuntN1]->nameLake << endl; ytokonday[2][numdayhunter] = 0; break; };
		if (placehunt[gdehuntN1]->get_kolytok() < (ytokonday[2][numdayhunter] - sravneniesytokonday)) { ytokonday[2][numdayhunter] = placehunt[gdehuntN1]->get_kolytok(); };
		int idytki = rand() % (placehunt[gdehuntN1]->get_kolytok());
		if (placehunt[gdehuntN1]->Strongytki(placehunt[gdehuntN1], idytki) == 1) {
			ytokonday[2][numdayhunter]--;
			if (ytokonday[2][numdayhunter] == 0) { cout << "Охотник 2 с фермы NUDYWIJ не поймал ни одной утки на " << placehunt[gdehuntN1]->nameLake << endl; ytokonday[2][numdayhunter] = 0; break;};
		}
		else {
			Ytka* poimanay = placehunt[gdehuntN1]->kick(idytki);
			if ((poimanay->itswim() == 1) || (poimanay->itfly() == 1)) { poimanay->podrezN++; }
			node4->dobav(poimanay);
			sravneniesytokonday++;
		}

		if (sravneniesytokonday >= ytokonday[2][numdayhunter]) { cout << "Охотник 1 с фермы NUDYWIJ поймал " << ytokonday[2][numdayhunter] << " уток" << " на " << placehunt[gdehuntN1]->nameLake << endl; };
	}; sravneniesytokonday = 0;
        for (int i = 1; i <= (ytokonday[3][numdayhunter] - sravneniesytokonday); ) {         //Охотник 2 с фермы NUDYWIJ
	          if (placehunt[gdehuntN2]->get_kolytok() == 0) { cout << "Охотник 2 с фермы NUDYWIJ не поймал ни одной утки на " << placehunt[gdehuntN2]->nameLake << endl; ytokonday[3][numdayhunter] = 0; break; };
	         if (placehunt[gdehuntN2]->get_kolytok() < (ytokonday[3][numdayhunter] - sravneniesytokonday)) { ytokonday[3][numdayhunter] = placehunt[gdehuntN2]->get_kolytok(); };
	         int idytki = rand() % (placehunt[gdehuntN2]->get_kolytok());
	         if (placehunt[gdehuntN2]->Strongytki(placehunt[gdehuntN2], idytki) == 1) {
		         ytokonday[3][numdayhunter]--;
		     if (ytokonday[3][numdayhunter] == 0) { cout << "Охотник 2 с фермы NUDYWIJ не поймал ни одной утки на " << placehunt[gdehuntN2]->nameLake << endl; ytokonday[3][numdayhunter] = 0; break; };
	          }
	        else {
		         Ytka* poimanay = placehunt[gdehuntN2]->kick(idytki);
	        if ((poimanay->itswim() == 1) || (poimanay->itfly() == 1)) { poimanay->podrezN++; }
	    	node4->dobav(poimanay);
	    	sravneniesytokonday++;
	}
	if (sravneniesytokonday >= ytokonday[3][numdayhunter]) { cout << "Охотник 2 с фермы NUDYWIJ поймал " << ytokonday[3][numdayhunter] << " уток" << " на " << placehunt[gdehuntN2]->nameLake << endl; }


};

		};
		void print_menu() {
			system("cls");
			if (numdayhunter == 0) { cout << endl << "Игра была начата, все утки находятся в своих родных озерах" << endl; }
			else {
				cout << "Закончился " << numdayhunter << "день охоты" << endl;
				if (numdayhunter == 8) { cout << " (Последний)" << endl; };
			};
			printf("1. Начать новый день охоты\n");
			printf("2. Показать информацию по озерам\n");
			printf("3. Показать информацию по уткам\n");
			printf("4. Показать информацию по охотникам\n");
			printf("5. Завершение охоты\n");
			if (numdayhunter == 8) { cout << "нажмите 1 для подведения итогов"; }
			cout << endl << "Введите нужный номер меню для дальнейших действий --->";
			return;
		}
		void print_menu1() {
			cout << endl << "1. Информация по уткам на озере Аргентино";
			cout << endl << "2. Информация по уткам на озере Байкал";
			cout << endl << "3. Информация по уткам на ферме JAMYHYP";
			cout << endl << "4. Информация по уткам на ферме NUDYWIJ";
			cout << endl << "5. Информация по всем уткам ";
			cout << endl << "6. Назад" << endl;
			cout << endl << "Введите нужный номер меню для дальнейших действий --->";
			return;
		}
		void print_menu2() {

			cout << endl << "1. Охонтик 1 с фермы JAMYHYP";
			cout << endl << "2. Охотник 2 с фермы JAMYHYP";
			cout << endl << "3. Охотник 1 с фермы NUDYWIJ";
			cout << endl << "4. Охотник 2 с фермы NUDYWIJ";
			cout << endl << "5. Назад" << endl;
			cout << endl << "Введите нужный номер меню для дальнейших действий --->";
			return;
		};
		void check_start() {
			int Nachaloigri = 0;
			cout << "                    Приветствуем Вас в симмуляторе охоты для уток!" << endl << "Нажмите 1 для запуска симмулятора" << endl;
			cin >> Nachaloigri;
			if (Nachaloigri != 1) { system("cls"); cout << endl << "Вы нажали не на ту клавишу, не хотите запускать игру?" << endl; system("pause"); system("cls"); return check_start(); };
			return;
		};
		int take_nummenu(int max) {
			int var;
			cin >> var;
			if ((var < 1) || (var > max)) { cout << "такого пункта в меню нету" << endl << "Введите нужный номер меню для дальнейших действий --->"; return take_nummenu(max); }
			return var;
		};
		void itogi(Lake* node1, Lake* node2, Lake* node3, Lake* node4, int variant) {
			system("cls");
			if (variant == 1000) { cout << "Охота была преждевременно завершенна" << endl << endl; };
			if ((node1->get_kolytok() == 0) && (node1->get_kolytok() == 0)) { cout << endl << "Все утки были пойманы " << endl << endl; };
			if (numdayhunter == 8) { cout << "Дни охоты закончились" << endl << endl; };
			cout << "На озере Агрентино осталось:             " << node1->get_kolytok() << " уток" << endl;
			cout << "На озере Байкал    осталось:             " << node2->get_kolytok() << " уток" << endl;
			cout << "На ферме JAMYHYP в заключении находятся: " << node3->get_kolytok() << " уток" << endl;
			cout << "На ферме NUDYWIJ в заключении находятся: " << node4->get_kolytok() << " уток" << endl;
			cout << "Охонтик 1 с фермы JAMYHYP в общем поймал " << ytokonday[0][1] + ytokonday[0][2] + ytokonday[0][3] + ytokonday[0][4] + ytokonday[0][5] + ytokonday[0][6] + ytokonday[0][7] + ytokonday[0][8] << " уток" << endl;/* << "Из них сейчас на ферме " << && &&<< " уток" << endl;*/
			cout << "Охонтик 2 с фермы JAMYHYP в общем поймал " << ytokonday[1][1] + ytokonday[1][2] + ytokonday[1][3] + ytokonday[1][4] + ytokonday[1][5] + ytokonday[1][6] + ytokonday[1][7] + ytokonday[1][8] << " уток" << endl;/* << "Из них сейчас на ферме " << && &&<< " уток" << endl;*/
			cout << "Охонтик 1 с фермы NUDYWIJ в общем поймал " << ytokonday[2][1] + ytokonday[2][2] + ytokonday[2][3] + ytokonday[2][4] + ytokonday[2][5] + ytokonday[2][6] + ytokonday[2][7] + ytokonday[2][8] << " уток" << endl;/* << "Из них сейчас на ферме " << && &&<< " уток" << endl;*/
			cout << "Охонтик 2 с фермы NUDYWIJ в общем поймал " << ytokonday[3][1] + ytokonday[3][2] + ytokonday[3][3] + ytokonday[3][4] + ytokonday[3][5] + ytokonday[3][6] + ytokonday[3][7] + ytokonday[3][8] << " уток" << endl;/* << "Из них сейчас на ферме " << && &&<< " уток" << endl;*/
			return;
		};
		void VsemogyshiiCrak() {
			cout << endl << "Всемогущий кряк появился" << endl;





		}

		int main() {
			setlocale(LC_ALL, "Rus");
			srand(time(NULL));
			check_start();
			int Num_peganki = 0;
			int Num_peganki1 = 0;
			int Num_nirky = 0;
			int Num_hoxlytka = 0;
			int Num_laysanytka = 0;
			int Num_jeltshirok = 0;
			int a = 1 + rand() % (VsegoYtok);                //определение количества уток на одном из озер (на друом озере будет VsegoYtok-a)
            Num_peganki = rand() % (a);
            if (a - Num_peganki != 0) {
		       Num_peganki1 = rand() % (a - Num_peganki);
		      Num_nirky = a - Num_peganki - Num_peganki1;
		};
           if ((VsegoYtok - a) != 0) {
		       Num_hoxlytka = rand() % (VsegoYtok - a);
		         Num_laysanytka = rand() % (VsegoYtok - a - Num_hoxlytka);
		        Num_jeltshirok = VsegoYtok - a - Num_hoxlytka - Num_laysanytka;
			};
			Lake Argentino, Baikal, JAMYHYP, NUDYWIJ;
			Lake* Arg, * Bai, * JAM, * NUD;
			Arg = &Argentino;Bai = &Baikal;
			JAM = &JAMYHYP;NUD = &NUDYWIJ;
			Arg->nameLake = Place[0];
			Bai->nameLake = Place[1];
			JAM->nameLake = Place[2];
			NUD->nameLake = Place[3];
			if (Num_peganki > 0) { for (int i = 0; i < Num_peganki; i++) { Arg->dobav(new peganki); }; };
			if (Num_peganki1 > 0) { for (int i = 0; i < Num_peganki1; i++) { Arg->dobav(new peganki1); }; };
			if (Num_nirky > 0) { for (int i = 0; i < Num_nirky; i++) { Arg->dobav(new nirky); }; };
			if (Num_hoxlytka > 0) { for (int i = 0; i < Num_hoxlytka; i++) { Bai->dobav(new hoxlytka); }; };
			if (Num_laysanytka > 0) { for (int i = 0; i < Num_laysanytka; i++) { Bai->dobav(new laysanytka); }; };
			if (Num_jeltshirok > 0) { for (int i = 0; i < Num_jeltshirok; i++) { Bai->dobav(new jeltshirok); }; };
			Arg->checkplace(0);
			Bai->checkplace(0);
			int variant = 0;
			int limcrak = 0;
			for (; numdayhunter <= VsegoDay;) {
				Arg->checkplace(1);
				Bai->checkplace(1);
				JAM->checkplace(1);
				NUD->checkplace(1);

				do {
					if ((Argentino.get_kolytok() == 0) && (Baikal.get_kolytok() == 0)) { cout << endl << "Все утки были пойманны до окончания дней охоты!" << endl; break; }
				menu:
					print_menu();
					variant = take_nummenu(5);
					switch (variant) {
					case 1: { numdayhunter++; break; }
					case 2: {Arg->getinfo();
						Bai->getinfo();
						JAM->getinfo();
						NUD->getinfo(); system("pause"); goto menu; break; }
					case 3: {menu1:
						print_menu1();
						variant = 10 * take_nummenu(6);
						switch (variant) {
						case 10: {cout << endl << "Количество уток на Аргентино: " << Arg->get_kolytok() << endl;
							Arg->opis_ytok();  break; }
						case 20: {cout << endl << "Количество уток на Байкале: " << Bai->get_kolytok() << endl;
							Bai->opis_ytok();  break;  }
						case 30: {cout << endl << "Количество уток на JAMYHYP: " << JAM->get_kolytok() << endl;
							JAM->opis_ytok(); break; }
						case 40: {cout << endl << "Количество уток на NUDYWIJ: " << NUD->get_kolytok() << endl;
							NUD->opis_ytok();  break; }
						case 50: {cout << endl << "Уток всего:" << (Arg->get_kolytok() + Bai->get_kolytok() + JAM->get_kolytok() + NUD->get_kolytok()) << endl; Arg->opis_ytok(); Bai->opis_ytok();JAM->opis_ytok(); NUD->opis_ytok();  break;  }
						case 60: { goto menu; break; }
						}
						if (variant != 60) { goto menu1; }}
					case 4: {if (numdayhunter == 0) { cout << endl << "	Охотники спокойно отдыхают и ждут начала сезона охоты " << endl; };
					  menu2:
						  print_menu2();
						  variant = 100 * take_nummenu(5);
						  switch (variant) {
						  case 100: {if (gdehuntJ1 == 1) { cout << endl << "Сегодня охотился на " << Bai->get_nameLake() << endl; };
								  if (gdehuntJ1 == 0) { cout << endl << "Сегодня охотился на " << Arg->get_nameLake() << endl; };
								  cout << endl << "Сегодня было пойманно " << ytokonday[0][numdayhunter] << " уток" << endl << "Пойманно в течении охоты " << ytokonday[0][1] + ytokonday[0][2] + ytokonday[0][3] + ytokonday[0][4] + ytokonday[0][5] + ytokonday[0][6] + ytokonday[0][7] + ytokonday[0][8] << " уток" << endl; break; }
						  case 200: {if (gdehuntJ2 == 1) { cout << endl << "Сегодня охотился на " << Bai->get_nameLake() << endl; };
								  if (gdehuntJ2 == 0) { cout << endl << "Сегодня охотился на " << Arg->get_nameLake() << endl; };
								  cout << endl << "Сегодня было пойманно " << ytokonday[1][numdayhunter] << " уток" << endl << "Пойманно в течении охоты " << ytokonday[1][1] + ytokonday[1][2] + ytokonday[1][3] + ytokonday[1][4] + ytokonday[1][5] + ytokonday[1][6] + ytokonday[1][7] + ytokonday[1][8] << " уток" << endl; break; }
						  case 300: {if (gdehuntN1 == 1) { cout << endl << "Сегодня охотился на " << Bai->get_nameLake() << endl; };
								  if (gdehuntN1 == 0) { cout << endl << "Сегодня охотился на " << Arg->get_nameLake() << endl; };
								  cout << endl << "Сегодня было пойманно " << ytokonday[2][numdayhunter] << " уток" << endl << "Пойманно в течении охоты " << ytokonday[2][1] + ytokonday[2][2] + ytokonday[2][3] + ytokonday[2][4] + ytokonday[2][5] + ytokonday[2][6] + ytokonday[2][7] + ytokonday[2][8] << " уток" << endl; break; }
						  case 400: {if (gdehuntN2 == 1) { cout << endl << "Сегодня охотился на " << Bai->get_nameLake() << endl; };
								  if (gdehuntN2 == 0) { cout << endl << "Сегодня охотился на " << Arg->get_nameLake() << endl; };
								  cout << endl << "Сегодня было пойманно " << ytokonday[3][numdayhunter] << " уток" << endl << "Пойманно в течении охоты " << ytokonday[3][1] + ytokonday[3][2] + ytokonday[3][3] + ytokonday[3][4] + ytokonday[3][5] + ytokonday[3][6] + ytokonday[3][7] + ytokonday[3][8] << " уток" << endl; break; }
						  case 500: { goto menu; break; }
						  }
						  if (variant != 500) { goto menu2; }};
					case 5: {
						cout << "Вы уверенны, что преждевременно хотите закончить охоту? Это приведет к подведению итогов прошедших дней охоты";
						cout << endl << "1. Да";
						cout << endl << "2. Нет";
						variant = 1000 * take_nummenu(2);
						switch (variant) {
						case 100: { continue; }
						case 200: {goto menu; break; }
						}
					}
					}
				} while ((variant != 1) && (variant != 1000));
				if ((variant == 1000)||(numdayhunter == 9)){ break; };
				if (numdayhunter > 1) {
					int kto_to_sbegal_s_JAM = JAM->leave_farm(Arg, Bai, 0);
					int kto_to_sbegal_s_NUD = NUD->leave_farm(Arg, Bai, 1);
					if ((kto_to_sbegal_s_JAM == 0) && (kto_to_sbegal_s_NUD == 0)) { cout << endl << " Ни одной утке не удалось вырваться с фермы "<<endl; };
				};                                        //проверка сбежавших с фермы уток
				if (Arg->get_smigr()!= 0) { Arg->migration(Bai); };
				if (Bai->get_smigr ()!=0) { Bai->migration(Arg); };
				int qwerty = rand() % 101;                                                              // выпадение Всемогущего кряка
				if ((qwerty <= CrakChance) && (limcrak == 0)) { VsemogyshiiCrak(); limcrak = 1;};
				if (numdayhunter <= 8) { hunt(Arg, Bai, JAM, NUD); };
				system("pause");
			};
			system("pause");
			itogi(Arg, Bai, JAM, NUD, variant); //подведение итогов охоты


		}