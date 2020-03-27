#include <cstdio>

struct Kosik {
	
	public:	
		void printAll() {
			char c;
			FILE * dataFile;
			dataFile = fopen("data.csv", "r");
			c = fgetc(dataFile);
			while(c != EOF) {
				printf("%c", c);
				c = fgetc(dataFile);
			}
			fclose(dataFile);
		}
		
		void putInCart() {		
			FILE * dataKosik;
			dataKosik = fopen("kosik.csv", "a");
			int id,cena;
			const char* nazev[32];
			printf("Zadejte id: ");
			scanf("%d", &id);
			
			printf("Zadejte nazev: ");
			scanf("%s", nazev);
			
			printf("Zadejte cenu: ");
			scanf("%d", &cena);
			
			fprintf(dataKosik, "%d;%s;%d\n", id, nazev, cena);
		}
		
		void printCart() {
			char c;
			FILE * contentKosik;
			contentKosik = fopen("kosik.csv", "r");
			c = fgetc(contentKosik);
			while(c != EOF) {
				printf("%c", c);
				c = fgetc(contentKosik);
			}
			fclose(contentKosik);
		} 
		
		void clearCart() {
			FILE * contentKosik;
			contentKosik = fopen("kosik.csv", "w");
			fclose(contentKosik);
		}

	private:
			
};

int main() {
	Kosik kosik;
	int cont;
	while(cont = 1) {
		int volba;
		printf("Stiskni 1 pro vypis vseho zbozi \nStiskni 2 pro pridani zbozi do kosiku \nStiskni 3 pro vypis obsahu kosiku\nNapis 4 pro vymazani kosiku\nNapis 5 pro ukonceni\n");
		scanf("%d", &volba);
		if(volba == 1) {
			kosik.printAll();
		}
		else if(volba == 2) {
			kosik.putInCart();
		}
		else if(volba == 3) {
			kosik.printCart();
		}
		else if(volba == 4) {
			kosik.clearCart();
		}
		else if(volba == 5) {
			break;
		}
	}
}




