#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <conio2.h>

using namespace std;

int value(char matkul){
	switch (matkul){
		case 'A' : return 4; break;
		case 'B' : return 3; break;
		case 'C' : return 2; break;
		case 'D' : return 1; break;
		default  : return 0;
	}
}

int main(int argc, char** argv) {
	char matkul[9], sks[9], jumlah;
	int tsks=0, tnilai=0;
	
	textcolor(15);
	cout << "Jumlah Matakuliah : "; jumlah = getch(); clrscr();
	cout << "+----+-------+-----+-------+\n"
		 << "| NO | INDEX | SKS | NILAI |\n"
		 << "+----+-------+-----+-------+";
	for(int i=0; i<(jumlah-'0'); i++){
		gotoxy(1,wherey()+1); printf("|  %i",i+1);
		gotoxy(6,wherey());   printf("|   "); matkul[i] = getche(); printf("   |");
		gotoxy(14,wherey());  printf("|  ");  sks[i] = getche();    printf("  |");
		gotoxy(20,wherey());  printf("|   %-2i  |",(value(toupper(matkul[i]))*(sks[i]-'0')));
		tsks += sks[i]-'0';
		tnilai += (value(toupper(matkul[i]))*(sks[i]-'0'));
	}
	printf("\n+--------------------------+");
	printf("\n|    TOTAL   | %2i  |   %-2i  |",tsks,tnilai);
	printf("\n+--------------------------+");
	printf("\n|  INDEKS PRESTASI | %.2f  |",(float)tnilai/(float)tsks);
	printf("\n+--------------------------+");
	getch();
}
